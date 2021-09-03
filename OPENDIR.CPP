/*dir and readdir example */

/* opendir.c - test opendir(), readdir(), closedir() */

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
 
void scandir(char *dirname)
{
   DIR *dir;
   struct dirent *ent;
 
   printf("First pass on '%s':\n",dirname);
   if ((dir = opendir(dirname)) == NULL)
   {
     perror("Unable to open directory");
	  exit(1);
   }
   while ((ent = readdir(dir)) != NULL)
	  printf("%s\n",ent->d_name);

	printf("Second pass on '%s':\n",dirname);
	rewinddir(dir);
	while ((ent = readdir(dir)) != NULL)
	  printf("%s\n",ent->d_name);
	if (closedir(dir) != 0)
	  perror("Unable to close directory");
}

void main(int argc,char *argv[])

{
	if (argc != 2)
	{
	  printf("usage: opendir dirname\n");
	  exit(1);
	}
	scandir(argv[1]);
	exit(0);
}




