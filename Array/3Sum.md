# 🔢 15. 3Sum

[LeetCode — 3Sum](https://leetcode.com/problems/3sum/)

## Problem Statement

Given an integer array `nums`, return all unique triplets:

```text
[nums[i], nums[j], nums[k]]
```

such that:

```text
i != j
i != k
j != k
```

and:

```text
nums[i] + nums[j] + nums[k] == 0
```

The solution must **not contain duplicate triplets**.

The order of the triplets and the order of elements inside a triplet does not matter.

---

# Example 1

### Input

```text
nums = [-1,0,1,2,-1,-4]
```

### Output

```text
[[-1,-1,2],[-1,0,1]]
```

### Explanation

The valid combinations are:

```text
-1 + 0 + 1 = 0
-1 + -1 + 2 = 0
```

Therefore:

```text
[[-1,-1,2],[-1,0,1]]
```

---

# Example 2

### Input

```text
nums = [0,1,1]
```

### Output

```text
[]
```

Explanation:

```text
0 + 1 + 1 = 2
```

Since the sum is not `0`, there is no valid triplet.

---

# Example 3

### Input

```text
nums = [0,0,0]
```

### Output

```text
[[0,0,0]]
```

Explanation:

```text
0 + 0 + 0 = 0
```

Only one unique triplet is returned.

---

# Main Challenge

The main challenge is **avoiding duplicate triplets**.

For example:

```text
nums = [-1,0,1,2,-1,-4]
```

There are multiple ways to select:

```text
[-1,0,1]
```

but we only want to return it once.

Therefore, we need to carefully skip duplicate values.

---

# Solution 1 — Two Pointer Approach

The best approach is:

```text
Sorting + Two Pointers
```

First sort the array.

For:

```text
[-1,0,1,2,-1,-4]
```

after sorting:

```text
[-4,-1,-1,0,1,2]
```

Now fix one element and use two pointers to find the other two elements.

---

# How Two Pointers Work

Suppose:

```text
i = fixed element
j = left pointer
k = right pointer
```

We calculate:

```text
sum = nums[i] + nums[j] + nums[k]
```

### Case 1 — `sum < 0`

The sum is too small.

We need a larger value.

Move:

```text
j++
```

---

### Case 2 — `sum > 0`

The sum is too large.

We need a smaller value.

Move:

```text
k--
```

---

### Case 3 — `sum == 0`

We found a valid triplet.

Store it:

```cpp
ans.push_back({nums[i], nums[j], nums[k]});
```

Then move both pointers:

```text
j++
k--
```

and skip duplicate values.

---

# Why Sorting Helps

Sorting gives us a very useful property.

Example:

```text
[-4,-1,-1,0,1,2]
```

When:

```text
sum < 0
```

we know moving `j` to the right increases the value.

When:

```text
sum > 0
```

we know moving `k` to the left decreases the value.

Without sorting, this two-pointer technique would not work.

---

# Detailed Dry Run

Consider:

```text
nums = [-1,0,1,2,-1,-4]
```

After sorting:

```text
[-4,-1,-1,0,1,2]
```

---

## Step 1 — `i = 0`

```text
nums[i] = -4
```

Pointers:

```text
i       j             k
↓       ↓             ↓
-4     -1    -1    0    1    2
```

Calculate:

```text
-4 + (-1) + 2 = -3
```

Since:

```text
sum < 0
```

move:

```text
j++
```

---

### Continue

```text
-4 + (-1) + 2 = -3
```

Again:

```text
j++
```

Now:

```text
-4 + 0 + 2 = -2
```

Move `j`.

```text
-4 + 1 + 2 = -1
```

No valid triplet for `-4`.

---

# Step 2 — `i = 1`

Now:

```text
nums[i] = -1
```

Pointers:

```text
i   j                 k
↓   ↓                 ↓
-4  -1  -1  0  1  2
    ↑               ↑
```

Actually, after fixing the first `-1`:

```text
i = 1
j = 2
k = 5
```

Calculate:

```text
-1 + (-1) + 2 = 0
```

Found:

```text
[-1,-1,2]
```

Store:

```text
ans = [[-1,-1,2]]
```

Move:

```text
j++
k--
```

Now:

```text
j = 3
k = 4
```

Calculate:

```text
-1 + 0 + 1 = 0
```

Found:

```text
[-1,0,1]
```

Store:

```text
ans = [
    [-1,-1,2],
    [-1,0,1]
]
```

Move:

```text
j++
k--
```

Now:

```text
j >= k
```

Stop this iteration.

---

# Step 3 — `i = 2`

Here:

```text
nums[i] = -1
```

But:

```text
nums[2] == nums[1]
```

So this is a duplicate fixed value.

Skip:

```cpp
if(i > 0 && nums[i] == nums[i - 1])
    continue;
```

This prevents duplicate triplets.

---

# Step 4 — `i = 3`

```text
nums[i] = 0
```

Pointers:

```text
j = 4
k = 5
```

Calculate:

```text
0 + 1 + 2 = 3
```

Since:

```text
sum > 0
```

move:

```text
k--
```

Now:

```text
j >= k
```

Stop.

---

# Final Answer

```text
[[-1,-1,2],[-1,0,1]]
```

---

# Duplicate Handling

There are two important duplicate checks.

## Duplicate `i`

```cpp
if(i > 0 && nums[i] == nums[i-1]) {
    continue;
}
```

Example:

```text
[-1,-1,0,1]
```

When processing the second `-1`, we skip it.

---

## Duplicate `j`

After finding a valid triplet:

```cpp
j++;
k--;
```

Then skip duplicate values:

```cpp
while(j < k && nums[j] == nums[j-1]) {
    j++;
}
```

This prevents returning the same triplet multiple times.

---

# Solution 1 — C++ Code

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {

            // Skip duplicate first elements
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int j = i + 1;
            int k = n - 1;

            while(j < k) {

                int sum = nums[i] + nums[j] + nums[k];

                if(sum < 0) {
                    j++;
                }

                else if(sum > 0) {
                    k--;
                }

                else {

                    ans.push_back({
                        nums[i],
                        nums[j],
                        nums[k]
                    });

                    j++;
                    k--;

                    // Skip duplicate second elements
                    while(j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                }
            }
        }

        return ans;
    }
};
```

---

# Solution 2 — Brute Force

The brute-force approach uses **three nested loops**.

We check every possible combination:

```text
i
 ↓
j
 ↓
k
```

For every combination:

```text
nums[i] + nums[j] + nums[k]
```

is calculated.

If the sum is `0`, we add the triplet.

Because duplicates are not allowed, we first sort the array and skip duplicate values.

---

# Brute Force Code

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {

            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for(int j = i + 1; j < n; j++) {

                if(j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                for(int k = j + 1; k < n; k++) {

                    if(k > j + 1 && nums[k] == nums[k - 1]) {
                        continue;
                    }

                    int sum = nums[i] + nums[j] + nums[k];

                    if(sum == 0) {

                        ans.push_back({
                            nums[i],
                            nums[j],
                            nums[k]
                        });
                    }
                }
            }
        }

        return ans;
    }
};
```

---

# Brute Force Complexity

There are three nested loops.

Therefore:

### Time Complexity

```text
O(N³)
```

Sorting takes:

```text
O(N log N)
```

but the three loops dominate.

Overall:

```text
O(N³)
```

### Space Complexity

Ignoring the output:

```text
O(1)
```

---

# Solution 3 — Optimal Two Pointer

The optimal approach combines:

```text
Sorting
+
Two Pointers
```

Instead of checking every combination with three loops, we fix one element and solve the remaining **2 Sum problem** using two pointers.

Conceptually:

```text
3 Sum
  ↓
Fix nums[i]
  ↓
Find two numbers
  ↓
Two Pointer
```

---

# Optimal C++ Code

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {

            // Skip duplicate first values
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int j = i + 1;
            int k = n - 1;

            while(j < k) {

                int sum = nums[i] + nums[j] + nums[k];

                if(sum < 0) {
                    j++;
                }

                else if(sum > 0) {
                    k--;
                }

                else {

                    ans.push_back({
                        nums[i],
                        nums[j],
                        nums[k]
                    });

                    j++;
                    k--;

                    // Skip duplicate values
                    while(j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                }
            }
        }

        return ans;
    }
};
```

---

# Why Is the Optimal Approach `O(N²)`?

The outer loop runs:

```text
O(N)
```

For each fixed `i`, the two pointers move toward each other.

`j` moves only forward and `k` moves only backward.

Therefore, the inner two-pointer traversal is:

```text
O(N)
```

So:

```text
O(N) × O(N)
```

gives:

```text
O(N²)
```

Sorting adds:

```text
O(N log N)
```

Therefore the final complexity is:

```text
O(N²)
```

---

# Complexity Comparison

| Approach    | Time Complexity | Space Complexity |
| ----------- | --------------: | ---------------: |
| Brute Force |         `O(N³)` |           `O(1)` |
| Two Pointer |         `O(N²)` |           `O(1)` |
| Sorting     |    `O(N log N)` |           `O(1)` |

The **Two Pointer approach** is the recommended solution.

---

# Why We Don't Use `unordered_set`

A hash-set solution can also be designed, but the sorted two-pointer approach is cleaner for this problem because:

* Duplicate handling becomes easier.
* The array is sorted.
* We can move pointers based on the sum.
* No additional hash data structure is required.

---

# Important Two Pointer Rule

After sorting:

```text
sum < 0
```

means:

```text
Need a larger value
      ↓
Move LEFT pointer
```

So:

```cpp
j++;
```

When:

```text
sum > 0
```

means:

```text
Need a smaller value
      ↓
Move RIGHT pointer
```

So:

```cpp
k--;
```

Remember:

```text
sum < 0  → j++
sum > 0  → k--
sum == 0 → store + move both
```

---

# Visual Representation

Sorted array:

```text
[-4, -1, -1, 0, 1, 2]
        ↑         ↑
        j         k
```

Fixed element:

```text
i
↓
-4  -1  -1  0  1  2
```

Calculate:

```text
nums[i] + nums[j] + nums[k]
```

Then adjust pointers.

---

# Edge Cases

## 1. Empty Array

```text
nums = []
```

Output:

```text
[]
```

---

## 2. Less Than 3 Elements

```text
nums = [1,2]
```

No triplet is possible.

Output:

```text
[]
```

---

## 3. All Zeros

```text
nums = [0,0,0]
```

Output:

```text
[[0,0,0]]
```

Duplicate handling ensures it appears only once.

---

## 4. All Positive

```text
nums = [1,2,3,4]
```

No three numbers can sum to `0`.

Output:

```text
[]
```

---

## 5. All Negative

```text
nums = [-5,-4,-3,-2]
```

No three numbers can sum to `0`.

Output:

```text
[]
```

---

# Common Mistakes

### ❌ Mistake 1 — Not Sorting

The two-pointer approach requires a sorted array.

Always:

```cpp
sort(nums.begin(), nums.end());
```

---

### ❌ Mistake 2 — Not Skipping Duplicate `i`

Use:

```cpp
if(i > 0 && nums[i] == nums[i - 1])
    continue;
```

---

### ❌ Mistake 3 — Forgetting Duplicate `j`

After finding a triplet:

```cpp
j++;
k--;
```

then skip duplicates:

```cpp
while(j < k && nums[j] == nums[j - 1])
    j++;
```

---

### ❌ Mistake 4 — Moving the Wrong Pointer

Remember:

```text
sum < 0 → j++
```

because we need a bigger value.

```text
sum > 0 → k--
```

because we need a smaller value.

---

### ❌ Mistake 5 — Using Three Loops for Optimal Solution

Three nested loops give:

```text
O(N³)
```

Use:

```text
Sorting + Two Pointers
```

for:

```text
O(N²)
```

---

# Interview Explanation

If asked to explain the optimal solution:

> "First, I sort the array so that I can use the two-pointer technique and easily handle duplicates. I fix one element using index `i`, then use two pointers `j` and `k` on the remaining part of the array. If the sum is less than zero, I move `j` forward to increase the sum. If the sum is greater than zero, I move `k` backward to decrease the sum. When the sum becomes zero, I store the triplet and move both pointers while skipping duplicates. The overall time complexity is `O(N²)`."

---

# Key Concepts

* Arrays
* Sorting
* Two Pointers
* Duplicate Handling
* 2 Sum Pattern
* Nested Loops
* Time Complexity Optimization

---

# Quick Revision

The complete pattern:

```text
              3 SUM
                ↓
              SORT
                ↓
          Fix one element
                ↓
         Two Pointer Search
           ↙           ↘
       sum < 0       sum > 0
          ↓             ↓
         j++           k--
                ↓
             sum == 0
                ↓
          Store triplet
                ↓
       Skip duplicates
```

### Pointer Rules

```text
sum < 0   → left++
sum > 0   → right--
sum == 0  → store + left++ + right--
```

### Duplicate Rule

```cpp
if(i > 0 && nums[i] == nums[i - 1])
    continue;
```

---

# Final Recommended Solution

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {

            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int j = i + 1;
            int k = n - 1;

            while(j < k) {

                int sum = nums[i] + nums[j] + nums[k];

                if(sum < 0) {
                    j++;
                }

                else if(sum > 0) {
                    k--;
                }

                else {

                    ans.push_back({
                        nums[i],
                        nums[j],
                        nums[k]
                    });

                    j++;
                    k--;

                    while(j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                }
            }
        }

        return ans;
    }
};
```

---

# Summary

| Feature        | Details                  |
| -------------- | ------------------------ |
| Problem        | 3Sum                     |
| LeetCode       | 15                       |
| Difficulty     | Medium                   |
| Main Approach  | Sorting + Two Pointers   |
| Brute Force    | `O(N³)`                  |
| Optimal        | `O(N²)`                  |
| Extra Space    | `O(1)` excluding output  |
| Main Challenge | Avoid duplicate triplets |
| Pointer 1      | `j = i + 1`              |
| Pointer 2      | `k = n - 1`              |
| `sum < 0`      | `j++`                    |
| `sum > 0`      | `k--`                    |
| `sum == 0`     | Store triplet            |

## 🧠 Remember

**3Sum is basically 2Sum repeated `N` times.**

```text
3Sum
 ↓
Sort
 ↓
Fix one number
 ↓
Use two pointers for remaining two
 ↓
Skip duplicates
 ↓
O(N²)
```

Once you understand **Two Sum + Two Pointers**, 3Sum becomes much easier. 🚀
