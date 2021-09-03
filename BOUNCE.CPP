#include <c:\bread\graffx.h>
#include <dos.h>
void plot_ball(int xo,int yo,int x=0){
font font1;
char bitmap[]={0,0,0,0,0,x,0,0,0,0,0,
	       0,0,0,0,x,x,x,0,0,0,0,
	       0,0,0,x,x,x,x,x,0,0,0,
	       0,0,x,x,x,x,x,x,x,0,0,
	       0,x,x,x,x,x,x,x,x,x,0,
	       x,x,x,x,x,x,x,x,x,x,x,
	       0,x,x,x,x,x,x,x,x,x,0,
	       0,0,x,x,x,x,x,x,x,0,0,
	       0,0,0,x,x,x,x,x,0,0,0,
	       0,0,0,0,x,x,x,0,0,0,0,
	       0,0,0,0,0,x,0,0,0,0,0,
	       };

font1.goxy(xo,yo);
font1.write_letter(67,x);
};
void main(){
mode_x();
get_scan(0,0);
for (int nbr1=30;nbr1<10000;nbr1++){
 plot_ball(60+50*sin(nbr1),60+50*cos(nbr1),nbr1%16+32);
// plot_ball(30+10*sin(nbr1),30+10*cos(nbr1),0);
 };
get_scan(0,0);
};
