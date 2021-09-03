#include<math.h>z
#include<iostream.h>
#include<fstream.h>

int check(unsigned long product){
unsigned long product1;
product1=(product*1000000);
product1=product1/1000000;
product=product/10000;
if (product1==product){
 return 1;
 }else{return 0;};
};


void main(){
ofstream answers;
char joe;
unsigned long m1,m2=365;
unsigned long product,product1;
answers.open("math.nbr");
for (m1=64252;m1<65535;m1++){
 product=m1 * 365;
 product1=product;
 if (check(product1)==1){
 cout <<"\n" << product;
 cin >> joe;
 };
};
answers.close();
};