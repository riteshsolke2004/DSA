# 🌳 Height of Binary Tree

## Problem Statement

Given the **root of a binary tree**, find the **maximum depth / height** of the tree.

The height of the binary tree is defined as the **number of edges on the longest path from the root node to the deepest node**.

### Important

This problem counts **edges**, not nodes.

For example:

```text id="3g5j8u"
        12
       /  \
      8    18
     / \
    5  11
```

The longest path is:

```text id="i8nq20"
12 → 8 → 5
```

Number of edges:

```text id="p7l6zv"
12 → 8     = 1 edge
8  → 5     = 1 edge

Total      = 2 edges
```

Therefore:

```text id="9a7l0p"
Height = 2
```

---

# Example 1

<img width="450" height="312" alt="blobid0_1758863116" src="https://github.com/user-attachments/assets/3d41dbef-69cd-4ce6-a74c-8d407d93b417" />


### Input

```text id="y4k2rx"
root = [12, 8, 18, 5, 11]
```

Binary Tree:

```text id="p2xq8v"
        12
       /  \
      8    18
     / \
    5  11
```

Possible paths:

```text id="7d9x1m"
12 → 8
12 → 18
12 → 8 → 5
12 → 8 → 11
```

The longest path is:

```text id="k0h9c4"
12 → 8 → 5
```

Number of edges:

```text id="q6xj8w"
2
```

### Output

```text id="gq4b5m"
2
```

---

# Example 2

<img width="474" height="400" alt="blobid1_1758863142" src="https://github.com/user-attachments/assets/cb7f8383-a63d-4f1e-afc3-a9850d305b26" />


### Input

```text id="x6y3mv"
root = [1, 2, 3, 4, N, 10, 5, N, N, N, N, 6, 7]
```

One possible representation:

```text id="v8j5yq"
          1
        /   \
       2     3
      /     / \
     4     10  5
               / \
              6   7
```

The longest path from root to a deepest node is:

```text id="a7k4dn"
1 → 3 → 5 → 6
```

Number of edges:

```text id="p0v6cj"
1 → 3     = 1
3 → 5     = 1
5 → 6     = 1

Total     = 3
```

### Output

```text id="1f7r0w"
3
```

---

# Approach — Recursion / DFS

We can solve this problem using **Depth First Search (DFS)** and recursion.

For every node:

1. Find the height of the left subtree.
2. Find the height of the right subtree.
3. Take the maximum of both.
4. Add `1` for the edge connecting the current node to its child.

The important part is the **base case**.

Since this problem asks for the number of **edges**, an empty tree should return:

```cpp id="xv5vnj"
-1
```

---

# Why Return `-1` for NULL?

This is the most important detail of this problem.

Consider a tree containing only one node:

```text id="s1h0s4"
    12
```

There are:

```text id="0z2sqp"
0 edges
```

If:

```cpp id="kn0h6s"
height(NULL) = -1;
```

then:

```text id="1p4e3h"
left  = -1
right = -1
```

Therefore:

```text id="j9w8se"
height(12)
= 1 + max(-1, -1)
= 0
```

Correct!

So:

```text id="z6h5os"
NULL → -1
Leaf → 0
```

This is because the problem counts **edges**.

---

# Recursive Formula

For every node:

```text id="k9p8qa"
height(root)
=
1 + max(
    height(root->left),
    height(root->right)
)
```

Base case:

```text id="4g6z1r"
if(root == NULL)
    return -1;
```

---

# C++ Solution

```cpp id="p5s7e0"
class Solution {
public:

    int height(Node* root) {

        if(root == NULL)
            return -1;

        int left = height(root->left);

        int right = height(root->right);

        return 1 + max(left, right);
    }
};
```

---

# Dry Run

Consider:

```text id="x2n8qk"
        12
       /  \
      8    18
     / \
    5  11
```

Call:

```text id="w9m2lq"
height(12)
```

---

## Step 1 — Node 12

Node `12` has two children.

So calculate:

```text id="d5v8mx"
left  = height(8)
right = height(18)
```

---

## Step 2 — Node 8

Node `8` has two children:

```text id="f8z1cq"
    8
   / \
  5  11
```

Calculate:

```text id="j4w7pa"
left  = height(5)
right = height(11)
```

---

## Step 3 — Node 5

Node `5` is a leaf:

```text id="x8k3qp"
    5
   / \
 NULL NULL
```

Therefore:

```text id="6q7m5b"
height(NULL) = -1
```

So:

```text id="c3f6yd"
height(5)
= 1 + max(-1, -1)
= 0
```

Therefore:

```text id="8r6z0n"
height(5) = 0
```

---

## Step 4 — Node 11

Node `11` is also a leaf.

```text id="s9w1cm"
height(11)
= 1 + max(-1, -1)
= 0
```

Therefore:

```text id="7f5x4d"
height(11) = 0
```

---

## Step 5 — Node 8

We now have:

```text id="8f7q0k"
height(5)  = 0
height(11) = 0
```

Therefore:

```text id="0m8s2v"
height(8)
= 1 + max(0, 0)
= 1
```

So:

```text id="b6y9rq"
height(8) = 1
```

---

## Step 6 — Node 18

Node `18` is a leaf.

Therefore:

```text id="d5c8yv"
height(18)
= 1 + max(-1, -1)
= 0
```

---

## Step 7 — Node 12

Now we have:

```text id="h9x1ma"
height(8)  = 1
height(18) = 0
```

Therefore:

```text id="a4r8vn"
height(12)
= 1 + max(1, 0)
= 2
```

Final answer:

```text id="z2q5hf"
2
```

---

# Recursion Tree

```text id="n0g5fz"
                    height(12)
                   /          \
                  /            \
          height(8)          height(18)
          /       \               |
         /         \              0
    height(5)   height(11)
        |            |
        0            0
```

Then:

```text id="1z8v7c"
height(8)
= 1 + max(0,0)
= 1
```

Finally:

```text id="x7c9ma"
height(12)
= 1 + max(1,0)
= 2
```

---

# Edge Count vs Node Count

This is a very important distinction.

## Height in Edges

For:

```text id="8ps9r4"
    1
   / \
  2   3
```

Longest path:

```text id="y4n7gc"
1 → 2
```

Edges:

```text id="hj7v2m"
1
```

Therefore:

```text id="f4x8qw"
Height = 1
```

---

## Height in Nodes

If we counted nodes instead:

```text id="p3m9az"
1 → 2
```

Number of nodes:

```text id="q6v1tb"
2
```

Therefore:

```text id="0s7jkc"
Node-based height = 2
```

So always check what the problem asks.

### This problem:

```text id="x2m8qa"
Height = Number of EDGES
```

Therefore:

```text id="e3z9kf"
NULL → -1
Leaf → 0
```

---

# Edge Cases

## 1. Empty Tree

```text id="f8r2mw"
root = NULL
```

Output:

```text id="d7x4qa"
-1
```

Because there are no nodes and the given definition uses the recursive edge-count convention.

---

## 2. Single Node

```text id="j5m8xz"
    1
```

Output:

```text id="k3r6vp"
0
```

There are zero edges.

---

## 3. Left-Skewed Tree

```text id="a9q4nc"
    1
   /
  2
 /
3
```

Longest path:

```text id="v6p2ks"
1 → 2 → 3
```

Number of edges:

```text id="c5z8mq"
2
```

Output:

```text id="e9n3xa"
2
```

---

## 4. Right-Skewed Tree

```text id="b8r5km"
1
 \
  2
   \
    3
```

Longest path:

```text id="x4c7pd"
1 → 2 → 3
```

Height:

```text id="q1m9va"
2
```

---

# Complexity Analysis

Every node is visited exactly once.

If the tree contains `N` nodes:

### Time Complexity

```text id="p7n4xs"
O(N)
```

### Space Complexity

The recursive calls use the call stack.

In the worst case, the tree is skewed:

```text id="g5w8mb"
1
 \
  2
   \
    3
     \
      4
```

The recursion depth becomes `N`.

Therefore:

```text id="m2q7yc"
Worst Case Space = O(N)
```

For a balanced binary tree:

```text id="x6r9vz"
Space = O(log N)
```

---

# Key Concept

The main thing to remember is:

> **This problem counts edges, not nodes.**

Therefore:

```text id="e4q7xm"
NULL → -1
Leaf → 0
Parent → 1 + max(left, right)
```

### Formula

```text id="g9c2fw"
height(root)
=
1 + max(
    height(root->left),
    height(root->right)
)
```

---

# Height vs Minimum Depth

Do not confuse this problem with **Minimum Depth of Binary Tree**.

| Problem               | What to Find          | NULL Base Case |
| --------------------- | --------------------- | -------------: |
| Height of Binary Tree | Longest path          |           `-1` |
| Minimum Depth         | Shortest path to leaf |            `0` |

### Height

```text id="t6m8xq"
Take MAX
```

```cpp id="8d4q1n"
1 + max(left, right)
```

### Minimum Depth

```text id="y7c3wp"
Take MIN
```

But when one child is `NULL`, follow the non-NULL child.

---

# Final Code

```cpp id="s5v9kj"
class Solution {
public:

    int height(Node* root) {

        if(root == NULL)
            return -1;

        int left = height(root->left);

        int right = height(root->right);

        return 1 + max(left, right);
    }
};
```

---

# Summary

| Concept     | Details                                |
| ----------- | -------------------------------------- |
| Problem     | Height of Binary Tree                  |
| Difficulty  | Easy                                   |
| Approach    | DFS + Recursion                        |
| Definition  | Longest path from root to deepest node |
| Measurement | Number of **edges**                    |
| NULL        | `-1`                                   |
| Leaf        | `0`                                    |
| Formula     | `1 + max(left, right)`                 |
| Time        | `O(N)`                                 |
| Worst Space | `O(N)`                                 |

## 🧠 Remember

```text
Height in EDGES:

NULL  → -1
Leaf  →  0
Node  →  1 + max(left, right)
```
