246. House Robber

You are a professional robber planning to rob houses along a street. The amount of money stored in each house is represented 
in an array nums where each element is a non-negative integer.
Your task is to determine the maximum amount of money you can rob tonight without triggering the security systems, 
which will be triggered if you rob two directly adjacent houses.

Your goal is to write a function that calculates this maximum amount.
 
Example:
Example 1:
Input: nums = [1, 2, 3, 1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3). Total amount = 1 + 3 = 4.
  
Example 2:

Input: nums = [2, 7, 9, 3, 1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9), and rob house 5 (money = 1). Total amount = 2 + 9 + 1 = 12.
  
Example 1:
Input:

nums=[1,2,3,1]
Output: 4
Explanation:Rob houses 1 and 3 (money = 1 + 3 = 4) to get maximum amount.

Example 2:
Input:
nums=[2,7,9,3,1]
Output:
12
Explanation:Rob houses 1, 3, and 5 (money = 2 + 9 + 1 = 12) for maximum amount.

Example 3:
Input:
nums=[2,1,1,2]
Output:
4
Explanation:Rob houses 1 and 4 (money = 2 + 2 = 4) for maximum amount.


#Solution 

class Solution {
public:
  int solve(vector<int> &nums, int i) {

    if (i >= nums.size()) {
      return 0;
    }

    int include = nums[i] + solve(nums, i + 2);

    int exclude = 0 + solve(nums, i + 1);

    int robbery = max(include, exclude);

    return robbery;
  }

  int rob(vector<int> &nums) {
    int i = 0;
    int ans = solve(nums, i);
    return ans;
  }
};
