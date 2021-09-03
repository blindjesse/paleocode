// Jesse Anderson

#include <dos.h>


void switch_pages(char pgnbr){
 asm{
  mov ah,05h
  mov al,pgnbr
  int 10h
 };
};

void gotoxy(char x, char y){
 asm{
  mov ah,02h
  mov dh, y
  mov dl, x
  int 10h
 };
};

void load_att(char x, char y,char attribute){
char far *vidseg;
vidseg = (char far *) MK_FP(0xB800,0);
 *(vidseg+(160*(y-1)+2*(x-1)+1)) = attribute;

 };

void load_char(int x, int y, char ch){
char far *vidseg;
vidseg = (char far *) MK_FP(0xB800,0);
 *(vidseg+(160*(y-1)+2*(x-1))) = ch;
};

void clr_scr(){
for (int loop1=1;loop1<=80; loop1++){
 for (int loop2=1;loop2<=25;loop2++){
  load_char(loop1,loop2,0);
  };
 };
};

void make_window_border(char minx,char miny,
								char maxx,char maxy){
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


void change_window_att(char minx,char miny,
								 char maxx,char maxy,char att){
for (int loop1=minx;loop1<=maxx;loop1++){
 for (int loop2=miny;loop2<=maxy;loop2++){
  load_att(loop1,loop2,att);
  };
 };
};

void load_string(char x, char y,char *string){
 for (int loop=0 ;string[loop] != '\0';loop++){
  load_char(x+loop,y,string[loop]);
 };
};

void main(){
 clr_scr();
 load_string(1,1,"stringloaderII!");
 };
