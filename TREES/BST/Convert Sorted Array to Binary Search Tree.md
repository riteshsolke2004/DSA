# 🌳 108. Convert Sorted Array to Binary Search Tree

[LeetCode — Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)

## Problem Statement

Given an integer array `nums` where the elements are sorted in **ascending order**, convert it into a **height-balanced Binary Search Tree (BST)**.

A binary tree is **height-balanced** when the height difference between the left and right subtrees of every node is at most `1`.

---

# What is a Binary Search Tree?

A **Binary Search Tree (BST)** follows this property:

```text
Left Subtree < Root < Right Subtree
```

For example:

```text
        0
       / \
     -3   9
     /   /
   -10   5
```

All values smaller than `0` are on the left, and larger values are on the right.

---

# What is a Height-Balanced Tree?

A tree is height-balanced when the left and right subtree heights differ by at most `1`.

For example:

```text
        0
       / \
     -3   9
     /   /
   -10   5
```

The tree is reasonably balanced.

We want to avoid creating a skewed tree like:

```text
-10
   \
   -3
      \
       0
        \
         5
          \
           9
```

The skewed tree behaves more like a linked list and is not height-balanced.

---

# Example 1
<img width="302" height="222" alt="btree1" src="https://github.com/user-attachments/assets/65cf27cb-1981-4b80-82e7-7dbe0f254b9d" />



### Input

```text
nums = [-10,-3,0,5,9]
```

### Output
<img width="302" height="222" alt="btree2" src="https://github.com/user-attachments/assets/2763ce46-836c-4537-ace9-438f85768276" />
```text
[0,-3,9,-10,null,5]
```

One possible tree:

```text
          0
        /   \
      -3     9
      /     /
   -10      5
```

Another valid answer is:

```text
        0
       / \
    -10   5
      \     \
      -3     9
```

Both are valid because the resulting trees are height-balanced BSTs.

---

# Example 2
<img width="342" height="142" alt="btree" src="https://github.com/user-attachments/assets/28abfd68-6108-4bf6-92af-1c9c12ec7735" />

### Input

```text
nums = [1,3]
```

### Output

```text
[3,1]
```

Tree:

```text
    3
   /
  1
```

This is also height-balanced.

Another valid tree is:

```text
1
 \
  3
```

Both are accepted.

---

# Main Approach

The array is already sorted:

```text
[-10,-3,0,5,9]
```

To create a balanced BST, choose the **middle element as the root**.

For:

```text
[-10,-3,0,5,9]
```

middle element:

```text
0
```

So:

```text
        0
```

The elements on the left become the left subtree:

```text
[-10,-3]
```

The elements on the right become the right subtree:

```text
[5,9]
```

Then repeat the same process recursively.

---

# Why Choose the Middle Element?

If we always choose the first element:

```text
[-10,-3,0,5,9]
```

we could get:

```text
-10
   \
   -3
      \
       0
        \
         5
          \
           9
```

This is highly unbalanced.

Instead, choosing the middle:

```text
        0
       / \
    -10   5
      \     \
      -3     9
```

keeps the number of nodes on both sides approximately equal.

Therefore:

> **Middle element → Balanced BST**

---

# Recursive Approach

We use three parameters:

```text
inorder → sorted array
s       → starting index
e       → ending index
```

For every recursive call:

### Step 1

Check if:

```text
s > e
```

If yes, there are no elements left.

Return:

```cpp
NULL
```

---

### Step 2

Find the middle index:

```cpp
mid = s + (e - s) / 2;
```

---

### Step 3

Create a node using:

```cpp
nums[mid]
```

---

### Step 4

Build the left subtree:

```cpp
solve(nums, s, mid - 1)
```

---

### Step 5

Build the right subtree:

```cpp
solve(nums, mid + 1, e)
```

---

# Code

```cpp
class Solution {
public:

    TreeNode* solve(vector<int>& nums, int s, int e) {

        if(s > e) {
            return NULL;
        }

        int mid = s + (e - s) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = solve(nums, s, mid - 1);

        root->right = solve(nums, mid + 1, e);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {

        int start = 0;
        int end = nums.size() - 1;

        return solve(nums, start, end);
    }
};
```

---

# Detailed Dry Run

Consider:

```text
nums = [-10,-3,0,5,9]
```

Indices:

```text
Index:   0    1   2  3  4
Value: -10  -3   0  5  9
```

Initially:

```text
s = 0
e = 4
```

---

## Step 1 — Root

Calculate:

```text
mid = 0 + (4 - 0) / 2
    = 2
```

Therefore:

```text
nums[2] = 0
```

Create:

```text
        0
```

Now recursively construct:

```text
Left  → indices 0 to 1
Right → indices 3 to 4
```

---

# Step 2 — Left Subtree

Call:

```text
solve(nums, 0, 1)
```

Calculate:

```text
mid = 0 + (1 - 0) / 2
    = 0
```

Therefore:

```text
nums[0] = -10
```

Create:

```text
        0
       /
     -10
```

Now:

```text
Left  → 0 to -1
Right → 1 to 1
```

---

# Step 3 — Left of -10

Call:

```text
solve(nums, 0, -1)
```

Since:

```text
s > e
```

we return:

```text
NULL
```

So:

```text
     -10
     /
   NULL
```

---

# Step 4 — Right of -10

Call:

```text
solve(nums, 1, 1)
```

Calculate:

```text
mid = 1
```

Therefore:

```text
nums[1] = -3
```

Create:

```text
      -10
        \
        -3
```

Both remaining ranges become invalid, so:

```text
-3
 / \
NULL NULL
```

Left subtree is now:

```text
    -10
       \
       -3
```

---

# Step 5 — Right Subtree of 0

Now process:

```text
solve(nums, 3, 4)
```

Calculate:

```text
mid = 3 + (4 - 3) / 2
    = 3
```

Therefore:

```text
nums[3] = 5
```

Create:

```text
        0
         \
          5
```

---

# Step 6 — Right of 5

Call:

```text
solve(nums, 4, 4)
```

Middle:

```text
mid = 4
```

Therefore:

```text
nums[4] = 9
```

Create:

```text
      5
       \
        9
```

---

# Final Tree

The final tree becomes:

```text
          0
        /   \
     -10     5
        \     \
        -3     9
```

This is a valid height-balanced BST.

---

# Recursion Visualization

The recursion looks like:

```text
[-10,-3,0,5,9]
          ↓
        mid = 2
          ↓
          0
        /   \
       /     \
 [-10,-3]   [5,9]
     ↓         ↓
   -10         5
     \          \
     -3          9
```

---

# Why Recursion Works

The same problem repeats on smaller arrays.

Initially:

```text
[-10,-3,0,5,9]
```

Then:

```text
[-10,-3]
```

and:

```text
[5,9]
```

Then:

```text
[-3]
```

and:

```text
[9]
```

This is a classic **Divide and Conquer** approach.

```text
             Array
               ↓
        Choose Middle
               ↓
        ┌──────┴──────┐
        ↓             ↓
   Left Half      Right Half
        ↓             ↓
      Repeat        Repeat
```

---

# Important Formula

Instead of:

```cpp
int mid = (s + e) / 2;
```

prefer:

```cpp
int mid = s + (e - s) / 2;
```

This is safer because it avoids potential integer overflow when `s` and `e` are very large.

---

# Why Is the Result a BST?

Because the input array is sorted.

For example:

```text
[-10,-3,0,5,9]
```

When we choose:

```text
0
```

as root:

```text
Left side:
[-10,-3]

Right side:
[5,9]
```

Every value on the left is smaller than `0`.

Every value on the right is greater than `0`.

The same property is maintained recursively.

Therefore, the resulting tree is a **Binary Search Tree**.

---

# Why Is the Result Height-Balanced?

At every step, we choose the middle element.

Therefore, approximately half the elements go to the left and half go to the right.

For example:

```text
              0
            /   \
          -10    5
             \    \
             -3    9
```

The number of nodes on both sides remains balanced.

---

# Edge Cases

## 1. Empty Array

```text
nums = []
```

Then:

```text
start = 0
end = -1
```

Since:

```text
start > end
```

return:

```text
NULL
```

---

## 2. One Element

```text
nums = [1]
```

Middle:

```text
mid = 0
```

Tree:

```text
1
```

---

## 3. Two Elements

```text
nums = [1,3]
```

Possible tree:

```text
    1
     \
      3
```

or:

```text
    3
   /
  1
```

Both are height-balanced BSTs.

---

# Common Mistakes

### ❌ Mistake 1 — Choosing First Element

Don't always choose:

```text
nums[s]
```

This can create a skewed tree.

Use the middle element.

---

### ❌ Mistake 2 — Wrong Base Case

Correct:

```cpp
if(s > e)
    return NULL;
```

---

### ❌ Mistake 3 — Wrong Left Range

Correct:

```cpp
root->left = solve(nums, s, mid - 1);
```

The middle element is already used as the root.

---

### ❌ Mistake 4 — Wrong Right Range

Correct:

```cpp
root->right = solve(nums, mid + 1, e);
```

---

### ❌ Mistake 5 — Passing the Vector by Value

Avoid:

```cpp
TreeNode* solve(vector<int> nums, ...)
```

because it copies the entire vector during every recursive call.

Prefer:

```cpp
TreeNode* solve(vector<int>& nums, ...)
```

This avoids unnecessary copying.

---

# Complexity Analysis

Let:

```text
N = number of elements in nums
```

Every element is used to create exactly one tree node.

Therefore:

### Time Complexity

```text
O(N)
```

Each element is processed once.

---

### Auxiliary Space

The recursion depth is approximately:

```text
O(log N)
```

because the tree is height-balanced.

Therefore:

```text
O(log N)
```

recursive stack space.

The created tree itself requires:

```text
O(N)
```

space.

---

# Approach Summary

```text
Sorted Array
     ↓
Find Middle Element
     ↓
Create Root
     ↓
Left Half → Left Subtree
     ↓
Right Half → Right Subtree
     ↓
Repeat Recursively
```

---

# Interview Explanation

If asked to explain the solution:

> "Since the array is sorted, I choose the middle element as the root of the BST. This guarantees that smaller elements are placed on the left and larger elements on the right. I then recursively apply the same process to the left and right halves of the array. Choosing the middle element at every step keeps the resulting BST height-balanced. The time complexity is `O(N)` and the recursion stack uses `O(log N)` space."

---

# Key Concepts

* Binary Search Tree
* Recursion
* Divide and Conquer
* Sorted Array
* Middle Element
* Height Balanced Tree
* Binary Tree
* Recursion Stack

---

# Quick Revision

Remember this pattern:

```text
Sorted Array
     ↓
   Middle
     ↓
   Root
   /  \
Left  Right
 ↓      ↓
Repeat Repeat
```

Core code:

```cpp
int mid = s + (e - s) / 2;

TreeNode* root = new TreeNode(nums[mid]);

root->left = solve(nums, s, mid - 1);

root->right = solve(nums, mid + 1, e);
```

---

# Final Code

```cpp
class Solution {
public:

    TreeNode* solve(vector<int>& nums, int s, int e) {

        if(s > e) {
            return NULL;
        }

        int mid = s + (e - s) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = solve(nums, s, mid - 1);

        root->right = solve(nums, mid + 1, e);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {

        int start = 0;
        int end = nums.size() - 1;

        return solve(nums, start, end);
    }
};
```

---

# Summary

| Feature         | Details                      |
| --------------- | ---------------------------- |
| Problem         | Convert Sorted Array to BST  |
| LeetCode        | 108                          |
| Difficulty      | Easy                         |
| Approach        | Recursion + Divide & Conquer |
| Main Idea       | Choose middle element        |
| Time Complexity | `O(N)`                       |
| Auxiliary Space | `O(log N)`                   |
| Data Structure  | Binary Search Tree           |
| Input           | Sorted Array                 |
| Output          | Height-Balanced BST          |

## 🧠 Final Takeaway

The entire problem is based on one simple idea:

> **For a sorted array, choose the middle element as the root and recursively build the left and right subtrees from the two halves.**

```text
[-10,-3,0,5,9]
       ↓
      0
     / \
 [-10,-3] [5,9]
     ↓       ↓
   -10       5
     \        \
     -3        9
```

**Sorted Array → Middle Element → BST → Recursion → Balanced Tree.** 🌳
