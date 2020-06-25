#include "Header.h"

/**********************************************************************
* AUTHOR   : Oscar Solis-Pacheco
* Lab #6   : Structs
* CLASS    : CS1B
* SECTION  : MTWTH: 5p - 7:20p
* Due Date : 6/23/20
***********************************************************************/

/***********************************************************************
*
* Structs
*
* ----------------------------------------------------------------------
* This program will search for a desired name on the list and then tell
* the user whether it was found or not. Then, it will display the person
* with the highest balance. It will also get the sum of all balances and
* display it in the OFile.
* ---------------------------------------------------------------------
* INPUT:
* 	inputFileName: Gets the name that the user wants to get data from.
* 	outputFileName: Gets the name that the user wants to output data to.
* 	userIn:	Gets the name that the user wants to search for.
*
* OUTPUT:
* 	nameSearch: Will tell the user whether or not name exists and if it
* 				they do exist, it will write to file.
* 	sumOfBalances: Will display sum of all balances
* 	highestBalance: Will show the person with highest balance.
*
*************************************************************************/



// START OF MAIN FUNCTION
int main() {

	/***********************************************************************
	* CONSTANTS
	* ---------------------------------------------------------------------------
	* OUTPUT - USED FOR CLASS HEADING
	* ---------------------------------------------------------------------------
	* PROGRAMMER: Oscar Solis-Pacheco
	* CLASS     : CS1B
	* SECTION   : MTWTH: 5:00p - 7:20p
	* LAB       : 6
	* LAB_NAME  : STRUCTS
	************************************************************************/


	// CHAR VARIABLES
	char inputFileName[20];
	char outputFileName[20];

	// FLOAT VARIABLES (ARRAYS)
	float balanceListOne[10];
	float balanceListTwo[10];
	float balanceSearched[10];
	// FLOAT VARIABLES
	float balanceTotalDue;
	float balanceTotal;

	// INT VARIABLE (CONSTANT)
	const int SIZE = 10;
	// INT VARIABLES
	int locationOfHighBalance;
	int displayHeader;
	int idList[10];
	int idSearched[10];
	int key;
	int loop;
	int locationOfPerson;
	int idOfBiggestBalance;
	
	// STRING VARIABLES (ARRAYS)
	string nameSearched[10];
	string lines[10];
	string names[10];
	// STRING VARIABLES
	string nameOfPeople;
	string biggestBalancePerson;
	ifstream inFile;
	ifstream iFile;
	ofstream oFile;
	listOfPeople peopleData;

	// ASSIGNING VARIABLES TO A VALUE
	balanceTotalDue = 0;
	balanceTotal = 0;
	locationOfHighBalance = 0;
	displayHeader = 0;
	key = 0;
	loop = 0;

	// DISPLAYS THE CLASS HEADER ONE TIME
	displayClassHeader();

	// ASKS THE USER WHAT THE FILE NAMES THEY WANT TO USE
	getFileNames(inputFileName, outputFileName);

	// OPENS THE FILES
	iFile.open(inputFileName);
	oFile.open(outputFileName);
	inFile.open(inputFileName);
	
	// POPULATES THE ARRAYS
	for (int i = 0; i < 10; i++) {
		getline(inFile, peopleData.name[i]);
		names[i] = peopleData.name[i];
		inFile >> peopleData.id[i];
		idList[i] = peopleData.id[i];
		inFile >> peopleData.balance[i];
		balanceListOne[i] = peopleData.balance[i];
		balanceListTwo[i] = peopleData.balance[i];
		inFile.ignore(1000, '\n');
	}

	// PROGRAM LOOPS UNTIL THEY TYPE "DONE"
	programLoop(iFile, oFile, displayHeader,
		inputFileName, names, balanceListOne, idList,
		idSearched, loop, nameSearched, balanceSearched, key);

	// GETS THE HIGHEST BALANCE AND THE LOCATION
	highestBalance(balanceListOne, locationOfHighBalance);

	// FOR LOOPS FOR THE HIGHEST BALANCE AND LOCATION
	for (int i = 0; i < SIZE; i++) {
		balanceTotal += balanceListOne[i];
	}
	for (int i = 0; i < SIZE; i++) {
		if (balanceSearched[i] > 0) {
			balanceTotalDue += balanceSearched[i];
		}
	}
	for (int i = 0; i < SIZE; i++) {
		if (balanceListTwo[i] == balanceListOne[locationOfHighBalance]) {
			locationOfPerson = i;
		}
	}
	// TOTALS THE BALANCE
	balanceTotalDue += balanceListOne[locationOfHighBalance];

	// WRITES TO FILE
	output(oFile, nameSearched, names, balanceSearched, balanceListOne, 
		balanceTotal, balanceTotalDue, idList, idSearched, locationOfHighBalance,
		key, locationOfPerson);

	// END OF PROGRAM
	cout << endl << endl;
	system("pause");
	return 0;
}