#include <c:\bread\graffx.h>
#include <math.h>
#include <complex.h>
//#include <c:\bread\screen.h>
complex com1,com2;
void main(){
 int nbr1,nbr2,nbr3,curpage=0;
 mode_x();
 nbr3=0;
 load_pals();
do{
 for (nbr1=1;nbr1<320;nbr1++){
  for (nbr2=1;nbr2<200;nbr2++){
   put_pix(nbr1,nbr2,(nbr1**nbr2),curpage);
  };
 };
 fade_out(nbr3%100+50,255-nbr3%50,30);
 swap(curpage);
 fade_in(0,255,30);
 curpage=curpage^1;
 nbr3++;
}while(!kbhit());
mode_3();
//play_pal2();
};