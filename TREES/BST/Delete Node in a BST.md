# 🌳 Delete Node in a BST

## Problem Statement

Given the root node of a **Binary Search Tree (BST)** and an integer `key`, delete the node containing the given key from the BST.

After deletion, return the **root of the updated BST**.

The deletion process has two main stages:

1. Search for the node containing the given key.
2. If the node is found, delete it while maintaining the BST property.

### Important BST Property

For every node in a Binary Search Tree:

- All values in the left subtree are smaller than the node's value.
- All values in the right subtree are greater than the node's value.

### Possible Deletion Cases

When the node is found, there are four practical cases:

1. Leaf node — no children.
2. Only left child.
3. Only right child.
4. Two children.

For two children, this solution uses the **inorder predecessor**, which is the maximum value in the left subtree.

---

# Examples

## Example 1
<img width="1202" height="322" alt="del_node_1" src="https://github.com/user-attachments/assets/08fc5c89-0ad7-49e3-85a0-eb225578f584" />
<img width="442" height="322" alt="del_node_supp" src="https://github.com/user-attachments/assets/e38695a5-0446-4417-8108-856ec4bec246" />

### Input

```text
root = [5,3,6,2,4,null,7]
key = 3
```

### Output

```text
[5,4,6,2,null,null,7]
```

### Explanation

The BST is:

```text
        5
       / \
      3   6
     / \   \
    2   4   7
```

The node `3` has two children.

The solution finds the maximum value in the left subtree of `3`, which is `2`, and uses it as the inorder predecessor.

After deletion, one valid BST is:

```text
        5
       / \
      4   6
     /     \
    2       7
```

Another valid answer is:

```text
[5,2,6,null,4,null,7]
```

Both are valid BSTs.

---

## Example 2

### Input

```text
root = [5,3,6,2,4,null,7]
key = 0
```

### Output

```text
[5,3,6,2,4,null,7]
```

### Explanation

The tree does not contain a node with value `0`, so nothing is deleted.

---

## Example 3

### Input

```text
root = []
key = 0
```

### Output

```text
[]
```

### Explanation

The tree is empty, so there is nothing to delete.

---

# 💡 Approach

The provided solution uses **recursive BST search and deletion**.

The main idea is:

1. Start from the root.
2. Compare `key` with `root->val`.
3. If `key` is smaller, search the left subtree.
4. If `key` is larger, search the right subtree.
5. If the key is found, handle the node according to its children.
6. If the node has two children:
   - Find the maximum value from its left subtree.
   - Replace the current node's value.
   - Recursively delete the duplicate predecessor.
7. Return the updated root.

---

# 🧠 Algorithm

1. If `root == NULL`, return `NULL`.
2. If `root->val == key`:
   - If it is a leaf, delete it and return `NULL`.
   - If it has only a left child, delete it and return the left child.
   - If it has only a right child, delete it and return the right child.
   - If it has two children:
     1. Find the maximum value in the left subtree.
     2. Replace the current node's value with that value.
     3. Delete the duplicate predecessor from the left subtree.
     4. Return the current root.
3. If `key < root->val`, recursively delete from the left subtree.
4. Otherwise, recursively delete from the right subtree.
5. Return `root`.

---

# 🔍 Finding the Inorder Predecessor

The inorder predecessor is the **largest value in the left subtree**.

In a BST, the largest value is always the rightmost node.

```text
       3
      /
     1
      \
       2
```

For node `3`:

```text
3 → left → 1 → right → 2
```

Therefore, the inorder predecessor is `2`.

The helper function:

```cpp
int getmax(TreeNode* root) {
    if(root == NULL) {
        return -1;
    }

    while(root->right != NULL) {
        root = root->right;
    }

    return root->val;
}
```

---

# 🌳 Recursion / Tree Explanation

The recursive flow is:

```text
                    deleteNode(root, key)
                             |
                       root == NULL?
                        /          \
                      Yes           No
                       |             |
                    return       Compare key
                    NULL
                                  /      \
                               smaller   greater
                                  |         |
                                left      right
                               subtree   subtree
                                  \       /
                                   Node Found
                                       |
                         ----------------------------
                         |            |             |
                       0 child      1 child       2 children
                         |            |             |
                       NULL       return child   predecessor
                                                    |
                                             delete predecessor
```

### Base Case

```cpp
if(root == NULL) {
    return NULL;
}
```

This handles an empty tree or a key that is not present.

### Recursive Case

```cpp
if(root->val > key) {
    root->left = deleteNode(root->left, key);
}
else {
    root->right = deleteNode(root->right, key);
}
```

The BST property lets us search only one subtree at each step.

---

# 🔄 Two-Child Dry Run

Input:

```text
root = [5,3,6,2,4,null,7]
key = 3
```

Initial tree:

```text
        5
       / \
      3   6
     / \   \
    2   4   7
```

### Step 1

Current node = `5`

Since:

```text
3 < 5
```

move left.

### Step 2

Current node = `3`

Since:

```text
3 == 3
```

the node is found.

It has two children.

### Step 3

Find maximum in the left subtree:

```text
    2
```

Maximum = `2`.

### Step 4

Replace:

```text
3 → 2
```

Temporary tree:

```text
        5
       / \
      2   6
     / \   \
    2   4   7
```

### Step 5

Delete the duplicate `2` from the left subtree.

Final tree produced by this approach:

```text
        5
       / \
      2   6
       \   \
        4   7
```

---

# 📊 Dry Run Table

| Step | Current Node | Key | Condition | Action |
|------|--------------|-----|-----------|--------|
| 1 | `5` | `3` | `3 < 5` | Move left |
| 2 | `3` | `3` | `3 == 3` | Node found |
| 3 | `3` | `3` | Two children | Find max in left subtree |
| 4 | `2` | — | Maximum found | Replace `3` with `2` |
| 5 | `2` | `2` | Leaf | Delete node |
| 6 | `5` | `3` | Updated subtree | Return root |

---

# 💻 My C++ Solution

The original solution has a **memory-management issue**.

It contains:

```cpp
TreeNode* temp = root;
temp = NULL;
delete temp;
```

After `temp = NULL`, `temp` no longer points to the actual node. Therefore, `delete temp` does not delete the actual node.

The corrected version keeps the same approach but correctly deletes the node.

```cpp
class Solution {
public:

    int getmax(TreeNode* root) {

        if(root == NULL) {
            return -1;
        }

        while(root->right != NULL) {
            root = root->right;
        }

        return root->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root == NULL) {
            return NULL;
        }

        if(root->val == key) {

            // Case 1: Leaf node
            if(root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }

            // Case 2: Only left child
            if(root->left != NULL && root->right == NULL) {
                TreeNode* child = root->left;
                delete root;
                return child;
            }

            // Case 3: Only right child
            if(root->left == NULL && root->right != NULL) {
                TreeNode* child = root->right;
                delete root;
                return child;
            }

            // Case 4: Two children
            if(root->left != NULL && root->right != NULL) {

                int replaceValue = getmax(root->left);

                root->val = replaceValue;

                root->left = deleteNode(root->left, replaceValue);

                return root;
            }
        }

        else if(root->val > key) {
            root->left = deleteNode(root->left, key);
        }

        else {
            root->right = deleteNode(root->right, key);
        }

        return root;
    }
};
```

---

# 🐛 Problem in the Original Code

The original code used:

```cpp
TreeNode* temp = root;
temp = NULL;
delete temp;
```

This does **not** delete `root`.

The pointer changes like this:

```text
Before:
temp ───────> actual node

After temp = NULL:
temp ───────> NULL
root ───────> actual node
```

Then:

```cpp
delete temp;
```

is effectively:

```cpp
delete NULL;
```

So the actual node remains allocated.

### Correct Approach

For a leaf:

```cpp
delete root;
return NULL;
```

For one child:

```cpp
TreeNode* child = root->left;
delete root;
return child;
```

The same idea applies to the right child.

---

# 🔎 Code Explanation

## 1. `getmax()`

```cpp
int getmax(TreeNode* root)
```

Finds the largest value in a subtree.

Because the largest value in a BST is always on the rightmost path:

```cpp
while(root->right != NULL) {
    root = root->right;
}
```

---

## 2. Empty Tree Check

```cpp
if(root == NULL) {
    return NULL;
}
```

There is no node to delete.

---

## 3. Node Found

```cpp
if(root->val == key)
```

This means the current node is the node that must be deleted.

---

## 4. Leaf Node

```cpp
if(root->left == NULL && root->right == NULL) {
    delete root;
    return NULL;
}
```

The node has no children, so simply remove it.

---

## 5. Only Left Child

```cpp
TreeNode* child = root->left;
delete root;
return child;
```

The left child replaces the deleted node.

---

## 6. Only Right Child

```cpp
TreeNode* child = root->right;
delete root;
return child;
```

The right child replaces the deleted node.

---

## 7. Two Children

```cpp
int replaceValue = getmax(root->left);
root->val = replaceValue;
root->left = deleteNode(root->left, replaceValue);
```

The maximum value from the left subtree is used as the inorder predecessor.

---

## 8. Search Direction

If:

```cpp
root->val > key
```

search left.

If:

```cpp
root->val < key
```

search right.

This is what makes BST search efficient.

---

# ⏱️ Complexity Analysis

Let `h` be the height of the BST.

### Time Complexity

```text
O(h)
```

For a balanced BST:

```text
O(log n)
```

For a skewed BST:

```text
O(n)
```

### Space Complexity

Because recursion is used:

```text
O(h)
```

Balanced BST:

```text
O(log n)
```

Worst case:

```text
O(n)
```

---

# ⚠️ Edge Cases

- Empty BST.
- Key does not exist.
- Deleting a leaf node.
- Deleting a node with only a left child.
- Deleting a node with only a right child.
- Deleting a node with two children.
- Deleting the root node.
- Deleting the only node in the tree.
- Highly skewed BST.

---

# 🧪 Additional Test Cases

## Test Case 1 — Delete Leaf

```text
Input:
root = [5,3,6,2,4,null,7]
key = 2

Output:
[5,3,6,null,4,null,7]
```

## Test Case 2 — Key Not Present

```text
Input:
root = [5,3,6,2,4,null,7]
key = 10

Output:
[5,3,6,2,4,null,7]
```

## Test Case 3 — Empty Tree

```text
Input:
root = []
key = 5

Output:
[]
```

## Test Case 4 — Delete Root

```text
Input:
root = [5,3,7,2,4,6,8]
key = 5

One valid output:
[4,3,7,2,null,6,8]
```

---

# 📌 Key Concepts

### Binary Search Tree

```text
Left Subtree < Root < Right Subtree
```

### Inorder Predecessor

The largest value in the left subtree.

### Recursion

The function calls itself on the required subtree.

### Pointer Reconnection

The returned subtree root must be assigned back:

```cpp
root->left = deleteNode(root->left, key);
```

or:

```cpp
root->right = deleteNode(root->right, key);
```

### Dynamic Memory

When dynamically allocated nodes are removed, they should be properly deleted using:

```cpp
delete root;
```

---

# 🎯 Important Takeaways

- BST deletion requires handling different child configurations.
- A leaf node can simply be deleted.
- A node with one child can be replaced by its child.
- A node with two children can use an inorder predecessor or successor.
- This solution uses the **inorder predecessor**.
- The inorder predecessor is the maximum value in the left subtree.
- Recursive return values are important for reconnecting the modified tree.
- Never set the pointer to `NULL` before deleting the object it points to.
- Time complexity is `O(h)`.
- Recursive space complexity is `O(h)`.

---

# 🚨 Common Mistakes

### Mistake 1: Deleting a NULL Pointer Instead of the Node

Wrong:

```cpp
temp = NULL;
delete temp;
```

Correct:

```cpp
delete root;
```

### Mistake 2: Not Assigning the Returned Subtree

Wrong:

```cpp
deleteNode(root->left, key);
```

Correct:

```cpp
root->left = deleteNode(root->left, key);
```

### Mistake 3: Forgetting the Two-Child Case

A node with two children needs a predecessor or successor.

### Mistake 4: Forgetting to Delete the Duplicate Predecessor

After:

```cpp
root->val = replaceValue;
```

the original predecessor must also be deleted.

---

# 🏆 Interview Notes

### Core Idea

Use BST properties to find the node, then handle it according to its number of children.

### Two-Child Strategy

Use:

```text
Maximum value in left subtree
```

as the inorder predecessor.

### Complexity

```text
Time  : O(h)
Space : O(h)
```

For a balanced BST:

```text
Time  : O(log n)
Space : O(log n)
```

Worst case:

```text
Time  : O(n)
Space : O(n)
```

---

# 📚 Related DSA Topics

- Binary Search Tree
- Binary Tree
- Recursion
- Inorder Traversal
- Inorder Predecessor
- Inorder Successor
- Tree Searching
- Dynamic Memory Management
- Pointers

---

# 🔗 Conclusion

BST deletion is a classic tree problem that tests understanding of recursion, BST properties, pointers, and tree restructuring.

The provided solution correctly follows the standard **inorder predecessor** strategy for nodes with two children.

The main correction required in the original code is proper memory deletion. Instead of setting `temp` to `NULL` before deleting it, the actual node must be deleted directly.

```cpp
delete root;
```

This keeps the original approach intact while fixing the memory-management issue.

---

# ⭐ Quick Revision

```text
                 BST Deletion
                      |
                 Search for Key
                      |
             +--------+--------+
             |        |        |
          key <     key ==    key >
             |        |        |
           Left     Delete    Right
                    Node
                      |
          +-----------+-----------+
          |           |           |
       No Child    One Child   Two Children
          |           |           |
       NULL       Return Child  Find Max
                                in Left
                                   |
                              Replace Value
                                   |
                              Delete Duplicate
```

### Final Complexity

```text
Time Complexity  : O(h)
Space Complexity : O(h)
```

where `h` is the height of the BST.
