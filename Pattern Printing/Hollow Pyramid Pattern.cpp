Hollow Pyramid Pattern
Given an integer n, you are required to generate a pattern that displays a hollow pyramid with height n, using the character *. The pyramid should have the following properties:

The pyramid has n levels, and each level is a row in the pattern.
The first and last rows contain * in a sequential manner, forming the outline of the pyramid.
Every other row contains stars (*) only at the beginning and at the end, leaving the interior hollow.
Each row is centered such that the base of the pyramid is aligned.
Example:
For example, if n = 5, the pattern would be:


    *    
   * *   
  *   *  
 *     * 
*********
Where each line is centered according to the base which has 2*n - 1 characters including spaces.

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
Explanation:A hollow pyramid with two rows.

Example 3:

Input:

n=3

Output:

    * 
  *   * 
* * * * * 
Explanation:A hollow pyramid with three rows.


  Approach
Pattern Structure: The problem involves creating a pyramid with n levels. Each level must be appropriately aligned.
Iterate Over Levels: Use a loop from 0 to n-1 to iterate over each level of the pyramid.
Leading Spaces: For each level i, print n-i-1 leading spaces to ensure the pyramid remains centered.
Print Row Content:
Use another loop to print 2*i + 1 characters for each row.
For the topmost and bottom row (level 0 and n-1), fill the row entirely with *.
For the intermediate levels, print * at the start and end, and spaces in between.
Output: Print each row to form the complete pattern.



  class Solution {
public:
    void printHollowPyramid(int n) {
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n - i - 1; j++) {
                cout << "  ";
            }

            for (int k = 0; k < 2 * i + 1; k++) {
                if (k == 0 || k == 2 * i || i == n - 1) {
                    cout << "* ";
                } else {
                    cout << "  ";
                }
            }
            cout << endl;
        }
    }
};
  
