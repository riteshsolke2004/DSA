# Trapping Rain Water 
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
 
* Example 1:
* <img width="412" height="161" alt="rainwatertrap" src="https://github.com/user-attachments/assets/05636193-99f6-4a8d-8018-722d5c122a28" />
* Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
* Output: 6
* Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
  In this case, 6 units of rain water (blue section) are being trapped.

* Example 2:
* Input: height = [4,2,0,3,2,5]
* Output: 9

## Solution 1 (Optimal 2 PTR Approach)
```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size() ;
        int ans = 0 ;

        int left = 0 ;
        int right = n - 1 ;

        int leftmax = 0 ; 
        int rightmax = 0 ;

        while(left < right) {

            leftmax = max(leftmax , height[left]) ;
            rightmax = max( rightmax, height[right]) ;

            if(leftmax < rightmax) {
                ans += leftmax - height[left] ;
                left++ ;
            }
            else{
                ans += rightmax - height[right] ;
                right-- ;
            }
        }

        return ans ;
        
    }
};



```

## Solution 2 (Brute Force)
```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size() ;

        vector<int> leftmax (n, 0);
        vector<int> rightmax(n, 0) ;

        leftmax[0] = height[0] ;
        rightmax[n-1] = height[n-1] ;

        for(int i=1; i<n; i++){
            leftmax[i] = max(leftmax[i-1], height[i]) ;

        }

        for(int i=n-2; i>=0; i--){
            rightmax[i] = max(rightmax[i+1], height[i]) ;
        }

        int ans = 0 ;
        for(int i=0; i<n; i++){
            ans += min(leftmax[i] , rightmax[i]) - height[i];
        }

        return ans ;


        
    }
};

```
