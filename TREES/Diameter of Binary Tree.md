# 🌳 543. Diameter of Binary Tree

## Problem Statement

Given the `root` of a binary tree, return the **length of the diameter** of the tree.

The **diameter of a binary tree** is the length of the **longest path between any two nodes** in the tree.

The path:

* May pass through the root.
* May **not** pass through the root.
* Is measured by the **number of edges** between the two nodes.

---

# Example 1
<img width="292" height="302" alt="diamtree" src="https://github.com/user-attachments/assets/a70ffc16-acec-419a-b38d-0a870aff6041" />

### Input

```text
root = [1,2,3,4,5]
```

Binary Tree:

```text
        1
       / \
      2   3
     / \
    4   5
```

The longest paths are:

```text
4 → 2 → 1 → 3
```

or:

```text
5 → 2 → 1 → 3
```

Number of edges:

```text
4 → 2      = 1 edge
2 → 1      = 1 edge
1 → 3      = 1 edge
```

Total:

```text
3 edges
```

### Output

```text
3
```

---

# Example 2

### Input

```text
root = [1,2]
```

Tree:

```text
    1
   /
  2
```

The longest path is:

```text
1 → 2
```

There is only:

```text
1 edge
```

### Output

```text
1
```

---

# Important Concept

The diameter can be formed by combining:

```text
Left subtree height
        +
Right subtree height
```

For every node:

```text
        Node
       /    \
    Left    Right
```

The path passing through that node is:

```text
Left subtree
     ↓
   Node
     ↓
Right subtree
```

Therefore:

```text
Diameter through node
=
leftHeight + rightHeight
```

---

# Three Possibilities

At every node, the diameter can be:

### Option 1 — Pass through current node

```text
leftHeight + rightHeight
```

### Option 2 — Completely inside left subtree

```text
diameter(left)
```

### Option 3 — Completely inside right subtree

```text
diameter(right)
```

Therefore:

```text
answer = max(option1, option2, option3)
```

---

# Approach Used

Your solution uses **recursion**.

There are two functions:

```cpp
maxDepth()
```

and:

```cpp
diameterOfBinaryTree()
```

### `maxDepth()`

Calculates the height of a subtree.

### `diameterOfBinaryTree()`

Checks the three possible diameter options.

---

# Step 1 — Calculate Height

Your function:

```cpp
int maxDepth(TreeNode* root)
```

calculates the height of the tree.

```cpp
if(root == NULL) {
    return 0;
}
```

For a non-null node:

```cpp
int leftHeight = maxDepth(root->left) + 1;
int rightHeight = maxDepth(root->right) + 1;
```

Then:

```cpp
return max(leftHeight, rightHeight);
```

---

# Why Add `+1`?

Suppose:

```text
    1
   /
  2
```

For node `2`:

```text
maxDepth(2) = 1
```

For node `1`:

```text
leftHeight = maxDepth(2) + 1
           = 1 + 1
           = 2
```

So the function returns the **number of nodes in the longest root-to-leaf path**.

This is slightly different from a height measured in edges.

---

# Step 2 — Calculate Diameter

At every node:

```cpp
int option1 = maxDepth(root->left)
            + maxDepth(root->right);
```

This represents a path passing through the current node.

Then:

```cpp
int option2 = diameterOfBinaryTree(root->left);
```

This represents a diameter completely inside the left subtree.

And:

```cpp
int option3 = diameterOfBinaryTree(root->right);
```

This represents a diameter completely inside the right subtree.

Finally:

```cpp
int ans = max(option1, max(option2, option3));
```

---

# C++ Solution

```cpp
class Solution {
public:

    int maxDepth(TreeNode* root) {

        if(root == NULL) {
            return 0;
        }

        int leftHeight = maxDepth(root->left) + 1;
        int rightHeight = maxDepth(root->right) + 1;

        int ans = max(leftHeight, rightHeight);

        return ans;
    }

    int diameterOfBinaryTree(TreeNode* root) {

        if(root == NULL) {
            return 0;
        }

        // Diameter passing through current node
        int option1 = maxDepth(root->left)
                    + maxDepth(root->right);

        // Diameter inside left subtree
        int option2 = diameterOfBinaryTree(root->left);

        // Diameter inside right subtree
        int option3 = diameterOfBinaryTree(root->right);

        int ans = max(option1, max(option2, option3));

        return ans;
    }
};
```

---

# Detailed Dry Run

Consider:

```text
        1
       / \
      2   3
     / \
    4   5
```

Expected diameter:

```text
4 → 2 → 1 → 3
```

Number of edges:

```text
3
```

---

## Step 1 — Node 4

Node `4` is a leaf.

```text
maxDepth(4)
```

Left:

```text
NULL → 0
```

Right:

```text
NULL → 0
```

Therefore:

```text
leftHeight = 0 + 1 = 1
rightHeight = 0 + 1 = 1
```

Height:

```text
1
```

---

# Step 2 — Node 5

Similarly:

```text
maxDepth(5) = 1
```

---

# Step 3 — Node 2

Tree:

```text
      2
     / \
    4   5
```

Left height:

```text
1
```

Right height:

```text
1
```

Therefore:

```text
option1 = 1 + 1
        = 2
```

This represents:

```text
4 → 2 → 5
```

Number of edges:

```text
2
```

Diameter of left subtree:

```text
option2 = 0
```

Diameter of right subtree:

```text
option3 = 0
```

Therefore:

```text
diameter(2) = 2
```

---

# Step 4 — Node 3

Node `3` is a leaf.

Therefore:

```text
diameter(3) = 0
```

Height:

```text
1
```

---

# Step 5 — Node 1

Tree:

```text
        1
       / \
      2   3
```

Left height:

```text
maxDepth(2) = 2
```

Right height:

```text
maxDepth(3) = 1
```

Therefore:

```text
option1 = 2 + 1
        = 3
```

This represents:

```text
4 → 2 → 1 → 3
```

Number of edges:

```text
3
```

Left subtree diameter:

```text
option2 = 2
```

Right subtree diameter:

```text
option3 = 0
```

Therefore:

```text
answer = max(3, 2, 0)
       = 3
```

Final:

```text
3
```

---

# Why Is `leftHeight + rightHeight` Correct?

Consider:

```text
        1
       / \
      2   3
     /
    4
```

At node `1`:

```text
leftHeight = 2
rightHeight = 1
```

The longest path passing through `1` is:

```text
4 → 2 → 1 → 3
```

Edges:

```text
4 → 2 = 1
2 → 1 = 1
1 → 3 = 1
```

Total:

```text
3
```

And:

```text
leftHeight + rightHeight
= 2 + 1
= 3
```

So the formula works.

---

# Important Point — Diameter Does Not Have To Pass Through Root

This is one of the most important parts of the problem.

Consider:

```text
          1
         /
        2
       / \
      3   4
     /     \
    5       6
```

The longest path is:

```text
5 → 3 → 2 → 4 → 6
```

It does **not** pass through the root `1`.

Therefore, simply calculating:

```text
maxDepth(root->left) + maxDepth(root->right)
```

at the root is not enough.

That's why we calculate:

```text
option1 = diameter through current node
option2 = diameter in left subtree
option3 = diameter in right subtree
```

---

# The Three Options

At every node:

```text
              Node
             /    \
            L      R
```

We calculate:

```text
Option 1:
leftHeight + rightHeight
```

```text
Option 2:
diameter(left)
```

```text
Option 3:
diameter(right)
```

Then:

```text
answer = max(option1, option2, option3)
```

---

# Visual Representation

```text
                   Node
                 /      \
                /        \
         Left subtree   Right subtree
               |              |
               |              |
          leftHeight      rightHeight
                \            /
                 \          /
                  \        /
                   \      /
                    Node
```

Diameter through node:

```text
leftHeight + rightHeight
```

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

There are no edges.

Therefore:

```text
Diameter = 0
```

Output:

```text
0
```

---

## 3. Two Nodes

```text
    1
   /
  2
```

There is one edge:

```text
1 → 2
```

Output:

```text
1
```

---

## 4. Completely Skewed Tree

```text
1
 \
  2
   \
    3
     \
      4
```

Longest path:

```text
1 → 2 → 3 → 4
```

Number of edges:

```text
3
```

Output:

```text
3
```

---

# Complexity Analysis

Your current solution calculates `maxDepth()` repeatedly.

For example:

```cpp
int option1 = maxDepth(root->left)
            + maxDepth(root->right);
```

Then recursively:

```cpp
diameterOfBinaryTree(root->left)
```

calculates those heights again.

This causes repeated work.

### Time Complexity

Worst case:

```text
O(N²)
```

especially for a skewed tree.

### Space Complexity

Recursion stack:

```text
O(H)
```

where `H` is the height of the tree.

Worst case:

```text
O(N)
```

---

# Optimized Approach

There is a better solution that calculates the **height and diameter together in one DFS traversal**.

Instead of repeatedly calling `maxDepth()`, we calculate the height once.

The idea:

```text
leftHeight
rightHeight

diameter through current node
=
leftHeight + rightHeight

height
=
1 + max(leftHeight, rightHeight)
```

This reduces the time complexity to:

```text
O(N)
```

---

# Optimized C++ Solution

```cpp
class Solution {
public:

    int solve(TreeNode* root, int& diameter) {

        if(root == NULL) {
            return 0;
        }

        int leftHeight = solve(root->left, diameter);
        int rightHeight = solve(root->right, diameter);

        // Diameter passing through current node
        diameter = max(diameter, leftHeight + rightHeight);

        // Return height of current node
        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        int diameter = 0;

        solve(root, diameter);

        return diameter;
    }
};
```

---

# Why Optimized Solution Is Better

### Your approach

```text
Calculate height
      ↓
Calculate diameter
      ↓
Calculate height again
      ↓
Calculate diameter
      ↓
Repeated work
```

Time:

```text
O(N²)
```

### Optimized approach

Each node is processed once:

```text
             Node
            /    \
           ↓      ↓
      leftHeight rightHeight
           \      /
            \    /
           diameter
               ↓
             height
```

Time:

```text
O(N)
```

---

# Comparison

| Approach                    |       Time |      Space |
| --------------------------- | ---------: | ---------: |
| Brute Force / Your Solution |    `O(N²)` |     `O(H)` |
| **Optimized DFS**           | **`O(N)`** | **`O(H)`** |

For coding interviews, the **optimized `O(N)` solution is preferred**.

---

# Key Concepts

* Binary Tree
* DFS
* Recursion
* Tree Height
* Diameter
* Divide and Conquer
* Postorder Traversal

---

# Important Pattern

The optimized solution follows **Postorder Traversal**:

```text
LEFT → RIGHT → ROOT
```

Why?

Because before calculating the diameter at the current node, we need:

```text
leftHeight
rightHeight
```

So we first calculate both children and then process the current node.

```text
        ROOT
       /    \
    LEFT    RIGHT
       \    /
        ↓  ↓
     Heights
        ↓
     Diameter
```

---

# Core Formula

For every node:

```text
leftHeight  = height(left)
rightHeight = height(right)
```

Diameter through current node:

```text
diameter = leftHeight + rightHeight
```

Height:

```text
height = 1 + max(leftHeight, rightHeight)
```

---

# Final Recommended Code

```cpp
class Solution {
public:

    int solve(TreeNode* root, int& diameter) {

        if(root == NULL) {
            return 0;
        }

        int leftHeight = solve(root->left, diameter);
        int rightHeight = solve(root->right, diameter);

        diameter = max(diameter, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        int diameter = 0;

        solve(root, diameter);

        return diameter;
    }
};
```

---

# Summary

| Concept          | Details                            |
| ---------------- | ---------------------------------- |
| Problem          | Diameter of Binary Tree            |
| LeetCode         | 543                                |
| Difficulty       | Easy                               |
| Approach         | DFS + Recursion                    |
| Traversal        | Postorder                          |
| Diameter Formula | `leftHeight + rightHeight`         |
| Height Formula   | `1 + max(leftHeight, rightHeight)` |
| Brute Force Time | `O(N²)`                            |
| Optimized Time   | **`O(N)`**                         |
| Space            | `O(H)`                             |

## 🧠 Remember

The diameter is **not necessarily through the root**.

At every node, think:

```text
          Node
         /    \
        L      R

diameter through node
        =
leftHeight + rightHeight
```

Then keep the maximum:

```cpp
diameter = max(diameter, leftHeight + rightHeight);
```

And return the height:

```cpp
return 1 + max(leftHeight, rightHeight);
```

**Diameter = longest path between any two nodes, measured in edges.** 🌳
