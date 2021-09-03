// This is the randomrun part of the conshell
#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>
#include <time.h>

class random_learning{
// holds the class that controls the multiple runs of confor
  public:
	 random_learning();
	 ~random_learning();
	 void first_run(int num_runs,char *recout, char *learnout);
	 void run_tests();
	 void test();
	 void scramble_learning();
  private:
	 char *none;
	 char *tempstorename;
	 char *learning_filename;
	 ifstream temp_learning_file;
	 char *temp_learning_filename;
	 ifstream learning_file;
	 char current_learning_filename[15];
	 ofstream current_learning_file;
	 char current_recognition_filename[15];
	 ofstream current_recognition_file;
	 char *temp_recognition_filea_name;
	 char *temp_recognition_fileb_name;
	 char *results_filename;
	 ifstream results_file;
	 int num_compounds;
	 int current_run;
	 int runs_to_do;
	 void loadbuf(char toload[127]);
	 void change_current_run(char nbr[3], int &numchar);
	 void change_current_learning_filename();
	 void load_compound_names();
	 void extract_learning();
	 void extract_recognition_data();
	 void run_test();
  }; //random_learning


//************************************************************************
random_learning::random_learning(){
 randomize;
 none="none";
 results_filename="recogn.a";
 tempstorename="data\\condos.tmp";
 temp_recognition_filea_name="data\\contemp.a";
 temp_recognition_fileb_name="data\\contemp.b";
 learning_filename="btxt.na";
 temp_learning_filename="btxt.tmp";
}; //constructor for random_learning

//************************************************************************
random_learning::~random_learning(){
}; //destructor for random learning

//************************************************************************
void random_learning::loadbuf(char toload[127]){
// puts characters into the character buffer
int nbr=0;
unsigned char ascnum;
if (toload[nbr]=='\n'){
 ascnum=13;
 }else ascnum=toload[nbr];
while (ascnum!='\0'){
  asm{
	mov ah,05h
	mov ch,0
	mov cl,ascnum
	int 16h
	};
  nbr++;
  ascnum=toload[nbr];
  };
};

//************************************************************************
void random_learning::change_current_run(char nbr[3], int &numchar){
 if (current_run/10 != 0){
  nbr[0]=char (48 + current_run/10);
  nbr[1]=char (48 + current_run%10);
  nbr[2]='\0';
  numchar=2;
  }else{
		 nbr[0] = (48 + current_run%10);
		 nbr[1] = '\0';
		 numchar = 1;
		 };
};
//************************************************************************
void random_learning::change_current_learning_filename(){
//room must be left in the inputstring for the count!!
// the second file must have an extension!! why?
ifstream tempstorein;
ofstream tempstoreout;
int dotpos=0;
int nbr=-1;
char todo[3];
int todonumchar;
int error=1;
tempstorein.open(tempstorename);
tempstorein >> current_run >> runs_to_do >> current_learning_filename >> current_recognition_filename;
tempstorein.close();
current_run ++;
tempstoreout.open(tempstorename);
tempstoreout << current_run <<" " << runs_to_do<<" " << current_learning_filename <<" "<< current_recognition_filename;
tempstoreout.close();
change_current_run(todo,todonumchar);
do{nbr++;
	switch (current_learning_filename[nbr]){
	  case '\0':{error=-1;
					 break;
					};
	  case '.':{dotpos=nbr;
					break;};
	  };
  }while (error == 1 );

if (dotpos == 0){
	 current_learning_filename[nbr]='.';
	 current_learning_filename[nbr+1]='\0';
	 dotpos=nbr;
  };

for (int loop=1;loop<=todonumchar;loop++){
 for (int lcv=nbr;lcv>=dotpos;lcv--){
  current_learning_filename[lcv+loop]=current_learning_filename[lcv+loop-1];
  };
  nbr++;
  dotpos++;
 };
for (int loop2=todonumchar;loop2>=1;loop2--){
 current_learning_filename[dotpos-loop2]=todo[todonumchar-loop2];
 };
current_learning_filename[dotpos]='.';
 };
 //************************************************************************
void random_learning::extract_learning(){
 char ch;
 char line[60];
num_compounds=0;
learning_file.open(learning_filename);
current_learning_file.open(current_learning_filename);

do{
 ch = learning_file.get();
 }while((ch == ' ') || (ch == '\n'));
 learning_file.putback(ch);

learning_file.getline(line,60);
while (line[0]!='\0'){
 current_learning_file << line << '\n';
 learning_file.getline(line,60);
 num_compounds++;
 };
current_learning_file.close();
};
//************************************************************************
void random_learning::load_compound_names(){
int temp_num_compounds=0;
		char compname[15];
ofstream temp_recognition_file;
results_file.open(results_filename);
temp_recognition_file.open(temp_recognition_filea_name);

  results_file.ignore(100,'t');
  results_file >> compname;
  results_file.ignore(70,'\n');
 do{
  temp_recognition_file << compname << "\n";
  temp_num_compounds++;
  results_file.ignore(100,'t');
  results_file >> compname;
  results_file.ignore(70,'\n');
	 }while (temp_num_compounds < num_compounds);
temp_recognition_file.close();
results_file.close();
};
//************************************************************************
void random_learning::extract_recognition_data(){
 char *bin;
 char ch;
 char compoundname[15];
 char dump[60];
 ifstream input_temp_file;
 ofstream output_temp_file;
 int lcv,num_of_rows=0;
 if (current_run % 2 ==1) {
  input_temp_file.open(temp_recognition_filea_name);
  output_temp_file.open(temp_recognition_fileb_name);
  }else{
	 input_temp_file.open(temp_recognition_fileb_name);
	 output_temp_file.open(temp_recognition_filea_name);
	};
 if (current_run == runs_to_do){
  output_temp_file.close();
  output_temp_file.open(current_recognition_filename);
  };
 results_file.open(results_filename);

 input_temp_file >> compoundname;
while (compoundname[0]!='\0'){
 output_temp_file << compoundname << ' ';

	for (int nbr=1; nbr < current_run; nbr++){
	  input_temp_file >> bin;
	  output_temp_file << bin << ' ';
	  };
	input_temp_file.ignore (60,'\n');

	do{
	  ch = results_file.get();
	  }while((ch == ' ') || (ch == '\n'));
	results_file.putback(ch);
	results_file.get(dump,60,'\n');
	for (int loop=0;dump[loop]!='\0';loop++){};
	if (dump[loop-1]!='s'){
	output_temp_file <<dump[loop-1];
	}else {output_temp_file << "none ";
		  };
  output_temp_file << '\n';
 input_temp_file >> compoundname;
 };
 input_temp_file.close();
 output_temp_file.close();
 results_file.close();
};

//************************************************************************
void random_learning::scramble_learning(){
// I realize this could easily become part of extract_learning, but I feel
// the size saved in the learnrows variable is more important that the
// little time saved doing it all at once.
char learnrows[60][500];
int ch,count=-1;
char line[70];
ofstream learning_file;
int number;
int num_strings=num_compounds;
int array_pos;
int nbr,loop;
//learnrows = new char*[num_compounds];
 learning_file.open(learning_filename);
 temp_learning_file.open(temp_learning_filename);
do{
 ch = temp_learning_file.get();
 }while((ch == ' ') || (ch == '\n'));
 temp_learning_file.putback(ch);

for (nbr=0;nbr<num_compounds;nbr++){
 temp_learning_file.getline(learnrows[nbr],60,'\n');
 };
for (loop=0;loop<num_compounds;loop++){
 number=0;
 array_pos=(random(6000) % num_strings);
 learning_file  << learnrows[array_pos]<< '\n';
 do{
  learnrows[array_pos][number]=learnrows[num_strings-1][number];
  number++;
 }while (learnrows[num_strings-1][number-1]!='\0');
 num_strings--;
 };
do{
 temp_learning_file.getline(line,60,'\n');
 learning_file << line << '\n';
 } while (!temp_learning_file.eof());
learning_file.close();
temp_learning_file.close();
};
//************************************************************************
void random_learning::run_test(){
 char stuffer[]={'z','a','p','.','b','a','t',13};
 loadbuf(stuffer);
 exit(0);
};
//************************************************************************
void random_learning::first_run(int num_runs,char *recout, char *learnout){
ofstream tempstore;
tempstore.open(tempstorename);
tempstore << 0 << " " << num_runs << " " << learnout <<" " << recout << " ";
tempstore.close();
runs_to_do = num_runs;
run_test();
};
//************************************************************************
void random_learning::run_tests(){
change_current_learning_filename();
	extract_learning();
	if (current_run==1){
	 load_compound_names();
	  };
	extract_recognition_data();
  scramble_learning();
	if (current_run < runs_to_do){
	 run_test();
	 };
};
//************************************************************************

