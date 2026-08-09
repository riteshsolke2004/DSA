# 🌳 Left View of Binary Tree

## Problem Statement

Given the `root` of a binary tree, return the **left view** of the tree.

The **left view** is the set of nodes that are visible when the binary tree is viewed from the **left side**.

For every level of the tree, we need to return the **first node encountered from the left**.

If the tree is empty, return an empty vector.

---

# What is Left View?

Consider the following tree:

```text
        1
       / \
      2   3
     / \
    4   5
```

If we look at the tree from the left side:

```text
Level 0 → 1
Level 1 → 2
Level 2 → 4
```

Therefore:

```text
Left View = [1, 2, 4]
```

The nodes `3` and `5` are hidden behind the nodes `2` and `4`.

---

# Example 1
<img width="300" height="250" alt="blobid0_1785586075" src="https://github.com/user-attachments/assets/1c815003-16b6-4b56-abdb-91f85f49f1df" />
<img width="300" height="250" alt="blobid1_1785586111" src="https://github.com/user-attachments/assets/8785d2fe-04bb-4c27-91f7-83b2f87f9037" />

### Input

```text
root = [1,2,3,4,5,N,N]
```

Tree:

```text
          1
        /   \
       2     3
      / \
     4   5
```

Level-wise:

```text
Level 0 → 1
Level 1 → 2, 3
Level 2 → 4, 5
```

For the left view, take the **first node at every level**:

```text
1
2
4
```

### Output

```text
[1,2,4]
```

---

# Example 2
<img width="323" height="400" alt="blobid2_1785504482" src="https://github.com/user-attachments/assets/c1d441fa-fcb1-4b88-89db-70fd2cf9bc9e" />
<img width="323" height="400" alt="blobid11_1785504656" src="https://github.com/user-attachments/assets/343da079-0b03-413c-8d2b-0b74fa4c6b07" />

### Input

```text
root = [1,2,3,N,N,4,N,N,5,N,N]
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

The first visible node at every level is:

```text
Level 0 → 1
Level 1 → 2
Level 2 → 4
Level 3 → 5
```

### Output

```text
[1,2,4,5]
```

---

# Main Idea

We use **DFS + Recursion**.

The important idea is:

> Visit the **left subtree first**, then the right subtree.

At every level, the first node we encounter is the node visible from the left.

---

# Why Do We Need `level`?

We need to know which level of the tree we are currently visiting.

For example:

```text
          1          ← level 0
        /   \
       2     3       ← level 1
      / \
     4   5           ← level 2
```

We maintain:

```cpp
int level
```

When we move down:

```cpp
level + 1
```

---

# Important Condition

The most important line is:

```cpp
if(level == ans.size())
```

This means:

> "Have we already stored a node for this level?"

Initially:

```text
ans = []
level = 0
```

Since:

```text
level == ans.size()
0 == 0
```

we store the root.

After storing:

```text
ans = [1]
```

Now:

```text
ans.size() = 1
```

When another node at level `0` is encountered, the condition becomes:

```text
0 == 1
```

which is false.

Therefore, only the **first node at each level** is added.

---

# Why Visit Left First?

We use:

```cpp
solve(root->left, ans, level + 1);
solve(root->right, ans, level + 1);
```

The left child is visited first.

Therefore, at every level:

```text
LEFT → RIGHT
```

The first node encountered is exactly the node we want for the left view.

---

# C++ Solution

```cpp
class Solution {
public:

    void solve(Node* root, vector<int>& ans, int level) {

        if(root == NULL)
            return;

        // First node at this level
        if(level == ans.size()) {
            ans.push_back(root->data);
        }

        // Visit left first
        solve(root->left, ans, level + 1);

        // Then visit right
        solve(root->right, ans, level + 1);
    }

    vector<int> leftView(Node* root) {

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
root = [1,2,3,4,5,N,N]
```

Tree:

```text
          1
        /   \
       2     3
      / \
     4   5
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

Then visit left:

```text
solve(2, ans, 1)
```

---

# Step 2 — Node 2

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

Add `2`:

```text
ans = [1,2]
```

Then visit left:

```text
solve(4, ans, 2)
```

---

# Step 3 — Node 4

Current:

```text
level = 2
ans = [1,2]
```

Check:

```text
2 == 2
```

True.

Add `4`:

```text
ans = [1,2,4]
```

Now:

```text
solve(NULL, ans, 3)
```

returns.

Then:

```text
solve(NULL, ans, 3)
```

returns.

So node `4` is complete.

---

# Step 4 — Back to Node 2

Now visit right child:

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

So we **do not add `5`**.

Why?

Because level `2` already has node `4`.

```text
Level 2 → 4, 5
           ↑
       already selected
```

This is exactly what we want.

---

# Step 5 — Back to Node 1

Now the left subtree is completely processed.

We visit:

```text
solve(3, ans, 1)
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

So `3` is not added.

Why?

Because level `1` already has:

```text
2
```

and `2` is visible from the left.

---

# Final Answer

After completing the recursion:

```text
ans = [1,2,4]
```

Therefore:

```text
Output = [1,2,4]
```

---

# Recursion Flow

The traversal is:

```text
             1
            / \
           2   3
          / \
         4   5
```

DFS order:

```text
1
↓
2
↓
4
↓
5
↓
3
```

But the first node encountered at each level is:

```text
Level 0 → 1
Level 1 → 2
Level 2 → 4
```

Therefore:

```text
Left View = [1,2,4]
```

---

# Visual Understanding

```text
             1  ← Level 0
            / \
           2   3  ← Level 1
          / \
         4   5  ← Level 2
```

From the left:

```text
        👁
         \
          1
          |
          2
          |
          4
```

So:

```text
[1,2,4]
```

---

# Why `level == ans.size()` Works

Suppose we are at level `2`.

Before visiting any node at level `2`:

```text
ans = [1,2]
```

Therefore:

```text
ans.size() = 2
```

The first node we encounter:

```text
level = 2
```

So:

```text
2 == 2
```

True.

We add the node.

Now:

```text
ans = [1,2,4]
```

and:

```text
ans.size() = 3
```

Any other node at level `2` will have:

```text
2 == 3
```

False.

Therefore, it won't be added.

---

# Why Not Use `level <= ans.size()`?

We specifically need:

```cpp
level == ans.size()
```

because we want to add **only the first node at each level**.

Using:

```cpp
level <= ans.size()
```

would allow incorrect insertions.

---

# Why Left Before Right?

Suppose:

```text
        1
       / \
      2   3
```

At level `1`:

```text
2  3
```

The left view needs:

```text
2
```

So we must visit:

```text
2 → 3
```

not:

```text
3 → 2
```

That's why:

```cpp
solve(root->left, ...)
solve(root->right, ...)
```

is important.

---

# What If We Visit Right First?

If we write:

```cpp
solve(root->right, ans, level + 1);
solve(root->left, ans, level + 1);
```

then we would get the **right view** instead.

For:

```text
        1
       / \
      2   3
```

Right-first traversal gives:

```text
[1,3]
```

which is the right view.

---

# Left View vs Right View

### Left View

Visit:

```text
LEFT → RIGHT
```

Take first node at each level.

```text
[1,2,4]
```

### Right View

Visit:

```text
RIGHT → LEFT
```

Take first node at each level.

```text
[1,3,5]
```

The concept is exactly the same.

---

# Recursive Pattern

The complete idea:

```text
                 ROOT
                   |
                Level 0
                   |
          Is this first node?
             /           \
           YES            NO
            ↓              ↓
          Store       Don't Store
                         |
                    Continue DFS
                    /         \
                 LEFT        RIGHT
```

---

# Algorithm

### Step 1

Create an empty answer vector:

```cpp
vector<int> ans;
```

### Step 2

Start DFS:

```cpp
solve(root, ans, 0);
```

### Step 3

If node is `NULL`, return.

### Step 4

If:

```cpp
level == ans.size()
```

add the node.

### Step 5

Visit left subtree first.

### Step 6

Visit right subtree.

### Step 7

Return `ans`.

---

# Complexity Analysis

Every node is visited exactly once.

### Time Complexity

```text
O(N)
```

where `N` is the number of nodes.

### Space Complexity

The recursion stack depends on the height:

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

The output vector itself requires:

```text
O(H)
```

because there can be at most one node per level.

---

# Edge Cases

## 1. Empty Tree

```text
root = NULL
```

The function immediately returns:

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

## 3. Left-Skewed Tree

```text
    1
   /
  2
 /
3
```

Every node is visible.

Output:

```text
[1,2,3]
```

---

## 4. Right-Skewed Tree

```text
1
 \
  2
   \
    3
```

Every node is also visible.

Output:

```text
[1,2,3]
```

---

# Common Mistakes

### ❌ Mistake 1 — Visiting Right First

Wrong for left view:

```cpp
solve(root->right, ans, level + 1);
solve(root->left, ans, level + 1);
```

This produces the right view.

---

### ❌ Mistake 2 — Adding Every Node

If we simply do:

```cpp
ans.push_back(root->data);
```

we get a DFS traversal, not the left view.

We need:

```cpp
if(level == ans.size())
```

---

### ❌ Mistake 3 — Forgetting Level Increment

Correct:

```cpp
solve(root->left, ans, level + 1);
solve(root->right, ans, level + 1);
```

Every child is one level deeper.

---

# Key Concepts

* Binary Tree
* DFS
* Recursion
* Tree Levels
* Left View
* Preorder Traversal
* Level Tracking

---

# Important Observation

The traversal is basically **Preorder DFS**:

```text
ROOT → LEFT → RIGHT
```

But we additionally track:

```text
level
```

and store only the **first node at each level**.

So you can remember:

```text
Left View
     ↓
Preorder DFS
     ↓
Root → Left → Right
     ↓
First node at every level
```

---

# Quick Revision

The most important line:

```cpp
if(level == ans.size()) {
    ans.push_back(root->data);
}
```

And traversal order:

```cpp
solve(root->left, ans, level + 1);
solve(root->right, ans, level + 1);
```

So the complete idea is:

```text
LEFT VIEW
   ↓
DFS
   ↓
LEFT FIRST
   ↓
FIRST NODE AT EACH LEVEL
   ↓
ANSWER
```

---

# Final Code

```cpp
class Solution {
public:

    void solve(Node* root, vector<int>& ans, int level) {

        if(root == NULL)
            return;

        if(level == ans.size()) {
            ans.push_back(root->data);
        }

        solve(root->left, ans, level + 1);

        solve(root->right, ans, level + 1);
    }

    vector<int> leftView(Node* root) {

        vector<int> ans;

        solve(root, ans, 0);

        return ans;
    }
};
```

---

# Summary

| Concept             | Details                          |
| ------------------- | -------------------------------- |
| Problem             | Left View of Binary Tree         |
| Difficulty          | Easy                             |
| Approach            | DFS + Recursion                  |
| Traversal           | Preorder (`Root → Left → Right`) |
| Time                | `O(N)`                           |
| Space               | `O(H)`                           |
| Main Idea           | First node at every level        |
| Level Tracking      | `level`                          |
| Important Condition | `level == ans.size()`            |
| Empty Tree          | `[]`                             |

## 🧠 Remember

For **Left View**:

```text
ROOT → LEFT → RIGHT
```

and:

```cpp
if(level == ans.size())
    ans.push_back(root->data);
```

**First node encountered at every level = Left View.** 🌳
