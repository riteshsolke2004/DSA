Find the Pivot Index of a Rotated Array

You are given an array that has been rotated at some pivot unknown to you beforehand. 
The array was initially sorted in increasing order, and then rotated at the pivot. 
Your task is to find the pivot index, which is the index of the highest element in the array
(i.e., the last element of the unrotated sorted array).

A rotated sorted array means that you take a portion of a sorted array from some index k to the end, and move it to the front. 
For example, the sorted array [0, 1, 2, 4, 5, 6, 7] after being rotated at pivot index 3, becomes [4, 5, 6, 7, 0, 1, 2].

Your Task:
Write a function to return the index of the pivot.

Example:
Input: nums = [4, 5, 6, 7, 0, 1, 2]
Output: 3
Explanation: In this array, the pivot point is the index 3 because the array [4, 5, 6, 7], 
when combined with [0, 1, 2], forms the original sorted array [0, 1, 2, 4, 5, 6, 7].

Example 1:
Input:
Input: nums = [3, 4, 5, 1, 2]
Output:
2
Explanation:

Example 2:
Input:
Input: nums = [4, 5, 6, 7, 0, 1, 2]
Output:
3
Explanation:

Example 3:
Input:
Input: nums = [1, 2, 3, 4, 5]
Output:
-1


## SOLUTION 

  class Solution {
public:
    int findPivotIndex(vector<int>& nums){
        int n = nums.size() ;
        int start = 0 ;
        int end = n - 1 ;

        while(start <= end) {
            int mid = ( start + end ) / 2 ;

            if(mid + 1 < n && nums[mid] > nums[mid + 1] ){
                return mid ;
            }

            if(nums[mid] < nums[start]){
                end = mid - 1 ;
            }
            else{
                start = mid + 1 ;
            }      


        }
        return -1 ;
}
};
