// and/or probability charts
// program written 2/20/97 as prob2.cpp
// program updated 3/1/97 and renamed prob3.cpp
// program adapted for three parent strings 3/4/97 and renamed prob4.cpp
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
 int string3[numbits];
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
 float prob3c1;
 float prob3c2;
 float olprob1c1;
 float olprob2c1;
 float olprob3c1;
 float olprob1c2;
 float olprob2c2;
 float olprob3c2;
 char *datafile;
 ifstream idata;
 ofstream odata;
 prob();
 void first_run();
 void run();
 void save();
 void rbitem();
 void compare();
};

prob::prob(){
 int nbr1;
 randomize();
 for(nbr1=0;nbr1<numbits;nbr1++){
  string1[nbr1]=random(2);
  string2[nbr1]=random(2);
  string3[nbr1]=random(2);
  };
 datafile="c:\\bread\\probtest.dat";
 };

void prob::first_run(){
 clrscr();
 numruns=1;
 cout << "Enter operation\n0 - rbit\n:  ";
// cout << "\n4
 cin >> function;
 switch(function){
  case 0:{
   rbitem();
   break;
   };
 };
 compare();
 save();
};

void prob::rbitem(){
 int choose;
 for (int nbr1=0;nbr1<numbits;nbr1++){
  choose=random(3);
  if (choose==1){
  child1[nbr1]=string1[nbr1]&&string2[nbr1]||string3[nbr1];
  if (child1[nbr1]==1)
   child2[nbr1]=0; else child2[nbr1]=1;
   }else if (choose==0){
  child1[nbr1]=string2[nbr1]&&string1[nbr1]||string3[nbr1];
  if (child1[nbr1]==1)
   child2[nbr1]=0; else child2[nbr1]=1;
   }else if (choose==2){
  child1[nbr1]=string3[nbr1]&&string1[nbr1]||string2[nbr1];
  if (child1[nbr1]==1)
   child2[nbr1]=0; else child2[nbr1]=1;
   };
  };
};

void prob::compare(){
 int same11=0,same21=0;
 int same12=0,same22=0;
 int same13=0,same23=0;
 for (int nbr1=0;nbr1<numbits;nbr1++){
  if (string1[nbr1]==child1[nbr1])
   same11++;
  if (string2[nbr1]==child1[nbr1])
   same21++;
  if (string1[nbr1]==child2[nbr1])
   same12++;
  if (string2[nbr1]==child2[nbr1])
   same22++;
  if (string3[nbr1]==child1[nbr1])
   same13++;
  if (string3[nbr1]==child2[nbr1])
   same23++;
  };
 prob1c1=(float)same11/(float)numbits;
 prob2c1=(float)same21/(float)numbits;
 prob1c2=(float)same12/(float)numbits;
 prob2c2=(float)same22/(float)numbits;
 prob3c1=(float)same13/(float)numbits;
 prob3c2=(float)same23/(float)numbits;
};

void prob::run(){
 int nbr1;
 randomize();
 for(nbr1=0;nbr1<numbits;nbr1++){
  string1[nbr1]=random(2);
  string2[nbr1]=random(2);
  string3[nbr1]=random(2);
  };
 switch(function){
  case 0:{
   rbitem();
   break;
   };
 };
 compare();
 idata.open(datafile);
 idata >> numruns >> olprob1c1 >> olprob2c1 >> olprob1c2 >> olprob2c2 >> olprob3c1 >> olprob3c2;
 idata.close();
 olprob1c1*=numruns;
 olprob2c1*=numruns;
 olprob1c2*=numruns;
 olprob2c2*=numruns;
 olprob3c1*=numruns;
 olprob3c2*=numruns;
 prob1c1+=olprob1c1;
 prob2c1+=olprob2c1;
 prob1c2+=olprob1c2;
 prob2c2+=olprob2c2;
 prob3c1+=olprob3c1;
 prob3c2+=olprob3c2;
 numruns++;
 prob1c1/=numruns;
 prob2c1/=numruns;
 prob1c2/=numruns;
 prob2c2/=numruns;
 prob3c1/=numruns;
 prob3c2/=numruns;
 save();
};

void prob::save(){
odata.open(datafile);
odata << numruns << " " << prob1c1 << " "  << prob2c1 <<" "<<prob1c2<<" "<<prob2c2<<" "<<prob3c1<<" " << prob3c2<< " "<< function;
odata.close();
};

void main(){
 char again;
 prob prob1;
 prob1.first_run();
do{
 prob1.run();
 gotoxy(1,6);
 cout <<"\n"<< prob1.numruns << " sets of " << numbits << " bits.\nP1C1: " << prob1.prob1c1 << "\nP2C1: " << prob1.prob2c1;
 cout << "\nP2C2: " << prob1.prob2c2 << "\nP1C2: " << prob1.prob1c2 ;
 cout << "\nP3C1: " << prob1.prob3c1 << "\nP3C2: " << prob1.prob3c2;
 }while((!kbhit())&&(prob1.numruns<420000));
};