#include "header.h"

// Looks for the highest balance
void highestBalance(float topBalance[], int& locationOfHighBalance) {
	int i, x;
	float placeHolder;
	for (i = 1; i < 10; i++) {
		placeHolder = topBalance[i];
		x = i - 1;
		while (x >= 0 && topBalance[x] > placeHolder) {
			topBalance[x + 1] = topBalance[x];
			x = x - 1;
		}
		topBalance[x + 1] = placeHolder;
	}
	locationOfHighBalance = 9;
}