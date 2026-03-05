# Same Tree
### Given the roots of two binary trees p and q, write a function to check if they are the same or not.
### Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

- Example 1:
- ![ex1](https://github.com/user-attachments/assets/acfe37e0-f4ed-4a8e-bef2-202bb8f068ce)

- Input: p = [1,2,3], q = [1,2,3]
- Output: true

- Example 2:
- ![ex2](https://github.com/user-attachments/assets/3266b37b-b2e2-4199-a01a-737d2ebebe65)

- Input: p = [1,2], q = [1,null,2]
- Output: false

- Example 3:
- ![ex3](https://github.com/user-attachments/assets/120a91b3-2a6d-4c5f-bcb1-e53237a0aa41)
- Input: p = [1,2,1], q = [1,1,2]
- Output: false

### SOLUTION 
```cpp
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(p == NULL && q == NULL) {
            return true ;
        }
        
        // if one is NULL ;
        if(p == NULL || q == NULL) {
            return false ;
        }

        if(p->val != q->val) {
            return false ;
        }
        
        return isSameTree(p->left , q->left) && 
        isSameTree(p->right , q->right) ;
    }
};
```
