# Single Number





# Solution 1 Using (XOR Operator)
```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for(int val : nums){
            ans = ans^val;
        }

        return ans;
        
    }
};

```

# Solution 2 (Unordered map)
```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        unordered_map<int,int> mp;

        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
        }

        for(auto it : mp) {
            if(it.second == 1) {
                return it.first;
            }
        }

        return -1;
    }
};

```
