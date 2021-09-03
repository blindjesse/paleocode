#include <c:\bread\screen.h>
#include <c:\tc\include\graphics.h>
void main(){
 _setgraphmode(IBM8514HI);
 for (int x=0;x<1024;x++){
  for (int y=0;y<768;y++){
  _putpixel(x,y,x%y);
  };
 };
 get_scan(0,0);
};