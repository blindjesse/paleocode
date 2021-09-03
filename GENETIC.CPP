// Second version of my project
#include <stdlib.h>
#include <iostream.h>

const num_children=2;
const pop_size=30;
const num_bits=32;

class genetic{
public:
 float population[pop_size];
 // this is typed as long, but until we find a random number generator with
 // 32 bit returns or write one ourselves, the numbers will only be so large
 // another consideration is the introduction of negative numbers somewhere
 // along the way.  i imagine this will be one of the most important functions
 // in the program.  and now it's gotta do floats too!
 float fitness[pop_size];
 float ideal_fitness;
  // this will be assigned at the time the function is selected by the user
 unsigned char parent1[num_bits],parent2[num_bits];
 unsigned char child[num_bits];
   // records the position of the least fit members according to their spots
   // in the population array
 int technique;
  // this holds the breeding technique we will use
 genetic();
 void new_population();
 long function1(int citizen);
 void one_point_cross();
 void two_point_cross();
 void uniform_cross(); // i have yet to understand this
 void raoc();
 void find_least_fit();
 // this will just put the num_children least fit starting at the beginning
 // of the population
 void find_most_fit();
 // this will just put the num_children most fit starting at the end of the
 // population
 void next_generation();
 int convergence();
 void run();
};

genetic::genetic(){
randomize();
ideal_fitness=13;
new_population();
clrscr();
cout <<  "Which breeding technique would you like to use?\n";
cout <<  "1. One-point crossover\n";
cout <<  "2. Two-point crossover\n";
cout <<  "3. Uniform crossover\n";
cout <<  "4. RAOC\n";
cin >> technique;
};

void genetic::new_population(){
for (int nbr1=0;nbr1<pop_size;nbr1++)
 population[nbr1]=random(RAND_MAX);
for (int nbr1=0;nbr1<pop_size;nbr1++)
  fitness[nbr1]=function1(nbr1);
};

void genetic::find_least_fit(){
// limit the bounds!
for (int nbr3=0;nbr3<num_children-1;nbr3++)
 for (int nbr2=nbr3+1;nbr2<pop_size;nbr2++){
  if (fitness[nbr2]-ideal_fitness>fitness[nbr3]-ideal_fitness)
   population[nbr3]=population[nbr2];
   };
};

void genetic::find_most_fit(){
// limit the bounds!
for (int nbr3=0;nbr3<num_children-1;nbr3++)
 for (int nbr2=pop_size-nbr3;nbr2>num_children-1;nbr2--){
  if (fitness[nbr2]-ideal_fitness<fitness[20-nbr3]-ideal_fitness)
   population[pop_size-nbr3]=population[nbr2];
   };
};

long genetic::function1(int citizen){
// answer = 13;
 return population[citizen]+13;
};

void one_point_cross(){

};

void two_point_cross();

void uniform_cross(); // i have yet to understand this

void raoc();

void genetic::next_generation(){
// breed
switch (technique){
 case 1:{
  one_point_cross();
  break;
  };
 };
for (int nbr1=0;nbr1<pop_size;nbr1++)
  fitness[nbr1]=function1(nbr1);
};

int genetic::convergence(){
char yesno;
cout << '\n';
for (int nbr1=0;nbr1<pop_size;nbr1+=3){
 cout << population[nbr1] << " " << population[nbr1+1] << " " << population[nbr1+2] << '\n';
 }
cout <<"\nProcess new generation? (y/n)\n";
cin >>  yesno;
if (yesno=='y')
 return 0; else
 if (yesno=='n')
  return 1;
};

void genetic::run(){
 do{
  find_least_fit();
  find_most_fit();
  next_generation();
  }while (!convergence());
};

void main(){
genetic ga1;
ga1.run();
};