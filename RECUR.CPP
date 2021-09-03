#include <iostream.h>
#include <c:\bread\screen.h>
int recur(int base, int power){
 int nbr1;
 for (nbr1=power-1;nbr1>1;nbr1--)
  return (base*recur(base,nbr1));
};

void main(){
int power,base,joe;
cout << "\nEnter base: ";
cin >> base;
cout << "\nEnter power: ";
cin >> power;
cout << '\n' << recur(base,power);
cin >> joe;
};