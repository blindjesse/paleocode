#include<math.h>
#include <iostream.h>
#include <conio.h>
#include <string.h>
#include<c:\bread\graffx.h>
class ttt{
public:
 void place_x();
 void place_o();
 void draw_board();
 void move();
 void run();
 int winner();
 font font1;
 int turn;
 char board[3][3];
 char names[2][20];
 char mv[3];
 };

void ttt::place_x(){
 for (int nbr1=0;nbr1<20;nbr1++){
  for (int nbr2=0;nbr2<20;nbr2++){
   if (((nbr1)==(nbr2))||(20-(nbr1))==((nbr2))){
   put_pix(nbr1+125+((int(mv[0])-48-1)*30),nbr2+75+(((int)mv[2]-48-1)*30),38,0);
   };
  };
 };
};

void ttt::place_o(){
 float deg=0;
 int cx,cy;
do{
 cx=(int)(10*cos(deg));
 cy=(int)(10*sin(deg));
 put_pix(cx+135+((int(mv[0])-48-1)*30),cy+85+((int(mv[2])-48-1)*30),42,0);
 deg+=0.005;
 }while(deg<=6.28);
};

void ttt::draw_board(){
 turn=0;
 for(int nbr1=0;nbr1<4;nbr1++){
  for(int nbr2=0;nbr2<90;nbr2++){
   put_pix(nbr1*30+120,nbr2+70,35,0);
   put_pix(nbr2+120,nbr1*30+70,35,0);
  };
 };

font1.write_string("Hello Tic-Tac-Toe Buffs!\n",35);
delay(1000);
font1.write_string("Player one, enter your name: ",34,0);
font1.get_stringln(names[0],33,9);
font1.write_string("Player two, enter your name: ",32,0);
font1.get_stringln(names[1],40,9);
};

void ttt::move(){
font1.goxy(1,1);
font1.clear_string(160);
font1.goxy(1,1);
font1.write_string(names[turn],41,0);
font1.write_string(", enter a move in the format row,column: ",42,0);
font1.get_stringln(mv,43,3);
while ((mv[0]<'1')||(mv[0]>'3')||(mv[2]<'1')||(mv[2]>'3')||(board[(int)mv[0]-49][(int)mv[2]-49]=='x')||(board[(int)mv[0]-49][(int)mv[2]-49]=='o')){
font1.goxy(1,1);
font1.clear_string(160);
font1.goxy(1,1);
font1.write_string(names[turn],43,0);
font1.write_string("! Bad move! Enter a move in the format\n row,column: ",44,0);
font1.get_stringln(mv,43,3);
 };
if (turn==0){
 place_x();
 board[(int)mv[0]-49][(int)mv[2]-49]='x';
 }
 else{
  place_o();
  board[(int)mv[0]-49][(int)mv[2]-49]='o';
  };

turn^=1;
};

int ttt::winner(){
//board[3][3]
int xo=0,xx=0,xy=0,xd1=0,od1=0,ox=0,oy=0,od2=0,xd2=0,ret=0;
for (int nbr1=0;nbr1<3;nbr1++){
 for (int nbr2=0;nbr2<3;nbr2++){
  if ((board[nbr1][nbr2]=='x')||(board[nbr1][nbr2]=='o'))
    xo++;
  if(board[nbr1][nbr2]=='x')
   xx++;
  if (board[nbr1][nbr2]=='o')
    xy++;
  if(board[nbr2][nbr1]=='x')
   ox++;
   if (board[nbr2][nbr1]=='o')
    oy++;
  if (board[nbr2][nbr2]=='x')
   xd1++;
  if (board[nbr2][nbr2]=='o')
   od1++;
  if (board[nbr2][2-nbr2]=='x')
   xd2++;
  if (board[nbr2][2-nbr2]=='o')
   od2++;
  }
  if ((xx==3)||(xy==3)||(xd1==3)||(xd2==3))
   ret=1; else
   if ((ox==3)||(oy==3)||(od1==3)||(xd2==3))
    ret=2; else
   if (xo==9)
    ret=3;
  xx=0;
  xy=0;
  xd1=0;
  xd2=0;
  ox=0;
  oy=0;
  od1=0;
  od2=0;
 };
  return ret;
};

void ttt::run(){
 int turn=0;
 int win=0;
 mode_x();
 draw_board();
 do{
  move();
  win=winner();
   }while ((win!=1)&&(win!=2)&&(win!=3));
 if (win!=3){
 font1.write_string(names[win-1],57,0);
 font1.write_string(" WON THE GAME!!!!\n",58,0);}
 else{
  font1.write_string("Nobody won this game, Birdo",59,0);
  };
};

void main(){
 ttt tic1;
 tic1.run();
 getch();
};