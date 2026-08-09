# 🌳 101. Symmetric Tree

## Problem Statement

Given the `root` of a binary tree, determine whether the tree is **symmetric around its center**.

A binary tree is symmetric if its **left subtree is a mirror image of its right subtree**.

In simple words:

> The left side and right side should have the same structure and corresponding values should be equal.

---

# Example 1
<img width="354" height="291" alt="symtree1" src="https://github.com/user-attachments/assets/7199becd-790d-428c-85c4-b825f46c1b41" />

### Input

```text
root = [1,2,2,3,4,4,3]
```

Tree:

```text
          1
        /   \
       2     2
      / \   / \
     3   4 4   3
```

Compare the two sides:

```text
Left side:              Right side:

      2                     2
     / \                   / \
    3   4                 4   3
```

They are mirror images.

Therefore:

```text
Output: true
```

---

# Example 2
<img width="308" height="258" alt="symtree2" src="https://github.com/user-attachments/assets/a40e8abc-0d5a-4b8b-930d-d1515ca60882" />

### Input

```text
root = [1,2,2,null,3,null,3]
```

Tree:

```text
          1
        /   \
       2     2
        \     \
         3     3
```

The left and right sides are **not mirror images**.

Therefore:

```text
Output: false
```

---

# What Does Symmetric Mean?

Consider:

```text
          1
        /   \
       2     2
      / \   / \
     3   4 4   3
```

For symmetry:

```text
Left subtree        Right subtree
     2                   2
    / \                 / \
   3   4               4   3
```

We need to compare:

```text
left->left   ↔   right->right
left->right  ↔   right->left
```

Notice that we **do not** compare:

```text
left->left ↔ right->left
```

because that would be checking the same direction, not the mirror direction.

---

# Approach

We use **recursion** to compare two subtrees as mirror images.

Create a helper function:

```cpp
symmetric(left, right)
```

This function checks whether the `left` and `right` trees are mirror images.

---

# Step 1 — Both Nodes Are NULL

If:

```cpp
left == NULL && right == NULL
```

then both sides ended at the same position.

Therefore, they are symmetric.

```cpp
return true;
```

---

# Step 2 — One Node Is NULL

If:

```cpp
left == NULL || right == NULL
```

then one side has a node and the other side doesn't.

The structures are different.

Therefore:

```cpp
return false;
```

---

# Step 3 — Compare Values

If both nodes exist, their values must be equal.

```cpp
if(left->val != right->val)
    return false;
```

For example:

```text
left = 3
right = 4
```

Since:

```text
3 != 4
```

the tree is not symmetric.

---

# Step 4 — Compare Mirror Children

This is the **most important part**.

We compare:

```cpp
symmetric(left->left, right->right)
```

and:

```cpp
symmetric(left->right, right->left)
```

Why?

Because we are checking a mirror.

For:

```text
          1
        /   \
       2     2
      / \   / \
     3   4 4   3
```

the comparisons are:

```text
left side          right side

    2                  2
   / \                / \
  3   4              4   3

  3  ←────────────→  3
  4  ←────────────→  4
```

So:

```text
left->left  ↔ right->right
left->right ↔ right->left
```

---

# Step 5 — Both Comparisons Must Be True

We use:

```cpp
return leftans && rightans;
```

Both mirror comparisons must be true.

If either one is false:

```text
true && false = false
```

Therefore, the entire tree is not symmetric.

---

# C++ Solution

```cpp
class Solution {
public:

    bool symmetric(TreeNode* left, TreeNode* right) {

        // Both nodes are NULL
        if(left == NULL && right == NULL)
            return true;

        // One node is NULL
        if(left == NULL || right == NULL)
            return false;

        // Values are different
        if(left->val != right->val)
            return false;

        // Compare mirror children
        bool leftans = symmetric(left->left, right->right);

        bool rightans = symmetric(left->right, right->left);

        // Both sides must be symmetric
        return leftans && rightans;
    }

    bool isSymmetric(TreeNode* root) {

        if(root == NULL)
            return true;

        return symmetric(root->left, root->right);
    }
};
```

---

# Detailed Dry Run

Let's use:

```text
root = [1,2,2,3,4,4,3]
```

Tree:

```text
          1
        /   \
       2     2
      / \   / \
     3   4 4   3
```

We start with:

```cpp
isSymmetric(root)
```

Root is not `NULL`.

So:

```cpp
symmetric(root->left, root->right)
```

becomes:

```text
symmetric(2,2)
```

---

# Step 1 — Compare `2` and `2`

```text
left  = 2
right = 2
```

Both exist.

Compare:

```text
2 == 2
```

True.

Now:

```cpp
leftans = symmetric(left->left, right->right);
```

This means:

```text
symmetric(3,3)
```

And:

```cpp
rightans = symmetric(left->right, right->left);
```

This means:

```text
symmetric(4,4)
```

---

# Step 2 — Compare `3` and `3`

```text
left  = 3
right = 3
```

Values match.

Now compare their children:

```text
NULL ↔ NULL
NULL ↔ NULL
```

Both pairs are `NULL`.

So:

```text
symmetric(3,3) = true
```

Therefore:

```text
leftans = true
```

---

# Step 3 — Compare `4` and `4`

Same process:

```text
4 == 4
```

Their children are:

```text
NULL ↔ NULL
NULL ↔ NULL
```

Therefore:

```text
symmetric(4,4) = true
```

So:

```text
rightans = true
```

---

# Step 4 — Back to Root's Children

At node `2`:

```text
leftans  = true
rightans = true
```

Therefore:

```cpp
return leftans && rightans;
```

```text
true && true
= true
```

So:

```text
symmetric(2,2) = true
```

---

# Final Result

Back inside:

```cpp
isSymmetric(root)
```

we get:

```text
true
```

Therefore:

```text
Output: true
```

---

# Dry Run — False Example

Consider:

```text
root = [1,2,2,null,3,null,3]
```

Tree:

```text
          1
        /   \
       2     2
        \     \
         3     3
```

Start:

```text
symmetric(2,2)
```

Values match.

Now compare:

```text
left->left ↔ right->right
```

That becomes:

```text
NULL ↔ 3
```

One is `NULL`, the other is not.

Therefore:

```cpp
return false;
```

So:

```text
symmetric(2,2) = false
```

Final result:

```text
Output: false
```

---

# The Most Important Part

For a symmetric tree, remember:

```text
              LEFT          RIGHT
                \            /
                 \          /
                  MIRROR
```

We compare:

```text
LEFT subtree          RIGHT subtree

left->left       ↔    right->right
left->right      ↔    right->left
```

### NOT:

```text
left->left ↔ right->left ❌
left->right ↔ right->right ❌
```

---

# Recursion Pattern

The recursive flow is:

```text
                Root
               /    \
              /      \
           Left      Right
             \        /
              \      /
              Compare
                 ↓
       ┌─────────┴─────────┐
       ↓                   ↓
 left->left           left->right
      ↕                    ↕
right->right          right->left
```

---

# Mirror Comparison Example

Consider:

```text
          1
        /   \
       2     2
      / \   / \
     3   4 4   3
```

The comparison is:

```text
3 ←────────────→ 3

4 ←────────────→ 4
```

So the tree is symmetric.

---

# Why `leftans && rightans`?

Suppose:

```text
leftans = true
rightans = true
```

Then:

```text
true && true = true
```

Symmetric.

But:

```text
leftans = true
rightans = false
```

Then:

```text
true && false = false
```

Not symmetric.

Therefore:

```cpp
return leftans && rightans;
```

is required.

---

# Important Difference: Same Tree vs Symmetric Tree

### Same Tree

For LeetCode 100:

```cpp
isSameTree(p->left, q->left)
isSameTree(p->right, q->right)
```

We compare the **same directions**.

```text
LEFT  ↔ LEFT
RIGHT ↔ RIGHT
```

### Symmetric Tree

For LeetCode 101:

```cpp
symmetric(left->left, right->right)
symmetric(left->right, right->left)
```

We compare **mirror directions**.

```text
LEFT  ↔ RIGHT
RIGHT ↔ LEFT
```

This is the main difference.

---

# Complexity Analysis

Every node is visited once.

Therefore:

### Time Complexity

```text
O(N)
```

where `N` is the number of nodes.

### Space Complexity

The recursion stack depends on the height of the tree:

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

## 1. Empty Tree

```text
root = []
```

The root is `NULL`.

```cpp
if(root == NULL)
    return true;
```

Output:

```text
true
```

---

## 2. Single Node

```text
    1
```

There is nothing to compare.

Output:

```text
true
```

---

## 3. Two Equal Children

```text
      1
     / \
    2   2
```

Symmetric:

```text
true
```

---

## 4. Different Child Values

```text
      1
     / \
    2   3
```

Since:

```text
2 != 3
```

Output:

```text
false
```

---

## 5. Different Structure

```text
      1
     / \
    2   2
     \   \
      3   3
```

The structure is not mirrored.

Output:

```text
false
```

---

# Common Mistakes

### ❌ Mistake 1 — Comparing Same Directions

Wrong:

```cpp
symmetric(left->left, right->left);
```

Correct:

```cpp
symmetric(left->left, right->right);
```

---

### ❌ Mistake 2 — Forgetting the Second Comparison

You need both:

```cpp
symmetric(left->left, right->right);
```

and:

```cpp
symmetric(left->right, right->left);
```

---

### ❌ Mistake 3 — Not Checking NULL

Always handle:

```cpp
if(left == NULL && right == NULL)
```

and:

```cpp
if(left == NULL || right == NULL)
```

before accessing:

```cpp
left->val
right->val
```

---

# Key Concepts

* Binary Tree
* Recursion
* DFS
* Mirror Tree
* Symmetric Tree
* Base Cases
* Boolean Logic
* `&&` Operator

---

# Quick Revision

Remember these four steps:

```text
1️⃣ Both NULL
      ↓
   true

2️⃣ One NULL
      ↓
   false

3️⃣ Values different
      ↓
   false

4️⃣ Otherwise
      ↓
Compare mirror children
```

Mirror children:

```text
left->left  ↔ right->right
left->right ↔ right->left
```

Finally:

```cpp
return leftans && rightans;
```

---

# Final Code

```cpp
class Solution {
public:

    bool symmetric(TreeNode* left, TreeNode* right) {

        if(left == NULL && right == NULL)
            return true;

        if(left == NULL || right == NULL)
            return false;

        if(left->val != right->val)
            return false;

        bool leftans = symmetric(left->left, right->right);

        bool rightans = symmetric(left->right, right->left);

        return leftans && rightans;
    }

    bool isSymmetric(TreeNode* root) {

        if(root == NULL)
            return true;

        return symmetric(root->left, root->right);
    }
};
```

---

# Summary

| Concept          | Details                           |
| ---------------- | --------------------------------- |
| Problem          | Symmetric Tree                    |
| LeetCode         | 101                               |
| Difficulty       | Easy                              |
| Approach         | DFS + Recursion                   |
| Time             | `O(N)`                            |
| Space            | `O(H)`                            |
| Main Idea        | Compare left and right as mirrors |
| Left Comparison  | `left->left ↔ right->right`       |
| Right Comparison | `left->right ↔ right->left`       |
| Final Condition  | `leftans && rightans`             |

## 🧠 Remember

**Same Tree #100:**

```text
LEFT  ↔ LEFT
RIGHT ↔ RIGHT
```

**Symmetric Tree #101:**

```text
LEFT  ↔ RIGHT
RIGHT ↔ LEFT
```

That's the key difference. 🌳
