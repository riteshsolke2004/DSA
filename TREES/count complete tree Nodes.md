# 🌳 222. Count Complete Tree Nodes

## Problem Statement

Given the `root` of a **complete binary tree**, return the total number of nodes in the tree.

A **complete binary tree** is a binary tree where:

* Every level except possibly the last level is completely filled.
* All nodes in the last level are placed as far **left as possible**.

The problem asks us to design an algorithm with a time complexity **better than `O(N)`**.

---

# What is a Complete Binary Tree?

Example:

```text
          1
        /   \
       2     3
      / \   /
     4   5 6
```

This is a complete binary tree because:

* Level 1 is completely filled.
* Level 2 is completely filled.
* The last level is filled from left to right.

---

# Example 1
<img width="372" height="302" alt="complete" src="https://github.com/user-attachments/assets/00bf4a7e-b652-4bac-a02e-941667d95c9c" />

### Input

```text
root = [1,2,3,4,5,6]
```

Tree:

```text
          1
        /   \
       2     3
      / \   /
     4   5 6
```

Number of nodes:

```text
1 + 2 + 3 = 6
```

### Output

```text
6
```

---

# Example 2

### Input

```text
root = []
```

The tree is empty.

Therefore:

```text
Output = 0
```

---

# Example 3

### Input

```text
root = [1]
```

Tree:

```text
1
```

There is only one node.

### Output

```text
1
```

---

# Brute Force Approach

The simple approach is to recursively count every node.

```cpp
int countNodes(TreeNode* root) {

    if(root == NULL) {
        return 0;
    }

    int left = countNodes(root->left);
    int right = countNodes(root->right);

    return left + right + 1;
}
```

The `+1` represents the current node.

For example:

```text
        1
       / \
      2   3
```

For node `1`:

```text
left  = 1
right = 1

answer = 1 + 1 + 1
       = 3
```

### Complexity

Every node is visited.

```text
Time:  O(N)
Space: O(H)
```

But the problem asks for better than `O(N)`.

So we need to use the fact that the tree is **complete**.

---

# Optimal Approach

The key observation is:

> In a complete binary tree, if the height of the leftmost path and the height of the rightmost path are equal, the tree is a perfect binary tree.

For a **perfect binary tree** with height `h`:

```text
Number of nodes = 2^h - 1
```

Example:

```text
          1
        /   \
       2     3
      / \   / \
     4   5 6   7
```

Height:

```text
h = 3
```

Number of nodes:

```text
2^3 - 1
= 8 - 1
= 7
```

Therefore, instead of visiting every node, we can directly calculate the number of nodes when the tree is perfect.

---

# How Do We Check Whether It Is Perfect?

Calculate two heights:

### Left Height

Keep moving left:

```cpp
TreeNode* temp = root;

while(temp) {
    left++;
    temp = temp->left;
}
```

### Right Height

Keep moving right:

```cpp
temp = root;

while(temp) {
    right++;
    temp = temp->right;
}
```

If:

```text
left == right
```

then the tree is perfect.

Therefore:

```text
nodes = 2^height - 1
```

---

# Why Does Equal Height Mean Perfect?

Because the tree is guaranteed to be **complete**.

Consider:

```text
          1
        /   \
       2     3
      / \   / \
     4   5 6   7
```

Leftmost path:

```text
1 → 2 → 4
```

Height:

```text
3
```

Rightmost path:

```text
1 → 3 → 7
```

Height:

```text
3
```

Both heights are equal.

Since the tree is complete, this means every position is filled.

Therefore it is a perfect tree.

---

# C++ Optimal Solution

```cpp
class Solution {
public:

    int countNodes(TreeNode* root) {

        if(root == NULL) {
            return 0;
        }

        int left = 0;
        int right = 0;

        // Find left height
        TreeNode* temp = root;

        while(temp) {
            left++;
            temp = temp->left;
        }

        // Find right height
        temp = root;

        while(temp) {
            right++;
            temp = temp->right;
        }

        // Perfect binary tree
        if(left == right) {
            return (1 << left) - 1;
        }

        // Otherwise recursively count
        return 1 + countNodes(root->left)
                 + countNodes(root->right);
    }
};
```

---

# Understanding `(1 << left) - 1`

This line:

```cpp
(1 << left) - 1
```

is equivalent to:

```text
2^left - 1
```

For example:

### If `left = 3`

```text
1 << 3
= 8
```

Then:

```text
8 - 1 = 7
```

So:

```cpp
(1 << 3) - 1
```

gives:

```text
7
```

---

# Dry Run

Consider:

```text
          1
        /   \
       2     3
      / \   /
     4   5 6
```

Expected answer:

```text
6
```

---

## Step 1 — Start at Node 1

```text
root = 1
```

Find left height.

Move:

```text
1 → 2 → 4
```

Therefore:

```text
left = 3
```

---

## Step 2 — Find Right Height

Start again from `1`.

Move:

```text
1 → 3 → NULL
```

Therefore:

```text
right = 2
```

So:

```text
left = 3
right = 2
```

They are not equal.

Therefore, this is **not a perfect tree**.

We cannot directly use:

```text
2^3 - 1
```

because the last level is not completely filled.

So we recursively calculate:

```cpp
1 + countNodes(root->left)
  + countNodes(root->right)
```

---

# Step 3 — Left Subtree

Left subtree:

```text
       2
      / \
     4   5
```

Find left height:

```text
2 → 4
```

So:

```text
left = 2
```

Find right height:

```text
2 → 5
```

So:

```text
right = 2
```

Now:

```text
left == right
```

Therefore, this subtree is perfect.

Number of nodes:

```text
2^2 - 1
= 4 - 1
= 3
```

So:

```text
countNodes(2) = 3
```

---

# Step 4 — Right Subtree

Right subtree:

```text
    3
   /
  6
```

Left height:

```text
3 → 6
```

```text
left = 2
```

Right height:

```text
3
```

```text
right = 1
```

Not equal.

So recursively count:

```text
1 + countNodes(6) + countNodes(NULL)
```

Node `6` is a leaf.

For node `6`:

```text
left = 1
right = 1
```

Therefore:

```text
countNodes(6)
= 2^1 - 1
= 1
```

So:

```text
countNodes(3)
= 1 + 1 + 0
= 2
```

---

# Step 5 — Final Calculation

At root `1`:

```text
countNodes(1)
= 1 + countNodes(2) + countNodes(3)
```

We calculated:

```text
countNodes(2) = 3
countNodes(3) = 2
```

Therefore:

```text
= 1 + 3 + 2
= 6
```

### Final Answer

```text
6
```

---

# Recursion Flow

For:

```text
          1
        /   \
       2     3
      / \   /
     4   5 6
```

The recursion is:

```text
                  1
                /   \
               /     \
              2       3
              |       |
           Perfect   Not Perfect
              |       |
             3       1 + 1
```

Therefore:

```text
1 + 3 + 2 = 6
```

---

# Another Important Example

Consider a perfect tree:

```text
          1
        /   \
       2     3
      / \   / \
     4   5 6   7
```

Left height:

```text
1 → 2 → 4
```

```text
left = 3
```

Right height:

```text
1 → 3 → 7
```

```text
right = 3
```

Since:

```text
left == right
```

we directly calculate:

```text
2^3 - 1
= 7
```

We don't need to visit nodes `2, 3, 4, 5, 6, 7`.

This is where the optimization comes from.

---

# Why This Is Faster Than O(N)

The brute-force solution visits every node:

```text
O(N)
```

The optimized solution checks heights.

Each height calculation takes:

```text
O(log N)
```

because we only move down one side of the tree.

The recursion also reduces the problem to subtrees.

Overall complexity:

```text
O((log N)^2)
```

for a complete binary tree.

Therefore:

```text
O(log² N) < O(N)
```

which satisfies the problem requirement.

---

# Complexity Analysis

Let:

```text
H = height of the complete binary tree
```

For each recursive call, we calculate:

```text
left height  → O(H)
right height → O(H)
```

The recursion has approximately `H` levels.

Therefore:

### Time Complexity

```text
O(H²)
```

Since:

```text
H = log N
```

we get:

```text
O(log² N)
```

### Space Complexity

The recursion depth is:

```text
O(H)
```

Therefore:

```text
O(log N)
```

auxiliary space.

---

# Brute Force vs Optimal

| Approach    |            Time |          Space | Idea                       |
| ----------- | --------------: | -------------: | -------------------------- |
| Brute Force |          `O(N)` |         `O(H)` | Visit every node           |
| **Optimal** | **`O(log² N)`** | **`O(log N)`** | Use complete-tree property |

---

# Important Observation

The whole optimization depends on this:

```text
Complete Binary Tree
        +
Left Height == Right Height
        ↓
Perfect Binary Tree
        ↓
2^h - 1 nodes
```

This is the main trick.

---

# Edge Cases

## 1. Empty Tree

```text
root = []
```

```cpp
if(root == NULL)
    return 0;
```

Output:

```text
0
```

---

## 2. Single Node

```text
    1
```

Left height:

```text
1
```

Right height:

```text
1
```

Equal:

```text
2^1 - 1 = 1
```

Output:

```text
1
```

---

## 3. Perfect Binary Tree

```text
        1
       / \
      2   3
     / \ / \
    4  5 6  7
```

Height:

```text
3
```

Nodes:

```text
2^3 - 1 = 7
```

Output:

```text
7
```

---

# Common Mistake

A common mistake is to assume:

```text
left height == right height
```

means the tree is perfect for **any binary tree**.

That is not true.

This works here because the problem guarantees that the tree is **complete**.

For a general binary tree, equal left and right heights do not necessarily mean it is perfect.

---

# Comparison With Simple Recursive Solution

### Brute Force

```cpp
class Solution {
public:

    int countNodes(TreeNode* root) {

        if(root == NULL) {
            return 0;
        }

        int left = countNodes(root->left);
        int right = countNodes(root->right);

        return left + right + 1;
    }
};
```

This is easy to understand but takes:

```text
O(N)
```

---

### Optimized

```cpp
class Solution {
public:

    int countNodes(TreeNode* root) {

        if(root == NULL) {
            return 0;
        }

        int left = 0;
        int right = 0;

        TreeNode* temp = root;

        while(temp) {
            left++;
            temp = temp->left;
        }

        temp = root;

        while(temp) {
            right++;
            temp = temp->right;
        }

        if(left == right) {
            return (1 << left) - 1;
        }

        return 1 + countNodes(root->left)
                 + countNodes(root->right);
    }
};
```

This uses the special property of a **complete binary tree**.

---

# Key Concepts

* Complete Binary Tree
* Perfect Binary Tree
* Tree Height
* Recursion
* Binary Tree
* Bit Manipulation
* Divide and Conquer

---

# Important Pattern

Remember this:

```text
Calculate Left Height
        ↓
Calculate Right Height
        ↓
Are they equal?
    /          \
  YES           NO
   ↓             ↓
Perfect       Recurse
   ↓             ↓
2^h - 1     left + right + 1
```

---

# Final Code

```cpp
class Solution {
public:

    int countNodes(TreeNode* root) {

        if(root == NULL) {
            return 0;
        }

        int left = 0;
        int right = 0;

        // Find left height
        TreeNode* temp = root;

        while(temp) {
            left++;
            temp = temp->left;
        }

        // Find right height
        temp = root;

        while(temp) {
            right++;
            temp = temp->right;
        }

        // Perfect binary tree
        if(left == right) {
            return (1 << left) - 1;
        }

        // Complete but not perfect
        return 1 + countNodes(root->left)
                 + countNodes(root->right);
    }
};
```

---

# Summary

| Concept              | Details                     |
| -------------------- | --------------------------- |
| Problem              | Count Complete Tree Nodes   |
| LeetCode             | 222                         |
| Difficulty           | Medium                      |
| Input                | Complete Binary Tree        |
| Brute Force          | Recursive counting          |
| Optimal              | Height comparison           |
| Perfect Tree Formula | `2^h - 1`                   |
| Time Complexity      | `O(log² N)`                 |
| Space Complexity     | `O(log N)`                  |
| Main Trick           | `leftHeight == rightHeight` |

## 🧠 Remember

The golden observation:

```text
Complete Tree
     +
Left Height == Right Height
     ↓
Perfect Tree
     ↓
Number of Nodes = 2^h - 1
```

And the key line:

```cpp
if(left == right)
    return (1 << left) - 1;
```

This avoids traversing every node and brings the solution down from **`O(N)` to `O(log² N)`**. 🌳
