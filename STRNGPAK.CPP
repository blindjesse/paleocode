// String Package version 1.0 for C++
#include <stdlib.h>
#include <iostream.h>

void instring(char *string, char delimiter);
void outstring(char *string);
void copy(char *one, char *two);
void concat (char *original, char *added);
int compare (char *one, char *two);
int length(char *string);

void instring(char *string, char delimiter){
 for (int nbr=0; string[nbr]!=delimiter; string[nbr]++){
  cin >> string[nbr];
 };
};

int length(char *string){
 for (int loop=0;string[loop]!='\0';loop++){};
 return loop;
};

void outstring(char *string){
int nbr,len;
nbr=0;
len=length(string);
 while (nbr<len){
  cout << string[nbr];
 };
};

void copy(char *get, char *give){
int nbr, lengive;
nbr=0;
lengive=length(give);
while (nbr<lengive){
 get[nbr]=give[nbr];
 };
};

void concat (char *original, char *added){
int nbr=0,lenorig,lenadd;
lenorig=length(original);
lenadd=length(added);
for (nbr=lenorig; nbr<(lenorig+lenadd); nbr++){
 original[nbr+lenorig]=added[nbr];
 };
};

int compare (char *one, char *two){
// -1 means they didn't match
//  1 means they did
 int nbr,lenone,lentwo,larger;
 nbr=0;
 if (length(one)!=length(two)){
  return -1;}else{
  while(one[nbr]!=two[nbr]){nbr++;
   };
   if (nbr==length(one)){
   return 1;
   }else{
    return -1;}
  };
};

int firstocc(char *string, char find){
 int len,nbr=0;
len=length(string);
while ((string[nbr]!=find)&&(nbr<=len)){
 nbr++;};
if (nbr>len){
 return -1;
 }else{
 return nbr;
 };
};

int lastocc(char *string, char find);
int nbr;
nbr=length(string);
while ((string[nbr]!=find)&&(nbr>=0)){
 nbr--;
 };
return nbr;
};