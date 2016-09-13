#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>
#include "StrType.h" // #include the file containing class/data structure to test

InType Allowed(std::string& inString);
bool Skip(std::string& inString);
int main()
{

  using namespace std;
	
  ifstream inFile; //file containing operations
  ifstream inData; //input data file
  ofstream outFile; //file to write results of operations to
	
  string inFileName, outFileName,inDataName, outFileLabel; //strings for file names and file label
	
  string command; //command to execute
  string skip;
  string allowed;
  int numCommands; //number of commands executed
	
  // Here you declare a variable of the type being tested, instantiate a class that is
  StrType inputString;	
  // Prompt for file names, read file names and prepare files
	
  cout << "Enter name of input file:  " << endl;
  cin >> inFileName;
  inFile.open( inFileName.c_str() );
	
  cout << "Enter the name of output file: " << endl;
  cin >>outFileName;
  outFile.open( outFileName.c_str() );
  
  cout << "Enter name of input data file: ";
  cin >> inDataName;
  inData.open(inDataName.c_str());
	
  cout << "Enter name of test run (label for output file): " << endl;
  cin >> outFileLabel;
  outFile << outFileLabel << endl;
	
  inFile >> command;
  numCommands = 0;
	
  while ( command != "Quit" ) {
    // The following should be specific to the structure being tested
    // Execute the command by invoking the member function of the
    // same name
    // Print the results to output file
    	
    if (command == "GetString") {
      inFile >> skip >> allowed;
      inputString.GetStringFile(Skip(skip), Allowed(allowed),inData);
    }
    else if (command == "MakeEmpty")
      inputString.MakeEmpty();
    else if (command == "PrintToFile")
      inputString.PrintToFile(true, outFile);
    else if (command == "PrintToScreen")
      inputString.PrintToScreen(true);
    else if (command == "CopyString") {
      StrType secondString;
      inputString.CopyString(secondString);
      outFile << "String to copy: ";
      inputString.PrintToFIle(false, outFile);
      outFile << " Copy of string";
      secondString.PrintToFile(false, outFile);
    }
    else {
      outFile << endl << "length of string: ";
      inputString.PrintToFile(false, outFile);
      outFile << " is " << inputString.LengthIs() << endl;
    }
    numCommands++
    cout << " Command number" << numCommands << "completed" << endl;
    inFile >> command;
  }
	
  cout << "Testing completed..." << endl;
  inFile.close();   //close file
  outFile.close(); //close file so it saves
	
  return 0;
}

InType Allowed(std::string& inString)
{
  if (inString == "ALPHA_NUM")
    return ALPHA_NUM;
  else if (inString == "ALPHA")
    return ALPHA;
  else if (inString == "NON_WHITE")
    return NON_WHITE
  else return NOT_NEW;
}

bool Skip(std::string& inString)
{
  if (inString == "true")
    return true;
  else return false;
}
