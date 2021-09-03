#include <iostream.h>
#include <stdlib.h>
#include <c:\bread\graffx.h>
void main(){
 int nbr1;
 int graypal[16][3];
 int temppal[16][3];
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
 for (nbr1=16;nbr1<32;nbr1++){
  get_pal(nbr1,graypal[nbr1-16]);
  set_pal(nbr1,10,0,0);
 };
 for (int nbr=1;nbr<100;nbr++){
 circle(160,100,nbr,(nbr/6.25)+16,0);
 };
for (int nbr6=0;nbr6<100;nbr6++){
 for (int nbr2=16;nbr2<32;nbr2++){
  for (int nbr3=0;nbr3<3;nbr3++){
   while(temppal[nbr2-16][nbr3]<graypal[nbr2-16][nbr3]){
    temppal[nbr2-16][nbr3]++;
    set_pal(nbr2,temppal[nbr2-16][0],temppal[nbr2-16][1],temppal[nbr2-16][2]);
    };
   };
  delay(25);
  for ( nbr3=0;nbr3<3;nbr3++){
   while(temppal[nbr2-16][nbr3]>10){
    temppal[nbr2-16][nbr3]--;
    set_pal(nbr2,temppal[nbr2-16][0],temppal[nbr2-16][1],temppal[nbr2-16][2]);
    };
   };
 };
};
 cin >> joe;
};