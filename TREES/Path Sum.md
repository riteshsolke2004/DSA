# 🌳 112. Path Sum

## Problem Statement

Given the `root` of a binary tree and an integer `targetSum`, determine whether the tree has a **root-to-leaf path** such that the sum of all node values along that path is equal to `targetSum`.

A **leaf node** is a node that has:

```text id="e3c2wp"
left child  = NULL
right child = NULL
```

The path must:

* Start from the **root**.
* End at a **leaf node**.
* Include every node between the root and leaf.
* Have a sum equal to `targetSum`.

---

# Example 1
<img width="592" height="421" alt="pathsum1" src="https://github.com/user-attachments/assets/c653719f-4e5c-4cc8-94be-ee7db5b76b8c" />

### Input

```text id="8x2x5z"
root = [5,4,8,11,null,13,4,7,2,null,null,null,1]

targetSum = 22
```

Binary Tree:

```text id="8r8n6b"
             5
           /   \
          4     8
         /     / \
       11     13  4
      /  \         \
     7    2         1
```

Possible path:

```text id="7y2gq3"
5 → 4 → 11 → 2
```

Calculate the sum:

```text id="9j2x5q"
5 + 4 + 11 + 2
= 22
```

The path ends at leaf `2`.

Therefore:

```text id="v8h2zr"
Output = true
```

---

# Example 2
<img width="212" height="181" alt="pathsum2" src="https://github.com/user-attachments/assets/1c20b438-a3c2-427f-8d36-d694e49812bb" />

### Input

```text id="f4k9w2"
root = [1,2,3]

targetSum = 5
```

Binary Tree:

```text id="s3k8ym"
      1
     / \
    2   3
```

Possible root-to-leaf paths:

```text id="x5n0qa"
1 → 2
```

Sum:

```text id="2n7jca"
1 + 2 = 3
```

And:

```text id="9z2r6v"
1 → 3
```

Sum:

```text id="0h7v5b"
1 + 3 = 4
```

Neither path has sum `5`.

Therefore:

```text id="w1j4sk"
Output = false
```

---

# Example 3

### Input

```text id="6u3z9k"
root = []

targetSum = 0
```

The tree is empty.

There is no root-to-leaf path.

Therefore:

```text id="q4n8yt"
Output = false
```

---

# Approach — Recursion / DFS

We can solve this problem using **Depth First Search (DFS)** and recursion.

The idea is simple:

At every node:

1. Add the current node's value to the running sum.
2. Check whether the current node is a leaf.
3. If it is a leaf, compare the running sum with `targetSum`.
4. Otherwise, recursively check the left and right subtrees.
5. If either subtree contains a valid path, return `true`.

---

# Important Condition — Leaf Node

A node is a leaf when:

```cpp id="1j7f40"
root->left == NULL && root->right == NULL
```

Only at a **leaf** should we compare the sum with `targetSum`.

This is important because the problem specifically asks for a **root-to-leaf path**.

---

# C++ Solution

```cpp id="w4m0x8"
class Solution {
public:

    bool solve(TreeNode* root, int target, int sum) {

        // Base case
        if(root == NULL) {
            return false;
        }

        // Add current node value
        sum = sum + root->val;

        // Check if current node is a leaf
        if(root->left == NULL && root->right == NULL) {

            if(sum == target) {
                return true;
            }
            else {
                return false;
            }
        }

        // Check left subtree
        bool leftans = solve(root->left, target, sum);

        // Check right subtree
        bool rightans = solve(root->right, target, sum);

        // If either side has a valid path
        return leftans || rightans;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {

        int sum = 0;

        return solve(root, targetSum, sum);
    }
};
```

---

# How the Approach Works

The main idea is to maintain:

```text id="9f2v6n"
sum
```

which represents the sum of values from the root to the current node.

For example:

```text id="2v7s8m"
        5
       /
      4
     /
    11
   /
  2
```

When we visit each node:

```text id="h7s2kd"
At 5:
sum = 5

At 4:
sum = 5 + 4 = 9

At 11:
sum = 9 + 11 = 20

At 2:
sum = 20 + 2 = 22
```

At node `2`, we check:

```text id="9d6j3m"
Is 2 a leaf?
```

Yes.

Then:

```text id="4v8p1x"
sum == targetSum
22 == 22
```

Therefore:

```text id="1n0r7q"
true
```

---

# Dry Run

Consider:

```text id="3q8y5m"
             5
           /   \
          4     8
         /     / \
       11     13  4
      /  \         \
     7    2         1
```

Target:

```text id="w5k2cz"
targetSum = 22
```

Initially:

```text id="q8r3ma"
sum = 0
```

---

## Step 1 — Node 5

```text id="6w2m9s"
sum = 0 + 5
    = 5
```

Node `5` is not a leaf.

So check both:

```text id="x3n8qa"
left  → node 4
right → node 8
```

---

## Step 2 — Node 4

```text id="m8c4z1"
sum = 5 + 4
    = 9
```

Node `4` is not a leaf.

Go left:

```text id="1s7k0v"
node 11
```

---

## Step 3 — Node 11

```text id="r2n6yw"
sum = 9 + 11
    = 20
```

Node `11` has two children:

```text id="9f1m3k"
       11
      /  \
     7    2
```

First check node `7`.

---

## Step 4 — Node 7

```text id="a4v9pq"
sum = 20 + 7
    = 27
```

Node `7` is a leaf.

Check:

```text id="p8x3mz"
27 == 22
```

False.

Return:

```text id="k7d2ws"
false
```

---

## Step 5 — Node 2

Now check the other child of `11`.

```text id="x6q1nb"
sum = 20 + 2
    = 22
```

Node `2` is a leaf.

Check:

```text id="d3w8yz"
22 == 22
```

True.

Therefore:

```text id="v9m4xq"
true
```

This result travels back through the recursive calls.

---

# Why `leftans || rightans`?

At each node we check both possible directions:

```text id="k7x2pn"
             root
            /    \
         left    right
```

A valid path can exist in either subtree.

Therefore:

```cpp id="h3n8zq"
return leftans || rightans;
```

means:

```text id="4w6p1y"
left path is valid
        OR
right path is valid
```

If either one is `true`, the entire answer is `true`.

---

# Recursion Flow

For the first example:

```text id="6j8w2m"
                  solve(5)
                 /        \
                /          \
          solve(4)       solve(8)
             |
          solve(11)
          /      \
     solve(7)   solve(2)
       false      true
```

At node `11`:

```text id="j1q6rs"
leftans  = false
rightans = true
```

Therefore:

```text id="8x4m7p"
leftans || rightans
= false || true
= true
```

This eventually returns `true` to the root.

---

# Important: Why Check Leaf Before Returning True?

Suppose:

```text id="n8v3kq"
        5
       /
      4
```

Target:

```text id="c7m2yx"
5
```

At node `5`:

```text id="p9w6za"
sum = 5
```

The sum matches the target.

But `5` is **not a leaf** because it has a child.

So we must **not** return `true`.

The path must reach a leaf.

This is why the condition is:

```cpp id="e4y1xn"
if(root->left == NULL && root->right == NULL)
```

before checking:

```cpp id="s8m3qc"
sum == target
```

---

# Edge Cases

## 1. Empty Tree

```text id="7s4k9m"
root = NULL
```

Immediately:

```cpp id="j2x6pr"
if(root == NULL)
    return false;
```

Output:

```text id="w8f3qa"
false
```

---

## 2. Single Node

```text id="9p4m7x"
    5
```

Target:

```text id="3k8w1q"
5
```

The node is a leaf.

```text id="6m2z9v"
sum = 5
target = 5
```

Output:

```text id="0q7x4a"
true
```

---

## 3. Single Node — Wrong Target

```text id="j8m3vp"
    5
```

Target:

```text id="x4k7z1"
10
```

```text id="r6w9qc"
5 != 10
```

Output:

```text id="h2n5sy"
false
```

---

# Complexity Analysis

Let:

```text id="v7q3mc"
N = number of nodes
```

Every node may be visited once.

### Time Complexity

```text id="0f8z7y"
O(N)
```

### Space Complexity

The recursive call stack depends on the height of the tree.

For a balanced tree:

```text id="a6m2px"
O(log N)
```

For a skewed tree:

```text id="k9w4zs"
O(N)
```

Therefore, worst-case auxiliary space:

```text id="n3x7cq"
O(N)
```

---

# Key Concepts

* Binary Tree
* DFS
* Recursion
* Root-to-Leaf Path
* Running Sum
* Boolean Recursion

---

# Important Pattern

For **Path Sum**, remember:

```text id="x7p3ma"
1. If root == NULL
       return false

2. Add root->val to sum

3. If root is a leaf
       check sum == target

4. Otherwise
       check left
       check right

5. Return
       left || right
```

---

# Core Code Pattern

```cpp id="h2v8qa"
sum += root->val;

if(root->left == NULL && root->right == NULL) {
    return sum == target;
}

bool leftans = solve(root->left, target, sum);
bool rightans = solve(root->right, target, sum);

return leftans || rightans;
```

---

# Connection With Tree Traversals

This problem also uses **DFS**.

The traversal pattern is roughly:

```text id="p5m8rx"
        ROOT
       /    \
    LEFT    RIGHT
```

We visit:

```text id="c7q2nz"
ROOT → LEFT → RIGHT
```

while carrying an additional value:

```text id="1w9s4k"
sum
```

So the recursion is doing two jobs:

```text id="4v6m2p"
DFS Traversal
     +
Running Sum
```

---

# Summary

| Concept        | Details                         |
| -------------- | ------------------------------- |
| Problem        | Path Sum                        |
| LeetCode       | 112                             |
| Difficulty     | Easy                            |
| Approach       | DFS + Recursion                 |
| Goal           | Root-to-leaf path               |
| Extra Variable | Running `sum`                   |
| Leaf Condition | `left == NULL && right == NULL` |
| Result         | `true` / `false`                |
| Time           | `O(N)`                          |
| Worst Space    | `O(N)`                          |

## 🧠 Remember

**Path Sum = DFS + Running Sum + Leaf Check**

```text id="f7z3nk"
ROOT
 ↓
Add value to SUM
 ↓
Is it a LEAF?
 ↓
YES → SUM == TARGET ?
 ↓
NO
 ↓
Check LEFT || RIGHT
```

The most important condition is:

```cpp id="r4q8xm"
root->left == NULL && root->right == NULL
```

because the required path must always end at a **leaf node**. 🌳
