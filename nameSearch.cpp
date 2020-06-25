#include "Header.h"

// Searches for name that the user wants to
bool nameSearch(int& location, string names[], string userIn, string inputFileName, string peoplesNames[]) {
	ifstream iFile(inputFileName);
	listOfPeople peopleData;
	const int SIZE = 10;
	bool found;
	found = false;
	int index = 0;
	while (!found && index < SIZE)
	{
		if (peoplesNames[index] == userIn)
		{
			location = index;
			found = true;
			return found;
		} else {
			index++;
		}
	}
	return false;
}