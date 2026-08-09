# 🌳 102. Binary Tree Level Order Traversal

## Problem Statement

Given the `root` of a binary tree, return the **level order traversal** of its nodes' values.

Level order traversal means:

> Visit the tree **level by level**, from **left to right**.

This traversal is also known as **Breadth First Search (BFS)**.

---

# Example 1
<img width="277" height="302" alt="tree1" src="https://github.com/user-attachments/assets/a4b885b2-a30b-4187-962d-7bcbb29624c0" />

### Input

```text
root = [3,9,20,null,null,15,7]
```

Tree:

```text
          3
        /   \
       9     20
            /  \
           15   7
```

Level by level:

```text
Level 0 → [3]
Level 1 → [9,20]
Level 2 → [15,7]
```

### Output

```text
[[3],[9,20],[15,7]]
```

---

# Example 2

### Input

```text
root = [1]
```

Tree:

```text
    1
```

There is only one level.

### Output

```text
[[1]]
```

---

# Example 3

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

# What is Level Order Traversal?

Consider this binary tree:

```text
              1
            /   \
           2     3
          / \   / \
         4   5 6   7
```

Level order traversal visits:

```text
Level 0 → 1

Level 1 → 2 3

Level 2 → 4 5 6 7
```

Therefore:

```text
[[1],[2,3],[4,5,6,7]]
```

The important point is:

> We process all nodes of one level before moving to the next level.

---

# Main Approach

We use **BFS (Breadth First Search)** with a `queue`.

A queue follows:

```text
FIFO
First In → First Out
```

For a binary tree:

```text
Root
 ↓
Children
 ↓
Grandchildren
 ↓
Next Level
```

This naturally gives us level order traversal.

---

# Why Do We Need `n = q.size()`?

This is the most important part:

```cpp
int n = q.size();
```

`n` tells us how many nodes belong to the **current level**.

For example:

```text
        1
       / \
      2   3
     / \
    4   5
```

Initially:

```text
Queue = [1]
```

So:

```text
n = 1
```

After processing `1`:

```text
Queue = [2,3]
```

Now:

```text
n = 2
```

We process exactly `2` nodes:

```text
2
3
```

While processing them, their children are added to the queue:

```text
Queue = [4,5]
```

But `4` and `5` belong to the **next level**.

That's why we store the original queue size before processing the level.

---

# Why Use a Separate `level` Vector?

We want the result in this format:

```text
[
    [3],
    [9,20],
    [15,7]
]
```

So for every level, we create:

```cpp
vector<int> level;
```

Then add each node's value:

```cpp
level.push_back(curr->val);
```

After processing the complete level:

```cpp
ans.push_back(level);
```

---

# C++ Solution

```cpp
class Solution {
public:

    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if(root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            int n = q.size();

            vector<int> level;

            for(int i = 0; i < n; i++) {

                TreeNode* curr = q.front();
                q.pop();

                level.push_back(curr->val);

                if(curr->left)
                    q.push(curr->left);

                if(curr->right)
                    q.push(curr->right);
            }

            ans.push_back(level);
        }

        return ans;
    }
};
```

---

# Detailed Dry Run

Let's use:

```text
root = [3,9,20,null,null,15,7]
```

Tree:

```text
          3
        /   \
       9     20
            /  \
           15   7
```

---

## Step 1 — Push Root

Initially:

```text
Queue = []
```

Push root:

```text
Queue = [3]
```

Answer:

```text
ans = []
```

---

# Step 2 — Process Level 0

Queue:

```text
[3]
```

Therefore:

```text
n = 1
```

Create:

```text
level = []
```

Process node `3`.

Pop:

```text
Queue = []
```

Add value:

```text
level = [3]
```

Add children:

```text
Queue = [9,20]
```

Level completed.

Add:

```text
ans = [[3]]
```

---

# Step 3 — Process Level 1

Queue:

```text
[9,20]
```

Therefore:

```text
n = 2
```

Create:

```text
level = []
```

---

## Process Node 9

Pop `9`.

```text
Queue = [20]
```

Add:

```text
level = [9]
```

Node `9` has no children.

---

## Process Node 20

Pop `20`.

```text
Queue = []
```

Add:

```text
level = [9,20]
```

Add children:

```text
Queue = [15,7]
```

Level completed.

Add:

```text
ans = [[3],[9,20]]
```

---

# Step 4 — Process Level 2

Queue:

```text
[15,7]
```

Therefore:

```text
n = 2
```

Create:

```text
level = []
```

---

## Process Node 15

Pop:

```text
Queue = [7]
```

Add:

```text
level = [15]
```

No children.

---

## Process Node 7

Pop:

```text
Queue = []
```

Add:

```text
level = [15,7]
```

No children.

Level completed.

Add:

```text
ans = [[3],[9,20],[15,7]]
```

---

# Final Result

The queue is now empty:

```text
Queue = []
```

So the loop stops.

Final answer:

```text
[[3],[9,20],[15,7]]
```

---

# Queue Visualization

The entire process:

```text
Start:

[3]


After Level 0:

[9,20]


After Level 1:

[15,7]


After Level 2:

[]
```

And the result:

```text
Level 0 → [3]
Level 1 → [9,20]
Level 2 → [15,7]
```

---

# Why Queue?

A queue follows:

```text
FIFO
```

For example:

```text
Queue:
[9,20]

Remove 9 first
→ 20 remains

Remove 20
→ Queue empty
```

This guarantees nodes are processed from left to right.

When we push:

```cpp
q.push(curr->left);
q.push(curr->right);
```

the left child enters before the right child.

Therefore:

```text
LEFT → RIGHT
```

---

# Algorithm

### Step 1

Create an empty answer:

```cpp
vector<vector<int>> ans;
```

### Step 2

If root is `NULL`, return empty answer.

### Step 3

Create a queue:

```cpp
queue<TreeNode*> q;
```

### Step 4

Push the root:

```cpp
q.push(root);
```

### Step 5

While the queue is not empty:

```cpp
while(!q.empty())
```

### Step 6

Store current level size:

```cpp
int n = q.size();
```

### Step 7

Create a vector for the current level:

```cpp
vector<int> level;
```

### Step 8

Process exactly `n` nodes.

For each node:

```text
Remove from queue
      ↓
Store value
      ↓
Push left child
      ↓
Push right child
```

### Step 9

Add the completed level:

```cpp
ans.push_back(level);
```

### Step 10

Return `ans`.

---

# Important Pattern

This is a very common BFS pattern for binary trees:

```cpp
while(!q.empty()) {

    int n = q.size();

    vector<int> level;

    for(int i = 0; i < n; i++) {

        TreeNode* curr = q.front();
        q.pop();

        level.push_back(curr->val);

        if(curr->left)
            q.push(curr->left);

        if(curr->right)
            q.push(curr->right);
    }

    ans.push_back(level);
}
```

You will use this pattern in many tree problems.

---

# Difference Between BFS and DFS

### BFS

Uses:

```text
Queue
```

Traversal:

```text
Level 0
   ↓
Level 1
   ↓
Level 2
```

Example:

```text
[1]
[2,3]
[4,5,6,7]
```

---

### DFS

Usually uses:

```text
Recursion / Stack
```

For example, preorder:

```text
Root → Left → Right
```

Example:

```text
1 → 2 → 4 → 5 → 3 → 6 → 7
```

---

# Level Order = BFS

Whenever you see:

> "level by level"

Think:

```text
BFS + Queue
```

For example:

* Level Order Traversal
* Right Side View
* Left View
* Average of Levels
* Minimum Depth
* Zigzag Level Order

Many of these can be solved using the same BFS structure.

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

Because:

```cpp
if(root == NULL)
    return ans;
```

---

## 2. Single Node

```text
    1
```

Output:

```text
[[1]]
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

Output:

```text
[[1],[2],[3]]
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

Output:

```text
[[1],[2],[3]]
```

---

## 5. Complete Binary Tree

```text
        1
       / \
      2   3
     / \ / \
    4  5 6  7
```

Output:

```text
[[1],[2,3],[4,5,6,7]]
```

---

# Common Mistakes

### ❌ Mistake 1 — Not Storing `q.size()`

Wrong:

```cpp
for(int i = 0; i < q.size(); i++)
```

This is dangerous because the queue size changes while you push children.

Instead:

```cpp
int n = q.size();

for(int i = 0; i < n; i++)
```

---

### ❌ Mistake 2 — Forgetting to Create a New Level

Each level needs its own vector:

```cpp
vector<int> level;
```

It should be created **inside** the `while` loop.

---

### ❌ Mistake 3 — Adding Level Before Processing

Correct order:

```text
Process nodes
    ↓
Complete level
    ↓
Push level into answer
```

```cpp
ans.push_back(level);
```

comes after the `for` loop.

---

### ❌ Mistake 4 — Forgetting Children

After processing a node:

```cpp
if(curr->left)
    q.push(curr->left);

if(curr->right)
    q.push(curr->right);
```

This adds nodes for the next level.

---

# Complexity Analysis

Every node is visited exactly once.

### Time Complexity

```text
O(N)
```

where `N` is the number of nodes.

### Space Complexity

The queue can contain nodes from a level:

```text
O(N)
```

The answer also contains every node:

```text
O(N)
```

Therefore overall auxiliary space is:

```text
O(N)
```

---

# Key Concepts

* Binary Tree
* BFS
* Queue
* Level Order Traversal
* Level Size
* Nested Vectors
* FIFO
* Tree Levels

---

# Quick Revision

Whenever you see:

> **Level by level**

Think:

```text
BFS
 ↓
Queue
 ↓
q.size()
 ↓
Process current level
 ↓
Push children
 ↓
Store level
```

The core pattern:

```cpp
while(!q.empty()) {

    int n = q.size();

    vector<int> level;

    for(int i = 0; i < n; i++) {

        TreeNode* curr = q.front();
        q.pop();

        level.push_back(curr->val);

        if(curr->left)
            q.push(curr->left);

        if(curr->right)
            q.push(curr->right);
    }

    ans.push_back(level);
}
```

---

# Final Code

```cpp
class Solution {
public:

    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if(root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            int n = q.size();

            vector<int> level;

            for(int i = 0; i < n; i++) {

                TreeNode* curr = q.front();
                q.pop();

                level.push_back(curr->val);

                if(curr->left)
                    q.push(curr->left);

                if(curr->right)
                    q.push(curr->right);
            }

            ans.push_back(level);
        }

        return ans;
    }
};
```

---

# Summary

| Concept        | Details                           |
| -------------- | --------------------------------- |
| Problem        | Binary Tree Level Order Traversal |
| LeetCode       | 102                               |
| Difficulty     | Medium                            |
| Approach       | BFS                               |
| Data Structure | Queue                             |
| Traversal      | Level by Level                    |
| Direction      | Left → Right                      |
| Time           | `O(N)`                            |
| Space          | `O(N)`                            |
| Current Level  | `q.size()`                        |
| Result         | `vector<vector<int>>`             |

## 🧠 Remember

**Level Order Traversal = BFS + Queue.**

The key trick is:

```cpp
int n = q.size();
```

This freezes the number of nodes belonging to the **current level**, allowing you to process one complete level at a time.

```text
        1
       / \
      2   3
     / \ / \
    4  5 6  7

       ↓ BFS

    [1]
    [2,3]
    [4,5,6,7]
```

🌳 **One level at a time — left to right.**
