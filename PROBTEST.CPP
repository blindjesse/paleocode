// and/or probability charts
// program written 2/20/97
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream.h>

const numbits=10000;

class prob{
public:
 int function; // 1=or 0=and
 int string1[numbits];
 int string2[numbits];
 int child[numbits];
 float prob1;
 float prob2;
 prob();
 void run();
 void andem();
 void orem();
 void xorem();
 void compare();
};

prob::prob(){
 randomize();
 for(int nbr1=0;nbr1<numbits;nbr1++){
  string1[nbr1]=random(2);
  string2[nbr1]=random(2);
  };
 };

void prob::orem(){
 for (int nbr1=0;nbr1<numbits;nbr1++)
  child[nbr1]=string1[nbr1]||string2[nbr1];
};

void prob::xorem(){
 for (int nbr1=0;nbr1<numbits;nbr1++)
  child[nbr1]=string1[nbr1]^string2[nbr1];
};

void prob::andem(){
 for (int nbr1=0;nbr1<numbits;nbr1++)
  child[nbr1]=string1[nbr1]&&string2[nbr1];
};

void prob::compare(){
 int same1=0,same2=0;
 for (int nbr1=0;nbr1<numbits;nbr1++){
  if (string1[nbr1]==child[nbr1])
   same1++;
  if (string2[nbr1]==child[nbr1])
   same2++;
  };
 prob1=(float)same1/(float)numbits;
 prob2=(float)same2/(float)numbits;
};

void prob::run(){
 int nbr1;
 clrscr();
 cout << "Enter operation\n2 - xor\n1 - or\n0 - and\n: ";
 cin >> function;
 if (function==1)
  orem(); else if (function==0)
   andem(); else if (function==2)
   xorem();
 compare();
 cout << "\nThis run had "<<numbits<<" bits in each parent. ";
 cout << "\nHere are the first thirty bits in the strings: ";
 cout << "\nString 1: ";
 for (nbr1=0;nbr1<30;nbr1++)
  cout << string1[nbr1] << " ";
 cout << "\nString 2: ";
 for (nbr1=0;nbr1<30;nbr1++)
  cout << string2[nbr1] << " ";
 cout << "\nChild:    ";
 for (nbr1=0;nbr1<30;nbr1++)
  cout << child[nbr1] << " ";
 cout << "\n\nAnd here are the percentages of bits identical between parent and child: ";
 cout << "\nSame in String 1 and Child: " << prob1;
 cout << "\nSame in String 2 and Child: " << prob2;
 cout << "\nHit '1' to run more tests: ";
};

void main(){
 char again;
do{
prob prob1;
prob1.run();
 again=getch();
 }while(again=='1');
};