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
    bool isAnagram(string s, string t) {

        if(s.length() != t.length()){
            return false;
        }

        int count[26] = {0};
        for(int i=0; i<s.length(); i++){
            count[s[i] - 'a']++;
        }

        for(int i=0; i<t.length(); i++){
            count[t[i] - 'a']--;
            if( count[t[i] - 'a'] < 0){
                return false ;
            }
        }

        return true;
        
    }
};
