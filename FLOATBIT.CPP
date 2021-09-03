#include <iostream.h>
#include <conio.h>
void main(){
char farray[32];
float figure;
float *bits;
figure=3.01;
bits=&figure;
cout << bits;
for (int nbr1=0;nbr1<4;nbr1++){
 farray[nbr1]=*(bits+nbr1);
	};
};