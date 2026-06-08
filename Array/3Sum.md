##  3 Sum
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.
 
- Example 1:   

- Input: nums = [-1,0,1,2,-1,-4]
- Output: [[-1,-1,2],[-1,0,1]]
- Explanation:  
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0. 
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
- Example 2:
 
- Input: nums = [0,1,1]
- Output: []
- Explanation: The only possible triplet does not sum up to 0.

- Example 3:

- Input: nums = [0,0,0]
- Output: [[0,0,0]]
- Explanation: The only possible triplet sums up to 0.


## Solution 1
```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size() ;
        vector<vector<int>> result ;
 
        for(int i=0; i<n-2; i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue ;
            }
            int left = i+1 ;
            int right = n-1 ;

            while(left < right){
                int sum = (nums[i] + nums[left] + nums[right]) ;

                if(sum == 0){
                    result.push_back({nums[i],nums[left], nums[right]}) ;
                    left++ ;
                    right-- ;

                    while(left < right && nums[left] == nums[left-1]) left++ ;
                    while(left < right && nums[right] == nums[right + 1]) right-- ;

                }
                else if (sum < 0) {
                    left++ ;
                } 
                else{
                    right-- ;
                }

            }
       
        }
        return result ;
    }
};
```
## Solution 2(Brute Force)
```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

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

                    int first = nums[i];
                    int second = nums[j];
                    int third = nums[k];

                    int sum = first + second + third;

                    if (sum == 0) {
                        vector<int> temp;
                        temp.push_back(first);
                        temp.push_back(second);
                        temp.push_back(third);
                        ans.push_back(temp);
                    }
                }
            }
        }
        return ans;
    }
};

```
## Solution 3 (Optimal)
```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size() ;

        vector<vector<int>> ans ;

        sort(nums.begin(), nums.end()) ;

        for(int i=0; i<n; i++){

            if(i > 0 && nums[i] == nums[i-1]){
                continue ;
            }

            int j = i+1 ;
            int k = n-1 ;

            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k]  ;

                if(sum < 0) {
                    j++ ;
                }
                else if(sum > 0){
                    k-- ;
                }
                else{
                    ans.push_back({nums[i], nums[j], nums[k]}) ;
                    j++ ;
                    k-- ;
                    while(j < k && nums[j] == nums[j-1]){
                        j++ ;
                    }
                }

            }
        }
        return ans ;
        
    }
};
```
