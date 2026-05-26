# Container With Most Water
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.

Example 1:

<img width="801" height="383" alt="question_11" src="https://github.com/user-attachments/assets/56dda8dd-0b58-492c-b8bf-3a8bcb305716" />

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, 
the max area of water (blue section) the container can contain is 49.

Example 2:
Input: height = [1,1]
Output: 1

# Solution 1 (Brute force) 
```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0 ;
        int n = height.size() ;

        for(int i=0; i<n; i++){

            for(int j=i+1; j<n; j++){

                int width = j - i ;
                int hgt = min(height[i], height[j]) ;
                int area = width * hgt ; 

                ans = max(ans, area) ;
            }
        }
        return ans ;
    }
};

```

# Solution 2 (2 PTR Approch)

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size() ;
        int left = 0 ;
        int right = n - 1 ;

        int ans = 0 ; 
        while(left < right) {
            int width = right - left ;
            int hgt = min(height[left], height[right]) ;
            int currArea = width * hgt ;

            ans = max(ans, currArea) ;
            if(height[left] < height[right]){
                left++ ;
            }
            else{
                right-- ;
            }
        }
        return ans ;
        
    }
};

```
