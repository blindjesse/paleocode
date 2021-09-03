#include <c:\jesse\conwin\cnfp3.h>
#include <iostream.h>


char compound_inputfilename[30];
char *compound_outputfilename="c:\\jesse\\confor2\\data\\btxt.na";
char *dictionary_filename="c:\\jesse\\confor2\\data\\diction.a";


void main(){
 cout << "\nLearning Convertor\n";
 cout << "Enter the name of the excel file: ";
 cin >> compound_inputfilename;
 learning_conversion learn1;
 learn1.convert_learning(compound_outputfilename,dictionary_filename,compound_inputfilename);
};
