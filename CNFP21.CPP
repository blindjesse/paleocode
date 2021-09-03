// Jesse Anderson
// 7/1/96 end of day

#include <iostream.h>
#include <fstream.h>
#include "c:\jesse\convert\cnfp2.h"
#include <conio.h>
void main(){
 int choice=3;
 char ch;
 class learning_conversion convert1;
 class recognition_conversion convert2;
 cout << "Confor File Conversion Utility\n\n";
do{
 cout << "Enter choice of function: \n";
 cout << "  1.  Convert an excel file to dictionary and learning files used by Confor.\n";
 cout << "  2.  Convert an excel file to a recognition file used by Confor.\n";
 cout << "  3.  Exit the program.\n\n: ";
 cin >> choice;
 cin.get(ch);
 switch (choice){
  case 1:
			 convert1.convert_learning();
			 break;
  case 2:
			 convert2.convert_recognition_rows();
			 break;
  case 3: break;
  }; //switch
 }while(choice != 3);
};
