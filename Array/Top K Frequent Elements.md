# 🔥 347. Top K Frequent Elements

## Problem Statement

Given an integer array `nums` and an integer `k`, return the `k` most frequent elements.

You may return the answer in **any order**.

### What is Given?

- An integer array `nums`.
- An integer `k`.

### What Needs to Be Returned?

Return exactly `k` elements that occur most frequently in the array.

### Important Conditions

- The answer can be returned in **any order**.
- Frequency means the number of times an element appears in the array.

---

# Examples

## Example 1

### Input

```text
nums = [1,1,1,2,2,3]
k = 2
```

### Output

```text
[1,2]
```

### Explanation

Frequency of each element:

```text
1 → 3 times
2 → 2 times
3 → 1 time
```

The two most frequent elements are:

```text
[1,2]
```

---

## Example 2

### Input

```text
nums = [1]
k = 1
```

### Output

```text
[1]
```

### Explanation

Only one element exists, so the top `1` frequent element is:

```text
[1]
```

---

## Example 3

### Input

```text
nums = [1,2,1,2,1,2,3,1,3,2]
k = 2
```

### Output

```text
[1,2]
```

### Explanation

Frequency of each element:

```text
1 → 4 times
2 → 4 times
3 → 2 times
```

The two most frequent elements are:

```text
[1,2]
```

---

# 💡 Approach

The provided solution uses:

1. **HashMap** to count frequencies.
2. A **vector of pairs** to store:
   ```text
   {frequency, element}
   ```
3. **Sorting in descending order** based on frequency.
4. Selecting the first `k` elements.

---

# 🧠 Step-by-Step Explanation

## Step 1: Count Frequency Using HashMap

```cpp
unordered_map<int, int> mp;
```

Traverse the array and count each number:

```cpp
for(int num : nums) {
    mp[num]++;
}
```

For:

```text
nums = [1,1,1,2,2,3]
```

The map becomes:

```text
1 → 3
2 → 2
3 → 1
```

---

## Step 2: Store Frequency and Element in a Vector

The code creates:

```cpp
vector<pair<int, int>> v;
```

Each pair stores:

```text
{frequency, element}
```

```cpp
for(auto pair : mp) {
    v.push_back({pair.second, pair.first});
}
```

So the vector conceptually contains:

```text
[(3,1), (2,2), (1,3)]
```

Where:

```text
first  → frequency
second → element
```

---

## Step 3: Sort in Descending Order

```cpp
sort(v.rbegin(), v.rend());
```

`rbegin()` and `rend()` sort the vector in descending order.

The highest frequencies come first:

```text
[(3,1), (2,2), (1,3)]
```

Since the pair stores frequency first, sorting prioritizes the frequency.

---

## Step 4: Take the First `k` Elements

```cpp
vector<int> ans;

for(int i = 0; i < k; i++) {
    ans.push_back(v[i].second);
}
```

For:

```text
k = 2
```

Take:

```text
v[0].second = 1
v[1].second = 2
```

Result:

```text
[1,2]
```

---

# 🔄 Complete Flow

```text
nums
  |
  v
Count frequencies using HashMap
  |
  v
{element → frequency}
  |
  v
Store as {frequency, element}
  |
  v
Sort in descending order
  |
  v
Take first k elements
  |
  v
Answer
```

---

# 🔍 Dry Run

Consider:

```text
nums = [1,1,1,2,2,3]
k = 2
```

## Step 1: Frequency Map

| Element | Frequency |
|---|---:|
| 1 | 3 |
| 2 | 2 |
| 3 | 1 |

```text
mp = {
    1 → 3,
    2 → 2,
    3 → 1
}
```

---

## Step 2: Create Vector of Pairs

```text
v = [
    {3,1},
    {2,2},
    {1,3}
]
```

Format:

```text
{frequency, element}
```

---

## Step 3: Sort Descending

```cpp
sort(v.rbegin(), v.rend());
```

Result:

```text
[{3,1}, {2,2}, {1,3}]
```

---

## Step 4: Select First `k = 2` Elements

```text
v[0].second = 1
v[1].second = 2
```

Therefore:

```text
ans = [1,2]
```

---

# 💻 Provided C++ Solution

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        for(int num : nums) {
            mp[num]++;
        }

        vector<pair<int, int>> v;

        for(auto pair : mp) {
            v.push_back({pair.second, pair.first});
        }

        sort(v.rbegin(), v.rend());

        vector<int> ans;

        for(int i = 0; i < k; i++) {
            ans.push_back(v[i].second);
        }

        return ans;
    }
};
```

---

# 🧩 Recursion Tree

This solution does **not** use recursion.

Therefore:

```text
Recursion Tree: Not Applicable
```

Instead, the solution uses:

```text
Hashing + Vector + Sorting
```

---

# 📊 Complexity Analysis

Let:

```text
n = size of nums
m = number of unique elements
```

Since `m ≤ n`:

## Time Complexity

### Frequency Counting

```text
O(n)
```

### Creating the Vector

```text
O(m)
```

### Sorting the Vector

```text
O(m log m)
```

### Taking the First `k` Elements

```text
O(k)
```

### Overall

```text
O(n + m log m + k)
```

In the worst case, when all elements are unique:

```text
O(n log n)
```

---

## Space Complexity

The HashMap stores up to `m` unique elements.

The vector also stores up to `m` pairs.

```text
Space Complexity: O(m)
```

Worst case:

```text
O(n)
```

---

# ⚠️ Important Points

## Why Store `{frequency, element}`?

```cpp
v.push_back({pair.second, pair.first});
```

The pair is stored as:

```text
{frequency, element}
```

This is important because `sort()` compares the first value first.

So sorting naturally prioritizes:

```text
Higher frequency
```

---

## Why Use `rbegin()` and `rend()`?

```cpp
sort(v.rbegin(), v.rend());
```

This sorts in descending order.

Example:

```text
Before:
(1,3), (3,1), (2,2)

After:
(3,1), (2,2), (1,3)
```

The most frequent elements are placed at the beginning.

---

## Why Use `.second`?

Each pair has:

```text
pair.first  → frequency
pair.second → element
```

So:

```cpp
ans.push_back(v[i].second);
```

adds the actual element to the answer.

---

# 🚨 Common Mistakes

## Mistake 1: Storing `{element, frequency}`

If you write:

```cpp
v.push_back({pair.first, pair.second});
```

then normal sorting will prioritize the element value instead of its frequency.

The provided code correctly uses:

```cpp
v.push_back({pair.second, pair.first});
```

---

## Mistake 2: Returning the Frequency Instead of the Element

This would be incorrect:

```cpp
ans.push_back(v[i].first);
```

Because `.first` stores the frequency.

The correct code is:

```cpp
ans.push_back(v[i].second);
```

---

## Mistake 3: Forgetting Descending Order

This:

```cpp
sort(v.begin(), v.end());
```

sorts in ascending order.

The provided solution correctly uses:

```cpp
sort(v.rbegin(), v.rend());
```

to place the highest frequencies first.

---

# 🏆 Key Concepts

- Arrays
- HashMap
- `unordered_map`
- Frequency Counting
- `vector`
- `pair`
- Sorting
- Reverse Iterators

---

# 🧠 Interview Notes

### What does `unordered_map` store here?

```text
Element → Frequency
```

### What does the vector store?

```text
{Frequency, Element}
```

### Why is frequency stored first?

Because sorting pairs compares the first value first.

### Why use reverse iterators?

```cpp
sort(v.rbegin(), v.rend());
```

to sort in descending order.

### What is the worst-case time complexity?

```text
O(n log n)
```

because of sorting.

---

# 🎯 Alternative Optimization

The provided solution sorts all unique elements.

A more optimized approach can use:

- Min Heap
- Bucket Sort

For example, Bucket Sort can solve the problem in:

```text
Time Complexity  : O(n)
Space Complexity : O(n)
```

However, the provided solution is clean, easy to understand, and correctly implements the:

```text
HashMap + Sorting
```

approach.

---

# ⭐ Quick Revision

```text
nums
  |
  v
Count frequency
  |
  v
unordered_map
  |
  v
Store {frequency, element}
  |
  v
Sort descending
  |
  v
Take first k elements
  |
  v
Return answer
```

For:

```text
nums = [1,1,1,2,2,3]
k = 2
```

```text
Frequency:
1 → 3
2 → 2
3 → 1

Sorted:
{3,1}
{2,2}
{1,3}

Answer:
[1,2]
```

---

# 📚 Related DSA Topics

- Arrays
- HashMap
- Frequency Counting
- Sorting
- Heap
- Priority Queue
- Bucket Sort
- Top K Problems

---

# 🔗 Conclusion

The solution follows a straightforward approach:

```text
1. Count every element using HashMap.
2. Store {frequency, element} pairs in a vector.
3. Sort the vector in descending order.
4. Return the first k elements.
```

## Final Complexity

```text
Time Complexity  : O(n log n) in the worst case
Space Complexity : O(n)
```

This approach is beginner-friendly, easy to implement, and a solid solution for understanding **frequency counting and Top K problems**.
