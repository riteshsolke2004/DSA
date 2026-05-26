# Subarray Sum Equals K
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2

## Solution 1 (Brute Force) 
```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size() ;
        int count = 0 ;

        for(int i=0; i<n; i++){
            int sum = 0 ;

            for(int j=i; j<n; j++){
                
                sum+= nums[j] ;

                if(sum == k) count++ ;
            }
        }
        return count ;
    }
};

```

## Solution 2 (Optimal Approch)
```cpp

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> mp;

        int sum = 0;
        int count = 0;

        mp[0] = 1;

        for(int i = 0; i < nums.size(); i++){

            sum += nums[i];

            count += mp[sum - k];

            mp[sum]++;
        }

        return count;
    }
};

```
