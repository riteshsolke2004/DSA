# 🌳 Postorder Traversal of Binary Tree

## Problem Statement

Given the `root` of a Binary Tree, return its **Postorder Traversal**.

In **Postorder Traversal**, nodes are visited in the following order:

```text
LEFT → RIGHT → ROOT
```

This means:

1. Traverse the entire **left subtree**.
2. Traverse the entire **right subtree**.
3. Visit the **current/root node**.

---

# Example 1

<img width="443" height="444" alt="blobid0_1752318711" src="https://github.com/user-attachments/assets/ca1210ee-c065-438a-aca3-d54522f7955f" />

### Input

```text
root = [19, 10, 8, 11, 13]
```

Binary Tree:

```text
        19
       /  \
     10    8
    /  \
   11  13
```

Postorder follows:

```text
LEFT → RIGHT → ROOT
```

### Traversal

First visit the left subtree of `19`:

```text
11 → 13 → 10
```

Then visit the right subtree:

```text
8
```

Finally visit the root:

```text
19
```

Therefore:

```text
11 → 13 → 10 → 8 → 19
```

### Output

```text
[11, 13, 10, 8, 19]
```

---

# Example 2
<img width="330" height="444" alt="blobid1_1752318749" src="https://github.com/user-attachments/assets/da6feae2-a407-492f-88fb-2e6c56599d35" />
### Input

```text
root = [11, 15, N, 7]
```

Binary Tree:

```text
      11
     /
    15
   /
  7
```

Postorder:

```text
7 → 15 → 11
```

### Output

```text
[7, 15, 11]
```

---

# Postorder Traversal Rule

The most important pattern to remember:

```text
LEFT → RIGHT → ROOT
```

For example:

```text
        1
       / \
      2   3
     / \
    4   5
```

Postorder traversal:

```text
4 → 5 → 2 → 3 → 1
```

---

# Approach — Recursion

We can solve this problem using **DFS (Depth First Search)** and recursion.

For every node:

### Step 1 — Traverse Left

```cpp
postorder(root->left, ans);
```

### Step 2 — Traverse Right

```cpp
postorder(root->right, ans);
```

### Step 3 — Visit Root

```cpp
ans.push_back(root->val);
```

So the pattern is:

```text
LEFT
 ↓
RIGHT
 ↓
ROOT
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
postorder(root):

    if root == NULL
        return

    postorder(left)

    postorder(right)

    visit root
```

---

# C++ Solution

```cpp
class Solution {
public:

    void postorder(TreeNode* root, vector<int>& ans) {

        if(root == NULL) {
            return;
        }

        postorder(root->left, ans);

        postorder(root->right, ans);

        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> ans;

        postorder(root, ans);

        return ans;
    }
};
```

---

# Dry Run

Consider this tree:

```text
        1
       / \
      2   3
     / \
    4   5
```

Call:

```text
postorder(1)
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

Postorder says:

```text
LEFT → RIGHT → ROOT
```

So first:

```text
postorder(2)
```

---

## Step 2 — Node 2

Current node:

```text
2
```

First go to its left:

```text
postorder(4)
```

---

## Step 3 — Node 4

Node `4` is a leaf.

First:

```text
postorder(NULL)
```

Return.

Then:

```text
postorder(NULL)
```

Return.

Now visit `4`:

```text
ans = [4]
```

Return to node `2`.

---

## Step 4 — Back to Node 2

The left subtree is complete.

Now process the right subtree:

```text
postorder(5)
```

Node `5` is a leaf.

After processing both NULL children:

```text
ans = [4, 5]
```

Return to node `2`.

Now both left and right subtrees are complete.

Visit node `2`:

```text
ans = [4, 5, 2]
```

---

## Step 5 — Back to Node 1

The entire left subtree is complete:

```text
[4, 5, 2]
```

Now process the right subtree:

```text
postorder(3)
```

Node `3` is a leaf.

After processing its children:

```text
ans = [4, 5, 2, 3]
```

Return to node `1`.

---

## Step 6 — Visit Root

Both subtrees of `1` are now complete.

Finally visit `1`:

```text
ans = [4, 5, 2, 3, 1]
```

---

# Final Answer

```text
[4, 5, 2, 3, 1]
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

The recursive calls look like:

```text
                    postorder(1)
                   /            \
                  /              \
           postorder(2)      postorder(3)
            /       \
           /         \
    postorder(4)   postorder(5)
```

But the current node is added **after both recursive calls**.

Therefore:

```text
4
↓
5
↓
2
↓
3
↓
1
```

Final:

```text
[4, 5, 2, 3, 1]
```

---

# Why Is Root Added Last?

This is the key difference between the three DFS traversals.

### Preorder

Root is added first:

```text
ROOT → LEFT → RIGHT
```

### Inorder

Root is added between left and right:

```text
LEFT → ROOT → RIGHT
```

### Postorder

Root is added last:

```text
LEFT → RIGHT → ROOT
```

In code:

```cpp
// Preorder
ans.push_back(root->val);
preorder(root->left, ans);
preorder(root->right, ans);
```

```cpp
// Inorder
inorder(root->left, ans);
ans.push_back(root->val);
inorder(root->right, ans);
```

```cpp
// Postorder
postorder(root->left, ans);
postorder(root->right, ans);
ans.push_back(root->val);
```

---

# Preorder vs Inorder vs Postorder

| Traversal     | Order                     | Root Position |
| ------------- | ------------------------- | ------------- |
| Preorder      | `ROOT → LEFT → RIGHT`     | First         |
| Inorder       | `LEFT → ROOT → RIGHT`     | Middle        |
| **Postorder** | **`LEFT → RIGHT → ROOT`** | **Last**      |

### Easy Trick

Remember where **ROOT** is placed:

```text
Preorder:
ROOT LEFT RIGHT
↑

Inorder:
LEFT ROOT RIGHT
     ↑

Postorder:
LEFT RIGHT ROOT
           ↑
```

---

# Edge Cases

## 1. Empty Tree

```text
root = []
```

Since:

```cpp
root == NULL
```

the function returns immediately.

Output:

```text
[]
```

---

## 2. Single Node

```text
    10
```

Postorder:

```text
10
```

Output:

```text
[10]
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

Postorder:

```text
3 → 2 → 1
```

Output:

```text
[3, 2, 1]
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

Postorder:

```text
3 → 2 → 1
```

Output:

```text
[3, 2, 1]
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

For a completely skewed tree:

```text
O(N)
```

Therefore, worst-case auxiliary space:

```text
O(N)
```

The answer vector itself requires:

```text
O(N)
```

space.

---

# Important Concept

The most important thing to remember:

> **In Postorder Traversal, the root is processed only after both subtrees are completely processed.**

```text
        ROOT
       /    \
    LEFT    RIGHT

        ↓

    LEFT
      ↓
    RIGHT
      ↓
    ROOT
```

---

# Core Code Pattern

```cpp
postorder(root->left, ans);

postorder(root->right, ans);

ans.push_back(root->val);
```

This is the complete Postorder pattern:

```text
LEFT → RIGHT → ROOT
```

---

# Final Code

```cpp
class Solution {
public:

    void postorder(TreeNode* root, vector<int>& ans) {

        if(root == NULL) {
            return;
        }

        postorder(root->left, ans);

        postorder(root->right, ans);

        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> ans;

        postorder(root, ans);

        return ans;
    }
};
```

---

# Summary

| Concept                | Details               |
| ---------------------- | --------------------- |
| Problem                | Postorder Traversal   |
| Difficulty             | Easy                  |
| Approach               | DFS + Recursion       |
| Traversal Order        | `LEFT → RIGHT → ROOT` |
| Base Case              | `root == NULL`        |
| Time Complexity        | `O(N)`                |
| Worst Space Complexity | `O(N)`                |

## 🧠 Remember

**Postorder = ROOT last.**

```text
LEFT → RIGHT → ROOT
```

The key code is:

```cpp
postorder(root->left, ans);
postorder(root->right, ans);
ans.push_back(root->val);
```

That single ordering is the heart of **Postorder Traversal**. 🌳
