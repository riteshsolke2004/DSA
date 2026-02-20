Solid Pyramid Pattern
In this problem, you are required to generate a solid pyramid pattern using asterisk (*) characters. Given an integer n, the task is to print a pyramid with n rows. Each row of the pyramid contains a specific number of asterisks that form a symmetrical pattern, centered to give the overall shape of a pyramid.

The number of asterisks starts at 1 in the first row and increases by 2 in each subsequent row, aligning the pyramid symmetrically. This means the second row will have 3 asterisks, the third will have 5, and so on.

Example
For n = 4, the output should be:

 
   *
  ***
 *****
*******
Here, the pyramid is built with 4 rows, where each row is centered by adjusting the spaces on either side of the asterisks.

Your task is to write a function that generates this pattern for any valid input of n within the specified constraints.

Example 1:

Input:

n=1

Output:

* 
Explanation:A single row pyramid with one '*' for n=1.

Example 2:

Input:

n=2

Output:

  * 
* * * 
Explanation:A solid pyramid with two rows.

Example 3:

Input:

n=3

Output:

    * 
  * * * 
* * * * * 
Explanation:A solid pyramid with three rows.



Approach
Use a for loop to iterate from 0 to (n-1), where the loop variable represents the current row.
For each row:
Print (n - current row number - 1) spaces using a loop.
Print (2 * current row number + 1) * characters using another loop.
Move to the next line after printing all characters for the current row.
Repeat this process for all rows to form the pyramid.

  

  # solution 

  class Solution {
public:
    void printSolidPyramid(int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                cout << "  ";
            }
            for (int k = 0; k < 2 * i + 1; k++) {
                cout << "* ";
            }
            cout << endl;
        }
    }
};
