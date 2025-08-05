470. Print All Odd Numbers in an Array using Recursion

Given an array of integers, write a recursive function to print all the odd numbers present in the array.
You must implement this functionality in C++ using recursion, without using any iterative constructs (e.g., loops).

Example
Input:
[3, 6, 1, 4, 7, 9]

Output:
3 1 7 9

Explanation:
The input array contains the integers: 3, 6, 1, 4, 7, 9.
The odd numbers among these are 3, 1, 7, and 9. Thus, the output should be a string of these numbers separated by spaces.
Note:
For this problem, the output does not require them to be in any particular format other than space-separated.
Example 1:

Input:

Input: n = 5, arr = [1, 2, 3, 4, 5]
Output:

1 3 5
Explanation:Odd numbers in [1, 2, 3, 4, 5] are 1, 3, and 5.

Example 2:

Input:

Input: n = 4, arr = [2, 4, 6, 8]
Explanation:No odd numbers in [2, 4, 6, 8].

Example 3:

Input:

Input: n = 6, arr = [7, 9, 11, 13, 15, 17]
Output:

7 9 11 13 15 17
Explanation:All numbers are odd.


  #solution 

  
vector<int>printAllOddNumbers(const vector<int>& arr, int index) {

    if(index >= arr.size()) return {} ;

    vector<int> ans = printAllOddNumbers(arr,index+1) ;

    if(!(arr[index] % 2 == 0)){
        ans.insert(ans.begin(), arr[index]) ;
    }

    return ans ;
}
