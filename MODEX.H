void mode_x(){
 asm{
  mov   ax,13h
  int   10h

  mov   dx,3C4h          //       ; select sequencer registers
  mov   al,4             //       ; index 4 -> memory mode register
  out   dx,al
  inc   dx
  in    al,dx            //       ; read the original value
  and   al,NOT 8         //       ; turn off chain 4 (bit 3)
  or    al,4             //       ; turn off odd/even (bit 2)
  out   dx,al            //       ; write the new value
  mov   dx,3CEh          //       ; select graphics controller registers
  mov   al,5              //      ; index 5 -> mode register
  out   dx,al
  inc   dx
  in    al,dx             //      ; read original value
  and   al,NOT 16         //      ; turn off odd/even (bit 4)
  out   dx,al             //      ; write new value
  dec   dx
  mov   al,6              //      ; index 6 -> miscellanous register
  out   dx,al
  inc   dx
  in    al,dx              //     ; read original value
  and   al,NOT 2           //     ; turn off chain odd/even (bit 1)
  out   dx,al              //     ; write original value

  mov   dx,3D4h            //     ; select CRCT registers
  mov   al,14h            //      ; index 14h -> Underline location register
  out   dx,al
  inc   dx
  in    al,dx              //     ; read original value
  and   al,NOT 64          //     ; turn off doubleword (bit 6)
  out   dx,al              //     ; write new value
  dec   dx
  mov   al,17h            //      ; index 17h -> Mode control register
  out   dx,al
  inc   dx
  in    al,dx              //     ; read original value
  or    al,16              //     ; turn on byte mode bit (bit 6)
  out   dx,al             //      ; write new value
 };
};

void putpix(int x, int y, char color, int page){
 int vpos;
 char pageofs;
 vpos = (x+(320*y))/4;
 pageofs = (page * 4);
 asm{
  mov   ax,0xA000
  mov   es,ax             //      ; select VGA memory segment
  mov   dx,0x3C4           //      ; select sequencer registers
  mov   al,2             //       ; index 2 -> map mask register
  inc   dx
  mov   al,2              //      ; change value to 4 : enable plane 2 only
  out   dx,al
  mov   di,vpos           //          ; set offset to 0FACh
  mov   al,color           //     ; value to write
  stosb
  };
};