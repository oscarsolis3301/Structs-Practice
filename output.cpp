#include "header.h"

// Writes to file
void output(ofstream& oFile, string nameSearched[], string names[], float balanceSearched[], 
	float balanceListOne[], float balanceTotal, float balanceTotalDue, int idList[], int idSearched[], int locationOfHighBalance,
	int key, int location) {

	oFile << "Higher Balance:\n";
	oFile << "ID #     NAME                     BALANCE DUE\n";
	oFile << "----     --------------------     -----------\n";
	oFile << idList[location] << "     " << names[location] << left << "\t\t      $" 
		  << right << fixed << setw(10) << setprecision(2) << balanceListOne[locationOfHighBalance] << endl << endl;

	oFile << "Total Balance for all person:\n";
	oFile << "$   " << balanceTotal << endl << endl;

	oFile << "Search Names:\n";
	oFile << "ID #     NAME                     BALANCE DUE\n";
	oFile << "----     --------------------     -----------";
	for (int i = 0; i < key; i++) {
		if (nameSearched[i].length() >= 13 && nameSearched[i].length() < 17) {
			oFile << "\n" << idSearched[i] << "     " << nameSearched[i] << left << "\t\t      $" << right
				<< fixed << setw(10) << setprecision(2) << balanceSearched[i];
		} else if(nameSearched[i].length() < 13) {
			oFile << "\n" << idSearched[i] << "     " << nameSearched[i] << left << "\t\t          $" << right
				<< fixed << setw(10) << setprecision(2) << balanceSearched[i];
		} else if(nameSearched[i].length() >= 17) {
			oFile << "\n" << idSearched[i] << "     " << nameSearched[i] << left << "\t\t  $" << right
				<< fixed << setw(10) << setprecision(2) << balanceSearched[i];
		}
	
	}
	oFile << endl << endl;
	oFile << "\t\t\t   Total Balance Due: $\t  " << fixed << setprecision(2) << balanceTotalDue;
}