#include <c:\bread\graffx.h>
//#include <c:\bread\screen.h>
const bl=33;
const x=22;
const y=21;
void main(){
int nbr1,nbr2,nbr3;
int picture[]=              { 0, 0, 0, 0, 0, 0, 0, 0,bl,bl, 0,bl,bl, 0, 0, 0, 0, 0, 0, 0, 0,
			      0, 0, 0, 0, 0, 0,bl,bl,bl,bl, 0,bl,bl,bl,bl, 0, 0, 0, 0, 0, 0,
			      0, 0, 0, 0, 0,bl,bl,bl, 0,bl, 0,bl, 0,bl,bl,bl, 0, 0, 0, 0, 0,
			      0, 0, 0, 0,bl,bl,bl, 0, 0,bl, 0,bl, 0, 0,bl,bl,bl, 0, 0, 0, 0,
			      0, 0, 0, 0,bl,bl, 0, 0, 0,bl, 0,bl, 0, 0, 0,bl,bl, 0, 0, 0, 0,
			      0, 0, 0, 0,bl,bl,bl, 0, 0,bl, 0,bl, 0, 0,bl,bl,bl, 0, 0, 0, 0,
			      0, 0, 0, 0, 0,bl,bl,bl, 0,bl, 0,bl, 0,bl,bl,bl, 0, 0, 0, 0, 0,
			      0, 0, 0, 0, 0, 0, 0,bl,bl,bl, 0,bl,bl,bl, 0, 0, 0, 0, 0, 0, 0,
			      0, 0, 0, 0, 0, 0, 0,bl,bl,bl, 0,bl,bl,bl, 0, 0, 0, 0, 0, 0, 0,
			      0, 0, 0, 0, 0, 0,bl,bl,bl,bl, 0,bl,bl,bl,bl, 0, 0, 0, 0, 0, 0,
			      0, 0, 0, 0, 0,bl,bl,bl,bl,bl, 0,bl,bl,bl,bl,bl, 0, 0, 0, 0, 0,
			      0, 0, 0, 0, 0,bl,bl,bl,bl,bl, 0,bl,bl,bl,bl,bl, 0, 0, 0, 0, 0,
			      0, 0, 0, 0,bl,bl,bl, 0,bl,bl, 0,bl,bl, 0,bl,bl,bl, 0, 0, 0, 0,
			      0, 0, 0,bl,bl,bl, 0, 0,bl,bl, 0,bl,bl, 0, 0,bl,bl,bl, 0, 0, 0,
			      0, 0,bl,bl,bl, 0, 0, 0,bl,bl, 0,bl,bl, 0, 0, 0,bl,bl,bl, 0, 0,
			      0, 0,bl,bl, 0, 0, 0, 0,bl,bl, 0,bl,bl, 0, 0, 0, 0,bl,bl, 0, 0,
			      0,bl,bl,bl, 0, 0, 0, 0,bl,bl, 0,bl,bl, 0, 0, 0, 0,bl,bl,bl, 0,
			      0,bl,bl,bl, 0, 0, 0, 0,bl,bl, 0,bl,bl, 0, 0, 0, 0,bl,bl,bl, 0,
			      0, 0,bl,bl,bl, 0, 0, 0,bl,bl, 0,bl,bl, 0, 0, 0,bl,bl,bl, 0, 0,
			      0, 0, 0,bl,bl,bl,bl,bl,bl,bl, 0,bl,bl,bl,bl,bl,bl,bl, 0, 0, 0,
			      0, 0, 0, 0, 0,bl,bl,bl,bl,bl, 0,bl,bl,bl,bl,bl, 0, 0, 0, 0, 0,
			      0, 0, 0, 0, 0, 0, 0,bl,bl,bl, 0,bl,bl,bl, 0, 0, 0, 0, 0, 0, 0,
			      0, 0, 0, 0, 0, 0, 0, 0, 0,bl, 0,bl, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
mode_x();
for (nbr1=0;nbr1<x;nbr1++)
 for (nbr2=0;nbr2<y;nbr2++)
  put_pix(nbr2,nbr1,picture[(nbr2)+(y*nbr1)],0);
 for (nbr3=0;nbr3<20;nbr3++){
  scroll_down(2);
  scroll_right(0+nbr3*21,21+nbr3*21,2);
  delay(10);
  };
get_scan(0,0);
};