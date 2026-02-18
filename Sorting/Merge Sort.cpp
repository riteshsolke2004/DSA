Merge Sort Algorithm 


#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;

    int i = left;      // starting index of left half
    int j = mid + 1;   // starting index of right half

    // Compare and merge
    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Remaining elements of left half
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // Remaining elements of right half
    while (j <= right) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy back to original array
    for (int k = 0; k < temp.size(); k++) {
        arr[left + k] = temp[k];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;  // Base case

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid);       // Sort left half
    mergeSort(arr, mid + 1, right);  // Sort right half

    merge(arr, left, mid, right);    // Merge both halves
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 6};

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}
