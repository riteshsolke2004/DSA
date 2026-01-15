Reverse a Vector

In this problem, you are given an array of integers. Your task is to create a function that returns a new array with the
elements of the original array in reverse order. The reversal should be performed without altering the original array; instead,
you should produce a new one that contains the elements in reversed order.

For example, consider an array:

[1, 2, 3, 4]
When reversed, this array should become:

[4, 3, 2, 1]
The goal is to ensure that every element from the input array appears in reverse order within the output array.

Example 1:
Input:
Input: arr = [1, 2, 3, 4, 5]
Output:
[5, 4, 3, 2, 1]
Explanation:The array is reversed to [5, 4, 3, 2, 1].
  
Example 2:
Input:
Input: arr = [10, 20, 30]
Output:
[30, 20, 10]
Explanation:The array is reversed to [30, 20, 10].
  
Example 3:
Input:
Input: arr = [-1, -2, -3]
Output:
[-3, -2, -1]
Explanation:The array is reversed to [-3, -2, -1].

  #include <algorithm>
class Solution {
public:
    vector<int> reverseArray( vector<int>& arr) {

        int i=0 ;
        int j = arr.size() - 1 ;

        while(i<=j){
            swap(arr[i] , arr[j]) ;
            i++ ;
            j-- ;
        }
        return arr ;
    }
};
