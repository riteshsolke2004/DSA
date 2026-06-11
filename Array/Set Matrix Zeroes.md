# Set Matrix Zeroes
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

### Example 1:
<img width="641" height="241" alt="mat1" src="https://github.com/user-attachments/assets/2c29ddd6-0c24-4744-b384-a9a997bf841a" />

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]



### Example 2:

<img width="791" height="241" alt="mat2" src="https://github.com/user-attachments/assets/4a39a197-849e-4cf0-a95b-f90a44761da2" />
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

# Solution 
```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m = matrix.size() ;
        int n = matrix[0].size() ;

        vector<int> row (m,0) ;
        vector<int> col (n, 0) ;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                
                if(matrix[i][j] == 0) {
                    row[i] = 1 ;
                    col[j] = 1 ;
                }
            }
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {

                if(row[i] == 1 || col[j] == 1) {
                    matrix[i][j] = 0 ;
                }
            }
        }
        
    }
};

```
