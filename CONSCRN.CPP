#include<c:\bread\screen.h>
#include<iostream.h>

const ominx = 5;
const omaxx = 30;
const ominy = 5;
const omaxy = 9;
const winatt = 10;
const boratt = 31;
const highatt = 116;

class conmain{
 public:
  conmain();
  ~conmain();
  void mainmenu();
  void convertmenu();
  void runmenu();
 };

conmain::conmain(){
 clr_scr();
 clr_att();
 load_win_att(1,1,80,1,boratt);
 load_string(33,1,"Confor Shell");
};

conmain::~conmain(){
 clr_scr();
 clr_att();
};

void conmain::mainmenu(){
 int stop=0;
 char ch;
 int ascii,scan;
 int yofs=0;
 int xofs=0;
 load_win_att(ominx,ominy,omaxx,omaxy,boratt);
 make_win_border(ominx,ominy,omaxx,omaxy);
 load_win_att(ominx+1,ominy+1,omaxx-1,omaxy-1,winatt);
 load_string(ominx+3,ominy+1,"Convert Files");
 load_string(ominx+3,ominy+2,"Run Tests");
 load_string(ominx+3,ominy+3,"Exit to DOS");
 load_win_att(ominx+1,ominy+1,omaxx-1,ominy+1,highatt);
 do{
  switch (ascii){
	case 13:{switch (yofs){
				case 0:{
				 convertmenu();
				 break;
				 };
				case 1:{
				 runmenu();
				 break;
				 };
				}; //switch yofs
				stop=1;
				break;
			  };
	}; //switch  ascii
 }while (stop ==0);
};

void conmain::convertmenu(){
char joe;
 load_win_att(ominx,ominy,omaxx,omaxy,8);
 make_win_border(12,8,43,11);
 load_win_att(12,8,43,11,boratt);
 load_win_att(13,9,42,10,winatt);
 load_string(13,9,"  Convert Recognition Files");
 load_string(15,10,"Convert Learning Files");
 load_win_att(13,9,42,9,highatt);
 cin >> joe;
 };

void conmain::runmenu(){
};


void main(){

conmain run1;
run1.mainmenu();
};
