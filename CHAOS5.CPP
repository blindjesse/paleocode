#include <c:\bread\graffx.h>
//#include <c:\bread\screen.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
void main(){
int nbr1,nbr2,nbr3,nbr4,ran,curpage=0;
int tempal[16][3];
nbr3=0;
mode_x();
randomize();
 for (nbr3=16;nbr3<31;nbr3++){
  get_pal(nbr3,tempal[nbr3-16]);
  };
 for (nbr1=1;nbr1<160;nbr1++){
  for (nbr2=1;nbr2<200;nbr2++){
   put_pix((nbr1*2)-1,nbr2,nbr1%16+16,curpage);
   put_pix((nbr1*2),nbr2,nbr1%16+16,curpage);
   };
  };
do{
 for (nbr3=1;nbr3<15;nbr3++){
  set_pal(nbr3+16,tempal[15-nbr3][0],tempal[15-nbr3][1],tempal[15-nbr3][2]);
  delay(25);
  };
 for (nbr4=1;nbr4<15;nbr4++){
  set_pal(nbr4+16,tempal[nbr4][0],tempal[nbr4][1],tempal[nbr4][2]);
  delay(25);
  };
 }while(!kbhit());
get_scan(0,0);
};