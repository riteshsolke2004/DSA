188. Number Triangle Pattern

Problem Description
Given an integer n, your task is to print a triangle pattern of numbers. The triangle should consist of n rows, where each row i contains the number i, repeated i times.

The sequence starts from the number 1 at the top, and each subsequent row increments the number value by one, building up the triangle until row n.

Example
For an input n = 5, the printed output should be:

1
22
333
4444
55555
The first row contains the number 1, repeated once.
The second row contains the number 2, repeated twice, and so on, up to row n.
Example 1:

Input:
n=1
Output:
1
Explanation:A single row with 1.

Example 2:
Input:
n=2
Output:
1
22
Explanation:A triangle with two rows.

Example 3:
Input:
n=3
Output:
1
22
333
Explanation:A triangle with three rows.



  # Solution :- 
  class Solution {
public:
    void printNumberTriangle(int n) {

        for(int i=1; i<=n; i++){

            for(int j=1; j<=i;j++){
                cout << i ;
            }
            cout << endl ;
            
        }
    }
};
