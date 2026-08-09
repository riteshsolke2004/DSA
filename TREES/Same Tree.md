# 🌳  Same Tree

## Problem Statement

Given the roots of two binary trees `p` and `q`, determine whether the two trees are **the same**.

Two binary trees are considered the same if:

1. They have the **same structure**.
2. Corresponding nodes have the **same values**.

We need to compare both trees recursively.

---

# Example 1
<img width="622" height="182" alt="ex1" src="https://github.com/user-attachments/assets/5f8d7347-5646-4650-b132-6e7d88b5ad49" />

### Input

```text
p = [1,2,3]
q = [1,2,3]
```

Trees:

```text
Tree P:             Tree Q:

    1                   1
   / \                 / \
  2   3               2   3
```

Both trees have:

* Same root value: `1`
* Same left value: `2`
* Same right value: `3`
* Same structure

Therefore:

```text
Output: true
```

---

# Example 2
<img width="382" height="182" alt="ex2" src="https://github.com/user-attachments/assets/02156e7b-55e3-4ccc-91b3-957536a94643" />

### Input

```text
p = [1,2]
q = [1,null,2]
```

Trees:

```text
Tree P:             Tree Q:

    1                   1
   /                     \
  2                       2
```

The values are the same, but the structure is different.

In `p`:

```text
1 → left → 2
```

In `q`:

```text
1 → right → 2
```

Therefore:

```text
Output: false
```

---

# Example 3
<img width="622" height="182" alt="ex3" src="https://github.com/user-attachments/assets/e2be7023-2632-4207-a149-165061b5a59c" />

### Input

```text
p = [1,2,1]
q = [1,1,2]
```

Trees:

```text
Tree P:             Tree Q:

    1                   1
   / \                 / \
  2   1               1   2
```

The structure is the same, but corresponding node values are different.

Therefore:

```text
Output: false
```

---

# Approach

We compare the two trees **node by node** using recursion.

For every pair of corresponding nodes, we check three things:

```text
1. Are both NULL?
2. Is one NULL and the other not?
3. Do their values match?
```

If all these conditions are satisfied, we recursively compare:

```text
Left subtree
     +
Right subtree
```

---

# Step 1 — Both Nodes Are NULL

If:

```cpp
p == NULL && q == NULL
```

then both trees have reached the end at the same position.

Therefore, they match.

Return:

```cpp
true
```

```cpp
if(p == NULL && q == NULL) {
    return true;
}
```

---

# Step 2 — One Node Is NULL

Suppose:

```text
p = NULL
q = 2
```

or:

```text
p = 2
q = NULL
```

The structures are different.

Therefore:

```cpp
if(p == NULL || q == NULL) {
    return false;
}
```

---

# Step 3 — Compare Values

If both nodes exist, compare their values:

```cpp
if(p->val != q->val) {
    return false;
}
```

For example:

```text
p = 5
q = 7
```

Since:

```text
5 != 7
```

the trees cannot be the same.

---

# Step 4 — Compare Left Subtrees

```cpp
bool left = isSameTree(p->left, q->left);
```

This recursively compares the left children.

---

# Step 5 — Compare Right Subtrees

```cpp
bool right = isSameTree(p->right, q->right);
```

This recursively compares the right children.

---

# Step 6 — Final Result

Both subtrees must be identical.

Therefore:

```cpp
return left && right;
```

If:

```text
left = true
right = true
```

then:

```text
true && true = true
```

Otherwise:

```text
false
```

---

# C++ Solution

```cpp
class Solution {
public:

    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Both nodes are NULL
        if(p == NULL && q == NULL) {
            return true;
        }

        // One node is NULL
        if(p == NULL || q == NULL) {
            return false;
        }

        // Values are different
        if(p->val != q->val) {
            return false;
        }

        // Compare left subtrees
        bool left = isSameTree(p->left, q->left);

        // Compare right subtrees
        bool right = isSameTree(p->right, q->right);

        // Both must be same
        return left && right;
    }
};
```

---

# Detailed Dry Run

Consider:

```text
p = [1,2,3]
q = [1,2,3]
```

Trees:

```text
        1                 1
       / \               / \
      2   3             2   3
```

---

## Step 1 — Compare Root

```cpp
isSameTree(1,1)
```

Both are not `NULL`.

Compare:

```text
1 == 1
```

True.

Now recursively compare:

```text
left  → (2,2)
right → (3,3)
```

---

# Step 2 — Compare Node 2

```cpp
isSameTree(2,2)
```

Values:

```text
2 == 2
```

True.

Compare left:

```text
NULL, NULL
```

Both are `NULL`.

Therefore:

```text
true
```

Compare right:

```text
NULL, NULL
```

Again:

```text
true
```

So:

```text
left  = true
right = true
```

Therefore:

```text
true && true
= true
```

Node `2` matches.

---

# Step 3 — Compare Node 3

```cpp
isSameTree(3,3)
```

Values:

```text
3 == 3
```

True.

Left:

```text
NULL, NULL
```

→ `true`

Right:

```text
NULL, NULL
```

→ `true`

Therefore node `3` matches.

---

# Step 4 — Back to Root

We have:

```text
left  = true
right = true
```

Therefore:

```cpp
return left && right;
```

Result:

```text
true && true
= true
```

### Final Answer

```text
true
```

---

# Dry Run — Different Structure

Consider:

```text
p = [1,2]
q = [1,null,2]
```

Trees:

```text
P:              Q:

    1               1
   /                 \
  2                   2
```

Start:

```text
isSameTree(1,1)
```

Values match.

Now compare left:

```text
isSameTree(2,NULL)
```

Here:

```text
p != NULL
q == NULL
```

So:

```cpp
return false;
```

Therefore:

```text
left = false
```

Even though we could stop here, the final condition would be:

```text
false && ...
```

which is:

```text
false
```

### Final Answer

```text
false
```

---

# Dry Run — Different Values

Consider:

```text
p = [1,2,1]
q = [1,1,2]
```

Trees:

```text
P:              Q:

    1               1
   / \             / \
  2   1           1   2
```

Root:

```text
1 == 1
```

So continue.

Compare left:

```text
2 vs 1
```

Values are different:

```text
2 != 1
```

Immediately:

```cpp
return false;
```

Therefore the trees are not the same.

---

# Three Important Conditions

You can remember the entire problem with these three checks:

### 1. Both NULL

```cpp
if(p == NULL && q == NULL)
    return true;
```

Means:

> Both trees ended at the same position.

---

### 2. One NULL

```cpp
if(p == NULL || q == NULL)
    return false;
```

Means:

> Structure is different.

---

### 3. Different Values

```cpp
if(p->val != q->val)
    return false;
```

Means:

> Node values are different.

If none of these conditions fail:

```text
Compare LEFT
+
Compare RIGHT
```

---

# Recursion Pattern

The recursion looks like:

```text
                  P       Q
                  |       |
               Compare
              /       \
             /         \
          LEFT         RIGHT
           ↓             ↓
       Compare        Compare
           ↓             ↓
          ...           ...
```

For every pair of nodes:

```text
         P               Q
         |               |
       value           value
         ↓               ↓
       Compare values
             ↓
        /           \
      LEFT          RIGHT
```

---

# Why `left && right`?

Suppose:

```text
left = true
right = true
```

Then:

```text
true && true
= true
```

Both sides are identical.

But:

```text
left = true
right = false
```

Then:

```text
true && false
= false
```

One side is different, so the complete tree is different.

Similarly:

```text
false && true = false
false && false = false
```

Therefore:

```cpp
return left && right;
```

is exactly what we need.

---

# Recursive Tree Comparison

The complete logic is:

```text
             Compare P and Q
                    |
          ┌─────────┴─────────┐
          ↓                   ↓
       P == NULL           P != NULL
       Q == NULL            Q != NULL
          ↓                   ↓
        TRUE             Compare values
                              |
                         ┌────┴────┐
                         ↓         ↓
                       LEFT      RIGHT
                         ↓         ↓
                      Compare   Compare
                         \         /
                          \       /
                           ↓     ↓
                            && 
                             ↓
                           Result
```

---

# Complexity Analysis

Let `N` be the number of nodes being compared.

Every corresponding node is visited at most once.

### Time Complexity

```text
O(N)
```

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

## 1. Both Trees Empty

```text
p = []
q = []
```

Both are `NULL`.

Output:

```text
true
```

---

## 2. One Tree Empty

```text
p = []
q = [1]
```

One is `NULL`.

Output:

```text
false
```

---

## 3. Single Identical Nodes

```text
p = [5]
q = [5]
```

Output:

```text
true
```

---

## 4. Single Different Nodes

```text
p = [5]
q = [10]
```

Output:

```text
false
```

---

# Common Mistakes

### ❌ Mistake 1 — Only Comparing Values

Checking:

```cpp
p->val == q->val
```

is not enough.

The structure must also be identical.

Example:

```text
P:      1          Q:      1
       /                  \
      2                    2
```

Values are the same, but the trees are different.

---

### ❌ Mistake 2 — Forgetting NULL Cases

Always check:

```cpp
if(p == NULL && q == NULL)
```

and:

```cpp
if(p == NULL || q == NULL)
```

before accessing:

```cpp
p->val
q->val
```

Otherwise, you may access a `NULL` pointer.

---

# Key Concepts

* Binary Tree
* Recursion
* DFS
* Structural Comparison
* Boolean Logic
* `&&` operator
* Base Cases

---

# Important Pattern

Remember this pattern for comparing two trees:

```cpp
if(p == NULL && q == NULL)
    return true;

if(p == NULL || q == NULL)
    return false;

if(p->val != q->val)
    return false;

return isSameTree(p->left, q->left)
    && isSameTree(p->right, q->right);
```

This is the cleanest way to remember the solution.

---

# Final Code

```cpp
class Solution {
public:

    bool isSameTree(TreeNode* p, TreeNode* q) {

        if(p == NULL && q == NULL) {
            return true;
        }

        if(p == NULL || q == NULL) {
            return false;
        }

        if(p->val != q->val) {
            return false;
        }

        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);

        return left && right;
    }
};
```

---

# Summary

| Concept         | Details            |
| --------------- | ------------------ |
| Problem         | Same Tree          |
| LeetCode        | 100                |
| Difficulty      | Easy               |
| Approach        | DFS + Recursion    |
| Time            | `O(N)`             |
| Space           | `O(H)`             |
| Compare         | Structure + Values |
| Both NULL       | `true`             |
| One NULL        | `false`            |
| Different Value | `false`            |
| Final Condition | `left && right`    |

## 🧠 Remember

For **Same Tree**, always ask three questions:

```text
1️⃣ Both NULL?
      ↓
    TRUE

2️⃣ One NULL?
      ↓
    FALSE

3️⃣ Values different?
      ↓
    FALSE

Otherwise:
      ↓
Compare LEFT + RIGHT
      ↓
   left && right
```

**Same Tree = Same structure + Same corresponding values.** 🌳
