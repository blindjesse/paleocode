// Jesse Anderson
// All code written by me.
// September, 1996
#include <dos.h>
#include <conio.h>

void switch_pages(char pgnbr){
 asm{
  mov ah,05h
  mov al,pgnbr
  int 10h
 };
};

void gotoxy(char x, char y){
/* goes to a specific place on the screen in text mode */
 asm{
  mov ah,02h
  mov bh, 0h
  mov dh, y
  mov dl, x
  int 10h
 };
};

void load_att(char x, char y,char attribute){
/* loads the attribute into the character at x,y */
char far *vidseg;
vidseg = (char far *) MK_FP(0xB800,0);
 *(vidseg+(160*(y-1)+2*(x-1)+1)) = attribute;

 };

void scroll_win(char x1,char y1,char x2,char y2,char num_lines,char att=7){
asm{
 mov ah,06h
 mov al,num_lines
 mov bh,att
 mov ch,y1
 mov cl,x1
 mov dh,y2
 mov dl,x2
 int 10h
 };
};

void load_char(int x, int y, char ch){
/* loads the character into the spot at x,y */
char far *vidseg;
vidseg = (char far *) MK_FP(0xB800,0);
 *(vidseg+(160*(y-1)+2*(x-1))) = ch;
};

void clr_scr(){
/*clears the screen*/
for (int loop1=1;loop1<=80; loop1++){
 for (int loop2=1;loop2<=25;loop2++){
  load_char(loop1,loop2,0);
  };
 };
};

void clr_att(){
/* clears all attributes on the screen to the DOS default (7) */
for (int loop1=1;loop1<=80; loop1++){
 for (int loop2=1;loop2<=25;loop2++){
  load_att(loop1,loop2,7);
  };
 };
};

void make_win_border(char minx,char miny,char maxx,char maxy){
/* draws the single lined window border */
load_char(minx,miny,218);  //1st corner
load_char(maxx,miny,191);  //2nd corner
load_char(minx,maxy,192);  //3rd corner
load_char(maxx,maxy,217);  //4th corner
for (int loop1=minx+1;loop1<maxx;loop1++){
 load_char(loop1,maxy,196);
 load_char(loop1,miny,196);
 }
for (int loop2=miny+1;loop2<maxy;loop2++){
 load_char(minx,loop2,179);
 load_char(maxx,loop2,179);
 };
};

void load_win_att(char minx,char miny,char maxx,char maxy,char att){
/* changes the character attribute for a whole window */
for (int loop1=minx;loop1<=maxx;loop1++){
 for (int loop2=miny;loop2<=maxy;loop2++){
  load_att(loop1,loop2,att);
  };
 };
};

void dload_string(char x,char y, char *string, int dlay){
 int yplus=0,loop=0;
 int xplus=0,yint;
 while (string[loop+xplus]!='\0'){
  if (string[loop+xplus]=='\n'){
   xplus = loop+xplus+1;
   yplus++;
   loop=0;
  };
  load_char(x+loop,y+yplus,string[loop+xplus]);
/*  delay(dlay);
  sound(100);
  delay(1);*/
  nosound();
  loop++;
  };
}

void load_string(char x, char y,char *string){
/* loads a character string at the row starting x,y */
 int yplus=0,loop=0;
 int xplus=0,yint;
 while (string[loop+xplus]!='\0'){
  if (string[loop+xplus]=='\n'){
   xplus = loop+xplus+1;
   yplus++;
   loop=0;
  };
  load_char(x+loop,y+yplus,string[loop+xplus]);
  loop++;
  };
};

void get_scan(int &scan,int &ascii){
/* gets a keystroke from the keyboard and returns the scan and ascii code*/
  union REGS regs;

  regs.h.ah = 0;
  int86(0x16,&regs,&regs);
  scan = regs.h.ah;
  ascii = regs.h.al;
  };

void get_att_byte(int &byte){
 union REGS regs;
 regs.h.ah = 2;
 int86(0x16,&regs,&regs);
 byte = regs.h.al;
};

void clear_win(int x1, int y1, int x2, int y2){
/* clears the characters and attributes in a specific window */
 for (int nbr =x1; nbr <=x2; nbr++){
  for (int loop = y1; loop <=y2; loop++){
	 load_att(nbr,loop,7);
	 load_char(nbr,loop,' ');
	};
  };
};

void clear_char(int x1, int y1, int x2, int y2){
/* clears the characters in a specific window */
 for (int nbr =x1; nbr <=x2; nbr++){
  for (int loop = y1; loop <=y2; loop++){
	 load_char(nbr,loop,' ');
	};
  };
};

void blow_cursor(){
/* deletes the cursor */
 asm{
  mov ah,01h
  mov ch,20h
  int 10h
 };
};

void restore_cursor(){
/* returns cursor to normal  */
 asm{
  mov ah,01h
  mov ch,0h
  int 10h
 };
};

long Raise(int base, int power){
/* takes the base to the power! */
 int nbr1;
 long obase;
 if (power>0)
 obase=base;
 else
  obase=1;
 for (nbr1=1;nbr1<power;nbr1++){
   obase*=base;
  };
 return obase;
};

void get_string(char string[40],int len){
char ch;
int nbr1=0;
ch=getch();
while ((ch!=(char)13)&&(nbr1<len)){
 if ((ch==8)&&(nbr1>=1)){
/* goxy(curx-6,cury);
 write_letter(32,color,0);
 goxy(curx-6,cury);*/
 gotoxy(wherex()-1,wherey());
 load_char(wherex(),wherey(),' ');
 gotoxy(wherex()-1,wherey());
 nbr1-=1;
 }else{
 if ((ch>=32)&&(ch<126)){
 string[nbr1]=ch;
 load_char(wherex(),wherey(),ch);
 gotoxy(wherex()+1,wherey());
// cout << ch
// write_letter((int)ch,color,backc);
 nbr1++;
  };
  };
 ch=getch();
 };
string[nbr1]='\0';
};
