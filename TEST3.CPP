#include <c:\bread\graphics.h>
#include <iostream.h>
#include <stdlib.h>
void main(){
 int pri[16][3];
 int temp[3];
 int key;
 char joe;
 randomize();
 mode_13();
  wait();
/*  for(int loop10=0;loop10<16;loop10++){
   set_pal(loop10,0,0,50);
  }; */
  key=random(4);
  if (key==3){
   key=-1;
   }else{key=1;};
  for (int loop=100;loop<400;loop+=key){
  key=random(2);
  if (key==0){
   key=-1;
   }else{key=1;};
  wait();
  for (int loop2=1;loop2<200;loop2++){
	for (int loop3=1;loop3<320;loop3++){
	put_pix(loop3,loop2,(loop3*loop2)%loop);
	};
      };
 };
 cin >> joe;
 mode_3();
};