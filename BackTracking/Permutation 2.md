# 🔢 47. Permutations II

## Problem Statement

Given a collection of integers `nums` that may contain **duplicates**, return all possible **unique permutations**.

A permutation is an arrangement of all elements of the array.

The answer can be returned in **any order**.

### What is Given? 

- An integer array `nums`.
- The array may contain duplicate values.

### What Needs to Be Returned?

Return all possible **unique permutations** of `nums`.

### Important Condition

Duplicate permutations must appear only once in the final answer.

---

# Examples

## Example 1

### Input

```text
nums = [1,1,2]
```

### Output

```text
[[1,1,2],
 [1,2,1],
 [2,1,1]]
```

### Explanation

Although there are `3! = 6` possible swapping arrangements, duplicate values create repeated permutations.

The unique permutations are:

```text
[1,1,2]
[1,2,1]
[2,1,1]
```

---

## Example 2

### Input

```text
nums = [1,2,3]
```

### Output

```text
[[1,2,3],
 [1,3,2],
 [2,1,3],
 [2,3,1],
 [3,1,2],
 [3,2,1]]
```

### Explanation

All elements are distinct, so all `3! = 6` permutations are unique.

---

# 💡 Approach: Backtracking + Set

The provided solution uses:

- **Backtracking**
- **Swapping**
- `set<vector<int>>` to store only unique permutations

The algorithm generates permutations by swapping elements.

Since duplicate values can produce the same permutation multiple times, every complete permutation is inserted into a `set`.

A `set` automatically removes duplicates.

---

# 🧠 Main Idea

For every position `start`:

```text
Try every element from start to n - 1
        |
        v
Swap it with nums[start]
        |
        v
Recursively generate the remaining permutation
        |
        v
Swap back
        |
        v
Try the next element
```

When a complete permutation is formed:

```cpp
if(start == nums.size()) {
    st.insert(nums);
    return;
}
```

The `set` ensures that duplicate permutations are stored only once.

---

# 💻 Provided C++ Solution

```cpp
class Solution {
public:

    void solve(int start, vector<vector<int>>& ans,
               vector<int>& nums, set<vector<int>>& st) {

        if(start == nums.size()) {
            st.insert(nums);
            return;
        }

        for(int j = start; j < nums.size(); j++) {
            swap(nums[start], nums[j]);

            solve(start + 1, ans, nums, st);

            swap(nums[start], nums[j]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<vector<int>> ans;
        int i = 0;

        set<vector<int>> st;

        solve(i, ans, nums, st);

        for(auto i : st) {
            ans.push_back(i);
        }

        return ans;
    }
};
```

---

# 🧩 Understanding the Code

## Step 1: Start Backtracking

```cpp
solve(i, ans, nums, st);
```

Initially:

```text
i = 0
```

So we start filling the permutation from the first index.

---

## Step 2: Base Case

```cpp
if(start == nums.size()) {
    st.insert(nums);
    return;
}
```

When:

```text
start == nums.size()
```

every position has been fixed.

The current `nums` array is a complete permutation.

It is inserted into:

```cpp
set<vector<int>> st
```

If the same permutation was already generated, the `set` ignores the duplicate.

---

## Step 3: Try Every Possible Element

```cpp
for(int j = start; j < nums.size(); j++)
```

For the current position `start`, every remaining element is tried.

---

## Step 4: Make a Choice

```cpp
swap(nums[start], nums[j]);
```

This places the selected element at the current position.

---

## Step 5: Recursive Call

```cpp
solve(start + 1, ans, nums, st);
```

Now the next position is processed.

---

## Step 6: Backtrack

```cpp
swap(nums[start], nums[j]);
```

This restores the array to its previous state before trying the next possibility.

---

# 🔍 Detailed Dry Run

Consider:

```text
nums = [1,1,2]
```

Initially:

```text
start = 0
nums = [1,1,2]
```

## First Branch

Swap:

```text
swap(0,0)
```

Array:

```text
[1,1,2]
```

Generate:

```text
[1,1,2]
[1,2,1]
```

---

## Second Branch

Swap:

```text
swap(0,1)
```

The array is still:

```text
[1,1,2]
```

Because both values are `1`.

This generates the same permutations again:

```text
[1,1,2]
[1,2,1]
```

But the `set` stores them only once.

---

## Third Branch

Swap:

```text
swap(0,2)
```

Array:

```text
[2,1,1]
```

This generates:

```text
[2,1,1]
```

---

## Final Set

The unique permutations stored are:

```text
[1,1,2]
[1,2,1]
[2,1,1]
```

---

# 🌳 Recursion Tree

For:

```text
nums = [1,1,2]
```

```text
solve(0)
│
├── swap(0,0) → [1,1,2]
│   ├── swap(1,1) → [1,1,2]
│   │   └── [1,1,2]
│   │
│   └── swap(1,2) → [1,2,1]
│       └── [1,2,1]
│
├── swap(0,1) → [1,1,2]
│   ├── Generates duplicate [1,1,2]
│   └── Generates duplicate [1,2,1]
│
└── swap(0,2) → [2,1,1]
    └── [2,1,1]
```

The `set` removes the repeated permutations.

---

# 🔙 Why Backtracking Is Necessary

The important pattern is:

```cpp
swap(nums[start], nums[j]);

solve(start + 1, ans, nums, st);

swap(nums[start], nums[j]);
```

```text
Choose
   ↓
Explore
   ↓
Undo the choice
   ↓
Try another choice
```

The second swap restores the array before the next iteration.

---

# 📦 Why Use a Set?

The input can contain duplicates.

For example:

```text
nums = [1,1,2]
```

Different swap operations can generate the same permutation.

Example:

```text
[1,1,2]
```

may be generated more than once.

Using:

```cpp
set<vector<int>> st;
```

ensures that only unique permutations remain.

---

# ⚠️ Important Observation About the Provided Code

The parameter:

```cpp
vector<vector<int>>& ans
```

is passed to `solve()`, but it is not used inside the recursive function.

The actual storage of permutations happens in:

```cpp
set<vector<int>> st
```

This is **not an error**, and the code works correctly. However, the `ans` parameter is unnecessary inside `solve()`.

A cleaner version would remove `ans` from the recursive function parameters.

---

# ✨ Cleaner Version of the Same Approach

```cpp
class Solution {
public:
    void solve(int start, vector<int>& nums, set<vector<int>>& st) {
        if(start == nums.size()) {
            st.insert(nums);
            return;
        }

        for(int j = start; j < nums.size(); j++) {
            swap(nums[start], nums[j]);

            solve(start + 1, nums, st);

            swap(nums[start], nums[j]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> st;

        solve(0, nums, st);

        return vector<vector<int>>(st.begin(), st.end());
    }
};
```

This uses the same:

```text
Backtracking + Swapping + Set
```

approach as the provided solution.

---

# ⏱️ Complexity Analysis

Let:

```text
n = nums.size()
```

In the worst case, the algorithm explores up to:

```text
n!
```

permutation branches.

## Time Complexity

Generating permutations:

```text
O(n × n!)
```

Additionally, inserting vectors into a `set` involves comparison overhead.

So the practical complexity has extra logarithmic and comparison costs.

A reasonable upper-bound description is:

```text
O(n × n! × log(n!))
```

for the set-based storage in the worst case.

## Space Complexity

### Recursion Stack

```text
O(n)
```

### Set and Output

In the worst case, storing all permutations requires:

```text
O(n × n!)
```

Therefore:

```text
Space Complexity: O(n × n!)
```

including stored permutations.

---

# 🚨 Common Mistakes

## Mistake 1: Forgetting to Backtrack

Incorrect:

```cpp
swap(nums[start], nums[j]);
solve(start + 1, nums, st);
```

Correct:

```cpp
swap(nums[start], nums[j]);
solve(start + 1, nums, st);
swap(nums[start], nums[j]);
```

---

## Mistake 2: Pushing Directly Into the Answer

If duplicates are possible:

```cpp
ans.push_back(nums);
```

may store the same permutation multiple times.

The provided approach avoids this using:

```cpp
set<vector<int>>
```

---

## Mistake 3: Not Handling Duplicate Permutations

For:

```text
[1,1,2]
```

simple swapping generates repeated branches.

A mechanism is needed to ensure uniqueness.

The provided solution uses a `set`.

---

# 🎯 Key Concepts

- Arrays
- Recursion
- Backtracking
- Swapping
- Sets
- Unique Permutations

---

# 🧠 Interview Notes

### What technique is used?

```text
Backtracking
```

### How are duplicate permutations removed?

Using:

```cpp
set<vector<int>>
```

### Why do we swap back?

To restore the previous state before exploring another branch.

### What is the recursion depth?

```text
O(n)
```

### Is this the most optimized approach?

Not necessarily.

This solution correctly generates all permutations and removes duplicates using a `set`, but an optimized approach can skip duplicate choices at each recursion level and avoid generating repeated permutations in the first place.

---

# ⭐ Quick Revision

```text
solve(start):

    if start == n:
        insert nums into set
        return

    for j from start to n - 1:

        swap(nums[start], nums[j])

        solve(start + 1)

        swap(nums[start], nums[j])
```

Finally:

```text
Copy all unique permutations from the set into ans.
```

---

# 📚 Related DSA Topics

- Recursion
- Backtracking
- Permutations
- Sets
- Arrays
- Duplicate Handling

---

# 🔗 Conclusion

The provided solution solves **Permutations II** using:

```text
Backtracking + Swapping + Set
```

The process is:

```text
1. Generate permutations using swapping.
2. Recursively fix every position.
3. Backtrack after every recursive call.
4. Insert complete permutations into a set.
5. Copy the unique permutations into the answer vector.
```

## Final Complexity

```text
Time Complexity  : O(n × n! × log(n!)) in the worst case
Auxiliary Space  : O(n) for recursion
Stored Output    : O(n × n!)
```

This is a correct and beginner-friendly approach for understanding how **Backtracking** can be combined with a `set` to handle duplicate permutations.
