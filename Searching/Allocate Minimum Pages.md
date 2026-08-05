# 📚 Allocate Minimum Pages

## Problem Statement

Given an array `arr[]`, where `arr[i]` represents the number of pages in the `i-th` book, and an integer `k` representing the number of students.

Allocate all books among the students such that:

* Each student receives **at least one book**.
* Each student receives a **contiguous sequence of books**.
* Every book must be allocated.
* A book cannot be assigned to more than one student.
* The **maximum number of pages assigned to any student should be minimized**.

If the number of students is greater than the number of books, return `-1`.

---

## Example 1

### Input

```text
arr = [12, 34, 67, 90]
k = 2
```

### Possible Allocations

```text
[12]          | [34, 67, 90]
12            | 191
Maximum = 191

[12, 34]      | [67, 90]
46            | 157
Maximum = 157

[12, 34, 67]  | [90]
113           | 90
Maximum = 113
```

Therefore:

```text
Output = 113
```

The minimum possible value of the maximum pages assigned to a student is **113**.

---

## Example 2

### Input

```text
arr = [15, 17, 20]
k = 5
```

### Output

```text
-1
```

There are only `3` books but `5` students.

Since every student must receive at least one book, allocation is impossible.

---

# Approach — Binary Search on Answer

Instead of generating every possible allocation, we use **Binary Search on the Answer**.

The answer must lie between:

```text
Maximum element of array ≤ Answer ≤ Sum of all elements
```

Therefore:

```cpp
start = max(arr);
end = sum(arr);
```

### Why is `start = max(arr)`?

Consider:

```text
arr = [12, 34, 67, 90]
```

The largest book contains:

```text
90 pages
```

A book cannot be divided between students.

Therefore, at least one student must receive the `90`-page book.

So the answer can never be smaller than `90`.

```text
start = 90
```

### Why is `end = sum(arr)`?

In the worst case, one student could receive all books.

```text
12 + 34 + 67 + 90 = 203
```

Therefore:

```text
end = 203
```

Our search space becomes:

```text
[90 ................ 203]
```

---

# Validity Check

For every value of `mid`, we check:

> Can all books be allocated to at most `k` students if no student receives more than `mid` pages?

This is handled by:

```cpp
isvalidAns(arr, k, mid)
```

We keep assigning contiguous books to the current student.

If adding the next book exceeds `maxPages`, we assign that book to the next student.

```cpp
if(pages + arr[i] <= maxPages) {
    pages += arr[i];
}
else {
    student++;
    pages = arr[i];
}
```

If we require more than `k` students:

```cpp
student > k
```

then the current `maxPages` value is not possible.

---

# Binary Search Logic

For every `mid`:

```cpp
mid = start + (end - start) / 2;
```

### If `mid` is valid

```cpp
if(isvalidAns(arr, k, mid))
```

then `mid` is a possible answer.

But we want the **minimum possible answer**, so:

```cpp
ans = mid;
end = mid - 1;
```

We search towards the left.

### If `mid` is invalid

It means `mid` is too small.

So:

```cpp
start = mid + 1;
```

We search towards the right.

---

# C++ Solution

```cpp
class Solution {
public:

    bool isvalidAns(vector<int> &arr, int k, long long maxPages) {

        int student = 1;
        long long pages = 0;

        for(int i = 0; i < arr.size(); i++) {

            if(pages + arr[i] <= maxPages) {

                pages += arr[i];

            }
            else {

                student++;

                if(student > k || arr[i] > maxPages) {
                    return false;
                }

                pages = arr[i];
            }
        }

        return true;
    }


    int findPages(vector<int> &arr, int k) {

        int n = arr.size();

        if(n < k) {
            return -1;
        }

        long long start = 0;
        long long sum = 0;
        long long ans = -1;

        for(int i = 0; i < n; i++) {

            start = max(start, (long long)arr[i]);
            sum += arr[i];
        }

        long long end = sum;

        while(start <= end) {

            long long mid = start + (end - start) / 2;

            if(isvalidAns(arr, k, mid)) {

                ans = mid;
                end = mid - 1;

            }
            else {

                start = mid + 1;
            }
        }

        return (int)ans;
    }
};
```

---

# Dry Run

Consider:

```text
arr = [12, 34, 67, 90]
k = 2
```

Initial binary-search range:

```text
start = max(arr) = 90
end   = sum(arr) = 203
```

Binary search keeps checking a possible maximum-page limit.

Eventually:

```text
mid = 113
```

Allocation:

```text
Student 1 → [12, 34, 67]

12 + 34 + 67 = 113


Student 2 → [90]

90
```

Maximum pages:

```text
max(113, 90) = 113
```

So `113` is valid.

Trying to reduce the limit below `113` would require more than `2` students.

Therefore:

```text
Answer = 113
```

---

# Complexity Analysis

Let:

```text
N = number of books
S = sum of pages
M = maximum pages in a single book
```

The validity check traverses the array once:

```text
O(N)
```

Binary search operates over the range:

```text
[M, S]
```

Therefore, the total time complexity is:

```text
O(N × log(S - M + 1))
```

### Space Complexity

```text
O(1)
```

No additional data structure proportional to the input size is required.

---

# Key Concepts

* Binary Search
* Binary Search on Answer
* Greedy Allocation
* Contiguous Array Partitioning
* Minimize the Maximum
* Search Space Optimization

---

## Important Pattern

Whenever a problem asks:

> **Minimize the maximum possible value**

or

> **Maximize the minimum possible value**

and you can efficiently check whether a candidate answer is possible, consider using:

```text
Binary Search on Answer
```

For this problem:

```text
Search Space
     ↓
[max(arr), sum(arr)]
     ↓
Choose mid
     ↓
Can books be allocated with maxPages = mid?
     ↓
YES → Search smaller values
NO  → Search larger values
     ↓
Minimum valid answer
```
