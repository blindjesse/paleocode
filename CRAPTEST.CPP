#include<iostream.h>
#include<fstream.h>

char *name="c:\\jesse\\elmt1.txt";
ifstream file;
char ch;

void main(){
 file.open(name);
 do{
 file.get(ch);
 cout << (int)ch << ' ';
  }while(!file.eof());
};