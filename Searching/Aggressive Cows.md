# Aggressive Cows

Given an integer array arr[], which denotes the positions of stalls. All the positions are distinct. There are k aggressive cows.

Assign the cows to the stalls such that the minimum distance between any two cows is maximized.

### Examples:

- Input: arr[] = [1, 2, 4, 8, 9], k = 3
- Output: 3
- Explanation: The first cow can be placed at arr[0], the second at arr[2], and the third at arr[3]. The minimum distance between any two cows is 3 (between arr[0] and arr[2]), which is the maximum possible among all valid arrangements.
- - Input: arr[] = [10, 1, 2, 7, 5], k = 3
  - Output: 4
  - Explanation: The first cow can be placed at arr[0], the second at arr[1], and the third at arr[4]. 
In this arrangement, the minimum distance between any two cows is 4 (between arr[1] and arr[4]), 
which is the maximum possible among all valid arrangements.

## Solution 
```cpp
class Solution {
  public:
  
    bool isvalidAns(vector<int> &arr, int k, int minDistance) {
        
        int cow = 1 ;
        int lastindex = 0 ;
        
        for(int i=1; i<arr.size(); i++){
            
            if(arr[i] - arr[lastindex] >= minDistance){
                
                cow++;
                lastindex = i ;
            }
            
            if(cow == k ){
                return true ;
            }
        }
        return false ;
        
    }
    int aggressiveCows(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(), arr.end()) ;
        
        int n = arr.size() ;
        
        int start = 0 ;
        int end = arr[n-1] - arr[0] ;
        int ans = -1 ;
        
        while(start <= end) {
            
            int mid = start + (end - start) / 2 ;
            
            if(isvalidAns(arr, k, mid)) {
                
                ans = mid ;
                start = mid + 1 ;
            }
            else {
                end = mid - 1 ;
            }
            
        }
        
        return ans ;
    }
};

```
