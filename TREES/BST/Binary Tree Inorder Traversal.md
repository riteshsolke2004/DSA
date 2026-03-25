# Binary Tree Inorder Traversal
- Given the root of a binary tree, return the inorder traversal of its nodes' values.


### Example 1:

- Input: root = [1,null,2,3]

- Output: [1,3,2]
- <img width="254" height="335" alt="screenshot-2024-08-29-202743" src="https://github.com/user-attachments/assets/fa45fac8-b185-4017-b006-9abdcc8727c0" />

### Example 2:

- Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
- Output: [4,2,6,5,7,1,3,9,8]
- <img width="524" height="428" alt="tree_2" src="https://github.com/user-attachments/assets/36ff5356-5b99-4c21-a55c-89b93d933758" />

### Example 3:

- Input: root = []

- Output: []

### Example 4:

- Input: root = [1]

- Output: [1]


# SOLUTION 
```cpp
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans) {
        if(root == NULL) return ; 

        inorder(root->left , ans) ;
        ans.push_back(root->val) ;
        inorder(root->right, ans) ;

    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans ;
        inorder(root,ans) ;
        return ans ;
    }
};

```
