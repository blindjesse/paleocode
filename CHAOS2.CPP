#include <c:\bread\graffx.h>
//#include <c:\bread\screen.h>
#include <math.h>
#include<conio.h>
#include <stdlib.h>
void main(){
randomize();
int nbr1,nbr2,nbr3,curpage=0;
mode_x();
do{
 for (nbr1=1;nbr1<320;nbr1++)
  for (nbr2=1;nbr2<200;nbr2++)
   put_pix(nbr1,nbr2,(nbr1^nbr2|(nbr3|nbr2)&(nbr2|nbr1))^nbr3,curpage);
   swap(curpage);
   curpage=curpage^1;
 nbr3++;
 nbr3=nbr3%150;
 fade_out(random(128),random(256),0);
 fade_in(random(128),random(256),0);
 }while(!kbhit());
mode_3();
};