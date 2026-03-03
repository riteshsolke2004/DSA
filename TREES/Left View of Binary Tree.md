# Left View of Binary Tree
###  Given the root of a binary tree. Your task is to return the left view of the binary tree.
### The left view of a binary tree is the set of nodes visible when the tree is viewed from the left side.

- Note: If the tree is empty, return an empty list.

- Examples :

- Input: root = [1, 2, 3, 4, 5, N, N]

- Output:[1, 2, 4]
- Explanation: From the left side of the tree, only the nodes 1, 2, and 4 are visible.

- Input: root = [1, 2, 3, N, N, 4, N, N, 5, N, N]

- Output: [1, 2, 4, 5]
- Explanation: From the left side of the tree, only the nodes 1, 2, 4, and 5 are visible.

### SOLUTION 
```cpp

class Solution {
  public:
  
    void solve(Node* root, int level , vector<int> &ans) {
        if(root == NULL) {
            return ; 
        }
        
        if(level == ans.size() ){
            ans.push_back(root->data) ;
        }
        
        solve(root->left, level+1, ans) ;
        solve(root->right,level+1, ans) ;
    }
    vector<int> leftView(Node *root) {
        // code here
        
        vector<int> ans ;
        solve(root , 0, ans) ;
        return ans ;
        
    }
};

```
