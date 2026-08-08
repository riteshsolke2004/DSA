# 🌳 Minimum Depth of Binary Tree

## Problem Statement

Given the root of a binary tree, find its **minimum depth**.

The **minimum depth** is the number of nodes along the shortest path from the root node down to the **nearest leaf node**.

### Important

A **leaf node** is a node that has:

```text
left child  = NULL
right child = NULL
```

---

# Example 1

<img width="432" height="302" alt="ex_depth" src="https://github.com/user-attachments/assets/2273b6a5-51bc-4f09-a3cb-3d38e4804645" />


### Input

```text
root = [3,9,20,null,null,15,7]
```

Binary Tree:

```text
        3
       / \
      9   20
         /  \
        15   7
```

The leaf nodes are:

```text
9, 15, 7
```

Paths from root:

```text
3 → 9
3 → 20 → 15
3 → 20 → 7
```

The shortest path is:

```text
3 → 9
```

Number of nodes:

```text
2
```

### Output

```text
2
```

---

# Example 2

### Input

```text
root = [2,null,3,null,4,null,5,null,6]
```

Binary Tree:

```text
2
 \
  3
   \
    4
     \
      5
       \
        6
```

The only leaf is `6`.

Path:

```text
2 → 3 → 4 → 5 → 6
```

Number of nodes:

```text
5
```

### Output

```text
5
```

---

# Approach — Recursion

We can solve this problem using **Depth First Search (DFS)** and recursion.

For every node, there are three important cases.

---

## Case 1 — Root is NULL

If the tree is empty:

```cpp
root == NULL
```

there is no depth.

Therefore:

```cpp
return 0;
```

---

## Case 2 — Only Right Child Exists

Suppose:

```text
    3
     \
      9
```

The left child is `NULL`.

We **cannot** simply do:

```cpp
min(leftDepth, rightDepth)
```

because the left side doesn't contain a leaf.

Instead, we must follow the right subtree:

```cpp
return 1 + minDepth(root->right);
```

---

## Case 3 — Only Left Child Exists

Suppose:

```text
    3
   /
  9
```

The right child is `NULL`.

We follow the left subtree:

```cpp
return 1 + minDepth(root->left);
```

---

## Case 4 — Both Children Exist

If both children exist:

```text
      3
     / \
    9   20
```

Find the minimum depth of both subtrees:

```cpp
min(minDepth(root->left),
    minDepth(root->right))
```

Then add `1` for the current node.

```cpp
return 1 + min(...);
```

---

# C++ Solution

```cpp
class Solution {
public:

    int minDepth(TreeNode* root) {

        // Empty tree
        if(root == NULL) {
            return 0;
        }

        // Only right child exists
        if(root->left == NULL) {
            return 1 + minDepth(root->right);
        }

        // Only left child exists
        if(root->right == NULL) {
            return 1 + minDepth(root->left);
        }

        // Both children exist
        return 1 + min(
            minDepth(root->left),
            minDepth(root->right)
        );
    }
};
```

---

# Why Can't We Simply Use `min()`?

A common mistake is:

```cpp
return 1 + min(
    minDepth(root->left),
    minDepth(root->right)
);
```

for every node.

Consider:

```text
    2
     \
      3
       \
        4
```

At node `2`:

```text
left = NULL
right = 3
```

If:

```text
minDepth(NULL) = 0
```

then:

```text
1 + min(0, minDepth(3))
```

would incorrectly give:

```text
1
```

But the actual minimum depth is:

```text
3
```

Therefore, when one child is `NULL`, we **must follow the non-NULL child**.

---

# Dry Run

Consider:

```text
        3
       / \
      9   20
         /  \
        15   7
```

Call:

```text
minDepth(3)
```

---

## At Node 3

Both children exist.

So:

```text
minDepth(3)
= 1 + min(minDepth(9), minDepth(20))
```

---

## At Node 9

```text
9
```

Both children are `NULL`.

Call:

```text
minDepth(NULL)
```

returns:

```text
0
```

Therefore:

```text
minDepth(9)
= 1
```

because `9` itself is a leaf.

---

## At Node 20

Both children exist.

```text
        20
       /  \
      15   7
```

Therefore:

```text
minDepth(20)
= 1 + min(
      minDepth(15),
      minDepth(7)
  )
```

---

## Node 15

`15` is a leaf:

```text
minDepth(15) = 1
```

---

## Node 7

`7` is a leaf:

```text
minDepth(7) = 1
```

Therefore:

```text
minDepth(20)
= 1 + min(1,1)
= 2
```

---

## Finally Node 3

We have:

```text
minDepth(9)  = 1
minDepth(20) = 2
```

Therefore:

```text
minDepth(3)
= 1 + min(1,2)
= 2
```

### Final Answer

```text
2
```

---

# Recursion Tree

For:

```text
[3,9,20,null,null,15,7]
```

The recursive calls are conceptually:

```text
                    minDepth(3)
                   /           \
                  /             \
          minDepth(9)       minDepth(20)
              |              /          \
              1       minDepth(15)  minDepth(7)
                              |           |
                              1           1
```

Then:

```text
minDepth(20)
= 1 + min(1,1)
= 2
```

and:

```text
minDepth(3)
= 1 + min(1,2)
= 2
```

---

# Important Edge Cases

### Empty Tree

```text
root = NULL
```

Output:

```text
0
```

---

### Single Node

```text
    1
```

Output:

```text
1
```

---

### Only Left Children

```text
      1
     /
    2
   /
  3
```

Minimum depth:

```text
3
```

---

### Only Right Children

```text
1
 \
  2
   \
    3
```

Minimum depth:

```text
3
```

---

# Complexity Analysis

Every node is visited once.

If there are `N` nodes:

### Time Complexity

```text
O(N)
```

### Space Complexity

The recursive calls use the call stack.

In the worst case, the tree is completely skewed:

```text
1
 \
  2
   \
    3
     \
      4
```

Recursion depth becomes `N`.

Therefore:

```text
O(N)
```

In a balanced tree, the recursion depth is approximately:

```text
O(log N)
```

---

# Key Concept

The most important part of this problem is:

> **A NULL child cannot automatically be treated as having minimum depth 0 when calculating the minimum path to a leaf.**

Remember this pattern:

```text
If root == NULL
    return 0

If left == NULL
    go right

If right == NULL
    go left

Otherwise
    take minimum of left and right
```

---

# Final Code

```cpp
class Solution {
public:

    int minDepth(TreeNode* root) {

        if(root == NULL) {
            return 0;
        }

        if(root->left == NULL) {
            return 1 + minDepth(root->right);
        }

        if(root->right == NULL) {
            return 1 + minDepth(root->left);
        }

        return 1 + min(
            minDepth(root->left),
            minDepth(root->right)
        );
    }
};
```

---

# Summary

| Concept      | Details                      |
| ------------ | ---------------------------- |
| Problem      | Minimum Depth of Binary Tree |
| LeetCode     | 111                          |
| Approach     | DFS + Recursion              |
| Base Case    | `root == NULL → 0`           |
| Leaf         | Both children are `NULL`     |
| One Child    | Follow the non-NULL child    |
| Two Children | Take minimum depth           |
| Time         | `O(N)`                       |
| Space        | `O(N)` worst case            |

### Pattern to Remember

```text
                Root
                  |
          Is root NULL?
             /       \
           YES       NO
            |         |
            0     One child NULL?
                    /       \
                  YES        NO
                   |          |
             Follow other   1 + min(left,right)
                child
```
