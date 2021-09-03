#include <c:\bread\graffx.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
const widnum=8;
void place_pict(){
int nbr1,nbr2,curpage=0;
 for (nbr1=1;nbr1<(int)(320/widnum);nbr1++){
  for (nbr2=1;nbr2<200;nbr2++){
   put_pix((nbr1*widnum)-7,nbr2,(((int)cos(nbr1)%(int)sin(nbr2))%16)+16,curpage);
   put_pix((nbr1*widnum)-6,nbr2,(((int)sin(nbr1)%(int)tan(nbr2))%16)+16,curpage);
   put_pix((nbr1*widnum)-5,nbr2,(((int)tan(nbr1)%(int)cos(nbr2))%16)+16,curpage);
   put_pix((nbr1*widnum)-4,nbr2,(((int)cos(nbr1)%(int)sin(nbr2))%16)+16,curpage);
   put_pix((nbr1*widnum)-3,nbr2,(((int)sin(nbr1)%(int)tan(nbr2))%16)+16,curpage);
   put_pix((nbr1*widnum)-2,nbr2,(((int)tan(nbr1)%(int)cos(nbr2))%16)+16,curpage);
   put_pix((nbr1*widnum)-1,nbr2,(((int)tan(nbr1)%(int)tan(nbr2))%16)+16,curpage);
   put_pix((nbr1*widnum),nbr2,(((int)cos(nbr1)%(int)sin(nbr2))%16)+16,curpage);
   };
  };
};

void main(){
mode_x();
randomize();
place_pict();
play_pal();
};