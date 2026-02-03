Binary Search Implementation

In this problem, you are provided with a sorted array of integers arr and an integer target. Your task is to implement a binary search algorithm to find the index of target in arr.
If the target does not exist in the array, you should return -1.

Binary Search is an efficient algorithm that relies on a divide and conquer approach. The main idea is to repeatedly divide the search space in half by comparing the middle element 
in the current interval to the target value. Depending on the comparison, the search interval is narrowed down to either the lower or upper half. This process repeats until the target
is found or the search interval becomes empty.

Example 1:
Input: arr = [-1, 0, 3, 5, 9, 12], target = 9
Output: 4
Explanation: The number 9 is located at index 4 in the array.

Example 2:
Input: arr = [-1, 0, 3, 5, 9, 12], target = 2
Output: -1
Explanation: The number 2 is not present in the array, thus the function returns -1.
  
Note:
Assume that all integers in the array arr are unique.
The algorithm should have a time complexity of O(log n).
Example 1:

Input:

Input: arr = [1, 2, 3, 4, 5, 6, 7, 8, 9], target = 5
Output:
4
  
Example 2:
Input:
Input: arr = [10, 20, 30, 40, 50, 60], target = 30
Output:
2
  
Example 3:
Input:
Input: arr = [1, 3, 5, 7, 9], target = 8
Output:
-1


  # Solution 
  int binarySearch(const vector<int>& arr, int target) {

    int n = arr.size() ;
    int start = 0 ;
    int end = n-1 ;

    while(start <= end){

        int mid = ( start + end ) / 2 ;

        if(arr[mid] == target){
            return mid ;
        }
        else if(target < arr[mid]){
            end = mid - 1 ;
        }
        else {
            start = mid + 1 ;
        }
    }
    return -1;
}
