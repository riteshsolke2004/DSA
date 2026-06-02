# Largest Rectangle in Histogram 
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
return the area of the largest rectangle in the histogram.

* Example 1:
* <img width="522" height="242" alt="histogram" src="https://github.com/user-attachments/assets/09154ebf-3676-4c06-8031-f820cb2c8e34" />
* Input: heights = [2,1,5,6,2,3]
* Output: 10
* Explanation: The above is a histogram where width of each bar is 1. The largest rectangle is shown in the red area, which has an area = 10 units.
  
* Example 2:
* <img width="202" height="362" alt="histogram-1" src="https://github.com/user-attachments/assets/47876f14-dee0-46f1-a2a8-11c06ac7c861" />
* Input: heights = [2,4]
* Output: 4

## Solution (Using Stack)
```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> left(n, 0);
        vector<int> right(n, 0);

        stack<int> s;

        for(int i = n - 1; i >= 0; i--){

            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }

            right[i] = s.empty() ? n : s.top();

            s.push(i);
        }

        while(!s.empty()){
            s.pop();
        }

        // Next Smaller Left
        for(int i = 0; i < n; i++){

            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }

            left[i] = s.empty() ? -1 : s.top();

            s.push(i);
        }

        long long ans = 0;

        for(int i = 0; i < n; i++){

            long long width = right[i] - left[i] - 1;

            long long currArea = heights[i] * width;

            ans = max(ans, currArea);
        }

        return ans;
    }
};

```
