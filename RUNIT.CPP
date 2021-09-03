// Jesse Anderson
// The Real Confor Shell Program
#include <iostream.h>
#include <windows.h>
char *path = "c:\jesse\confor\confor.exe";
char *arg  = "c:\jesse\confor\confor.exe";
char *edit= "calc" ;
unsigned int bread=0;

void OwlMain(int, char *[]){
bread = WinExec(path,SW_SHOWNORMAL);
};
