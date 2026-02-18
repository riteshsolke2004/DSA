Quick Sort Algorithm 

#include <iostream>
#include <vector>
using namespace std;

// Partition function
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];   // Take last element as pivot
    int i = low - 1;         // Smaller element index

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);  // Place pivot in correct position
    return i + 1;
}

// Quick Sort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);   // Left side
        quickSort(arr, pi + 1, high);  // Right side
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 6};

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}


