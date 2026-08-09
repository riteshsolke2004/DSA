# 🌳 Binary Tree Maximum Path Sum

## Problem Statement

Given the `root` of a binary tree, find the **maximum path sum** of any non-empty path.

A **path** is a sequence of nodes where every pair of adjacent nodes is connected by an edge.

Important points:

* A node can appear in the path **at most once**.
* The path does **not have to pass through the root**.
* The path can start and end at **any two nodes**.
* The path must contain at least **one node**.

---

# What is a Path?

Consider:

```text
        1
       / \
      2   3
```

Possible paths include:

```text
2
3
1
2 → 1
1 → 3
2 → 1 → 3
```

The path:

```text
2 → 1 → 3
```

has sum:

```text
2 + 1 + 3 = 6
```

So the maximum path sum is:

```text
6
```

---

# Example 1
<img width="322" height="182" alt="exx1" src="https://github.com/user-attachments/assets/04fd209b-a28d-4f20-87b9-3da5e1b78180" />

### Input

```text
root = [1,2,3]
```

Tree:

```text
        1
       / \
      2   3
```

The best path is:

```text
2 → 1 → 3
```

Sum:

```text
2 + 1 + 3 = 6
```

### Output

```text
6
```

---

# Example 2
<img width="431" height="302" alt="exx2" src="https://github.com/user-attachments/assets/cd74f309-2634-4cfa-bef9-bc217d075cf2" />

### Input

```text
root = [-10,9,20,null,null,15,7]
```

Tree:

```text
          -10
          /  \
         9    20
             /  \
            15   7
```

The best path is:

```text
15 → 20 → 7
```

Sum:

```text
15 + 20 + 7 = 42
```

### Output

```text
42
```

Notice that the maximum path does **not** pass through the root `-10`.

---

# Important Observation

At every node, there are two different values we need to think about.

Suppose:

```text
          Node
         /    \
        L      R
```

We calculate:

```text
left = best contribution from left subtree
right = best contribution from right subtree
```

Then there are two different concepts.

---

# 1. Maximum Path Through Current Node

A path can use both left and right sides:

```text
       Left
         \
          Node
         /
       Right
```

Therefore:

```text
currentPath =
root->val + left + right
```

This can potentially be the **final answer**.

---

# 2. Maximum Path Going Up to Parent

When returning to the parent, we **cannot return both left and right**.

Why?

Because a path cannot split into two branches when continuing upward.

So we return:

```text
root->val + max(left, right)
```

This represents:

```text
       Parent
          |
         Node
        /
       Best side
```

Only one side can continue toward the parent.

---

# The Two Important Formulas

### Formula 1 — Candidate Answer

```cpp
current = root->val + left + right;
```

This path can use:

```text
LEFT + ROOT + RIGHT
```

Update:

```cpp
ans = max(ans, current);
```

---

### Formula 2 — Return Value

```cpp
return root->val + max(left, right);
```

Only one branch can be returned to the parent.

---

# Why `max(0, ...)`?

This is the most important trick in the problem.

Suppose:

```text
        10
       /
     -20
```

If we include `-20`:

```text
10 + (-20) = -10
```

This makes the path worse.

So we simply ignore the negative contribution.

```cpp
int left = max(0, solve(root->left, ans));
```

If the left contribution is negative:

```text
-20
```

we use:

```text
0
```

Meaning:

> Don't take this subtree.

---

# Example

Consider:

```text
        10
       /  \
      5   -20
```

Left contribution:

```text
5
```

Right contribution:

```text
-20
```

After:

```cpp
max(0, -20)
```

we get:

```text
0
```

Therefore:

```text
current = 10 + 5 + 0
        = 15
```

We ignore the negative subtree.

---

# C++ Solution

```cpp
class Solution {
public:

    int solve(TreeNode* root, int& ans) {

        if(root == NULL) {
            return 0;
        }

        // Ignore negative contributions
        int left = max(0, solve(root->left, ans));
        int right = max(0, solve(root->right, ans));

        // Path passing through current node
        int current = root->val + left + right;

        // Update global maximum
        ans = max(ans, current);

        // Return one side to parent
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {

        int ans = INT_MIN;

        solve(root, ans);

        return ans;
    }
};
```

---

# Detailed Dry Run

Let's use:

```text
root = [-10,9,20,null,null,15,7]
```

Tree:

```text
          -10
          /  \
         9    20
             /  \
            15   7
```

Expected:

```text
42
```

---

# Step 1 — Node 9

Node `9` is a leaf.

Left:

```text
0
```

Right:

```text
0
```

Therefore:

```text
left = max(0,0) = 0
right = max(0,0) = 0
```

Current path:

```text
current = 9 + 0 + 0
        = 9
```

Update:

```text
ans = max(INT_MIN,9)
    = 9
```

Return to parent:

```text
9 + max(0,0)
= 9
```

So:

```text
solve(9) = 9
```

---

# Step 2 — Node 15

Node `15` is a leaf.

```text
left = 0
right = 0
```

Current:

```text
15 + 0 + 0
= 15
```

Update:

```text
ans = max(9,15)
    = 15
```

Return:

```text
15
```

---

# Step 3 — Node 7

Node `7` is a leaf.

```text
left = 0
right = 0
```

Current:

```text
7
```

Update:

```text
ans = max(15,7)
    = 15
```

Return:

```text
7
```

---

# Step 4 — Node 20

Now we are at:

```text
       20
      /  \
     15   7
```

From left:

```text
left = 15
```

From right:

```text
right = 7
```

Both are positive, so we keep both.

Calculate:

```text
current = 20 + 15 + 7
        = 42
```

Update:

```text
ans = max(15,42)
    = 42
```

This is our best path:

```text
15 → 20 → 7
```

Now what should we return to `-10`?

We **cannot return**:

```text
15 + 20 + 7
```

because that would mean both branches continue upward.

We can return only one side:

```text
20 + max(15,7)
= 20 + 15
= 35
```

Therefore:

```text
solve(20) = 35
```

---

# Step 5 — Node -10

Tree:

```text
          -10
          /  \
         9    20
             /  \
            15   7
```

From left:

```text
left = 9
```

From right:

```text
right = 35
```

Both are positive.

Calculate:

```text
current = -10 + 9 + 35
        = 34
```

Update:

```text
ans = max(42,34)
    = 42
```

So the answer remains:

```text
42
```

Return value would be:

```text
-10 + max(9,35)
= -10 + 35
= 25
```

But this return value is not the final answer.

The global `ans` already contains:

```text
42
```

---

# Final Answer

```text
42
```

The path is:

```text
15 → 20 → 7
```

---

# Why Do We Need `ans`?

This is very important.

The value returned by `solve()` is **not necessarily the final answer**.

For example:

```text
          -10
          /  \
         9    20
             / \
            15  7
```

At node `20`:

```text
current = 15 + 20 + 7
        = 42
```

But the value returned to `-10` is:

```text
35
```

So we need a separate variable:

```cpp
int& ans
```

to store the maximum path found anywhere in the tree.

---

# Why Do We Return Only One Branch?

Consider:

```text
        20
       /  \
      15   7
```

The best path through `20` is:

```text
15 → 20 → 7
```

But if `20` has a parent:

```text
         Parent
            |
           20
          /  \
         15   7
```

We cannot return:

```text
15 → 20 → 7
```

to the parent because that creates a path with three directions.

A path must be continuous and cannot branch.

So we return:

```text
20 + max(15,7)
```

which is:

```text
35
```

This represents:

```text
Parent → 20 → 15
```

Only one side continues upward.

---

# Visual Difference

### Path used for `ans`

```text
        20
       /  \
      15   7

15 → 20 → 7
```

Formula:

```text
root + left + right
```

---

### Value returned to parent

```text
       Parent
          |
         20
        /
       15
```

Formula:

```text
root + max(left,right)
```

---

# The Two Values

At every node:

```text
┌──────────────────────────────────────┐
│                                      │
│  current = root + left + right      │
│                                      │
│  Used to update ANSWER               │
│                                      │
└──────────────────────────────────────┘

                 AND

┌──────────────────────────────────────┐
│                                      │
│  return = root + max(left,right)    │
│                                      │
│  Sent to PARENT                      │
│                                      │
└──────────────────────────────────────┘
```

This is the key concept of **LeetCode 124**.

---

# Handling Negative Values

Consider:

```text
        -3
       /  \
     -2   -5
```

We start with:

```cpp
int ans = INT_MIN;
```

This is important because all values could be negative.

At `-2`:

```text
current = -2
ans = -2
```

At `-5`:

```text
current = -5
ans = -2
```

At `-3`:

```text
left = max(0,-2)
     = 0

right = max(0,-5)
      = 0
```

Therefore:

```text
current = -3
```

Final:

```text
ans = -2
```

The answer is:

```text
-2
```

not `0`.

That's why we use:

```cpp
int ans = INT_MIN;
```

instead of:

```cpp
int ans = 0;
```

---

# Why `max(0, solve(...))`?

Suppose:

```text
left contribution = -10
```

Taking it would reduce our path sum.

So:

```cpp
max(0, -10)
```

gives:

```text
0
```

This means:

```text
Don't take this subtree.
```

For a positive contribution:

```text
max(0,15) = 15
```

So:

```text
Positive → Take it
Negative → Ignore it
```

---

# Recursion Flow

The algorithm follows **Postorder DFS**:

```text
        ROOT
       /    \
      /      \
    LEFT    RIGHT
      ↓        ↓
   result    result
      \        /
       \      /
        CURRENT
           ↓
       update ans
           ↓
       return value
```

The order is:

```text
LEFT → RIGHT → ROOT
```

This is necessary because the current node needs the best contributions from its children first.

---

# Core Algorithm

For every node:

### 1. Get left contribution

```cpp
left = max(0, solve(root->left, ans));
```

### 2. Get right contribution

```cpp
right = max(0, solve(root->right, ans));
```

### 3. Calculate path through current node

```cpp
current = root->val + left + right;
```

### 4. Update global answer

```cpp
ans = max(ans, current);
```

### 5. Return one branch to parent

```cpp
return root->val + max(left, right);
```

---

# Algorithm in Simple Words

At every node, ask:

> "If I make this node the middle of my path, what is the best sum I can get?"

Answer:

```text
node + best left + best right
```

Then ask:

> "If my parent wants to continue this path, which side should I give it?"

Answer:

```text
node + max(best left, best right)
```

That's the entire problem.

---

# Complexity Analysis

Every node is visited exactly once.

For each node, we perform constant-time operations.

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

LeetCode guarantees a non-empty tree for this problem, but if handled:

```cpp
if(root == NULL)
    return 0;
```

---

## 2. Single Node

```text
root = [5]
```

Answer:

```text
5
```

---

## 3. All Negative Values

```text
        -10
       /   \
     -20   -5
```

Answer:

```text
-5
```

We must use:

```cpp
INT_MIN
```

for the initial answer.

---

## 4. Positive and Negative Values

```text
        10
       /  \
     -20   30
```

Negative contribution is ignored:

```text
left = max(0,-20)
     = 0
```

Right:

```text
right = 30
```

Current:

```text
10 + 0 + 30
= 40
```

Answer:

```text
40
```

---

# Common Mistakes

### ❌ Mistake 1

Returning:

```cpp
root->val + left + right
```

This is wrong because the parent cannot continue through both branches.

Correct:

```cpp
return root->val + max(left, right);
```

---

### ❌ Mistake 2

Using:

```cpp
int ans = 0;
```

This fails when all values are negative.

Correct:

```cpp
int ans = INT_MIN;
```

---

### ❌ Mistake 3

Not ignoring negative contributions.

Wrong:

```cpp
left = solve(root->left, ans);
```

Correct:

```cpp
left = max(0, solve(root->left, ans));
```

---

# Key Concepts

* Binary Tree
* DFS
* Recursion
* Postorder Traversal
* Maximum Path Sum
* Global Maximum
* Negative Contribution
* Divide and Conquer

---

# Important Formulas

### Best path through current node

```text
current = root->val + left + right
```

### Value returned to parent

```text
return = root->val + max(left,right)
```

### Ignore negative subtree

```text
left  = max(0,left)
right = max(0,right)
```

---

# Final Code

```cpp
class Solution {
public:

    int solve(TreeNode* root, int& ans) {

        if(root == NULL)
            return 0;

        int left = max(0, solve(root->left, ans));
        int right = max(0, solve(root->right, ans));

        int current = root->val + left + right;

        ans = max(ans, current);

        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {

        int ans = INT_MIN;

        solve(root, ans);

        return ans;
    }
};
```

---

# Summary

| Concept           | Details                      |
| ----------------- | ---------------------------- |
| Problem           | Binary Tree Maximum Path Sum |
| LeetCode          | 124                          |
| Difficulty        | Hard                         |
| Approach          | DFS + Recursion              |
| Traversal         | Postorder                    |
| Time              | `O(N)`                       |
| Space             | `O(H)`                       |
| Global Answer     | `ans`                        |
| Ignore Negative   | `max(0, contribution)`       |
| Path Through Node | `root + left + right`        |
| Return to Parent  | `root + max(left,right)`     |

## 🧠 Remember This

The most important distinction:

```text
             CURRENT NODE
             /         \
            L           R

ANSWER:
L + NODE + R
      ↓
can use BOTH sides

RETURN:
NODE + max(L,R)
      ↓
can use ONLY ONE side
```

And:

```cpp
left = max(0, left);
right = max(0, right);
```

means:

> **Never allow a negative subtree to make your path worse.**

**Maximum Path Sum = best left contribution + current node + best right contribution.** 🌳
