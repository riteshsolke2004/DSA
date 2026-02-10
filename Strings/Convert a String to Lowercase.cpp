Convert a String to Lowercase

Problem Description
You are given a string s composed of both uppercase and lowercase English alphabetical characters. 
Your task is to transform all the characters in the string into lowercase. Create a function that accepts 
this string and returns a new string with all characters converted to lowercase.

Example
Example 1:
Input: "HeLLo WoRLd"
Output: "hello world"
Example 2:
Input: "PYTHON"
Output: "python"
Explanation:
Example 1: The input string 'HeLLo WoRLd' is transformed to 'hello world' by converting each uppercase character to its corresponding lowercase form.
Example 2: For 'PYTHON', every character in the string is converted to lowercase, resulting in 'python'.
Example 1:

Input:

Input: "Hello World"

Output:

hello world
Explanation:All uppercase letters are converted to lowercase.

Example 2:

Input:

Input: "TeStInG"

Output:

testing
Explanation:Mixed uppercase and lowercase letters are converted to all lowercase.

Example 3:

Input:

Input: "C++ Programming"

Output:

c++ programming
Explanation:Letters are converted to lowercase, but special characters remain unchanged.


  #Solution


class Solution {
public:
    string toLowerCase(string s) {
        for(int i=0; i<=s.length(); i++){

            if(s[i] >= 'A' && s[i] <= 'Z'){
                s[i] = s[i] - 'A' + 'a' ;
            }
        }
        return s ;
    }
};
