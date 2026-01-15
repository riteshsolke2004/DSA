Count the Number of Zeros and Ones in an Array

Given an array of integers nums where each element is either 0 or 1, your task is to determine how many zeros and how many ones exist in the array. 
Return the counts of zeros and ones in the specified format.

Example
Input
nums = [0, 1, 0, 1, 1, 0, 1, 0]
Output
zeros: 4, ones: 4
Explanation
The provided array contains four 0s and four 1s, resulting in an output of zeros: 4, ones: 4.

Instructions
Implement a function that will take the array nums as input and return the count of zeros and ones.
Example 1:
Input:
Input: nums = [0, 1, 0, 1, 1, 0]
Output:
zeros: 3, ones: 3
Explanation:Equal number of zeros and ones, count of each is 3.

Example 2:
Input:
Input: nums = [1, 1, 1, 1, 1]
Output:
zeros: 0, ones: 5
Explanation:All elements are ones, so zero count is 0 and one count is 5.

Example 3:
Input:
Input: nums = [0, 0, 0, 0, 0, 0]
Output:
zeros: 6, ones: 0
Explanation:All elements are zeros, so zero count is 6 and one count is 0.


class Solution {
public:
    std::pair<int, int> countZerosAndOnes(const std::vector<int>& nums) {

        int n = nums.size() ;
        int zeroCount = 0 ;
        int oneCount = 0 ;

        for(int i=0 ; i<n; i++){

            if(nums[i] == 0){
                zeroCount++ ;
            }
            else{
                oneCount++ ;
            }
        }

        return {zeroCount,oneCount} ;
    }
};
