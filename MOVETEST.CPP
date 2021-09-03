#include <c:\bread\graffx.h>
#include <c:\bread\screen.h>
void main(){
 mode_x();
 for (int nbr=1;nbr<20;nbr++){
  put_pix(nbr+30,50,34,0);
 };
 delay(100);
 move_row(30,50,50,75,0);
 get_scan(0,0);
};

