# 🔢 18. 4Sum

[LeetCode — 4Sum](https://leetcode.com/problems/4sum/)

## Problem Statement

Given an integer array `nums` of size `n`, return all **unique quadruplets**:

```text
[nums[a], nums[b], nums[c], nums[d]]
```

such that:

```text
0 <= a, b, c, d < n
```

and:

```text
a, b, c, d are distinct
```

and:

```text
nums[a] + nums[b] + nums[c] + nums[d] == target
```

The answer can be returned in **any order**, but duplicate quadruplets are not allowed.

---

# Example 1

### Input

```text
nums = [1,0,-1,0,-2,2]
target = 0
```

### Output

```text
[[-2,-1,1,2],
 [-2,0,0,2],
 [-1,0,0,1]]
```

### Explanation

The valid quadruplets are:

```text
-2 + (-1) + 1 + 2 = 0

-2 + 0 + 0 + 2 = 0

-1 + 0 + 0 + 1 = 0
```

Therefore:

```text
[[-2,-1,1,2],
 [-2,0,0,2],
 [-1,0,0,1]]
```

---

# Example 2

### Input

```text
nums = [2,2,2,2,2]
target = 8
```

### Output

```text
[[2,2,2,2]]
```

Although there are many ways to select four `2`s, only one unique quadruplet is returned.

---

# Main Challenge

There are two important things to handle:

1. Find four numbers whose sum equals `target`.
2. Avoid duplicate quadruplets.

For example:

```text
[2,2,2,2,2]
```

should return:

```text
[[2,2,2,2]]
```

not multiple copies of the same quadruplet.

---

# Solution 1 — Brute Force

The most straightforward approach is to use **four nested loops**.

We select:

```text
i → first element
j → second element
k → third element
l → fourth element
```

Then calculate:

```text
nums[i] + nums[j] + nums[k] + nums[l]
```

If the sum equals `target`, store the quadruplet.

---

# Brute Force Approach

First sort the array:

```cpp
sort(nums.begin(), nums.end());
```

Sorting helps us:

* Handle duplicates easily.
* Keep quadruplets in sorted order.
* Make the output consistent.

Then use four loops.

---

# Duplicate Handling

For every pointer, skip duplicate values.

For `i`:

```cpp
if(i > 0 && nums[i] == nums[i - 1])
    continue;
```

For `j`:

```cpp
if(j > i + 1 && nums[j] == nums[j - 1])
    continue;
```

For `k`:

```cpp
if(k > j + 1 && nums[k] == nums[k - 1])
    continue;
```

For `l`:

```cpp
if(l > k + 1 && nums[l] == nums[l - 1])
    continue;
```

---

# Brute Force Code

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

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

                    for(int l = k + 1; l < n; l++) {

                        if(l > k + 1 && nums[l] == nums[l - 1]) {
                            continue;
                        }

                        long long sum =
                            (long long)nums[i]
                            + nums[j]
                            + nums[k]
                            + nums[l];

                        if(sum == target) {

                            ans.push_back({
                                nums[i],
                                nums[j],
                                nums[k],
                                nums[l]
                            });
                        }
                    }
                }
            }
        }

        return ans;
    }
};
```

---

# Why Use `long long`?

Consider large values:

```text
nums[i] = 1000000000
nums[j] = 1000000000
nums[k] = 1000000000
nums[l] = 1000000000
```

The sum becomes:

```text
4000000000
```

This can exceed the range of a normal `int`.

Therefore, use:

```cpp
long long sum;
```

or cast the first value:

```cpp
long long sum =
    (long long)nums[i] + nums[j] + nums[k] + nums[l];
```

This avoids integer overflow.

---

# Brute Force Complexity

There are four nested loops.

Therefore:

```text
Time Complexity = O(N⁴)
```

Sorting:

```text
O(N log N)
```

But the four loops dominate.

### Final Time Complexity

```text
O(N⁴)
```

### Extra Space

Ignoring the output:

```text
O(1)
```

---

# Solution 2 — Optimal Approach

The optimal approach is:

```text
Sorting + Two Fixed Elements + Two Pointers
```

The idea is similar to **3Sum**.

In 3Sum:

```text
Fix 1 element
+
Two pointers
```

In 4Sum:

```text
Fix 2 elements
+
Two pointers
```

So:

```text
4Sum
 ↓
Fix nums[i]
 ↓
Fix nums[j]
 ↓
Use two pointers
 ↓
Find nums[p] + nums[q]
```

---

# Pointer Structure

We use four indices:

```text
i → first element
j → second element
p → left pointer
q → right pointer
```

Initially:

```text
i = 0
j = i + 1
p = j + 1
q = n - 1
```

Calculate:

```text
sum = nums[i] + nums[j] + nums[p] + nums[q]
```

---

# Pointer Movement

Because the array is sorted:

### If `sum < target`

We need a larger sum.

Move:

```cpp
p++;
```

---

### If `sum > target`

We need a smaller sum.

Move:

```cpp
q--;
```

---

### If `sum == target`

We found a valid quadruplet.

Store:

```cpp
ans.push_back({
    nums[i],
    nums[j],
    nums[p],
    nums[q]
});
```

Then:

```cpp
p++;
q--;
```

Skip duplicates afterward.

---

# Why Sorting Is Important

Suppose the sorted array is:

```text
[-2,-1,0,0,1,2]
```

If:

```text
sum < target
```

moving `p` right gives us a larger number.

Therefore the sum increases.

If:

```text
sum > target
```

moving `q` left gives us a smaller number.

Therefore the sum decreases.

This is exactly why the two-pointer approach works.

---

# Optimal Code

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

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

                int p = j + 1;
                int q = n - 1;

                while(p < q) {

                    long long sum =
                        (long long)nums[i]
                        + nums[j]
                        + nums[p]
                        + nums[q];

                    if(sum == target) {

                        ans.push_back({
                            nums[i],
                            nums[j],
                            nums[p],
                            nums[q]
                        });

                        p++;
                        q--;

                        while(p < q && nums[p] == nums[p - 1]) {
                            p++;
                        }

                        while(p < q && nums[q] == nums[q + 1]) {
                            q--;
                        }
                    }

                    else if(sum < target) {
                        p++;
                    }

                    else {
                        q--;
                    }
                }
            }
        }

        return ans;
    }
};
```

---

# Detailed Dry Run

Consider:

```text
nums = [1,0,-1,0,-2,2]
target = 0
```

First sort:

```text
[-2,-1,0,0,1,2]
```

---

## Step 1 — `i = 0`

```text
nums[i] = -2
```

Now:

```text
i = 0
j = 1
p = 2
q = 5
```

Values:

```text
-2  -1   0   0   1   2
 ↑   ↑   ↑             ↑
 i   j   p             q
```

Calculate:

```text
-2 + (-1) + 0 + 2
= -1
```

Since:

```text
sum < target
```

move:

```text
p++
```

---

## Step 2

Now:

```text
p = 3
```

Calculate:

```text
-2 + (-1) + 0 + 2
= -1
```

Again:

```text
sum < 0
```

Move:

```text
p++
```

---

## Step 3

Now:

```text
p = 4
```

Calculate:

```text
-2 + (-1) + 1 + 2
= 0
```

Found:

```text
[-2,-1,1,2]
```

Store:

```text
ans = [
    [-2,-1,1,2]
]
```

Then:

```text
p++
q--
```

---

## Step 4 — Same `i`, next `j`

Now:

```text
j = 2
nums[j] = 0
```

Pointers:

```text
p = 3
q = 5
```

Calculate:

```text
-2 + 0 + 0 + 2
= 0
```

Found:

```text
[-2,0,0,2]
```

Store:

```text
ans = [
    [-2,-1,1,2],
    [-2,0,0,2]
]
```

Move:

```text
p++
q--
```

Now:

```text
p = 4
q = 4
```

Stop because:

```text
p >= q
```

---

# Step 5 — `i = 1`

Now:

```text
nums[i] = -1
```

Possible valid combination:

```text
-1 + 0 + 0 + 1 = 0
```

Therefore:

```text
[-1,0,0,1]
```

is added.

Final answer:

```text
[
    [-2,-1,1,2],
    [-2,0,0,2],
    [-1,0,0,1]
]
```

---

# Complete Pointer Pattern

```text
                 4Sum
                   ↓
             Sort the array
                   ↓
             Fix first (i)
                   ↓
             Fix second (j)
                   ↓
           Two pointers (p,q)
              ↙    ↓    ↘
          <target =target >target
             ↓       ↓       ↓
            p++    store    q--
                     ↓
                 p++, q--
                     ↓
              Skip duplicates
```

---

# Difference Between 3Sum and 4Sum

### 3Sum

```text
Fix 1 element
      ↓
Two pointers
```

Complexity:

```text
O(N²)
```

---

### 4Sum

```text
Fix 2 elements
      ↓
Two pointers
```

Complexity:

```text
O(N³)
```

This is a very useful pattern to remember.

---

# Complexity Comparison

| Approach    | Time Complexity | Extra Space |
| ----------- | --------------: | ----------: |
| Brute Force |         `O(N⁴)` |      `O(1)` |
| Optimal     |         `O(N³)` |      `O(1)` |

Sorting requires:

```text
O(N log N)
```

but it is dominated by the main algorithm.

Therefore:

### Optimal Time

```text
O(N³)
```

### Extra Space

```text
O(1)
```

excluding the output array.

---

# Important Duplicate Handling

There are **four positions**, so duplicate handling is important.

### For `i`

```cpp
if(i > 0 && nums[i] == nums[i - 1])
    continue;
```

### For `j`

```cpp
if(j > i + 1 && nums[j] == nums[j - 1])
    continue;
```

### For `p`

After finding a quadruplet:

```cpp
while(p < q && nums[p] == nums[p - 1])
    p++;
```

### For `q`

```cpp
while(p < q && nums[q] == nums[q + 1])
    q--;
```

This ensures every quadruplet appears only once.

---

# Example — Duplicate Values

Consider:

```text
nums = [2,2,2,2,2]
target = 8
```

Sorted:

```text
[2,2,2,2,2]
```

The only possible unique answer is:

```text
[[2,2,2,2]]
```

Without duplicate handling, the same quadruplet would be inserted many times.

---

# Common Mistakes

### ❌ Mistake 1 — Using `int` for Sum

Don't rely on:

```cpp
int sum
```

when values can be large.

Use:

```cpp
long long sum
```

---

### ❌ Mistake 2 — Forgetting to Sort

Two pointers require a sorted array:

```cpp
sort(nums.begin(), nums.end());
```

---

### ❌ Mistake 3 — Not Skipping Duplicate `i`

Use:

```cpp
if(i > 0 && nums[i] == nums[i - 1])
    continue;
```

---

### ❌ Mistake 4 — Not Skipping Duplicate `j`

Use:

```cpp
if(j > i + 1 && nums[j] == nums[j - 1])
    continue;
```

---

### ❌ Mistake 5 — Wrong Pointer Movement

Remember:

```text
sum < target → p++
sum > target → q--
sum == target → store + p++ + q--
```

---

# Interview Explanation

If asked to explain the optimal solution:

> "First, I sort the array to enable the two-pointer technique and handle duplicates easily. Then I fix two elements using two nested loops. For the remaining two elements, I use two pointers, one from the left and one from the right. If the sum is smaller than the target, I move the left pointer forward. If the sum is greater, I move the right pointer backward. When the sum equals the target, I store the quadruplet and move both pointers while skipping duplicates. The overall time complexity is `O(N³)`."

---

# Key Concepts

* Arrays
* Sorting
* Two Pointers
* Nested Loops
* Duplicate Handling
* `long long`
* 2Sum Pattern
* 3Sum Pattern
* 4Sum Pattern

---

# Quick Revision

### 4Sum Pattern

```text
4Sum
 ↓
Sort
 ↓
Fix i
 ↓
Fix j
 ↓
Two Pointers
 ↓
p + q
```

### Pointer Rules

```text
sum < target
      ↓
     p++

sum > target
      ↓
     q--

sum == target
      ↓
   store answer
      ↓
    p++, q--
```

### Complexity

```text
Brute Force → O(N⁴)

Optimal     → O(N³)
```

---

# Final Recommended Code

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

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

                int p = j + 1;
                int q = n - 1;

                while(p < q) {

                    long long sum =
                        (long long)nums[i]
                        + nums[j]
                        + nums[p]
                        + nums[q];

                    if(sum < target) {
                        p++;
                    }

                    else if(sum > target) {
                        q--;
                    }

                    else {

                        ans.push_back({
                            nums[i],
                            nums[j],
                            nums[p],
                            nums[q]
                        });

                        p++;
                        q--;

                        while(p < q && nums[p] == nums[p - 1]) {
                            p++;
                        }

                        while(p < q && nums[q] == nums[q + 1]) {
                            q--;
                        }
                    }
                }
            }
        }

        return ans;
    }
};
```

---

# 🧠 Final Takeaway

The easiest way to remember **4Sum** is:

```text
2Sum → 1 loop + Hash Map / Two Pointer
3Sum → 1 loop + Two Pointer
4Sum → 2 loops + Two Pointer
```

So the progression is:

```text
2Sum → O(N)
3Sum → O(N²)
4Sum → O(N³)
```

The key idea is **reduce the problem by fixing elements and using two pointers for the remaining pair**. 🚀
