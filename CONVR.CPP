#include <c:\jesse\conwin\cnfp3.h>
#include <iostream.h>


char compound_inputfilename[30];
char *compound_outputfilename="c:\\jesse\\confor2\\data\\btxt.ra";
char *dictionary_filename="c:\\jesse\\confor2\\data\\diction.a";


void main(){
 cout << "\nRecognition Convertor\n";

 cout << "Enter the name of the excel file: ";
 cin >> compound_inputfilename;
 recognition_conversion learn1;
 learn1.convert_recognition_rows(compound_outputfilename,dictionary_filename,compound_inputfilename);
};