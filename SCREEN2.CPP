#include <stdio.h>
#include <dos.h>

main(){
 unsigned char scancode;
 unsigned char charcode;
 union REGS regs;

  regs.h.ah = 0;
  int86(0x16,&regs,&regs);
  scancode = regs.h.ah;
  charcode = regs.h.al;
  printf("%.3d &.3d [%c]\n",scancode,charcode, charcode);
};
