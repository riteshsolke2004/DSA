# 🌳 199. Binary Tree Right Side View

## Problem Statement

Given the `root` of a binary tree, imagine yourself standing on the **right side** of the tree.

Return the values of the nodes that are visible from the right side, ordered from **top to bottom**.

For each level of the binary tree, we need to find the **first node visible from the right side**.

---

# Example 1
<img width="671" height="348" alt="tmpd5jn43fs-1" src="https://github.com/user-attachments/assets/b9f7fa4a-48de-4e6b-af6b-3d625e0b8deb" />

### Input

```text
root = [1,2,3,null,5,null,4]
```

Tree:

```text
          1
        /   \
       2     3
        \     \
         5     4
```

From the right side:

```text
Level 0 → 1
Level 1 → 3
Level 2 → 4
```

### Output

```text
[1,3,4]
```

---

# Example 2
<img width="829" height="443" alt="tmpkpe40xeh-1" src="https://github.com/user-attachments/assets/bfe8991b-69a3-415b-b46d-eefe4da4150d" />

### Input

```text
root = [1,2,3,4,null,null,null,5]
```

Tree:

```text
          1
        /   \
       2     3
      /
     4
    /
   5
```

From the right side, the visible nodes are:

```text
Level 0 → 1
Level 1 → 3
Level 2 → 4
Level 3 → 5
```

### Output

```text
[1,3,4,5]
```

Notice that at level 2 there is no right-side node, so node `4` becomes visible.

---

# Example 3

### Input

```text
root = [1,null,3]
```

Tree:

```text
      1
       \
        3
```

Visible nodes:

```text
Level 0 → 1
Level 1 → 3
```

### Output

```text
[1,3]
```

---

# Example 4

### Input

```text
root = []
```

The tree is empty.

### Output

```text
[]
```

---

# What is Right Side View?

Consider:

```text
          1
        /   \
       2     3
      / \     \
     4   5     6
```

From the **right side**, we see:

```text
        👁
         \
          1
          |
          3
          |
          6
```

Therefore:

```text
Right View = [1,3,6]
```

We need the **first node encountered at every level**, but we visit the **right subtree first**.

---

# Main Approach

We use:

* **DFS**
* **Recursion**
* **Level tracking**

The important idea is:

> Visit the **right subtree first**, then the left subtree.

At every level, the first node we encounter is the node visible from the right side.

Traversal order:

```text
ROOT → RIGHT → LEFT
```

---

# Why Do We Need `level`?

We need to know which level of the tree we are currently visiting.

For example:

```text
          1          ← Level 0
        /   \
       2     3       ← Level 1
      /       \
     4         6     ← Level 2
```

We pass:

```cpp
int level
```

When moving to a child:

```cpp
level + 1
```

---

# Important Condition

The most important line is:

```cpp
if(level == ans.size()) {
    ans.push_back(root->val);
}
```

This means:

> If we haven't stored any node for this level yet, store the current node.

Initially:

```text
ans = []
level = 0
```

Therefore:

```text
0 == 0
```

So the root is added.

After adding:

```text
ans = [1]
```

Now `ans.size()` is `1`.

When another node at level `0` is encountered:

```text
level = 0
ans.size() = 1
```

Therefore:

```text
0 == 1
```

is false.

So we don't add another node at that level.

---

# Why Visit Right First?

We use:

```cpp
solve(root->right, ans, level + 1);
solve(root->left, ans, level + 1);
```

Because we want the **rightmost node** at each level.

By visiting:

```text
RIGHT → LEFT
```

the rightmost node is encountered first.

Therefore, it gets stored in `ans`.

---

# C++ Solution

```cpp
class Solution {
public:

    void solve(TreeNode* root, vector<int>& ans, int level) {

        if(root == NULL) {
            return;
        }

        // First node at this level
        if(level == ans.size()) {
            ans.push_back(root->val);
        }

        // Visit right first
        solve(root->right, ans, level + 1);

        // Then visit left
        solve(root->left, ans, level + 1);
    }

    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;

        solve(root, ans, 0);

        return ans;
    }
};
```

---

# Detailed Dry Run

Let's use:

```text
root = [1,2,3,null,5,null,4]
```

Tree:

```text
          1
        /   \
       2     3
        \     \
         5     4
```

---

## Step 1 — Node 1

Call:

```text
solve(1, ans, 0)
```

Initially:

```text
ans = []
level = 0
```

Check:

```text
level == ans.size()

0 == 0
```

True.

Add `1`:

```text
ans = [1]
```

Now visit **right first**:

```text
solve(3, ans, 1)
```

---

# Step 2 — Node 3

Current:

```text
level = 1
ans = [1]
```

Check:

```text
1 == 1
```

True.

Add `3`:

```text
ans = [1,3]
```

Now visit right:

```text
solve(4, ans, 2)
```

---

# Step 3 — Node 4

Current:

```text
level = 2
ans = [1,3]
```

Check:

```text
2 == 2
```

True.

Add `4`:

```text
ans = [1,3,4]
```

Node `4` has no children.

Return.

---

# Step 4 — Back to Node 3

Node `3` has no left child.

So:

```text
solve(NULL, ans, 2)
```

returns.

---

# Step 5 — Back to Node 1

Now the right subtree is completely processed.

We visit the left subtree:

```text
solve(2, ans, 1)
```

Current:

```text
level = 1
ans.size() = 3
```

Check:

```text
1 == 3
```

False.

So `2` is **not added**.

Why?

Because level `1` already has node `3`.

And `3` is visible from the right side.

---

# Step 6 — Node 5

Node `2` has a right child `5`.

So:

```text
solve(5, ans, 2)
```

Current:

```text
level = 2
ans.size() = 3
```

Check:

```text
2 == 3
```

False.

So `5` is not added.

Why?

Because level `2` already has:

```text
4
```

and `4` is the rightmost node at that level.

---

# Final Answer

After the complete traversal:

```text
ans = [1,3,4]
```

Therefore:

```text
Output = [1,3,4]
```

---

# Recursion Flow

For:

```text
          1
        /   \
       2     3
        \     \
         5     4
```

Our DFS order is:

```text
1
↓
3
↓
4
↓
2
↓
5
```

Now group by level:

```text
Level 0 → 1
Level 1 → 3, 2
Level 2 → 4, 5
```

The first node at each level is:

```text
Level 0 → 1
Level 1 → 3
Level 2 → 4
```

Therefore:

```text
[1,3,4]
```

---

# Visual Understanding

```text
          1  ← Level 0
        /   \
       2     3  ← Level 1
        \     \
         5     4  ← Level 2
```

From the right:

```text
                    👁
                     \
                      1
                      |
                      3
                      |
                      4
```

Therefore:

```text
Right View = [1,3,4]
```

---

# Why `level == ans.size()` Works

Suppose we are processing level `2`.

Before visiting the first node at level 2:

```text
ans = [1,3]
```

Therefore:

```text
ans.size() = 2
```

Current:

```text
level = 2
```

So:

```text
2 == 2
```

is true.

We add the node:

```text
ans = [1,3,4]
```

Now:

```text
ans.size() = 3
```

If another node at level 2 is visited:

```text
level = 2
```

Then:

```text
2 == 3
```

is false.

Therefore, it is ignored.

This guarantees:

> **Only the first node visited at each level is stored.**

---

# Right View vs Left View

This is very important.

## Left View

Visit:

```text
ROOT → LEFT → RIGHT
```

First node at every level:

```text
[1,2,4]
```

---

## Right View

Visit:

```text
ROOT → RIGHT → LEFT
```

First node at every level:

```text
[1,3,4]
```

So the difference is simply the traversal order.

```text
LEFT VIEW:

LEFT → RIGHT


RIGHT VIEW:

RIGHT → LEFT
```

---

# Example Comparison

Consider:

```text
          1
        /   \
       2     3
      / \   / \
     4   5 6   7
```

### Left View

Traversal:

```text
1 → 2 → 4 → 5 → 3 → 6 → 7
```

First node per level:

```text
Level 0 → 1
Level 1 → 2
Level 2 → 4
```

Output:

```text
[1,2,4]
```

### Right View

Traversal:

```text
1 → 3 → 7 → 6 → 2 → 5 → 4
```

First node per level:

```text
Level 0 → 1
Level 1 → 3
Level 2 → 7
```

Output:

```text
[1,3,7]
```

---

# Algorithm

### Step 1

Create an empty vector:

```cpp
vector<int> ans;
```

### Step 2

Start DFS:

```cpp
solve(root, ans, 0);
```

### Step 3

If the node is `NULL`, return.

### Step 4

Check:

```cpp
level == ans.size()
```

If true, store the node.

### Step 5

Visit the right subtree first.

### Step 6

Visit the left subtree.

### Step 7

Return `ans`.

---

# Complexity Analysis

Every node is visited once.

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

The answer vector requires at most one node per level.

---

# Edge Cases

## 1. Empty Tree

```text
root = []
```

Output:

```text
[]
```

---

## 2. Single Node

```text
    1
```

Output:

```text
[1]
```

---

## 3. Right-Skewed Tree

```text
1
 \
  2
   \
    3
```

Every node is visible.

Output:

```text
[1,2,3]
```

---

## 4. Left-Skewed Tree

```text
    1
   /
  2
 /
3
```

Even though all nodes are on the left, they are still visible because there is no node blocking them.

Output:

```text
[1,2,3]
```

---

## 5. Missing Right Node

Consider:

```text
          1
        /   \
       2     3
      /
     4
```

At level 2, there is only `4`.

So:

```text
Right View = [1,3,4]
```

This shows that the right view doesn't necessarily mean "always choose the right child." It means:

> Choose the **rightmost visible node at each level**.

---

# Common Mistakes

### ❌ Mistake 1 — Visiting Left First

If you write:

```cpp
solve(root->left, ans, level + 1);
solve(root->right, ans, level + 1);
```

you are calculating the **left view**, not the right view.

For right view, use:

```cpp
solve(root->right, ans, level + 1);
solve(root->left, ans, level + 1);
```

---

### ❌ Mistake 2 — Adding Every Node

Don't simply do:

```cpp
ans.push_back(root->val);
```

That gives a traversal, not the right view.

Use:

```cpp
if(level == ans.size())
    ans.push_back(root->val);
```

---

### ❌ Mistake 3 — Forgetting `level + 1`

Children are one level deeper:

```cpp
solve(root->right, ans, level + 1);
solve(root->left, ans, level + 1);
```

---

### ❌ Mistake 4 — Thinking Right View Means Always Right Child

This is incorrect.

Example:

```text
      1
     / \
    2   3
   /
  4
```

At level 2, there is no right child.

So `4` is still visible.

Right view:

```text
[1,3,4]
```

---

# Key Concepts

* Binary Tree
* DFS
* Recursion
* Preorder Traversal
* Level Tracking
* Right View
* First Node at Each Level

---

# Important Observation

The solution is basically **Preorder DFS**, but with a different child order:

```text
Normal Preorder:

ROOT → LEFT → RIGHT
```

For right view:

```text
ROOT → RIGHT → LEFT
```

Then:

```text
Take first node at every level
```

So remember:

```text
Right View
    ↓
Preorder DFS
    ↓
Root → Right → Left
    ↓
First node at every level
```

---

# Quick Revision

The two most important parts are:

```cpp
if(level == ans.size()) {
    ans.push_back(root->val);
}
```

and:

```cpp
solve(root->right, ans, level + 1);
solve(root->left, ans, level + 1);
```

Therefore:

```text
RIGHT FIRST
     ↓
FIRST NODE AT EACH LEVEL
     ↓
RIGHT SIDE VIEW
```

---

# Final Code

```cpp
class Solution {
public:

    void solve(TreeNode* root, vector<int>& ans, int level) {

        if(root == NULL) {
            return;
        }

        if(level == ans.size()) {
            ans.push_back(root->val);
        }

        solve(root->right, ans, level + 1);

        solve(root->left, ans, level + 1);
    }

    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;

        solve(root, ans, 0);

        return ans;
    }
};
```

---

# Summary

| Concept             | Details                     |
| ------------------- | --------------------------- |
| Problem             | Binary Tree Right Side View |
| LeetCode            | 199                         |
| Difficulty          | Medium                      |
| Approach            | DFS + Recursion             |
| Traversal           | `Root → Right → Left`       |
| Time                | `O(N)`                      |
| Space               | `O(H)`                      |
| Main Idea           | First node at every level   |
| Level Tracking      | `level`                     |
| Important Condition | `level == ans.size()`       |
| Empty Tree          | `[]`                        |

## 🧠 Remember

**Left View:**

```text
ROOT → LEFT → RIGHT
```

**Right View:**

```text
ROOT → RIGHT → LEFT
```

Both use the same idea:

```text
First node encountered at every level
```

Only the traversal direction changes. 🌳
