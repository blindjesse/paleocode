// This is the randomrun part of the conshell
#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>


class random_learning{
  public:
	 random_learning();
	 ~random_learning();
	 void first_run(int num_runs,char *recout, char *learnout);
	 void run_tests();
	 void test();
  private:
	 char *tempstorename;
	 char *learning_filename;
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
	 void change_num_runs(char nbr[2], int &numchar);
	 void save_tables();
	 void change_current_learning_filename();
	 void load_compound_names();
	 void extract_learning();
	 void extract_recognition_data();
	 void run_test();
  }; //random_learning


//************************************************************************
random_learning::random_learning(){
 results_filename="recogn.a";
 tempstorename="condos.tmp";
 temp_recognition_filea_name="contemp.a";
 temp_recognition_fileb_name="contemp.b";
}; //constructor for random_learning

//************************************************************************
random_learning::~random_learning(){
}; //destructor for random learning

//************************************************************************
void random_learning::loadbuf(char toload[127]){
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
void random_learning::change_num_runs(char nbr[2], int &numchar){
 if (runs_to_do/10 != 0){
  nbr[0]=char (48 + runs_to_do/10);
  nbr[1]=char (48 + runs_to_do%10);
  numchar=2;
  }else{
		 nbr[0] = (48 + runs_to_do%10);
		 numchar = 1;
		 };
};
//************************************************************************
void random_learning::change_current_learning_filename(){
 ifstream temp_file;
 ifstream tempstore;
 current_run=0;
 int nbr=-1;
 int error=1;
 int flag=0;
 char count='1';
 char todo[2];
 int todonumchar;
 tempstore.open(tempstorename);
 tempstore >> runs_to_do >> current_learning_filename >> current_recognition_filename;
 change_num_runs(todo,todonumchar);
 int dotpos=0;
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
 for (int pos=nbr;pos>=dotpos; pos--){
  current_learning_filename[pos+1+todonumchar]=current_learning_filename[pos];
  };
 if (todonumchar==2){
  current_learning_filename[pos+1+todonumchar+1]='\0';
  current_learning_filename[pos+1+todonumchar]=todo[1];
  current_learning_filename[pos+todonumchar]=todo[0];
 }else {current_learning_filename[pos+1+todonumchar+1]='\0';
		  current_learning_filename[pos+1+todonumchar]=todo[0];
		 };
 do{
	current_learning_filename[pos+1]=count;
	temp_file.open(current_learning_filename,ios::nocreate);
	current_run++;
	if (temp_file == NULL){
	 flag=1;
	 };
	temp_file.close();
	count++;
	} while (flag==0);

};
//************************************************************************
void random_learning::extract_learning(){
 char ch;
 char line[60];
 learning_filename="btxt.na";
learning_file.open(learning_filename);
current_learning_file.open(current_learning_filename);

do{
 ch = learning_file.get();
 }while((ch == ' ') || (ch == '\n'));
 learning_file.putback(ch);

learning_file.getline(line,60);
num_compounds=1;
while (line[0]!='\0'){
 current_learning_file << line << '\n';
 learning_file.getline(line,60);
 num_compounds++;
 };
current_learning_file.close();
};
//************************************************************************
void random_learning::load_compound_names(){
		char dump[70];
int temp_num_compounds=0;
char ch;
int nbr;
		char compname[15];
ofstream temp_recognition_file;
results_file.open(results_filename);
temp_recognition_file.open(temp_recognition_filea_name);
/*do{
 recognition_file.seekg(learning_file.tellg()+1);
 ch = recognition_file.peek();
 }while((ch == ' ') || (ch == '\n'));
*/
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
 int nbr;
		char compoundname[15];
		char dump[70];
 char *rowbins;
 ifstream input_temp_file;
 // one by one, they followed the sun
 ofstream output_temp_file;
 // two by two, to another rendezvous
 rowbins = new char [runs_to_do];
 int lcv;
 char bin;
 if (current_run % 2 ==1) {
  input_temp_file.open(temp_recognition_fileb_name);
  output_temp_file.open(temp_recognition_filea_name);
  }else{
	 input_temp_file.open(temp_recognition_filea_name);
	 output_temp_file.open(temp_recognition_fileb_name);
	};
 results_file.open(results_filename);
 for (lcv=1; lcv<=num_compounds; lcv++){
  input_temp_file >> compoundname;
  for (nbr=1; nbr < current_run-1; nbr++){
	input_temp_file.get(dump,70,'_');
	input_temp_file >> rowbins[nbr];
	input_temp_file.ignore (70,'\n');
	};
  results_file.ignore(70,'_');
  results_file >> rowbins[current_run];
  output_temp_file << compoundname;
  for (nbr=2; nbr <= current_run; nbr++){
	output_temp_file << ' ' << rowbins[nbr];
  output_temp_file << '\n';
  };
 };
 input_temp_file.close();
 output_temp_file.close();
 results_file.close();
};

//************************************************************************
void random_learning::run_test(){
 char stuffer[]={'c',':','\\','w','i','n','\\','z','a','p','.','b','a','t',13};
 loadbuf(stuffer);
 exit(0);
};

//************************************************************************
void random_learning::first_run(int num_runs,char *recout, char *learnout){
ofstream tempstore;
tempstore.open(tempstorename);
tempstore << num_runs << " " << learnout <<" " << recout << " ";
tempstore.close();
runs_to_do = num_runs;
change_current_learning_filename();
run_test();
};
//************************************************************************
void random_learning::run_tests(){
	 runs_to_do=3;

change_current_learning_filename();
while (current_run < runs_to_do){
	extract_learning();
	if (current_run==2){
	 load_compound_names();
	 };
	extract_recognition_data();
	run_test();
	};
};

//************************************************************************
void random_learning::test(){
 change_current_learning_filename();
	extract_learning();
	if (current_run==2){
	 load_compound_names();
	 };
	extract_recognition_data();
};
//************************************************************************
void main(int argc, char *argv[]){
 random_learning random;
 char name1[50];
 char name2[50];
 int tests;
 if (argv[1][0]=='r'){
  random.run_tests();
 }else{
 cout << "Enter the number of tests you wish to run: ";
 cin >> tests;
 cout << "Enter the name of the file to be produced containing the recognition table:\n";
 cin >> name1;
 cout << "Enter the name of the files to be produced containing the learning setups\n(the last letter of the name will hold the number of the test\nfor which the file was used:\n";
 cin >> name2;
 random.first_run(tests,name1,name2);
 };
// random.test();
};
