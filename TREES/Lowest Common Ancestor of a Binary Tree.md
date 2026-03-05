### Lowest Common Ancestor of a Binary Tree 
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes
p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

- Example 1:
-<img width="200" height="190" alt="binarytree" src="https://github.com/user-attachments/assets/2ca8e943-7935-47bf-8813-260351648a7d" />
 
- Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
- Output: 3
- Explanation: The LCA of nodes 5 and 1 is 3.

- Example 2:
- <img width="200" height="190" alt="binarytree" src="https://github.com/user-attachments/assets/c7bc92ac-5981-4857-8b7a-ba9ad6cc60a2" />

- Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
- Output: 5
- Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.


- Example 3:
- Input: root = [1,2], p = 1, q = 2
- Output: 1

### SOLUTION 
```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if( root == NULL) {
            return NULL ;
        } 

        if(root == p) return p ;

        if(root == q) return q ;

        TreeNode* leftsubtree = lowestCommonAncestor(root->left , p , q) ;
        TreeNode* rightsubtree = lowestCommonAncestor(root->right , p , q) ;

        if(leftsubtree != NULL && rightsubtree == NULL){
            return leftsubtree ;
        }
        else if(leftsubtree == NULL && rightsubtree != NULL){
            return rightsubtree ;
        }
        else if(leftsubtree == NULL && rightsubtree == NULL){
            return NULL  ;
        }
        else{
            return root  ;
        }
        
    }
};
```
