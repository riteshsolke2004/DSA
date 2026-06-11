# 3Sum Closest
Given an integer array nums of length n and an integer target, find three integers at distinct indices in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

 

### Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
### Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

# Solution 
```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int currSum = 0;
        sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n - 2; i++) {

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                currSum = nums[i] + nums[left] + nums[right];

                if (abs(target - currSum) < abs(target - closestSum)) {
                    closestSum = currSum;
                }

                if (currSum == target) {
                    return currSum;
                } else if (currSum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return closestSum;
    }
};

```
