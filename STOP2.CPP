unsigned char nbr,lcv;
int loop1;

void scanloader(unsigned char code){
  asm{
	mov ah,05h
	mov ch,code
	mov cl,0
	int 16h
	};
};

void ascloader(char code){
  asm{
	mov ah,05h
	mov cl,code
	mov ch,0
	int 16h
	};
};
void loadbuf(char *toload){
int nbr=0;
while (toload[nbr]!='\0'){
  ascloader(toload[nbr]);
  nbr++;
  };
};

void main(){
 char stuff1[]={'c','o','n','f','o','r',13,13,13,13};
 loadbuf(stuff1);
 scanloader(80);
 ascloader(13);
 };


