# Two Sum IV - Input is a BST 
- Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

## Example 1: 
![sum_tree_1](https://github.com/user-attachments/assets/8d46cba0-5b9f-42ff-8c6c-20d092ed0e16)

- Input: root = [5,3,6,2,4,null,7], k = 9
- Output: true

## Example 2:
![sum_tree_2](https://github.com/user-attachments/assets/d8a69be4-1bf3-486c-bf5b-500a8e1bb0bf)

- Input: root = [5,3,6,2,4,null,7], k = 28
- Output: false


# SOLUTION

```cpp 

  class Solution {
  public:
    void storeinorder(TreeNode* root, vector<int>& inorder) {

        if (root == NULL) {
            return;
        }

        storeinorder(root->left, inorder);
        inorder.push_back(root->val);
        storeinorder(root->right, inorder);
    }

    bool checkTwoSum(vector<int>& inorder, int k) {

        int n = inorder.size();
        int s = 0;
        int e = n - 1;
        while (s < e) {

            int sum = inorder[s] + inorder[e];

            if (sum == k)
                return true;
            else if (sum > k) {
                e--;
            } else {
                s++;
            }
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        if (root == NULL)
            return NULL;

        vector<int> inorder;
        storeinorder(root, inorder);
        bool ans = checkTwoSum(inorder, k);
        return ans;
    }
};

``` 
