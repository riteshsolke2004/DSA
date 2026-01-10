Inverted Alphabet Triangle Pattern

Problem Description
You are required to generate an inverted triangle pattern using the English alphabet, based on a specified integer input n.
This input determines the size of the triangle.
The triangle pattern starts with the letter 'A' and extends to the letter corresponding to the n-th position in the alphabet. 
The first row of the pattern includes letters from 'A' to the n-th letter, the second row includes up to the n-1-th letter, 
and this reduction continues until only the letter 'A' is printed on the last row.

Example
For n = 5, the expected output is:

ABCDE
ABCD
ABC
AB
A
Here, each row in the resulting pattern decreases by one letter until only 'A' remains in the final row.
This task involves generating and printing this pattern based on the provided input value n.

Example 1:
Input:
n=1
Output:
A
Explanation:A single row with 'A'.

Example 2:
Input:
n=2
Output:

AB
A
Explanation:An inverted triangle with two rows.

Example 3:
Input:
n=3
Output:
ABC
AB
A
Explanation:An inverted triangle with three rows.

  Approach
Initialize Loop for Rows:

Start a loop with an index i from n down to 1. This index also defines the number of letters printed in each row.
Initialize Inner Loop for Characters:

For each row, initiate another loop starting from the character 'A' and continuing up to the i-th character in the alphabet ('A' + i - 1).
Print each character within this range for the current row.
Printing:

After finishing printing characters for a row, move to a new line to begin the next row.
Output:

The output for each function call is structured such that it generates an inverted triangle pattern of letters for any given integer n.

  
  # Solution :- 
  
class Solution {
public:
    void printInvertedAlphabetTriangle(int n) {
        
        for(int row = n ; row >=1 ; row--){

            for(char ch = 'A'; ch < 'A' + row ; ch++){

                cout << ch ;
            }
            cout << endl ;
        }
    }
};
