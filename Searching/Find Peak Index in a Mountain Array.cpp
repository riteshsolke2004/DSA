Find Peak Index in a Mountain Array

A mountain array is defined as an array that:

Has at least 3 elements.
Contains a peak element where:
arr[0] < arr[1] < ... < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Your task is to find the index of the peak element in the given mountain array arr.

Example:

Input: arr = [0, 2, 5, 3, 1]
Output: 2
In this example, the peak element is 5, located at index 2.
Note:
The input is guaranteed to be a mountain array.

Example 1:
Input:
Input: arr = [0, 1, 0]
Output:
1

Example 2:
Input:
Input: arr = [1, 3, 5, 4, 2]
Output:
2
  
Example 3:
Input:
Input: arr = [0, 2, 4, 6, 5, 3, 1]
Output:
3

  # Solution
  int peakIndexInMountainArray(vector<int>& arr) {

    int n = arr.size() ;
    int start = 0 ;
    int end = n - 1 ;
    int ans = -1  ;

    while(start <= end){

        int mid = (start + end) / 2 ;

        if(arr[mid] < arr[mid + 1]){
           start =  mid + 1 ;
        }
        else {
            ans = mid ;
            end = mid - 1 ;

        }
    }
    return ans;
}
