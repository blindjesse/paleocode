#include <c:\bread\graffx.h>
//#include <c:\bread\screen.h>
void main(){
mode_x();
for (int nbr1=1;nbr1<200;nbr1++)
 for (int nbr=1; nbr<256;nbr++)
  put_pix(nbr,nbr1,nbr,0);
 get_scan(0,0);
};