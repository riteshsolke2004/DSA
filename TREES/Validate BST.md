# 🌳 98. Validate Binary Search Tree

[LeetCode — Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)

## Problem Statement

Given the `root` of a binary tree, determine whether it is a **valid Binary Search Tree (BST)**.

A valid BST follows these rules:

* Every node in the **left subtree** contains a value **strictly less** than the node's value.
* Every node in the **right subtree** contains a value **strictly greater** than the node's value.
* Both the left and right subtrees must also be valid BSTs.
* Duplicate values are **not allowed**.

---

## Example 1
<img width="302" height="182" alt="tree1" src="https://github.com/user-attachments/assets/07c0e876-c824-4f25-90ef-ce2982dc257c" />

### Input

```text
root = [2,1,3]
```

Tree:

```text
      2
     / \
    1   3
```

Since:

```text
1 < 2 < 3
```

The tree is a valid BST.

### Output

```text
true
```

---

## Example 2
<img width="422" height="292" alt="tree2" src="https://github.com/user-attachments/assets/8580a058-98d7-46dc-8012-8f205d4fbbc9" />

### Input

```text
root = [5,1,4,null,null,3,6]
```

Tree:

```text
        5
       / \
      1   4
         / \
        3   6
```

The node `4` is in the right subtree of `5`.

Therefore, it must be greater than `5`.

But:

```text
4 < 5
```

So the tree is invalid.

### Output

```text
false
```

---

# BST Property

A Binary Search Tree follows:

```text
             Root
            /    \
       Smaller   Greater
```

For every node:

```text
Left Subtree < Root < Right Subtree
```

For example:

```text
        10
       /  \
      5    15
```

Here:

```text
5 < 10
15 > 10
```

So this part is valid.

---

# Why Simple Child Checking Is Not Enough

Consider:

```text
        10
       /  \
      5    15
          /
         6
```

We might check:

```text
5 < 10      ✅
15 > 10     ✅
6 < 15      ✅
```

It looks correct if we only compare children.

But `6` is in the **right subtree of 10**.

Therefore:

```text
6 must be > 10
```

But:

```text
6 < 10 ❌
```

So the tree is **not** a valid BST.

Therefore, we need to maintain a valid **range** for every node.

---

# Approach — Range Method

For every node, maintain:

```text
minimum allowed value
maximum allowed value
```

Initially, the root can have any value:

```text
(-∞, +∞)
```

For a node with value `x`:

### Left Subtree

All values must be smaller than `x`.

```text
(minimum, x)
```

### Right Subtree

All values must be greater than `x`.

```text
(x, maximum)
```

---

# Range Example

Consider:

```text
        10
       /  \
      5    15
          /
         6
```

Initially:

```text
10 → (-∞, +∞)
```

For `5`:

```text
5 → (-∞, 10)
```

For `15`:

```text
15 → (10, +∞)
```

For `6`, because it is the left child of `15`:

```text
6 → (10, 15)
```

But:

```text
6 <= 10
```

Therefore:

```text
false
```

---

# Algorithm

1. Start from the root.
2. Give the root the range:

```text
(-∞, +∞)
```

3. Check whether the current node lies inside its allowed range.
4. If it does not, return `false`.
5. For the left subtree:

   * Keep the same minimum.
   * Make the maximum equal to the current node's value.
6. For the right subtree:

   * Make the minimum equal to the current node's value.
   * Keep the same maximum.
7. Continue recursively.
8. If all nodes satisfy their ranges, return `true`.

---

# C++ Solution

```cpp
class Solution {
public:

    bool check(TreeNode* root, long long minValue, long long maxValue) {

        if(root == NULL) {
            return true;
        }

        if(root->val <= minValue || root->val >= maxValue) {
            return false;
        }

        bool left = check(root->left, minValue, root->val);

        bool right = check(root->right, root->val, maxValue);

        return left && right;
    }

    bool isValidBST(TreeNode* root) {

        return check(root, LLONG_MIN, LLONG_MAX);
    }
};
```

---

# Code Explanation

## 1. Base Case

```cpp
if(root == NULL) {
    return true;
}
```

If we reach `NULL`, there is no violation.

So return:

```text
true
```

---

## 2. Check Valid Range

```cpp
if(root->val <= minValue || root->val >= maxValue) {
    return false;
}
```

The current value must satisfy:

```text
minValue < root->val < maxValue
```

If it violates the range, the tree is invalid.

---

## 3. Check Left Subtree

```cpp
bool left = check(root->left, minValue, root->val);
```

For the left subtree:

```text
minValue < value < root->val
```

So the maximum allowed value becomes:

```text
root->val
```

---

## 4. Check Right Subtree

```cpp
bool right = check(root->right, root->val, maxValue);
```

For the right subtree:

```text
root->val < value < maxValue
```

So the minimum allowed value becomes:

```text
root->val
```

---

## 5. Final Result

```cpp
return left && right;
```

Both subtrees must be valid.

Therefore:

```text
Left = true
AND
Right = true
```

means the entire tree is a valid BST.

---

# Detailed Dry Run

Consider:

```text
root = [2,1,3]
```

Tree:

```text
      2
     / \
    1   3
```

### Step 1 — Root

Call:

```cpp
check(root, LLONG_MIN, LLONG_MAX)
```

Current value:

```text
2
```

Allowed range:

```text
(-∞, +∞)
```

Check:

```text
-∞ < 2 < +∞
```

Valid.

---

### Step 2 — Left Child

Call:

```cpp
check(root->left, LLONG_MIN, 2)
```

Current value:

```text
1
```

Allowed range:

```text
(-∞, 2)
```

Check:

```text
1 < 2
```

Valid.

---

### Step 3 — Children of 1

Both children are `NULL`.

Therefore:

```text
true
```

---

### Step 4 — Right Child of 2

Call:

```cpp
check(root->right, 2, LLONG_MAX)
```

Current value:

```text
3
```

Allowed range:

```text
(2, +∞)
```

Check:

```text
2 < 3
```

Valid.

---

### Step 5 — Children of 3

Both children are `NULL`.

Therefore:

```text
true
```

Final:

```text
left  = true
right = true
```

Therefore:

```text
true && true = true
```

### Final Output

```text
true
```

---

# Invalid BST Dry Run

Consider:

```text
root = [5,1,4,null,null,3,6]
```

Tree:

```text
        5
       / \
      1   4
         / \
        3   6
```

### Root

```text
5 → (-∞, +∞)
```

Valid.

### Left Child

```text
1 → (-∞, 5)
```

Valid.

### Right Child

Because `4` is the right child of `5`:

```text
4 → (5, +∞)
```

But:

```text
4 <= 5
```

Therefore:

```text
false
```

The algorithm immediately returns:

```text
false
```

---

# Why Use `LLONG_MIN` and `LLONG_MAX`?

We use:

```cpp
LLONG_MIN
LLONG_MAX
```

instead of:

```cpp
INT_MIN
INT_MAX
```

because the tree values can be close to the limits of an `int`.

Using `long long` gives us a safe range outside the possible `int` values.

---

# Duplicate Values

BST requires **strictly smaller** and **strictly greater** values.

Consider:

```text
      5
     /
    5
```

This is invalid because:

```text
5 < 5 ❌
```

Our condition:

```cpp
root->val <= minValue ||
root->val >= maxValue
```

correctly rejects duplicates.

---

# Important Range Rules

| Position      | Valid Range             |
| ------------- | ----------------------- |
| Root          | `(-∞, +∞)`              |
| Left Subtree  | `(minValue, root->val)` |
| Right Subtree | `(root->val, maxValue)` |

Remember:

```text
LEFT  → Maximum becomes root->val
RIGHT → Minimum becomes root->val
```

---

# Common Mistakes

### ❌ Checking Only Immediate Children

This is not enough:

```text
left < root
right > root
```

A node can violate a constraint from an **ancestor**.

Use the range method.

---

### ❌ Allowing Duplicate Values

BST requires:

```text
left < root < right
```

Not:

```text
left <= root <= right
```

---

### ❌ Wrong Left Range

Correct:

```cpp
check(root->left, minValue, root->val);
```

---

### ❌ Wrong Right Range

Correct:

```cpp
check(root->right, root->val, maxValue);
```

---

# Complexity Analysis

Let `N` be the number of nodes.

Every node is visited once.

### Time Complexity

```text
O(N)
```

### Space Complexity

The recursion stack depends on the height `H` of the tree:

```text
O(H)
```

For a balanced tree:

```text
O(log N)
```

For a skewed tree:

```text
O(N)
```

---

# Edge Cases

## Empty Tree

```text
root = []
```

Output:

```text
true
```

An empty tree is considered a valid BST.

---

## Single Node

```text
root = [1]
```

Output:

```text
true
```

---

## Duplicate Values

```text
root = [2,2,3]
```

Output:

```text
false
```

---

## Skewed Valid BST

```text
1
 \
  2
   \
    3
     \
      4
```

Output:

```text
true
```

---

# Interview Explanation

> I use the range-based recursive approach to validate the BST. Initially, the root can have any value, so its range is negative infinity to positive infinity. For every left subtree, the maximum allowed value becomes the current node's value. For every right subtree, the minimum allowed value becomes the current node's value. If any node falls outside its allowed range, I return false. If every node satisfies its range, the tree is a valid BST.

---

# Quick Revision

```text
                 Root
             (-∞, +∞)
              /     \
             /       \
            ↓         ↓
         LEFT       RIGHT
      (min, root) (root, max)
```

### Core Condition

```cpp
if(root->val <= minValue ||
   root->val >= maxValue) {
    return false;
}
```

### Recursive Calls

```cpp
check(root->left, minValue, root->val);

check(root->right, root->val, maxValue);
```

---

# Final Code

```cpp
class Solution {
public:

    bool check(TreeNode* root, long long minValue, long long maxValue) {

        if(root == NULL) {
            return true;
        }

        if(root->val <= minValue || root->val >= maxValue) {
            return false;
        }

        bool left = check(root->left, minValue, root->val);

        bool right = check(root->right, root->val, maxValue);

        return left && right;
    }

    bool isValidBST(TreeNode* root) {

        return check(root, LLONG_MIN, LLONG_MAX);
    }
};
```

---

# Summary

| Feature          | Details                     |
| ---------------- | --------------------------- |
| Problem          | Validate Binary Search Tree |
| LeetCode         | 98                          |
| Difficulty       | Medium                      |
| Approach         | Recursion + Range           |
| Time Complexity  | `O(N)`                      |
| Space Complexity | `O(H)`                      |
| Root Range       | `(-∞, +∞)`                  |
| Left Range       | `(min, root->val)`          |
| Right Range      | `(root->val, max)`          |
| Duplicate Values | Not Allowed                 |

## 🧠 Final Takeaway

The main idea is:

```text
Left  → Smaller
Right → Greater
```

But checking only the immediate children is **not enough**.

Every node must satisfy the restrictions imposed by **all of its ancestors**.

Therefore:

```text
BST Validation
       ↓
Maintain Valid Range
       ↓
Recursion
       ↓
Every node valid
       ↓
true
```

**BST Validation = Recursion + Valid Range.** 🌳✅
