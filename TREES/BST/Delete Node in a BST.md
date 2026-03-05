# Delete Node in a BST

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

1. Search for a node to remove.
2. If the node is found, delete the node.
 

- Example 1:
- ![del_node_1](https://github.com/user-attachments/assets/d63c0dac-1366-4754-90b7-90fa8b402ddc)
- Input: root = [5,3,6,2,4,null,7], key = 3
- Output: [5,4,6,2,null,null,7]
- Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
- One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
- Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

- Example 2:
- ![del_node_supp](https://github.com/user-attachments/assets/36d51148-08ea-4cfb-ba99-7186e480cf29)

- Input: root = [5,3,6,2,4,null,7], key = 0
- Output: [5,3,6,2,4,null,7]
- Explanation: The tree does not contain a node with value = 0.
  
- Example 3:
- Input: root = [], key = 0
- Output: []

# SOLUTION
```cpp

class Solution {
public:

    int getmax(TreeNode* root){

        if(root == NULL) {
            return -1 ;
        }

        while(root->right != NULL){
            root = root->right ;
        }

        return root->val ;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) {
            return NULL ;
        }

        if(root->val == key) {
            // for leaves Node 
            if(root->left == NULL  && root->right == NULL){
                TreeNode* temp = root ;
                temp = NULL ;
                delete temp ;
                return NULL  ;
            }
            // for left Node
            if(root->left != NULL && root->right == NULL){
                TreeNode* temp = root ;
                TreeNode* child = root->left ;
                temp = NULL ;
                delete temp ;
                return child ;
            }
            // for right Node
            if(root->left == NULL && root->right != NULL){
                TreeNode* temp = root ;
                TreeNode* child = root->right ;
                temp = NULL ;
                delete temp ;
                return child ;
            }

            if(root->left != NULL && root->right != NULL){
                
                int replaceValue = getmax(root->left) ;
                root->val = replaceValue ;
                root->left = deleteNode(root->left , replaceValue) ;
                return root  ;

            }

        }
        else {
            if( root->val > key){
                root->left = deleteNode(root->left , key) ;
            }
            else{
                root->right = deleteNode(root->right , key) ;
            }
        } 
        return root  ;
    }
};

```
