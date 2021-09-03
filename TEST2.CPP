#include <c:\bread\graffx.h>
#include <iostream.h>

void main(){
 int curpage=1;
 char joe;
 mode_x();
 swap(2);
 for (int loop=2;loop<300;loop++){
     curpage=curpage^1;
  for (int loop2=1;loop2<200;loop2++){
	for (int loop3=1;loop3<320;loop3++){
	put_pix(loop3,loop2,(loop3%loop%16)+16,curpage);
	};
      };
     swap(curpage);
    };
/*  for(int loop4=0;loop4<16;loop4++){
    get_pal(loop4,pri[loop4]);
    };
 }; */
 cin >> joe;
 mode_3();
};