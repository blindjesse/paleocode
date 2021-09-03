// and/or probability charts
// program written 2/20/97
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream.h>
#include <fstream.h>


const numbits=10000;


class prob{
public:
 int function; // 1=or 0=and
 unsigned long numruns;
 int string1[numbits];
 int string2[numbits];
 int child[numbits];
 float prob1;
 float prob2;
 float olprob1;
 float olprob2;
 char *datafile;
 ifstream idata;
 ofstream odata;
 prob();
 void first_run();
 void run();
 void save();
 void rbitem();
 void andem();
 void orem();
 void xorem();
 void compare();
};

prob::prob(){
 int nbr1;
 randomize();
 for(nbr1=0;nbr1<numbits;nbr1++){
  string1[nbr1]=random(2);
  string2[nbr1]=random(2);
  };
 datafile="c:\\bread\\probtest.dat";
 };

void prob::first_run(){
 clrscr();
 numruns=1;
 cout << "Enter operation\n2 - xor\n1 - or\n0 - and\n3 - rbit\n: ";
 cin >> function;
 if (function==1)
  orem(); else if (function==0)
   andem(); else if (function==2)
   xorem();
 compare();
 save();
};

void prob::rbitem(){
 int choose;
 for (int nbr1=0;nbr1<numbits;nbr1++){
  choose=random(2);
  if (choose==1){
  child[nbr1]=string1[nbr1]||string2[nbr1];
   }else if (choose==0){
  child[nbr1]=string1[nbr1]&&string2[nbr1];
   };
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
 randomize();
 for(nbr1=0;nbr1<numbits;nbr1++){
  string1[nbr1]=random(2);
  string2[nbr1]=random(2);
  };
 switch(function){
  case 0:{
   andem();
   break;
   };
  case 1:{
    orem();
   break;
   };
  case 2:{
   xorem();
   break;
   };
  case 3:{
   rbitem();
   break;
   };
 };
 compare();
 idata.open(datafile);
 idata >> numruns >> olprob1 >> olprob2;
 idata.close();
 olprob1*=numruns;
 olprob2*=numruns;
 prob1+=olprob1;
 prob2+=olprob2;
 numruns++;
 prob1/=numruns;
 prob2/=numruns;
 save();
};

void prob::save(){
odata.open(datafile);
odata << numruns << " " << prob1 << " "  << prob2 <<" " << function;
odata.close();
};

void main(){
 char again;
 prob prob1;
 prob1.first_run();
do{
 prob1.run();
 gotoxy(1,6);
 cout <<"\n"<< prob1.numruns << " sets of 10000 bits.\n" << prob1.prob1 << "\n" << prob1.prob2;
 }while((!kbhit())&&(prob1.numruns<420000));
};