// Jesse Anderson
// Confor Shell version 1.0
// September, 1996

//#include<c:\bread\cnfp3.h>
#include<c:\bread\screen.h>
#include<c:\bread\runtest.h>
#include<iostream.h>
#include<dir.h>
#include<string.h>
#include<dirent.h>

const max_num_names=180;
const max_name_size=13;
const winatt = 10;
const boratt = 31;
const highatt = 116;
const texatt = 5;


//*******************************************************
class window{
 // base class for all windows
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

class errormenu:private window{
 public:
  void run();
};

class textmenu:public inputmenu{
 public:
  textmenu(int minx,int miny,int maxx,int maxy,int input_lngth);
  int test_file_name();
  int keyhandler();
  void next_window();
  char input[55];
};

//*****************************************************************
mainmenu main1(5,5,30,9);
convertmenu convert1(12,8,43,11);
int num_runs;
int current_window;
// three filenames required for learning conversion
char learning_input_name[55];
char dict_output_name[55];
char learn_output_name[55];
// three filenames required for learning conversion
char recogn_input_name[55];
char dict_input_name[55];
char recogn_output_name[55];
// two filenames required for multiple test runs
char recogn_table_output_name[55];
char learn_test_output_name[55];

void filerr(){
errormenu error1;
error1.run();
};

void run_tests(){
 current_window=8;
 nummenu num_tests(20,10,58,15,2);
 num_tests.text="        Enter the number of \n       tests you wish to run.";
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
 int error_flag;
 do{
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
			 case 2:{load_win_att(x1,y1,x2,y2,8);
						run_tests();
						break;};
			 case 3:{exit(0);
				break;};
			 };
			break;
			};
  case 27:{
			error_flag=1;
			break;
			};
  };
 } while (error_flag!=1);
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
	break;
	};
  case 13:{
	switch (current_row){
	 case 1:{
	  load_win_att(x1,y1,x2,y2,8);
	  current_window=1;
	  textmenu learn1(9,16,69,22,55);
	  learn1.text="   Enter the path and name of the input file (space \n   delimited) containing the dictionary and learning data";
	  learn1.run();
	  break;
	  };
	 case 2:{
	 current_window=5;
	 textmenu rec1(9,16,69,22,55);
	 rec1.text="        Enter the path and name of the \n     input file containing recognition data.";
	 rec1.run();
	 clear_win(x1,y1,x2,y2);
	  break;
	  };
	 }; //switch
	};  //case 13
  }; //switch keyhandler
};

//
//*******************************************************

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
char joe;
int ascii,nbr=1,scan,error_flag=0;
 gotoxy(x1+textofs-1,y2-3);
input[0]=0;
input[1]=0;
do{get_scan(scan,ascii);
	if ((ascii > 40) && (ascii < 58) && (nbr<=inputlength)){
	 cout << (char)ascii;
	 input[nbr-1]=(char)ascii;
	 if (nbr==inputlength){
	  gotoxy(x1+textofs,y2-3);
					  nbr=1; };
	 nbr++;
	}else{
	switch (scan){
	 case 0xE:{		gotoxy(x1+17,y2-3);
				nbr=1;
		   break;}; // backspace
	 case 0x4B:{
				gotoxy(x1+17,y2-3);
				nbr=1;
			  break;};  // left
	 case 0x4D:{
				gotoxy(x1+18,y2-3);
				input[0]=0;
				nbr=2;
			  break;};  // right

	 }; //switch scan
	switch(ascii){
	 case 32:{
		  //gotoxy(x1+18,y2-3);
		  cout << " ";
		  input[0]=0;
		  nbr=2;
		  break;
		  };
	 case 13:{ num_runs=(((input[0]-48)*10) + (input[1]-48));
		   if ((input[1]-48 > 0) || (input[0]-48 >0)){
			 error_flag=0;
			 load_win_att(x1,y1,x2,y2,8);
			 clear_win(x1,y1,x2,y2);
			 current_window=9;
			 textmenu run2(9,16,69,22,55);
			 run2.text="some file name";
			 run2.run();
			error_flag=1;};
			 break;};
	 case 27:{clear_win(x1,y1,x2,y2);
		  error_flag=1;
		  break;};
	 };  // switch ascii
			}; //end else
 }while (error_flag!=1);
};

//*******************************************************
textmenu::textmenu(int minx,int miny,int maxx,int maxy,int input_lngth){
 inputlength=input_lngth;
 x1=minx;
 x2=maxx;
 y1=miny;
 y2=maxy;
 textofs=((x2-x1-inputlength+1)/2);
 max_row=y2-y1-1;
 };

int textmenu::keyhandler(){
int ascii,nbr=0,scan,error_flag=0;
 gotoxy(x1+textofs-1,y2-3);
do{get_scan(scan,ascii);
	if ((ascii > 31) && (ascii < 127) && (nbr< inputlength-2)){
	 cout << (char)ascii;
	 input[nbr]=(char)ascii;
	 if (nbr==inputlength){
	  gotoxy(x1+textofs,y2-3);
	  nbr; };
	 nbr++;
	}else{
	switch (scan){
	 case 0x4B:{
				if (nbr>=0){
				 nbr--;
				 gotoxy(x1+textofs+nbr,y2-3);};
			  break;};  // left
	 case 0x4D:{
				if (nbr < inputlength-2){
				 nbr++;
				 gotoxy(x1+textofs+nbr,y2-3);};
			  break;};  // right
	 }; //switch scan

	switch(ascii){
	 case 8:{if  (nbr>0){
				nbr--;
				gotoxy(x1+textofs+nbr,y2-3);
				cout << ' ';
				gotoxy(x1+textofs+nbr,y2-3);
				input[nbr-1]='\0'; };
				break;};
	 case 13:{error_flag=1;
		   clear_win(x1,y1,x2,y2);
		   next_window();
		  //test the filename
		   break;};
	 case 27:{ error_flag=1;
		   clear_win(x1,y1,x2,y2);
		    convertmenu convert2(12,8,43,11);
		    convert2.run();
				 break;};
	 };  // switch ascii
			}; //end else
 }while (error_flag!=1);
};

int textmenu::test_file_name(){
ifstream testfile;
testfile.open(input);
if (testfile.fail()){
return -1;}else return 1;
};

void textmenu::next_window(){
switch (current_window){
 case 1:{ current_window=2;
	  textmenu learn2(9,16,69,22,55);
	  learn2.text="  Enter the name of the dictionary file that \n        will be created. ";
	  learn2.run();
	break;};
 case 2:{ current_window=3;
	  textmenu learn3(9,16,69,22,55);
	  learn3.text="  Enter the name of the learning file that \n          will be created. ";
	  learn3.run();
	 break;};
 case 3:{ current_window=4;
	  textmenu done1(9,17,45,22,2);
	  done1.text="     File Conversion Completed.\n \n               OK";
	  done1.run();
	  break;};
 case 4:{break;};
 case 5:{ current_window=6;
	  textmenu rec2(9,16,69,22,55);
	  rec2.text="      number three please ";
	  rec2.run();
	break;};
 case 6:{ current_window=3;
	  textmenu rec3(9,16,69,22,55);
	  rec3.text=" 	then number four";
	  rec3.run();
	break;};
 case 7:{break;};
 case 8:{break;};
 case 9:{ current_window=10;
	  textmenu run3(9,16,69,22,55);
	  run3.text="some other file name";
	  run3.run();
	 break;};
 case 10:{current_window=11;
	  textmenu done2(9,16,69,22,0);
	  done2.text="finished here!";
	  done2.run();
	  break;};
 };
};
//*******************************************************

void inputmenu::run(){
 draw();
 load_win_att(x1,y1,x2,y2,boratt);
// inputlength=2;
 load_win_att(x1+textofs,y2-2,x1+inputlength-1+textofs,y2-2,texatt);
 load_string(x1+1,y1+1,text);
 (void)keyhandler();
 };

//*******************************************************
/*int run_learning_conversion(char learning_input_name[55];
			char dict_output_name[55];
			char learn_output_name[55];){

};
//*******************************************************
int run_recognition_conversion(char recogn_input_name[55];
			       char dict_input_name[55];
			       char recogn_output_name[55];){
};
//*******************************************************
int run_multiple_tests(char recogn_table_output_name[55];
		       char learn_test_output_name[55];){
};
//*******************************************************
  */
void open(){
 clr_scr();
 clr_att();
 load_win_att(1,1,80,1,boratt);
 load_string(33,1,"Confor Shell");
// blow_cursor();
 main1.run();
 };

void do_tests(){
 random_learning random;
 random.run_tests();
};

void main(int argc, char *argv[]){
if (argv[1][0]=='r'){
 do_tests();
 }else{
 open();};

};


