#include <dos.h>

void mode_12(){
 asm{
 mov ax,12h
 int 10h
 };
};

void mode_3(){
 asm{
 mov ax,3h
 int 10h
 };
};

void put_pix(int x, int y, char color){
asm{
 mov ah, 0Ch
 mov al, color
 mov cx, y
 mov dx, x
 };
};