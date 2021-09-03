// Jesse Anderson
// April 10, 1997

class font{
 public:
  int rows[5][32];
  // stores the binary representations (in integers) the numbers 0-31
  font();
  // initialiser for the font class
  void write_letter(int ascii,int color,int backc);
  // writes a single letter to the screen, given the ascii code, x and y
  // coordinates, and the color (0-256)
  void write_string(char string[],int color,int backc);
  // writes a string of letters to the screen, stored in a char string, at
  // coordinates x and y, and color color
  void clear_string(int numchars,int color);
  void get_string(char string[40],int color,int len,int backc);
  void get_stringln(char string[40],int color,int len,int backc);
  void goxy(int x, int y);
  int curx,cury;
 };

font::font(){
int row,col;
curx=1;
cury=1;
// puts the computer in graphics mode
//mode_x();

/* load the rows variable with the binary digits of the
  numbers 0 to 31 */
for (row=0;row<32;row++)
 for (col=0;col<5;col++)
   if (row&Raise(2,col))
   rows[4-col][row]=1;
   else
     rows[4-col][row]=0;

};

void font::goxy(int x, int y){
curx=x;
cury=y;
};

void font::write_letter(int ascii,int color,int backc=-1){
/* this constant stores the row values for each letter.  this is the essence
   the font unit.  rather than storing each 8*5 bitmap for each letter pixel
   by pixel, this stores it in 8 rows, each row having 5 pixels.  the pixels
   which are on are those which are 1s in the binary representation of the
   row numbers.
   for instance:  the number 1 is 00001 in 5 digit binary.
   for a straight bar down the right side of the 8*5 space, the corresponding
   pixmap would be:
   00001
   00001
   00001
   00001
   00001
   00001
   00001
   00001
   or, stored in rows : 1,1,1,1,1,1,1,1
  the array starts at space (32 in ascii) and goes on for 96 characters)
  */
int letterow[96][8]=  {0,0,0,0,0,0,0,0,
   4,4,4,4,0,4,0,0,
   10,10,10,0,0,0,0,0,
   10,10,31,10,31,10,10,0,
   4,15,20,14,5,30,4,0,
   24,25,2,4,8,19,3,0,
   8,20,20,8,21,18,13,0,
   4,4,0,0,0,0,0,0,
   2,4,8,8,8,4,2,0,
   8,4,2,2,2,4,8,0,
   0,10,4,31,4,10,0,0,
   0,4,4,31,4,4,0,0,
   0,0,0,0,12,12,4,8,
   0,0,0,31,0,0,0,0,
   0,0,0,0,0,24,24,0,
   0,1,2,4,8,16,0,0,
   14,17,17,21,17,17,14,0,
   4,12,4,4,4,4,14,0,
   14,17,1,6,8,16,31,0,
   14,17,1,14,1,17,14,0,
   2,6,10,18,31,2,2,0,
   31,16,30,1,1,17,14,0,
   6,8,16,30,17,17,14,0,
   31,1,2,4,8,8,8,0,
   14,17,17,14,17,17,14,0,
   14,17,17,15,1,2,12,0,
   0,12,12,0,12,12,0,0,
   0,12,12,0,12,12,4,8,
   2,4,8,16,8,4,2,0,
   0,0,31,0,31,0,0,0,
   16,8,4,2,4,8,16,0,
   14,17,1,2,4,0,4,0,
   14,17,21,23,23,20,16,15,
   14,17,17,31,17,17,17,0,
   30,17,17,30,17,17,30,0,
   14,17,16,16,16,17,14,0,
   28,18,17,17,17,18,28,0,
   31,16,16,30,16,16,31,0,
   31,16,16,30,16,16,16,0,
   14,17,16,16,19,17,15,0,
   17,17,17,31,17,17,17,0,
   14,4,4,4,4,4,14,0,
   1,1,1,1,17,17,14,0,
   17,18,20,24,20,18,17,0,
   16,16,16,16,16,16,31,0,
   17,27,21,21,17,17,17,0,
   17,17,25,21,19,17,17,0,
   14,17,17,17,17,17,14,0,
   30,17,17,30,16,16,16,0,
   14,17,17,17,21,18,13,0,
   30,17,17,30,20,18,17,0,
   14,17,16,14,1,17,14,0,
   31,4,4,4,4,4,4,0,
   17,17,17,17,17,17,14,0,
   17,17,17,10,10,4,4,0,
   17,17,17,21,21,27,17,0,
   17,17,10,4,10,17,17,0,
   17,17,10,4,4,4,4,0,
   31,1,2,4,8,16,31,0,
   14,8,8,8,8,8,14,0,
   0,16,8,4,2,1,0,0,
   14,2,2,2,2,2,14,0,
   4,10,17,0,0,0,0,0,
   0,0,0,0,0,0,0,31,
   8,8,4,0,0,0,0,0,
   0,0,14,1,15,17,15,0,
   16,16,30,17,17,17,30,0,
   0,0,15,16,16,16,15,0,
   1,1,15,17,17,17,15,0,
   0,0,14,17,31,16,14,0,
   4,10,8,28,8,8,8,0,
   0,0,14,17,17,15,1,14,
   16,16,30,17,17,17,17,0,
   4,0,12,4,4,4,14,0,
   4,0,12,4,4,4,20,12,
   16,16,18,20,24,20,18,0,
   12,4,4,4,4,4,14,0,
   0,0,26,21,21,21,17,0,
   0,0,30,17,17,17,17,0,
   0,0,14,17,17,17,14,0,
   0,0,30,17,17,30,16,16,
   0,0,15,17,17,15,1,1,
   0,0,23,24,16,16,16,0,
   0,0,15,16,14,1,30,0,
   8,8,28,8,8,10,4,0,
   0,0,17,17,17,17,15,0,
   0,0,17,17,17,10,4,0,
   0,0,17,17,21,21,10,0,
   0,0,17,14,4,14,17,0,
   0,0,17,17,17,15,1,14,
   0,0,31,2,4,8,31,0,
   6,8,8,16,8,8,6,0,
   4,4,4,4,4,4,4,0,
   12,2,2,1,2,2,12,0,
   1,14,16,0,0,0,0,0,
   31,31,31,31,31,31,31,31};

/* these lines load a letter into video memory (using put_pix) by susbstituting
  the color for every 1 in the array and writing to the screen */
if (char(ascii)=='\n'){
 cury+=10;
 curx=1;
 }else{
   if (color==257){
    color = random(256);
    };
for (int nbr1=0;nbr1<5;nbr1++)
 for (int nbr2=0;nbr2<8;nbr2++)
  if (rows[nbr1][letterow[ascii-32][nbr2]]!=0){
   put_pix(curx+nbr1,cury+nbr2,color,0);
   }else{
   if (backc!=-1){
    put_pix(curx+nbr1,cury+nbr2,backc,0);
    };
   };
curx+=6;
if (curx>=314){
 curx=1;
 if (cury<=190){
 cury+=10l;
  };
 };
};
};


void font::write_string(char string[],int color,int backc=-1){
int nbr1=0;
/* a simple procedure to write a letter, move six pixels to the right, and
  write another, until the end of the string */
do{
 write_letter((int)string[nbr1],color,backc);
 nbr1++;
 }while(string[nbr1]!='\0');
};

void font::clear_string(int numchars,int backc=0){
 for (int nbr1=0;nbr1<numchars;nbr1++)
 write_letter(32,0,backc);
 };

void font::get_string(char string[40],int color,int len,int backc=-1){
char ch;
int nbr1=0;
ch=getch();
while ((ch!=(char)13)&&(nbr1<len)){
 if ((ch==8)&&(nbr1>=1)){
 goxy(curx-6,cury);
 write_letter(32,color,0);
 goxy(curx-6,cury);
 nbr1-=1;
 }else{
 if ((ch>=32)&&(ch<126)){
 string[nbr1]=ch;
 write_letter((int)ch,color,backc);
 nbr1++;
  };
  };
 ch=getch();
 };
string[nbr1+1]='\0';
};

void font::get_stringln(char string[40],int color,int len,int backc=-1){
char ch;
int nbr1=0;
ch=getch();
while ((ch!=(char)13)&&(nbr1<len)){
 if ((ch==8)&&(nbr1>=1)){
 goxy(curx-6,cury);
 write_letter(32,color,0);
 goxy(curx-6,cury);
 nbr1-=1;
 }else{
 if ((ch>=32)&&(ch<126)){
 string[nbr1]=ch;
 write_letter((int)ch,color,backc);
 nbr1++;
  }
 };
 ch=getch();
 };
write_letter('\n',color,backc);
string[nbr1]='\0';
};