 # 🔢 46. Permutations

## Problem Statement

Given an array `nums` of **distinct integers**, return all possible **permutations** of the array.

A permutation is a different arrangement of all the elements.

You can return the answer in **any order**. 

### What is Given? 

- An array `nums` containing distinct integers.

### What Needs to Be Returned?

Return all possible arrangements of the elements of `nums`.

### Important Conditions

- Every permutation contains all elements exactly once.
- The answer can be returned in any order.

---

# Examples

## Example 1

### Input

```text
nums = [1,2,3]
```

### Output

```text
[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

### Explanation

For `3` distinct elements:

```text
3! = 6
```

possible permutations exist.

---

## Example 2

### Input

```text
nums = [0,1]
```

### Output

```text
[[0,1],[1,0]]
```

### Explanation

There are:

```text
2! = 2
```

possible arrangements.

---

## Example 3

### Input

```text
nums = [1]
```

### Output

```text
[[1]]
```

### Explanation

Only one permutation is possible.

---

# 💡 Approach: Backtracking Using Swapping

The provided solution uses **Backtracking**.

At each index `i`, we try every remaining element at that position by swapping.

After exploring that choice recursively, we swap again to restore the previous state.

```text
Choose
   ↓
Explore recursively
   ↓
Undo the choice
   ↓
Try the next choice
```

---

# 🧠 Algorithm

1. Start from index `0`.
2. If `i == nums.size()`, a complete permutation is formed.
3. Add the current array to `ans`.
4. Loop from `j = i` to `nums.size() - 1`.
5. Swap `nums[i]` with `nums[j]`.
6. Recursively call `solve(i + 1)`.
7. Swap again to backtrack.
8. Return all permutations.

---

# 💻 Provided C++ Solution

```cpp
class Solution {
public:
    void solve(int i, vector<int>& nums, vector<vector<int>>& ans) {

        if(i == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for(int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            solve(i + 1, nums, ans);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int i = 0;

        solve(i, nums, ans);

        return ans;
    }
};
```

---

# 🔍 Detailed Dry Run

Consider:

```text
nums = [1,2,3]
```

At index `0`, try every element.

## Fix `1` at Index 0

```text
[1,2,3]
```

Generate permutations of the remaining positions:

```text
[1,2,3]
[1,3,2]
```

## Fix `2` at Index 0

```text
[2,1,3]
```

Generate:

```text
[2,1,3]
[2,3,1]
```

## Fix `3` at Index 0

Generate:

```text
[3,2,1]
[3,1,2]
```

All permutations:

```text
[1,2,3]
[1,3,2]
[2,1,3]
[2,3,1]
[3,2,1]
[3,1,2]
```

---

# 🌳 Recursion Tree

```text
solve(0)
│
├── Fix 1
│   ├── Fix 2 → [1,2,3]
│   └── Fix 3 → [1,3,2]
│
├── Fix 2
│   ├── Fix 1 → [2,1,3]
│   └── Fix 3 → [2,3,1]
│
└── Fix 3
    ├── Fix 2 → [3,2,1]
    └── Fix 1 → [3,1,2]
```

---

# 🔙 Understanding Backtracking

The key part is:

```cpp
swap(nums[i], nums[j]);
solve(i + 1, nums, ans);
swap(nums[i], nums[j]);
```

The first swap makes a choice.

The recursive call explores that choice.

The second swap restores the original array before trying the next choice.

---

# 🧩 Base Case

```cpp
if(i == nums.size()) {
    ans.push_back(nums);
    return;
}
```

When `i` reaches `nums.size()`, every position has been fixed.

Therefore, the current array is one complete permutation.

---

# 📊 Number of Permutations

For `n` distinct elements:

```text
Total Permutations = n!
```

| Elements | Permutations |
|---:|---:|
| 1 | 1 |
| 2 | 2 |
| 3 | 6 |
| 4 | 24 |
| 5 | 120 |

---

# ⏱️ Complexity Analysis

Let:

```text
n = nums.size()
```

There are `n!` possible permutations.

## Time Complexity

```text
O(n × n!)
```

There are `n!` permutations, and storing each permutation takes `O(n)`.

## Space Complexity

### Recursion Stack

```text
O(n)
```

### Output Storage

```text
O(n × n!)
```

---

# ⚠️ Important Points

## Why Do We Swap Back?

Without:

```cpp
swap(nums[i], nums[j]);
```

after recursion, the array would remain modified and the next branch would not start from the correct previous state.

## Why Does `j` Start From `i`?

Positions before `i` are already fixed.

So:

```cpp
for(int j = i; j < nums.size(); j++)
```

tries only the remaining elements.

---

# 🚨 Common Mistakes

## Forgetting Backtracking

Incorrect:

```cpp
swap(nums[i], nums[j]);
solve(i + 1, nums, ans);
```

Correct:

```cpp
swap(nums[i], nums[j]);
solve(i + 1, nums, ans);
swap(nums[i], nums[j]);
```

## Wrong Base Case

The correct base case is:

```cpp
i == nums.size()
```

## Starting `j` From 0

Incorrect:

```cpp
for(int j = 0; j < nums.size(); j++)
```

Correct:

```cpp
for(int j = i; j < nums.size(); j++)
```

---

# 🎯 Key Concepts

- Arrays
- Recursion
- Backtracking
- Swapping
- Decision Tree
- Permutations

---

# 🧠 Interview Notes

### What technique is used?

```text
Backtracking
```

### How many permutations exist for `n` distinct elements?

```text
n!
```

### Why is the swap undone?

To restore the previous state and explore the next choice.

### What is the recursion depth?

```text
O(n)
```

---

# ⭐ Quick Revision

```text
solve(i):

    if i == n:
        store nums
        return

    for j from i to n - 1:

        swap(nums[i], nums[j])

        solve(i + 1)

        swap(nums[i], nums[j])
```

---

# 📚 Related DSA Topics

- Recursion
- Backtracking
- Arrays
- Swapping
- Subsets
- Combinations
- N-Queens
- Rat in a Maze

---

# 🔗 Conclusion

The provided solution generates all possible permutations using **Backtracking with Swapping**.

```text
1. Fix an element at the current index.
2. Recursively generate permutations for the remaining positions.
3. Undo the swap.
4. Try the next element.
```

## Final Complexity

```text
Time Complexity  : O(n × n!)
Auxiliary Space  : O(n)
Output Space     : O(n × n!)
```

This is a clean and standard approach for understanding **Recursion and Backtracking**.
