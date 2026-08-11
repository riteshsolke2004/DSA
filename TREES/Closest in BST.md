# 🌳 Closest in BST

## Problem Statement

Given the **root** of a Binary Search Tree (BST) and an integer `k`, find the **minimum absolute difference** between `k` and the value of any node in the BST.

In simple words, we need to find the node whose value is **closest to `k`**.

The formula used is:

```text
|node->data - k|

We need to find the minimum value among all these differences.
```
# Example 1
<img width="291" height="354" alt="blobid0_1783688040" src="https://github.com/user-attachments/assets/9b1056a0-787b-46cf-abfe-e731efc5ae16" />

# Input
root = [10, 2, 11, 1, 5, N, N, N, N, 3, 6, N, 4]
k = 13
Tree
             10
            /  \
           2    11
          / \
         1   5
            / \
           3   6
            \
             4
Output
2
Explanation

The node closest to 13 is 11.

|10 - 13| = 3
|2  - 13| = 11
|11 - 13| = 2
|1  - 13| = 12
|5  - 13| = 8
|3  - 13| = 10
|6  - 13| = 7
|4  - 13| = 9

The minimum absolute difference is:

|11 - 13| = 2

Therefore, the answer is:

2
# Example 2
<img width="352" height="362" alt="blobid1_1783744852" src="https://github.com/user-attachments/assets/29a37fb3-5b4c-47d4-8a82-5a5c696e1410" />

# Input
root = [8, 1, 9, N, 4, N, 10, 3]
k = 9
Tree
          8
         / \
        1   9
         \   \
          4   10
         /
        3
Output
0
Explanation

The tree already contains the value 9.

|9 - 9| = 0

Therefore, the minimum possible difference is 0.

Approach

We use recursion / DFS traversal to visit every node of the BST.

For every node:

int ans = abs(root->data - k);

Then compare this difference with the minimum difference found so far.

minvalue = min(ans, minvalue);

We continue recursively for both:

Left Subtree
Right Subtree
Algorithm
Initialize minvalue with INT_MAX.
Start recursion from the root.
If the current node is NULL, return.
Calculate the absolute difference:
abs(root->data - k)
Update the minimum difference.
Recursively visit the left subtree.
Recursively visit the right subtree.
Return the minimum difference.
Why Do We Use abs()?

We need the absolute difference between the node value and k.

For example:

node = 11
k = 13

Without abs():

11 - 13 = -2

But the actual distance between the two values is:

|11 - 13| = 2

Therefore, we use:

abs(root->data - k)
Why Do We Use minvalue?

We need to store the smallest difference found while traversing the tree.

Initially:

int minvalue = INT_MAX;

Suppose we get:

Difference = 8

Then:

minvalue = 8

Later we find:

Difference = 3

Then:

minvalue = 3

Later we find:

Difference = 2

Then:

minvalue = 2

So the minimum value keeps getting updated.

Why Pass minvalue by Reference?

The recursive function uses:

int &minvalue

The & means that all recursive calls use the same variable.

For example:

minDiff()
    |
    minvalue = INT_MAX
    |
    ↓
solve()
    |
    minvalue = 3
    |
    ↓
solve()
    |
    minvalue = 2

The final value 2 is available in the original minvalue.

If we passed it normally instead of by reference, every recursive call would receive its own copy.

## C++ Solution

```cpp
class Solution {
  public:

    int solve(Node* root, int k, int &minvalue) {
        
        if(root == NULL) {
            return 0;
        }
        
        int rootValue = root->data;
        
        int ans = abs(rootValue - k);
        
        minvalue = min(ans, minvalue);
        
        solve(root->left, k, minvalue);
        solve(root->right, k, minvalue);
        
        return minvalue;
    }

    int minDiff(Node *root, int k) {
        
        int minvalue = INT_MAX;
        
        int ans = solve(root, k, minvalue);
        
        return ans;
    }
};

```
# Detailed Dry Run

### Consider:

root = [10, 2, 11, 1, 5, N, N, N, N, 3, 6, N, 4]
k = 13

# Tree:

             10
            /  \
           2    11
          / \
         1   5
            / \
           3   6
            \
             4

Initially:

minvalue = INT_MAX
k = 13
Step 1: Node 10

Current node:

10

Calculate:

|10 - 13| = 3

Update:

minvalue = min(INT_MAX, 3)
         = 3

Now recursively visit the left subtree.

Step 2: Node 2

Current node:

2

Calculate:

|2 - 13| = 11

Update:

minvalue = min(3, 11)
         = 3
Step 3: Node 1

Current node:

1

Calculate:

|1 - 13| = 12

Update:

minvalue = min(3, 12)
         = 3

Node 1 has no children.

Return.

Step 4: Node 5

Current node:

5

Calculate:

|5 - 13| = 8

Update:

minvalue = min(3, 8)
         = 3

Now visit its left and right children.

Step 5: Node 3

Current node:

3

Calculate:

|3 - 13| = 10

Update:

minvalue = min(3, 10)
         = 3

Node 3 has a right child 4.

Step 6: Node 4

Current node:

4

Calculate:

|4 - 13| = 9

Update:

minvalue = min(3, 9)
         = 3

Node 4 has no children.

Return.

Step 7: Node 6

Current node:

6

Calculate:

|6 - 13| = 7

Update:

minvalue = min(3, 7)
         = 3

Node 6 has no children.

Return.

Step 8: Node 11

Now we process the right subtree of 10.

Current node:

11

Calculate:

|11 - 13| = 2

Update:

minvalue = min(3, 2)
         = 2

Now the minimum difference is 2.

Dry Run Table
Node	k	Absolute Difference	minvalue
10	13	3	3
2	13	11	3
1	13	12	3
5	13	8	3
3	13	10	3
4	13	9	3
6	13	7	3
11	13	2	2

Final:

Minimum Difference = 2
Recursive Flow
                 solve(10)
                    |
          Calculate |10 - 13| = 3
                    |
              minvalue = 3
                    |
             ┌──────┴──────┐
             ↓             ↓
         solve(2)      solve(11)
             |             |
       Calculate 11    Calculate 2
             |             |
        minvalue = 3  minvalue = 2
             |
        ┌────┴────┐
        ↓         ↓
    solve(1)   solve(5)
                  |
              ┌───┴───┐
              ↓       ↓
          solve(3)  solve(6)
              |
           solve(4)
Algorithm Flow
Start
  |
  ↓
minvalue = INT_MAX
  |
  ↓
Traverse current node
  |
  ↓
Calculate |node - k|
  |
  ↓
Update minvalue
  |
  ↓
Traverse Left Subtree
  |
  ↓
Traverse Right Subtree
  |
  ↓
Return minvalue
  |
  ↓
End
Complexity Analysis

Let N be the number of nodes in the BST.

Time Complexity

Every node is visited exactly once.

O(N)
Space Complexity

The recursive call stack depends on the height of the tree.

O(H)

Where H is the height of the BST.

For a balanced BST:

O(log N)

For a skewed BST:

O(N)
Edge Cases
1. Exact Match

If:

k = 9

and the tree contains:

9

Then:

|9 - 9| = 0

Output:

0
2. K Smaller Than All Nodes

Example:

        10
       /  \
      5    15

k = 1

Closest node is 5.

|5 - 1| = 4

Output:

4
3. K Greater Than All Nodes

Example:

        10
       /  \
      5    15

k = 20

Closest node is 15.

|15 - 20| = 5

Output:

5
4. Single Node

Example:

root = [10]
k = 13

Difference:

|10 - 13| = 3

Output:

3
Common Mistakes
❌ Mistake 1: Forgetting abs()

Wrong:

root->data - k

Correct:

abs(root->data - k)
❌ Mistake 2: Initializing minvalue With 0

Wrong:

int minvalue = 0;

Correct:

int minvalue = INT_MAX;

Because the minimum difference can be greater than 0.

❌ Mistake 3: Not Passing minvalue by Reference

Wrong:

int solve(Node* root, int k, int minvalue)

Correct:

int solve(Node* root, int k, int &minvalue)

Using a reference ensures that every recursive call updates the same minimum value.

❌ Mistake 4: Forgetting One Subtree

We need to check both:

solve(root->left, k, minvalue);
solve(root->right, k, minvalue);

Otherwise, we may miss the closest node.

Key Concepts
Binary Search Tree
Binary Tree
DFS
Recursion
Tree Traversal
Reference Variable
Absolute Difference
Minimum Tracking
Important Observation

The main idea is very simple:

For every node:

difference = |node->data - k|

Keep the smallest difference.

The complete process is:

BST
 ↓
Visit Every Node
 ↓
Calculate Absolute Difference
 ↓
Update Minimum
 ↓
Return Minimum
Quick Revision
Initialize
int minvalue = INT_MAX;
Calculate Difference
int ans = abs(root->data - k);
Update Minimum
minvalue = min(ans, minvalue);
Traverse
solve(root->left, k, minvalue);
solve(root->right, k, minvalue);
# Final Code

```cpp
class Solution {
public:

    int solve(Node* root, int k, int &minvalue) {
        
        if(root == NULL) {
            return 0;
        }
        
        int rootValue = root->data;
        
        int ans = abs(rootValue - k);
        
        minvalue = min(ans, minvalue);
        
        solve(root->left, k, minvalue);
        solve(root->right, k, minvalue);
        
        return minvalue;
    }

    int minDiff(Node *root, int k) {
        
        int minvalue = INT_MAX;
        
        int ans = solve(root, k, minvalue);
        
        return ans;
    }
};

```
Summary
Feature	Details
Problem	Closest in BST
Difficulty	Medium
Approach	DFS + Recursion
Main Idea	Minimum absolute difference
Formula	abs(node->data - k)
Initial Minimum	INT_MAX
Time Complexity	O(N)
Space Complexity	O(H)
Exact Match	0
🧠 Final Takeaway

The core concept is:

Closest in BST
      ↓
Visit Every Node
      ↓
Calculate |node - k|
      ↓
Track Minimum
      ↓
Return Minimum

Closest in BST = DFS + Absolute Difference + Minimum Tracking. 🌳🎯
