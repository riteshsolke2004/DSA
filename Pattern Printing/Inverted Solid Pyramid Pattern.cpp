Inverted Solid Pyramid Pattern
Write a function that prints an inverted solid pyramid pattern using the character '*'. The height of the pyramid is determined by an integer n provided as input.

The pattern should be displayed such that:

The first row contains 2n - 1 stars.
The second row contains 2n - 3 stars.
The third row contains 2n - 5 stars, continuing this progression until the last row, which contains a single star.
Each row should be centered, meaning that leading spaces are added appropriately such that the stars form a symmetrical pattern.

Example
Consider n = 3:


*****
 ***
  *
Explanation:

The first row has 5 stars (2*3 - 1) and no leading spaces.
The second row has 3 stars and 1 leading space.
The third row contains 1 star with 2 leading spaces.
Your task is to implement the function such that it generates the correct pattern for any valid value of n.

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

* * * 
  * 
Explanation:An inverted solid pyramid with two rows.

Example 3:

Input:

n=3

Output:

* * * * * 
  * * * 
    * 
Explanation:An inverted solid pyramid with three rows.


  Approach
Initialization:

We need to handle the number of rows n, which determines the height of the pyramid.
For each row i from 0 to n-1, we compute two main components: leading spaces and the count of stars.
Calculate Leading Spaces:

For the row at index i, the number of leading spaces is simply i.
Calculate Number of Stars:

The number of stars in row i is given by the formula: 2 * (n - i) - 1.
Pattern Construction:

For each row, print the calculated number of spaces followed by the calculated number of stars.
Each row results in a symmetrical pattern, progressively shifting rightwards due to increasing leading spaces.
Output:

For each row, append the results to form the pyramid. Use endl in C++ or System.out.println() in Java for line breaks between rows.


class Solution {
public:
    void printInvertedSolidPyramid(int n) {
        for (int i = 0; i < n; i++) {
            // Print leading spaces
            for (int j = 0; j < 2*i; j++) {
                cout << " ";
            }
            // Print '*' characters
            for (int k = 0; k < 2 * (n - i) - 1; k++) {
                cout << "* ";
            }
            cout << endl;
        }
    }
};
