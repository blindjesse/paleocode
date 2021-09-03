#include <c:\bread\graffx.h>
//#include <c:\bread\screen.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
const widnum=2;
void place_pict(){
int nbr1,nbr2,curpage=0;
 for (nbr1=1;nbr1<(int)(320/widnum);nbr1++){
  for (nbr2=1;nbr2<200;nbr2++){
   put_pix((nbr1*widnum)-1,nbr2,(((nbr1*2-1)^nbr2)%16)+16,curpage);
   put_pix((nbr1*widnum),nbr2,(((nbr1*2)^nbr2)%16)+16,curpage);
   };
  };
};


void main(){
mode_x();
randomize();
place_pict();
play_pal();
};