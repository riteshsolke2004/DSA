# 🔢 Subarrays with Sum K

## Problem Statement

Given an unsorted array `arr[]` of integers and an integer `k`, find the **number of subarrays** whose sum is exactly equal to `k`.

A **subarray** is a contiguous part of an array.

### What is Given?

- An integer array `arr[]`
- An integer `k`

### What Needs to Be Returned?

Return the total number of contiguous subarrays whose sum is exactly equal to `k`.

---

# Examples

## Example 1

### Input

```text
arr[] = [10, 2, -2, -20, 10], k = -10
```

### Output

```text
3
```

### Explanation

The following subarrays have sum `-10`:

```text
arr[0...3] = [10, 2, -2, -20]
arr[1...4] = [2, -2, -20, 10]
arr[3...4] = [-20, 10]
```

Therefore, the answer is:

```text
3
```

---

## Example 2

### Input

```text
arr[] = [9, 4, 20, 3, 10, 5], k = 33
```

### Output

```text
2
```

### Explanation

The valid subarrays are:

```text
arr[0...2] = [9, 4, 20]
arr[2...4] = [20, 3, 10]
```

Both have a sum equal to `33`.

---

## Example 3

### Input

```text
arr[] = [1, 3, 5], k = 0
```

### Output

```text
0
```

### Explanation

No subarray has a sum equal to `0`.

---

# 💡 Approach: Prefix Sum + HashMap

The provided solution uses:

- **Prefix Sum**
- **HashMap (`unordered_map`)**

Instead of generating every possible subarray, we store the frequency of previous prefix sums.

---

# 🧠 Core Idea

Suppose:

```text
prefixSum[j] = sum from index 0 to j
```

For a subarray from index `i + 1` to `j`:

```text
prefixSum[j] - prefixSum[i] = k
```

Rearranging:

```text
prefixSum[i] = prefixSum[j] - k
```

Therefore, when the current prefix sum is `sum`, we check whether:

```text
sum - k
```

has appeared previously.

If it appeared multiple times, every occurrence represents a valid subarray.

---

# 🔄 Approach Flow

```text
Array
  |
  v
Calculate Prefix Sum
  |
  v
Check (sum - k) in HashMap
  |
  +---- Found ----> Add its frequency to count
  |
  +---- Not Found -> Continue
  |
  v
Store current prefix sum
  |
  v
Return count
```

---

# 🧩 Why `mp[0] = 1`?

The code initializes:

```cpp
mp[0] = 1;
```

This represents a prefix sum of `0` before processing the array.

It allows us to count subarrays starting from index `0`.

Example:

```text
arr = [9, 4, 20]
k = 33
```

When:

```text
sum = 33
sum - k = 0
```

Since `mp[0] = 1`, the subarray `[9,4,20]` is counted.

---

# 🧠 Algorithm

1. Create an `unordered_map` for prefix sum frequencies.
2. Initialize `sum = 0` and `count = 0`.
3. Set `mp[0] = 1`.
4. Traverse the array.
5. Add the current element to `sum`.
6. Check whether `sum - k` exists.
7. Add its frequency to `count`.
8. Store the current prefix sum.
9. Return `count`.

---

# 💻 Provided C++ Solution

```cpp
class Solution {
public:
    int cntSubarrays(vector<int> &arr, int k) {

        unordered_map<int, int> mp;

        int sum = 0;
        int count = 0;

        mp[0] = 1;

        for(int i = 0; i < arr.size(); i++) {

            sum += arr[i];

            if(mp.find(sum - k) != mp.end()) {
                count += mp[sum - k];
            }

            mp[sum]++;
        }

        return count;
    }
};
```

---

# 🔍 Detailed Dry Run

Consider:

```text
arr = [10, 2, -2, -20, 10]
k = -10
```

Initial state:

```text
sum = 0
count = 0

mp = {
    0 → 1
}
```

| Index | Element | Current Sum | `sum - k` | Frequency Found | Count |
|---|---:|---:|---:|---:|---:|
| 0 | 10 | 10 | 20 | 0 | 0 |
| 1 | 2 | 12 | 22 | 0 | 0 |
| 2 | -2 | 10 | 20 | 0 | 0 |
| 3 | -20 | -10 | 0 | 1 | 1 |
| 4 | 10 | 0 | 10 | 2 | 3 |

Final answer:

```text
3
```

---

# 🔎 Understanding the Final Iteration

At index `4`:

```text
sum = 0
k = -10

sum - k = 0 - (-10)
        = 10
```

The prefix sum `10` appeared twice.

Therefore:

```cpp
count += mp[10];
```

```text
count = 1 + 2 = 3
```

The two additional valid subarrays are:

```text
[2, -2, -20, 10]
[-20, 10]
```

---

# 📊 Prefix Sum Visualization

```text
Index:        0    1    2    3    4
Array:       10    2   -2  -20   10
             -----------------------
Prefix Sum:  10   12   10  -10    0
```

The algorithm looks for:

```text
Previous Prefix Sum = Current Prefix Sum - k
```

---

# 🧩 Why Store Frequency?

The same prefix sum can occur multiple times.

Therefore, the HashMap stores:

```text
Prefix Sum → Frequency
```

This is why the solution uses:

```cpp
count += mp[sum - k];
```

instead of:

```cpp
count++;
```

Every previous occurrence can form a different valid subarray.

---

# 🧩 Recursion Tree

This solution does **not** use recursion.

```text
Recursion Tree: Not Applicable
```

The solution uses:

```text
Prefix Sum + HashMap
```

---

# ⏱️ Complexity Analysis

Let `n` be the size of the array.

## Time Complexity

The array is traversed once.

```text
Time Complexity: O(n)
```

HashMap operations take `O(1)` average time.

## Space Complexity

The HashMap can store up to `n + 1` prefix sums.

```text
Space Complexity: O(n)
```

---

# ⚠️ Important Points

## 1. Check Before Updating the Map

The correct order is:

```text
1. Update sum
2. Check sum - k
3. Add frequency to count
4. Store current sum
```

Equivalent code:

```cpp
sum += arr[i];

if(mp.find(sum - k) != mp.end()) {
    count += mp[sum - k];
}

mp[sum]++;
```

---

## 2. Negative Numbers Are Supported

This approach works correctly even when negative numbers exist.

Example:

```text
[10, 2, -2, -20, 10]
```

Because of negative values, a normal sliding window approach is not generally reliable.

---

## 3. Subarrays Starting From Index `0`

```cpp
mp[0] = 1;
```

ensures that such subarrays are counted.

---

# 🚨 Common Mistakes

## Forgetting `mp[0] = 1`

This can miss subarrays starting from index `0`.

## Adding Only `1`

Incorrect:

```cpp
count++;
```

Correct:

```cpp
count += mp[sum - k];
```

because the same required prefix sum may have appeared multiple times.

## Updating the Map Too Early

Always check for:

```text
sum - k
```

before increasing:

```cpp
mp[sum]++;
```

---

# 🎯 Key Concepts

- Arrays
- Subarrays
- Prefix Sum
- HashMap
- `unordered_map`
- Frequency Counting
- Cumulative Sum

---

# 🧠 Interview Notes

### What does the HashMap store?

```text
Prefix Sum → Number of occurrences
```

### Why check `sum - k`?

Because:

```text
Current Prefix Sum - Previous Prefix Sum = k
```

Therefore:

```text
Previous Prefix Sum = Current Prefix Sum - k
```

### What is the optimized approach?

```text
Prefix Sum + HashMap
```

---

# ⭐ Quick Revision

```text
Initialize:
sum = 0
count = 0
mp[0] = 1

For every element:
    sum += element

    if(sum - k exists):
        count += frequency of (sum - k)

    mp[sum]++

Return count
```

---

# 📚 Related DSA Topics

- Arrays
- Prefix Sum
- HashMap
- `unordered_map`
- Frequency Counting
- Subarrays

---

# 🔗 Conclusion

The provided solution efficiently counts all subarrays whose sum is exactly `k` using:

```text
Prefix Sum + HashMap
```

The key formula is:

```text
Current Prefix Sum - Previous Prefix Sum = k
```

Therefore:

```text
Previous Prefix Sum = Current Prefix Sum - k
```

By storing the frequency of every prefix sum, the solution counts all valid subarrays in a single traversal.

## Final Complexity

```text
Time Complexity  : O(n)
Space Complexity : O(n)
```
