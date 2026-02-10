/*242. Valid Anagram
Solved
Easy
Topics
premium lock icon
Companies
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false
  */

class Solution {
public:
    bool isAnagram(const string& s, const string& t) {
        // Implement logic to check if `t` is an anagram of `s`
        int arr[1000] = {0} ;
        for(int i=0; i<s.length(); i++){
            char ch = s[i] ;
            arr[ch] ++ ;
        } 

        for(int i=0; i<t.length(); i++ ){
            char ch = t[i] ;
            arr[ch] -- ;
        }

        for(int i=0; i<1000; i++){
            if(arr[i] != 0){
                return false ;
            }
        }
        return true ;
    }
};
