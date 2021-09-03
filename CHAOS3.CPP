#include <c:\bread\graffx.h>
#include <c:\bread\screen.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
void main(){
int nbr1,nbr2,nbr3,ran,curpage=0;
int tempal[3];
nbr3=0;
mode_x();
randomize();
do{
 for (nbr1=1;nbr1<320;nbr1++){
  for (nbr2=1;nbr2<200;nbr2++){
   ran=random(64);
   put_pix(nbr1,nbr2,(nbr1^nbr2|(nbr3|nbr2)&(nbr2|nbr1))^nbr3,curpage);
   set_pal(nbr2*nbr1%256,random(64),random(64),random(64));
   };
   };
 nbr3++;
 }while(!kbhit());
get_scan(0,0);
};