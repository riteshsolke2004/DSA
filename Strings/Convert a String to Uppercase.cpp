 Convert a String to Uppercase

In this task, you need to create a function that transforms all lowercase letters in a given string to their corresponding uppercase counterparts.
The function should only process ASCII characters, ensuring that digits, punctuation marks, and other non-lowercase characters remain unaffected. 
The goal is to iterate through each character of the string and convert uppercase letters wherever necessary.

Example
Input:
s = "Hello, World!"

Output:
"HELLO, WORLD!"

Explanation:
In the given string, all lowercase letters 'e', 'l', 'o', 'r' are converted to their corresponding 
uppercase letters 'E', 'L', 'O', 'R'. All other characters, including punctuation and spaces, remain unchanged.

Example 1:

Input:

Input: "hello world"

Output:

HELLO WORLD
Explanation:All lowercase letters are converted to uppercase.

Example 2:

Input:

Input: "TeStInG"

Output:

TESTING
Explanation:Mixed uppercase and lowercase letters are converted to all uppercase.

Example 3:

Input:

Input: "c++ programming"

Output:

C++ PROGRAMMING
Explanation:Letters are converted to uppercase, but special characters remain unchanged.


  # Solution 
  class Solution {
public:
    string toUpperCase(string s) {
        // Your code goes here
        for(int i=0; i<=s.length(); i++){

            if(s[i] >= 'a' && s[i] <= 'z'){
                s[i] = s[i] - 'a' + 'A' ;
            }
        }
        return s ;
    }
};
