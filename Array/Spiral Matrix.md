# Spiral Matrix

Given an m x n matrix, return all elements of the matrix in spiral order.

 

## Example 1:
<img width="242" height="242" alt="spiral1" src="https://github.com/user-attachments/assets/9015b51f-e102-4cfd-99e7-2a5201a49654" />

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

## Example 1:
<img width="322" height="242" alt="spiral" src="https://github.com/user-attachments/assets/d14fcc26-9775-4b6b-9b74-e6d5b2909ad0" />

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;

        int top = 0;
        int left = 0;
        int bottom = m - 1;
        int right = n - 1;

        while (top <= bottom && left <= right) {

            for (int j = left; j <= right; j++) {
                ans.push_back(matrix[top][j]);
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

            if (top <= bottom) {
                for (int k = right; k >= left; k--) {
                    ans.push_back(matrix[bottom][k]);
                }
                bottom--;
            }

            if (left <= right) {
                for (int r = bottom; r >= top; r--) {
                    ans.push_back(matrix[r][left]);
                }
                left++;
            }
        }
        return ans;
    }
};

```
