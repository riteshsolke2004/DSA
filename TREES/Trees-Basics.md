# 🌳 Trees Data Structure – Complete Notes

## 📌 What is a Tree?

A **Tree** is a hierarchical, non-linear data structure consisting of nodes connected by edges.

It represents parent–child relationships.

👉 Example uses:

* File systems
* DOM structure
* Database indexing
* AI decision trees

---

## ⭐ Basic Terminology

| Term    | Meaning                        |
| ------- | ------------------------------ |
| Node    | Basic element storing data     |
| Root    | Topmost node                   |
| Parent  | Node having children           |
| Child   | Node derived from parent       |
| Leaf    | Node with no children          |
| Sibling | Nodes with same parent         |
| Edge    | Connection between nodes       |
| Height  | Longest path from node to leaf |
| Depth   | Distance from root             |
| Subtree | Tree inside another tree       |

---

## 🌲 Types of Trees

* General Tree
* Binary Tree
* Binary Search Tree (BST)
* AVL Tree
* Red-Black Tree
* Heap
* Trie
* Segment Tree
* B-Tree

---

## 🌿 Binary Tree

A tree where each node has **at most two children**.

```cpp
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};
```

---

## 📊 Types of Binary Trees

| Type     | Description                    |
| -------- | ------------------------------ |
| Full     | Every node has 0 or 2 children |
| Complete | All levels filled except last  |
| Perfect  | All nodes filled               |
| Skewed   | All nodes on one side          |
| Balanced | Height difference ≤ 1          |

---

## 🔁 Tree Traversals

### 1️⃣ Inorder (LNR)

```cpp
void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
```

---

### 2️⃣ Preorder (NLR)

```cpp
void preorder(Node* root){
    if(!root) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
```

---

### 3️⃣ Postorder (LRN)

```cpp
void postorder(Node* root){
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
```

---

### 4️⃣ Level Order (BFS)

```cpp
void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout<<temp->data<<" ";

        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}
```

---

## 🔍 Binary Search Tree (BST)

👉 Left subtree < Root < Right subtree

### ✅ Search

```cpp
Node* search(Node* root, int key){
    if(!root || root->data==key) return root;

    if(key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}
```

---

### ✅ Insertion

```cpp
Node* insert(Node* root, int val){
    if(!root) return new Node(val);

    if(val < root->data)
        root->left = insert(root->left,val);
    else
        root->right = insert(root->right,val);

    return root;
}
```

---

### ✅ Deletion (3 Cases)

* Leaf node
* One child
* Two children (replace with inorder successor)

---

## 🧠 Heap (Important for Interviews)

👉 Complete Binary Tree

| Type     | Property          |
| -------- | ----------------- |
| Max Heap | Parent > Children |
| Min Heap | Parent < Children |

Used in:

* Priority Queue
* Heap Sort
* Scheduling

---

## ⏱ Time Complexity

| Operation | Binary Tree | BST (Avg) | BST (Worst) |
| --------- | ----------- | --------- | ----------- |
| Search    | O(n)        | O(log n)  | O(n)        |
| Insert    | O(n)        | O(log n)  | O(n)        |
| Delete    | O(n)        | O(log n)  | O(n)        |

---
