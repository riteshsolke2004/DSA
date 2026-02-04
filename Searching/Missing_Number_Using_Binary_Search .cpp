Missing Number
Problem Description
Given an array nums containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Note:
Try to implement an algorithm with a linear runtime complexity.

Example 1:
Input:
n=3 nums=[3,0,1]
Output:
2
Explanation:The range should contain {0,1,2,3}. Only 2 is absent.

Example 2:
Input:
n=4 nums=[1,2,3,4]
Output:
0
Explanation:Numbers present are {1,2,3,4}; 0 is missing.

Example 3:
Input:
n=4 nums=[0,1,2,3]
Output:
4
Explanation:Expected range is {0,1,2,3,4}; 4 is not present.

  #include <algorithm>
class Solution {
public:

    int getmissingnumber(vector<int> arr){
        int n = arr.size() ;
        int start = 0 ;
        int end = n - 1 ;
        int ans = n ;

        while(start <= end){

            int mid = (start+end) / 2 ;

            if(mid == arr[mid]){
                start = mid + 1 ;
            }
            else{
                ans = mid ;
                end = mid - 1 ;

            }
        }
        return ans ;

    }
    int missingNumber(vector<int>& nums){
        sort(nums.begin(), nums.end()) ;
        int missNum = getmissingnumber(nums) ;

        return missNum ;

    }
};
