Hollow Square Pattern
Create a program that prints a hollow square pattern using the * character.

Given an integer n, which specifies the size of the square, the pattern should have dimensions of n x n (n rows and n columns):

The first and last rows should be filled entirely with *.
The rows in-between should start and end with a *, and the space between these stars should be filled with spaces.
Example
For n = 5, the output pattern should look like:


*****
*   *
*   *
*   *
*****
This indicates the pattern's borders have *, and the inner rows, except for the borders, contain spaces between bordering stars. Use nested loops to generate each line of the pattern and remember to use conditional statements to determine when to print * or a space.

Example 1:

Input:

n=3

Output:

* * * 
*   * 
* * * 
Explanation:Hollow square pattern of size 3.

Example 2:

Input:

n=5

Output:

* * * * * 
*       * 
*       * 
*       * 
* * * * * 
Explanation:Hollow square pattern of size 5.

Example 3:

Input:

n=10

Output:

* * * * * * * * * * 
*                 * 
*                 * 
*                 * 
*                 * 
*                 * 
*                 * 
*                 * 
*                 * 
* * * * * * * * * * 
Explanation:Hollow square pattern of size 10.

Approach
Use a for loop to iterate through the rows of the square from 0 to n-1.
Inside the loop:
If the row is the first (i == 0) or the last (i == n-1), print * for all n columns.
For the middle rows (1 ≤ i ≤ n-2):
Print * for the first column (j == 0) and last column (j == n-1).
Print spaces for all other columns (1 ≤ j ≤ n-2).
After printing each row, move to a new line to maintain the square structure.

  
# Solution :
class Solution {
public:
    void printHollowSquare(int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                    cout << "* ";
                } else {

                    cout << "  ";
                }
            }
            cout << endl;
        }
    }
};
