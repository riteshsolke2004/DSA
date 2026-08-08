# 🌳  Path Sum II

## Problem Statement

Given the `root` of a binary tree and an integer `targetSum`, return **all root-to-leaf paths** where the sum of the node values in the path is equal to `targetSum`.

Each path should contain the **node values**, not the node references.

A **root-to-leaf path**:

* Starts from the **root**.
* Ends at a **leaf node**.
* Contains every node between the root and leaf.

A **leaf node** is a node with:

```text
left == NULL
right == NULL
```

---

# Example 1
<img width="592" height="421" alt="pathsumii1" src="https://github.com/user-attachments/assets/92829399-aaf5-4371-b0a5-857553a02028" />

### Input

```text
root = [5,4,8,11,null,13,4,7,2,null,null,5,1]

targetSum = 22
```

Binary Tree:

```text
              5
            /   \
           4     8
          /     / \
        11     13  4
       /  \       / \
      7    2     5   1
```

There are two valid root-to-leaf paths.

### Path 1

```text
5 → 4 → 11 → 2
```

Sum:

```text
5 + 4 + 11 + 2 = 22
```

### Path 2

```text
5 → 8 → 4 → 5
```

Sum:

```text
5 + 8 + 4 + 5 = 22
```

### Output

```text
[[5,4,11,2],[5,8,4,5]]
```

---

# Example 2
<img width="212" height="181" alt="pathsum2" src="https://github.com/user-attachments/assets/bbb12b3d-6dd8-480d-a061-d805db881b79" />

### Input

```text
root = [1,2,3]

targetSum = 5
```

Tree:

```text
      1
     / \
    2   3
```

Possible paths:

```text
1 → 2
```

Sum:

```text
1 + 2 = 3
```

And:

```text
1 → 3
```

Sum:

```text
1 + 3 = 4
```

No path has sum `5`.

### Output

```text
[]
```

---

# Example 3

### Input

```text
root = [1,2]

targetSum = 0
```

Tree:

```text
    1
   /
  2
```

Only root-to-leaf path:

```text
1 → 2
```

Sum:

```text
1 + 2 = 3
```

It does not equal `0`.

### Output

```text
[]
```

---

# Approach — DFS + Backtracking

This problem can be solved using:

```text
DFS + Recursion + Backtracking
```

We maintain two important vectors:

```cpp
vector<int> path;
vector<vector<int>> ans;
```

### `path`

Stores the current root-to-current-node path.

For example:

```text
5 → 4 → 11
```

then:

```text
path = [5,4,11]
```

### `ans`

Stores all valid paths.

For example:

```text
ans = [
    [5,4,11,2],
    [5,8,4,5]
]
```

---

# Main Idea

At every node:

1. Add the current node value to `sum`.
2. Add the current node to `path`.
3. Check whether the node is a leaf.
4. If it is a leaf and `sum == targetSum`, save the current path.
5. Recursively explore the left subtree.
6. Recursively explore the right subtree.
7. Remove the current node from `path` using `pop_back()`.

The pattern is:

```text
PUSH
  ↓
EXPLORE
  ↓
POP
```

This is called **Backtracking**.

---

# Why Do We Need Backtracking?

Suppose we have:

```text
        5
       / \
      4   8
     /
    11
   /  \
  7    2
```

When exploring:

```text
5 → 4 → 11 → 7
```

our path becomes:

```text
[5,4,11,7]
```

After finishing node `7`, we return to node `11`.

Now we want to explore node `2`.

Before doing that, we must remove `7`:

```cpp
path.pop_back();
```

Now:

```text
[5,4,11]
```

Then add `2`:

```text
path.push_back(2);
```

Now:

```text
[5,4,11,2]
```

Correct!

Without `pop_back()` we would incorrectly get:

```text
[5,4,11,7,2] ❌
```

So:

```text
Enter node → push
Leave node  → pop
```

---

# C++ Solution

```cpp
class Solution {
public:

    void solve(TreeNode* root, int targetSum, int sum,
               vector<int>& path,
               vector<vector<int>>& ans) {

        // Base case
        if(root == NULL) {
            return;
        }

        // Add current node value
        sum += root->val;

        // Add current node to current path
        path.push_back(root->val);

        // Check leaf node
        if(root->left == NULL && root->right == NULL) {

            if(sum == targetSum) {
                ans.push_back(path);
            }
        }

        // Explore left subtree
        solve(root->left, targetSum, sum, path, ans);

        // Explore right subtree
        solve(root->right, targetSum, sum, path, ans);

        // Backtracking
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<vector<int>> ans;
        vector<int> path;

        solve(root, targetSum, 0, path, ans);

        return ans;
    }
};
```

---

# Detailed Explanation

## Step 1 — Base Case

```cpp
if(root == NULL) {
    return;
}
```

If there is no node, there is nothing to process.

---

## Step 2 — Add Node Value

```cpp
sum += root->val;
```

For example:

```text
5 → 4 → 11
```

The running sum becomes:

```text
5
5 + 4 = 9
9 + 11 = 20
```

---

## Step 3 — Add Node to Path

```cpp
path.push_back(root->val);
```

For:

```text
5 → 4 → 11
```

we have:

```text
path = [5,4,11]
```

---

# Step 4 — Check Leaf

```cpp
if(root->left == NULL && root->right == NULL)
```

This confirms that the current node is a leaf.

Only a **root-to-leaf** path is valid.

If it is a leaf:

```cpp
if(sum == targetSum) {
    ans.push_back(path);
}
```

We copy the current path into `ans`.

---

# Step 5 — Explore Left

```cpp
solve(root->left, targetSum, sum, path, ans);
```

This explores all paths through the left subtree.

---

# Step 6 — Explore Right

```cpp
solve(root->right, targetSum, sum, path, ans);
```

This explores all paths through the right subtree.

---

# Step 7 — Backtracking

After both subtrees have been explored:

```cpp
path.pop_back();
```

This removes the current node from the path.

This is necessary so that the parent can explore its other branch correctly.

---

# Complete Dry Run

Consider:

```text
              5
            /   \
           4     8
          /     / \
        11     13  4
       /  \       / \
      7    2     5   1
```

Target:

```text
22
```

---

## Start

```text
sum = 0
path = []
ans = []
```

---

## Node 5

Add `5`:

```text
sum = 5
path = [5]
```

Not a leaf.

Go left.

---

## Node 4

```text
sum = 5 + 4 = 9
path = [5,4]
```

Not a leaf.

Go left.

---

## Node 11

```text
sum = 9 + 11 = 20
path = [5,4,11]
```

Not a leaf.

First explore `7`.

---

## Node 7

```text
sum = 20 + 7 = 27
path = [5,4,11,7]
```

`7` is a leaf.

Check:

```text
27 == 22
```

False.

So this path is not added.

Now backtrack:

```text
path.pop_back();
```

Path becomes:

```text
[5,4,11]
```

---

## Node 2

Now explore the right child of `11`.

```text
sum = 20 + 2 = 22
path = [5,4,11,2]
```

`2` is a leaf.

Check:

```text
22 == 22
```

True.

So:

```cpp
ans.push_back(path);
```

Now:

```text
ans = [
    [5,4,11,2]
]
```

Then backtrack:

```text
path.pop_back();
```

Path:

```text
[5,4,11]
```

---

# Backtracking to Node 4

Node `11` is finished.

Backtrack:

```text
path.pop_back();
```

Path becomes:

```text
[5,4]
```

Node `4` is finished.

Backtrack:

```text
path.pop_back();
```

Path becomes:

```text
[5]
```

Now we return to root `5` and explore the right subtree.

---

# Node 8

```text
sum = 5 + 8 = 13
path = [5,8]
```

Explore left:

```text
13
```

---

# Node 13

```text
sum = 13 + 13 = 26
path = [5,8,13]
```

`13` is a leaf.

Check:

```text
26 == 22
```

False.

Backtrack:

```text
path = [5,8]
```

Now explore right child `4`.

---

# Node 4

```text
sum = 13 + 4 = 17
path = [5,8,4]
```

Not a leaf.

Explore left child `5`.

---

# Node 5

```text
sum = 17 + 5 = 22
path = [5,8,4,5]
```

`5` is a leaf.

Check:

```text
22 == 22
```

True.

Add:

```text
ans = [
    [5,4,11,2],
    [5,8,4,5]
]
```

Backtrack.

---

# Node 1

Now explore the other child of node `4`.

```text
sum = 17 + 1 = 18
path = [5,8,4,1]
```

`1` is a leaf.

Check:

```text
18 == 22
```

False.

Backtrack.

---

# Final Answer

```text
[
    [5,4,11,2],
    [5,8,4,5]
]
```

---

# Recursion / Backtracking Flow

Conceptually:

```text
                         5
                       /   \
                      /     \
                     4       8
                    /       / \
                  11       13   4
                 /  \          / \
                7    2        5   1
```

DFS explores:

```text
5
↓
4
↓
11
↓
7 ❌
↓
BACKTRACK
↓
2 ✅
↓
BACKTRACK
↓
BACKTRACK
↓
8
↓
13 ❌
↓
BACKTRACK
↓
4
↓
5 ✅
↓
BACKTRACK
↓
1 ❌
```

Valid paths:

```text
[5,4,11,2]
[5,8,4,5]
```

---

# `push_back()` vs `pop_back()`

This is the most important concept in this problem.

### When entering a node:

```cpp
path.push_back(root->val);
```

Example:

```text
[5,4]
```

Enter `11`:

```text
[5,4,11]
```

### When leaving a node:

```cpp
path.pop_back();
```

After finishing `11`:

```text
[5,4]
```

So remember:

```text
PUSH = Enter node
POP  = Leave node
```

---

# Why `ans.push_back(path)`?

Notice:

```cpp
ans.push_back(path);
```

We don't do:

```cpp
ans.push_back(root->val);
```

because `ans` is:

```cpp
vector<vector<int>>
```

It needs an entire path.

For example:

```text
path = [5,4,11,2]
```

Then:

```cpp
ans.push_back(path);
```

stores:

```text
ans = [
    [5,4,11,2]
]
```

Later another valid path can be added:

```text
ans = [
    [5,4,11,2],
    [5,8,4,5]
]
```

---

# Why Is `path` Passed by Reference?

We use:

```cpp
vector<int>& path
```

instead of:

```cpp
vector<int> path
```

because all recursive calls should work on the **same current path**.

Example:

```text
5
 ↓
4
 ↓
11
```

The same vector changes:

```text
[5]
[5,4]
[5,4,11]
```

Then backtracking changes it back:

```text
[5,4]
[5]
[]
```

This makes the DFS efficient and allows us to backtrack.

---

# Path Sum I vs Path Sum II

These two problems are very similar but have an important difference.

## Path Sum I — LeetCode 112

Question:

> Does at least one valid path exist?

Answer:

```text
true / false
```

So:

```cpp
return left || right;
```

---

## Path Sum II — LeetCode 113

Question:

> Find **all** valid paths.

Answer:

```text
vector<vector<int>>
```

Therefore we need:

```cpp
vector<int> path;
vector<vector<int>> ans;
```

and backtracking.

---

# Complexity Analysis

Let:

```text
N = number of nodes
```

We perform DFS and potentially visit every node.

### Time Complexity

Basic traversal:

```text
O(N)
```

However, when valid paths are copied into `ans`, copying each path costs proportional to its length.

So the practical complexity can be expressed as:

```text
O(N + output size)
```

In the worst case, the output itself can be large.

### Space Complexity

The current path requires:

```text
O(H)
```

where `H` is the height of the tree.

The recursion stack also requires:

```text
O(H)
```

So auxiliary space is:

```text
O(H)
```

excluding the output.

Worst case for a skewed tree:

```text
O(N)
```

---

# Edge Cases

## 1. Empty Tree

```text
root = []
```

There are no paths.

Output:

```text
[]
```

---

## 2. Single Node — Valid

```text
root = [5]
targetSum = 5
```

Path:

```text
[5]
```

Output:

```text
[[5]]
```

---

## 3. Single Node — Invalid

```text
root = [5]
targetSum = 10
```

Output:

```text
[]
```

---

## 4. Multiple Valid Paths

```text
        1
       / \
      2   3
```

If:

```text
targetSum = 3
```

Valid paths:

```text
1 → 2
```

Output:

```text
[[1,2]]
```

---

# Key Concepts

* Binary Tree
* DFS
* Recursion
* Backtracking
* Root-to-Leaf Path
* Running Sum
* `vector<int>`
* `vector<vector<int>>`

---

# Important Pattern

For **Path Sum II**, remember:

```text
                 ROOT
                   ↓
             PUSH root->val
                   ↓
             Update sum
                   ↓
              Is leaf?
             /         \
           YES          NO
            ↓            ↓
       sum == target   Explore
            ↓         /       \
         Add path    LEFT     RIGHT
                         \       /
                          ↓     ↓
                         POP
```

The essential pattern is:

```cpp
path.push_back(root->val);

// Explore
solve(root->left, ...);
solve(root->right, ...);

// Backtrack
path.pop_back();
```

---

# Final Code

```cpp
class Solution {
public:

    void solve(TreeNode* root, int targetSum, int sum,
               vector<int>& path,
               vector<vector<int>>& ans) {

        if(root == NULL) {
            return;
        }

        sum += root->val;

        path.push_back(root->val);

        if(root->left == NULL && root->right == NULL) {

            if(sum == targetSum) {
                ans.push_back(path);
            }
        }

        solve(root->left, targetSum, sum, path, ans);

        solve(root->right, targetSum, sum, path, ans);

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<vector<int>> ans;
        vector<int> path;

        solve(root, targetSum, 0, path, ans);

        return ans;
    }
};
```

---

# Summary

| Concept          | Details                         |
| ---------------- | ------------------------------- |
| Problem          | Path Sum II                     |
| LeetCode         | 113                             |
| Difficulty       | Medium                          |
| Approach         | DFS + Recursion + Backtracking  |
| Goal             | Find **all** root-to-leaf paths |
| Running Variable | `sum`                           |
| Current Path     | `vector<int> path`              |
| Final Answer     | `vector<vector<int>> ans`       |
| Leaf Condition   | `left == NULL && right == NULL` |
| Enter Node       | `push_back()`                   |
| Leave Node       | `pop_back()`                    |
| Time             | `O(N + output size)`            |
| Auxiliary Space  | `O(H)`                          |

## 🧠 Remember

**Path Sum II = Path Sum I + Path Tracking + Backtracking**

```text
PUSH
  ↓
EXPLORE
  ↓
CHECK LEAF
  ↓
ADD VALID PATH
  ↓
POP
```

The golden pattern:

```cpp
path.push_back(root->val);

// recursive calls

path.pop_back();
```

**Push while going down the tree, pop while coming back up.** 🌳
