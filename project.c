/* ENGGEN131 Project - C Project - 2019 */
/* The Warehouse */

/* << Include your information here - name, user name, ID number >> */

#include <stdlib.h>
#include "project.h"

int IsPrime(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
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
	words[0] = '-';
	words[1] = '9';
	words[2] = '9';
	words[3] = '9';
	words[4] = '9';
	words[5] = '\0';
}

/*
Your comment should go here � it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/
int WinningBid(int *values, int length) {
	values[0] = length;
	return values[0] - length - 9999;

}

/*
Your comment should go here � it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/
void BoxDesign(char *design, int width, int height) {
	width = height;
	design[0] = '-';
	design[1] = '9';
	design[2] = '9';
	design[3] = '9';
	design[4] = '9';
	design[5] = '\0';
}

/*
Your comment should go here � it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/
void WorkerRoute(int warehouse[10][10]) {
	warehouse[0][0] = -9999;
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

