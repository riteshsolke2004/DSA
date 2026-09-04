# 🔢 Two Sum
 
[LeetCode — Two Sum](https://leetcode.com/problems/two-sum/)

## Problem Statement 
 
Given an integer array `nums` and an integer `target`, return the **indices** of the two numbers such that they add up to the target.

### Conditions
 
* Each input has **exactly one solution**.
* You **cannot use the same element twice**.
* The answer can be returned in **any order**.

--- 
 
# Example 1

### Input

```text
nums = [2, 7, 11, 15]
target = 9
```

### Output

```text
[0, 1]
```

### Explanation

```text
nums[0] + nums[1]
= 2 + 7
= 9
```

Therefore:

```text
[0, 1]
```

---

# Example 2

### Input

```text
nums = [3, 2, 4]
target = 6
```

### Output

```text
[1, 2]
```

### Explanation

```text
nums[1] + nums[2]
= 2 + 4
= 6
```

---

# Example 3

### Input

```text
nums = [3, 3]
target = 6
```

### Output

```text
[0, 1]
```

### Explanation

```text
3 + 3 = 6
```

Even though the values are the same, they are located at different indices.

---

# Approach 1 — Brute Force

The simplest approach is to check **every possible pair**.

For every index `i`, check all elements after it using index `j`.

If:

```cpp
nums[i] + nums[j] == target
```

then return:

```cpp
{i, j}
```

---

## Algorithm

1. Start from the first element.
2. For every `i`, check all elements after `i`.
3. Calculate:

```cpp
sum = nums[i] + nums[j];
```

4. If `sum == target`, return `{i, j}`.
5. If no pair is found, return an empty vector.

---

## Brute Force Code

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();

        for(int i = 0; i < n; i++) {

            for(int j = i + 1; j < n; j++) {

                int sum = nums[i] + nums[j];

                if(sum == target) {
                    return {i, j};
                }
            }
        }

        return {};
    }
};
```

---

# Brute Force Dry Run

Consider:

```text
nums = [3, 2, 4]
target = 6
```

### Step 1

```text
i = 0
nums[i] = 3
```

Check:

```text
3 + 2 = 5 ❌
3 + 4 = 7 ❌
```

No answer.

---

### Step 2

```text
i = 1
nums[i] = 2
```

Check:

```text
2 + 4 = 6 ✅
```

Therefore:

```text
return [1,2]
```

---

# Complexity — Brute Force

For every element, we may check every other element.

### Time Complexity

```text
O(N²)
```

### Space Complexity

```text
O(1)
```

---

# Approach 2 — Optimal Hash Map

The brute-force approach checks many unnecessary pairs.

We can improve it using:

```cpp
unordered_map<int, int>
```

The idea is to store:

```text
number → index
```

while traversing the array.

For every number:

```text
nums[i]
```

we calculate its required partner:

```text
complement = target - nums[i]
```

Then we check whether the complement already exists in the hash map.

---

# Why Does Complement Work?

Suppose:

```text
target = 9
nums[i] = 2
```

We need:

```text
2 + ? = 9
```

Therefore:

```text
? = 9 - 2
  = 7
```

So:

```text
complement = target - nums[i]
```

If `7` already exists in the map, we found the answer.

---

# Optimal Algorithm

For every element:

### Step 1

Calculate:

```cpp
int complement = target - nums[i];
```

### Step 2

Check whether the complement exists:

```cpp
mp.find(complement)
```

### Step 3

If it exists, return:

```cpp
{mp[complement], i}
```

### Step 4

Otherwise store the current number:

```cpp
mp[nums[i]] = i;
```

---

# Optimal C++ Solution

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++) {

            int complement = target - nums[i];

            if(mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};
```

---

# Detailed Dry Run — Optimal Solution

Consider:

```text
nums = [2, 7, 11, 15]
target = 9
```

Initially:

```text
mp = {}
```

---

## Iteration 1

```text
i = 0
nums[i] = 2
```

Calculate:

```text
complement = 9 - 2
            = 7
```

Check:

```text
Is 7 in map?
```

No.

So store:

```text
mp[2] = 0
```

Map:

```text
{2 → 0}
```

---

## Iteration 2

```text
i = 1
nums[i] = 7
```

Calculate:

```text
complement = 9 - 7
            = 2
```

Check:

```text
Is 2 in map?
```

Yes!

Map contains:

```text
2 → 0
```

Therefore:

```text
return {0,1}
```

Final answer:

```text
[0,1]
```

---

# Visual Explanation

```text
nums = [2, 7, 11, 15]
        ↑
        i

target = 9
```

For `2`:

```text
9 - 2 = 7
```

Store:

```text
2 → index 0
```

Next element:

```text
7
```

Required value:

```text
9 - 7 = 2
```

`2` already exists:

```text
2 → index 0
```

Therefore:

```text
[0,1]
```

---

# Dry Run — Example 2

```text
nums = [3,2,4]
target = 6
```

Initially:

```text
mp = {}
```

### i = 0

```text
nums[i] = 3
complement = 6 - 3
            = 3
```

`3` is not in map.

Store:

```text
3 → 0
```

Map:

```text
{3 → 0}
```

---

### i = 1

```text
nums[i] = 2
complement = 6 - 2
            = 4
```

`4` is not in map.

Store:

```text
2 → 1
```

Map:

```text
{3 → 0, 2 → 1}
```

---

### i = 2

```text
nums[i] = 4
complement = 6 - 4
            = 2
```

`2` exists in map:

```text
2 → 1
```

Therefore:

```text
return {1,2}
```

Final answer:

```text
[1,2]
```

---

# Why Do We Check Before Inserting?

This is important.

We do:

```cpp
if(mp.find(complement) != mp.end())
```

before:

```cpp
mp[nums[i]] = i;
```

This prevents using the **same element twice**.

For example:

```text
nums = [3]
target = 6
```

At `i = 0`:

```text
complement = 6 - 3
            = 3
```

The map is empty, so we don't find `3`.

Then we store:

```text
3 → 0
```

The algorithm ends.

It doesn't incorrectly return:

```text
[0,0]
```

---

# Example 3 — Duplicate Values

Consider:

```text
nums = [3,3]
target = 6
```

### i = 0

```text
complement = 6 - 3
            = 3
```

Map doesn't contain `3`.

Store:

```text
3 → 0
```

---

### i = 1

```text
complement = 6 - 3
            = 3
```

Map contains:

```text
3 → 0
```

Therefore:

```text
return {0,1}
```

Correct.

---

# Brute Force vs Optimal

| Approach    |           Time |  Space |
| ----------- | -------------: | -----: |
| Brute Force |        `O(N²)` | `O(1)` |
| Hash Map    | `O(N)` average | `O(N)` |

The **Hash Map approach is optimal** for the standard Two Sum problem.

---

# Why Hash Map is Faster

### Brute Force

Checks pairs:

```text
(0,1)
(0,2)
(0,3)
(1,2)
(1,3)
...
```

This can require approximately:

```text
N²
```

comparisons.

---

### Hash Map

Each element is processed once:

```text
Calculate complement
        ↓
Check map
        ↓
Store element
```

Hash-map lookup is **O(1) average**, giving:

```text
O(N)
```

overall.

---

# Important C++ Functions

### `unordered_map`

```cpp
unordered_map<int, int> mp;
```

Stores:

```text
key → value
```

Here:

```text
number → index
```

Example:

```cpp
mp[2] = 0;
```

means:

```text
Number 2 is present at index 0.
```

---

### `find()`

```cpp
mp.find(x)
```

checks whether `x` exists.

If found:

```cpp
mp.find(x) != mp.end()
```

If not found:

```cpp
mp.find(x) == mp.end()
```

---

# Common Mistakes

### ❌ Mistake 1 — Using Same Element

Don't return:

```text
[i,i]
```

The same element cannot be used twice.

---

### ❌ Mistake 2 — Sorting the Array

If you sort the array:

```text
[2,7,11,15]
```

you may lose the original indices.

Since the problem asks for indices, sorting requires extra work to preserve them.

The hash-map solution avoids this.

---

### ❌ Mistake 3 — Inserting Before Checking

Prefer:

```cpp
if(mp.find(complement) != mp.end()) {
    return {mp[complement], i};
}

mp[nums[i]] = i;
```

This correctly handles duplicate values.

---

# Key Concepts

* Arrays
* Hash Map
* `unordered_map`
* Complement
* Index Tracking
* Average `O(1)` Lookup
* Brute Force
* Optimization

---

# Interview Explanation

If asked to explain the optimal approach:

> "For every element, I calculate the complement as `target - nums[i]`. I maintain an unordered map storing each previously visited number and its index. If the complement is already present, I return its stored index and the current index. Otherwise, I store the current number and continue. This gives an average time complexity of `O(N)` and space complexity of `O(N)`."

---

# Quick Revision

Remember this formula:

```text
complement = target - current element
```

Then:

```text
        Current Number
               ↓
       target - current
               ↓
          Complement
               ↓
       Is it in map?
          ↙       ↘
        YES        NO
         ↓          ↓
      Return      Store
      indices     number
```

---

# Final Recommended Code

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++) {

            int complement = target - nums[i];

            if(mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};
```

---

# Summary

| Feature             | Brute Force  | Hash Map       |
| ------------------- | ------------ | -------------- |
| Technique           | Nested Loops | Hashing        |
| Time                | `O(N²)`      | `O(N)` average |
| Space               | `O(1)`       | `O(N)`         |
| Easy to Understand  | ✅            | ✅              |
| Interview Preferred | ❌            | ✅              |
| Best Choice         | ❌            | ⭐              |

## 🧠 Remember

The entire optimal solution comes down to one idea:

```text
target - current = required number
```

For:

```text
nums = [2,7,11,15]
target = 9
```

we get:

```text
9 - 2 = 7
```

When `7` appears, we already know where `2` was.

That's the whole trick behind **Two Sum in O(N)**. 🚀
