# 🌳 116. Populating Next Right Pointers in Each Node

## Problem Statement

You are given a **perfect binary tree** where:

* All leaves are at the same level.
* Every parent has exactly two children.
* Each node contains a `next` pointer.

The structure of the node is:

```cpp
struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
};
```

The task is to populate each node's `next` pointer so that it points to the **next node on the same level**.

If there is no node to the right, the `next` pointer should be:

```text
NULL
```

Initially, all `next` pointers are `NULL`.

---

# Example 1
<img width="1058" height="361" alt="116_sample" src="https://github.com/user-attachments/assets/19ee3a03-06db-451c-9373-a8b18463ec54" />

### Input

```text
root = [1,2,3,4,5,6,7]
```

Tree:

```text
              1
            /   \
           2     3
          / \   / \
         4   5 6   7
```

After connecting the `next` pointers:

```text
              1
               \
                NULL

        2  →  3  →  NULL

    4  →  5  →  6  →  7  →  NULL
```

Serialized output:

```text
[1,#,2,3,#,4,5,6,7,#]
```

Here `#` represents the end of a level.

---

# Example 2

### Input

```text
root = []
```

The tree is empty.

Therefore:

```text
Output: []
```

---

# Main Idea

We use **BFS (Breadth First Search)** with a `queue`.

BFS naturally processes a binary tree **level by level**.

For example:

```text
              1
            /   \
           2     3
          / \   / \
         4   5 6   7
```

The queue processes:

```text
Level 0 → 1
Level 1 → 2 3
Level 2 → 4 5 6 7
```

For every level:

* Connect the current node to the next node in the queue.
* The last node of the level points to `NULL`.

---

# Why Do We Need the Queue?

A queue helps us process nodes in **level order**.

Initially:

```text
Queue:
[1]
```

Process `1`.

Add its children:

```text
Queue:
[2,3]
```

Process `2` and `3`.

Then add their children:

```text
Queue:
[4,5,6,7]
```

This gives us exactly the nodes belonging to the next level.

---

# Important Variable — `n`

Inside the while loop:

```cpp
int n = q.size();
```

`n` represents the **number of nodes in the current level**.

For example:

```text
Queue = [4,5,6,7]
```

Then:

```text
n = 4
```

So we process exactly these 4 nodes as one level.

This is very important because while processing them, we add their children to the queue.

Those children belong to the **next level**, not the current level.

---

# How Do We Connect Nodes?

For every node:

```cpp
Node* curr = q.front();
q.pop();
```

If it is not the last node of the current level:

```cpp
if(i < n - 1)
    curr->next = q.front();
```

The next node is currently at the front of the queue.

For the last node:

```cpp
else
    curr->next = NULL;
```

because there is no node to its right.

---

# C++ Solution

```cpp
class Solution {
public:

    Node* connect(Node* root) {

        if(root == NULL)
            return NULL;

        queue<Node*> q;

        q.push(root);

        while(!q.empty()) {

            int n = q.size();

            for(int i = 0; i < n; i++) {

                Node* curr = q.front();
                q.pop();

                // Connect to next node in same level
                if(i < n - 1)
                    curr->next = q.front();
                else
                    curr->next = NULL;

                // Add children for next level
                if(curr->left)
                    q.push(curr->left);

                if(curr->right)
                    q.push(curr->right);
            }
        }

        return root;
    }
};
```

---

# Detailed Dry Run

Consider:

```text
root = [1,2,3,4,5,6,7]
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

## Step 1 — Push Root

Initially:

```text
Queue = []
```

Push root:

```text
Queue = [1]
```

---

# Step 2 — Process Level 0

Queue:

```text
[1]
```

So:

```cpp
n = q.size();
```

gives:

```text
n = 1
```

Start:

```text
i = 0
```

Pop:

```text
curr = 1
```

Queue is now:

```text
[]
```

Since:

```text
i < n - 1
0 < 0
```

is false.

Therefore:

```text
1->next = NULL
```

Add children:

```text
Queue = [2,3]
```

Level 0 completed.

---

# Step 3 — Process Level 1

Queue:

```text
[2,3]
```

Therefore:

```text
n = 2
```

We need to process exactly 2 nodes.

---

## Process Node 2

```text
i = 0
curr = 2
```

Pop `2`.

Queue:

```text
[3]
```

Check:

```text
i < n - 1

0 < 1
```

True.

Therefore:

```text
2->next = q.front()
```

The front is:

```text
3
```

So:

```text
2 → 3
```

Now add children of `2`:

```text
Queue = [3,4,5]
```

---

## Process Node 3

```text
i = 1
curr = 3
```

Pop `3`.

Queue:

```text
[4,5]
```

Check:

```text
1 < 1
```

False.

Therefore:

```text
3->next = NULL
```

Add children:

```text
Queue = [4,5,6,7]
```

Level 1 completed.

Connections:

```text
2 → 3 → NULL
```

---

# Step 4 — Process Level 2

Queue:

```text
[4,5,6,7]
```

Therefore:

```text
n = 4
```

We process:

```text
i = 0
i = 1
i = 2
i = 3
```

---

## Process Node 4

```text
i = 0
curr = 4
```

Queue after pop:

```text
[5,6,7]
```

Since:

```text
0 < 3
```

true.

Therefore:

```text
4->next = 5
```

Connection:

```text
4 → 5
```

---

## Process Node 5

```text
i = 1
curr = 5
```

Queue:

```text
[6,7]
```

Since:

```text
1 < 3
```

true.

Therefore:

```text
5->next = 6
```

Connection:

```text
5 → 6
```

---

## Process Node 6

```text
i = 2
curr = 6
```

Queue:

```text
[7]
```

Since:

```text
2 < 3
```

true.

Therefore:

```text
6->next = 7
```

Connection:

```text
6 → 7
```

---

## Process Node 7

```text
i = 3
curr = 7
```

Queue:

```text
[]
```

Since:

```text
3 < 3
```

false.

Therefore:

```text
7->next = NULL
```

Final level:

```text
4 → 5 → 6 → 7 → NULL
```

---

# Final Tree

After completing BFS:

```text
              1
              ↓
            NULL

        2  →  3
        ↓       ↓
      NULL     NULL

    4 → 5 → 6 → 7
                    ↓
                  NULL
```

Or more clearly:

```text
Level 0:

1 → NULL


Level 1:

2 → 3 → NULL


Level 2:

4 → 5 → 6 → 7 → NULL
```

---

# Queue Visualization

The entire execution:

```text
Start:

[1]


After Level 0:

[2,3]


After Level 1:

[4,5,6,7]


After Level 2:

[]
```

Connections:

```text
1 → NULL

2 → 3 → NULL

4 → 5 → 6 → 7 → NULL
```

---

# Why `q.front()`?

Suppose:

```text
Queue = [3,4,5]
```

We process node `2`.

After removing `2`:

```text
Queue = [3,4,5]
```

The node immediately to the right of `2` is `3`.

Therefore:

```cpp
curr->next = q.front();
```

sets:

```text
2 → 3
```

---

# Why Last Node Gets NULL?

Suppose the current level is:

```text
4 5 6 7
```

For node `7`, there is no node after it on the same level.

Therefore:

```cpp
7->next = NULL;
```

We identify the last node using:

```cpp
if(i < n - 1)
```

If this condition is false:

```text
i == n - 1
```

the node is the last node of that level.

---

# Algorithm

### Step 1

If the tree is empty, return `NULL`.

### Step 2

Create a queue:

```cpp
queue<Node*> q;
```

### Step 3

Push the root:

```cpp
q.push(root);
```

### Step 4

While the queue is not empty:

```cpp
while(!q.empty())
```

### Step 5

Store the current level size:

```cpp
int n = q.size();
```

### Step 6

Process all `n` nodes.

### Step 7

For each node:

* If it isn't the last node → connect to `q.front()`.
* If it is the last node → connect to `NULL`.

### Step 8

Push left and right children into the queue.

### Step 9

Return the root.

---

# Why This Works

The queue always maintains nodes in **level order**.

For example:

```text
Queue:

Current Level
     ↓
[2,3,4,5,6]
```

When we process `2`, the next node is `3`.

When we process `3`, the next node is `4`.

But we don't want `3 → 4` because `4` belongs to the next level.

That's why we use:

```cpp
int n = q.size();
```

and only connect nodes within those `n` nodes.

---

# Important Concept

The key idea is:

```text
Queue → Level Order
```

and:

```text
n = Number of nodes in current level
```

Then:

```text
Current node
      ↓
Is it last in this level?
      |
   ┌──┴──┐
  YES    NO
   ↓      ↓
 NULL   q.front()
```

---

# Difference Between BFS and This Problem

Normal BFS:

```text
Process nodes level by level.
```

This problem:

```text
Process nodes level by level
+
Connect adjacent nodes.
```

So this is basically:

```text
BFS + next pointer connection
```

---

# Complexity Analysis

Every node is processed exactly once.

### Time Complexity

```text
O(N)
```

where `N` is the number of nodes.

### Space Complexity

The queue can contain nodes from one or more levels.

For a perfect binary tree, the maximum queue size is approximately the number of nodes in the last level:

```text
O(N)
```

Therefore:

```text
Time  = O(N)
Space = O(N)
```

---

# Edge Cases

## 1. Empty Tree

```text
root = []
```

Immediately:

```cpp
if(root == NULL)
    return NULL;
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

There is no node to its right.

Therefore:

```text
1 → NULL
```

---

## 3. Two-Level Tree

```text
      1
     / \
    2   3
```

Output connections:

```text
1 → NULL

2 → 3 → NULL
```

---

# Common Mistakes

### ❌ Mistake 1 — Connecting Across Levels

Wrong:

```text
2 → 3 → 4
```

`4` belongs to the next level.

Correct:

```text
2 → 3 → NULL

4 → 5 → 6 → 7 → NULL
```

Using `n = q.size()` prevents this.

---

### ❌ Mistake 2 — Forgetting the Last Node

The last node must point to:

```text
NULL
```

That's why we use:

```cpp
if(i < n - 1)
    curr->next = q.front();
else
    curr->next = NULL;
```

---

### ❌ Mistake 3 — Adding Children Before Connecting

The clean order is:

```text
1. Pop current node
2. Set next pointer
3. Push children
```

This keeps the current level separate from the next level.

---

# Key Concepts

* Binary Tree
* Perfect Binary Tree
* BFS
* Queue
* Level Order Traversal
* `next` Pointer
* Level Size
* `q.front()`

---

# Quick Revision

Remember:

```text
BFS
 ↓
Take level size
 ↓
Process exactly that many nodes
 ↓
Current node → q.front()
 ↓
Last node → NULL
 ↓
Push children
```

The most important code:

```cpp
int n = q.size();

for(int i = 0; i < n; i++) {

    Node* curr = q.front();
    q.pop();

    if(i < n - 1)
        curr->next = q.front();
    else
        curr->next = NULL;

    if(curr->left)
        q.push(curr->left);

    if(curr->right)
        q.push(curr->right);
}
```

---

# Final Code

```cpp
class Solution {
public:

    Node* connect(Node* root) {

        if(root == NULL)
            return NULL;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {

            int n = q.size();

            for(int i = 0; i < n; i++) {

                Node* curr = q.front();
                q.pop();

                if(i < n - 1)
                    curr->next = q.front();
                else
                    curr->next = NULL;

                if(curr->left)
                    q.push(curr->left);

                if(curr->right)
                    q.push(curr->right);
            }
        }

        return root;
    }
};
```

---

# Summary

| Concept            | Details                        |
| ------------------ | ------------------------------ |
| Problem            | Populating Next Right Pointers |
| LeetCode           | 116                            |
| Difficulty         | Medium                         |
| Tree Type          | Perfect Binary Tree            |
| Approach           | BFS + Queue                    |
| Traversal          | Level Order                    |
| Time               | `O(N)`                         |
| Space              | `O(N)`                         |
| Same Level         | Connect using `q.front()`      |
| Last Node          | `next = NULL`                  |
| Important Variable | `n = q.size()`                 |

## 🧠 Remember

This problem is basically:

```text
LEVEL ORDER TRAVERSAL
        +
CONNECT ADJACENT NODES
```

For every level:

```text
1 → NULL

2 → 3 → NULL

4 → 5 → 6 → 7 → NULL
```

**BFS gives you the level, and `q.front()` gives you the next node.** 🌳
