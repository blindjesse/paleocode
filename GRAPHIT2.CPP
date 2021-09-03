#include <conio.h>
#include <iostream.h>
#include <c:\bread\graffx.h>

const axes_col=46;
const grap_col=12;
const num_points=5; // this is the number of points on each side of the y-axis

class graph{
 public:
  int x_stretch,y_stretch,*function;
  int x_origin,y_origin,axes_len,degree,ypoints[num_points*2];
  graph(int xor,int yor,int axlen);
  void get_function();
  void draw();
  void draw_axes();
 private:
  void fill_array();
  void draw_graph();
};

graph::graph(int xor,int yor,int axlen){
 x_origin=xor;
 y_origin=yor;
 axes_len=axlen;
 x_stretch=3;
 y_stretch=3;
 };

void graph::draw_axes(){
 int nbr1;
 for (nbr1=0;nbr1<axes_len;nbr1++){
  put_pix(x_origin-(axes_len/2)+nbr1,y_origin,axes_col,0);
  put_pix(x_origin,y_origin-(axes_len/2)+nbr1,axes_col,0);
  };
};

void graph::get_function(){
int nbr1;
clr_scr();
/*cout << "Enter the degree of the function: ";
cin >> degree;
cout << "Enter the numbers of the equation (see Jesse): ";
for (nbr1=0;nbr1<degree+1;nbr1++){
 function[nbr1]=getche();
 };*/
degree=2;
function = new int [degree];
function[0]=0;
function[1]=1;
function[2]=1;
};

void graph::draw(){
fill_array();
draw_graph();
};

void graph::fill_array(){
int nbr1,nbr2;
for (nbr1=-num_points;nbr1<num_points;nbr1++){
  ypoints[nbr1+num_points]=0;
  for (nbr2=1;nbr2<degree+1;nbr2++){
   ypoints[nbr1+num_points]=ypoints[nbr1+num_points]+(pow(nbr1,nbr2)*function[nbr2]);
  };
 };
 };

void graph::draw_graph(){
int nbr1;
for (nbr1=-num_points;nbr1<num_points;nbr1++){
 if ((ypoints[nbr1+num_points]<320)&&(ypoints[nbr1+num_points]>0)&&(ypoints[nbr1+num_points+1]<320)&&(ypoints[nbr1+num_points+1]>0))
 line(nbr1+x_origin,-ypoints[nbr1+num_points]+y_origin,nbr1+1+x_origin,-ypoints[nbr1+1+num_points]+y_origin,grap_col,0);
 };
};

void main(){
graph g1(320/2,200/2,200);
g1.get_function();
mode_x();
g1.draw_axes();
g1.draw();
get_scan(0,0);
};