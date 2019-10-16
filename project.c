/**
 * ENGGEN131 Project - C Project - 2019
 * The Warehouse
 * 
 * AUTHOR: Matt Moran
 * USER: mmor330
 * ID #: 194231692
 */

#include "project.h"

/**
 * Macros for very simple math functions
 * MAX calculates the maximum of two numbers
 * MIN calculates the minimum of two numbers
 * ABS calculates the absolute value of a number
 */
#define MIN(A, B) (((A) < (B)) ? (A) : (B))
#define MAX(A, B) (((A) > (B)) ? (A) : (B))
#define ABS(A) ((A > 0) ? (A) : -(A))

// define Point struct in project.h
// if I submit this by accident then it will still work
#ifndef PROJECT_H_POINT
/**
 * Structure containing the position of a single point in the warehouse
 */
typedef struct { 
   int y; // the y position in the warehouse, from top to bottom
   int x; // the x position in the warehouse, from left to right
} Point;
#endif

/**
 * BubbleSort sorts an array of integers in ascending order.
 * 
 * @param  values[]  The array of integers to sort.
 * @param  length  The number of elements in `values`.
 * 
 * @algorithm  
 */
void BubbleSort(int values[], int length) {
    int swapped;

    do {
        // reset swapped flag
        swapped = 0;
        
        for (int i = 1; i < length; i++) {
            // if the pair is in the wrong order
            if (values[i - 1] > values[i]) {
                swapped = 1;

                // swap them
                int tmp = values[i - 1];
                values[i - 1] = values[i];
                values[i] = tmp;
            }
        }
        // after each loop the last element is guaranteed to be
        //   in the correct order (so we don't need to check it)
        length--;

    // loop until no changes are made (then sorting is complete)
    } while (swapped);
}

int GetWarehouseTile(int warehouse[WAREHOUSE_SIZE][WAREHOUSE_SIZE], Point p) {
    return warehouse[p.y][p.x];
}

char GetTileChar(int tile) {
    switch (tile) {
        case 0:
            return '_';
        case 1:
            return '#';
        case 2:
            return '*';
        case 3:
            return 'O';
        case 4:
            return 'o';
        case 5:
            return 'X';
        case 6:
            return 'x';
    }
    return '!';
}

int GetWarehouseChar(int warehouse[WAREHOUSE_SIZE][WAREHOUSE_SIZE], Point p) {
    return GetTileChar(warehouse[p.y][p.x]);
}

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

Point FindInWarehouse3(int warehouse[WAREHOUSE_SIZE][WAREHOUSE_SIZE], int tile1, int tile2, int tile3) {
    Point p = { -1, -1 };
    for (int y = 0; y < WAREHOUSE_SIZE; y++) {
        for (int x = 0; x < WAREHOUSE_SIZE; x++) {
            if (warehouse[y][x] == tile1 || warehouse[y][x] == tile2 || warehouse[y][x] == tile3) {
                p.y = y;
                p.x = x;
                return p;
            }
        }
    }
    return p;
}
Point FindInWarehouse2(int warehouse[WAREHOUSE_SIZE][WAREHOUSE_SIZE], int tile1, int tile2) {
    return FindInWarehouse3(warehouse, tile1, tile2, -1);
}
Point FindInWarehouse(int warehouse[WAREHOUSE_SIZE][WAREHOUSE_SIZE], int tile) {
    return FindInWarehouse3(warehouse, tile, -1, -1);
}

int TileIsBox(int tile) {
    return tile == BOX || tile == BOX_ON_TARGET;
}
int TileIsWorker(int tile) {
    return tile == WORKER || tile == WORKER_ON_TARGET;
}
int TileIsTarget(int tile) {
    return tile == TARGET || tile == BOX_ON_TARGET || tile == WORKER_ON_TARGET;
}

void AddTargetToTile(int *tile) {
    if (*tile == BOX) {
        *tile = BOX_ON_TARGET;
    }
    else if (*tile == WORKER) {
        *tile = WORKER_ON_TARGET;
    }
    else if (*tile == SPACE) {
        *tile = TARGET;
    }
}
void RemoveTargetFromTile(int *tile) {
    if (*tile == BOX_ON_TARGET) {
        *tile = BOX;
    }
    else if (*tile == WORKER_ON_TARGET) {
        *tile = WORKER;
    }
    else if (*tile == TARGET) {
        *tile = SPACE;
    }
}

int CountInWarehouse3(int warehouse[WAREHOUSE_SIZE][WAREHOUSE_SIZE], int tile1, int tile2, int tile3) {
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
int CountInWarehouse2(int warehouse[WAREHOUSE_SIZE][WAREHOUSE_SIZE], int tile1, int tile2) {
    return CountInWarehouse3(warehouse, tile1, tile2, -1);
}
int CountInWarehouse(int warehouse[WAREHOUSE_SIZE][WAREHOUSE_SIZE], int tile) {
    return CountInWarehouse3(warehouse, tile, -1, -1);
}

/*
 * Calculates the absolute time difference (in seconds) between two times.
 *
 * @param  minuteA, secondA  The first time, in minutes and seconds.
 * @param  minuteB, secondB  The second time, in minutes and seconds.
*/
int TimeWorked(int minuteA, int secondA, int minuteB, int secondB) {
    int timeA = minuteA * 60 + secondA;
    int timeB = minuteB * 60 + secondB;
    return ABS(timeA - timeB);
}

/*
 * Finds the highest prime number that is less than or equal to a maximum.
 *
 * @param  maximum  The maximum number that the prime number can be.
*/
int WarehouseAddress(int maximum) {
    // start at the maximum address and count down until we find a prime
    int i = maximum;

    // if `i` is even, it definitely isn't a prime so don't check it
    if (i % 2 == 0) i--;

    // check through all odd numbers, starting from the top
    for (; i > 0; i -= 2) {
        // return the highest prime number
        if (IsPrime(i)) return i;
    }

    // oh no, we didn't find a prime
    // (this is impossible as 3 is a prime number)
    return -1;
}

/*
 * Rotates every character to the left.
 * 
 * @param  words  The string to rotate.
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
 * Finds the lowest unique number in the array.
 * 
 * @param  values  The array to search.
 * @param  length  The number of elements in `values`.
*/
int WinningBid(int *values, int length) {
    // if there is only one bid then it wins by default
    if (length == 1) {
        return values[0];
    }

    // sort bids ascending
    BubbleSort(values, length);

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
 * Draws an ASCII box, with center marks.
 * 
 * @param  design  The string to draw the box into.
 * @param  width   The width of the box.
 * @param  height  The height of the box.
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
 * Draws a path through the warehouse from the worker to the box.
 * 
 * @param  warehouse  The 2D-array to draw the path through.
*/
void WorkerRoute(int warehouse[WAREHOUSE_SIZE][WAREHOUSE_SIZE]) {
    // find location of worker and box
    Point worker = FindInWarehouse(warehouse, 1);
    Point box = FindInWarehouse(warehouse, 2);

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
 * Move the worker to an adjacent tile, pushing a box if necessary.
 * 
 * @param  warehouse  The warehouse to move the worker in.
 * @param  move       The direction to move the worker in [w, a, s, d].
*/
int MakeMove(int warehouse[WAREHOUSE_SIZE][WAREHOUSE_SIZE], char move) {
    // find location of worker
    Point worker = FindInWarehouse2(warehouse, WORKER, WORKER_ON_TARGET);

    // these points hold the locations we will travel to
    // p2 is the location the worker will move to
    // p3 is the location the box will move to (if we are pushing a box)
    Point p1, p2, p3;
    p1 = p2 = p3 = worker;

    switch (move) {
        // up
        case 'w': {
            p2.y -= 1;
            p3.y -= 2;
            break;
        }
        // left
        case 'a': {
            p2.x -= 1;
            p3.x -= 2;
            break;
        }
        // down
        case 's': {
            p2.y += 1;
            p3.y += 2;
            break;
        }
        // right
        case 'd': {
            p2.x += 1;
            p3.x += 2;
            break;
        }
    }

    // figure out which tiles are targets
    int p1IsTarget = TileIsTarget(warehouse[p1.y][p1.x]);
    int p2IsTarget = TileIsTarget(warehouse[p2.y][p2.x]);
    int p3IsTarget = TileIsTarget(warehouse[p3.y][p3.x]);

    // remove target modifiers
    RemoveTargetFromTile(&warehouse[p1.y][p1.x]);
    RemoveTargetFromTile(&warehouse[p2.y][p2.x]);
    RemoveTargetFromTile(&warehouse[p3.y][p3.x]);

    // if we are pushing a box, move that first
    if (warehouse[p2.y][p2.x] == BOX) {
        // only move into an empty space
        if (warehouse[p3.y][p3.x] == SPACE) {
            warehouse[p3.y][p3.x] = BOX;
            warehouse[p2.y][p2.x] = WORKER;
            warehouse[p1.y][p1.x] = SPACE;
        }
    }
    // not pushing a box, only move into an empty space
    else if (warehouse[p2.y][p2.x] == SPACE) {
        warehouse[p2.y][p2.x] = WORKER;
        warehouse[p1.y][p1.x] = SPACE;
    }

    // add back target modifiers
    if (p1IsTarget) AddTargetToTile(&warehouse[p1.y][p1.x]);
    if (p2IsTarget) AddTargetToTile(&warehouse[p2.y][p2.x]);
    if (p3IsTarget) AddTargetToTile(&warehouse[p3.y][p3.x]);
    
    // finished if the worker is standing on a target and there are zero un-covered targets
    if (warehouse[p2.y][p2.x] == WORKER_ON_TARGET 
            && CountInWarehouse(warehouse, TARGET) == 0) {
        return 1;
    }

    return 0;
}
