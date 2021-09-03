#include <c:\bread\graffx.h>
#include <stdlib.h>
#include <iostream.h>

void main(){
int y=4;
char joe[]="AbCdEfGhIjKlMnOpQrStUvWxYz";
int nbr2=0;
int nbr6;
int palstore[16][3];
randomize();

for (int nbr3=16;nbr3<32;nbr3++){
 get_pal(nbr3,palstore[nbr3-16]);
 };
font font1;
do{
for (int nbr1=0;nbr1<15;nbr1++){
 font1.write_string(joe,4+nbr2*0.05,y+nbr2*0.05,16+nbr2*0.05);
 y+=10;
 };
for (nbr6=0;nbr6<nbr2*0.05;nbr6++){
 set_pal(nbr6+16,palstore[nbr6+1][0],palstore[nbr6+1][1],palstore[nbr6+1][2]);
 };
y=4;
nbr2++;
}while (!kbhit());
//font1.write_letter(111,4,4,35);
get_scan(0,0);
};