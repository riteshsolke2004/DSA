469. Print All Even Numbers in an Array using Recursion

Given an array of integers, your task is to print all the even numbers from the array using recursion.
You need to implement a function that takes an array and its size as input and prints all even numbers present in the array. Use recursive approach for finding and printing the even numbers.

Example
Input:
arr = [2, 3, 5, 6, 8, 11] n = 6
Output:
2 6 8

Explanation:

The numbers 2, 6, and 8 from the array are even numbers, and hence they are printed.
The numbers 3, 5, and 11 are odd, so they are not printed.
Example 1:
Input: n = 5, arr = [1, 2, 3, 4, 5]
Output:
2 4
Explanation:Only even numbers in [1, 2, 3, 4, 5] are 2 and 4.

Example 2:
Input: n = 4, arr = [10, 21, 32, 45]
Output:
10 32
Explanation:Even numbers in [10, 21, 32, 45] are 10 and 32.

Example 3:
Input: n = 6, arr = [2, 4, 6, 8, 10, 12]
Output:
2 4 6 8 10 12
Explanation:All numbers are even.



#Solution 

  vector<int>printEvenNumbers(vector<int>& arr, int index) {

    if(index >= arr.size()) return {} ;

    vector<int> ans = printEvenNumbers(arr,index+1) ;

    if(arr[index] % 2 == 0){
        ans.insert(ans.begin(), arr[index]) ;
    }

    return ans ;
}
