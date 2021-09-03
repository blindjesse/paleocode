#include <c:\bread\graphics.h>
#include <iostream.h>

void main(){
  int xstart=160,x=160,y,ystart=100,roadco=150;
  int nbr1;
  int pal[3];
  char joe;
  mode_13();
 for (nbr1=1;nbr1<500;nbr1++){
  for (y=100;y<=199;y++){
   for (x=xstart-(y-ystart);x<=xstart+(y-ystart);x++){
    put_pix(x,y,(roadco+y-nbr1)%(y),0);
    };
  };
 };
 cin >> joe;
};
