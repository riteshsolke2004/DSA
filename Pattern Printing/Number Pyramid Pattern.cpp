Number Pyramid Pattern
Your task is to generate a pyramid-shaped pattern of numbers based on a given integer n. The pyramid will contain n rows,
and each row i will have numbers starting from 1 up to i. The numbers in each row should be centrally aligned to form a pyramid shape.

Example:
If n is 4, the output should be:

      1
    1 2
  1 2 3
1 2 3 4
Details:
The pyramid is built from a series of rows with each subsequent row having increasing numbers.
Align each row in a centered format, filling the space to the left with necessary spaces to maintain the pyramid structure.
Example 1:

Input:
n = 1
Output:
1
Explanation:Single row with one number

Example 2:
Input:
n = 2
Output:
 1 
1 2 
Explanation:Two rows showing progression of numbers

Example 3:
Input:
n = 3

Output:

  1 
 1 2 
1 2 3 
Explanation:Three rows with proper spacing


Approach
1. Iterating Through Rows: Use a loop to iterate from the first row up to row n. Each iteration corresponds to a specific row i.
2. Center Alignment with Leading Spaces: For central alignment, print (n - i) spaces before the numbers for row i. 
   This ensures that shorter rows (those with fewer numbers) are aligned to the center relative to longer rows.
3. Number Printing: After printing the necessary leading spaces, print numbers from 1 to i for the current row. 
   Add a space between numbers to maintain visual clarity.
4. Finalize Each Row: After printing all numbers for a row, move to the following line (this is achieved by printing a newline character).
This approach, through managing the number of leading spaces and iterating over numbers to print through loops, ensures the correct pyramid formation.


# Solution 
class Solution {
public:
    void printNumberPyramid(int n) {

        for(int row=1; row<=n; row++){

            for(int col=1; col<=(n-row); col++){
                cout << " " ;
            }

            for(int count=1; count<=row; count++){
                cout << count<< " " ;
            }

            cout << endl ;
        }


    }
};



