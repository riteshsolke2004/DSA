247. Add Strings

Given two non-negative integers, num1 and num2, represented as strings, you need to add these numbers and return the result as a string.
You must handle the addition of these numbers without converting them into integers directly or using built-in functions that handle large integers.
 
Example: 
Input:
num1 = "123"
num2 = "456"
Output:
"579"

Explanation:
123 + 456 = 579, and the result is returned as a string.

Example 1:
Input:
num1='11', num2='123'
Output:
134
Explanation:Adding 11 and 123 gives 134.

Example 2:
Input:
num1='456', num2='77'
Output:
533
Explanation:Adding 456 and 77 gives 533.

Example 3:
Input:
num1='0', num2='0'
Output:
0
Explanation:Adding 0 and 0 gives 0.


#code 

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length() - 1 ;
        int j = num2.length() - 1 ;
        int carry = 0 ;
        string ans ;

        while(i>=0 || j>=0 || carry > 0){
            int sum = 0 ;
            if(i>=0){
                sum += num1[i] - '0' ;
                i-- ;
            }
            if(j>=0){
                sum += num2[j] - '0' ;
                j-- ;
            }
            sum += carry ;
            int lastdigit = sum % 10 ;
            char lastdigitchar = lastdigit + '0' ;
            ans.push_back(lastdigitchar) ;
            carry = sum / 10 ;
        }
        reverse(ans.begin() , ans.end()) ;
        return ans ;
        
    }
};
