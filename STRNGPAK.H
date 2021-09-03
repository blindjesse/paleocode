
// String Package version 1.0 for C++
#include <stdlib.h>
#include <iostream.h>
#include <dos.h>

void instring(char string[], char delimiter);
void outstring(char string[]);
void copy(char one[], char two[]);
void concat (char original[], char added[]);
int compare (char one[], char two[]);
int length(char string[]);
char get_ascii();

char get_ascii(){
 union REGS regs;
 regs.h.ah=0;
 int86(0x16,&regs,&regs);
 return regs.h.al;
};

int length(char string[]){
 for (int loop=0;string[loop]!='\0';loop++){};
 return loop;
};

void instring(char string[], char delimiter){
 int nbr=0;
 string[nbr]=get_ascii();
while (string[nbr]!=delimiter){
  cout << string[nbr];
  if ((string[nbr]==(char)8)&&(nbr>0)){
   cout << ' ' << (char)8 ;
   nbr--;}else{
  nbr++;};
  string[nbr]=get_ascii();
 };
 string[nbr]='\0';
};

void outstring(char string[]){
int nbr,len;
nbr=0;
len=length(string);
 while (nbr<len){
  cout << string[nbr];
  nbr++;
 };
};

void copy(char get[], char give[]){
int nbr, lengive;
nbr=0;
lengive=length(give);
while (nbr<=lengive){
 get[nbr]=give[nbr];
 nbr++;
 };
};

void concat (char original[], char added[]){
int nbr=0,lenorig,lenadd;
lenorig=length(original);
lenadd=length(added);
for (nbr=0; nbr<=lenadd; nbr++){
 original[nbr+lenorig]=added[nbr];
 };
};

int compare (char one[], char two[]){
// -1 means they didn't match
//  1 means they did
 int nbr,lenone,lentwo,larger;
 nbr=0;
  while((one[nbr]==two[nbr])&&(nbr<length(one))){nbr++;
   };
   if (nbr==length(one)){
   return 1;
   }else{
    return 0;} //zero was returned her because that is the C++ default
};


int firstocc(char string[], char find){
 int len,nbr=0;
len=length(string);
while ((string[nbr]!=find)&&(nbr<=len)){
 nbr++;};
if (nbr>len){
 return -1; // -1 was returned here b/c zero could be an array spot
 }else{
 return nbr;
 };
};

int lastocc(char string[], char find){
int nbr;
nbr=length(string);
while ((string[nbr]!=find)&&(nbr>=0)){
 nbr--;
 };
return nbr;
};