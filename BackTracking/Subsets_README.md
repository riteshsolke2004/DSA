# 🔢 78. Subsets

## Problem Statement

Given an integer array `nums` of **unique** elements, return all possible **subsets** of the array. The collection of all subsets is called the **Power Set**.

### Important Points

- Every element can either be **included** or **excluded**.
- The empty subset `[]` must be included.
- No duplicate subsets are allowed.
- The answer can be returned in any order.
- For `n` elements, there are exactly `2ⁿ` possible subsets.

---

# Examples

## Example 1

### Input

```text
nums = [1,2,3]
```

### Output

```text
[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
```

### Explanation

Each element has two choices: include it or exclude it.

```text
Total subsets = 2³ = 8
```

---

## Example 2

### Input

```text
nums = [0]
```

### Output

```text
[[],[0]]
```

### Explanation

The two possible subsets are:

```text
[]
[0]
```

---

# 💡 Approach: Recursion + Backtracking

The provided solution uses the classic **Include / Exclude** recursion pattern.

For every element:

```text
                 nums[i]
                /                  Exclude      Include
```

The algorithm explores both possibilities for every element until all elements have been processed.

---

# 💻 Provided C++ Solution

```cpp
class Solution {
public:

    void solve(int i, vector<int>& nums, 
    vector<int> &currSubset, vector<vector<int>> &ans) {

        if(i == nums.size()) {
            ans.push_back(currSubset);
            return;
        }

        solve(i + 1, nums, currSubset, ans);

        currSubset.push_back(nums[i]);

        solve(i + 1, nums, currSubset, ans);

        currSubset.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int> currSubset;
        vector<vector<int>> ans;

        int index = 0;
        solve(index, nums, currSubset, ans);

        return ans;
    }
};
```

---

# 🧠 Code Explanation

## 1. `currSubset`

```cpp
vector<int> currSubset;
```

This stores the subset currently being created.

For example:

```text
[]
[1]
[1, 2]
```

---

## 2. `ans`

```cpp
vector<vector<int>> ans;
```

This stores every completed subset.

---

## 3. Base Case

```cpp
if(i == nums.size()) {
    ans.push_back(currSubset);
    return;
}
```

When `i` reaches the size of the array, every element has already been either:

```text
Included
OR
Excluded
```

Therefore, the current subset is complete and is stored in `ans`.

---

## 4. Exclude the Current Element

```cpp
solve(i + 1, nums, currSubset, ans);
```

Here, `nums[i]` is not added to `currSubset`.

This represents:

```text
Don't take nums[i]
```

---

## 5. Include the Current Element

```cpp
currSubset.push_back(nums[i]);

solve(i + 1, nums, currSubset, ans);
```

This represents:

```text
Take nums[i]
```

The recursion then explores all subsets containing that element.

---

## 6. Backtracking

After exploring the include case:

```cpp
currSubset.pop_back();
```

The current element is removed.

The pattern is:

```text
Choose
  ↓
Explore
  ↓
Undo
```

This is called **Backtracking**.

---

# 🌳 Recursion Tree

For:

```text
nums = [1, 2, 3]
```

Each element creates two choices:

```text
                         []
                       /                     Exclude 1  Include 1
                    []          [1]
                  /   \        /                  Ex 2   In 2   Ex 2  In 2
```

Continuing this for every element creates:

```text
2³ = 8 subsets
```

The possible subsets are:

```text
[]
[3]
[2]
[2,3]
[1]
[1,3]
[1,2]
[1,2,3]
```

The order may differ because the problem allows any order.

---

# 🔍 Detailed Dry Run

Consider:

```text
nums = [1, 2, 3]
```

Initially:

```text
i = 0
currSubset = []
```

## Step 1: Exclude `1`

```text
currSubset = []
```

Move to index `1`.

---

## Step 2: Exclude `2`

```text
currSubset = []
```

Move to index `2`.

---

## Step 3: Exclude `3`

Now:

```text
i == nums.size()
```

Store:

```text
[]
```

---

## Step 4: Include `3`

```cpp
currSubset.push_back(3);
```

Current subset:

```text
[3]
```

Store `[3]`.

Then backtrack:

```cpp
currSubset.pop_back();
```

Current subset becomes:

```text
[]
```

---

## Step 5: Include `2`

Current subset:

```text
[2]
```

The recursion generates:

```text
[2]
[2,3]
```

Then `2` is removed during backtracking.

---

## Step 6: Include `1`

Current subset:

```text
[1]
```

The recursion generates:

```text
[1]
[1,3]
[1,2]
[1,2,3]
```

All possible subsets are eventually stored.

---

# 🔄 Algorithm

```text
1. Create currSubset and ans.

2. Start recursion from index 0.

3. For every nums[i]:

       Choice 1:
           Exclude nums[i].

       Choice 2:
           Include nums[i].

4. If all elements are processed:
       Add currSubset to ans.

5. After exploring the include branch:
       Remove the element using pop_back().

6. Return ans.
```

---

# 🔄 Flow Diagram

```text
Start
  |
  v
solve(0, [], ans)
  |
  v
i == nums.size()?
  |
 Yes -----------------> Store currSubset
  |                         |
 No                        Return
  |
  v
Exclude nums[i]
  |
  v
Recursive Call
  |
  v
Include nums[i]
  |
  v
push_back(nums[i])
  |
  v
Recursive Call
  |
  v
pop_back()
  |
  v
Return
```

---

# 🔙 Why Backtracking is Needed

The same `currSubset` vector is reused throughout recursion.

For example:

```text
[1]
```

After including `2`:

```text
[1,2]
```

Once that branch is completely explored, we must remove `2` before trying another possibility.

```cpp
currSubset.pop_back();
```

restores the previous state.

---

# ⚠️ Important Edge Cases

## 1. Single Element

```text
nums = [0]
```

Output:

```text
[]
[0]
```

## 2. Empty Array

An empty array has one valid subset:

```text
[]
```

## 3. Unique Elements

The problem guarantees unique elements, so duplicate subsets are not generated.

---

# ⏱️ Complexity Analysis

For `n` elements, every element has two choices:

```text
Include
Exclude
```

Therefore:

```text
Number of subsets = 2ⁿ
```

## Time Complexity

```text
O(n × 2ⁿ)
```

There are `2ⁿ` subsets, and copying a subset can take up to `O(n)` time.

## Auxiliary Space Complexity

```text
O(n)
```

This is used by:

- The recursion stack.
- `currSubset`.

## Output Space

```text
O(n × 2ⁿ)
```

because all subsets are stored.

---

# 🎯 Key Concepts

- Recursion
- Backtracking
- Include / Exclude Pattern
- Decision Tree
- Power Set

---

# 🧠 Interview Notes

### Why are there `2ⁿ` subsets?

Every element has two choices:

```text
Take
Don't Take
```

For `n` elements:

```text
2 × 2 × 2 ... = 2ⁿ
```

### Why is `pop_back()` important?

```cpp
currSubset.pop_back();
```

undoes the previous choice and restores the subset before exploring another recursive branch.

### Why is the base case `i == nums.size()`?

Because every element has already been processed.

Each element is either:

```text
Included
OR
Excluded
```

So one complete subset is ready.

---

# ⭐ Quick Revision

```text
For every element:

    Choice 1:
        Exclude

    Choice 2:
        Include

Base Case:
    Store currSubset

For Include:
    push_back()
    recurse
    pop_back()
```

---

# 📚 Related DSA Topics

- Recursion
- Backtracking
- Subsequences
- Power Set
- Combination Problems
- Permutations

---

# 🔗 Conclusion

The provided solution uses the **Include / Exclude Recursion** technique to generate every possible subset.

For each element:

```text
Don't Take
    OR
Take
```

The recursion explores both choices, and:

```cpp
currSubset.pop_back();
```

performs the backtracking step to restore the previous state.

## Final Complexity

```text
Time Complexity      : O(n × 2ⁿ)
Auxiliary Space      : O(n)
Output Space         : O(n × 2ⁿ)
```

This is a clean, standard, and interview-friendly approach for generating the **Power Set**.
