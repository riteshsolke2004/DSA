Find the Maximum Element in an Array

Your task is to find the maximum integer value in a given array. This basic problem tests your ability to work with array traversal
and element comparison efficiently.

Function Signature
    def findMaximum(arr: List[int]) -> int:

Input
A list of integers arr.
Output
The maximum integer present in the array.
  
Example
Example 1:
Input:
arr = [1, 2, 3, 4, 5]
Output:
5
Explanation: The largest number in the array [1, 2, 3, 4, 5] is 5.


Example 2:
Input:
arr = [-1, -2, -3, -4, -5]
Output:
-1
Explanation: Even though all numbers are negative, -1 is the highest value in the array.

Approach
While handling the problem, ensure you iterate through the array and keep track of the current maximum element. 
It is necessary to update this maximum as you progress through the array.

Example 1:
Input:
Input: arr = [1, 2, 3, 4, 5]
Output:
5
Explanation:The maximum element in the array is 5.

Example 2:
Input:
Input: arr = [5, 4, 3, 2, 1]
Output:
5
Explanation:The maximum element is at the beginning.

Example 3:
Input:
Input: arr = [10, 20, 5, 40, 30, 50]
Output:
50
Explanation:The maximum element is 50, appearing last.

Approach
Initialization:

Start by assuming the first element of the array (arr[0]) is the maximum element. This assumption is necessary to have a baseline for comparison.
Iteration:

Traverse through each element of the array starting from the second element (index = 1).
Compare each element with our assumed max_element.
Comparison and Update:

If the current element is greater than the max_element, update max_element to this current value.
Continue this process until all elements have been compared.
Conclusion:

Once the loop completes, max_element will contain the largest element in the array, which is then returned as the final result

#include <limits.h>

class Solution {
public:
    int findMaximum(vector<int>& arr) {

        int n = arr.size() ;
        int maxi = INT_MIN ;

        for(int i=0; i<n; i++){
            maxi = max(arr[i],maxi) ;
        }

        return maxi ;
    }
};
