Check if a String is a Palindrome

Given a string s, your task is to determine whether the string is a palindrome or not. A string is considered 
a palindrome if it reads the same forwards and backwards.

For instance, the string "racecar" is a palindrome because it reads the same from left to right and right to left. 
Conversely, the string "hello" is not a palindrome due to the difference in the sequence when read in reverse.

Example:
Example 1:
Input:


s = "madam"
Output:


true
Explanation: The string "madam" reads identically forwards and backwards.

Example 2:
Input:


s = "hello"
Output:


false
Explanation: The string "hello" does not have the same sequence when read backwards.

Note:
The palindrome check is case-sensitive, meaning "Madam" and "madam" are distinct; only strings with 
identical sequences in both directions when case is considered will qualify as palindromes.
Example 1:

Input:

Input: "racecar"

Output:

true
Explanation:The string "racecar" reads the same forward and backward.

Example 2:

Input:

Input: "level"

Output:

true
Explanation:The string "level" is a palindrome.

Example 3:

Input:

Input: "hello"

Output:

false
Explanation:The string "hello" does not read the same forward and backward.


  # Solution 

  bool isPalindrome(string s) {

    int start = 0 ;
    int end = s.length() - 1 ;

    while(start <= end){

        if(s[start] != s[end]){
            return false ;
            
        }
        start++ ;
        end-- ;
    }
    return true;
}
