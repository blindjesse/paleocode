#include <c:\bread\graffx.h>
//#include <c:\bread\screen.h>
void main(){
 int nbr1,nbr2,nbr3,curpage=0;
 mode_x();
 nbr3=0;
 load_pals();
do{
 for (nbr1=1;nbr1<320;nbr1++){
  for (nbr2=1;nbr2<200;nbr2++){
   put_pix(nbr1,nbr2,raise(nbr1^nbr2,nbr3%15),curpage);
  };
 };
 fade_out(nbr3,255-nbr3,30);
 swap(curpage);
 fade_in(nbr3,255-nbr3,0);
 curpage=curpage^1;
 nbr3++;
}while(!kbhit());
mode_3();
//play_pal2();
};