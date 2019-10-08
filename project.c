/* ENGGEN131 Project - C Project - 2019 */
/* The Warehouse */

/*\ 
 * AUTHOR: Matt Moran
 * USER: mmor330
 * ID #: 194231692
\*/ 

#include <stdlib.h> /* THIS LIBRARY IS NOT ALLOWED */
#include "project.h"
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

/* DEFINED IN project.h 
typedef struct  { 
   int y;
   int x;
} Point;
*/

int IsPrime(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int CompareInts(const void *aPointer, const void *bPointer) {
    int a = *((int*) aPointer);
    int b = *((int*) bPointer);
    return (a > b) - (a < b);
}

Point findInWarehouse(int warehouse[WAREHOUSE_SIZE][WAREHOUSE_SIZE], int tile) {
	Point p = { -1 };
	for (int y = 0; y < WAREHOUSE_SIZE; y++) {
		for (int x = 0; x < WAREHOUSE_SIZE; x++) {
			if (warehouse[y][x] == tile) {
				p.y = y;
				p.x = x;
				return p;
			}
		}
	}
}

int countInWarehouse3(int warehouse[WAREHOUSE_SIZE][WAREHOUSE_SIZE], int tile1, int tile2, int tile3) {
	int count = 0;
	for (int y = 0; y < WAREHOUSE_SIZE; y++) {
		for (int x = 0; x < WAREHOUSE_SIZE; x++) {
			if (warehouse[y][x] == tile1 || warehouse[y][x] == tile2 || warehouse[y][x] == tile3) {
				count++;
			}
		}
	}
	return count;
}
int countInWarehouse2(int warehouse[WAREHOUSE_SIZE][WAREHOUSE_SIZE], int tile1, int tile2) {
	return countInWarehouse3(warehouse, tile1, tile2, -1);
}
int countInWarehouse(int warehouse[WAREHOUSE_SIZE][WAREHOUSE_SIZE], int tile) {
	return countInWarehouse3(warehouse, tile, -1, -1);
}

int SwapTiles(int warehouse[WAREHOUSE_SIZE][WAREHOUSE_SIZE], Point p1, Point p2) {
    int p1Value = warehouse[p1.y][p1.x];
    int p2Value = warehouse[p2.y][p2.x];

    // fail if trying to move into a wall
    if (p1Value == WALL || p2Value == WALL) {
        return 1;
    }

	// fail if trying to swap a box with a worker or another box
	if (p1Value == BOX || p1Value == BOX_ON_TARGET) {
		if (p2Value == BOX || p2Value == BOX_ON_TARGET || p2Value == WORKER || p2Value == WORKER_ON_TARGET) {
			return 1;
		}
	}
	// fail if trying to swap a box with a worker or another box
	if (p2Value == BOX || p2Value == BOX_ON_TARGET) {
		if (p1Value == BOX || p1Value == BOX_ON_TARGET || p1Value == WORKER || p1Value == WORKER_ON_TARGET) {
			return 1;
		}
	}

    // check if moving off/onto a target
    int p1IsTarget = p1Value == TARGET || p1Value == BOX_ON_TARGET || p1Value == WORKER_ON_TARGET;
    int p2IsTarget = p2Value == TARGET || p2Value == BOX_ON_TARGET || p2Value == WORKER_ON_TARGET;

    // remove the 'on target' modifier from the source values
    if (p1Value == TARGET)           p1Value = SPACE;
    if (p2Value == TARGET)           p2Value = SPACE;
    if (p1Value == BOX_ON_TARGET)    p1Value = BOX;
    if (p2Value == BOX_ON_TARGET)    p2Value = BOX;
    if (p1Value == WORKER_ON_TARGET) p1Value = WORKER;
    if (p2Value == WORKER_ON_TARGET) p2Value = WORKER;

    // add the 'on target' modifier to the destination values
    if (p2IsTarget) {
        if (p1Value == SPACE)  p1Value = TARGET;
        if (p1Value == BOX)    p1Value = BOX_ON_TARGET;
        if (p1Value == WORKER) p1Value = WORKER_ON_TARGET;
    }
    if (p1IsTarget) {
        if (p2Value == SPACE)  p2Value = TARGET;
        if (p2Value == BOX)    p2Value = BOX_ON_TARGET;
        if (p2Value == WORKER) p2Value = WORKER_ON_TARGET;
    }

    // assign values to the warehouse
    warehouse[p1.y][p1.x] = p2Value;
    warehouse[p2.y][p2.x] = p1Value;

	return 0;
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
    // if there is only one bid then it wins by default
    if (length == 1) {
        return values[0];
    }

    // sort bids ascending
    qsort(values, length, sizeof(int), CompareInts);

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
    Point worker = findInWarehouse(warehouse, 1);
	Point box = findInWarehouse(warehouse, 2);

    // draw path horizontally
    for (int x = MIN(worker.x, box.x) + 1; x < MAX(worker.x, box.x); x++) {
        warehouse[worker.y][x] = 3;
    }

    // draw path vertically
    for (int y = MIN(worker.y, box.y) + 1; y < MAX(worker.y, box.y); y++) {
        warehouse[y][box.x] = 3;
    }

    // add in the intersection/corner (if the worker and box aren't there)
    if (warehouse[worker.y][box.x] == 0) {
        warehouse[worker.y][box.x] = 3;
    }
}

/*
Your comment should go here � it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/
int MakeMove(int warehouse[WAREHOUSE_SIZE][WAREHOUSE_SIZE], char move) {
    static int targetsCovered, totalTargets;
    if (!totalTargets) {
        // count total number of targets
        totalTargets = countInWarehouse3(warehouse, TARGET, BOX_ON_TARGET, WORKER_ON_TARGET);
    }

    // find location of worker
    Point worker = findInWarehouse(warehouse, WORKER);

	// these points hold the locations we will travel to
	// p2 is the location the worker will move to
	// p3 is the location the box will move to (if we are pushing a box)
	Point p2, p3;
	p2.y = p3.y = worker.y;
	p2.x = p3.x = worker.x;

	// determine if we are pushing a box or not
	int pushingBox = 0;
    switch (move) {
        // up
        case 'w': {
			p2.y = worker.y - 1;
            if (warehouse[p2.y][p2.x] == BOX) {
				pushingBox = 1;
				p3.y -= 2;
            }
            break;
        }
        // left
        case 'a': {
			p2.x = worker.x - 1;
            if (warehouse[p2.y][p2.x] == BOX) {
				pushingBox = 1;
				p3.x -= 2;
            }
            break;
        }
        // down
        case 's': {
			p2.y = worker.y + 1;
            if (warehouse[p2.y][p2.x] == BOX) {
				pushingBox = 1;
				p3.y += 2;
            }
            break;
        }
        // right
        case 'd': {
			p2.x = worker.x + 1;
            if (warehouse[p2.y][p2.x] == BOX) {
				pushingBox = 1;
				p3.x += 2;
            }
            break;
        }
    }

	// perform the move
	int movesFailed = 0;
	if (pushingBox) {
		printf("pushingBox\n");
		movesFailed += SwapTiles(warehouse, p2, p3);
	}
	if (movesFailed == 0) {
		movesFailed += SwapTiles(warehouse, worker, p2);
	}
	if (movesFailed != 0) {
		printf("%d moves failed!\n", movesFailed);
	}

    return 0;
}
