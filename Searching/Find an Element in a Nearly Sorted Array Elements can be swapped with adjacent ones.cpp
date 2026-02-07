Find an Element in a Nearly Sorted Array Elements can be swapped with adjacent ones

In a nearly sorted array, elements are expected to be in sorted order except that each element can be swapped
with its adjacent elements. This means that any element at index i in a sorted array could appear at index i-1, i,
or i+1 in a nearly sorted array. Your task is to determine the index of a given target element K within this array.
If the element K is not present, return -1.

Example
Input:
n = 5
arr = [3, 5, 10, 9, 11]
K = 10
Output:
2
Explanation: The element 10 can be found at index 2, satisfying the conditions of a nearly sorted array.

Additional Example
Input:
n = 4
arr = [1, 3, 4, 2]
K = 4
Output:
2
Explanation: The element 4 appears at index 2 in this nearly sorted array.

Example 1:
Input:
Input: n = 7, arr = [10, 3, 40, 20, 50, 80, 70], K = 40
Output:
2
Explanation:40 is found at index 2.

Example 2:
Input:
Input: n = 5, arr = [5, 10, 30, 20, 40], K = 20
Output:
3
Explanation:20 is found at index 3.

Example 3:
Input:
Input: n = 6, arr = [10, 20, 30, 40, 50, 60], K = 30
Output:
2
Explanation:30 is found at index 2.

int findElementInNearlySortedArray(const vector<int>& arr, int K) {

    int n = arr.size() ;
    int start = 0 ;
    int end = n - 1 ;

    while(start <= end) {

        int mid = (start + end) / 2 ;

        if(arr[mid] == K){
            return mid ;
        }
        
        if(arr[mid + 1] == K) {
            return mid + 1 ;
        }

        if(arr[mid - 1] == K){

            return mid - 1 ;
        }

        if(arr[mid]< K){
            start = mid + 1 ;
        }
        else{
            end = mid - 1 ;
        }
    }
    return -1; // Placeholder return
}
