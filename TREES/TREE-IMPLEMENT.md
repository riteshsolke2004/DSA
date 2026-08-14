# 🌳 Binary Tree Traversals in C++

## 📖 Problem Statement

Implement a binary tree and perform the following three Depth-First Search traversals:

1. **Preorder Traversal** — `Node → Left → Right`
2. **Inorder Traversal** — `Left → Node → Right`
3. **Postorder Traversal** — `Left → Right → Node`

The tree is built recursively from user input, where `-1` represents a `NULL` node.

--- 

# 🧪 Example

### Input

```text
1 2 4 -1 -1 5 -1 -1 3 -1 -1
```

### Constructed Tree

```text
          1
        /   \
       2     3
      / \
     4   5
```

### Output

```text
Preorder:
1 2 4 5 3

Inorder:
4 2 5 1 3

Postorder:
4 5 2 3 1
```

---

# 🌲 Traversal Techniques

| Traversal | Technique | Order |
|---|---|---|
| Preorder | `NLR` | Node → Left → Right |
| Inorder | `LNR` | Left → Node → Right |
| Postorder | `LRN` | Left → Right → Node |

---

# 🏗️ Approach

## 1. Build the Tree

The `buildtree()` function:

1. Takes a value as input.
2. Returns `NULL` if the value is `-1`.
3. Creates a new node otherwise.
4. Recursively builds the left subtree.
5. Recursively builds the right subtree.

```text
Input Value
    |
    v
Is value -1?
   / \
 Yes  No
  |    |
NULL  Create Node
         |
      /     \
   Left     Right
```

## 2. Preorder Traversal

```text
Node → Left → Right
```

## 3. Inorder Traversal

```text
Left → Node → Right
```

## 4. Postorder Traversal

```text
Left → Right → Node
```

---

# 🔍 Dry Run

For:

```text
          1
        /   \
       2     3
      / \
     4   5
```

### Preorder

```text
1 → 2 → 4 → 5 → 3
```

### Inorder

```text
4 → 2 → 5 → 1 → 3
```

### Postorder

```text
4 → 5 → 2 → 3 → 1
```

---

# 💻 Complete C++ Code

```cpp
#include <iostream>
using namespace std;

class Node {
public:

    int data;
    Node* left;
    Node* right;

    Node(int value) {

        data = value;
        left = NULL;
        right = NULL;
    }
};

Node* buildtree() {
    int val;

    cout << "Enter value (-1 for NULL): ";
    cin >> val;

    if(val == -1) return NULL;

    Node* root = new Node(val);

    cout << "Enter left of " << val << endl;
    root->left = buildtree();

    cout << "Enter right of " << val << endl;
    root->right = buildtree();

    return root;
}

void preOrder(Node* root) {

    // NLR TECHNIQUE
    // N = print Node
    // L = move on Left side
    // R = move on right side

    if(root == NULL) {
        return;
    }

    cout << root->data << " ";

    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root) {

    // LNR TECHNIQUE

    if(root == NULL) {
        return;
    }

    inOrder(root->left);

    cout << root->data << " ";

    inOrder(root->right);
}

void postOrder(Node* root) {

    // LRN TECHNIQUE

    if(root == NULL) {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);

    cout << root->data << " ";
}

int main()
{
    cout << "------------*****Tree Implementation*****-------------";
    cout << endl;

    Node* root = buildtree();

    cout << "preOrder printing :- ";
    cout << endl;
    preOrder(root);

    cout << endl;

    cout << "inOrder printing :- ";
    cout << endl;
    inOrder(root);

    cout << endl;

    cout << "postOrder printing :- ";
    cout << endl;
    postOrder(root);

    return 0;
}
```

---

# ▶️ Sample Input

```text
1
2
4
-1
-1
5
-1
-1
3
-1
-1
```

This creates:

```text
          1
        /   \
       2     3
      / \
     4   5
```

---

# 🖥️ Expected Output

```text
------------*****Tree Implementation*****-------------
preOrder printing :-
1 2 4 5 3

inOrder printing :-
4 2 5 1 3

postOrder printing :-
4 5 2 3 1
```

---

# ⏱️ Complexity Analysis

Let:

- `n` = number of nodes
- `h` = height of the tree

## Time Complexity

Each traversal visits every node exactly once.

```text
Preorder  → O(n)
Inorder   → O(n)
Postorder → O(n)
```

### Overall

```text
Time Complexity: O(n)
```

## Space Complexity

The recursive call stack depends on the height of the tree.

```text
Space Complexity: O(h)
```

- Balanced tree: `O(log n)`
- Skewed tree: `O(n)`

---

# ⚠️ Edge Cases

## Empty Tree

```text
Input: -1
```

All traversals produce no output.

## Single Node

```text
5
```

Output:

```text
Preorder:  5
Inorder:   5
Postorder: 5
```

## Left-Skewed Tree

```text
      4
     /
    3
   /
  2
 /
1
```

```text
Preorder  → 4 3 2 1
Inorder   → 1 2 3 4
Postorder → 1 2 3 4
```

## Right-Skewed Tree

```text
1
 \
  2
   \
    3
     \
      4
```

```text
Preorder  → 1 2 3 4
Inorder   → 1 2 3 4
Postorder → 4 3 2 1
```

---

# 🧠 Key Concepts

### Base Case

```cpp
if(root == NULL) {
    return;
}
```

This stops the recursive calls when a node does not exist.

### Recursion

Each traversal recursively processes the left and right subtrees.

### DFS

Preorder, Inorder, and Postorder are all forms of **Depth-First Search**.

---

# 🎯 Important Takeaways

- **Preorder** → `NLR`
- **Inorder** → `LNR`
- **Postorder** → `LRN`
- `-1` represents a `NULL` node.
- Every traversal visits all nodes once.
- Time complexity is `O(n)`.
- Recursive space complexity is `O(h)`.

---

# 🚨 Common Mistakes

### Forgetting the Base Case

```cpp
if(root == NULL) {
    return;
}
```

### Using the Wrong Traversal Order

```text
Preorder  → NLR
Inorder   → LNR
Postorder → LRN
```

### Printing the Node at the Wrong Position

The placement of:

```cpp
cout << root->data << " ";
```

determines which traversal is performed.

---

# 🏆 Quick Revision

```text
PREORDER
N → L → R

INORDER
L → N → R

POSTORDER
L → R → N
```

For:

```text
          1
        /   \
       2     3
      / \
     4   5
```

```text
Preorder  → 1 2 4 5 3
Inorder   → 4 2 5 1 3
Postorder → 4 5 2 3 1
```

---

# 📚 Related Topics

- Binary Trees
- Binary Search Trees
- Tree Traversal
- Recursion
- Depth-First Search
- Preorder Traversal
- Inorder Traversal
- Postorder Traversal

---

# 🔗 Conclusion

This implementation demonstrates the three fundamental recursive binary tree traversals:

```text
Preorder  → Node → Left → Right
Inorder   → Left → Node → Right
Postorder → Left → Right → Node
```

Each traversal visits every node exactly once, but processes the current node at a different stage.

## Final Complexity

```text
Time Complexity  : O(n)
Space Complexity : O(h)
```
