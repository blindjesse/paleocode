#include <c:\bread\graffx.h>
//#include <c:\bread\screen.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
const widnum=8;
void place_pict(){
int nbr1,nbr2,curpage=0;
 for (nbr1=1;nbr1<(int)(320/widnum);nbr1++){
  for (nbr2=1;nbr2<200;nbr2++){
   put_pix((nbr1*widnum)-7,nbr2,(((nbr1*2-1)^nbr2)%16)+16,curpage);
   put_pix((nbr1*widnum)-6,nbr2,(((nbr1*2-1)^nbr2)%16)+16,curpage);
   put_pix((nbr1*widnum)-5,nbr2,(((nbr1*2-1)^nbr2)%16)+16,curpage);
   put_pix((nbr1*widnum)-4,nbr2,(((nbr1*2-1)^nbr2)%16)+16,curpage);
   put_pix((nbr1*widnum)-3,nbr2,(((nbr1*2-1)^nbr2)%16)+16,curpage);
   put_pix((nbr1*widnum)-2,nbr2,(((nbr1*2-1)^nbr2)%16)+16,curpage);
   put_pix((nbr1*widnum)-1,nbr2,(((nbr1*2-1)^nbr2)%16)+16,curpage);
   put_pix((nbr1*widnum),nbr2,(((nbr1*2)^nbr2)%16)+16,curpage);
   };
  };
};

/*void play_pal(){
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
};*/

void main(){
mode_x();
randomize();
place_pict();
play_pal();
};