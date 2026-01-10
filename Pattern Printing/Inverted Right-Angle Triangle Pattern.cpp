Problem Description
You need to generate an inverted right-angle triangle pattern using the asterisk symbol ('*'). Given an integer n, print the triangle such that:

The triangle has n rows.
The first row contains exactly n asterisks.
The second row contains n-1 asterisks.
This pattern continues until the final row, which will have just 1 asterisk.
Add a single space after each asterisk when printing.
Here's how this works:

Input: A single integer n representing the number of rows.

Output: A series of print statements that generate the triangle pattern.

Example:
If the input n is 4, your output should be:


* * * * 
* * * 
* * 
* 
Explanation:
Row 1 has 4 asterisks, each followed by a space.
Row 2 has 3 asterisks, each followed by a space.
Row 3 has 2 asterisks, each followed by a space.
Row 4 has 1 asterisk followed by a space.
Example 1:

Input:

n=2

Output:

* * 
* 
Explanation:An inverted right-angle triangle pattern of height 2.

Example 2:

Input:

n=3

Output:

* * * 
* * 
* 
Explanation:An inverted right-angle triangle pattern of height 3.

Example 3:

Input:

n=5

Output:

* * * * * 
* * * * 
* * * 
* * 
* 
Explanation:An inverted right-angle triangle pattern of height 5.



 Approach
Use a for loop to iterate from 0 to n-1, where the loop variable represents the current row index.
Inside the loop:
Print as many *s as (n - current row index) using another for loop.
After printing all the *s for the current row, move to a new line.
Repeat this process for all n rows to create the inverted triangle. 




  class Solution {
public:
    void printInvertedRightAngleTriangle(int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                cout << "* ";
            }
            cout << endl;
        }
    }
};
