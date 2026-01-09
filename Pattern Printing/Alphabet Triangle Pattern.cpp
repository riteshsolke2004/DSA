190. Alphabet Triangle Pattern

Problem Description
You are tasked with generating an alphabetical triangle pattern for a given positive integer n. The pattern will be structured such that it starts with the letter 'A' at the top,
and for each subsequent row, one more letter is added, continuing sequentially through the alphabet. Specifically, the i-th row will contain the first i letters of the alphabet.

The objective is to create this pattern based on the input value n, where n represents the number of rows in the triangle.

Example
For instance, if the input n is 5, the expected output should be:

A
AB
ABC
ABCD
ABCDE
This illustrates a triangle with 5 rows, where each row begins with the letter 'A' and extends through the i-th letter of the alphabet for that row number, where i is the row index starting from 1.

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
A
AB
Explanation:A triangle with two rows.

Example 3:
Input:
n=3
Output:
A
AB
ABC
Explanation:A triangle with three rows.


  # Solution 
  class Solution {
public:
    void printAlphabetTriangle(int n) {

        for(int i=1; i<=n; i++){

            for(char ch = 'A'; ch <'A'+ i; ch++){
                cout << ch ;
                
            }
            cout << endl ;
            
        }
    }
};
