#include "Header.h"

// Ends program if user types "done," else it keeps running
void programLoop(ifstream& iFile, ofstream& oFile, int& displayHeader,
	string inputFileName, string peopleNames[], float balanceList[], int idList[], 
	int idSearched[], int& loop,string nameSearched[], float balanceSearched[], int& key) {

	listOfPeople peopleData;
	string data[10];
	const int SIZE = 10;
	int index = 0;
	int location = 0;
	
	bool running = true;
	while (running) {
		string userIn = userInput(iFile, oFile, displayHeader, data);
		if (userIn == "done") {
			cout << endl << "Thank you for using my program." << endl;
			running = false;
		} else {
			bool found = nameSearch(location, data, userIn, inputFileName, peopleNames);
			if (found == true) {

				int foundLocation = location;
				nameSearched[key] = userIn;
				idSearched[loop] = idList[foundLocation];
				balanceSearched[loop] = balanceList[foundLocation];
				loop++;
				key++;
				cout << "Found.\n";
			} else {
				cout << userIn << " was not found.\n";
			}
		}
	}


}
