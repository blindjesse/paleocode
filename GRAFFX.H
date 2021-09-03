#include <c:\bread\screen.h>
#include <conio.h>
#include <mem.h>
#include <math.h>
#include <dos.h>
#include <stdlib.h>

#define CRTC_ADDR	0x3d4	/* Base port of the CRT Controller (color) */
#define SEQU_ADDR	0x3c4	/* Base port of the Sequencer */
#define GRAC_ADDR	0x3ce	/* Base port of the Graphics Controller */

int palsto[256][3];
char *vscreen;
float *cosx;
float *sinx;

void mode_x(){
  unsigned char *vidseg;
  union REGS r;
  float deg;
  vidseg = (unsigned char *) MK_FP(0xA000,0);
  r.x.ax = 0x0013;
  int86(0x10, &r, &r);
  outport(SEQU_ADDR, 0x0604);
  outport(CRTC_ADDR, 0xE317);
  outport(CRTC_ADDR, 0x0014);
  outport(SEQU_ADDR, 0x0F02);
  memset(vidseg+1, 0, 0xffff);
  vidseg[0] = 0;
  deg=0.0;
};


float deg(int rad){
 float num;
 num = (rad * 180)/3.1415;
 return num;
};

float rad(int deg){
 float num;
 num = (deg * 3.1415)/180;
 return num;
};

void load_tables(){
float deg;
int nbr;
deg=0.0;
for (nbr=1;nbr<900;nbr++){
  sinx[nbr]=sin(rad(deg));
  cosx[nbr]=cos(rad(deg));
  deg+=0.4;
 };
};

void mode_3(){
 asm{
 mov ax,3h
 int 10h
 };
};


void put_pix(int x, int y, char color, int page){
 char far *vidseg;
 outportb(0x3c4, 0x02);
 outportb(0x3c5, 0x01 << (x & 3));
 vidseg = (char far *) MK_FP(0xA000,0);
 if ((x<320)&&(y<200)){
 vidseg[(unsigned)(80*y)+(x/4)+(page*80*200)]=color;
 };
};


void translate(int x, int y, int page){
 unsigned int visStart;
 visStart = (page*x/4*y);
 outport(CRTC_ADDR, 0x0C);		/* set high byte */
 outport(CRTC_ADDR+1, visStart >> 8);
 outport(CRTC_ADDR, 0x0D);		/* set low byte */
 outport(CRTC_ADDR+1, visStart & 0xff);
};

void swap(int page){
 unsigned int visStart;
 visStart = (page*80*200);
 outport(CRTC_ADDR, 0x0C);		/* set high byte */
 outport(CRTC_ADDR+1, visStart >> 8);
 outport(CRTC_ADDR, 0x0D);		/* set low byte */
 outport(CRTC_ADDR+1, visStart & 0xff);
};

void plot_win(int x1,int x2,int y1,int y2,
	       int color, int scrnbr){
int nbr1,nbr2;
 for (nbr1=x1;nbr1<x2;nbr1++){
  for (nbr2=y1;nbr2<y2;nbr2++){
  put_pix(nbr1,nbr2,color,scrnbr);
  };
 };
};

void get_pal( int ColorNo,int colorpal[3]) {

  outp (0x03C7,ColorNo);
  colorpal[0] = inp (0x03C9);
  colorpal[1] = inp (0x03C9);
  colorpal[2] = inp (0x03C9);
}

void set_pal(int ColorNo, unsigned char R,
	 unsigned char G,       unsigned char B) {

  outp (0x03C8,ColorNo);
  outp (0x03C9,R);
  outp (0x03C9,G);
  outp (0x03C9,B);

}

void wait() {

  _DX = 0x03DA;

  l1: asm {
	in  al,dx;
	and al,0x08;
	jnz l1;
		}

  l2: asm {
	in  al,dx;
	and al,0x08;
	jz  l2;
		}
}

void load_pal(int pall[256][3]){
int loop6;
 for (loop6=0;loop6<256;loop6++){
  get_pal(loop6,pall[loop6]);
 };
};

void scroll_right(int y1,int y2,int numtoscroll){
 int loop;
 char far *vga;
 vga = (char far *)MK_FP(0xA000,0);
 for(loop=y1;loop<y2;loop++){
  memcpy(vga+(loop*320),vga+(numtoscroll+(loop*320)),320);
 };
};

void scroll_left(int y1,int y2,int numtoscroll){
 int loop;
 char far *vga;
 vga = (char far *)MK_FP(0xA000,0);
 for(loop=y1;loop<y2;loop++){
  memcpy(vga+(numtoscroll+(loop*320)),vga+(loop*320),320);
 };
};

void scroll_up(int numtoscroll){
 char far *vga;
 vga = (char far *)MK_FP(0xA000,0);
  memcpy (vga,vga+320,63680);
};

void scroll_down(int numtoscroll){
 char far *vga;
 vga = (char far *)MK_FP(0xA000,0);
 memcpy (vga+(320*numtoscroll),vga,64000-(320*numtoscroll));
};

void circle(int cx,int cy,int rad,int color,int page){
 float deg=0;
 int x,y;
do{
 x=(int)(rad*cos(deg));
 y=(int)(rad*sin(deg));
 put_pix(x+cx,y+cy,color,page);
 deg+=0.005;
 }while(deg<=6.28);
};

int sign(long nbr){
 if (nbr>0) return 1;
 else if (nbr<0) return -1;
 else return 0;
};

void line(int x1, int y1, int x2, int y2,int color,int screen){
long xslp,s,yslp,d1x,d1y,d2x,d2y,m,n;
int i;
xslp = x2-x1;
yslp = y2-y1;
d1x = sign(xslp);
d1y = sign(yslp);
d2x = sign(xslp);
d2y = 0;
m = abs(xslp);
n = abs(yslp);

if (m<=n){
 d2x=0;
 d2y=sign(yslp);
 m=abs(yslp);
 n=abs(xslp);
 };

 s = (int)(m/2);

 for (i=0;i<(int)(m);i++){
  put_pix(x1,y1,color,screen);
  s +=n;
  if (s >=m){
   s-=m;
   x1+=d1x;
   y1+=d1y;
  }else{
   x1+=d2x;
   y1+=d2y;
  };
 };
};

void play_pal(){
 int nbr3,nbr4,ran;
 int tempal[256][3];
 for (nbr3=0;nbr3<255;nbr3++){
  get_pal(nbr3,tempal[nbr3]);
  };
do{
 ran=random(14)+1;
 for (nbr3=0;nbr3<15;nbr3++){
  set_pal(32-nbr3,tempal[(ran+1)*16-nbr3][0],tempal[(ran+1)*16-nbr3][1],tempal[(ran+1)*16-nbr3][2]);
  delay(30);
  };
 for (nbr4=0;nbr4<15;nbr4++){
  set_pal(nbr4+16,tempal[ran*16+nbr4][0],tempal[ran*16+nbr4][1],tempal[ran*16+nbr4][2]);
  delay(30);
  };
 }while(!kbhit());
get_scan(0,0);
};

void play_pal2(){
 int nbr3,nbr4,ran;
 int tempal[256][3];
 for (nbr3=0;nbr3<255;nbr3++){
  get_pal(nbr3,tempal[nbr3]);
  };
do{
 ran=random(14)+1;
 for (nbr3=0;nbr3<15;nbr3++){
  set_pal((ran+1)*16-nbr3,tempal[(ran+1)*16-nbr3][0],tempal[(ran+1)*16-nbr3][1],tempal[(ran+1)*16-nbr3][2]);
  delay(30);
  };
 for (nbr4=0;nbr4<15;nbr4++){
  set_pal(nbr4+ran*16,tempal[ran*16+nbr4][0],tempal[ran*16+nbr4][1],tempal[ran*16+nbr4][2]);
  delay(30);
  };
 }while(!kbhit());
get_scan(0,0);
};

void load_pals(){
int nbr3;
 for (nbr3=0;nbr3<255;nbr3++){
  get_pal(nbr3,palsto[nbr3]);
  };
};

void black_out(int start=0,int end=255){
int nbr1;
 for (nbr1=start;nbr1<end;nbr1++){
  set_pal(nbr1,0,0,0);
 };
};

void fade_in(int start=0,int end=255,int dtime=10){
int tempal[3],change_pal=0;
int nbr1,nbr2,nbr3;
for (nbr3=0;nbr3<63;nbr3++){
 for (nbr1=start;nbr1<end;nbr1++){
   get_pal(nbr1,tempal);
   for (nbr2=0;nbr2<3;nbr2++){
    if (tempal[nbr2]<palsto[nbr1][nbr2]){
     tempal[nbr2]++;
    };
   };
  set_pal(nbr1,tempal[0],tempal[1],tempal[2]);
 };
 delay(dtime);
};
};

void fade_out(int start=0,int end=255,int dtime=20){
int nbr3,nbr2,nbr1;
int tempal[3];
for (nbr3=0;nbr3<63;nbr3++){
 for (nbr2=start;nbr2<end;nbr2++){
  get_pal(nbr2,tempal);
  for (nbr1=0;nbr1<3;nbr1++)
   if (tempal[nbr1]>0){
    tempal[nbr1]--;
    };
  set_pal(nbr2,tempal[0],tempal[1],tempal[2]);
 };
 delay(dtime);
};
};
#include <c:\bread\fonst.h>
