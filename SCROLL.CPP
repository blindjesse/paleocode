#include <stdlib.h>
#include <c:\bread\graphics.h>
#include <conio.h>
#include <c:\bread\screen.h>

void main(){
 int loop1,loop2,ran;
 char scan,ascii;
 char far *vga;
 vga = (char far *) MK_FP(0xA000,0);

 mode_13();
 char pict[9][9]={   { 0, 0, 0, 0,26, 0, 0, 0, 0},
		     { 0, 0,27,25,25,25,27, 0, 0},
		     { 0,27,25,24,23,24,25,27, 0},
		     { 0,25,24,23,21,23,24,25, 0},
		     {26,25,23,21, 0,21,23,25,26},
		     { 0,25,24,23,21,23,24,25, 0},
		     { 0,27,25,24,23,24,25,27, 0},
		     { 0, 0,27,25,25,25,27, 0, 0},
		     { 0, 0, 0, 0,26, 0, 0, 0, 0}, };
 randomize();
for(loop2=0;loop2<9;loop2++){
 for (loop1=50;loop1<59;loop1++)
  put_pix(319,loop1,pict[loop2][loop1-50],0);
 for (loop1=50;loop1<59;loop1++)
  memcpy(vga+(loop1*320),vga+(1+(loop1*320)),320);
};

for (loop1=50;loop1<59;loop1++){
  memcpy(vga+(loop1*320),vga+(1+(loop1*320)),320);
//  delay(5);
  };
for (int loop3=0;loop3<100;loop3++){
for (loop2=0;loop2<50;loop2++){
 scroll_left(50,59,1);
 };
for (loop2=0;loop2<45;loop2++){
 scroll_right(50,59,1);
 };
};
get_scan(0,0);
};