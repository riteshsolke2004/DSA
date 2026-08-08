# 🌳 110. Balanced Binary Tree

## Problem Statement

Given a binary tree, determine whether it is **height-balanced**.

A binary tree is **height-balanced** if, for **every node**, the difference between the height of its left subtree and the height of its right subtree is at most `1`.

In other words:

```text id="c1f8ae"
| leftHeight - rightHeight | <= 1
```

This condition must be true for **every node** in the tree.

---

# Example 1
<img width="342" height="221" alt="balance_1" src="https://github.com/user-attachments/assets/d51cb9d6-3dd1-4e16-804f-7120356feb24" />

### Input

```text id="a7z4k2"
root = [3,9,20,null,null,15,7]
```

Binary Tree:

```text id="c7h9kp"
        3
       / \
      9   20
         /  \
        15   7
```

At node `3`:

```text id="g8w3bn"
left height  = 1
right height = 2
```

Difference:

```text id="m3y8vp"
|1 - 2| = 1
```

At every other node, the difference is also at most `1`.

Therefore:

```text id="y6w1hs"
Output = true
```

---

# Example 2
<img width="452" height="301" alt="balance_2" src="https://github.com/user-attachments/assets/74b0f403-8c6f-4987-9118-a8d5c0964b32" />

### Input

```text id="q8m2ls"
root = [1,2,2,3,3,null,null,4,4]
```

Binary Tree:

```text id="m6f8xp"
          1
        /   \
       2     2
      / \
     3   3
    / \
   4   4
```

At node `1`, the left subtree is much deeper than the right subtree.

At some nodes:

```text id="z9k4tb"
|leftHeight - rightHeight| > 1
```

Therefore:

```text id="g3v7nm"
Output = false
```

---

# Example 3

### Input

```text id="t8p3qx"
root = []
```

The tree is empty.

An empty tree is considered balanced.

Therefore:

```text id="k4x7va"
Output = true
```

---

# What is a Height-Balanced Tree?

For every node:

```text id="z7y2mc"
        Node
       /    \
      /      \
   Left      Right
```

Calculate:

```text id="9r5vks"
leftHeight
rightHeight
```

Then:

```text id="2l0z5n"
difference = |leftHeight - rightHeight|
```

The tree is balanced only if:

```text id="v6h8qa"
difference <= 1
```

for **every node**.

---

# Important Point

It is **not enough** to check only the root.

For example:

```text id="1o3r6x"
        1
       / \
      2   3
     /
    4
   /
  5
```

The root may appear to have a small height difference, but deeper inside the tree there can be an unbalanced subtree.

Therefore, we must check:

```text id="h5m8w2"
Root
 ↓
Left subtree
 ↓
Right subtree
```

---

# Approach Used in Your Code

Your solution uses two functions:

```cpp id="r8y3kp"
getheight()
```

and:

```cpp id="p2x6mz"
isBalanced()
```

### `getheight()`

Calculates the height of a subtree.

### `isBalanced()`

Checks:

1. Height difference at the current node.
2. Whether the left subtree is balanced.
3. Whether the right subtree is balanced.

---

# Step 1 — Calculate Height

Your function:

```cpp id="0p5g8s"
int getheight(TreeNode* root)
```

calculates the height of the tree.

Base case:

```cpp id="x7m2qa"
if(root == NULL) {
    return 0;
}
```

For a non-null node:

```cpp id="z3k8vp"
int leftDepth = getheight(root->left);
int rightDepth = getheight(root->right);
```

Then:

```cpp id="w9n4lc"
return max(leftDepth, rightDepth) + 1;
```

---

# Height Formula

For every node:

```text id="2u8x9f"
height =
1 + max(leftHeight, rightHeight)
```

Example:

```text id="8q3n5m"
      1
     /
    2
   /
  3
```

Height of node `3`:

```text id="z4v1ks"
1
```

Height of node `2`:

```text id="q6b8py"
1 + max(1,0)
= 2
```

Height of node `1`:

```text id="n3s7dm"
1 + max(2,0)
= 3
```

---

# Step 2 — Check Balance

At the current node:

```cpp id="8w4p1z"
int leftheight = getheight(root->left);
int rightheight = getheight(root->right);
```

Calculate:

```cpp id="v2m7sx"
int absDiff = abs(leftheight - rightheight);
```

If:

```cpp id="x9q3jd"
absDiff > 1
```

the tree is not balanced.

Return:

```cpp id="r7n2kc"
false
```

---

# Step 3 — Check Left and Right Subtrees

If the current node is balanced:

```cpp id="p8v5mz"
bool leftans = isBalanced(root->left);
bool rightans = isBalanced(root->right);
```

Both must be balanced.

Therefore:

```text id="q4n9xs"
leftans && rightans
```

must be `true`.

---

# C++ Solution — Your Approach

```cpp id="a8s3km"
class Solution {
public:

    int getheight(TreeNode* root) {

        if(root == NULL) {
            return 0;
        }

        int leftDepth = getheight(root->left);
        int rightDepth = getheight(root->right);

        int ans = max(leftDepth, rightDepth) + 1;

        return ans;
    }

    bool isBalanced(TreeNode* root) {

        if(root == NULL) {
            return true;
        }

        int leftheight = getheight(root->left);
        int rightheight = getheight(root->right);

        int absDiff = abs(leftheight - rightheight);

        if(absDiff > 1) {
            return false;
        }
        else {

            bool leftans = isBalanced(root->left);
            bool rightans = isBalanced(root->right);

            if(leftans == true && rightans == true) {
                return true;
            }
            else {
                return false;
            }
        }
    }
};
```

---

# Dry Run

Consider:

```text id="3f8m2k"
        3
       / \
      9   20
         /  \
        15   7
```

---

## Node 3

We need:

```text id="9r2x6p"
leftHeight
rightHeight
```

### Left subtree

```text id="7q5n3m"
9
```

Height:

```text id="g2w8kx"
1
```

### Right subtree

```text id="6m4p1z"
       20
      /  \
     15   7
```

Height:

```text id="r7v3nc"
2
```

Therefore at node `3`:

```text id="w9x5qa"
leftHeight = 1
rightHeight = 2
```

Difference:

```text id="j6k2mp"
|1 - 2| = 1
```

Since:

```text id="e5r8ys"
1 <= 1
```

node `3` is balanced.

---

# Check Node 20

Node `20`:

```text id="g2y7nk"
      20
     /  \
    15   7
```

Height of `15`:

```text id="v5q8mz"
1
```

Height of `7`:

```text id="p2k4xc"
1
```

Difference:

```text id="x9n6rw"
|1 - 1| = 0
```

Balanced.

---

# Check Node 9

Node `9` is a leaf.

```text id="k7m2qp"
leftHeight = 0
rightHeight = 0
```

Difference:

```text id="j3v8ls"
0
```

Balanced.

---

# Final Result

Every node is balanced.

Therefore:

```text id="m6q1zy"
true
```

---

# Why `abs()`?

We don't care whether the left subtree is taller or the right subtree is taller.

For example:

```text id="j4q7sm"
left = 3
right = 2
```

Difference:

```text id="b2x8kn"
3 - 2 = 1
```

And:

```text id="k8p3mz"
left = 2
right = 3
```

Difference:

```text id="q7m1vd"
2 - 3 = -1
```

Both should be considered balanced.

So we use:

```cpp id="r6x4kp"
abs(leftheight - rightheight)
```

which gives:

```text id="l5n8qy"
1
```

in both cases.

---

# Why Do We Check Both Subtrees?

Suppose:

```text id="a9x3kp"
        1
       / \
      2   3
     /
    4
   /
  5
```

The tree can become unbalanced deeper inside.

So this:

```cpp id="q8m2zd"
abs(leftheight - rightheight) <= 1
```

at the root alone is **not sufficient**.

We also need:

```cpp id="x5n7va"
isBalanced(root->left)
```

and:

```cpp id="k3p8rs"
isBalanced(root->right)
```

---

# Recursion Flow

The process is:

```text id="m8q4xn"
                  ROOT
                 /    \
                /      \
        Check LEFT    Check RIGHT
             ↓             ↓
          Balanced?      Balanced?
             \             /
              \           /
               \         /
                ↓       ↓
             Check Height
                    ↓
             Difference <= 1
```

---

# Complexity Analysis — Your Approach

Your solution calls:

```cpp id="k3x7pd"
getheight()
```

again and again for different nodes.

This causes repeated calculations.

For example:

```text id="r7m2qc"
isBalanced(root)
      ↓
getheight(left)
      ↓
getheight(right)
      ↓
isBalanced(left)
      ↓
getheight(left-left)
      ↓
getheight(left-right)
```

The same subtree heights can be calculated multiple times.

### Time Complexity

Worst case:

```text id="9w3m5k"
O(N²)
```

### Space Complexity

Recursion stack:

```text id="c8x2va"
O(H)
```

where `H` is the height of the tree.

Worst case:

```text id="y7m4pq"
O(N)
```

---

# Optimized Approach

We can calculate the **height and balance status together**.

Instead of calculating height separately again and again, we use one DFS function.

The idea:

```text id="0m8k3x"
If subtree is unbalanced:
    return -1

Otherwise:
    return its height
```

This is a very useful tree recursion pattern.

---

# Optimized C++ Solution

```cpp id="g6p2vz"
class Solution {
public:

    int checkHeight(TreeNode* root) {

        if(root == NULL) {
            return 0;
        }

        int leftHeight = checkHeight(root->left);

        if(leftHeight == -1) {
            return -1;
        }

        int rightHeight = checkHeight(root->right);

        if(rightHeight == -1) {
            return -1;
        }

        if(abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {

        return checkHeight(root) != -1;
    }
};
```

---

# How the Optimized Approach Works

The function returns two possible things:

### Case 1 — Tree is balanced

Return its height:

```text id="3r6k8w"
height
```

### Case 2 — Tree is unbalanced

Return:

```text id="j7x2mp"
-1
```

Therefore:

```text id="4k8v1s"
height >= 0  → balanced
-1           → unbalanced
```

---

# Example

Consider:

```text id="x5m8qs"
        1
       /
      2
     /
    3
```

Start at node `3`:

```text id="8z4p6m"
height = 1
```

Node `2`:

```text id="q3m7vn"
leftHeight = 1
rightHeight = 0

difference = 1

height = 2
```

Node `1`:

```text id="s8k2yx"
leftHeight = 2
rightHeight = 0

difference = 2
```

Since:

```text id="v4n9pc"
2 > 1
```

return:

```text id="b6q1mz"
-1
```

This immediately tells us the tree is unbalanced.

---

# Why `-1`?

A valid tree height is always:

```text id="9x5q2m"
0 or greater
```

So `-1` can be safely used as a special value meaning:

```text id="k7m3pv"
UNBALANCED
```

This avoids needing a separate boolean variable.

---

# Complexity of Optimized Solution

Every node is visited exactly once.

Therefore:

### Time

```text id="w5p8zx"
O(N)
```

### Space

Recursion stack:

```text id="a2m7qc"
O(H)
```

Worst case:

```text id="f9x4nb"
O(N)
```

---

# Comparison

| Approach               |       Time |      Space |
| ---------------------- | ---------: | ---------: |
| Your Approach          |    `O(N²)` |     `O(H)` |
| **Optimized Approach** | **`O(N)`** | **`O(H)`** |

The optimized solution is preferred in interviews.

---

# Important Pattern

This problem uses **Postorder DFS**:

```text id="v4x9mq"
LEFT → RIGHT → ROOT
```

Why?

We need the heights of both children before checking the current node.

```text id="m2k7qp"
        ROOT
       /    \
    LEFT    RIGHT
      ↓       ↓
   height   height
      \       /
       \     /
        CHECK
          ↓
      BALANCED?
```

---

# Core Formula

For every node:

```text id="q7m3sx"
leftHeight  = height(left)
rightHeight = height(right)
```

Check:

```text id="k9x2vp"
abs(leftHeight - rightHeight) <= 1
```

If balanced:

```text id="r4m8nc"
height = 1 + max(leftHeight, rightHeight)
```

---

# Key Concepts

* Binary Tree
* Height-Balanced Tree
* DFS
* Recursion
* Postorder Traversal
* Tree Height
* Difference of Heights
* `abs()`
* Special Return Value `-1`

---

# Edge Cases

## Empty Tree

```text id="b3x7pm"
root = []
```

Output:

```text id="m8q2vz"
true
```

Because an empty tree is considered balanced.

---

## Single Node

```text id="r6n4xc"
    1
```

Left height:

```text id="z8k3qm"
0
```

Right height:

```text id="j4p7vs"
0
```

Difference:

```text id="x2m9nb"
0
```

Balanced:

```text id="w5q1kc"
true
```

---

# Final Recommended Code

```cpp id="n5q8zx"
class Solution {
public:

    int checkHeight(TreeNode* root) {

        if(root == NULL) {
            return 0;
        }

        int leftHeight = checkHeight(root->left);

        if(leftHeight == -1) {
            return -1;
        }

        int rightHeight = checkHeight(root->right);

        if(rightHeight == -1) {
            return -1;
        }

        if(abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {

        return checkHeight(root) != -1;
    }
};
```

---

# Summary

| Concept            | Details                              |
| ------------------ | ------------------------------------ |
| Problem            | Balanced Binary Tree                 |
| LeetCode           | 110                                  |
| Difficulty         | Easy                                 |
| Technique          | DFS + Recursion                      |
| Traversal          | Postorder                            |
| Balance Condition  | `abs(leftHeight - rightHeight) <= 1` |
| Your Approach      | `O(N²)`                              |
| Optimized Approach | **`O(N)`**                           |
| Auxiliary Space    | `O(H)`                               |
| Special Value      | `-1` = Unbalanced                    |

## 🧠 Remember

The golden condition is:

```cpp id="h9m3vx"
abs(leftHeight - rightHeight) <= 1
```

And the optimized tree pattern is:

```text id="r3x7kp"
LEFT
 ↓
RIGHT
 ↓
CHECK CURRENT NODE
 ↓
RETURN HEIGHT
```

**Balanced Binary Tree = Every node must have left/right height difference ≤ 1.** 🌳
