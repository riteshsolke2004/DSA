#  Maximum Subarray

### Given an integer array nums, find the subarray with the largest sum, and return its sum.
 
## Example 1:

- Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
- Output: 6
- Explanation: The subarray [4,-1,2,1] has the largest sum 6.
## Example 2:

- Input: nums = [1]
- Output: 1
- Explanation: The subarray [1] has the largest sum 1.
## Example 3:

- Input: nums = [5,4,-1,7,8]
- Output: 23
- Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

# solution 1
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0, maxSum = INT_MIN;

        for(int val : nums){
            currSum += val;
            maxSum = max(currSum,maxSum);

            if(currSum<0){
                currSum = 0;
            }
        }

        return maxSum;
    }

};
```
# Solution 2 (Brute Force)
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int maxSum = INT_MIN ;

        for(int st=0; st<nums.size(); st++){
            int currSum = 0 ;
            for(int end=st; end<nums.size(); end++){

                currSum += nums[end] ;
                maxSum = max(currSum, maxSum) ;

            }
        }
        return maxSum ;
        
    }
};
```
# Solution 3 (Kadane's Algorithm )
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int currSum = 0;
        int maxSum = nums[0];

        for(int i = 0; i < nums.size(); i++) {

            currSum += nums[i];

            maxSum = max(maxSum, currSum);

            if(currSum < 0) {
                currSum = 0;
            }
        }

        return maxSum;
    }
};

```
