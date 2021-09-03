#include <c:\bread\graffx.h>
//#include <c:\bread\screen.h>
#include <math.h>
void main(){
int nbr1,nbr2,nbr3,curpage=0;
mode_x();
for (nbr3=1;nbr3<200;nbr3++){
 for (nbr1=1;nbr1<320;nbr1++)
  for (nbr2=1;nbr2<200;nbr2++)
   put_pix(nbr1,nbr2,(nbr1^nbr2&(nbr2|nbr1))|nbr3,curpage);
   swap(curpage);
   curpage=curpage^1;
  };
get_scan(0,0);
};