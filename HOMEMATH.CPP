#include<d:\jesse\graphics.h>
#include <math.h>
#include <iostream.h>
void main(){
int nbr1,nbr2,nbr3;
mode_13();
for (nbr1=0;nbr1<320;nbr1++)
 for (nbr2=0;nbr2<200;nbr2++)
  put_pix(nbr1,nbr2,cos(nbr1/5)+cos(nbr2/5));
cin >> nbr3;
};