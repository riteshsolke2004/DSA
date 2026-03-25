# Convert Sorted Array to Binary Search Tree 
- Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

### Example 1:
- Input: nums = [-10,-3,0,5,9]
- ![btree1](https://github.com/user-attachments/assets/ee077040-cf89-4f05-9115-b87311cb2db9)
- Output: [0,-3,9,-10,null,5]
- Explanation: [0,-10,5,null,-3,null,9] is also accepted:
![btree2](https://github.com/user-attachments/assets/c3f02329-ac26-4efd-a524-aaec0ae2cd52)

## Example 2:
- Input: nums = [1,3]
- Output: [3,1]
- Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
- ![btree](https://github.com/user-attachments/assets/79c2bc5e-4d54-4e6b-a7df-e095a62a8d9f)

# SOLUTION 
```cpp
class Solution {
public:

    TreeNode* solve(vector<int>& inorder, int s, int e) {
        if(s > e) {
            return NULL ;
        }
        int mid = (s+e) / 2 ;
        int element = inorder[mid] ;
        TreeNode* root = new TreeNode(element) ;

        root->left = solve(inorder, s, mid-1) ;
        root->right = solve(inorder, mid+1, e) ; 
        return root ;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start = 0 ;
        int end = nums.size()-1 ;
        TreeNode* root = solve(nums, start, end) ;
        return root ;
        
    }
};
```
