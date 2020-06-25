
#include "Header.h"

// Gets the name of the files that the user wants to use
void getFileNames(char inputFileName[], char outputFileName[]) {
	ifstream iFile;
	ofstream oFile;

	cout << "What input file would you like to use? ";
	cin.clear();
	cin.getline(inputFileName, 20);

	cout << "What output file would you like to use? ";
	cin.clear();
	cin.getline(outputFileName, 20);
}