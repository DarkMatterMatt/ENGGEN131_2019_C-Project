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
    // special case: the only even prime number is two
    if (maximum == 3) {
        return 2;
    }

    // start below the maximum address and count down until we find a prime
    int i = maximum - 1;

    // if `i` is even, it definitely isn't a prime so don't check it
    if (i % 2 == 0) i--;

    // check through all odd numbers, starting from the top
    for (; i > 0; i -= 2) {
        // return the highest prime number
        if (IsPrime(i)) {
            return i;
        }
    }

    // oh no, we didn't find a prime
    // (this is impossible as 2 is a prime number)
    return -1;
}

int main(void) {
    // this is the number that WarehouseAddress address should return
    int highestPrime = 2;

    // loop through the first million numbers
    for (int num = 3; num < 1e6; num++) {
        // check that WarehouseAddress is returning the correct address
        if (WarehouseAddress(num) != highestPrime) {
            printf("WarehouseAddress(%d) = %d. Expected %d.\n", num, WarehouseAddress(num), highestPrime);
        }
        // if there's a new highest prime then store it
        if (IsPrime(num)) {
            highestPrime = num;
        }
    }

    return 0;
}
