// and/or probability charts
// program written 2/20/97 as prob2.cpp
// program updated 3/1/97 and renamed prob3.cpp
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream.h>
#include <fstream.h>


const numbits=5000;

class prob{
public:
 int function; // 1=or 0=and
 unsigned long numruns;
 int string1[numbits];
 int string2[numbits];
 int child1[numbits];
 int child2[numbits];
 float prob1c1;
  // holds the percentage of parent 1 in child 1
 float prob2c1;
  // holds the percentage of parent 2 in child 1
 float prob1c2;
  // holds the percentage of parent 1 in child 2
 float prob2c2;
  // holds the percentage of parent 2 in child 2
 float olprob1c1;
 float olprob2c1;
 float olprob1c2;
 float olprob2c2;
 char *datafile;
 ifstream idata;
 ofstream odata;
 prob();
 void first_run();
 void run();
 void save();
 void raocem();
 void one_point();
 void two_point();
 void uniform();
 void aosunem();
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
 cout << "Enter operation\n0 - randomized and/or crossover ";
 cout << "\n1 - one-point crossover ";
 cout << "\n2 - two-point crossover ";
 cout << "\n3 - uniform crossover ";
 cout << "\n4 - and/or uniform crossover\n: ";
 cin >> function;
 switch(function){
  case 0:{
   raocem();
   break;
   };
  case 1:{
   one_point();
   break;
   };
  case 2:{
   two_point();
   break;
   };
  case 3:{
    uniform();
    break;
   };
  case 4:{
    aosunem();
    break;
   };
  };
 compare();
 save();
};

void prob::raocem(){
int temp1,choose;
for (int nbr1=0;nbr1<numbits;nbr1++){
 temp1=rand();
 if (rand()<temp1){
  child1[nbr1]=string1[nbr1]||string2[nbr1];
  child2[nbr1]=string1[nbr1]&&string2[nbr1];
   }else {
  child1[nbr1]=string1[nbr1]&&string2[nbr1];
  child2[nbr1]=string1[nbr1]||string2[nbr1];
   };
 };
};

void prob::aosunem(){
 int choose;
 for (int nbr1=0;nbr1<numbits;nbr1++){
  choose=random(2);
  if (choose==1){
  child1[nbr1]=string1[nbr1]||string2[nbr1];
  child2[nbr1]=string1[nbr1]&&string2[nbr1];
   }else if (choose==0){
  child1[nbr1]=string1[nbr1]&&string2[nbr1];
  child2[nbr1]=string1[nbr1]||string2[nbr1];
   };
  };
};

void prob::one_point(){
int randum;
int nbr1;
randum=random(numbits);
for (nbr1=0;nbr1<randum;nbr1++){
 child1[nbr1]=string1[nbr1];
 child2[nbr1]=string2[nbr1];
 };
for (nbr1=randum;nbr1<numbits;nbr1++){
 child1[nbr1]=string2[nbr1];
 child2[nbr1]=string1[nbr1];
 };
};

void prob::two_point(){
int randum1,randum2;
int nbr1;
randum1=random(numbits);
randum2=random(numbits);

for (nbr1=0;nbr1<((randum1<randum2)?randum1:randum2);nbr1++){
 child1[nbr1]=string1[nbr1];
 child2[nbr1]=string2[nbr1];
 };
for (nbr1=((randum1<randum2)?randum1:randum2);nbr1<((randum1>randum2)?randum1:randum2);nbr1++){
 child1[nbr1]=string2[nbr1];
 child2[nbr1]=string1[nbr1];
 };
for (nbr1=((randum1>randum2)?randum1:randum2);nbr1<numbits;nbr1++){
 child1[nbr1]=string1[nbr1];
 child2[nbr1]=string2[nbr1];
 };
};

void prob::uniform(){
int crossmask[numbits];
int nbr1;
for (nbr1=0;nbr1<numbits;nbr1++)
 crossmask[nbr1]=random(2);
for (nbr1=0;nbr1<numbits;nbr1++){
 if (crossmask[nbr1]==1){
  child1[nbr1]=string1[nbr1];
  child2[nbr1]=string2[nbr1];
  }else{ if (crossmask[nbr1]==1){
  child2[nbr1]=string1[nbr1];
  child1[nbr1]=string2[nbr1];
   };
  };
 };
};

void prob::compare(){
 int same11=0,same21=0;
 int same12=0,same22=0;
 for (int nbr1=0;nbr1<numbits;nbr1++){
  if (string1[nbr1]==child1[nbr1])
   same11++;
  if (string2[nbr1]==child1[nbr1])
   same21++;
  if (string1[nbr1]==child2[nbr1])
   same12++;
  if (string2[nbr1]==child2[nbr1])
   same22++;
  };
 prob1c1=(float)same11/(float)numbits;
 prob2c1=(float)same21/(float)numbits;
 prob1c2=(float)same12/(float)numbits;
 prob2c2=(float)same22/(float)numbits;
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
   raocem();
   break;
   };
  case 1:{
   one_point();
   break;
   };
  case 2:{
   two_point();
   break;
   };
  case 3:{
   uniform();
   break;
   };
  case 4:{
   aosunem();
   break;
   };
 };
 compare();
 idata.open(datafile);
 idata >> numruns >> olprob1c1 >> olprob2c1 >> olprob1c2 >> olprob2c2;
 idata.close();
 olprob1c1*=numruns;
 olprob2c1*=numruns;
 olprob1c2*=numruns;
 olprob2c2*=numruns;
 prob1c1+=olprob1c1;
 prob2c1+=olprob2c1;
 prob1c2+=olprob1c2;
 prob2c2+=olprob2c2;
 numruns++;
 prob1c1/=numruns;
 prob2c1/=numruns;
 prob1c2/=numruns;
 prob2c2/=numruns;
 save();
};

void prob::save(){
odata.open(datafile);
odata << numruns << " " << prob1c1 << " "  << prob2c1 <<" "<<prob1c2<<" "<<prob2c2<<" "<< function;
odata.close();
};

void main(){
 char again;
 prob prob1;
 prob1.first_run();
do{
 prob1.run();
 gotoxy(1,8);
 cout <<"\n"<< prob1.numruns << " sets of " << numbits << " bits.\nP1C1: " << prob1.prob1c1 << "\nP2C1: " << prob1.prob2c1;
 cout << "\nP2C2: " << prob1.prob2c2 << "\nP1C2: " << prob1.prob1c2 ;
 }while((!kbhit())&&(prob1.numruns<420000));
};