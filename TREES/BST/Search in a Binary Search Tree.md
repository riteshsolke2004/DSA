# 🌳 700. Search in a Binary Search Tree

[LeetCode — Search in a Binary Search Tree](https://leetcode.com/problems/search-in-a-binary-search-tree/)

## Problem Statement

You are given the root of a **Binary Search Tree (BST)** and an integer `val`.

Your task is to find the node whose value is equal to `val`.

If the node exists:

* Return the **subtree rooted at that node**.
* If the node does not exist, return `NULL`.

---

# What Does "Return the Subtree" Mean?

Suppose the BST is:

```text
        4
       / \
      2   7
     / \
    1   3
```

If:

```text
val = 2
```

We don't just return the value `2`.

We return the entire subtree rooted at `2`:

```text
      2
     / \
    1   3
```

This is why the function returns:

```cpp
TreeNode*
```

instead of:

```cpp
int
```

---

# Example 1
<img width="422" height="302" alt="tree1" src="https://github.com/user-attachments/assets/9cf95c11-0acd-4716-9e96-69e0ea419cd3" />

### Input

```text
root = [4,2,7,1,3]
val = 2
```

Tree:

```text
        4
       / \
      2   7
     / \
    1   3
```

Search for:

```text
val = 2
```

Start at `4`:

```text
4 > 2
```

So move to the **left subtree**.

At `2`:

```text
2 == 2
```

We found the required node.

Return:

```text
      2
     / \
    1   3
```

### Output

```text
[2,1,3]
```

---

# Example 2
<img width="422" height="302" alt="tree2" src="https://github.com/user-attachments/assets/bbf67d8b-1cff-4157-a6b8-c26a2c2d4f9d" />

### Input

```text
root = [4,2,7,1,3]
val = 5
```

Tree:

```text
        4
       / \
      2   7
     / \
    1   3
```

Start at `4`:

```text
4 < 5
```

So move right.

At `7`:

```text
7 > 5
```

So move left.

But:

```text
7->left = NULL
```

Therefore, `5` doesn't exist.

Return:

```text
NULL
```

### Output

```text
[]
```

---

# Binary Search Tree Property

A BST follows this rule:

```text
        Root
       /    \
   Smaller  Greater
```

For every node:

```text
Left Subtree < Root < Right Subtree
```

Therefore, while searching:

```text
val < root->val
       ↓
     LEFT
```

```text
val > root->val
       ↓
     RIGHT
```

```text
val == root->val
       ↓
     FOUND
```

---

# Approach

We use **recursion** and the BST property.

### Step 1 — Check NULL

If:

```cpp
root == NULL
```

the value doesn't exist.

Return:

```cpp
NULL
```

---

### Step 2 — Check Current Node

If:

```cpp
root->val == val
```

we found the node.

Return:

```cpp
root
```

Remember: returning `root` means returning the **entire subtree rooted at that node**.

---

### Step 3 — Search Left

If:

```cpp
root->val > val
```

then `val` must be somewhere in the left subtree.

```cpp
return searchBST(root->left, val);
```

---

### Step 4 — Search Right

If:

```cpp
root->val < val
```

then `val` must be somewhere in the right subtree.

```cpp
return searchBST(root->right, val);
```

---

# Algorithm

1. Start from `root`.
2. If `root == NULL`, return `NULL`.
3. If `root->val == val`, return `root`.
4. If `val < root->val`, recursively search the left subtree.
5. If `val > root->val`, recursively search the right subtree.
6. Continue until the value is found or `NULL` is reached.

---

# C++ Solution

```cpp
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {

        if(root == NULL) {
            return NULL;
        }

        if(root->val == val) {
            return root;
        }

        if(root->val > val) {
            return searchBST(root->left, val);
        }

        return searchBST(root->right, val);
    }
};
```

---

# Detailed Dry Run

Consider:

```text
root = [4,2,7,1,3]
val = 3
```

Tree:

```text
        4
       / \
      2   7
     / \
    1   3
```

---

## Step 1

Current node:

```text
root->val = 4
val = 3
```

Compare:

```text
4 == 3 ❌
```

Then:

```text
4 > 3
```

So go left.

```text
searchBST(root->left, 3)
```

---

## Step 2

Current node:

```text
root->val = 2
```

Compare:

```text
2 == 3 ❌
```

Then:

```text
2 < 3
```

So go right.

```text
searchBST(root->right, 3)
```

---

## Step 3

Current node:

```text
root->val = 3
```

Compare:

```text
3 == 3 ✅
```

Return:

```text
root
```

The returned subtree is:

```text
3
```

So the answer is the node containing `3`.

---

# Dry Run — Value Not Found

Consider:

```text
root = [4,2,7,1,3]
val = 5
```

Tree:

```text
        4
       / \
      2   7
     / \
    1   3
```

### At `4`

```text
4 < 5
```

Go right.

```text
        4
         \
          7
```

### At `7`

```text
7 > 5
```

Go left.

```text
7
/
NULL
```

Now:

```text
root == NULL
```

Return:

```text
NULL
```

---

# Recursion Visualization

```text
                  4
                  |
              val = 2
                  |
              4 > 2
                  ↓
                  2
               /     \
              1       3
```

Since:

```text
2 == val
```

return node `2`.

---

# Why Return `root`?

This is an important point.

Suppose:

```text
        4
       / \
      2   7
     / \
    1   3
```

If:

```text
val = 2
```

The answer isn't just:

```text
2
```

It is:

```text
      2
     / \
    1   3
```

Therefore:

```cpp
return root;
```

returns the pointer to the root of the required subtree.

---

# Why We Don't Search Both Subtrees

In a normal binary tree, we might need:

```text
Search Left
     +
Search Right
```

But in a BST, we know where the value can exist.

For example:

```text
        10
       /  \
      5    15
```

If:

```text
val = 13
```

Since:

```text
13 > 10
```

we know `13` cannot be in the left subtree.

So we only search:

```text
Right Subtree
```

This makes BST search much more efficient.

---

# Decision Diagram

```text
                 root
                   |
            root == NULL?
              /       \
            YES        NO
             ↓          ↓
           NULL      root == val?
                       /      \
                     YES       NO
                      ↓         ↓
                    root     Compare
                              /    \
                         val < root  val > root
                              ↓          ↓
                            LEFT       RIGHT
```

---

# Complexity Analysis

Let:

```text
H = height of the BST
```

At each step, we move only to one child.

Therefore:

### Time Complexity

```text
O(H)
```

For a balanced BST:

```text
H = O(log N)
```

So:

```text
O(log N)
```

For a skewed BST:

```text
H = O(N)
```

So worst case:

```text
O(N)
```

---

### Space Complexity

Because recursion is used:

```text
O(H)
```

For a balanced tree:

```text
O(log N)
```

Worst case:

```text
O(N)
```

---

# Balanced BST

Example:

```text
          8
        /   \
       4     12
      / \   /  \
     2   6 10   14
```

Search is approximately:

```text
O(log N)
```

---

# Skewed BST

Example:

```text
1
 \
  2
   \
    3
     \
      4
       \
        5
```

Search can become:

```text
O(N)
```

---

# Edge Cases

### 1. Empty Tree

```text
root = NULL
```

Return:

```text
NULL
```

---

### 2. Value is Root

```text
        4
       / \
      2   7
```

If:

```text
val = 4
```

Return immediately:

```text
root
```

---

### 3. Value is Leaf

```text
        4
       / \
      2   7
```

Search for:

```text
val = 7
```

Return the node `7`.

---

### 4. Value Doesn't Exist

```text
        4
       / \
      2   7
```

Search:

```text
val = 5
```

Eventually reach `NULL`.

Return:

```text
NULL
```

---

# Common Mistakes

### ❌ Mistake 1 — Returning Only the Value

Don't do:

```cpp
return root->val;
```

The function needs to return:

```cpp
TreeNode*
```

So return:

```cpp
return root;
```

---

### ❌ Mistake 2 — Searching Both Sides

Don't do:

```cpp
searchBST(root->left, val);
searchBST(root->right, val);
```

Use the BST property.

---

### ❌ Mistake 3 — Wrong Direction

Remember:

```text
val < root->val → LEFT
```

```text
val > root->val → RIGHT
```

---

### ❌ Mistake 4 — Forgetting NULL

Always check:

```cpp
if(root == NULL) {
    return NULL;
}
```

---

# Interview Explanation

If asked to explain this solution:

> "Since the given tree is a BST, I use its ordering property. If the current node's value equals `val`, I return that node, which represents the root of the required subtree. If `val` is smaller, I recursively search the left subtree; otherwise, I search the right subtree. If I reach `NULL`, the value doesn't exist, so I return `NULL`."

---

# Key Concepts

* Binary Search Tree
* Recursion
* BST Property
* Binary Tree
* Searching
* Subtree
* Tree Traversal
* Divide and Conquer

---

# Quick Revision

Remember these three cases:

```text
root == NULL
     ↓
   NULL
```

```text
root->val == val
     ↓
   return root
```

```text
root->val > val
     ↓
    LEFT
```

```text
root->val < val
     ↓
   RIGHT
```

---

# Final Code

```cpp
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {

        if(root == NULL) {
            return NULL;
        }

        if(root->val == val) {
            return root;
        }

        if(root->val > val) {
            return searchBST(root->left, val);
        }

        return searchBST(root->right, val);
    }
};
```

---

# Summary

| Feature          | Details                        |
| ---------------- | ------------------------------ |
| Problem          | Search in a Binary Search Tree |
| LeetCode         | 700                            |
| Difficulty       | Easy                           |
| Approach         | Recursion                      |
| Data Structure   | BST                            |
| Search Direction | Left / Right                   |
| Balanced Time    | `O(log N)`                     |
| Worst Time       | `O(N)`                         |
| Auxiliary Space  | `O(H)`                         |
| Found            | Return subtree root            |
| Not Found        | Return `NULL`                  |

## 🧠 Final Takeaway

The whole problem comes down to the BST property:

```text
          Root
         /    \
     Smaller  Greater
```

So:

```text
val < root->val → Go LEFT
val > root->val → Go RIGHT
val == root->val → RETURN ROOT
```

And the key point:

**When you find the value, return the node itself — because that node is the root of the required subtree.** 🌳🔍
