//Jesse Anderson

#include<dos.h>
#include<process.h>
#include <iostream.h>
#include<c:\jesse\conwin\cnfp3.h>
#include<c:\jesse\confor2\runtest.h>

class condos{
 public:
	condos();
	~condos();
	void run();
	void run_tests(char argv);
 private:
	void convert_files();
	char *get_learning_inputfilename();
	char *get_recognition_inputfilename();
	char *get_compound_outputfilename();
	char *get_dictionary_filename();
	int  check_file();
	void file_error();
};

condos::condos(){};
condos::~condos(){};

void condos::run(){
 int choice;
 cout << "ConShell\n\n";
 cout << "1. Convert Files\n";
 cout << "2. Run Tests (with previously converted files)\n";
 cout << "3. Exit Conshell\n";
 cout << "\n> ";
 cin >> choice;
 switch (choice){
  case 1:{convert_files();
			 break;};
  case 2:{run_tests(' ');
			 break;};
  case 4:break;
  };
};

char *condos::get_learning_inputfilename(){
char name[20];
cout << "\nEnter the path and name of the excel file containing bins\nand learning data.\n>";
cin >> name;
return name;
};

char *condos::get_recognition_inputfilename(){
char name[20];
cout << "\nEnter the path and name of the excel file containing recognition information.\n  :";
cin >> name;
return name;
};

char *condos::get_compound_outputfilename(){
char *name="btxt.na";
return name;
};

char *condos::get_dictionary_filename(){
char *name="diction.a";
return name;
};

void condos::convert_files(){
	int choice;
	cout << "\n1. Convert learning files\n";
	cout << "2. Convert recognition files\n";
	cout << "3. Cancel\n";
	cout << "\n> ";
	cin >> choice;
	switch (choice){
	 case 1: {learning_conversion Learn1;
				 Learn1.convert_learning(
								get_compound_outputfilename(),
								get_dictionary_filename(),
								get_learning_inputfilename());
				  break;};
	 case 2: {recognition_conversion Recog1;
				 Recog1.convert_recognition_rows(get_compound_outputfilename(),
								get_dictionary_filename(),
								get_recognition_inputfilename());
				 break;};
	 case 3:{break;};
	 };
};

void condos::run_tests(char argv){
random_learning random;
 randomize;
 char name1[50];
 char name2[50];
 char ch;
 int tests;
 if (argv =='r'){
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

};



void main(int argc, char *argv[]){
  condos runner;
if (argv[1][0]=='r'){
 runner.run_tests(argv[1][0]);
 }else{ 
  runner.run(); };
};


