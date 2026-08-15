# 🔢 Merge Sorted Array

## Problem Statement

You are given two integer arrays `nums1` and `nums2`, sorted in **non-decreasing order**, and two integers `m` and `n`.

- `m` represents the number of valid elements in `nums1`.
- `n` represents the number of elements in `nums2`.
- `nums1` has a total length of `m + n`.
- Only the first `m` elements of `nums1` should initially be considered.
- The final merged array must be stored inside `nums1`.

---

# Examples

## Example 1

### Input

```text
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6], n = 3
```

### Output

```text
[1,2,2,3,5,6]
```

### Explanation

The valid arrays are:

```text
[1,2,3]
[2,5,6]
```

After merging:

```text
[1,2,2,3,5,6]
```

---

## Example 2

### Input

```text
nums1 = [1], m = 1
nums2 = [], n = 0
```

### Output

```text
[1]
```

### Explanation

There are no elements in `nums2`, so `nums1` remains unchanged.

---

## Example 3

### Input

```text
nums1 = [0], m = 0
nums2 = [1], n = 1
```

### Output

```text
[1]
```

### Explanation

Since `m = 0`, there are no valid elements in `nums1`. The `0` is only a placeholder.

---

# 💡 Approach: Two Pointers + Extra Array

The provided solution uses two pointers and an extra vector `ans`.

```text
i → nums1
j → nums2
```

Since both arrays are sorted, compare the current elements and place the smaller one into `ans`.

---

# 🧠 Algorithm

1. Create an empty vector `ans`.
2. Initialize `i = 0` and `j = 0`.
3. Compare `nums1[i]` and `nums2[j]`.
4. Add the smaller element to `ans`.
5. Move the corresponding pointer.
6. Copy remaining elements from `nums1`, if any.
7. Copy remaining elements from `nums2`, if any.
8. Copy `ans` back into `nums1`.

---

# 🔄 Approach Flow

```text
nums1 + nums2
      |
      v
Compare current elements
      |
      v
Choose smaller element
      |
      v
Store in ans
      |
      v
Copy remaining elements
      |
      v
Copy ans back to nums1
```

---

# 💻 Provided C++ Solution

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;

        int i = 0;
        int j = 0;

        while(i < m && j < n) {

            if(nums1[i] <= nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
            }
            else {
                ans.push_back(nums2[j]);
                j++;
            }
        }

        while(i < m) {
            ans.push_back(nums1[i]);
            i++;
        }

        while(j < n) {
            ans.push_back(nums2[j]);
            j++;
        }

        for(int i = 0; i < m + n; i++) {
            nums1[i] = ans[i];
        }
    }
};
```

---

# 🔍 Detailed Dry Run

Consider:

```text
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6], n = 3
```

Initially, only:

```text
nums1 = [1,2,3]
nums2 = [2,5,6]
```

are merged.

| Step | `nums1[i]` | `nums2[j]` | Added | `ans` |
|---|---:|---:|---:|---|
| 1 | 1 | 2 | 1 | `[1]` |
| 2 | 2 | 2 | 2 | `[1,2]` |
| 3 | 3 | 2 | 2 | `[1,2,2]` |
| 4 | 3 | 5 | 3 | `[1,2,2,3]` |
| Remaining | - | 5, 6 | 5, 6 | `[1,2,2,3,5,6]` |

Finally:

```text
nums1 = [1,2,2,3,5,6]
```

---

# 🧩 Why Use `m` Instead of `nums1.size()`?

`nums1` has a total size of:

```text
m + n
```

But only the first `m` elements are valid initially.

Example:

```text
nums1 = [1,2,3,0,0,0]
m = 3
```

The last `n` positions are placeholders.

Therefore:

```cpp
while(i < m && j < n)
```

is correct.

---

# 🧩 Why Are the Remaining Loops Needed?

The main loop stops when either array is exhausted.

The other array may still contain elements.

Therefore:

```cpp
while(i < m)
```

copies remaining elements from `nums1`.

And:

```cpp
while(j < n)
```

copies remaining elements from `nums2`.

---

# 🧩 Recursion Tree

This solution does not use recursion.

```text
Recursion Tree: Not Applicable
```

The approach is:

```text
Two Pointers + Extra Array
```

---

# ⏱️ Complexity Analysis

Let:

```text
m = number of valid elements in nums1
n = number of elements in nums2
```

## Time Complexity

Each element is processed once.

```text
Time Complexity: O(m + n)
```

## Space Complexity

The extra vector stores `m + n` elements.

```text
Space Complexity: O(m + n)
```

---

# ⚠️ Important Points

## Arrays Are Already Sorted

No additional sorting is needed.

## Equal Elements Are Handled Correctly

```cpp
if(nums1[i] <= nums2[j])
```

correctly handles duplicate values.

## Final Answer Must Be Stored in `nums1`

The solution copies the merged result back:

```cpp
nums1[i] = ans[i];
```

---

# 🚨 Common Mistakes

## Mistake 1: Treating Placeholder Values as Valid Elements

Use:

```cpp
i < m
```

not:

```cpp
i < nums1.size()
```

during merging.

## Mistake 2: Forgetting Remaining Elements

Always handle:

```cpp
while(i < m)
```

and:

```cpp
while(j < n)
```

## Mistake 3: Forgetting to Copy the Result Back

The problem requires modifying `nums1`.

---

# 🎯 Key Concepts

- Arrays
- Two Pointers
- Merging Sorted Arrays
- Extra Space
- Vector

---

# 🧠 Interview Notes

### Why is the two-pointer approach efficient?

Both arrays are already sorted, so only the current smallest unprocessed elements need to be compared.

### Can this be solved using `O(1)` extra space?

Yes. An optimized solution can merge from the end of `nums1`.

The provided solution uses an extra array, making the logic simple and beginner-friendly.

---

# ⭐ Quick Revision

```text
i = 0
j = 0

while both arrays have elements:
    compare nums1[i] and nums2[j]
    add smaller element to ans

copy remaining nums1 elements
copy remaining nums2 elements

copy ans back into nums1
```

---

# 📚 Related DSA Topics

- Arrays
- Two Pointers
- Sorting
- Merge Sort
- In-place Array Operations

---

# 🔗 Conclusion

The provided solution merges two sorted arrays using:

```text
Two Pointers + Extra Array
```

## Final Complexity

```text
Time Complexity  : O(m + n)
Space Complexity : O(m + n)
```

The approach is clean, efficient, and a great way to understand the standard merging technique used in sorted arrays and Merge Sort.
