/* ENGGEN131 Project - C Project - 2019 */
/* The Warehouse */

/*
Program to test the functions defined in the "project.c" source file
*/
#include "project.h"

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

void MyTestFunction(int task) {
	// An example of code that you could use to test Task One.
	// You should write additional tests of your own
	switch (task) {
		case 1: {
			printf("\nTESTING TASK ONE:\n");
			printf("=================\n");
			printf("   TimeWorked(2, 0, 1, 0) = %d (should be 60)\n", TimeWorked(2, 0, 1, 0));
			printf("   TimeWorked(1, 0, 2, 0) = %d (should be 60)\n", TimeWorked(1, 0, 2, 0));
			printf("   TimeWorked(55, 11, 42, 12) = %d (should be 779)\n", TimeWorked(55, 11, 42, 12));
			printf("   TimeWorked(42, 12, 55, 11) = %d (should be 779)\n", TimeWorked(42, 12, 55, 11));
			printf("   TimeWorked(33, 33, 33, 33) = %d (should be 0)\n", TimeWorked(33, 33, 33, 33));
			break;
		}

		// An example of code that you could use to test Task Two.
		// You should write additional tests of your own
		case 2: {
			printf("\nTESTING TASK TWO:\n");
			printf("=================\n");
			printf("   WarehouseAddress(1000) = %d (should be 997)\n", WarehouseAddress(1000));
			printf("   WarehouseAddress(50) = %d (should be 47)\n", WarehouseAddress(50));
			printf("   WarehouseAddress(104393) = %d (should be 104383)\n", WarehouseAddress(104393));
			break;
		}

		// An example of code that you could use to test Task Three.
		// You should write additional tests of your own
		case 3: {
			printf("\nTESTING TASK THREE:\n");
			printf("=================\n");
			char message1[MAX_ARRAY_SIZE] = "Discount today only!";
			char message2[MAX_ARRAY_SIZE] = "Hurry, hurry, hurry...";
			char message3[MAX_ARRAY_SIZE] = "Good luck!";
			Advertise(message1);
			Advertise(message2);
			Advertise(message3);
			printf("   Advertise(Discount today only!) = \"%s\" (should be: \"iscount today only!D\")\n", message1);
			printf("   Advertise(Hurry, hurry, hurry...) = \"%s\" (should be: \"urry, hurry, hurry...H\")\n", message2);
			printf("   Advertise(Good luck!) = \"%s\" (should be: \"ood luck!G\")\n", message3);
			break;
		}

		// An example of code that you could use to test Task Four.
		// You should write additional tests of your own
		case 4: {
			printf("\nTESTING TASK FOUR:\n");
			printf("=================\n");
			int values1[MAX_ARRAY_SIZE] = {3, 7, 5, 6, 3, 4, 8, 4, 5, 8, 12, 11};
			int values2[MAX_ARRAY_SIZE] = {6, 17, 6, 6, 6, 6, 12, 12, 17, 10000};
			int values3[MAX_ARRAY_SIZE] = {5, 4, 3, 2, 1};
			int values4[MAX_ARRAY_SIZE] = {1};
			int values5[MAX_ARRAY_SIZE] = {5, 5};
			printf("   WinningBid({3, 7, 5, 6, 3, 4, 8, 4, 5, 8, 12, 11}) = %d (should be 6)\n", WinningBid(values1, 12));
			printf("   WinningBid({6, 17, 6, 6, 6, 6, 12, 12, 17, 10000}) = %d (should be 10000)\n", WinningBid(values2, 10));
			printf("   WinningBid({5, 4, 3, 2, 1}) = %d (should be 1)\n", WinningBid(values3, 5));
			printf("   WinningBid({1}) = %d (should be 1)\n", WinningBid(values4, 1));
			printf("   WinningBid({5, 5}) = %d (should be -1)\n", WinningBid(values5, 2));
			break;
		}

		// An example of code that you could use to test Task Five.
		// You should write additional tests of your own
		case 5: {
			printf("\nTESTING TASK FIVE:\n");
			printf("=================\n");
			char box1[MAX_ARRAY_SIZE] = {0};
			char box2[MAX_ARRAY_SIZE] = {0};
			char box3[MAX_ARRAY_SIZE] = {0};
			char box4[MAX_ARRAY_SIZE] = {0};
			char box5[MAX_ARRAY_SIZE] = {0};
			char box6[MAX_ARRAY_SIZE] = {0};
			BoxDesign(box1, 12, 5);
			BoxDesign(box2, 15, 15);
			BoxDesign(box3, 4, 4);
			BoxDesign(box4, 2, 2);
			BoxDesign(box5, 5, 2);
			BoxDesign(box6, 2, 5);
			printf("Box 1 = \n%s\n", box1);
			printf("Box 2 = \n%s\n", box2);
			printf("Box 3 = \n%s\n", box3);
			printf("Box 4 = \n%s\n", box4);
			printf("Box 5 = \n%s\n", box5);
			printf("Box 6 = \n%s\n", box6);
			printf("Checking string lengths = %d %d %d\n", strlen(box1), strlen(box2), strlen(box3));
			break;
		}

		// An example of code that you could use to test Task Six.
		// You should write additional tests of your own
		case 6: {
			printf("\nTESTING TASK SIX:\n");
			printf("=================\n");
			int i, j;
			int warehouse1[WAREHOUSE_SIZE][WAREHOUSE_SIZE] = {
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 2, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			};
			int warehouse2[WAREHOUSE_SIZE][WAREHOUSE_SIZE] = {
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 2}
			};
			int warehouse3[WAREHOUSE_SIZE][WAREHOUSE_SIZE] = {
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 2, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			};
			int warehouse4[WAREHOUSE_SIZE][WAREHOUSE_SIZE] = {
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 2, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			};
			int warehouse5[WAREHOUSE_SIZE][WAREHOUSE_SIZE] = {
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 1, 0, 0, 2, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			};

			WorkerRoute(warehouse1);
			WorkerRoute(warehouse2);
			WorkerRoute(warehouse3);
			WorkerRoute(warehouse4);
			WorkerRoute(warehouse5);

			printf("Worker route 1: \n");
			for (i = 0; i < WAREHOUSE_SIZE; i++) {
				for (j = 0; j < WAREHOUSE_SIZE; j++) {
					printf("%d", warehouse1[i][j]);
				}
				printf("\n");
			}

			printf("\nWorker route 2: \n");
			for (i = 0; i < WAREHOUSE_SIZE; i++) {
				for (j = 0; j < WAREHOUSE_SIZE; j++) {
					printf("%d", warehouse2[i][j]);
				}
				printf("\n");
			}

			printf("Worker route 3: \n");
			for (i = 0; i < WAREHOUSE_SIZE; i++) {
				for (j = 0; j < WAREHOUSE_SIZE; j++) {
					printf("%d", warehouse3[i][j]);
				}
				printf("\n");
			}
			
			printf("Worker route 4: \n");
			for (i = 0; i < WAREHOUSE_SIZE; i++) {
				for (j = 0; j < WAREHOUSE_SIZE; j++) {
					printf("%d", warehouse4[i][j]);
				}
				printf("\n");
			}
			
			printf("Worker route 5: \n");
			for (i = 0; i < WAREHOUSE_SIZE; i++) {
				for (j = 0; j < WAREHOUSE_SIZE; j++) {
					printf("%d", warehouse5[i][j]);
				}
				printf("\n");
			}
			break;
		}

		case 11: {
			printf("\nTESTING SwapTiles:\n");
			printf("=================\n");
			
			int warehouse[10][10] = {
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
				{1, 1, 1, 0, 0, 0, 1, 1, 1, 1},
				{1, 2, 5, 3, 0, 0, 1, 1, 1, 1},
				{1, 1, 1, 0, 3, 2, 1, 1, 1, 1},
				{1, 2, 1, 1, 3, 0, 1, 1, 1, 1},
				{1, 0, 1, 0, 2, 0, 1, 1, 1, 1},
				{1, 3, 0, 4, 3, 3, 2, 1, 1, 1},
				{1, 2, 0, 0, 2, 0, 0, 1, 1, 1},
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			};
			Point p0 = { .x = 3, .y = 5 }; // 0 = SPACE
			Point p1 = { .x = 0, .y = 2 }; // 1 = WALL
			Point p2 = { .x = 1, .y = 2 }; // 2 = TARGET
			Point p3 = { .x = 3, .y = 2 }; // 3 = BOX
			Point p4 = { .x = 3, .y = 6 }; // 4 = BOX ON TARGET
			Point p5 = { .x = 2, .y = 2 }; // 5 = WORKER

			// swap _#
			printf("  SwapTiles(%c, %c) = ", GetWarehouseChar(warehouse, p0), GetWarehouseChar(warehouse, p1));
			SwapTiles(warehouse, p0, p1);
			printf("(%c, %c)\n", GetWarehouseChar(warehouse, p0), GetWarehouseChar(warehouse, p1));
			SwapTiles(warehouse, p0, p1);

			// swap *O
			printf("  SwapTiles(%c, %c) = ", GetWarehouseChar(warehouse, p2), GetWarehouseChar(warehouse, p3));
			SwapTiles(warehouse, p2, p3);
			printf("(%c, %c)\n", GetWarehouseChar(warehouse, p2), GetWarehouseChar(warehouse, p3));
			SwapTiles(warehouse, p2, p3);

			// swap XO
			printf("  SwapTiles(%c, %c) = ", GetWarehouseChar(warehouse, p5), GetWarehouseChar(warehouse, p3));
			SwapTiles(warehouse, p5, p3);
			printf("(%c, %c)\n", GetWarehouseChar(warehouse, p5), GetWarehouseChar(warehouse, p3));
			SwapTiles(warehouse, p5, p3);

			// swap Xo
			printf("  SwapTiles(%c, %c) = ", GetWarehouseChar(warehouse, p5), GetWarehouseChar(warehouse, p4));
			SwapTiles(warehouse, p5, p4);
			printf("(%c, %c)\n", GetWarehouseChar(warehouse, p5), GetWarehouseChar(warehouse, p4));
			SwapTiles(warehouse, p5, p4);

			printf("\n");
			break;
		}
	}
}

//********************************************************************
//********************************************************************
// REMEMBER:
// FOR THE PROJECT, YOU ARE ONLY SUBMITTING THE MakeMove() FUNCTION
// ABOVE (AND ANY HELPER FUNCTIONS THAT YOU HAVE DEFINED).  REMEMBER
// TO PLACE THE MakeMove() FUNCTION (AND ANY HELPER FUNCTIONS) INTO
// THE project.c FILE BEFORE SUBMISSION.
//********************************************************************
//********************************************************************

/* Function prototype declarations */
void PrintWarehouse(int warehouse[10][10]);
char GetMove(void);

// Print a welcome message, and enter the main game loop.
int main(void)
{
	/* An example warehouses for testing Task 7 */
	int warehouse7[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 5, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};

	/* An example warehouses for testing Task 8 */
	int warehouse8[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 5, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 3, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};

	/* An example warehouses for testing Task 9 */
	int warehouse9[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 5, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 3, 3, 3, 3, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};

	/* An example warehouses for testing Task 10 */
	int warehouse10[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 0, 0, 0, 1, 1, 1, 1},
		{1, 2, 5, 3, 0, 0, 1, 1, 1, 1},
		{1, 1, 1, 0, 3, 2, 1, 1, 1, 1},
		{1, 2, 1, 1, 3, 0, 1, 1, 1, 1},
		{1, 0, 1, 0, 2, 0, 1, 1, 1, 1},
		{1, 3, 0, 4, 3, 3, 2, 1, 1, 1},
		{1, 2, 0, 0, 2, 0, 0, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};

	/* Optional level for Task 10 */
	/*	int warehouse10[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
		{1, 1, 1, 0, 3, 1, 0, 0, 1, 1},
		{1, 2, 0, 0, 2, 2, 0, 0, 0, 1},
		{1, 1, 1, 0, 1, 0, 3, 3, 3, 1},
		{1, 0, 0, 3, 0, 0, 1, 5, 2, 1},
		{1, 2, 0, 0, 0, 1, 1, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	}; */
	int task = -1;
	int i, j;

	// The main warehouse to be used in the game
	int warehouse[10][10];

	printf("ENGGEN131 2019 - C Project...\n");
	printf(" _____ _            _    _                _                          \n");
	printf("|_   _| |          | |  | |              | |                         \n");
	printf("  | | | |__   ___  | |  | | __ _ _ __ ___| |__   ___  _   _ ___  ___ \n");
	printf("  | | | \'_ \\ / _ \\ | |/\\| |/ _` | \'__/ _ \\ \'_ \\ / _ \\| | | / __|/ _ \\\n");
	printf("  | | | | | |  __/ \\  /\\  / (_| | | |  __/ | | | (_) | |_| \\__ \\  __/\n");
	printf("  \\_/ |_| |_|\\___|  \\/  \\/ \\__,_|_|  \\___|_| |_|\\___/ \\__,_|___/\\___|\n");
	printf("\nEnter the number of the task that you would like to test:\n\n");
	printf("  1 - 6  = this will execute the code in MyTestFunction()\n");
	printf("  7 - 10 = this will play the Warehouse game\n");
	while (task < 1) {
		printf("\nWhat task would you like to test (1, 2, 3, 4, 5, 6, 7, 8, 9 or 10)? ");
		scanf("%d", &task);
	}

	printf("\n\nOK, testing task %d!\nGood luck!\n\n", task);

	if (task < 7 || task > 10) {
		MyTestFunction(task);
	} else {
		printf("\nThe Warehouse game!");
		printf("\nUse the keys 'w', 'a', 's', 'd' to move the worker (X)\n");
		printf("Push the boxes (O) onto the targets (*) to complete your shift!\n");

		for (i = 0; i < 10; i++) {
			for (j = 0; j < 10; j++) {
				if (task == 7)
					warehouse[i][j] = warehouse7[i][j];
				else if (task == 8)
					warehouse[i][j] = warehouse8[i][j];
				else if (task == 9)
					warehouse[i][j] = warehouse9[i][j];
				else
					warehouse[i][j] = warehouse10[i][j];
			}
		}

		// The main game loop - continue to make moves until the game is over
		int gameOver = 0;
		PrintWarehouse(warehouse);
		while (!gameOver) {
			gameOver = MakeMove(warehouse, GetMove());
			PrintWarehouse(warehouse);
			if (gameOver) {
				printf("\nCongratulations! \nYour work here is done!\n\n");
			}
		}
	}

	return 0;
}

/* A simple function for displaying the cave. */
void PrintWarehouse(int warehouse[10][10])
{
	int i, j;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (warehouse[i][j] == 0) {
				printf(" ");
			} else if (warehouse[i][j] == 1) {
				printf("#");
			} else if (warehouse[i][j] == 2) {
				printf("*");
			} else if (warehouse[i][j] == 3) {
				printf("O");
			} else if (warehouse[i][j] == 4) {
				printf("O");
			} else if (warehouse[i][j] == 5) {
				printf("X");
			} else if (warehouse[i][j] == 6) {
				printf("X");
			}
		}
		printf("\n");
	}
}

/* The GetMove() function returns the entered character.  Invalid
   characters are ignored */
char GetMove(void)
{
	char move;
	printf("\nEnter move: ");
	// Ignore any characters that are invalid
	scanf("%c", &move);
	while ((move != 'w') && (move != 'a') && (move != 's') && (move != 'd')) {
		scanf("%c", &move);
	}
	return move;
}
