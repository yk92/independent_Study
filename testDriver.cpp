#include <iostream>
#include <fstream>
#include <string>
// #include the file containing class/data structure to test

int main()
{

	using namespace std;
	
	ifstream inFile; //file containing operations
	ofstream outFile; //file to write results of operations to
	
	string inFileName, outFileName, outFileLabel; //strings for file names and file label
	
	string command; //command to execute
	int numCommands; //number of commands executed
	
	// Here you declare a variable of the type being tested, instantiate a class that is
	
	// Prompt for file names, read file names and prepare files
	
	cout << "Enter name of input file:  " << endl;
	cin >> inFileName;
	inFile.open( inFileName.c_str() );
	
	cout << "Enter the name of output file: " << endl;
	cin >>outFileName;
	outFile.open( outFileName.c_str() );
	
	cout << "Enter name of test run (label for output file): " << endl;
	cin >> outFileLabel;
	outFile << outFileLabel << endl;
	
	inFile >> command;
	numCommands = 0;
	
	while ( command != "Quit" ) {
	
		// The following should be specific to the structure being tested
   	    // Execute the command by invoking the member function of the
    	//  same name
    	// Print the results to output file
    	
    	numCommands++;
    	
    	cout << "Command number " << numCommands << " completed." << endl;
    	inFile >> command;
	}
	
	cout << "Testing completed..." << endl;
	inFile.close();   //close file
	outFile.close(); //close file so it saves
	
	return 0;
}