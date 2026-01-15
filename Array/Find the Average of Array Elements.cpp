Find the Average of Array Elements

Problem Description
You are given an array of integers. Your task is to compute the average value of the elements in the array. 
The average is defined as the sum of all the elements divided by the number of elements. You should consider 
all possible integer values that are within the provided constraints.

Example:
Suppose you have an array: [2, 4, 6, 8]

The sum of the array elements is 2 + 4 + 6 + 8 = 20.
The number of elements in the array is 4.
Therefore, the average is 20 / 4 = 5.0.
Your task is to implement a function that calculates this average for any given array of integers.

Example 1:
Input:
Input: arr = [2, 4, 6, 8, 10]
Output:
6
Explanation:Average of [2, 4, 6, 8, 10] is 6.

Example 2:
Input:
Input: arr = [1, -1, 1, -1]
Output:
0
Explanation:Average of [1, -1, 1, -1] is 0.

Example 3:
Input:
Input: arr = [5, 10, 15]
Output:
10
Explanation:Average of [5, 10, 15] is 10.

Approach
Initialization: Start by initializing a variable, sum, to zero. This variable will be used to accumulate the sum of all elements in the array.

Iterate through the array: Use a loop to traverse through each element of the array. During each iteration, add the current element's value to the sum.

Calculate the average: Once the loop completes, calculate the average by dividing the sum by the size of the array. This operation gives us the desired average.

Return the result: Return the computed average as a double to ensure precision, especially when dealing with integer division.



class Solution {
public:
    double findAverage(const vector<int>& arr) {

        int n = arr.size() ;
        double ans = 0 ;

        for(int i=0 ; i<n ; i++){
            ans = ans + arr[i] ;
        }
        ans = ans / n ;

        return ans ;
    }
};
