 Find First and Last Occurrence of an Element in a Sorted Array

You are given a sorted array of integers nums and an integer target. Your task is to identify the starting and ending positions of target in the array.
If target does not exist in the array, return [-1, -1].

This problem requires you to find both the first and last positions of target efficiently.
Ideally, you should aim to achieve this in O(log N) time complexity using an appropriate algorithm.

Example 1:


Input: nums = [5,7,7,8,8,10], target = 8
Output: [3, 4]
Example 2:


Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1, -1]
Example 3:


Input: nums = [], target = 0
Output: [-1, -1]
Explanation
In Example 1, the target 8 appears from index 3 to 4. Thus, the output is [3, 4].
In Example 2, the target 6 is absent from the array, so the output is [-1, -1].
In Example 3, the array is empty, thus the target 0 is not found, resulting in [-1, -1].

Example 1:
Input:
Input: nums = [5,7,7,8,8,10], target = 8

Output:
[3, 4]

Example 2:
Input:
Input: nums = [5,7,7,8,8,10], target = 6
Output:
[-1, -1]

Example 3:
Input:
Input: nums = [], target = 0
Output:
[-1, -1]


  # Solution 

  #include <vector>
#include <algorithm>
class Solution {
public:

    int firstOccurance(vector<int>& nums, int target){
        int n = nums.size() ;
        int start = 0 ;
        int end = n - 1 ;
        int ans = -1 ;

        while(start <= end) {
            int mid = (start + end) / 2 ;

            if(nums[mid] == target){
                ans = mid ;
                end = mid - 1 ;
            }
            else{
                start = mid + 1 ;
            }
        }
        return ans ;

    }

    int lastOccurance(vector<int>& nums, int target){
        int n = nums.size() ;
        int start = 0 ;
        int end = n - 1 ;
        int ans = -1 ;

        while(start <= end) {
            int mid = (start + end) / 2 ;

            if(nums[mid] == target){
                ans = mid ;
                start = mid + 1 ;
            }
            else if(target < nums[mid]){
                end = mid - 1 ;
            }
            else{
                start = mid + 1 ;
            }
        }

        return ans ;

    }
    vector<int> searchRange(vector<int>& nums, int target){

        int first = firstOccurance(nums, target) ;
        int last = lastOccurance(nums, target) ;

        vector<int> temp ;
        temp.push_back(first) ;
        temp.push_back(last) ;

        return temp ;
    }
};
