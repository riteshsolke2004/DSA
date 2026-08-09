# 🌳 572. Subtree of Another Tree

## Problem Statement

Given the roots of two binary trees `root` and `subRoot`, determine whether `subRoot` is a **subtree** of `root`.

A tree `subRoot` is considered a subtree of `root` if there exists a node in `root` such that the tree rooted at that node has:

* The **same structure**
* The **same node values**

as `subRoot`.

The entire tree `root` can also be considered a subtree of itself.

---

# Example 1
<img width="532" height="400" alt="subtree1-tree" src="https://github.com/user-attachments/assets/2c262508-dd35-45ca-b8c6-6edd6333a90b" />

### Input

```text
root = [3,4,5,1,2]
subRoot = [4,1,2]
```

Tree:

```text
          3
        /   \
       4     5
      / \
     1   2
```

`subRoot`:

```text
        4
       / \
      1   2
```

The tree rooted at node `4` in `root` is exactly the same as `subRoot`.

Therefore:

```text
Output: true
```

---

# Example 2
<img width="502" height="458" alt="subtree2-tree" src="https://github.com/user-attachments/assets/f5be1c83-4a75-44c1-86c7-c3c8f1701ae3" />

### Input

```text
root = [3,4,5,1,2,null,null,null,null,0]
subRoot = [4,1,2]
```

Tree:

```text
          3
        /   \
       4     5
      / \
     1   2
        /
       0
```

`subRoot` expects:

```text
      4
     / \
    1   2
```

But in `root`, node `2` has an additional child `0`.

Therefore, the structures are different.

```text
Output: false
```

---

# What Does Subtree Mean?

Consider:

```text
          3
        /   \
       4     5
      / \
     1   2
```

The following are subtrees:

```text
        3
       / \
      4   5
     / \
    1   2
```

```text
      4
     / \
    1   2
```

```text
    1
```

```text
    2
```

The subtree rooted at `4` is:

```text
      4
     / \
    1   2
```

If `subRoot` is exactly this tree, the answer is `true`.

---

# Main Idea

This problem combines two concepts:

### 1. Same Tree

We already know how to check whether two trees are identical.

We use:

```cpp
same(root, subRoot)
```

This checks:

* Same structure
* Same values

### 2. Search Every Node

We need to check whether `subRoot` matches the tree rooted at **any node** of `root`.

So we recursively search:

```text
Current node
     ↓
Check same tree?
   /       \
 LEFT      RIGHT
```

---

# Two Functions

Our solution uses two functions:

```cpp
same()
```

and:

```cpp
isSubtree()
```

---

# Function 1 — `same()`

```cpp
bool same(TreeNode* root, TreeNode* subRoot)
```

This checks whether two trees are exactly identical.

---

## Case 1 — Both NULL

```cpp
if(root == NULL && subRoot == NULL)
    return true;
```

Both trees ended at the same position.

Therefore:

```text
true
```

---

## Case 2 — One NULL

```cpp
if(root == NULL || subRoot == NULL)
    return false;
```

One tree has a node while the other doesn't.

Therefore their structures are different.

```text
false
```

---

## Case 3 — Different Values

```cpp
if(root->val != subRoot->val)
    return false;
```

If the node values are different, the trees cannot be identical.

---

## Case 4 — Compare Left and Right

```cpp
return same(root->left, subRoot->left) &&
       same(root->right, subRoot->right);
```

Both subtrees must be identical.

---

# Function 2 — `isSubtree()`

```cpp
bool isSubtree(TreeNode* root, TreeNode* subRoot)
```

This searches the entire `root` tree.

At every node:

```text
1. Check if current tree matches subRoot.
2. If not, search left subtree.
3. If not, search right subtree.
```

---

# Step-by-Step Logic

First:

```cpp
if(root == NULL)
    return false;
```

If there are no nodes left to search, we didn't find `subRoot`.

Then:

```cpp
if(same(root, subRoot))
    return true;
```

If the current node is the root of a tree identical to `subRoot`, we found it.

Otherwise:

```cpp
return isSubtree(root->left, subRoot) ||
       isSubtree(root->right, subRoot);
```

Search both sides.

---

# C++ Solution

```cpp
class Solution {
public:

    bool same(TreeNode* root, TreeNode* subRoot) {

        // Both are NULL
        if(root == NULL && subRoot == NULL)
            return true;

        // One is NULL
        if(root == NULL || subRoot == NULL)
            return false;

        // Values are different
        if(root->val != subRoot->val)
            return false;

        // Compare left and right subtrees
        return same(root->left, subRoot->left) &&
               same(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        // No tree left to search
        if(root == NULL)
            return false;

        // Current tree matches subRoot
        if(same(root, subRoot))
            return true;

        // Search left or right subtree
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};
```

---

# Detailed Dry Run

Let's use Example 1:

```text
root = [3,4,5,1,2]
subRoot = [4,1,2]
```

Tree:

```text
              3
            /   \
           4     5
          / \
         1   2
```

Subtree:

```text
          4
         / \
        1   2
```

---

# Step 1 — Start at Node 3

Call:

```cpp
isSubtree(3, subRoot)
```

First:

```cpp
same(3,4)
```

Compare:

```text
3 != 4
```

So:

```text
same(3,4) = false
```

Therefore we search:

```text
left → 4
right → 5
```

---

# Step 2 — Move to Node 4

Now:

```cpp
isSubtree(4, subRoot)
```

Call:

```cpp
same(4,4)
```

Values match.

Now compare:

```text
4's left  ↔ subRoot's left
4's right ↔ subRoot's right
```

---

# Step 3 — Compare Node 1

```text
root side:    1
subRoot:      1
```

Values match.

Their children are:

```text
NULL ↔ NULL
NULL ↔ NULL
```

Therefore:

```text
same(1,1) = true
```

---

# Step 4 — Compare Node 2

```text
root side:    2
subRoot:      2
```

Values match.

Children:

```text
NULL ↔ NULL
NULL ↔ NULL
```

Therefore:

```text
same(2,2) = true
```

---

# Step 5 — Back to Node 4

We have:

```text
left  = true
right = true
```

Therefore:

```text
true && true
= true
```

So:

```text
same(4,4) = true
```

Therefore:

```text
isSubtree(4, subRoot) = true
```

And finally:

```text
Output = true
```

---

# Recursion Visualization

```text
                  root = 3
                      |
                same(3,4)
                   false
                  /     \
                 /       \
              node 4    node 5
                 |
             same(4,4)
                true
                 |
            SUBTREE FOUND
                 ↓
               true
```

---

# Dry Run — False Example

Consider:

```text
root = [3,4,5,1,2,null,null,null,null,0]
subRoot = [4,1,2]
```

Tree:

```text
          3
        /   \
       4     5
      / \
     1   2
        /
       0
```

SubRoot:

```text
      4
     / \
    1   2
```

---

## Start at 3

```text
same(3,4)
```

Values differ:

```text
3 != 4
```

So:

```text
false
```

Search left.

---

## At Node 4

```text
same(4,4)
```

Values match.

Compare left:

```text
1 ↔ 1
```

This matches.

Now compare right:

```text
2 ↔ 2
```

Values match.

But now compare their children.

For `root`:

```text
2
/
0
```

For `subRoot`:

```text
2
```

So we eventually compare:

```text
0 ↔ NULL
```

One is NULL and the other isn't.

Therefore:

```text
same(2,2) = false
```

Therefore:

```text
same(4,4) = false
```

---

# Continue Searching

The algorithm then searches:

```text
left subtree
right subtree
```

No matching subtree is found.

Therefore:

```text
Output = false
```

---

# Why Do We Need `same()`?

Because simply finding the same root value isn't enough.

Consider:

```text
root:

       4
      / \
     1   2
        /
       0
```

and:

```text
subRoot:

       4
      / \
     1   2
```

Both have root value:

```text
4
```

But they are **not the same tree**.

So:

```cpp
same(root, subRoot)
```

must verify the **entire structure**.

---

# Important Difference: Same Tree vs Subtree

### Same Tree — LeetCode 100

We have two trees and directly ask:

```text
Are these two trees identical?
```

We compare:

```text
P ↔ Q
```

---

### Subtree — LeetCode 572

We have:

```text
Large Tree
     ↓
Search every node
     ↓
Does any subtree equal subRoot?
```

So the process is:

```text
Search + Same Tree
```

---

# Visualizing the Algorithm

```text
                  ROOT
                   |
          Is ROOT same as subRoot?
             /           \
           YES            NO
            ↓              ↓
          TRUE       Search LEFT
                         OR
                     Search RIGHT
```

This is exactly what:

```cpp
if(same(root, subRoot))
    return true;

return isSubtree(root->left, subRoot) ||
       isSubtree(root->right, subRoot);
```

does.

---

# Important Boolean Logic

The final line:

```cpp
return isSubtree(root->left, subRoot) ||
       isSubtree(root->right, subRoot);
```

uses `||`.

Why?

Because we only need **one side** to contain the subtree.

For example:

```text
left  = false
right = true
```

Then:

```text
false || true
= true
```

The subtree exists in the right side.

Similarly:

```text
true || false
= true
```

So:

```text
LEFT OR RIGHT
```

is exactly what we need.

---

# `same()` Uses `&&`

Inside `same()`:

```cpp
return same(root->left, subRoot->left) &&
       same(root->right, subRoot->right);
```

We need **both** sides to match.

Therefore:

```text
LEFT AND RIGHT
```

---

# Very Important Difference

### `same()`

```text
LEFT && RIGHT
```

Because both sides must match.

### `isSubtree()`

```text
LEFT || RIGHT
```

Because the subtree can be anywhere on either side.

Remember:

```text
same()      → AND
isSubtree() → OR
```

🔥 This is one of the easiest ways to remember the solution.

---

# Complexity Analysis

Let:

* `N` = number of nodes in `root`
* `M` = number of nodes in `subRoot`

For every node in `root`, we may call `same()`.

In the worst case:

```text
Time = O(N × M)
```

### Space Complexity

Because of recursion:

```text
O(H)
```

where `H` is the height of the tree.

Worst case:

```text
O(N)
```

---

# Edge Cases

## 1. `subRoot` is Found at Root

```text
root:
    3
   / \
  4   5

subRoot:
    3
   / \
  4   5
```

`root` itself is a subtree.

Output:

```text
true
```

---

## 2. `root` is NULL

```text
root = NULL
```

There is no subtree to search.

Your code returns:

```cpp
false
```

---

## 3. Same Root Value but Different Structure

```text
root:
      4
     / \
    1   2
       /
      0

subRoot:
      4
     / \
    1   2
```

Same root value but different structure.

Output:

```text
false
```

---

## 4. Single Node Subtree

```text
root:
       3
      / \
     4   5

subRoot:
       4
```

Node `4` exists.

Therefore:

```text
true
```

---

# Common Mistakes

### ❌ Mistake 1 — Only Comparing Root Values

Wrong:

```cpp
if(root->val == subRoot->val)
    return true;
```

This does not check the entire subtree.

---

### ❌ Mistake 2 — Using `&&` in `isSubtree()`

Wrong:

```cpp
return isSubtree(root->left, subRoot) &&
       isSubtree(root->right, subRoot);
```

The subtree only needs to exist on **one side**.

Correct:

```cpp
return isSubtree(root->left, subRoot) ||
       isSubtree(root->right, subRoot);
```

---

### ❌ Mistake 3 — Using `||` in `same()`

Wrong:

```cpp
return same(root->left, subRoot->left) ||
       same(root->right, subRoot->right);
```

Both sides must match.

Correct:

```cpp
return same(root->left, subRoot->left) &&
       same(root->right, subRoot->right);
```

---

# Key Concepts

* Binary Tree
* Recursion
* DFS
* Same Tree
* Subtree
* Structural Comparison
* Boolean Logic
* `&&`
* `||`

---

# Quick Revision

Remember the solution as:

```text
                 ROOT
                   |
             same(root,subRoot)
                   |
          ┌────────┴────────┐
          ↓                 ↓
        TRUE              FALSE
          ↓                 ↓
       return true      Search LEFT
                           OR
                       Search RIGHT
```

And:

```text
same()      → LEFT && RIGHT
isSubtree() → LEFT || RIGHT
```

---

# Final Code

```cpp
class Solution {
public:

    bool same(TreeNode* root, TreeNode* subRoot) {

        if(root == NULL && subRoot == NULL)
            return true;

        if(root == NULL || subRoot == NULL)
            return false;

        if(root->val != subRoot->val)
            return false;

        return same(root->left, subRoot->left) &&
               same(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(root == NULL)
            return false;

        if(same(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};
```

---

# Summary

| Concept             | Details                   |   |        |
| ------------------- | ------------------------- | - | ------ |
| Problem             | Subtree of Another Tree   |   |        |
| LeetCode            | 572                       |   |        |
| Difficulty          | Easy                      |   |        |
| Approach            | DFS + Recursion           |   |        |
| Helper Function     | `same()`                  |   |        |
| Time                | `O(N × M)`                |   |        |
| Space               | `O(H)`                    |   |        |
| `same()`            | Checks structure + values |   |        |
| `isSubtree()`       | Searches every node       |   |        |
| `same()` Logic      | `LEFT && RIGHT`           |   |        |
| `isSubtree()` Logic | `LEFT                     |   | RIGHT` |

## 🧠 Remember

The entire solution can be remembered in one sentence:

> **At every node of the main tree, check whether the subtree starting there is the same as `subRoot`; if not, search left or right.**

```text
isSubtree
    ↓
same?
 /   \
YES   NO
 ↓     ↓
true  LEFT || RIGHT
```

**Subtree = Search every possible root + Same Tree comparison.** 🌳
