# 4Sum
* Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

* 0 <= a, b, c, d < n
* a, b, c, and d are distinct.
* nums[a] + nums[b] + nums[c] + nums[d] == target
* You may return the answer in any order.

** Example 1: 

- Input: nums = [1,0,-1,0,-2,2], target = 0
- Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

** Example 2:

- Input: nums = [2,2,2,2,2], target = 8
- Output: [[2,2,2,2]]


## Solution 1 (Brute Force)
```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < n; j++) {

                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                for (int k = j + 1; k < n; k++) {

                    if (k > j + 1 && nums[k] == nums[k - 1]) {
                        continue;
                    }

                    for (int l = k + 1; l < n; l++) {

                        if (l > k + 1 && nums[l] == nums[l - 1]) {
                            continue;
                        }

                        int first = nums[i];
                        int second = nums[j];
                        int third = nums[k];
                        int fourth = nums[l];

                        long long sum =
                            (long long)first + second + third + fourth;

                        if (sum == target) {

                            vector<int> temp;
                            temp.push_back(first);
                            temp.push_back(second);
                            temp.push_back(third);
                            temp.push_back(fourth);

                            ans.push_back(temp);
                        }
                    }
                }
            }
        }
        return ans;
    }
};

```

## Solution 2 (Optimal) 
```cpp

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                int p = j + 1;
                int q = n - 1;

                while (p < q) {

                    long long int sum =
                        (long long)nums[i] + nums[j] + nums[p] + nums[q];

                    if (sum == target) {

                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                        p++;
                        q--;

                        while (p < q && nums[p] == nums[p - 1]) {
                            p++;
                        }

                        while (p < q && nums[q] == nums[q + 1]) {
                            q--;
                        }

                    } else if (sum > target) {
                        q--;
                    } else {
                        p++;
                    }
                }
            }
        }
        return ans;
    }
};

```
