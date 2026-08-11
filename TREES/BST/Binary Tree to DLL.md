# 🌳 Binary Tree to Doubly Linked List (DLL)

## Problem Statement

Given the **root of a binary tree**, convert the binary tree into a **Doubly Linked List (DLL)** in place using the same `Node` structure.

The DLL must follow the **inorder traversal** of the binary tree:

```text
Left → Root → Right
```

The existing pointers are reused:

- `left` → `prev`
- `right` → `next`
- The leftmost node becomes the head of the DLL.

Return the **head of the resulting DLL**.

---

# 🧪 Examples

## Example 1
<img width="212" height="210" alt="blobid3_1768475771" src="https://github.com/user-attachments/assets/724a563c-19c8-48cf-a33a-4a2b14620ea4" />

### Input

```text
root = [1, 2, 3]
```

Tree:

```text
        1
       / \
      2   3
```

### Output

Forward traversal:

```text
2 1 3
```

Backward traversal:

```text
3 1 2
```

### Explanation

Inorder traversal visits:

```text
2 → 1 → 3
```

Therefore, node `2` becomes the head.

```text
NULL ← 2 ⇄ 1 ⇄ 3 → NULL
```

---

## Example 2
<img width="338" height="267" alt="blobid2_1763203489" src="https://github.com/user-attachments/assets/b56551fa-6e89-40eb-be54-e62de34cfe7a" />

### Input

```text
root = [10, 20, 30, 40, 60]
```

Tree:

```text
          10
         /  \
       20    30
      /  \
    40    60
```

### Output

Forward traversal:

```text
40 20 60 10 30
```

Backward traversal:

```text
30 10 60 20 40
```

### Explanation

Inorder traversal visits:

```text
40 → 20 → 60 → 10 → 30
```

Node `40` becomes the head.

```text
NULL ← 40 ⇄ 20 ⇄ 60 ⇄ 10 ⇄ 30 → NULL
```

---

# 💡 Approach

The provided solution uses **recursive inorder traversal** with two pointers:

```cpp
Node* &head
Node* &prev
```

The main idea is:

1. Perform inorder traversal.
2. The first visited node becomes `head`.
3. `prev` stores the previously visited node.
4. Connect `prev->right` to the current node.
5. Connect `current->left` to `prev`.
6. Move `prev` to the current node.
7. Continue the traversal.
8. After traversal, set the last node's `right` to `NULL`.
9. Return `head`.

The key observation is that **inorder traversal already gives the exact order required for the DLL**.

---

# 🧠 Algorithm

1. If `root == NULL`, return.
2. Recursively traverse the left subtree.
3. Process the current node:
   - If `prev == NULL`, set `head = root`.
   - Otherwise connect:
     ```cpp
     prev->right = root;
     root->left = prev;
     ```
4. Set:
   ```cpp
   prev = root;
   ```
5. Recursively traverse the right subtree.
6. After the complete traversal, set the last node's `right` pointer to `NULL`.
7. Return `head`.

---

# 🌳 Recursion / Tree Explanation

The traversal follows:

```text
                    inorder(root)
                         |
                ┌────────┴────────┐
                ↓                 ↓
          inorder(left)     inorder(right)
                |
          Process root
```

The actual order is:

```text
Left → Root → Right
```

For every visited node, the DLL is extended by connecting it with `prev`.

### Base Case

```cpp
if(root == NULL) {
    return;
}
```

### Recursive Case

```cpp
inorder(root->left, head, prev);

// Process current node

inorder(root->right, head, prev);
```

---

# 🔄 How `head` and `prev` Work

### `head`

Stores the first node of the DLL.

```cpp
if(prev == NULL) {
    head = root;
}
```

Since the first node visited in inorder traversal is the leftmost node, it becomes the head.

### `prev`

Stores the previously visited node.

For every new node:

```cpp
prev->right = root;
root->left = prev;
```

Then:

```cpp
prev = root;
```

So the DLL is built one connection at a time.

---

# 🔍 Detailed Dry Run

For:

```text
root = [10, 20, 30, 40, 60]
```

Tree:

```text
          10
         /  \
       20    30
      /  \
    40    60
```

Inorder:

```text
40 → 20 → 60 → 10 → 30
```

### Step 1 — Visit `40`

Initially:

```text
head = NULL
prev = NULL
```

`40` is the first node.

```text
head = 40
prev = 40
```

DLL:

```text
NULL ← 40
```

### Step 2 — Visit `20`

Connect:

```text
40 ⇄ 20
```

Then:

```text
prev = 20
```

### Step 3 — Visit `60`

Connect:

```text
20 ⇄ 60
```

Then:

```text
prev = 60
```

### Step 4 — Visit `10`

Connect:

```text
60 ⇄ 10
```

Then:

```text
prev = 10
```

### Step 5 — Visit `30`

Connect:

```text
10 ⇄ 30
```

Then:

```text
prev = 30
```

Finally:

```cpp
prev->right = NULL;
```

Final DLL:

```text
NULL ← 40 ⇄ 20 ⇄ 60 ⇄ 10 ⇄ 30 → NULL
```

---

# 📊 Dry Run Table

| Step | Current | Previous Before | Action | Head | Previous After |
|------|---------|------------------|--------|------|----------------|
| 1 | `40` | `NULL` | Set head | `40` | `40` |
| 2 | `20` | `40` | `40 ⇄ 20` | `40` | `20` |
| 3 | `60` | `20` | `20 ⇄ 60` | `40` | `60` |
| 4 | `10` | `60` | `60 ⇄ 10` | `40` | `10` |
| 5 | `30` | `10` | `10 ⇄ 30` | `40` | `30` |
| End | — | `30` | `30->right = NULL` | `40` | `30` |

---

# 💻 My C++ Solution

Your provided solution is **correct** and follows the required inorder + previous-pointer approach.

```cpp
/* Structure for tree and linked list
class Node {
  public:
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};*/

class Solution {
public:

    void inorder(Node* root, Node* &head, Node* &prev) {

        if(root == NULL) {
            return;
        }

        inorder(root->left, head, prev);

        if(prev == NULL) {
            head = root;
        }
        else {
            prev->right = root;
            root->left = prev;
        }

        prev = root;

        inorder(root->right, head, prev);
    }

    Node* treeToDLL(Node* root) {

        Node* head = NULL;
        Node* prev = NULL;

        inorder(root, head, prev);

        if(prev) {
            prev->right = NULL;
        }

        return head;
    }
};
```

---

# 🔎 Code Explanation

## 1. `inorder()` Function

```cpp
void inorder(Node* root, Node* &head, Node* &prev)
```

This function performs inorder traversal and simultaneously builds the DLL.

`head` and `prev` are passed by reference so their updated values remain available across recursive calls.

---

## 2. Base Case

```cpp
if(root == NULL) {
    return;
}
```

If there is no node, stop recursion.

---

## 3. Traverse Left Subtree

```cpp
inorder(root->left, head, prev);
```

This ensures the nodes are processed in inorder order.

---

## 4. Set the Head

```cpp
if(prev == NULL) {
    head = root;
}
```

The first node visited is the leftmost node, so it becomes the DLL head.

---

## 5. Connect Two Nodes

```cpp
prev->right = root;
root->left = prev;
```

This converts:

```text
prev → root
```

into a two-way DLL connection:

```text
prev ⇄ root
```

---

## 6. Update `prev`

```cpp
prev = root;
```

The current node becomes the previous node for the next inorder node.

---

## 7. Traverse Right Subtree

```cpp
inorder(root->right, head, prev);
```

Continue the inorder traversal.

---

## 8. Terminate the DLL

After traversal:

```cpp
if(prev) {
    prev->right = NULL;
}
```

`prev` points to the last node, so its `right` pointer must be `NULL`.

---

# 🧩 Pointer Conversion

The same tree node is reused.

```text
Binary Tree              DLL

left   ───────────────→  prev
right  ───────────────→  next
```

Therefore:

```text
Tree Node:
    left
    right

DLL Node:
    prev
    next
```

No new nodes are created.

---

# 📐 Visual Representation

For:

```text
        1
       / \
      2   3
```

Inorder:

```text
2 → 1 → 3
```

DLL:

```text
NULL ← 2 ⇄ 1 ⇄ 3 → NULL
        ↑
       HEAD
```

---

# 🧠 Why Does This Approach Work?

The problem requires the DLL to follow inorder traversal.

Inorder traversal is:

```text
Left → Root → Right
```

The algorithm visits every node in exactly this order.

For each visited node, it connects the current node to the previously visited node:

```cpp
prev->right = root;
root->left = prev;
```

Therefore, the final DLL has exactly the same ordering as the inorder traversal.

The first visited node becomes the head, and the last node's `right` pointer is set to `NULL`.

---

# ⏱️ Complexity Analysis

Let `n` be the number of nodes and `h` be the height of the tree.

## Time Complexity

Every node is visited exactly once.

```text
Time Complexity: O(n)
```

## Space Complexity

No additional nodes or data structures are created.

However, recursion uses stack space:

```text
Space Complexity: O(h)
```

For a balanced tree:

```text
O(log n)
```

For a skewed tree:

```text
O(n)
```

---

# ⚠️ Edge Cases

### 1. Empty Tree

```text
root = []
```

Output:

```text
[]
```

### 2. Single Node

```text
    5
```

DLL:

```text
NULL ← 5 → NULL
```

### 3. Left-Skewed Tree

```text
        4
       /
      3
     /
    2
   /
  1
```

Inorder:

```text
1 2 3 4
```

DLL:

```text
NULL ← 1 ⇄ 2 ⇄ 3 ⇄ 4 → NULL
```

### 4. Right-Skewed Tree

```text
1
   2
       3
           4
```

Inorder:

```text
1 2 3 4
```

DLL:

```text
NULL ← 1 ⇄ 2 ⇄ 3 ⇄ 4 → NULL
```

---

# 🧪 Additional Test Cases

## Test Case 1 — Empty Tree

```text
Input:
root = []

Output:
[]
```

## Test Case 2 — Single Node

```text
Input:
root = [10]

Forward:
10

Backward:
10
```

## Test Case 3 — Left-Skewed Tree

```text
Input:
root = [4,3,null,2,null,1]

Inorder:
1 2 3 4

Forward DLL:
1 2 3 4

Backward DLL:
4 3 2 1
```

## Test Case 4 — Right-Skewed Tree

```text
Input:
root = [1,null,2,null,3,null,4]

Inorder:
1 2 3 4

Forward DLL:
1 2 3 4

Backward DLL:
4 3 2 1
```

## Test Case 5 — Complete Binary Tree

```text
Input:
root = [1,2,3,4,5,6,7]

Inorder:
4 2 5 1 6 3 7

Forward DLL:
4 2 5 1 6 3 7

Backward DLL:
7 3 6 1 5 2 4
```

---

# 📌 Key Concepts

### Inorder Traversal

```text
Left → Root → Right
```

### Doubly Linked List

```text
prev ⇄ current ⇄ next
```

### In-Place Conversion

The existing tree nodes and pointers are reused.

### Previous Pointer

`prev` stores the previously visited inorder node.

### Head Pointer

`head` stores the first node of the DLL.

### Pass by Reference

```cpp
Node* &head
Node* &prev
```

allows recursive calls to update the same pointer variables.

---

# 🎯 Important Takeaways

- Inorder traversal determines the DLL order.
- The first inorder node becomes the head.
- `left` acts as `prev`.
- `right` acts as `next`.
- `prev` connects the previous and current nodes.
- No new nodes are created.
- The conversion is performed in place.
- The last node's `right` must be `NULL`.
- Every node is visited exactly once.
- Time complexity is `O(n)`.
- Recursive space complexity is `O(h)`.

---

# 🚨 Common Mistakes

### Mistake 1: Using the Wrong Traversal

The required order is:

```text
Left → Root → Right
```

not preorder or postorder.

### Mistake 2: Forgetting the Head

The first visited node must be assigned:

```cpp
head = root;
```

### Mistake 3: Connecting Only One Direction

Both connections are required:

```cpp
prev->right = root;
root->left = prev;
```

### Mistake 4: Forgetting the Last `NULL`

After traversal:

```cpp
prev->right = NULL;
```

### Mistake 5: Creating New Nodes

The problem specifically asks for an **in-place** conversion.

---

# 🏆 Interview Notes

### Core Idea

Perform inorder traversal and connect each visited node with the previous visited node.

### What becomes the head?

The first node visited in inorder traversal.

### How are pointers reused?

```text
left  → prev
right → next
```

### Why is `prev` required?

It lets us connect the current node with the node visited immediately before it.

### Are new nodes created?

No. The existing tree nodes are reused.

### Time Complexity

```text
O(n)
```

### Space Complexity

```text
O(h)
```

where `h` is the height of the tree.

---

# 📚 Related DSA Topics

- Binary Tree
- Doubly Linked List
- Inorder Traversal
- Recursion
- Tree Traversal
- In-Place Algorithms
- Pointers
- Pass by Reference
- Linked List Manipulation

---

# 🔗 Conclusion

Converting a Binary Tree into a Doubly Linked List is straightforward when we use **inorder traversal**.

The solution maintains two important pointers:

```text
head → first node of the DLL
prev → previously visited node
```

For each visited node, the two-way connection is created using:

```cpp
prev->right = root;
root->left = prev;
```

Because the existing `left` and `right` pointers are reused, the conversion happens **in place** without creating new nodes.

The final structure is:

```text
NULL ← HEAD ⇄ Node ⇄ Node ⇄ ... ⇄ Tail → NULL
```

with:

```text
Time Complexity  : O(n)
Space Complexity : O(h)
```

This is a clean and standard solution for the **Binary Tree to DLL** problem.

---

# ⭐ Quick Revision

```text
              Binary Tree
                   |
            Inorder Traversal
                   |
            Left → Root → Right
                   |
                   ↓
          Doubly Linked List
                   |
       left = prev | right = next
                   |
                   ↓
        NULL ← Head ⇄ ... ⇄ Tail → NULL
```

### Core Logic

```cpp
if(prev == NULL) {
    head = root;
}
else {
    prev->right = root;
    root->left = prev;
}

prev = root;
```

### Final Step

```cpp
if(prev) {
    prev->right = NULL;
}
```

### Final Complexity

```text
Time  : O(n)
Space : O(h)
```
