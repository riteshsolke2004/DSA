# 🌳 Inorder Traversal of Binary Tree

## Problem Statement

Given the `root` of a Binary Tree, return its **Inorder Traversal**.

In an **Inorder Traversal**, we visit the nodes in the following order:

```text
LEFT → ROOT → RIGHT
```

This means:

1. Traverse the entire **left subtree**.
2. Visit the **current/root node**.
3. Traverse the entire **right subtree**.

---

# Example 1

<img width="450" height="312" alt="blobid0_1758796476" src="https://github.com/user-attachments/assets/4afa5a9b-872d-480e-82f7-a0030f265e53" />

### Input

```text
root = [1, 2, 3, 4, 5]
```

Binary Tree:

```text
        1
       / \
      2   3
     / \
    4   5
```

### Inorder Traversal

Start from root `1`.

First traverse the left subtree:

```text
        2
       / \
      4   5
```

Its inorder traversal is:

```text
4 → 2 → 5
```

Then visit root:

```text
1
```

Then traverse the right subtree:

```text
3
```

Therefore:

```text
4 → 2 → 5 → 1 → 3
```

### Output

```text
[4, 2, 5, 1, 3]
```

---

# Example 2
<img width="385" height="400" alt="blobid1_1758796530" src="https://github.com/user-attachments/assets/caaeb701-3cdf-4d5c-9b62-44f0d6cebb31" />

### Input

```text
root = [8, 1, 5, N, 7, 10, 6, N, 10, 6]
```

### Output

```text
[1, 7, 10, 8, 6, 10, 5, 6]
```

The nodes are visited using:

```text
LEFT → ROOT → RIGHT
```

---

# Inorder Traversal Rule

The most important pattern to remember is:

```text
LEFT → ROOT → RIGHT
```

Or:

```text
        ROOT
        /  \
       /    \
    LEFT    RIGHT

Traversal:

LEFT
 ↓
ROOT
 ↓
RIGHT
```

---

# Recursive Approach

We can solve Inorder Traversal using **recursion / DFS**.

For every node:

### Step 1

Traverse its left subtree:

```cpp
inorder(root->left, ans);
```

### Step 2

Visit the current node:

```cpp
ans.push_back(root->data);
```

### Step 3

Traverse its right subtree:

```cpp
inorder(root->right, ans);
```

---

# Base Case

If the current node is `NULL`:

```cpp
if(root == NULL) {
    return;
}
```

There is nothing to traverse, so return to the previous recursive call.

---

# Recursive Formula

Conceptually:

```text
inorder(root):

    if root == NULL
        return

    inorder(left)

    visit root

    inorder(right)
```

Or simply:

```text
LEFT
ROOT
RIGHT
```

---

# C++ Solution

```cpp
class Solution {
public:

    void inorder(Node* root, vector<int>& ans) {

        if(root == NULL) {
            return;
        }

        inorder(root->left, ans);

        ans.push_back(root->data);

        inorder(root->right, ans);
    }

    vector<int> inOrder(Node* root) {

        vector<int> ans;

        inorder(root, ans);

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

We call:

```text
inorder(1)
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

According to Inorder:

```text
LEFT → ROOT → RIGHT
```

So first call:

```text
inorder(2)
```

---

## Step 2 — Node 2

Current:

```text
2
```

Again, first go left:

```text
inorder(4)
```

---

## Step 3 — Node 4

Current:

```text
4
```

First call:

```text
inorder(4->left)
```

But:

```text
4->left = NULL
```

So:

```text
inorder(NULL)
```

returns immediately.

Now visit `4`:

```cpp
ans.push_back(4);
```

Answer becomes:

```text
ans = [4]
```

Now go right:

```text
inorder(4->right)
```

Right is also `NULL`.

Return to node `2`.

---

## Step 4 — Back to Node 2

We have completed the left subtree.

Now visit node `2`:

```cpp
ans.push_back(2);
```

Answer:

```text
ans = [4, 2]
```

Now traverse its right subtree:

```text
inorder(5)
```

---

## Step 5 — Node 5

First go left:

```text
NULL
```

Return.

Visit `5`:

```text
ans = [4, 2, 5]
```

Go right:

```text
NULL
```

Return.

Now the complete left subtree of `1` has been processed.

---

## Step 6 — Back to Node 1

Current answer:

```text
[4, 2, 5]
```

Now visit root `1`:

```cpp
ans.push_back(1);
```

Answer:

```text
[4, 2, 5, 1]
```

Now traverse right:

```text
inorder(3)
```

---

## Step 7 — Node 3

Go left:

```text
NULL
```

Return.

Visit `3`:

```text
ans = [4, 2, 5, 1, 3]
```

Go right:

```text
NULL
```

Return.

---

# Final Answer

```text
[4, 2, 5, 1, 3]
```

---

# Recursive Call Flow

For:

```text
        1
       / \
      2   3
     / \
    4   5
```

The recursive calls happen like:

```text
                    inorder(1)
                   /          \
                  /            \
           inorder(2)       inorder(3)
            /      \
           /        \
    inorder(4)    inorder(5)
```

But remember, the node is added to the answer **between the left and right recursive calls**.

Therefore:

```text
4
↓
2
↓
5
↓
1
↓
3
```

Final:

```text
[4, 2, 5, 1, 3]
```

---

# Code Execution Flow

The core code is:

```cpp
inorder(root->left, ans);

ans.push_back(root->data);

inorder(root->right, ans);
```

For node `1`:

```text
inorder(2)
     ↓
[4, 2, 5]

push(1)
     ↓
[4, 2, 5, 1]

inorder(3)
     ↓
[4, 2, 5, 1, 3]
```

---

# Why Pass `ans` by Reference?

Notice:

```cpp
void inorder(Node* root, vector<int>& ans)
```

We use:

```cpp
vector<int>& ans
```

instead of:

```cpp
vector<int> ans
```

The `&` means the vector is passed **by reference**.

This allows every recursive call to modify the **same answer vector**.

For example:

```text
Call inorder(4)

ans = [4]

Return to inorder(2)

ans = [4, 2]

Call inorder(5)

ans = [4, 2, 5]
```

All recursive calls work on the same vector.

Without `&`, every function call would receive its own copy of the vector.

---

# Base Case Explanation

The base case is:

```cpp
if(root == NULL) {
    return;
}
```

Consider a leaf node:

```text
    4
   / \
NULL NULL
```

When we call:

```text
inorder(4)
```

first:

```text
inorder(NULL)
```

returns.

Then:

```text
visit 4
```

Then:

```text
inorder(NULL)
```

returns.

This correctly processes the leaf node.

---

# Complexity Analysis

Let:

```text
N = total number of nodes
```

Every node is visited exactly once.

Therefore:

### Time Complexity

```text
O(N)
```

---

### Space Complexity

The recursive call stack depends on the height of the tree.

For a balanced tree:

```text
O(log N)
```

For a skewed tree:

```text
1
 \
  2
   \
    3
     \
      4
```

The recursion depth can become:

```text
O(N)
```

Therefore, worst-case auxiliary space:

```text
O(N)
```

The output vector also stores `N` elements.

---

# Edge Cases

## 1. Empty Tree

```text
root = NULL
```

The function immediately returns.

Output:

```text
[]
```

---

## 2. Single Node

```text
    10
```

Traversal:

```text
LEFT → NULL
ROOT → 10
RIGHT → NULL
```

Output:

```text
[10]
```

---

## 3. Left-Skewed Tree

```text
        4
       /
      3
     /
    2
   /
  1
```

Inorder:

```text
1 → 2 → 3 → 4
```

Output:

```text
[1, 2, 3, 4]
```

---

## 4. Right-Skewed Tree

```text
1
 \
  2
   \
    3
     \
      4
```

Inorder:

```text
1 → 2 → 3 → 4
```

Output:

```text
[1, 2, 3, 4]
```

---

# Binary Tree Traversal Comparison

There are three main DFS traversals.

| Traversal   | Order                     |
| ----------- | ------------------------- |
| Preorder    | `ROOT → LEFT → RIGHT`     |
| **Inorder** | **`LEFT → ROOT → RIGHT`** |
| Postorder   | `LEFT → RIGHT → ROOT`     |

The position of **ROOT** changes.

### Preorder

```text
ROOT
LEFT
RIGHT
```

### Inorder

```text
LEFT
ROOT
RIGHT
```

### Postorder

```text
LEFT
RIGHT
ROOT
```

---

# Easy Trick to Remember

For all three DFS traversals:

```text
LEFT and RIGHT stay in the same order.
```

Only the position of `ROOT` changes.

```text
Preorder  → ROOT LEFT RIGHT

Inorder   → LEFT ROOT RIGHT

Postorder → LEFT RIGHT ROOT
```

For this problem, remember:

```text
INORDER
   ↓
LEFT → ROOT → RIGHT
```

---

# Final Code

```cpp
class Solution {
public:

    void inorder(Node* root, vector<int>& ans) {

        if(root == NULL) {
            return;
        }

        inorder(root->left, ans);

        ans.push_back(root->data);

        inorder(root->right, ans);
    }

    vector<int> inOrder(Node* root) {

        vector<int> ans;

        inorder(root, ans);

        return ans;
    }
};
```

---

# Summary

| Concept                | Details               |
| ---------------------- | --------------------- |
| Problem                | Inorder Traversal     |
| Difficulty             | Easy                  |
| Data Structure         | Binary Tree           |
| Technique              | DFS + Recursion       |
| Traversal Order        | `LEFT → ROOT → RIGHT` |
| Base Case              | `root == NULL`        |
| Time Complexity        | `O(N)`                |
| Worst Space Complexity | `O(N)`                |

## 🧠 Pattern to Remember

```text
INORDER TRAVERSAL

        ROOT
       /    \
    LEFT    RIGHT

         ↓

    LEFT
      ↓
    ROOT
      ↓
    RIGHT
```

Core recursive pattern:

```cpp
inorder(root->left, ans);

ans.push_back(root->data);

inorder(root->right, ans);
```

**Inorder = LEFT → ROOT → RIGHT** 🌳
