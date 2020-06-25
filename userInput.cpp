
#include "Header.h"

// Gets the name they want to search for
string userInput(ifstream& iFile, ofstream& oFile, int& header, string data[]) {
	cin.clear();
	userTypeName nameSearch;
	if (header != 1) {
		// This will write the class heading to the file.
		oFile << "************************************************";
		oFile << "\n* PROGRAMMED BY : " << PROGRAMMER;
		oFile << "\n* CLASS \t\t: " << CLASS;
		oFile << "\n* SECTION \t\t: " << SECTION;
		oFile << "\n* LAB # " << LAB_NUM << "\t\t: " << LAB_NAME;
		oFile << "\n************************************************\n\n";
		header++;
	}
	cout << endl;
	cout << "Who do you want to search for (enter done to exit) : ";
	getline(cin, nameSearch.name);
	return nameSearch.name;
}