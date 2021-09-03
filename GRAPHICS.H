#include <mem.h>
#include <dos.h>

char *vscreen;

void mode_13(){
 asm{
 mov ax,13h
 int 10h
 };
};

void mode_3(){
 asm{
 mov ax,3h
 int 10h
 };
};


void vflip(){
 movedata (_DS,(unsigned)vscreen,0xA000,0,64000);
};

void put_pix(int x, int y, char color, int scrnbr){
/*char far *vidseg;
vidseg = (char far *) MK_FP(0xA000,0);*/
switch (scrnbr){
 case 0:{
	asm{
	 mov ax,0xA000
	 mov es,ax
	 mov bx,[x]
	 mov dx,[y]
	 push bx
	 mov bx,dx
	 mov dh,dl
	 xor dl,dl
	 shl bx,6
	 add dx,bx
	 pop bx
	 add bx,dx
	 mov di,bx
	 mov al,[color]
	 stosb
	};
	break;};
 case 1:{
	 vscreen[x+(y*320)]=color;
	 break;
	 };
  }; //switch
};

void plot_win(int x1,int x2,int y1,int y2,
	       int color, int scrnbr){
 for (int nbr1=x1;nbr1<x2;nbr1++){
  for (int nbr2=y1;nbr2<y2;nbr2++){
  put_pix(nbr1,nbr2,color,scrnbr);
  };
 };
};
void get_pal(unsigned int ColorNo,int colorpal[3]) {

  outp (0x03C7,ColorNo);
  colorpal[0] = inp (0x03C9);
  colorpal[1] = inp (0x03C9);
  colorpal[2] = inp (0x03C9);
}

void set_pal(unsigned char ColorNo, unsigned char R,
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
 for (int loop6=0;loop6<256;loop6++){
  get_pal(loop6,pall[loop6]);
 };
};

void vsinit(){
 vscreen = new char[64000];
};

void scroll_right(int y1,int y2,int numtoscroll){
 int loop;
 char far *vga;
 vga = (char far *)MK_FP(0xA000,0);
 for(loop=y1;loop<y2;loop++){
  memcpy(vga+(numtoscroll+(loop*320)),vga+(loop*320),320);
 };
};

void scroll_left(int y1,int y2,int numtoscroll){
 int loop;
 char far *vga;
 vga = (char far *)MK_FP(0xA000,0);
 for(loop=y1;loop<y2;loop++){
  memcpy(vga+(loop*320),vga+(numtoscroll+(loop*320)),320);
 };
};
