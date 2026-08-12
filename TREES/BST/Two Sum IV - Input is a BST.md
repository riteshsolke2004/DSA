# 🌳 653. Two Sum IV - Input is a BST

## Problem Statement

Given the **root of a Binary Search Tree (BST)** and an integer `k`, return `true` if there exist **two different elements** in the BST whose sum is equal to `k`; otherwise return `false`.

### Important Conditions

- The input is a Binary Search Tree.
- We need to find two different nodes.
- Their values must satisfy:
  ```text
  value1 + value2 = k
  ```
- Inorder traversal of a BST produces values in sorted ascending order.

---

# 🧪 Examples

## Example 1
<img width="562" height="322" alt="sum_tree_1" src="https://github.com/user-attachments/assets/20c180b1-c525-4087-9f82-1001b65cd139" />

### Input

```text
root = [5,3,6,2,4,null,7]
k = 9
```

### Output

```text
true
```

### Explanation

The BST is:

```text
        5
       / \
      3   6
     / \   \
    2   4   7
```

Inorder traversal:

```text
2 3 4 5 6 7
```

A valid pair is:

```text
2 + 7 = 9
```

Therefore, the answer is `true`.

---

## Example 2
<img width="562" height="322" alt="sum_tree_2" src="https://github.com/user-attachments/assets/801db3a0-b560-4b99-8017-6429bd4e0526" />

### Input

```text
root = [5,3,6,2,4,null,7]
k = 28
```

### Output

```text
false
```

### Explanation

The largest two values are `7` and `6`:

```text
7 + 6 = 13
```

No two values can produce `28`, so the answer is `false`.

---

# 💡 Approach

The provided solution uses:

```text
BST
 ↓
Inorder Traversal
 ↓
Sorted Vector
 ↓
Two-Pointer Technique
 ↓
Find Pair With Sum = k
```

### Step 1: Store Inorder Traversal

The function `storeinorder()` performs:

```text
Left → Root → Right
```

Because the input is a BST, the resulting vector is sorted.

Example:

```text
BST → [5,3,6,2,4,null,7]

Inorder → [2,3,4,5,6,7]
```

### Step 2: Apply Two Pointers

Initialize:

```text
s = 0
e = n - 1
```

where:

- `s` points to the smallest value.
- `e` points to the largest value.

For every pair:

```text
sum = inorder[s] + inorder[e]
```

- `sum == k` → return `true`
- `sum > k` → decrement `e`
- `sum < k` → increment `s`

If `s >= e`, no valid pair exists.

---

# 🧠 Algorithm

1. If `root == NULL`, return `false`.
2. Create an empty vector `inorder`.
3. Perform inorder traversal and store all node values.
4. The vector is sorted because the input is a BST.
5. Set:
   ```text
   s = 0
   e = n - 1
   ```
6. While `s < e`:
   - Calculate `sum = inorder[s] + inorder[e]`.
   - If `sum == k`, return `true`.
   - If `sum > k`, decrement `e`.
   - Otherwise increment `s`.
7. Return `false`.

---

# 🌳 Recursion / Tree Explanation

The solution uses recursion for inorder traversal:

```text
                 inorder(root)
                       |
              ┌────────┴────────┐
              ↓                 ↓
        inorder(left)    inorder(right)
              |
          Store root
```

The exact order is:

```text
Left → Root → Right
```

For a BST, this gives sorted values.

---

# 🔄 Inorder Traversal Example

For:

```text
        5
       / \
      3   6
     / \   \
    2   4   7
```

The traversal visits:

```text
2 → 3 → 4 → 5 → 6 → 7
```

So:

```cpp
inorder = {2, 3, 4, 5, 6, 7};
```

---

# 🔍 Two-Pointer Explanation

For:

```text
inorder = [2,3,4,5,6,7]
k = 9
```

Initially:

```text
s = 0
e = 5
```

Therefore:

```text
inorder[s] = 2
inorder[e] = 7
```

Calculate:

```text
2 + 7 = 9
```

Since:

```text
9 == k
```

return:

```text
true
```

---

# 📊 Dry Run

## Example 1

```text
root = [5,3,6,2,4,null,7]
k = 9
```

Inorder:

```text
[2, 3, 4, 5, 6, 7]
```

| Step | `s` | `e` | Left | Right | Sum | Action |
|------|-----|-----|------|-------|-----|--------|
| 1 | 0 | 5 | 2 | 7 | 9 | Found → `true` |

Final answer:

```text
true
```

---

## Example 2

```text
inorder = [2,3,4,5,6,7]
k = 28
```

| Step | `s` | `e` | Pair | Sum | Action |
|------|-----|-----|------|-----|--------|
| 1 | 0 | 5 | `2 + 7` | 9 | `s++` |
| 2 | 1 | 5 | `3 + 7` | 10 | `s++` |
| 3 | 2 | 5 | `4 + 7` | 11 | `s++` |
| 4 | 3 | 5 | `5 + 7` | 12 | `s++` |
| 5 | 4 | 5 | `6 + 7` | 13 | `s++` |
| 6 | 5 | 5 | — | — | Stop |

Since `s >= e`, return:

```text
false
```

---

# 💻 My C++ Solution

Your approach is correct: **inorder traversal + sorted vector + two pointers**.

There is only a small readability improvement in the original code:

```cpp
return NULL;
```

inside a `bool` function should preferably be:

```cpp
return false;
```

`NULL` behaves like `0`, so the original code works in this situation, but `false` is the correct semantic value.

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

            if (sum == k) {
                return true;
            }
            else if (sum > k) {
                e--;
            }
            else {
                s++;
            }
        }

        return false;
    }

    bool findTarget(TreeNode* root, int k) {

        if (root == NULL) {
            return false;
        }

        vector<int> inorder;

        storeinorder(root, inorder);

        bool ans = checkTwoSum(inorder, k);

        return ans;
    }
};
```

---

# 🔎 Code Explanation

## 1. `storeinorder()`

```cpp
void storeinorder(TreeNode* root, vector<int>& inorder)
```

Performs inorder traversal and stores node values in the vector.

```text
Left → Root → Right
```

---

## 2. Base Case

```cpp
if (root == NULL) {
    return;
}
```

Stops recursion when there is no node.

---

## 3. Store Current Value

```cpp
inorder.push_back(root->val);
```

The current node is stored after processing the left subtree.

---

## 4. `checkTwoSum()`

```cpp
bool checkTwoSum(vector<int>& inorder, int k)
```

Uses two pointers on the sorted vector.

```cpp
int s = 0;
int e = n - 1;
```

---

## 5. Sum Equals `k`

```cpp
if (sum == k) {
    return true;
}
```

A valid pair has been found.

---

## 6. Sum Greater Than `k`

```cpp
else if (sum > k) {
    e--;
}
```

The sum is too large, so move the right pointer toward smaller values.

---

## 7. Sum Smaller Than `k`

```cpp
else {
    s++;
}
```

The sum is too small, so move the left pointer toward larger values.

---

## 8. `findTarget()`

This is the main function.

It:

1. Handles an empty tree.
2. Creates the inorder vector.
3. Stores the BST values.
4. Calls `checkTwoSum()`.
5. Returns the result.

---

# 🐛 Small Issue in the Original Code

Original:

```cpp
if (root == NULL)
    return NULL;
```

The function returns `bool`.

Better:

```cpp
if (root == NULL)
    return false;
```

### Is this an algorithmic error?

No.

`NULL` evaluates to zero, so it behaves as `false` here. However, using `false` is clearer and better C++ style.

---

# 🧩 Why Two Pointers Work

The vector is sorted:

```text
[2, 3, 4, 5, 6, 7]
```

Suppose:

```text
left = 2
right = 7
```

If:

```text
left + right > k
```

we need a smaller sum, so decrease `right`.

If:

```text
left + right < k
```

we need a larger sum, so increase `left`.

Because the array is sorted, every pointer movement eliminates unnecessary possibilities.

---

# ⚠️ Edge Cases

### Empty Tree

```text
root = []
k = 10

Output:
false
```

### Single Node

```text
root = [5]
k = 10

Output:
false
```

A single node cannot form a pair with another different node.

### Pair Exists

```text
root = [5,3,6,2,4,null,7]
k = 9

Output:
true
```

Because:

```text
2 + 7 = 9
```

### Pair Does Not Exist

```text
root = [5,3,6,2,4,null,7]
k = 28

Output:
false
```

### Duplicate Values

If duplicate values are allowed by the tree representation, two different nodes can form a pair using the same value.

Example:

```text
5 + 5 = 10
```

provided there are two distinct nodes containing `5`.

---

# 🧪 Additional Test Cases

## Test Case 1

```text
Input:
root = [2,1,3]
k = 4

Output:
true
```

Because:

```text
1 + 3 = 4
```

## Test Case 2

```text
Input:
root = [2,1,3]
k = 10

Output:
false
```

## Test Case 3

```text
Input:
root = []
k = 5

Output:
false
```

## Test Case 4

```text
Input:
root = [5]
k = 10

Output:
false
```

## Test Case 5

```text
Input:
root = [10,5,15,3,7,12,20]
k = 22

Output:
true
```

Because:

```text
10 + 12 = 22
```

---

# ⏱️ Complexity Analysis

Let `n` be the number of nodes.

## Inorder Traversal

Every node is visited once:

```text
O(n)
```

## Two-Pointer Search

Both pointers move at most `n` positions:

```text
O(n)
```

Therefore:

```text
Total Time = O(n)
```

## Space Complexity

The inorder vector stores all node values:

```text
O(n)
```

The recursive call stack uses:

```text
O(h)
```

where `h` is the tree height.

Therefore:

```text
Space = O(n + h)
```

Since `h <= n`:

```text
Overall Space Complexity = O(n)
```

---

# 📌 Key Concepts

### Binary Search Tree

```text
Left Subtree < Root < Right Subtree
```

### Inorder Traversal

```text
Left → Root → Right
```

For a BST:

```text
Inorder = Sorted Order
```

### Two-Pointer Technique

```text
left  → smallest
right → largest
```

Move pointers according to the current sum.

### Recursion

The inorder traversal recursively visits the left and right subtrees.

### Pass by Reference

```cpp
vector<int>& inorder
```

allows the same vector to be modified without copying it.

---

# 🎯 Important Takeaways

- Inorder traversal of a BST gives sorted values.
- A sorted vector allows the two-pointer technique.
- `sum == k` → answer is `true`.
- `sum > k` → move `right` left.
- `sum < k` → move `left` right.
- Use `s < e` so the same element is not used twice.
- The algorithm takes `O(n)` time.
- The vector requires `O(n)` space.
- `return false` is preferable to `return NULL` in a boolean function.

---

# 🚨 Common Mistakes

### Mistake 1: Using the Wrong Traversal

For a BST, inorder traversal is important because it gives sorted order.

```text
Left → Root → Right
```

### Mistake 2: Using `s <= e`

This could allow the same node to be considered twice.

Correct:

```cpp
while (s < e)
```

### Mistake 3: Moving the Wrong Pointer

```text
sum > k → e--
sum < k → s++
```

### Mistake 4: Forgetting Empty Tree Handling

Always handle:

```cpp
if (root == NULL)
```

### Mistake 5: Assuming Every Pair Must Be Adjacent

The required pair can be anywhere in the sorted vector.

---

# 🏆 Interview Notes

### What is the core idea?

Convert the BST into a sorted array using inorder traversal and apply the two-pointer Two Sum technique.

### Why does inorder traversal help?

Because inorder traversal of a BST produces values in ascending order.

### Why use two pointers?

The sorted order allows us to eliminate impossible pairs efficiently.

### What if the sum is too large?

```text
right--
```

### What if the sum is too small?

```text
left++
```

### Why `left < right`?

To make sure two different elements are used.

### Time Complexity

```text
O(n)
```

### Space Complexity

```text
O(n)
```

---

# 📚 Related DSA Topics

- Binary Search Tree
- Binary Tree
- Inorder Traversal
- Recursion
- Two Sum
- Two-Pointer Technique
- Sorted Arrays
- Tree Searching
- Tree Traversal

---

# 🔗 Conclusion

The solution follows a clean two-step strategy:

```text
BST
 ↓
Inorder Traversal
 ↓
Sorted Vector
 ↓
Two Pointers
 ↓
Find Pair With Sum = k
```

The key observation is that a BST's inorder traversal is already sorted. This allows the classic Two Sum two-pointer technique to be applied efficiently.

The pointer rules are:

```text
sum == k → true
sum > k  → right--
sum < k  → left++
```

If no pair is found before the pointers meet, return `false`.

### Final Complexity

```text
Time Complexity  : O(n)
Space Complexity : O(n)
```

This is a clean and interview-ready solution for **LeetCode 653 — Two Sum IV: Input is a BST**.

---

# ⭐ Quick Revision

```text
             BST
              |
              ↓
       Inorder Traversal
              |
              ↓
        Sorted Vector
              |
       ┌──────┴──────┐
       ↓             ↓
    left = 0      right = n-1
       |             |
       └──────┬──────┘
              ↓
        left + right
              |
       ┌──────┼───────┐
       ↓      ↓       ↓
    == k     > k     < k
       |      |       |
     true   right--  left++
```

### Final Complexity

```text
Time  : O(n)
Space : O(n)
```
