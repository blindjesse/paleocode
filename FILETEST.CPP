/* findfirst and findnext example */

#include <stdio.h>
#include <iostream.h>
#include <dir.h>

int main(void)
{
   struct ffblk ffblk;
   int joe;
   int done;
   cout << "Directory listing of *.*";
   done = findfirst("*.*",&ffblk,0);
   while (!done)
   {
      cout << ffblk.ff_name;
      done = findnext(&ffblk);
   }
   cin >> joe;
   return 0;
}
