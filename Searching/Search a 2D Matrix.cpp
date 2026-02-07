Search a 2D Matrix

### LEETCODE 
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

 
Example 1:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false


### CODEHELP QUESTION
  Search an Element in a 2D Matrix

You are provided with an m x n matrix, where each row and each column are sorted in ascending order.
Your task is to find out whether a given target number exists in this matrix. The matrix is structured 
in such a way that facilitates efficient searching due to its sorted properties. Your goal is to implement
the function bool searchMatrix(vector<vector<int>>& matrix, int target) that returns true if the target is present 
in the matrix, and false otherwise.

Example:
Input:


matrix = [[1, 4, 7, 11, 15],
          [2, 5, 8, 12, 19],
          [3, 6, 9, 16, 22],
          [10, 13, 14, 17, 24],
          [18, 21, 23, 26, 30]]
target = 5
Output: true

Explanation: 5 is located in the second row of the matrix.

Input:


matrix = [[1, 4, 7, 11, 15],
          [2, 5, 8, 12, 19],
          [3, 6, 9, 16, 22],
          [10, 13, 14, 17, 24],
          [18, 21, 23, 26, 30]]
target = 20
Output: false

Explanation: 20 does not exist in the matrix.

Example 1:
Input:
Input: matrix = [[1, 3, 5], [7, 9, 11], [13, 15, 17]], target = 9
Output:

true
Explanation:

Example 2:
Input:
Input: matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]], target = 10
Output:
false
Explanation:

Example 3:
Input:
Input: matrix = [[10, 20, 30], [40, 50, 60], [70, 80, 90]], target = 80
Output:
true


## LEETCODE SOLUTION 
  class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size() ;
        int columns = matrix[0].size() ;
        int total = rows * columns ;

        int start = 0 ;
        int end = total - 1 ;

        while(start <= end){

            int mid = (start + end) / 2 ;

            int rowindex = mid / columns ;
            int columnindex = mid % columns ;

            if(matrix[rowindex][columnindex] == target){
                return true ;
            }

            if(target > matrix[rowindex][columnindex]){

                start = mid + 1 ;
            }
            else{

                end = mid - 1 ;
            }

        }

        return false ;

        
    }
};

## CODEHELP SOLUTON
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int row = matrix.size() ;
        int col = matrix[0].size() ;
        int total = row * col ;
        int n = total - 1 ;

        int start = 0 ;
        int end = n ;

        while(start <= end) {
            int mid = (start + end) / 2 ;

            int rowindex = mid / col ;
            int colindex = mid % col ;

            if(row == 1){
                return true ;
            }

            if(matrix[rowindex][colindex] == target) {
                return mid ;

            }
            
            if(matrix[rowindex][colindex] > target){
                end = mid - 1 ;
            }
            else{
                start = mid + 1 ;
            }

        }
        return false ;
    }
};
