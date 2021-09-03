// Jesse Anderson
// last work done 7/1/96

#include<iostream.h>
#include<fstream.h>
#include<string.h>


const max_att_size = 10; // holds the maximum size of the attribute name
const max_comp_size = 15; //holds the maximum size of the compound name
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
	 virtual void save_row();
	 void combine_output_files();
	 char bin_calc(int pos);
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
	 void save_row();
	 ifstream dictionary_file;
	 char dictionary_filename[40];
	};

void main(){
 class recognition_conversion convertor;
 convertor.convert_recognition_rows();
}
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

void conversion::save_row(){
// pre: a valid compound row is stored in compound
// post: the row in compound is converted to confor format and stored in
// 		temp_compound_file
char *btc =" belongs to class ";
char *hat =" has attribute ";
int nbr;
temp1_compound_file <<  compound.compoundname << btc << attribute_names[0] << "_" << bin_calc(0)<< "\n";
for (nbr=1; nbr<=num_attributes-1; nbr++){
 temp2_compound_file << compound.compoundname << hat << attribute_names[nbr] << "_" << bin_calc(nbr)<<" ;\n";
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
ch = compound_outputfilename[count];
compound_outputfile << "task " << ch << " ;";
delete [] buffer;
};

//---------------------------------------------------------------------//

char conversion::bin_calc(int pos){
// pre: a row is stored in compound, and a valid attribute row number is stored
// 	  in pos
// post: the attribute value of the number corresponding to the row and position
//	   	given is returned
char ch;
ch=96;
do
 ch++;
while((compound.attributes[pos]<bins[((pos)*num_bins*2)+(ch-97)*2]) ||
		(compound.attributes[pos]>bins[((pos)*num_bins*2)+((ch-97)*2)+1]));
return ch;
};

//---------------------------------------------------------------------//

learning_conversion::learning_conversion(){
// Constructor for learning_conversion
};
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
  cout << "\nFinished. ";}
 else cerr << "Cannot open file.  Please verify filename and try again.";
 };

//---------------------------------------------------------------------//

void learning_conversion::convert_rows(){
// pre: the file cursor is positioned at the beginning of the row info
// post: all rows have been converted to confor format and saved
char null;

temp1_compound_file.open(temp1_compound_filename);
temp2_compound_file.open(temp2_compound_filename);

  do {compound_inputfile.get(null);
	}while (null != '\n');
while (!compound_inputfile.eof()){
 load_row();
 if (!compound_inputfile.eof()){
  save_row();
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
int row=0,counter,num_columns=0;
char tempchar;
char *named="NAME";
attribute_names = new name[max_num_atts];
bins = new float[max_num_atts * 30];
 compound_inputfile >> attribute_names[row];
while (strncmp(attribute_names[row],named,4)!=0){
 compound_inputfile.get(tempchar);
 counter = 0;
 while ((counter <= 29) && (tempchar != '\n')){
  compound_inputfile>> bins[counter+((row)*num_columns)];
  compound_inputfile.get(tempchar);
  counter ++;
  };
 num_columns = counter;
 row++;
 compound_inputfile >> attribute_names[row];
 };
 num_bins = (counter / 2);
 num_attributes = row;
};

//---------------------------------------------------------------------//

void learning_conversion::save_bin_rules(){
// pre: the binrules have been loaded into the bins variable
// post: the binrules are converted into the confor file format and
// 		saved in compound_outputfile
char *att="attribute ";
char *bin=" - binning ";
char cur_bin;
int nbr,row;

cout << "Enter the name of the file to be created containing the dictionary information.\n: ";
cin.getline(dictionary_filename,40);
dictionary_file.open(dictionary_filename);
for (row = 0; row <=num_attributes-1; row++){
 for (nbr = 0; nbr<=((num_bins-1)*2); nbr+=2){
  cur_bin = 97+(nbr/2);
  dictionary_file << att << attribute_names[row] << bin << cur_bin <<" : [ ";
  dictionary_file << bins[nbr+((row)*8)] << " - ";
  dictionary_file << bins[nbr+((row)*8)+1] << "  ] ;\n";
  };
 dictionary_file << '\n';
 };
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
 cout << "\nFinished.";
};

//---------------------------------------------------------------------//

void recognition_conversion::convert_recognition_rows(){
 temp1_compound_file.open(temp1_compound_filename);
 temp2_compound_file.open(temp2_compound_filename);

 load_bins();
 cout << "Enter the name containing the compound information you wish to convert.\n:";
 cin.getline(compound_inputfilename,40);
 compound_inputfile.open(compound_inputfilename);
 if (!compound_inputfile.fail()){
 compound_inputfile.ignore(300,'\n');
 while(!compound_inputfile.eof()){
	load_row();
  if (!compound_inputfile.eof()){
	save_row();
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

void recognition_conversion::save_row(){

char *btc =" belongs to class ";
char *hat =" has attribute ";
int nbr;

temp1_compound_file << compound.compoundname << btc << " ? ;\n";
for (nbr=1; nbr<=num_attributes-1; nbr++){
  temp2_compound_file << compound.compoundname << hat << attribute_names[nbr] << "_" << bin_calc(nbr)<<" ;\n";
 };
};

//---------------------------------------------------------------------//

void recognition_conversion::load_bins(){
int loop1=0,loop2=0,nbr=0;
char ch;
	cout << "Enter the name of the inputfile containing the dictionary information.\n: ";
	cin.getline(dictionary_filename,40);
	dictionary_file.open(dictionary_filename);
  if (!dictionary_file.fail()){
	 num_bins=0;
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
	  num_bins++;
	  }while (ch=='a');
	  dictionary_file.get(ch);
	  loop1++;
	}; // while loop1
  } //if
  else cerr<<"Unable to open file.  Please verify name and try again.";
  num_bins/=num_attributes;
  };

