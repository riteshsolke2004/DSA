Sort an Array

Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other 
numbers are changed (for example, 1 and 5).
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessarily unique.


  # Solution 

  class Solution {
public:

    void merge(vector<int>& nums, int l, int m, int r) {
        vector<int> temp;
        int i = l, j = m + 1;

        while (i <= m && j <= r) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }

        while (i <= m)
            temp.push_back(nums[i++]);

        while (j <= r)
            temp.push_back(nums[j++]);

        for (int k = 0; k < temp.size(); k++)
            nums[l + k] = temp[k];
    }

    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r)
            return;

        int m = (l + r) / 2;

        mergeSort(nums, l, m);
        mergeSort(nums, m + 1, r);

        merge(nums, l, m, r);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
