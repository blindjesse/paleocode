#include<conio.h>
#include<c:\bread\graffx.h>
const Beta1=-11;
const Beta2=-12;
const Gamma=60;
const Alpha=10;
const Res=200;
const Modf=3;

void main(){
int i,j,x,y,z,c;
mode_x();
for (i=0;i<320;i++){
 for (j=0;j<200;j++){
 x = Beta1+ (Gamma*i);
 y = Beta2+ (Gamma*j);
 z = Alpha*(cos(x)+cos(y));
 c = (int)z;
 if (c%Modf==0)
  put_pix(i,j,random(4)+20,0);
 };
};
play_pal();
get_scan(0,0);
};