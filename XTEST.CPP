#include <c:\bread\graffx.h>
#include <iostream.h>

void main(){
 char joe;
 int nbr1,nbr2;
 mode_x();
 swap(2);
for (int nbr3=0;nbr3<16;nbr3++){
 for (nbr1=0;nbr1<320;nbr1++){
  for (nbr2=0;nbr2<200;nbr2++){
  put_pix(nbr1,nbr2,nbr3,0);
  };
 };
swap(0);
 for (nbr1=0;nbr1<320;nbr1++){
  for (nbr2=0;nbr2<200;nbr2++){
  put_pix(nbr1,nbr2,nbr3+16,1);
  };
 };
swap(1);
};
 cin >> joe;
};