# Search in a Binary Search Tree 

### You are given the root of a binary search tree (BST) and an integer val.

### Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

- Example 1:
- ![tree1](https://github.com/user-attachments/assets/22220698-5a62-4959-939d-393263445a7c)

- Input: root = [4,2,7,1,3], val = 2
- Output: [2,1,3]

  - Example 2:
  - ![tree2](https://github.com/user-attachments/assets/1f5ec594-4359-44d2-9c96-958a1c115869)

- Input: root = [4,2,7,1,3], val = 5
- Output: []

# SOLUTION 
```cpp
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) {
            return NULL ;
        }

        if(root->val == val){
            return root ;
        }
        else if(root->val > val) {
            TreeNode* leftans = searchBST(root->left , val) ;
            return leftans ;
        }
        else{
            TreeNode* rightans = searchBST(root->right , val) ;
            return rightans ;
        }
        return NULL ;
    }
};

```
