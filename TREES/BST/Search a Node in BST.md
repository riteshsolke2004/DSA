# 🌳 Search a Node in Binary Search Tree

## Problem Statement

Given the **root** of a Binary Search Tree (BST) and an integer `key`, determine whether a node with value `key` exists in the BST.

Return:

```text
true
```

if the key is present.

Otherwise, return:

```text
false
```

---

# What is a Binary Search Tree?

A Binary Search Tree follows this property:

```text
        Root
       /    \
   Smaller  Greater
```

For every node:

```text
Left Subtree  <  Node  <  Right Subtree
```

Because of this property, we don't need to search the entire tree.

We can decide whether to go **left or right** based on the value of `key`.

---

# Example 1
<img width="444" height="400" alt="blobid0_1760333323" src="https://github.com/user-attachments/assets/97f7ac2d-fdb9-4dbd-b928-bc7472be3896" />

### Input

```text
root = [6, 2, 8, N, N, 7, 9]
key = 8
```

Tree:

```text
        6
       / \
      2   8
         / \
        7   9
```

Search:

```text
key = 8
```

Start at `6`:

```text
6 < 8
```

Therefore, go right.

```text
        6
         \
          8  ← Found
```

### Output

```text
true
```

---

# Example 2
<img width="444" height="400" alt="blobid1_1760333335" src="https://github.com/user-attachments/assets/95d3d7c4-1b6b-4f97-b402-c96f2cb68d5a" />

### Input

```text
root = [16, 12, 18, 10, N, 17, 19]
key = 14
```

Tree:

```text
          16
         /  \
       12    18
      /     /  \
    10     17   19
```

Search for:

```text
key = 14
```

Start at `16`:

```text
16 > 14
```

Go left.

At `12`:

```text
12 < 14
```

Go right.

But `12` has no right child.

Therefore, `14` does not exist.

### Output

```text
false
```

---

# Approach

The BST property allows us to eliminate half of the possible search space at every step.

For every node:

### Case 1 — Node is NULL

The key doesn't exist in this subtree.

Return:

```cpp
false
```

---

### Case 2 — Node value equals key

We found the key.

Return:

```cpp
true
```

---

### Case 3 — Node value is smaller than key

If:

```text
root->data < key
```

then the key can only be in the **right subtree**.

So:

```cpp
search(root->right, key)
```

---

### Case 4 — Node value is greater than key

If:

```text
root->data > key
```

then the key can only be in the **left subtree**.

So:

```cpp
search(root->left, key)
```

---

# Algorithm

1. Start from the root.
2. If `root == NULL`, return `false`.
3. If `root->data == key`, return `true`.
4. If `root->data < key`, search the right subtree.
5. Otherwise, search the left subtree.
6. Continue until the key is found or a `NULL` node is reached.

---

# C++ Solution

```cpp
class Solution {
public:

    bool search(Node* root, int key) {

        if(root == NULL) {
            return false;
        }

        if(root->data == key) {
            return true;
        }

        if(root->data < key) {

            return search(root->right, key);
        }

        else {

            return search(root->left, key);
        }
    }
};
```

---

# Detailed Dry Run

Consider:

```text
root = [6, 2, 8, N, N, 7, 9]
key = 9
```

Tree:

```text
        6
       / \
      2   8
         / \
        7   9
```

---

## Step 1

Current node:

```text
root = 6
key = 9
```

Compare:

```text
6 == 9 ❌
```

Then:

```text
6 < 9
```

So go right:

```text
search(root->right, 9)
```

---

## Step 2

Current node:

```text
root = 8
```

Compare:

```text
8 == 9 ❌
```

Then:

```text
8 < 9
```

Go right:

```text
search(root->right, 9)
```

---

## Step 3

Current node:

```text
root = 9
```

Compare:

```text
9 == 9
```

True.

Return:

```text
true
```

---

# Dry Run for Missing Key

Consider:

```text
root = [6, 2, 8, N, N, 7, 9]
key = 5
```

Tree:

```text
        6
       / \
      2   8
         / \
        7   9
```

### Step 1

At `6`:

```text
6 > 5
```

Go left.

```text
        6
       /
      2
```

### Step 2

At `2`:

```text
2 < 5
```

Go right.

But:

```text
2->right = NULL
```

Therefore:

```text
search(NULL, 5)
```

returns:

```text
false
```

---

# Why Don't We Search Both Sides?

In a normal Binary Tree, if we want to find a value, we may need to search:

```text
Left
 +
Right
```

But in a BST, we have an advantage.

Suppose:

```text
        10
       /  \
      5    15
```

Search for:

```text
13
```

Since:

```text
10 < 13
```

we know `13` **cannot be in the left subtree**, because every value in the left subtree is smaller than `10`.

Therefore, we only search:

```text
Right subtree
```

This is the main advantage of a BST.

---

# Search Decision

Remember this simple rule:

```text
              root
                |
        ┌───────┴───────┐
        ↓               ↓
 root->data > key   root->data < key
        ↓               ↓
      LEFT             RIGHT
```

Or simply:

```text
key < root->data  → LEFT
key > root->data  → RIGHT
key == root->data → FOUND
```

---

# Recursive Flow

```text
                Start
                  ↓
            root == NULL?
             /         \
           YES          NO
            ↓            ↓
         false      root == key?
                       /     \
                     YES      NO
                      ↓        ↓
                    true    Compare
                              /   \
                         key < root  key > root
                             ↓          ↓
                           LEFT       RIGHT
```

---

# Complexity Analysis

Let `H` be the height of the BST.

### Time Complexity

We visit only one path from the root to a node.

Therefore:

```text
O(H)
```

For a balanced BST:

```text
H = log N
```

So:

```text
O(log N)
```

For a skewed BST:

```text
H = N
```

So worst case:

```text
O(N)
```

---

### Space Complexity

Because we use recursion, the recursion stack depends on the tree height:

```text
O(H)
```

Balanced tree:

```text
O(log N)
```

Worst-case skewed tree:

```text
O(N)
```

---

# Balanced vs Skewed BST

### Balanced BST

```text
          8
        /   \
       4     12
      / \   /  \
     2   6 10   14
```

Height:

```text
O(log N)
```

Search:

```text
O(log N)
```

---

### Skewed BST

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

Height:

```text
O(N)
```

Search:

```text
O(N)
```

---

# Edge Cases

## 1. Empty Tree

```text
root = NULL
```

Output:

```text
false
```

---

## 2. Key is Root

```text
        10
       /  \
      5    15
```

Search:

```text
key = 10
```

Immediately:

```text
10 == 10
```

Return:

```text
true
```

---

## 3. Key is Leaf

```text
        10
       /  \
      5    15
```

Search:

```text
key = 5
```

Path:

```text
10 → 5
```

Return:

```text
true
```

---

## 4. Key Doesn't Exist

```text
        10
       /  \
      5    15
```

Search:

```text
key = 7
```

Path:

```text
10 → 5 → NULL
```

Return:

```text
false
```

---

# Common Mistakes

### ❌ Mistake 1 — Searching Both Subtrees

Don't do:

```cpp
search(root->left, key);
search(root->right, key);
```

That ignores the BST property.

Instead:

```cpp
if(root->data < key)
    return search(root->right, key);
else
    return search(root->left, key);
```

---

### ❌ Mistake 2 — Wrong Direction

Remember:

```text
key > root->data → RIGHT
```

and:

```text
key < root->data → LEFT
```

---

### ❌ Mistake 3 — Forgetting NULL Case

Always handle:

```cpp
if(root == NULL)
    return false;
```

Otherwise, you may dereference a null pointer.

---

### ❌ Mistake 4 — Unnecessary Final Return

Your original code has:

```cpp
return false;
```

after all branches.

It is unreachable because every previous branch already returns.

You can remove it.

---

# Interview Explanation

If asked to explain the solution:

> "Since this is a Binary Search Tree, I use its ordering property. If the current node's value equals the key, I return true. If the current value is smaller than the key, I search only the right subtree. Otherwise, I search only the left subtree. If I reach NULL, the key is not present, so I return false."

---

# Key Concepts

* Binary Search Tree
* Recursion
* BST Property
* Searching
* Left Subtree
* Right Subtree
* Tree Height

---

# Quick Revision

Remember:

```text
key == root->data
        ↓
      FOUND
```

```text
key > root->data
        ↓
      RIGHT
```

```text
key < root->data
        ↓
       LEFT
```

And:

```text
root == NULL
     ↓
   false
```

---

# Final Code

```cpp
class Solution {
public:

    bool search(Node* root, int key) {

        if(root == NULL) {
            return false;
        }

        if(root->data == key) {
            return true;
        }

        if(root->data < key) {
            return search(root->right, key);
        }

        return search(root->left, key);
    }
};
```

---

# Summary

| Feature           | Details              |
| ----------------- | -------------------- |
| Problem           | Search a Node in BST |
| Difficulty        | Easy                 |
| Approach          | Recursion            |
| Data Structure    | Binary Search Tree   |
| Key Property      | Left < Root < Right  |
| Balanced Time     | `O(log N)`           |
| Worst Time        | `O(N)`               |
| Auxiliary Space   | `O(H)`               |
| Successful Search | Return `true`        |
| Failed Search     | Return `false`       |

## 🧠 Final Takeaway

BST searching is simple because **you never need to search both sides**.

```text
             Root
            /    \
        Smaller  Greater
           ↓        ↓
          LEFT     RIGHT
```

So just remember:

**Smaller → Left | Greater → Right | Equal → Found.** 🌳🔍
