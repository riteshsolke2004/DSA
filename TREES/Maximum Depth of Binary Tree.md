### Maximum Depth of Binary Tree
Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

- Example 1:
- ![tmp-tree](https://github.com/user-attachments/assets/e4e4f9de-42e4-4243-9418-ddc8767fbac5)
 
- Input: root = [3,9,20,null,null,15,7]
- Output: 3

- Example 2:
- Input: root = [1,null,2]
- Output: 2


  ## SOLUTION
  ```cpp
  class Solution {
public:
    int maxDepth(TreeNode* root) {

        if(root == NULL) {
            return 0 ;
        }

        int leftHeight = maxDepth(root->left) + 1 ;
        int rightHeight = maxDepth(root->right) + 1 ;

        int ans = max(leftHeight , rightHeight) ;
        return ans ;
        
    }
};

```
