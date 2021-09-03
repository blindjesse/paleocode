#include <dos.h>
void main(){
int nbr1,nbr2;
for (nbr1=1;nbr1<30;nbr1++){
 for (nbr2=1;nbr2<10;nbr2++){
 sound(nbr1*nbr2+500);
 delay(25);
 };
};
nosound();
};