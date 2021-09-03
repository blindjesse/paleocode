#include <c:\bread\screen.h>
#include <stdlib.h>
#include <math.h>
#include <iostream.h>

// Jesse's Genetic Workshop
// Version .99 alpha 1
// January, 1996

const pop_size=20;
const num_children=5;
const unsigned int max_mem_size=65536;
const max_bit_size=16;
int init=1;

class genetic{
public:
 int population[pop_size];
 int bad_ones[num_children];
 unsigned long fitness[pop_size];
 char parent1[max_bit_size],parent2[max_bit_size];
 void first_population();
 void breed();
 char *uint2string(unsigned int num);
 unsigned int string2uint(char string[]);
 void calc_fitness();
 unsigned long fofx(unsigned int num);
 int convergence();
 void insert_children();
 void seed_out();
};

void genetic::first_population(){
 for (int nbr=0;nbr<pop_size;nbr++)
  population[nbr]=random(max_mem_size);
};

void genetic::calc_fitness(){
 for (int nbr=0;nbr<pop_size;nbr++)
  fitness[nbr]=fofx(population[nbr]);
};

char *genetic::uint2string(unsigned int num){
 char temp[max_bit_size];
 for (int nbr=0;nbr<16;nbr++)
  if (num & Raise(2,nbr))
   temp[nbr]=1;
 return temp;
};

unsigned int string2uint(char string[]){
unsigned int number;
for(int nbr=0;nbr<max_bit_size;nbr++)
 if (string[nbr]==1)
  number+=Raise(2,nbr);
return number;
};

int genetic::convergence(){
int nbr1;
for (int nbr=0;nbr<pop_size;nbr++)
 cout << population[nbr] << "\n";
cout << "Good enough?  Hit 1.  Otherwise bang it.";
cin >> nbr1;
if (nbr1==1)
 return 1;
};

void genetic::insert_children(){
 for (int nbr1=0;nbr1<num_children-1;nbr1++)
  population[bad_ones[nbr1]]=random(max_mem_size);
};

void genetic::seed_out(){
for (int nbr=0;nbr<num_children-1;nbr++)
 bad_ones[nbr]=0;
for (int nbr1=0;nbr1<pop_size;nbr1++){
// check the least places first and then shift em down accordingly
 if (population[nbr1]<population[bad_ones[0]]){
  for (int nbr2=num_children;nbr2>0;nbr2--)
   bad_ones[nbr2]=bad_ones[nbr2-1];
   bad_ones[0]=nbr1;
  }else
    if (population[nbr1]<population[bad_ones[1]]){
      for (int nbr2=num_children;nbr2>1;nbr2--)
       bad_ones[nbr2]=bad_ones[nbr2-1];
       bad_ones[1]=nbr1;
    }else
     if (population[nbr1]<population[bad_ones[2]]){
      for (int nbr2=num_children;nbr2>2;nbr2--)
       bad_ones[nbr2]=bad_ones[nbr2-1];
       bad_ones[2]=nbr1;
     }else
      if (population[nbr1]<population[bad_ones[3]]){
       for (int nbr2=num_children;nbr2>3;nbr2--)
	bad_ones[nbr2]=bad_ones[nbr2-1];
	bad_ones[3]=nbr1;
      }else
       if (population[nbr1]<population[bad_ones[4]]){
	for (int nbr2=num_children;nbr2>4;nbr2--)
	 bad_ones[nbr2]=bad_ones[nbr2-1];
	 bad_ones[4]=nbr1;
      };
 };
};

unsigned long genetic::fofx(unsigned int guess){
// this function is x^2
return Raise(guess,2);
};

void breed(){
};

void main(){
genetic genetic1;
genetic1.breed();
};