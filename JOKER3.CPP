#include <iostream.h>
#include <stdlib.h>
//#include <c:\bread\screen.h>
#include <c:\bread\graffx.h>
void main(){
 int nbr1;
 int graypal[256][3];
 int temppal[256][3];
 char joe;
 int ranum;
 for (int nbr4=0;nbr4<16;nbr4++){
  for (int nbr5=0;nbr5<3;nbr5++){
  temppal[nbr4][nbr5]=0;
  };
 };
 randomize();
// swap(2);
 mode_x();
 for (nbr1=0;nbr1<100;nbr1++){
  get_pal(nbr1,graypal[nbr1]);
  set_pal(nbr1,graypal[nbr1][0],graypal[nbr1][1],graypal[nbr1][2]);
 };
 for (int nbr=1;nbr<100;nbr++){
 circle(160,100,nbr,nbr,0);
 };
for (int nbr6=0;nbr6<200;nbr6++){
 for (int nbr2=0;nbr2<100;nbr2++){
  for (int nbr3=0;nbr3<3;nbr3++){
    while(temppal[nbr2][nbr3]<graypal[nbr2][nbr3]){
    temppal[nbr2][nbr3]++;
    set_pal(nbr2,temppal[nbr2][0],temppal[nbr2][1],temppal[nbr2][2]);
    };
   };
  for (nbr3=0;nbr3<3;nbr3++){
   while(temppal[nbr2][nbr3]<graypal[nbr2][(nbr3^nbr6)]){
    temppal[nbr2][nbr3]++;
    set_pal(nbr2,temppal[nbr2][0],temppal[nbr2][1],temppal[nbr2][2]);
    };
   };
 };
};
 get_scan(joe,joe);
};