# 🌳 Lowest Common Ancestor in Binary Tree

## Problem Statement

Given the **root** of a binary tree containing unique values and two node values `n1` and `n2`, find the **Lowest Common Ancestor (LCA)** of these two nodes.

The **Lowest Common Ancestor** is the lowest node in the tree that has both `n1` and `n2` as descendants.

A node can also be considered a descendant of itself.

Both `n1` and `n2` are guaranteed to be present in the tree.

---

# What is LCA?

Consider this tree:

```text
          1
        /   \
       2     3
      / \   / \
     4   5 6   7
```

For:

```text
n1 = 4
n2 = 5
```

Both nodes are inside the subtree of `2`.

Therefore:

```text
LCA(4,5) = 2
```

---

# Example 1

<img width="455" height="285" alt="blobid3_1785502298" src="https://github.com/user-attachments/assets/9e65e8a7-dc76-44f6-a08a-591e4c05211c" />

### Input

```text
root = [1,2,3,4,5,6,7]
n1 = 4
n2 = 5
```

Tree:

```text
          1
        /   \
       2     3
      / \   / \
     4   5 6   7
```

Path to `4`:

```text
1 → 2 → 4
```

Path to `5`:

```text
1 → 2 → 5
```

The first common node from the bottom is:

```text
2
```

### Output

```text
2
```

---

# Example 2
<img width="455" height="285" alt="blobid4_1785502298" src="https://github.com/user-attachments/assets/46ac57ee-ed0c-47eb-b136-e22ec492f36d" />

### Input

```text
root = [1,2,3,4,5,6,7,N,N,N,N,8]

n1 = 7
n2 = 8
```

Tree:

```text
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
              \
               8
```

The paths are:

```text
1 → 3 → 7
```

and:

```text
1 → 3 → 6 → 8
```

The lowest common ancestor is:

```text
3
```

### Output

```text
3
```

---

# Approach

We solve this problem using **Recursion + DFS**.

At every node, there are three important cases:

### Case 1 — Current node is `NULL`

There is no answer in this subtree.

Return:

```cpp
NULL
```

---

### Case 2 — Current node is `n1` or `n2`

We found one of the required nodes.

Return:

```cpp
root
```

---

### Case 3 — Search Both Subtrees

Recursively search:

```text
Left subtree
      +
Right subtree
```

We get:

```cpp
leftans
rightans
```

Now there are four possibilities.

---

# Four Cases After Recursion

## Case 1

```text
leftans = NULL
rightans = NULL
```

Neither node exists in this subtree.

Return:

```cpp
NULL
```

---

## Case 2

```text
leftans != NULL
rightans == NULL
```

A required node was found in the left subtree.

Return:

```cpp
leftans
```

---

## Case 3

```text
leftans == NULL
rightans != NULL
```

A required node was found in the right subtree.

Return:

```cpp
rightans
```

---

## Case 4 — Most Important

```text
leftans != NULL
rightans != NULL
```

This means:

* One node was found in the left subtree.
* The other node was found in the right subtree.

Therefore, the **current node is the LCA**.

Return:

```cpp
root
```

---

# Visual Understanding

Consider:

```text
          1
        /   \
       2     3
      / \   / \
     4   5 6   7
```

Find:

```text
n1 = 4
n2 = 5
```

At node `2`:

```text
       2
      / \
     4   5
```

The recursive calls return:

```text
leftans  = 4
rightans = 5
```

Since both are non-null:

```cpp
if(leftans != NULL && rightans != NULL)
    return root;
```

Therefore:

```text
LCA = 2
```

---

# C++ Solution

```cpp
class Solution {
public:

    Node* lca(Node* root, int n1, int n2) {

        // Base case
        if(root == NULL) {
            return NULL;
        }

        // Current node is one of the target nodes
        if(root->data == n1) {
            return root;
        }

        if(root->data == n2) {
            return root;
        }

        // Search left subtree
        Node* leftans = lca(root->left, n1, n2);

        // Search right subtree
        Node* rightans = lca(root->right, n1, n2);

        // Both sides don't contain target
        if(leftans == NULL && rightans == NULL) {
            return NULL;
        }

        // Target found in left subtree
        if(leftans != NULL && rightans == NULL) {
            return leftans;
        }

        // Target found in right subtree
        if(leftans == NULL && rightans != NULL) {
            return rightans;
        }

        // One target on each side
        if(leftans != NULL && rightans != NULL) {
            return root;
        }

        return NULL;
    }
};
```

---

# Dry Run

Let's use:

```text
root = [1,2,3,4,5,6,7]
n1 = 4
n2 = 5
```

Tree:

```text
          1
        /   \
       2     3
      / \   / \
     4   5 6   7
```

---

## Step 1 — Start at Node 1

```text
lca(1, 4, 5)
```

Node `1` is neither `4` nor `5`.

So search both:

```text
left → node 2
right → node 3
```

---

# Step 2 — Node 2

```text
lca(2, 4, 5)
```

Node `2` is neither target.

Search left:

```text
lca(4,4,5)
```

---

# Step 3 — Node 4

```text
root->data == n1
```

So:

```cpp
return root;
```

Therefore:

```text
leftans = Node 4
```

---

# Step 4 — Search Right of Node 2

Now:

```text
lca(5,4,5)
```

Node `5` equals `n2`.

Therefore:

```cpp
return root;
```

So:

```text
rightans = Node 5
```

---

# Step 5 — Back at Node 2

We now have:

```text
leftans  = 4
rightans = 5
```

Both are non-null.

Therefore:

```cpp
return root;
```

Here:

```text
root = 2
```

So:

```text
LCA = 2
```

---

# Step 6 — Back at Node 1

The left subtree returned:

```text
Node 2
```

The right subtree is searched for `4` and `5`.

Neither exists in the right subtree.

Therefore:

```text
rightans = NULL
```

At node `1`:

```text
leftans  = 2
rightans = NULL
```

So we return:

```text
leftans
```

which is:

```text
Node 2
```

Final answer:

```text
2
```

---

# Recursion Flow

```text
                         1
                       /   \
                      2     3
                     / \
                    4   5
```

Search:

```text
                 lca(1)
                /      \
            lca(2)    lca(3)
             /   \
         lca(4)  lca(5)
            ↓       ↓
            4       5
             \     /
              \   /
               Node 2
                  ↓
               LCA = 2
```

---

# Why Do We Return `leftans`?

Suppose:

```text
          1
         /
        2
       /
      4
```

and:

```text
n1 = 4
n2 = 2
```

At node `2`, we immediately find `n2`.

So node `2` is returned.

At node `1`:

```text
leftans = 2
rightans = NULL
```

There is no reason for node `1` to become the LCA.

So we return:

```cpp
return leftans;
```

This allows the already-found answer to travel back up the recursion.

---

# Why Do We Return `root` When Both Are Non-NULL?

This is the core idea.

Suppose:

```text
          2
         / \
        4   5
```

We search for `4` and `5`.

Left recursion finds:

```text
4
```

Right recursion finds:

```text
5
```

So:

```text
leftans  != NULL
rightans != NULL
```

This means the two target nodes are located in **different branches** of node `2`.

Therefore:

```text
2
```

is their lowest common ancestor.

---

# Important Pattern

For LCA in a normal Binary Tree:

```text
                    ROOT
                   /    \
                  /      \
             Search      Search
              LEFT       RIGHT
                ↓          ↓
             leftans    rightans
                  \       /
                   \     /
                    CHECK
```

Then:

```text
leftans == NULL
rightans == NULL
        ↓
      NULL
```

```text
leftans != NULL
rightans == NULL
        ↓
    leftans
```

```text
leftans == NULL
rightans != NULL
        ↓
    rightans
```

```text
leftans != NULL
rightans != NULL
        ↓
       ROOT
```

---

# Important Difference: Binary Tree vs BST

This solution is for a **normal Binary Tree**.

We cannot use:

```text
n1 < root
n2 < root
```

to decide which side to search.

That shortcut works for a **Binary Search Tree (BST)** because BST has ordering.

For a normal Binary Tree, we must search:

```text
LEFT + RIGHT
```

---

# Complexity Analysis

Each node may be visited once.

### Time Complexity

```text
O(N)
```

where `N` is the number of nodes.

### Space Complexity

The recursion stack depends on tree height:

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
root = NULL
```

Return:

```text
NULL
```

---

## 2. One Node Is the Root

Example:

```text
      1
     / \
    2   3
```

Find:

```text
n1 = 1
n2 = 3
```

Since root is `n1`, we return root:

```text
LCA = 1
```

---

## 3. Both Nodes Are in Different Subtrees

```text
       1
      / \
     2   3
```

For:

```text
n1 = 2
n2 = 3
```

Left returns `2`.

Right returns `3`.

Therefore:

```text
LCA = 1
```

---

## 4. One Node Is an Ancestor of the Other

```text
       1
      /
     2
    /
   4
```

For:

```text
n1 = 2
n2 = 4
```

Node `2` is already an ancestor of `4`.

Since we check:

```cpp
if(root->data == n1)
    return root;
```

we correctly return:

```text
2
```

---

# Key Concepts

* Binary Tree
* DFS
* Recursion
* Lowest Common Ancestor
* Divide and Conquer
* Postorder-style recursion

---

# The Most Important Logic

Remember these four cases:

```cpp
if(leftans == NULL && rightans == NULL)
    return NULL;

if(leftans != NULL && rightans == NULL)
    return leftans;

if(leftans == NULL && rightans != NULL)
    return rightans;

if(leftans != NULL && rightans != NULL)
    return root;
```

Or simply remember:

```text
Both NULL       → NULL
Only LEFT       → LEFT
Only RIGHT      → RIGHT
Both non-NULL   → ROOT
```

---

# Optimized / Cleaner Version

The same logic can be written more cleanly:

```cpp
class Solution {
public:

    Node* lca(Node* root, int n1, int n2) {

        if(root == NULL) {
            return NULL;
        }

        if(root->data == n1 || root->data == n2) {
            return root;
        }

        Node* leftans = lca(root->left, n1, n2);
        Node* rightans = lca(root->right, n1, n2);

        if(leftans != NULL && rightans != NULL) {
            return root;
        }

        if(leftans != NULL) {
            return leftans;
        }

        return rightans;
    }
};
```

This has the same:

```text
Time  = O(N)
Space = O(H)
```

but is much easier to remember.

---

# Final Summary

| Concept                | Details              |
| ---------------------- | -------------------- |
| Problem                | LCA in Binary Tree   |
| Difficulty             | Medium               |
| Approach               | DFS + Recursion      |
| Time                   | `O(N)`               |
| Space                  | `O(H)`               |
| Main Idea              | Search both subtrees |
| Both sides return node | Current node is LCA  |
| Only left returns      | Return left answer   |
| Only right returns     | Return right answer  |
| Neither returns        | Return `NULL`        |

## 🧠 Remember

The golden rule for LCA in a normal Binary Tree:

```text
          ROOT
         /    \
      target  target
         \    /
          \  /
           ROOT
            ↓
           LCA
```

If **one target comes from the left and the other from the right**, the current node is the LCA.

And if the current node itself is one of the targets, return it immediately.

```cpp
if(root->data == n1 || root->data == n2)
    return root;
```

That's the core trick. 🌳
