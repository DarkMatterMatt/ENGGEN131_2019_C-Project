#include <stdio.h>

/*
 * Determines if the given number is a prime number.
 *
 * @param  num  The number to check.
*/
int IsPrime(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

/*
 * Finds the highest prime number that is less than or equal to a maximum.
 *
 * @param  maximum  The maximum number that the prime number can be.
*/
int WarehouseAddress(int maximum) {
    return -1;
}

int main(void) {
    int highestPrime = 2;

    for (int num = 3; num < 1e2; num++) {
        if (WarehouseAddress(num) != highestPrime) {
            printf("WarehouseAddress(%d) = %d. Expected %d.\n", num, WarehouseAddress(num), highestPrime);
        }
        if (IsPrime(num)) {
            highestPrime = num;
        }
    }

    return 0;
}