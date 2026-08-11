# 🌳 701. Insert into a Binary Search Tree

[LeetCode — Insert into a Binary Search Tree](https://leetcode.com/problems/insert-into-a-binary-search-tree/)

## Problem Statement

You are given the `root` node of a **Binary Search Tree (BST)** and an integer `val`.

Your task is to insert `val` into the BST while maintaining the BST property.

Return the **root of the BST after insertion**.

It is guaranteed that `val` does not already exist in the BST.

---

# What is a Binary Search Tree?

A Binary Search Tree follows this rule:

```text
              Root
             /    \
       Smaller    Greater
```

For every node:

```text
Left Subtree < Root < Right Subtree
```

Therefore, while inserting a new value:

```text
val < root->val
        ↓
      LEFT
```

and:

```text
val > root->val
        ↓
      RIGHT
```

---

# Example 1
<img width="752" height="221" alt="insertbst" src="https://github.com/user-attachments/assets/8ffc5d2c-0f6b-4167-bfea-61d30349bc91" />
<img width="352" height="301" alt="bst" src="https://github.com/user-attachments/assets/ba22afda-764a-468d-912c-bb48499e00e0" />

### Input

```text
root = [4,2,7,1,3]
val = 5
```

Initial tree:

```text
        4
       / \
      2   7
     / \
    1   3
```

We want to insert:

```text
5
```

Start at `4`:

```text
5 > 4
```

Go right.

At `7`:

```text
5 < 7
```

Go left.

The left child of `7` is `NULL`.

Therefore, insert `5` there.

Final tree:

```text
        4
       / \
      2   7
     / \ /
    1  3 5
```

Output:

```text
[4,2,7,1,3,5]
```

---

# Example 2

### Input

```text
root = [40,20,60,10,30,50,70]
val = 25
```

Initial tree:

```text
          40
         /  \
       20    60
      /  \   / \
    10   30 50 70
```

Search for the correct position of `25`.

At `40`:

```text
25 < 40
```

Go left.

At `20`:

```text
25 > 20
```

Go right.

At `30`:

```text
25 < 30
```

Go left.

The left child of `30` is `NULL`.

Insert `25`.

Final tree:

```text
          40
         /  \
       20    60
      /  \   / \
    10   30 50 70
         /
        25
```

---

# Main Approach

Insertion in a BST is basically a **search for the correct NULL position**.

We recursively compare `val` with the current node.

### Case 1 — Root is NULL

If:

```cpp
root == NULL
```

we found the position where the new node should be inserted.

Create:

```cpp
new TreeNode(val)
```

and return it.

---

### Case 2 — Value is Smaller

If:

```cpp
val < root->val
```

the new value belongs to the left subtree.

```cpp
root->left = insertIntoBST(root->left, val);
```

---

### Case 3 — Value is Greater

If:

```cpp
val > root->val
```

the new value belongs to the right subtree.

```cpp
root->right = insertIntoBST(root->right, val);
```

---

# Algorithm

1. Start from the root.
2. If the current node is `NULL`, create a new node with `val`.
3. If `val < root->val`, recursively insert into the left subtree.
4. Otherwise, recursively insert into the right subtree.
5. Connect the returned node to the appropriate child.
6. Return the original `root`.

---

# C++ Solution

```cpp
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        if(root == NULL) {
            TreeNode* newroot = new TreeNode(val);
            return newroot;
        }

        if(val < root->val) {

            root->left = insertIntoBST(root->left, val);
        }
        else {

            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }
};
```

---

# Important Part of the Code

This is the key:

```cpp
root->left = insertIntoBST(root->left, val);
```

and:

```cpp
root->right = insertIntoBST(root->right, val);
```

Why do we assign the result?

Because eventually the recursion reaches a `NULL` position and creates the new node.

For example:

```text
root->left = insertIntoBST(root->left, val);
```

If `root->left` is `NULL`:

```text
insertIntoBST(NULL, val)
        ↓
new TreeNode(val)
        ↓
return new node
```

Then:

```text
root->left = new node
```

So the new node gets connected to the tree.

---

# Detailed Dry Run

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

---

## Step 1

Current node:

```text
root = 4
val = 5
```

Compare:

```text
5 < 4 ❌
```

So:

```text
5 > 4
```

Go right:

```cpp
root->right = insertIntoBST(root->right, 5);
```

Now:

```text
        4
       / \
      2   7
```

---

## Step 2

Current node:

```text
root = 7
val = 5
```

Compare:

```text
5 < 7
```

Go left:

```cpp
root->left = insertIntoBST(root->left, 5);
```

Currently:

```text
7->left = NULL
```

---

## Step 3

Now:

```text
root = NULL
```

Therefore:

```cpp
if(root == NULL)
```

is true.

Create:

```cpp
TreeNode* newroot = new TreeNode(5);
```

Return:

```text
5
```

---

## Step 4 — Connect Node

The previous call was:

```cpp
root->left = insertIntoBST(root->left, val);
```

So:

```text
7->left = 5
```

Tree becomes:

```text
        4
       / \
      2   7
     / \ /
    1  3 5
```

---

## Step 5 — Return Root

At node `7`:

```cpp
return root;
```

returns `7`.

Then at node `4`:

```cpp
return root;
```

returns `4`.

Therefore the final root is still:

```text
4
```

---

# Recursion Visualization

```text
insertIntoBST(4, 5)
        |
        | 5 > 4
        ↓
insertIntoBST(7, 5)
        |
        | 5 < 7
        ↓
insertIntoBST(NULL, 5)
        |
        ↓
   Create Node(5)
        |
        ↓
     return 5
        |
        ↓
    7->left = 5
        |
        ↓
     return 7
        |
        ↓
    4->right = 7
        |
        ↓
     return 4
```

---

# Why Do We Return `root`?

This is very important.

Suppose:

```text
        4
       / \
      2   7
```

We insert:

```text
5
```

We eventually modify:

```text
7->left = 5
```

But the root of the whole tree is still:

```text
4
```

Therefore, every recursive call returns its current root:

```cpp
return root;
```

This keeps the original tree connected.

---

# Another Dry Run

Consider:

```text
root = [4,2,7,1,3]
val = 8
```

Tree:

```text
        4
       / \
      2   7
     / \
    1   3
```

### At 4

```text
8 > 4
```

Go right.

### At 7

```text
8 > 7
```

Go right.

### At NULL

Create:

```text
8
```

Final tree:

```text
        4
       / \
      2   7
     / \   \
    1   3   8
```

---

# Another Example — Insert Smaller Value

Consider:

```text
root = [4,2,7,1,3]
val = 0
```

Path:

```text
4
↓
0 < 4 → LEFT

2
↓
0 < 2 → LEFT

1
↓
0 < 1 → LEFT

NULL
↓
Create 0
```

Final tree:

```text
        4
       / \
      2   7
     / \
    1   3
   /
  0
```

---

# Decision Diagram

```text
                  Start
                    |
              root == NULL?
               /          \
             YES           NO
              ↓             ↓
         Create Node    Compare val
                           /    \
                          /      \
                    val < root   val > root
                         ↓          ↓
                       LEFT       RIGHT
                         ↓          ↓
                      Repeat     Repeat
```

---

# BST Insertion Rule

The easiest way to remember:

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
root == NULL
       ↓
 CREATE NODE
```

---

# Why Doesn't Insertion Change the Existing Nodes?

We don't move existing nodes.

We simply find an empty (`NULL`) position where the new node can be attached.

For example:

```text
        4
       / \
      2   7
```

Insert `5`:

```text
        4
       / \
      2   7
         /
        5
```

Only the new node is added.

---

# Edge Cases

## 1. Empty BST

Input:

```text
root = []
val = 5
```

Since:

```text
root == NULL
```

create:

```text
5
```

Output:

```text
[5]
```

---

## 2. Insert Smaller Value

```text
        5
       /
      3
```

Insert:

```text
2
```

Result:

```text
        5
       /
      3
     /
    2
```

---

## 3. Insert Greater Value

```text
        5
         \
          7
```

Insert:

```text
9
```

Result:

```text
        5
         \
          7
           \
            9
```

---

## 4. Insert Between Two Values

```text
        5
       / \
      3   8
```

Insert:

```text
6
```

Result:

```text
        5
       / \
      3   8
         /
        6
```

---

# Common Mistakes

### ❌ Mistake 1 — Creating the Node Too Early

Don't create a new node at every recursive call.

Create it only when:

```cpp
root == NULL
```

---

### ❌ Mistake 2 — Forgetting to Connect the Returned Node

Wrong:

```cpp
insertIntoBST(root->left, val);
```

Correct:

```cpp
root->left = insertIntoBST(root->left, val);
```

Similarly:

```cpp
root->right = insertIntoBST(root->right, val);
```

---

### ❌ Mistake 3 — Not Returning Root

Always return:

```cpp
return root;
```

Otherwise the tree connection can be lost.

---

### ❌ Mistake 4 — Wrong Direction

Remember:

```text
Smaller → Left
Greater → Right
```

---

# Complexity Analysis

Let `H` be the height of the BST.

We travel along only one path from the root.

### Time Complexity

```text
O(H)
```

For a balanced BST:

```text
O(log N)
```

For a skewed BST:

```text
O(N)
```

---

### Space Complexity

Because recursion is used:

```text
O(H)
```

Balanced BST:

```text
O(log N)
```

Worst case:

```text
O(N)
```

---

# Balanced BST

```text
          8
        /   \
       4     12
      / \   /  \
     2   6 10   14
```

Insertion/search:

```text
O(log N)
```

---

# Skewed BST

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

Insertion can become:

```text
O(N)
```

---

# Interview Explanation

If asked to explain:

> "Since the tree is a BST, I compare the value with the current node. If the value is smaller, I recursively insert it into the left subtree. If it is greater, I insert it into the right subtree. When I reach a NULL position, I create the new node there. Finally, I return the current root so that all recursive connections remain intact."

---

# Key Concepts

* Binary Search Tree
* Recursion
* BST Property
* Insertion
* Tree Traversal
* Binary Tree
* Divide and Conquer

---

# Quick Revision

Remember these three cases:

```text
root == NULL
     ↓
Create New Node
```

```text
val < root->val
     ↓
Insert LEFT
```

```text
val > root->val
     ↓
Insert RIGHT
```

And always:

```cpp
return root;
```

---

# Final Code

```cpp
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        if(root == NULL) {
            return new TreeNode(val);
        }

        if(val < root->val) {
            root->left = insertIntoBST(root->left, val);
        }
        else {
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }
};
```

---

# Summary

| Feature         | Details                          |
| --------------- | -------------------------------- |
| Problem         | Insert into a Binary Search Tree |
| LeetCode        | 701                              |
| Difficulty      | Medium                           |
| Approach        | Recursion                        |
| Data Structure  | BST                              |
| Smaller Value   | Go Left                          |
| Greater Value   | Go Right                         |
| NULL Position   | Create New Node                  |
| Balanced Time   | `O(log N)`                       |
| Worst Time      | `O(N)`                           |
| Auxiliary Space | `O(H)`                           |

## 🧠 Final Takeaway

BST insertion is basically:

```text
             Compare
                ↓
        ┌───────┴───────┐
        ↓               ↓
    Smaller          Greater
        ↓               ↓
      LEFT            RIGHT
        ↓               ↓
       NULL            NULL
        ↓               ↓
    Insert Node     Insert Node
```

The most important line to understand is:

```cpp
root->left = insertIntoBST(root->left, val);
```

or:

```cpp
root->right = insertIntoBST(root->right, val);
```

The recursive call finds the correct `NULL` position, creates the new node, and returns it so it can be attached to the BST. 🌳
