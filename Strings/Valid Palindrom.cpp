/* 249. Valid Palindrome

   Given a string s, the task is to determine whether the string is a valid palindrome. A palindromic string reads the same backward as forward when ignoring cases and removing all non-alphanumeric characters.

   Example 1:

   Input: "A man, a plan, a canal: Panama"
   Output: true
   Explanation: After removing non-alphanumeric characters and converting to lowercase, the string becomes "amanaplanacanalpanama", which is a palindrome.
   Example 2:

   Input: "race a car"
   Output: false
   Explanation: After processing, the string becomes "raceacar", which is not a palindrome.
*/

class Solution {
public:
  bool validcharacter(char ch) {
    if (ch >= 'a' && ch <= 'z') {
      return true;
    }
    if (ch >= 'A' && ch <= 'Z') {
      return true;
    }
    if (ch >= '0' && ch <= '9') {
      return true;
    }
    return false;
  }
  string alphanumeric(string &s) {
    string str = "";
    for (int i = 0; i < s.length(); i++) {
      char ch = s[i];
      if (validcharacter(ch)) {
        if (ch >= 'A' && ch <= 'Z') {
          ch = ch - 'A' + 'a';
        }
        str.push_back(ch);
      }
    }
    return str;
  }
  bool isPalindrome(string s) {

    string newstr = alphanumeric(s);
    if (s.empty()) {
      return true;
    }
    int n = newstr.size();
    int start = 0;
    int end = n - 1;

    while (start <= end) {

      if (newstr[start] != newstr[end]) {
        return false;
      }
      start++;
      end--;
    }
    return true;
  }
};
