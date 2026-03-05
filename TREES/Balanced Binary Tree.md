### Balanced Binary Tree

Given a binary tree, determine if it is height-balanced

- Example 1:
- ![balance_1](https://github.com/user-attachments/assets/e0e3586a-79c8-4906-ab03-e6533521bccb)
- Input: root = [3,9,20,null,null,15,7]
- Output: true

- Example 2:
- ![balance_2](https://github.com/user-attachments/assets/cb4a6429-127a-4b95-9e26-147acdfd68ed)

- Input: root = [1,2,2,3,3,null,null,4,4]
- Output: false

- Example 3:

- Input: root = []
- Output: true

### SOLUTION

```cpp
class Solution {
public:
    int getheight(TreeNode* root) {

        if(root == NULL) {
            return 0 ;
        }

        int leftDepth = getheight(root->left) ;
        int rightDepth = getheight(root->right) ;

        int ans = max(leftDepth , rightDepth) + 1 ;
        return ans ;

    }
    bool isBalanced(TreeNode* root) {

        if(root == NULL) {
            return true ;
        }

        int leftheight = getheight(root->left) ;
        int rightheight = getheight(root->right) ;

        int absDiff = abs(leftheight - rightheight) ;

        if(absDiff > 1) {
            return false ;
        } 
        else{

            bool leftans = isBalanced(root->left) ;
            bool rightans = isBalanced(root->right) ;

            if(leftans == true && rightans == true ){
                return true ;
            }
            else{
                return false ;
            }
        }
        
    }
};

```
