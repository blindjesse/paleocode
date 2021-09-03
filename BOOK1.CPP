#include<conio.h>
#include<c:\bread\graffx.h>
float tantable[628];

void load(){
for (int nbr=0;nbr<628;nbr++)
 tantable[nbr]=tan(nbr/100);
};

int tant(float theta){
int alpha;
alpha=(int(theta*100))%628;
return tantable[alpha];
};

void main(){
int nbr1,nbr2,nbr3,curpage,color;
float nbr4;
mode_x();
do{
for (nbr1=1;nbr1<320;nbr1++){
 for (nbr2=1;nbr2<200;nbr2++){
  color=((int)sqrt(random(RAND_MAX)))%256;
  put_pix(nbr1,nbr2,color,curpage);
};
};
nbr4+=0.05;
swap(curpage);
curpage=curpage^1;
}while(!kbhit());
get_scan(0,0);
};