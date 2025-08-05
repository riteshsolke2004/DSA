467. Compute Factorial of a Number Recursively
Write a function that computes the factorial of a given non-negative integer n using a recursive approach.
Factorial of a non-negative integer n is defined as the product of all positive integers less than or equal to n. It is denoted by n!.

For example:

4! = 4 * 3 * 2 * 1 = 24
0! = 1 (by definition)
The task is to implement a function that takes an integer n and returns its factorial.

Example
Input:
n = 5
Output: 120

Explanation:
5! = 5 * 4 * 3 * 2 * 1 = 120.
Input:
n = 0
Output: 1

Explanation:
0! = 1 (by definition).
Example 1:
Input:
Input: n = 0
Output: 1
Explanation:0! = 1 by definition.
Example 2:
Input: n = 1
Output: 1
Explanation:1! = 1.
    
Example 3:
Input: n = 2
Output: 2
Explanation:2! = 2 × 1 = 2.

    
#include <iostream>
using namespace std ;

int factorial(int n) {
    
    if(n == 0){
        return 1 ;
    }
    int fact = factorial(n-1) ;
    return fact * n ;
}

int main() {
    
    int result = factorial(5) ;
    cout << "fact is :- "<< result ;
    return 0 ;
}
