#include <stdlib.h>
#include <c:\bread\graffx.h>

int palsto[256][3];

void load_pals(){
int nbr3;
 for (nbr3=0;nbr3<255;nbr3++){
  get_pal(nbr3,palsto[nbr3]);
  };
};

void black_out(int start=0,int end=255){
int nbr1;
 for (nbr1=start;nbr1<end;nbr1++){
  set_pal(nbr1,0,0,0);
 };
};

void fade_in(int start=0,int end=255,int dtime=10){
int tempal[3];
int nbr1,nbr2,nbr3;
for (nbr3=0;nbr3<63;nbr3++){
 for (nbr1=start;nbr1<end;nbr1++){
   get_pal(nbr1,tempal);
   for (nbr2=0;nbr2<3;nbr2++){
    if (tempal[nbr2]<palsto[nbr1][nbr2]){
     tempal[nbr2]++;
    };
   };
  set_pal(nbr1,tempal[0],tempal[1],tempal[2]);
 };
 delay(dtime);
};
};

void fade_out(int start=0,int end=255,int dtime=20){
int nbr3,nbr2,nbr1;
int tempal[3];
for (nbr3=0;nbr3<63;nbr3++){
 for (nbr2=start;nbr2<end;nbr2++){
  get_pal(nbr2,tempal);
  for (nbr1=0;nbr1<3;nbr1++)
   if (tempal[nbr1]>0){
    tempal[nbr1]--;
    };
  set_pal(nbr2,tempal[0],tempal[1],tempal[2]);
 };
 delay(dtime);
};
};

void main(){
int nbr1,nbr2;
randomize();
mode_x();
load_pals();
black_out();
for (nbr1=0;nbr1<320;nbr1++)
 for (nbr2=0;nbr2<200;nbr2++)
  put_pix(nbr1,nbr2,random(256),0);
fade_in(0,6,30);
fade_out(0,6,30);
fade_in(6,12,30);
fade_out(6,12,30);
fade_in(13,19,30);
fade_out(13,19,30);
fade_in(20,26,30);
fade_out(20,26,30);
fade_in(26,32,30);
fade_out(26,32,30);
get_scan(0,0);
mode_3();
};
