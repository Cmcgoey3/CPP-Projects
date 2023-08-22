/**
 * Name: Connor McGoey
 * Date: February 1, 2023
*/

/**
 * This program calculates the Fibonacci-like sequence of values N(i*5), where 0 <= i <= 10, pure recursion and a O(2^n) time complexity.
*/

#include <iostream>
#include <cstdint>
using namespace std;

/**
 * Recursive function to calculate the Fibonacci-like sequence number corresponding to 'num'.
 * 
 * parameter num: long long representation of the goal Fibonacci-like sequence number
 * return: the Fibonacci-like sequence number of num.
*/
long long fibRecursiveLong(long long num) {
    if ((num == 0) || (num == 1)) {
        return (long long)2;
    }
    else {
        return fibRecursiveLong(num - 1) + fibRecursiveLong(num - 2);
    }
}

/**
 * Main function to find and print the Fibonacci-like numbers of values N(i*5), where 0 <= i <= 10.
*/
int main() {
    printf("7a Fibonacci-like sequence:\n");
    for (int i = 0; i <= 10; i++) {
        long long result = fibRecursiveLong(i*5);
        printf("N(%d) = %lld \n",i*5, result);
    }
}
