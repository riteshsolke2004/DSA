Find Single Non-Duplicate Element using Binary Search

You are given a sorted array consisting of n integers where every element appears exactly twice,
except for one element which appears exactly once. Your task is to find this single non-duplicate element in the array.
The array is structured in such a way that it guarantees that exactly one element appears once, while every other element appears twice.

To solve this problem efficiently, you should implement an algorithm with O(log n) runtime complexity.

Example:
Input: nums = [1, 1, 2, 3, 3, 4, 4, 8, 8]

Output: 2

Explanation: Here, each element appears twice except for 2, which appears only once. Therefore, 2 is the single non-duplicate element in the array.

Example 1:

Input:

Input: [1,1,2,3,3,4,4,8,8]

Output:

2
Explanation:The unique element in the array is 2.

Example 2:

Input:

Input: [3,3,7,7,10,11,11]

Output:

10
Explanation:The unique element in the array is 10.

Example 3:

Input:

Input: [1,1,2,2,3]

Output:

3
Explanation:The unique element in the array is 3.


# SOLUTION

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // Implement function with binary search logic
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid % 2 == 1) {
                mid--;
            }
            if (nums[mid] == nums[mid + 1]) {
                left = mid + 2;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};
