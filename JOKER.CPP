#include <iostream.h>
#include <c:\bread\graffx.h>
void main(){
 char joe;
 swap(2);
 mode_x();
 load_tables();
 for (int nbr=1;nbr<90;nbr++){
 circle(160,100,nbr,nbr+40,0);
 circle(160,100,nbr+2,nbr+40,1);
 circle(160,100,nbr+4,nbr+40,2);
 circle(160,100,nbr+6,nbr+40,3);
 };
 int nbr2=1;
 do{
  swap(1);
  delay(100);
  swap(2);
  delay(100);
  swap(3);
  delay(100);
  swap(2);
  delay(100);
  swap(1);
  delay(100);
  swap(0);
  delay(100);
  }while(nbr2!=0);
 cin >> joe;
};