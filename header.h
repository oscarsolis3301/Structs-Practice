#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <vector>

const char PROGRAMMER[30] = "Oscar Solis-Pacheco"; // NAME
const char CLASS[5] = "CS1B";					  // CLASS
const char SECTION[25] = "MTWTH: 5:00p - 7:20p"; // TIME OF CLASS
const int LAB_NUM = 6;                          // LAB NUMBER
const char LAB_NAME[25] = "Structs";		   // NAME OF LAB

using namespace std;

struct listOfPeople {
	string name[10];
	int id[10];
	float balance[10];
};

struct userTypeName {
	string name;
};

void displayClassHeader();

string userInput(ifstream& inFile, ofstream& oFile, int& header, string data[]);

bool nameSearch(int& location, string names[], string userIn, string inputFileName, string peoplesNames[]);

void getFileNames(char inputFileName[], char outputFileName[]);

void programLoop(ifstream& iFile, ofstream& oFile, int& displayHeader,
	string inputFileName, string peopleNames[], float balanceList[], int idList[],
	int idSearched[], int& loop, string nameSearched[], float balanceSearched[], int& key);

void highestBalance(float topBalance[], int& locationOfHighBalance);

void output(ofstream& oFile, string nameSearched[], string names[], float balanceSearched[],
	float balanceListOne[], float balanceTotal, float balanceTotalDue, int idList[], int idSearched[], int locationOfHighBalance,
	int key, int location);