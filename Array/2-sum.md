# 🔢 Two Sum

## Problem Statement

Given an integer array `nums` and an integer `target`, return the **indices** of the two numbers such that they add up to the target.

### Conditions

* Each input has **exactly one solution**.
* You **cannot use the same element twice**.
* The answer can be returned in **any order**.

---

## Example 1

### Input

```text
nums = [2, 7, 11, 15]
target = 9
```

### Output

```text
[0, 1]
```

### Explanation

```text
nums[0] + nums[1]
= 2 + 7
= 9
```

Hence, the answer is:

```text
[0, 1]
```

---

## Example 2

### Input

```text
nums = [3, 2, 4]
target = 6
```

### Output

```text
[1, 2]
```

### Explanation

```text
nums[1] + nums[2]
= 2 + 4
= 6
```

---

## Example 3

### Input

```text
nums = [3, 3]
target = 6
```

### Output

```text
[0, 1]
```

---

# Brute Force Approach

The simplest idea is to check **every possible pair** of elements.

For every element `i`, compare it with every element after it (`j = i + 1`).

If:

```text
nums[i] + nums[j] == target
```

then return the indices `{i, j}`.

---

# Algorithm

1. Traverse the array using index `i`.
2. For every `i`, traverse the remaining elements using index `j`.
3. Calculate:

```cpp
sum = nums[i] + nums[j];
```

4. If:

```text
sum == target
```

return:

```cpp
{i, j}
```

5. If no pair is found, return an empty vector.

---

# C++ Solution

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();

        for(int i = 0; i < n; i++) {

            for(int j = i + 1; j < n; j++) {

                int sum = nums[i] + nums[j];

                if(sum == target) {
                    return {i, j};
                }
            }
        }

        return {};
    }
};
```

---

# Dry Run

Consider:

```text
nums = [2, 7, 11, 15]
target = 9
```

### Initial State

```text
n = 4
```

---

### Iteration 1

```text
i = 0
nums[i] = 2
```

#### Compare with `j = 1`

```text
nums[j] = 7

sum = 2 + 7
    = 9
```

Since:

```text
9 == target
```

Return:

```text
{0, 1}
```

The algorithm stops immediately.

---

# Another Dry Run

```text
nums = [3, 2, 4]
target = 6
```

### i = 0

```text
3 + 2 = 5 ❌
```

```text
3 + 4 = 7 ❌
```

---

### i = 1

```text
2 + 4 = 6 ✅
```

Return:

```text
{1, 2}
```

---

# Visualization

```text
nums = [2, 7, 11, 15]

i = 0
        ↓

2   7   11   15
    ↑
    j

2 + 7 = 9 ✅

Return [0, 1]
```

---

# Complexity Analysis

Let:

```text
N = size of the array
```

### Time Complexity

Two nested loops:

```text
Outer Loop  → O(N)
Inner Loop  → O(N)
```

Overall:

```text
O(N²)
```

---

### Space Complexity

Only a few variables are used.

```text
O(1)
```

---

# Key Concepts

* Arrays
* Nested Loops
* Brute Force
* Pair Search

---

# Better Approach (Hash Map)

Instead of checking every pair, we can use a **Hash Map (`unordered_map`)**.

Store each number and its index while traversing the array.

For every element:

```text
complement = target - nums[i]
```

If the complement already exists in the hash map, return both indices immediately.

This reduces the complexity to:

```text
Time  : O(N)
Space : O(N)
```

---

# Comparison

| Approach                   | Time Complexity | Space Complexity |
| -------------------------- | --------------: | ---------------: |
| Brute Force (Nested Loops) |         `O(N²)` |           `O(1)` |
| Hash Map (`unordered_map`) |          `O(N)` |           `O(N)` |

---

# Learning Outcome

This brute-force solution is useful for understanding the problem and is often the first approach that comes to mind. However, for interviews and coding platforms like LeetCode, the **Hash Map approach** is preferred because it achieves **linear time complexity (`O(N)`)**.
