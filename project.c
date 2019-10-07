/* ENGGEN131 Project - C Project - 2019 */
/* The Warehouse */

/* << Include your information here - name, user name, ID number >> */

#include <stdlib.h>
#include "project.h"
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

int IsPrime(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int compareInts(const void *aPointer, const void *bPointer) {
    int a = *((int*) aPointer);
    int b = *((int*) bPointer);
    return (a > b) - (a < b);
}

/*
Your comment should go here � it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/
int TimeWorked(int minuteA, int secondA, int minuteB, int secondB) {
	int timeA = minuteA * 60 + secondA;
	int timeB = minuteB * 60 + secondB;
	return abs(timeA - timeB);
}

/*
Your comment should go here � it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/
int WarehouseAddress(int maximum) {
	// start at the maximum address and count down until we find a prime
	int i = maximum;

	// if `i` is even, it definitely isn't a prime so decrement
	if (i % 2 == 0) i--;

	// check through all odd numbers, starting from the top
	for (; i > 0; i -= 2) {
		// return the highest prime number
		if (IsPrime(i)) return i;
	}

	// oh no, we didn't find a prime
	// (this is literally impossible as 1 is a prime number)
	return -1;
}

/*
Your comment should go here � it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/
void Advertise(char *words) {
	// strings are null-terminated, find length of string
	int length = -1;
	while (words[++length]);

	// store first character
	char firstChar = words[0];

	// rotate characters
	for (int i = 1; i < length; i++) {
		words[i - 1] = words[i];
	}

	// append first character to the end
	words[length - 1] = firstChar;
}

/*
Your comment should go here � it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/

int WinningBid(int *values, int length) {
	// if their is only one bid then it wins by default
	if (length == 1) {
		return values[0];
	}

	// sort bids ascending
	qsort(values, length, sizeof(int), compareInts);

	// check if lowest bid is unique
	if (values[0] != values[1]) {
		return values[0];
	}

	// check if any bids in the middle are unique
	for (int i = 1; i < length - 1; i++) {
		// unique if different from elements before and after
		if (values[i - 1] != values [i] && values[i] != values [i + 1]) {
			return values[i];
		}
	}

	// check if highest bid is unique
	if (values[length - 2] != values[length - 1]) {
		return values[length - 1];
	}

	// no unique bids
	return -1;
}

/*
Your comment should go here � it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/
void BoxDesign(char *design, int width, int height) {
	// find positions for center marks
	int centerX1 = width / 2;
	int centerX2 = centerX1 - 1 + width % 2; // add another X if even width
	int centerY1 = height / 2;
	int centerY2 = centerY1 - 1 + height % 2; // add another X if even height

	// don't add center marks if there is no room for them
	if (width < 3 || height < 3) {
		centerX1 = centerX2 = centerY1 = centerY2 = -1;
	}

	int i = 0; // current position in string

	// loop through each row down the page
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			// add box borders
			if (0 == x || x == width - 1 || 0 == y || y == height - 1) {
				design[i++] = '*';
			}
			// add center marks
			else if ((centerX1 == x || x == centerX2) && (centerY1 == y || y == centerY2)) {
				design[i++] = 'X';
			}
			// space in the center of the box
			else {
				design[i++] = ' ';
			}
		}
		// add a newline at the end of each row
		design[i++] = '\n';
	}
}

/*
Your comment should go here � it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/
void WorkerRoute(int warehouse[WAREHOUSE_SIZE][WAREHOUSE_SIZE]) {
	// find location of worker and box
	int workerX, workerY, boxX, boxY;
	for (int y = 0; y < WAREHOUSE_SIZE; y++) {
		for (int x = 0; x < WAREHOUSE_SIZE; x++) {
			// check if it is the worker
			if (warehouse[y][x] == 1) {
				workerX = x;
				workerY = y;
			}
			// check if it is the box
			else if (warehouse[y][x] == 2) {
				boxX = x;
				boxY = y;
			}
		}
	}

	// draw path horizontally
	for (int x = MIN(workerX, boxX) + 1; x < MAX(workerX, boxX); x++) {
		warehouse[workerY][x] = 3;
	}

	// draw path vertically
	for (int y = MIN(workerY, boxY) + 1; y < MAX(workerY, boxY); y++) {
		warehouse[y][boxX] = 3;
	}

	// add in the intersection/corner (if the worker and box aren't there)
	if (warehouse[workerY][boxX] == 0) {
		warehouse[workerY][boxX] = 3;
	}
}

/*
Your comment should go here � it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/
int MakeMove(int warehouse[10][10], char move) {
	move = '0';
	warehouse[0][0] = warehouse[0][0];
	return 0;
}

