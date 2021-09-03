#include <c:\bread\graphics.h>
#include <c:\bread\screen.h>
#include <string.h>
#include <iostream.h>
#include <math.h>
const grasscol=47,watercol=33,waterx1=80,waterx2=239;
int curpage;

void refresh(int screen);

class moving_obj{
public:
 int height,width,xrate,yrate,startx,starty;
 int *bitmap;
 void move(int x, int y, int scrnbr);
 void plot(int scrnbr);
private:
 void plot_row(int nbr,int scrnbr, int color);
 void plot_col(int nbr,int scrnbr, int color);
};

class target:public moving_obj{
public:
 int direction;
 target(int x1,int y1);
 void action();
 void destroy();
};

class target2:public moving_obj{
public:
 int direction;
 target2(int x1,int y1);
 void action();
 void destroy();
};

class airplane:public moving_obj{
public:
 airplane();
 void keyhandler();
 void destroy();
};

target target1(120,75);
target2 target2(120,90);

void refresh(int scrnbr){
 for (int nbr1=0;nbr1<200;nbr1++){
  for(int nbr2=0;nbr2<80;nbr2++){
  put_pix(nbr2,nbr1,grasscol,scrnbr);
  };
  for(nbr2=80;nbr2<240;nbr2++){
  put_pix(nbr2,nbr1,watercol,scrnbr);
  };
  for(nbr2=240;nbr2<320;nbr2++){
  put_pix(nbr2,nbr1,grasscol,scrnbr);
  };
 }; //nbr1
};

void moving_obj::move(int x, int y, int scrnbr){
if (x>0){
 for (int nbr1=startx;nbr1<=startx+x;nbr1++){
  plot_col(nbr1,scrnbr,watercol);
  };
 }else{if (x<0){
  for (int nbr2=startx;nbr2>=startx+x;nbr2--){
  plot_col(nbr2+width,scrnbr,watercol);
  };
       };
};
if (y>0){
 for (int nbr3=starty;nbr3<=starty+y;nbr3++){
  plot_row(nbr3,scrnbr,watercol);
  };
 }else{if (y<0){
   for (int nbr4=starty;nbr4>=starty+y;nbr4--){
    plot_row(nbr4+height,scrnbr,watercol);
   };
       };
};

startx+=x;
starty+=y;
plot(scrnbr);
};

void moving_obj::plot_row(int nbr,int scrnbr,int color){
 for (int nbr2=0;nbr2<width;nbr2++){
  put_pix(startx+nbr2,nbr,color,scrnbr);
  };
}

void moving_obj::plot_col(int nbr,int scrnbr,int color){
for (int nbr1=0;nbr1<height;nbr1++){
  put_pix(nbr,starty+nbr1,color,scrnbr);
  };
}

void moving_obj::plot(int scrnbr){
wait();
for (int nbr1=0;nbr1<height;nbr1++){
 for (int nbr2=0;nbr2<width;nbr2++){
  put_pix(startx+nbr2,starty+nbr1,bitmap[(nbr1*width)+nbr2],scrnbr);
  };
 };
};

airplane::airplane(){
height=11;
width=11;
startx=160;
starty=150;
int tempmap[] ={33,33,33,33,33, 0,33,33,33,33,33,
		33,33,33,33,33, 0,33,33,33,33,33,
		33,33,33,33, 0, 0, 0,33,33,33,33,
		33,33,33,33, 0, 0, 0,33,33,33,33,
		33,33,33, 0,80, 0,80, 0,33,33,33,
		33,33, 0, 0, 0, 0, 0, 0, 0,33,33,
		 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		33,33,33, 0, 0, 0, 0, 0,33,33,33,
		33,33,33,41,33,41,33,41,33,33,33,
		33,33,33,40,33,40,33,40,33,33,33};
bitmap = new int[height*width];
for (int nbr=0;nbr<(height*width);nbr++){
 bitmap[nbr]=tempmap[nbr];
 };
};


void airplane::keyhandler(){
 int atts,count1=0,count2=0,movement;
do{
 get_att_byte(atts);
 count1++;
 target1.action();
 target2.action();
  if (atts & 2){  //left shift
//	 if (count2 % 20==0){
	  move(-2,0,0);
	  target1.action();
	  target2.action();
//	  swap(curpage^1);
//	  curpage=curpage^1;
	  movement++;
//	  };
	 count2++;
	}else{
	if (atts & 1){  // right shift
//	 if (count2 % 20==0){
		move(2,0,0);
	  target1.action();
	  target2.action();
//		swap(curpage^1);
//		curpage=curpage^1;
		movement++;
//	  };
	 count2++;
	 }; //if atts
	}; //else
 }while (!(atts & 8));
};

target::target(int x1,int y1){
int lcv;
startx=x1;
starty=y1;
width=25;
height=5;
direction=1;
int tempmap[]={33,33,33,33,33,30,30,30,30,30,30,30,30,30,30,30,30,30,30,33,33,33,33,33,33,
	       33,33,33,33,30,30, 0,30, 0,30, 0,30, 0,30, 0,30, 0,30,30,30,33,33,33,33,33,
	       30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,
	       33,33,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,33,33,
	       33,33,33,33,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,33,33,33,33,33};
bitmap = new int[height*width];
for (lcv=0;lcv<(height*width);lcv++){
 bitmap[lcv]=tempmap[lcv];
 };
plot(0);
//plot(1);
};

void target::action(){
if (startx+width==waterx2){
  direction=-1;
  }else if(startx==waterx1){
   direction=1;
   }
 if (direction==1){
  move(1,0,0);
  }else if(direction==-1){
   move(-1,0,0);
   };
};

target2::target2(int x1,int y1){
int lcv;
startx=x1;
starty=y1;
width=20;
height=14;
direction=1;
int tempmap[]={33,33,33,33,33,14,33,14,33,33,33,33,33,33,33,33,33,33,33,33,
	       33,33,33,33,33,14,33,14,33,33,33,33,33,33,33,33,33,33,33,33,
	       33,33,33,33,33,14,33,14,14,33,33,33,33,33,33,33,33,33,33,33,
	       33,33,33,33,33,14,33,14,14,33,33,33,33,33,33,33,33,33,33,33,
	       33,33,33,33,33,14,33,14,14,14,33,33,33,33,33,33,33,33,33,33,
	       33,33,33,33,33,14,33,14,14,14,14,33,33,33,33,33,33,33,33,33,
	       33,33,33,33,33,14,33,14,14,14,14,33,33,33,33,33,33,33,33,33,
	       33,33,33,33,33,14,33,14,14,14,14,14,33,33,33,33,33,33,33,33,
	       33,33,33,33,33,14,33,14,14,14,14,14,14,33,33,33,33,33,33,33,
	       33,33,33,33,33,14,14,14,14,14,14,14,14,14,33,33,33,33,33,33,
	       33,33,33,33,33,14,33,14,33,33,33,33,33,33,33,33,33,33,33,33,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	       33, 0, 0, 0,30, 0,30, 0,30, 0,30, 0,30, 0,30, 0,30, 0, 0,33,
	       33,33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,33,33};
bitmap = new int[height*width];
for (lcv=0;lcv<(height*width);lcv++){
 bitmap[lcv]=tempmap[lcv];
 };
plot(0);
plot(1);
};


void target2::action(){
if (startx+width==waterx2){
  direction=-1;
  }else if(startx==waterx1){
   direction=1;
   }
 if (direction==1){
  move(1,0,0);
  }else if(direction==-1){
   move(-1,0,0);
   };
};

void start_plane(){
 airplane hero1;
 hero1.plot(0);
 hero1.plot(1);
 hero1.keyhandler();
};

void main(){
 char joe;
 mode_13();
// swap(2);
 refresh(0);
// refresh(1);
 target1.plot(0);
// target1.plot(1);
// swap(0);
 curpage=0;
 start_plane();
};