#include<c:\jesse\screen\screen.h>
#include<iostream.h>
#include <dir.h>
#include <string.h>
#include <dirent.h>

const max_num_names=180;
const max_name_size=13;
const winatt = 10;
const boratt = 31;
const highatt = 116;
const texatt = 5;


//*******************************************************
class window{
 protected:
  virtual void draw(int batt=boratt,int watt=winatt);
  virtual void row_att(int row,int att=highatt);
  void row_text(int row, char *text);
  virtual int keyhandler();
  int border_att, window_att, highlight_att;
  int current_row,max_row;
  int x1,y1,x2,y2;
 };

class mainmenu:private window{
 public:
  mainmenu(int minx,int miny,int maxx,int maxy);
  void run();
 };

class convertmenu:private window{
 public:
  convertmenu(int minx, int miny, int maxx, int maxy);
  void run();
 };

class inputmenu:protected window{
 public:
  void run();
  char *text;
  int inputlength,textofs;
};
class nummenu:public inputmenu{
 public:
  nummenu(int minx,int miny,int maxx,int maxy,int input_lngth);
  int keyhandler();
  char input[2];
};

class textmenu:private inputmenu{
 public:
  textmenu(int minx,int miny,int maxx,int maxy,int input_lngth);
  int keyhandler();
  char input[55];
};

class openmenu:private window{
 public:
  char *title;
  openmenu(int minx, int miny, int maxx, int maxy);
  int keyhandler();
  void run();
  void draw();
  void row_att (int row,int att=highatt);
  void fill_name_array();
  int test_file();
  void clear_file_names();
  void load_file_names();
  int test_file_name();
  int numnames;
  char names[max_num_names][max_name_size];
  char filename[max_name_size];
  char *current_directory_name;
  int x1a,y1a,x1b,y1b,x2a,y2a,x2b,y2b,x3a,y3a,x3b,y3b,x4a,y4a,x4b,y4b;
  int fileofs,nameofs;
  };

class errormenu:private window{
 public:
  void run();
};

//*****************************************************************
mainmenu main1(5,5,30,9);
openmenu open1(13,5,62,22);
convertmenu convert1(12,8,43,11);

void filerr(){
errormenu error1;
error1.run();
};

void run_tests(){
 nummenu num_tests(20,10,58,15,2);
 num_tests.text="        Enter the number of \\n       tests you wish to run.";
 num_tests.run();
};

//*****************************************************************
void window::draw(int batt,int watt){
 clear_win(x1,y1,x2,y2);
 make_win_border(x1,y1,x2,y2);
 load_win_att(x1,y1,x2,y2,batt);
 load_win_att(x1+1,y1+1,x2-1,y2-1,watt);
 };

void window::row_att(int row, int att){
 load_win_att(x1+1,y1+row,x2-1,y1+row,att);
};

void window::row_text(int row, char *text){
 load_string(x1+1,y1+row,text);
};

int window::keyhandler(){
 int scan,ascii,error_flag=0;
 do{
  get_scan(scan,ascii);
  switch (scan){
	case 0x48:{if (current_row > 1) {
				row_att(current_row,winatt);
				current_row--;
				row_att(current_row);
								};
			  break;
			 };
	case 0x50:{if (current_row < max_row) {
				row_att(current_row,winatt);
				current_row++;
				row_att(current_row);
								};
				break;
			 };
	 }; //switch scan
  switch(ascii){
	case 13:{error_flag=1;
				break;
		  };
	case 27:{error_flag=1;
				};
	};
  }while(error_flag!=1);
 return ascii;
};

//*******************************************************

mainmenu::mainmenu(int minx, int miny, int maxx, int maxy){
 x1=minx;
 x2=maxx;
 y1=miny;
 y2=maxy;
 max_row=y2-y1-1;
};

void mainmenu::run(){
 draw();
 row_text(1,"  Convert Files");
 row_text(2,"  Run Tests");
 row_text(3,"  Exit to DOS");
 row_att(1);
 current_row=1;
 switch (keyhandler()){
  case 13:{
			switch (current_row){
			 case 1:{load_win_att(x1,y1,x2,y2,8);
						convert1.run();
						break;
						};
			 case 2:{run_tests();
						break;};
			 };
			break;
			};
  case 27:{
			break;
			};
  };

};

//*******************************************************

convertmenu::convertmenu(int minx, int miny, int maxx, int maxy){
 x1=minx;
 x2=maxx;
 y1=miny;
 y2=maxy;
 max_row=y2-y1-1;
};

void convertmenu::run(){
 draw();
 row_text(1,"  Convert Learning Files");
 row_text(2,"  Convert Recognition Files");
 row_att(1);
 current_row=1;
 switch (keyhandler()){
  case 27:{
	clear_win(x1,y1,x2,y2);
	main1.run();
	};
  case 13:{
	switch (current_row){
	 case 1:{
	  load_win_att(x1,y1,x2,y2,8);
	  open1.run();
	  break;
	  };
	 case 2:{
	  break;
	  };
	 }; //switch
	};  //case 13
  }; //switch keyhandler
};

//
//*******************************************************

openmenu::openmenu(int minx, int miny, int maxx, int maxy){
 current_directory_name=getcwd(NULL,60);
 x1=minx;
 x2=maxx;
 y1=miny;
 y2=maxy;
 max_row=y2-y1-1;
 x1a=x1+4;
 y1a=y1+2;
 x1b=x2-17;
 y1b=y1+2;
 x4a=x1+4;
 y4a=y1+4;
 x4b=x2-17;
 y4b=y2-2;
 x2a=x1+36;
 y2a=y1+3;
 x2b=x1+45;
 y2b=y1+3;
 x3a=x1+36;
 y3a=y1+5;
 x3b=x2-4;
 y3b=y1+5;
};

void openmenu::run(){
int getback;
draw();
getback = keyhandler();
};

void openmenu::clear_file_names(){
 clear_char(x4a,y4a,x4a+13,y4a+12);
 clear_char(x4a+15,y4a,x4b-1,y4a+12);
};

void openmenu::load_file_names(){
int nbr=0;
clear_file_names();
while((nbr < 12) && ((nbr+12*(fileofs-1))<=numnames)){
  if (fileofs>=15){
	fileofs=1;
	nameofs=2;
	fill_name_array();
  };
  load_string(17,9+nbr,names[nbr+12*(fileofs-1)]);
  nbr++;
  };
if ((nbr+12*(fileofs-1))<numnames){
 nbr=0;
 while((nbr < 12) && ((nbr+12*(fileofs))<=numnames)){
  load_string(32,9+nbr,names[nbr+12*(fileofs)]);
  nbr++;
  };
 };
};

void openmenu::draw(){
char joe;
make_win_border(x1,y1,x2,y2);
clear_win(x1+1,y1+1,x2-1,y2-1);
load_win_att(x1,y1,x2,y2,boratt);
load_win_att(x1a,y1a,x1b,y1b,winatt); //filename box (window 1)
load_win_att(x4a,y4a,x4b,y4b,winatt); // files box   (window 4)
load_win_att(x2a,y2a,x2b,y2b,winatt);  //"open" box  (window 2)
load_string(x2a,y2a,"  Open");
load_win_att(x3a,y3a,x3b,y3b,winatt); //"cancel" box  (window 3)
load_string(x3a,y3a,"  Cancel");
load_win_att(31,9,31,20,1);
for (int loop=0; loop < 12; loop++){
  load_char(31,9+loop,179);
 };
fill_name_array();
fileofs=1;
nameofs=1;
load_file_names();
load_string(x1+4,y1+2,names[0]);
row_att(4);
current_row=4;
};

void openmenu::row_att(int row, int att){
/*in this function "row" is really standing for a window.
 in "draw" above, the four windows in the menu are defined.
 here, a number corresponds to each window.  In the last window the
 numbers are used for each separate filename:  it begins with four,
 goes down to 15 and then begins again in the second column, for
 a total of 27 possible rows  */
if (row <4){
 switch (row){
  case 1:{ load_win_att(x1a,y1a,x1b,y1b,att);
			 break;};
  case 2:{ load_win_att(x2a,y2a,x2b,y2b,att);
			 break;};
  case 3:{ load_win_att(x3a,y3a,x3b,y3b,att);
			 break;};
  }; //switch
 }else{if (row<16){
		 load_win_att(x4a,y4a+row-4,x4a+13,y4a+row-4,att);
		 }else{
				 load_win_att(x4a+15,y4a+row-16,x4a+28,y4a+row-16,att);
				 };
  };
};

int openmenu::keyhandler(){
 int scan,ascii,error_flag=0;
 do{
  if (current_row >= 4){
  clear_char(x1a,y1a,x1b,y1a);
  strncpy(filename,names[current_row-4+((fileofs-1)*12)],14);
  load_string(x1a,y1a,filename);
  };
  get_scan(scan,ascii);
  switch (scan){
	case 0x48:{ if (current_row > 4){
					 row_att(current_row,winatt);
					 current_row--;
					 row_att(current_row);};
				  break;};  // up
	case 0x50:{if ((current_row < 27) && (current_row >=4)){
					 row_att(current_row,winatt);
					 current_row++;
					 row_att(current_row);};
				  break;};  // down
	case 0x4B:{	if (current_row > 15){
					 row_att(current_row,winatt);
					 current_row-=12;
					 row_att(current_row);
					 }else{if ((current_row > 3) && (fileofs>1)){
							 fileofs--;
							 load_file_names();
							 };
					  };
				  break;};  // left
	case 0x4D:{	if ((current_row > 3) && (current_row < 16)){
					 row_att(current_row,winatt);
					 current_row+=12;
					 row_att(current_row);
					 }else{if ((current_row > 15) && ((fileofs+1)*12+1)<numnames){
							 fileofs++;
							 load_file_names();
							 };
					  };

				  break;};  // right
	 case 0x0F:{if (current_row>=4){
					 row_att(current_row,winatt);
					 current_row=2;
					 row_att(current_row);
					 }else{ switch(current_row){
								case 2:{row_att(current_row,winatt);
										  current_row++;
										  row_att(current_row);
										  break;
										  };
								case 3:{row_att(current_row,winatt);
										  current_row=1;
										  row_att(current_row);
										  break;
										  };
								case 1:{row_att(current_row,winatt);
										  current_row=4;
										  row_att(current_row);
										  break;
										  };
								};   // switch(current_row)
					 }; //else
					break;}; //tab
	 }; //switch scan

  switch(ascii){

	case 13:{test_file_name();
				break;};
	case 27:{error_flag=1;
				break;};
	};  // switch ascii
  }while(error_flag!=1);
 return ascii;
};

void openmenu::fill_name_array(){
 int loop1=0;
 int nbr=-1;
 DIR *curdir;
 struct dirent *curfilename;
 curdir = opendir(current_directory_name);
 char temp[16];
 curfilename = readdir(curdir);
 for (int loop2=0;loop2<(max_num_names*(nameofs-1));loop2++){
	curfilename = readdir(curdir);
	};
 do{
  nbr++;
  loop1=0;
  cout << curfilename->d_name << " ";
  do{
  temp[loop1]=names[nbr][loop1]=curfilename->d_name[loop1];
  loop1++;
  }while (curfilename->d_name[loop1]!='\0');
//  cout << curfilename->d_name << " ";
  for (int lcv=loop1;lcv>0;lcv--){
	temp[lcv]=temp[lcv-1];
	};
  temp[loop1+1]='\0';
  temp[0]='\\';
//  cout << temp << " ";
  if (opendir(temp)!=NULL){
	 strncpy(names[nbr],temp,13);
	 };
  curfilename = readdir(curdir);
 }while((curfilename->d_name!=NULL) && (nbr <= max_num_names));
 if (curfilename->d_name!=NULL){
  nbr++;
  };
 numnames=nbr;
};


int openmenu::test_file_name(){
DIR *dir;
if (filename[0]=='\\'){
 current_directory_name=filename;
 fill_name_array();
 fileofs=1;
 load_file_names();
 };
};

//*******************************************************

void errormenu::run(){
 x1=23;
 y1=10;
 x2=58;
 y2=16;
 max_row=y2-y1-1;
 draw();
 load_string(x1+1,y1+1,"              ERROR!  ");
 load_string(x1+1,y1+2,"   Unable to verify path and/or  ");
 load_string(x1+1,y1+3,"   filename, please verify both  ");
 load_string(x1+1,y1+4,"          and try again.        ");
 load_string(x1+1,y1+5,"                OK             ");
 load_win_att(x1+14,y1+1,x1+21,y1+1,14+128);
 load_win_att(x1+14,y1+5,x1+21,y1+5,highatt);
 };

//*******************************************************

nummenu::nummenu(int minx,int miny,int maxx,int maxy,int input_lngth){
 inputlength=input_lngth;
 x1=minx;
 x2=maxx;
 y1=miny;
 y2=maxy;
 textofs=((x2-x1-inputlength+1)/2);
 max_row=y2-y1-1;
};

int nummenu::keyhandler(){
int ascii,nbr=1,scan,error_flag=0;
 gotoxy(x1+17,y2-2);
do{get_scan(scan,ascii);
	if ((ascii > 31) && (ascii < 127) && (nbr<=inputlength)){
	 cout << (char)ascii;
	 input[nbr-1]=(char)ascii;
	 if (nbr==inputlength){
	  gotoxy(x1+inputlength+textofs,y2-2);
	  nbr=1; };
	 nbr++;
	}else{
	switch (scan){
	 case 0x4B:{
				gotoxy(x1+17,y2-2);
				nbr=1;
			  break;};  // left
	 case 0x4D:{
				gotoxy(x1+18,y2-2);
				nbr=2;
			  break;};  // right
	 }; //switch scan

	switch(ascii){
	 case 13:{error_flag=1;
				 break;};
	 case 27:{clear_win(x1,y1,x2,y2);
				 main1.run();
				 break;};
	 };  // switch ascii
			}; //end else
 }while (error_flag!=1);
};

//*******************************************************
void inputmenu::run(){
 draw();
 load_win_att(x1,y1,x2,y2,boratt);
// inputlength=2;
 load_win_att(x1+textofs,y1+3,x1+inputlength-1+textofs,y1+3,texatt);
 load_string(x1+1,y1+1,text);
 (void)keyhandler();
 };

//*******************************************************



