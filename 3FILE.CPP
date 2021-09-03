#include <ctype.h>
#include <iostream.h>
#include <fstream.h>
#include <conio.h>
#include <string.h>
#include <iomanip.h>

#define out_file "testout"

const char blank=' ';
const char enter='\n';

void main()
{
clrscr();
ifstream fs;
ofstream as;

char ch;
int numwords,numletters;
char in_file[40];
cout << " File?: ";
cin  >> in_file;

as.open(out_file);
fs.open (in_file);
if (fs.fail())
	cerr << "Could Not Find " << in_file;
else
{                           o
 numletters=0;
 numwords=0;
 while (!fs.eof())
  {
    fs.get(ch);
    if ((ch!=blank) && (ch!=enter))
     {
      as.put(ch);
      numletters++;
     }
    else
    {
     as.put(blank);
     as << numletters;
     as.put(enter);
     numletters=0;
     numwords++;
    }
  }
as << "\n \n \n \n" << "Number of words: " << numwords;
cout << "Thank you you for using our program, "<< endl;
fs.close();
as.close();
}
}