118. Reverse String [Using Recursion]

Given an array s of characters, your task is to reverse the array in place using a recursive approach. 
You should modify the input array s directly, rearranging its elements so that they appear in reverse order.

The rearrangement must be done via a recursive method. Importantly, you are not allowed to use any new data 
structures or allocate space for another array, meaning the array must be reversed in place.

Example:
Input:
s = ['h', 'e', 'l', 'l', 'o']
Output: ['o', 'l', 'l', 'e', 'h']

Example 1:

Input: s = [h,e,l,l,o]

Output: [o,l,l,e,h]
Explanation:The input string hello is reversed. Each character's position is swapped such that the first character becomes the last,
and the last becomes the first, continuing this process until all characters are reversed. The result is olleh, represented as [o,l,l,e,h] in list format.

Example 2:

Input:
s = [a,b,c,d]
Output:
[d,c,b,a]
Explanation:The input string hello is reversed. Each character's position is swapped such that the first character becomes the last,
and the last becomes the first, continuing this process until all characters are reversed. The result is olleh, represented as [d,c,b,a] in list format.

Example 3:

Input:
s = [x,y,z]
Output:

[z,y,x]
Explanation:The input string hello is reversed. Each character's position is swapped such that the first character becomes the last, 
  and the last becomes the first, continuing this process until all characters are reversed. The result is olleh, represented as [z,y,x] in list format.



#Solution :- 

class Solution {

private:
    void helperfunc(vector<char>& s,int left, int right){

        if(left > right) return;

        char temp = s[left] ;
        s[left] = s[right] ;
        s[right] = temp ;

        helperfunc(s, left+1 , right-1) ;

    }

public:
     vector<char> reverseString(vector<char>& s) {
        helperfunc(s,0 , s.size() - 1 ) ;
        return s ;
    
    }
};
