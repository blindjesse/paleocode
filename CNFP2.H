// Jesse Anderson
// last work done 7/1/96 end of day

#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<ctype.h>

const max_att_size = 10; // holds the maximum size of the attribute name
const max_num_bins = 10; // holds the maximum number of bins
const max_num_atts = 40; // holds the maximum number of attributes

typedef char name[max_att_size];
typedef struct compoundrow{
  float *attributes;
  char compoundname[20];};

class conversion{
 protected:
	 conversion();
	 ~conversion();
	 int num_attributes;
	 int num_bins;
	 float *bins;
	 compoundrow compound;
	 name *attribute_names;
	 ifstream compound_inputfile;
	 char compound_inputfilename[40];
	 ofstream compound_outputfile;
	 char compound_outputfilename[40];
	 ofstream temp1_compound_file;
	 char *temp1_compound_filename;
	 ofstream temp2_compound_file;
	 char *temp2_compound_filename;
	 virtual void load_row();
	 virtual void save_row(int bin_counter);
	 void combine_output_files();
	 char bin_calc(int pos,int &bin_counter);
 };

class learning_conversion: private conversion{
  public:
	 void convert_learning();
	 learning_conversion::learning_conversion();
	 learning_conversion::~learning_conversion();
  private:
	 void convert_rows();
	 void load_bin_rules();
	 void save_bin_rules();
	 ofstream dictionary_file;
	 char dictionary_filename[40];
  };

class recognition_conversion: private conversion {
  public:
	 void convert_recognition_rows();
	 recognition_conversion();
	~recognition_conversion();
  private:
	 void load_bins();
	 void load_row();
	 void save_row(int bin_counter);
	 ifstream dictionary_file;
	 char dictionary_filename[40];
	};


//---------------------------------------------------------------------//
conversion::conversion(){
// Constructor for conversion
 attribute_names =NULL;
 bins = NULL;
 temp1_compound_filename = "temp1.dat";
 temp2_compound_filename = "temp2.dat";
 };

//---------------------------------------------------------------------//

conversion::~conversion(){
// Destructor for conversion
 if (attribute_names!=NULL)
	delete [] attribute_names;
 if (bins!=NULL)
	delete [] bins;
 };

//---------------------------------------------------------------------//

void conversion::load_row(){
// pre: the file cursor is at the beginning of a line containing compound
//		  information and formatted correctly
// post: the row is loaded into compound
int nbr;
compound.attributes = new float[num_attributes];
 compound_inputfile >> compound.compoundname;
for (nbr=0; nbr <=num_attributes-1; nbr++){
 compound_inputfile >> compound.attributes[nbr];
 };
};

//---------------------------------------------------------------------//

void conversion::save_row(int bin_counter){
// pre: a valid compound row is stored in compound
// post: the row in compound is converted to confor format and stored in
// 		temp_compound_file
char *btc =" belongs to class ";
char *hat =" has attribute ";
int nbr;
temp1_compound_file <<  compound.compoundname << btc << attribute_names[0] << "_" << bin_calc(0,bin_counter)<<" ;\n";
bin_counter++;
for (nbr=1; nbr<=num_attributes-1; nbr++){
 temp2_compound_file << compound.compoundname << hat << attribute_names[nbr] << "_" << bin_calc(nbr,bin_counter)<<" ;\n";
 bin_counter++;
 };
};

//---------------------------------------------------------------------//

void conversion::combine_output_files(){
char *buffer;
char ch;
int nbr=0;
int count=0;
ifstream temp1;
ifstream temp2;
temp1.open(temp1_compound_filename);
temp2.open(temp2_compound_filename);
cout << "Enter the name of the file you wish to produce";
cout << " containing\nthe compound information.\n: ";
cin.getline(compound_outputfilename,40);
compound_outputfile.open(compound_outputfilename);

buffer = new char[80];
compound_outputfile << "\n";
do{
  temp1.getline(buffer,80,'\n');
  compound_outputfile << buffer<< '\n';
  }while (!temp1.eof());

do{
  temp2.getline(buffer,80,'\n');
  compound_outputfile << buffer << '\n';
  nbr++;
  if (nbr%(num_attributes-1)==0){
	compound_outputfile << '\n';};
  }while (!temp2.eof());

while(compound_outputfilename[count]!='\0'){
	  count++;};
ch = compound_outputfilename[count-1];
compound_outputfile << "task " << char(_toupper(ch)) << ";";
compound_outputfile.close();
delete [] buffer;
};

//---------------------------------------------------------------------//

char conversion::bin_calc(int pos,int &bin_counter){
// pre: a row is stored in compound, and a valid attribute row number is stored
// 	  in pos
// post: the attribute value of the number corresponding to the row and position
//	   	given is returned
char ch;
ch=96;
do{
 ch++;
 }while((ch<115)&&(compound.attributes[pos]<bins[bin_counter+(ch-97)*2]) ||
		(compound.attributes[pos]>bins[bin_counter+(ch-97)*2+1]));
 if (ch>=115){
 cerr << "Invalid input in compound " << compound.compoundname << " , please check data.";
 }
do{
  bin_counter++;
  }while (bins[bin_counter+(ch-97)*2]>=0);
 bin_counter+=((ch-97)*2);
 return ch;
};

//---------------------------------------------------------------------//

learning_conversion::learning_conversion(){
// Constructor for learning_conversion
};

//---------------------------------------------------------------------//

learning_conversion::~learning_conversion(){
// Destructor for learning_conversion
}

//---------------------------------------------------------------------//

void learning_conversion::convert_learning(){
// pre: none
// post: an excel file in the specified format is saved in
//       confor format in another set of files
  cout << "Enter the name of the file containing the compound information that \nyou wish to convert.\n: ";
  cin.getline(compound_inputfilename,40);
  compound_inputfile.open(compound_inputfilename);
  if (!compound_inputfile.fail()){
  load_bin_rules();
  save_bin_rules();

  convert_rows();
  combine_output_files();
  compound_inputfile.close();
  cout << "\nFinished.\n ";}
 else cerr << "Cannot open file.  Please verify filename and try again.";
 };

//---------------------------------------------------------------------//

void learning_conversion::convert_rows(){
// pre: the file cursor is positioned at the beginning of the row info
// post: all rows have been converted to confor format and saved
char null;
int bin_counter;
temp1_compound_file.open(temp1_compound_filename);
temp2_compound_file.open(temp2_compound_filename);

  do {compound_inputfile.get(null);
	}while (null != '\n');
while (!compound_inputfile.eof()){
 bin_counter=0;
 load_row();
 if (!compound_inputfile.eof()){
  save_row(bin_counter);
  };
 do {compound_inputfile.get(null);
  }while (null != '\n');
 };
 compound_outputfile << "\n";
temp1_compound_file.close();
temp2_compound_file.close();
};

//---------------------------------------------------------------------//

void learning_conversion::load_bin_rules(){
// pre: a valid file is opened in the compound_inputfile variable
// post: the bin rules are loaded into the bins variable from compound_inputfile
int row=0,counter=0;
char tempchar;
char *named="NAME";
attribute_names = new name[max_num_atts];
bins = new float[max_num_atts * 30];

compound_inputfile >> attribute_names[row];
num_attributes=0;
while (strncmp(attribute_names[row],named,4)!=0){// while the name != "NAME"
 compound_inputfile.get(tempchar);
 while ((counter <= (max_num_bins+1)*max_num_atts) && (tempchar != '\n')){
  compound_inputfile>> bins[counter];
  compound_inputfile.get(tempchar);
  counter ++;
  };
 num_attributes++;
 bins[counter]=-300;
 counter++;
 row++;
 compound_inputfile >> attribute_names[row];
 };
};

//---------------------------------------------------------------------//

void learning_conversion::save_bin_rules(){
// pre: the binrules have been loaded into the bins variable
// post: the binrules are converted into the confor file format and
// 		saved in compound_outputfile
char *att="attribute ";
char *bin=" - binning ";
char ch=97;
int nbr=0,row;

cout << "Enter the name of the file to be created containing the dictionary information.\n: ";
cin.getline(dictionary_filename,40);
dictionary_file.open(dictionary_filename);
for (row = 0; row <=num_attributes-1; row++){
 while (bins[nbr]>=0){
  dictionary_file << att << attribute_names[row] << bin << ch <<" : [ ";
  dictionary_file << bins[nbr] << " - ";
  dictionary_file << bins[nbr+1] << "  ] ;\n";
  nbr+=2;
  ch++;
  };
  nbr++;
  ch=97;
 dictionary_file << '\n';
 };
dictionary_file.close();
};

//---------------------------------------------------------------------//

recognition_conversion::recognition_conversion(){
 attribute_names = new name[max_num_atts];
 bins = new float[max_num_bins*max_num_atts*2];
};

//---------------------------------------------------------------------//

recognition_conversion::~recognition_conversion(){
 if (attribute_names!=NULL)
  delete [] attribute_names;
 if (bins!=NULL)
  delete [] bins;
};

//---------------------------------------------------------------------//

void recognition_conversion::convert_recognition_rows(){
int bin_counter;

temp1_compound_file.open(temp1_compound_filename);
temp2_compound_file.open(temp2_compound_filename);

 load_bins();
 cout << "Enter the name containing the compound information you wish to convert.\n: ";
 cin.getline(compound_inputfilename,40);
 compound_inputfile.open(compound_inputfilename);
 if (!compound_inputfile.fail()){
  compound_inputfile.ignore(300,'\n');
  while(!compound_inputfile.eof()){
	bin_counter=0;
	load_row();
	if (!compound_inputfile.eof()){
	 save_row(bin_counter);
	 };
	};
  temp1_compound_file.close();
  temp2_compound_file.close();
  compound_inputfile.close();
  combine_output_files();
  cout << "\nFinished.";
 }else cout << "Unable to open file.  Please check name and try again.";
};

//---------------------------------------------------------------------//

void recognition_conversion::load_row(){
char ch;
int nbr=0;

compound.attributes = new float[num_attributes];
 compound_inputfile >> compound.compoundname;
 compound_inputfile.get(ch);
while ((nbr <= num_attributes-1) && (ch != '\n')){
 compound_inputfile >> compound.attributes[nbr];
 compound_inputfile.get(ch);
 nbr++;
  };
};

//---------------------------------------------------------------------//

void recognition_conversion::save_row(int bin_counter){

char *btc =" belongs to class ";
char *hat =" has attribute ";
int nbr;

temp1_compound_file << compound.compoundname << btc << " ? ;\n";
bin_counter+=9;
for (nbr=1; nbr<=num_attributes-1; nbr++){
  temp2_compound_file << compound.compoundname << hat << attribute_names[nbr] << "_" << bin_calc(nbr,bin_counter)<<" ;\n";
  bin_counter++;
 };
};

//---------------------------------------------------------------------//

void recognition_conversion::load_bins(){
int loop1=0,loop2=0,nbr=0;
char ch;
	cout << "Enter the name of the inputfile containing the dictionary information.\n:";
	cin.getline(dictionary_filename,40);
	dictionary_file.open(dictionary_filename);
  if (!dictionary_file.fail()){
	 num_attributes=0;
	while (!dictionary_file.eof()){
	 nbr++;
	 num_attributes++;
	 dictionary_file.ignore(10,' ');
	 dictionary_file >> attribute_names[loop1];
	 do{
	  dictionary_file.ignore(40,'[');
	  dictionary_file >> bins[loop2];
	  dictionary_file.ignore(3,'-');
	  dictionary_file >> bins[loop2+1];
	  dictionary_file.ignore(6,'\n');
	  loop2+=2;
	  dictionary_file.get(ch);
	  }while (ch=='a');
	  bins[loop2]=-300;
	  loop2++;
	  dictionary_file.get(ch);
	  loop1++;
	}; // while loop1
  } //if
  else cerr<<"Unable to open file.  Please verify name and try again.";
  };

void convert_learn(char *input,char *compound, char *diction){
 learning conversion *learner;
 learner= new learning_conversion;
 learner.convert_learning;
 delete learner;
};
void convert_recogn(){};
