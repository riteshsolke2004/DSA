# " Kth Smallest Element in a BST "
- Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

### Example 1:
- Input: root = [3,1,4,null,2], k = 1
- Output: 1
- ![kthtree1](https://github.com/user-attachments/assets/acc8ab58-e2f3-45be-bb7c-cd4eb01a72b8)

### Example 2:
- Input: root = [5,3,6,2,4,null,null,1], k = 3
- Output: 3
-![kthtree2](https://github.com/user-attachments/assets/76990298-9f7a-4b93-9a7d-898ed0f9e907)

# SOLUTION 
- By 2 Ways to Solve this problem
1. By Recursive Call
2. By Store inorder and return inorder of K-1 place

## SOLUTION 1
```cpp
class Solution {
public:
    void solve(TreeNode* root, int k, int &count, TreeNode* &ans) {
        if(root == NULL) {
            return ;
        }

        solve(root->left, k, count, ans) ;

        count++ ;
        if(count == k){
            ans = root ;
        }

        solve(root->right, k, count, ans) ;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int count = 0 ;
        TreeNode* ans = NULL ;
        solve(root, k, count, ans) ;
        return ans->val ;      
    }
};
```
## SOLUTION 2 
```cpp
class Solution {
public:
    void StoreInorderTraversal(TreeNode* root, vector<int>& inorder) {
        if(root == NULL) return ;

        StoreInorderTraversal(root->left, inorder) ;
        inorder.push_back(root->val) ;
        StoreInorderTraversal(root->right, inorder) ;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder ;
        StoreInorderTraversal(root,inorder) ;
        return inorder[k-1] ;

        
    }
};
```
