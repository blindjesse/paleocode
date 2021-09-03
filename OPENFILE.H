#include <dir.h>
#include <string.h>
//#include <stdio.h>
#include <dirent.h>

class openfile{
 public:
  openfile();
  int numnames;
  char names[13][500];
  char filename[13];
  char *current_directory_name;
  void fill_name_array();
  int open_file();
  };

openfile::openfile(){
 current_directory_name=getcwd(NULL,60);
};


void openfile::fill_name_array(){
 int nbr=-1;
 DIR *curdir;
 struct dirent *curfilename;
 curdir = opendir(current_directory_name);

 curfilename = readdir(curdir);
 do{
 nbr++;
 strncpy(names[nbr],curfilename->d_name,14);
 curfilename = readdir(curdir);
 }while(curfilename->d_name!=NULL);
 numnames=nbr;
 };
