/**
 * Name: Connor McGoey
 * Date: February 1, 2023
*/

/**
 * This program calculates the Fibonacci-like sequence of values N(i*20), where 0 <= i <= 25, using matrix multiplication and a O(n) time complexity.
*/

#include <iostream>
#include <cstdint>
#include <vector>
using namespace std;

/**
 * Constant representation of the first matrix to be used in n > 1. Called when the recursive call is needed in the first case.
*/
vector<vector<long long>> G1
{
    {2},
    {2}
};

/**
 * Helper function to print out the contents of a long long vector and then a newline.
 * 
 * Parameter num: the long long vector to be printed to console
 * return void: simply prints each number
*/
void printNumber(vector<long long> num) {
    for (int i : num) {
        cout << i;
    }
    cout << endl;
}

/**
 * Helper function to add long long vector representations of numbers together. Also removes leading 0's from the left side of the vector
 * 
 * Parameter vector1: the first vector in the summation
 * Parameter vector2: the second vector in the summation
 * return res: the resulting long long vector after the summation
*/
vector<long long> addVector(vector<long long> vector1, vector<long long> vector2){
    // Gather the length of the longest vector
    int largestLength = max(vector1.size(), vector2.size());

    /**
     * Create two new vectors newVector1 and newVector2 which hold the values of vector1 and vector2, but with added 0's if needed on the shorter
     * vector. If both vectors are the same length, then newVector1 and newVector2 are going to be identical.
    */
    vector<long long> newVector1(largestLength);
    fill(newVector1.end() - vector1.size(), newVector1.end(), 0);
    copy(vector1.begin(), vector1.end(), newVector1.end() - vector1.size());

    vector<long long> newVector2(largestLength);
    fill(newVector2.end() - vector2.size(), newVector2.end(), 0);
    copy(vector2.begin(), vector2.end(), newVector2.end() - vector2.size());
    
    // Create a new vector res which will hold the resulting vector after the summation
    vector<long long> res(largestLength);

    /**
     * Initialize two variables carryValue which holds the value of the carry of the summation of each digit, and end which holds the integer
     * representation of the last index of the res vector.
     * Upon each iteration, add the two values at the same index in both newVector1 and newVector2 as well as the value stored in the carry. The res vector
     * at the same index will store the value of digitValue modulo 10 as this will be the single digit remainder. The carryValue will hold the next value over.
    */
    long long carryValue = 0;
    int end = largestLength - 1;
    for (int i = end; i >= 0; i--) {
        long long digitValue = newVector1[i] + newVector2[i] + carryValue;
        carryValue = digitValue / 10;
        res[i] = digitValue % 10;
    }

    /**
     * If there is still a carry value after the summation of the two vectors, but no remaining indexes to traverse, push/insert the carryValue onto the res vector 
    */
    if (carryValue > 0) {
        res.insert(res.begin(), carryValue);
    }

    /**
     * If there are leading 0's on the left side of the summation, remove them one by one.
    */
    while (res.size() > 1 && res.front() == 0) {
        res.erase(res.begin());
    }

    return res;
}

/**
 * Function to multiple two vectors together, specifically designed for the vector {{1,1},{1,0}} as this is the vector that multiplies G(n-1) each time.
 * Because the values are 1, the matrix multiplication of the element at [0] is equal to the addition of of the two initial vectors, and the element at [1]
 * is equal to 1(matrix[0]) = matrix[0]. A temp value is used to store matrix[0] before it is changed by the addVector function call.
 * 
 * parameter matrix: the 2d matrix to be multiplied.
 * return matrix: the next Fibonacci-like sequence matrix Gn
*/
vector<vector<long long>> matrixMultiply(vector<vector<long long>> matrix) {
    vector<long long> temp = matrix[0];
    matrix[0] = addVector(matrix[0], matrix[1]);
    matrix[1] = temp;
    return matrix;
}

/**
 * Recursive Fibonacci-like function that takes in the current Fibonacci-like iteration 'n' that it is at, the target Fibonacci-like iteration 'target'
 * and the previous Fibonacci-like value 'matrix'.
 * 
 * parameter current: the current Fibonacci-like iteration
 * parameter target: the target Fibonacci-like iteration
 * parameter matrix: the 2d matrix representation of the previous Fibonacci-like matrix
 * return : the Fibonacci-like matrix (base case), or the recursive call of the next Fibonacci-like number
*/
vector<vector<long long>> fibLikeMatrix(int current, int target, vector<vector<long long>> matrix){
    vector<vector<long long>> res = matrixMultiply(matrix);
    current++;
    // If the current Fibonacci-like iteration is equal to the target, print it and return it. Otherwise recursively call itself 
    if (current == target) {
        printf("N(%d) = ", target);
        printNumber(res[0]);
        return res;
    } else {
        return fibLikeMatrix(current, target, res);
    }
}

/**
 * Base case Fibonacci-like sequence handler for n = 0, or n = 1. Otherwise, call the recursive, matrix multiplication of the Fibonacci-like sequence algorithm
 * 
 * parameter n: the 'target' Fibonacci-like sequence number
 * return: 2 if base case n, otherwise call the matrix recursive function and return 0.
*/
long long fibLikeMatrixBase(int n){
    if (n == 0 || n == 1) {
        // If n is one of the two base cases 0 or 1, print the base case 2 and return 2.
        printf("N(%d) = %lld \n",n, 2);
        return (long long)2;
    } else {
        fibLikeMatrix(1, n, G1);
        return 0;
    }
}

/**
 * Main function to call the Fibonacci-like recursive algorithm on values N(i*20), where 0 <= i <= 25.
*/
int main() {
    printf("7b Fibonacci-like sequence:\n");
    for (int i = 0; i <= 25; i++) {
        fibLikeMatrixBase(i*20);
    }
}
