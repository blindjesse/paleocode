#include <c:\bread\screen.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <c:\bread\graphics.h>
//#include <c:\bread\screen.h>
/* THIS PROGRAM DOES NOT WORK!!*/
void main(){
 int nbr1,nbr2,nbr3,curpage=0;
 mode_13();
 nbr3=0;
// load_pals();
 for (nbr1=1;nbr1<320;nbr1++){
  for (nbr2=1;nbr2<200;nbr2++){
   put_pix(nbr1,nbr2,(int)(180/3.1415)*(atan((nbr2*(3.1415/180)))),curpage);
  };
 };
get_scan(0,0);
mode_3();
//play_pal2();
};