# Single Element in a Sorted Array
You are given a sorted array consisting of only integers where every element appears exactly twice, 
except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

* Example 1:
* Input: nums = [1,1,2,3,3,4,4,8,8]
* Output: 2

* Example 2:
* Input: nums = [3,3,7,7,10,11,11]
* Output: 10

## Solution 
```cpp

class Solution {
public:
    int singleNonDuplicate(vector<int>& Arr) {
        int n = Arr.size();
        if(n == 1){
            return Arr[0];
        }
        int st = 0, end = n-1;

        while(st <= end){
            int mid = st + (end - st) / 2;

            if(mid == 0 && Arr[0] != Arr[1]){
                return Arr[mid];
            }

            if(mid == n-1 && Arr[mid] != Arr[mid+1]){
                return Arr[mid];
            }

            if(Arr[mid-1] != Arr[mid] && Arr[mid] != Arr[mid+1]){
                return Arr[mid];
            }

            if(mid % 2 == 0 ){
                if(Arr[mid-1] == Arr[mid]){
                    end = mid - 1;
                }
                else{
                    st = mid + 1;
                }
            }else{
                if(Arr[mid-1] == Arr[mid]){
                    st = mid + 1;
                }
                else{
                    end = mid - 1;
                }
            }
        }
        return -1;
    }

};

```
