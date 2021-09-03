#include <c:\bread\graffx.h>
const o=40;
const y=43;
const r=37;
int startx;
int starty;
int one[]={0,0,o,0,0,0,o,0,0,
	   0,0,0,y,0,y,0,0,0,
	   0,0,0,o,r,o,0,0,0,
	   0,0,y,y,o,y,y,0,0,
	   y,o,o,r,r,r,o,o,y,
	   0,0,y,y,o,y,y,0,0,
	   0,0,0,o,r,o,0,0,0,
	   0,0,0,y,0,y,0,0,0,
	   0,0,y,0,0,0,y,0,0};

int two[]={0,0,0,0,0,0,0,0,0,
	   0,0,0,y,0,y,0,0,0,
	   0,0,0,o,r,o,0,0,0,
	   0,0,y,0,o,0,y,0,0,
	   0,o,0,r,r,r,0,o,0,
	   0,0,y,0,o,0,y,0,0,
	   0,0,0,o,r,o,0,0,0,
	   0,0,0,y,0,y,0,0,0,
	   0,0,0,0,0,0,0,0,0};

int thr[]={0,0,0,0,0,0,0,0,0,
	   0,0,0,0,0,0,0,0,0,
	   0,0,0,0,r,0,0,0,0,
	   0,0,y,0,o,0,y,0,0,
	   0,0,0,r,0,r,0,0,0,
	   0,0,y,0,o,0,y,0,0,
	   0,0,0,0,r,0,0,0,0,
	   0,0,0,0,0,0,0,0,0,
	   0,0,0,0,0,0,0,0,0};
int fur[]={0,0,0,0,0,0,0,0,0,
	   0,0,0,0,0,0,0,0,0,
	   0,0,0,0,0,0,0,0,0,
	   0,0,0,0,r,0,0,0,0,
	   0,0,0,r,r,r,0,0,0,
	   0,0,0,0,r,0,0,0,0,
	   0,0,0,0,0,0,0,0,0,
	   0,0,0,0,0,0,0,0,0,
	   0,0,0,0,0,0,0,0,0};
void main(){
 mode_x();
 randomize();
for (int nbr=0;nbr<33;nbr++){
 startx=random(320)+1;
 starty=random(200)+1;
 for (int nbr1=0;nbr1<9;nbr1++)
  for (int nbr2=0;nbr2<9;nbr2++)
   put_pix(nbr1+startx,nbr2+starty,one[nbr1*9+nbr2],0);
 delay(300);
 for (nbr1=0;nbr1<9;nbr1++)
  for (nbr2=0;nbr2<9;nbr2++)
   put_pix(nbr1+startx,nbr2+starty,two[nbr1*9+nbr2],0);
 delay(300);
 for (nbr1=0;nbr1<9;nbr1++)
  for (nbr2=0;nbr2<9;nbr2++)
   put_pix(nbr1+startx,nbr2+starty,thr[nbr1*9+nbr2],0);
 delay(300);
 for (nbr1=0;nbr1<9;nbr1++)
  for (nbr2=0;nbr2<9;nbr2++)
   put_pix(nbr1+startx,nbr2+starty,fur[nbr1*9+nbr2],0);
 delay(300);
 for (nbr1=0;nbr1<9;nbr1++)
  for (nbr2=0;nbr2<9;nbr2++)
   put_pix(nbr1+startx,nbr2+starty,0,0);
};
 get_scan(0,0);
};
