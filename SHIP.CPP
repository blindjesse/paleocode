#include <conio.h>
#include <c:\bread\screen.h>
#include <iostream.h>
#include <string.h>
#define xrows 10
#define yrows 10

const char* toplace="ABBCCD";

class battle{
public:
 battle();
 int xoff,yoff,woff;
 char one[xrows][yrows];
 char two[xrows][yrows];
 char coords[3];
 char direct;
 void player_move();
 void computer_move();
 void run();
 void setup_ships();
 void place_boat(int type);
 void place_computers();
 int check_place(int length);
 void redraw_board();
};

battle::battle(){
int temp=0;
xoff=5;
yoff=5;
woff=30;
blow_cursor();
load_win_att(xoff-1,yoff-1,xoff+xrows*2,yoff+yrows-1,28);
load_win_att(xoff+xrows*2+woff-1,yoff-1,xoff+xrows*4+woff,yoff+yrows-1,28);
load_win_att(xoff,yoff,xoff+xrows*2,yoff+yrows-1,26);
load_win_att(xoff+xrows*2+woff,yoff,xoff+xrows*4+woff,yoff+yrows-1,26);
gotoxy(xoff,yoff-1);
for (int nbr2=0;nbr2<xrows;nbr2++)
 cout<<' ' <<  nbr2;
for (nbr2=0;nbr2<xrows;nbr2++){
 gotoxy(xoff-1,yoff+nbr2);
 cout << char(65+nbr2) ;
 };
gotoxy(xoff+xrows*2+woff,yoff-1);
for (nbr2=0;nbr2<xrows;nbr2++)
 cout<< " " << nbr2 ;
for (nbr2=0;nbr2<xrows;nbr2++){
 gotoxy(xoff+xrows*2+woff-1,yoff+nbr2);
 cout << char(65+nbr2) ;

load_win_att(xoff+5+xrows*2,yoff+1,xoff+xrows*2+24,yoff+7,26);
load_win_att(xoff+5+xrows*2+1,yoff+2,xoff+xrows*2+23,yoff+6,12);
temp=xoff+5+xrows*2+1;
gotoxy(xoff+5+xrows*2+5,yoff+1);
cout << "-> KEY <-";
gotoxy(xoff+5+xrows*2+1,yoff+2);
cout << "  Å = Uncharted";
load_att(temp+2,yoff+2,10);
gotoxy(xoff+5+xrows*2+1,yoff+3);
cout << "     ± = Miss";
load_att(temp+5,yoff+3,10);
gotoxy(xoff+5+xrows*2+1,yoff+4);
cout << "     Î = Hit   ";
load_att(temp+5,yoff+4,10);
gotoxy(xoff+5+xrows*2+1,yoff+5);
cout << "   = Your Boat";
load_att(temp+2,yoff+5,10);
gotoxy(xoff+5+xrows*2+1,yoff+6);
cout << "   = Sunk Ship";
load_att(temp+2,yoff+6,10);

 };

for (int nbr=0;nbr<xrows;nbr++){
 for (int nbr1=0;nbr1<yrows;nbr1++){
  one[nbr][nbr1]='Å';
  two[nbr][nbr1]='Å ';
  gotoxy(xoff+nbr*2,yoff+nbr1);
  cout << char(196) << char(197);
  gotoxy(xoff+nbr*2+2*xrows+woff,yoff+nbr1);
  cout << char(196) << char(197);
  };
 gotoxy(xoff+xrows*2,yoff+nbr);
 cout << 'Ä';
 gotoxy(xoff+xrows*2+2*xrows+woff,yoff+nbr);
 cout << 'Ä';
 };
load_win_att(1,16,79,25,31);
gotoxy(34,16);
cout << "Control Panel";
};

void battle::setup_ships(){
char* ships= "This ship is ";
char joe[2];
//window(2,24,78,24);
load_win_att(2,17,78,24,15);
dload_string(2,17,"You will now set up your ships. ",30);
delay(100);
dload_string(2,18,"You have the following: ",30);
load_win_att(4,19,60,19,9);
delay(100);
dload_string(4,19,"1 Aircraft Carrier (5 units in length)",30);
load_win_att(4,20,60,20,10);
delay(100);
dload_string(4,20,"2 Battleships (4 units in length)",30);
load_win_att(4,21,60,21,11);
delay(100);
dload_string(4,21,"2 Cargo ships (3 units in length)",30);
load_win_att(4,22,60,22,12);
delay(100);
dload_string(4,22,"1 Destroyer (2 units in length)",40);
delay(100);
dload_string(2,23,"For each ship you will enter the coordinates of an end by giving a",40);
delay(100);
dload_string(2,24,"letter, number pair.",40);
delay(100);
scroll_win(1,16,77,23,1,15);
dload_string(2,24,"Then you will enter either a 'D' or a 'R' to indicate whether the ",40);
scroll_win(1,16,77,23,1,15);
dload_string(2,24,"ship goes down or right from that point.",40);
scroll_win(1,16,77,23,1,15);

for (int lcv=0;lcv<6;lcv++){
joe[0]=(char)(53+(int(toplace[lcv])-65)*2);
joe[1]='\0';
strcat(ships,joe);
strcat(ships," units in length. Enter the starting letter,number pair: " );
dload_string(2,24,ships,40);
scroll_win(1,16,77,23,1,15);
gotoxy(2,24);
get_string(coords,3);
//cin >> *coords;
scroll_win(1,16,77,23,1,15);
dload_string(2,24,"Enter the direction (D for down or R for right): ",40);
scroll_win(1,16,77,23,1,15);
cin >> direct;
if (check_place(5)==1)
 place_boat(5);
 else{
 //  no good, reload the boat
  };
redraw_board();
scroll_win(1,16,77,23,1,15);
 };
place_computers();
};

int battle::check_place(int length){
 int ret = 1;
 int nbr;
if ((direct=='R')||(direct=='r')){
 if ((((int)coords[2]+length-48)>xrows)||((int)coords[2]-length-48)<0)
  ret =0;else{
 for (nbr=0;nbr<length;nbr++)
  if (one[(int)coords[2]+nbr-48][(int)coords[0]-65]!='Å')
   ret = 0;
   };
  }else{
  if ((direct=='D')||(direct=='d'))
   if ((((int)coords[0]+length-65)>yrows)||((int)coords[0]-length-65)<0)
    ret =0;else{
    for (nbr=0;nbr<length;nbr++){
     if (one[(int)coords[2]-48][(int)coords[0]-65+nbr]!='Å')
       ret=0;
    };
  };
 };
return ret;
};

void battle::place_computers(){
};

void battle::place_boat(int type){
int nbr;
if ((direct=='R')||(direct=='r')){
 for (nbr=0;nbr<type;nbr++)
  one[(int)coords[2]+nbr-48][(int)coords[0]-65]=char(5-type+65);
  }else{
  if ((direct=='D')||(direct=='d'))
   for (nbr=0;nbr<type;nbr++){
    one[(int)coords[2]-48][(int)coords[0]-65+nbr]=char(5-type+65);
   };
  };
};

void battle::redraw_board(){
for (int nbr=0;nbr<xrows;nbr++){
 for (int nbr1=0;nbr1<yrows;nbr1++){
  load_char(5+nbr*2+1,5+nbr1,one[nbr][nbr1]);
  load_char(5+nbr*2+2*xrows+30+1,5+nbr1,two[nbr][nbr1]);
  };
 };
};

void battle::player_move(){
};

void battle::run(){
setup_ships();
};

void main(){
clrscr();
clr_att();
battle battle1;
battle1.run();
getch();
};