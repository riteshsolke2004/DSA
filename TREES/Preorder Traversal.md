# 🌳  Binary Tree Preorder Traversal

## Problem Statement

Given the `root` of a binary tree, return the **Preorder Traversal** of its nodes' values.

In **Preorder Traversal**, nodes are visited in the following order:

```text
ROOT → LEFT → RIGHT
```

This means:

1. Visit the current/root node.
2. Traverse the entire left subtree.
3. Traverse the entire right subtree.

---

# Example 1
<img width="254" height="335" alt="screenshot-2024-08-29-202743" src="https://github.com/user-attachments/assets/59093d9e-bca9-433f-9f8a-ffc7f413fbf8" />

### Input

```text
root = [1, null, 2, 3]
```

Binary Tree:

```text
    1
     \
      2
     /
    3
```

Preorder traversal:

```text
1 → 2 → 3
```

### Output

```text
[1, 2, 3]
```

---

# Example 2
<img width="524" height="428" alt="tree_2" src="https://github.com/user-attachments/assets/75aa2e7f-f749-4041-b081-31af0f334247" />

### Input

```text
root = [1,2,3,4,5,null,8,null,null,6,7,9]
```

Binary Tree:

```text
              1
            /   \
           2     3
          / \     \
         4   5     8
            / \   /
           6   7 9
```

Preorder follows:

```text
ROOT → LEFT → RIGHT
```

Traversal:

```text
1 → 2 → 4 → 5 → 6 → 7 → 3 → 8 → 9
```

### Output

```text
[1,2,4,5,6,7,3,8,9]
```

---

# Example 3

### Input

```text
root = []
```

The tree is empty.

### Output

```text
[]
```

---

# Example 4

### Input

```text
root = [1]
```

Binary Tree:

```text
1
```

### Output

```text
[1]
```

---

# Preorder Traversal

The most important thing to remember is:

```text
ROOT → LEFT → RIGHT
```

For example:

```text
        1
       / \
      2   3
     / \
    4   5
```

Preorder:

```text
1 → 2 → 4 → 5 → 3
```

---

# Approach — Recursion

We can solve this problem using **DFS (Depth First Search)** and recursion.

For every node:

### Step 1 — Visit Root

First add the current node to the answer:

```cpp
ans.push_back(root->val);
```

### Step 2 — Traverse Left

```cpp
preorder(root->left, ans);
```

### Step 3 — Traverse Right

```cpp
preorder(root->right, ans);
```

Therefore, the pattern is:

```text
ROOT
 ↓
LEFT
 ↓
RIGHT
```

---

# Base Case

If the current node is `NULL`, there is nothing to process.

```cpp
if(root == NULL) {
    return;
}
```

This stops the recursion.

---

# Recursive Formula

Conceptually:

```text
preorder(root):

    if root == NULL
        return

    visit root

    preorder(left)

    preorder(right)
```

---

# C++ Solution

```cpp
class Solution {
public:

    void preorder(TreeNode* root, vector<int>& ans) {

        if(root == NULL) {
            return;
        }

        ans.push_back(root->val);

        preorder(root->left, ans);

        preorder(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> ans;

        preorder(root, ans);

        return ans;
    }
};
```

---

# Dry Run

Consider:

```text
        1
       / \
      2   3
     / \
    4   5
```

Call:

```text
preorder(1)
```

Initially:

```text
ans = []
```

---

## Step 1 — Node 1

Current node:

```text
1
```

Preorder says:

```text
ROOT → LEFT → RIGHT
```

So first add `1`.

```text
ans = [1]
```

Then:

```text
preorder(2)
```

---

## Step 2 — Node 2

Current:

```text
2
```

Add `2`.

```text
ans = [1,2]
```

Now traverse left:

```text
preorder(4)
```

---

## Step 3 — Node 4

Current:

```text
4
```

Add `4`.

```text
ans = [1,2,4]
```

Left child is `NULL`.

Return.

Right child is `NULL`.

Return to node `2`.

---

## Step 4 — Back to Node 2

Now process the right subtree:

```text
preorder(5)
```

Node `5` is added:

```text
ans = [1,2,4,5]
```

Both children are `NULL`.

Return to node `1`.

---

## Step 5 — Back to Node 1

The entire left subtree is complete.

Now process right subtree:

```text
preorder(3)
```

Add `3`:

```text
ans = [1,2,4,5,3]
```

Both children are `NULL`.

---

# Final Answer

```text
[1,2,4,5,3]
```

---

# Recursion Tree

For:

```text
        1
       / \
      2   3
     / \
    4   5
```

The calls look like:

```text
                    preorder(1)
                   /           \
                  /             \
           preorder(2)      preorder(3)
            /       \
           /         \
    preorder(4)   preorder(5)
```

But remember:

**The current node is added before making the recursive calls.**

Therefore:

```text
1
↓
2
↓
4
↓
5
↓
3
```

Final:

```text
[1,2,4,5,3]
```

---

# Why Is Root Added First?

Compare Preorder and Inorder.

### Preorder

```text
ROOT → LEFT → RIGHT
```

So:

```cpp
ans.push_back(root->val);

preorder(root->left, ans);

preorder(root->right, ans);
```

### Inorder

```text
LEFT → ROOT → RIGHT
```

So:

```cpp
inorder(root->left, ans);

ans.push_back(root->val);

inorder(root->right, ans);
```

The position of:

```cpp
ans.push_back(root->val);
```

determines the traversal type.

---

# Preorder vs Inorder vs Postorder

| Traversal     | Order                   |
| ------------- | ----------------------- |
| **Preorder**  | **ROOT → LEFT → RIGHT** |
| **Inorder**   | **LEFT → ROOT → RIGHT** |
| **Postorder** | **LEFT → RIGHT → ROOT** |

### Easy Trick

The `LEFT` and `RIGHT` always remain in the same order.

Only the position of `ROOT` changes.

```text
Preorder:
ROOT LEFT RIGHT

Inorder:
LEFT ROOT RIGHT

Postorder:
LEFT RIGHT ROOT
```

---

# Edge Cases

## 1. Empty Tree

```text
root = []
```

The root is `NULL`.

```cpp
if(root == NULL)
    return;
```

Therefore:

```text
[]
```

---

## 2. Single Node

```text
    1
```

Output:

```text
[1]
```

---

## 3. Left-Skewed Tree

```text
    1
   /
  2
 /
3
```

Preorder:

```text
1 → 2 → 3
```

Output:

```text
[1,2,3]
```

---

## 4. Right-Skewed Tree

```text
1
 \
  2
   \
    3
```

Preorder:

```text
1 → 2 → 3
```

Output:

```text
[1,2,3]
```

---

# Complexity Analysis

Let:

```text
N = number of nodes
```

Every node is visited exactly once.

### Time Complexity

```text
O(N)
```

### Space Complexity

The recursion stack depends on the height of the tree.

For a balanced tree:

```text
O(log N)
```

For a skewed tree:

```text
O(N)
```

Therefore, worst-case auxiliary space is:

```text
O(N)
```

The output vector itself requires:

```text
O(N)
```

space.

---

# Key Concepts

* Binary Tree
* DFS
* Recursion
* Preorder Traversal
* Vector
* Tree Traversal

---

# Important Pattern

Remember:

```text
PREORDER

        ROOT
       /    \
    LEFT    RIGHT

        ↓

ROOT → LEFT → RIGHT
```

The core code is:

```cpp
ans.push_back(root->val);

preorder(root->left, ans);

preorder(root->right, ans);
```

---

# Final Code

```cpp
class Solution {
public:

    void preorder(TreeNode* root, vector<int>& ans) {

        if(root == NULL) {
            return;
        }

        ans.push_back(root->val);

        preorder(root->left, ans);

        preorder(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> ans;

        preorder(root, ans);

        return ans;
    }
};
```

---

# Summary

| Concept     | Details                        |
| ----------- | ------------------------------ |
| Problem     | Binary Tree Preorder Traversal |
| LeetCode    | 144                            |
| Difficulty  | Easy                           |
| Approach    | DFS + Recursion                |
| Traversal   | `ROOT → LEFT → RIGHT`          |
| Base Case   | `root == NULL`                 |
| Time        | `O(N)`                         |
| Worst Space | `O(N)`                         |

## 🧠 Remember

**Preorder = ROOT first.**

```text
ROOT → LEFT → RIGHT
```

That's the key pattern for LeetCode **144. Binary Tree Preorder Traversal**. 🌳
