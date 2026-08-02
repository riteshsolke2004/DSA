# Maximum Product Subarray

Given an array arr[] that contains positive and negative integers (may contain 0 as well). 
Find the maximum product that we can get in a subarray of arr[].

Note: It is guaranteed that the answer fits in a 32-bit integer.

### Examples
- Input: arr[] = [-2, 6, -3, -10, 0, 2]
- Output: 180
- Explanation: The subarray with maximum product is [6, -3, -10] with product = 6 * (-3) * (-10) = 180.

- Input: arr[] = [-1, -3, -10, 0, 6]
- Output: 30
- Explanation: The subarray with maximum product is [-3, -10] with product = (-3) * (-10) = 30.

- Input: arr[] = [2, 3, 4]
- Output: 24
- Explanation: For an array with all positive elements, the result is product of all elements.

  ## Solution
  ```cpp
  class Solution {
  public:
    int maxProduct(vector<int> &arr) {

        int n = arr.size();

        int prefix = 1;
        int suffix = 1;
        int maxProduct = INT_MIN;

        for(int i = 0; i < n; i++) {

            if(prefix == 0)
                prefix = 1;

            if(suffix == 0)
                suffix = 1;

            prefix *= arr[i];

            suffix *= arr[n - i - 1];

            maxProduct = max(maxProduct, max(prefix, suffix));
        }

        return maxProduct;
    }
};

``` 
