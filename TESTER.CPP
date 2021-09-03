#include <c:\bread\strngpak.h>
#include <conio.h>

void main(){
 char string1[30],string2[30];
 char nick;
 clrscr();
 cout << "Input a string: ";
 instring(string1,13);
 cout << "\n\nThe string has been copied to another string and that string has been \nplaced at the end of the first: ";
 copy(string2,string1);
 concat(string1,string2);
 outstring(string1);
 cout << "\n\nThis is the result of a comparison between string1 and string2: ";
 cout <<' '<< compare(string1,string2);
 cout << "\n\nstring1 has been copied to string2: ";
 copy (string2,string1);
 outstring(string1);
 cout << ' ';
 outstring(string2);
 cout << "\n\nThis is the result of a comparison between string1 and string2: ";
 cout << ' ' << compare(string1,string2);
// cout << ' '     << firstocc(string1,'s');
// cout << ' ' << lastocc(string1, 's');
 cin >> nick;
};