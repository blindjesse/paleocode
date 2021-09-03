#include <c:\bread\graphics.h>
#include <iostream.h>

void main(){
 int pall[256][3];
 int temp[3];
 int R,G,B;
 char joe;
 mode_13();
// for (int loop1=100;loop1<=200;loop1++){
  wait();

// };
// delay(500);
  load_pal(pall);
  wait();
 for (int loop4=0;loop4<256;loop4++){
  set_pal(loop4,0,0,0);
 };
  for (int loop2=1;loop2<200;loop2++){
	for (int loop3=1;loop3<320;loop3++){
	put_pix(loop3,loop2,(loop3+50) * (loop2+50) %(loop3+loop2)%50,0);
	//put_pix(loop3,loop2,50);
	};
  };
  for (int loop7=0;loop7<64;loop7++){
	wait();
	delay(40);
  for (int loop8=0;loop8<256;loop8++){
	outport(0x3c7,loop8);
	temp[0]=inport(0x3c9);
	temp[1]=inport(0x3c9);
	temp[2]=inport(0x3c9);
  //	get_pal(loop8,temp[0],temp[1],temp[2]);
	if (temp[0]<pall[loop8][0]){
	 temp[0]++;
	 };
	if (temp[1]<pall[loop8][1]){
	 temp[1]++;
	 };
	if (temp[2]<pall[loop8][2]){
	 temp[2]++;
	 };
	set_pal(loop8,temp[0],temp[1],temp[2]);
  };
 };
 cin >> joe;
 mode_3();
};