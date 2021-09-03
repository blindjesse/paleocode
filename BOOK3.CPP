#include<conio.h>
#include<c:\bread\graffx.h>

void main(){
int Beta1=-11,Beta2=-12,Gamma=150,Alpha=4,Modf=3;
int i,j,x,y,z,c,nbr,curpage=0;
mode_x();
do{
for (i=1;i<320;i++){
 for (j=1;j<200;j++){
 x = Beta1+ (Gamma*i);
 y = Beta2+ (Gamma*j);
 z = Alpha*(tan(x*y)/(i%j+1));
 c = (int)z;
 if (c%Modf==0)
  put_pix(i,j,i+j,curpage);
 };
};

Gamma++;
Alpha++;
Modf++;
swap(curpage);
curpage=curpage^1;
}while (!kbhit());
play_pal();
get_scan(0,0);
};