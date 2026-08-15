# 🔢 Majority Element

## 📖 Problem Statement

Given an array `nums` of size `n`, return the **majority element**.

The majority element is the element that appears **more than ⌊n / 2⌋ times**.

You may assume that the majority element always exists in the array.

---

# 🧪 Examples

## Example 1

### Input

```text
nums = [3,2,3]
```

### Output

```text
3
```

### Explanation

`3` appears `2` times, which is more than `⌊3 / 2⌋ = 1`.

---

## Example 2

### Input

```text
nums = [2,2,1,1,1,2,2]
```

### Output

```text
2
```

### Explanation

`2` appears `4` times.

```text
⌊7 / 2⌋ = 3
4 > 3
```

Therefore, `2` is the majority element.

---

# 💡 Approaches Used

This repository includes four approaches:

1. Sorting + Middle Element
2. Sorting + Frequency Counting
3. Boyer-Moore Voting Algorithm
4. HashMap / Frequency Map

---

# 1️⃣ Sorting + Middle Element

## Intuition

After sorting, the majority element must occupy the middle index because it appears more than half of the array.

```text
[2,2,1,1,1,2,2]
        |
      Sort
        v
[1,1,1,2,2,2,2]
       ^
     n / 2
```

## Algorithm

1. Sort the array.
2. Return `nums[n / 2]`.

## Code

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans = nums[nums.size() / 2];

        return ans;
    }
};
```

## Dry Run

```text
nums = [2,2,1,1,1,2,2]

After sorting:
[1,1,1,2,2,2,2]

n = 7
n / 2 = 3

nums[3] = 2
```

### Complexity

```text
Time Complexity  : O(n log n)
Space Complexity : Depends on sorting implementation
```

---

# 2️⃣ Sorting + Frequency Counting

## Intuition

After sorting, equal elements become adjacent, so we can count consecutive occurrences.

## Algorithm

1. Sort the array.
2. Start with `freq = 1`.
3. Compare each element with the previous element.
4. Increase frequency if both are equal.
5. Reset frequency when the element changes.
6. Return the element when `freq > n / 2`.

## Code

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        int freq = 1;
        int ans = nums[0];

        for(int i = 1; i < n; i++) {

            if(nums[i] == nums[i - 1]) {
                freq++;
            }
            else {
                freq = 1;
                ans = nums[i];
            }

            if(freq > n / 2) {
                return ans;
            }
        }

        return ans;
    }
};
```

## Dry Run

```text
Sorted Array = [1,1,1,2,2,2,2]

1 → freq = 1
1 → freq = 2
1 → freq = 3

2 → reset freq = 1
2 → freq = 2
2 → freq = 3
2 → freq = 4

4 > 7 / 2

Answer = 2
```

### Complexity

```text
Time Complexity  : O(n log n)
Space Complexity : Depends on sorting implementation
```

---

# 3️⃣ Boyer-Moore Voting Algorithm ⭐

## Intuition

Maintain:

```text
ans  → current candidate
freq → vote count
```

Rules:

```text
If freq == 0:
    Choose current element as candidate

If current element == candidate:
    freq++

Otherwise:
    freq--
```

Different elements cancel each other out.

Because the problem guarantees that a majority element exists, the final candidate is the answer.

## Code

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        int freq = 0, ans = 0;

        for(int i = 0; i < n; i++) {

            if(freq == 0) {
                ans = nums[i];
            }

            if(nums[i] == ans) {
                freq++;
            }
            else {
                freq--;
            }
        }

        return ans;
    }
};
```

## Detailed Dry Run

```text
nums = [2,2,1,1,1,2,2]
```

| Element | Candidate | Action | Frequency |
|---|---:|---|---:|
| 2 | 2 | `freq++` | 1 |
| 2 | 2 | `freq++` | 2 |
| 1 | 2 | `freq--` | 1 |
| 1 | 2 | `freq--` | 0 |
| 1 | 1 | New candidate, `freq++` | 1 |
| 2 | 1 | `freq--` | 0 |
| 2 | 2 | New candidate, `freq++` | 1 |

Final answer:

```text
2
```

### Complexity

```text
Time Complexity  : O(n)
Space Complexity : O(1)
```

This is the most optimized approach among the provided solutions.

---

# 4️⃣ HashMap / Frequency Map

## Intuition

Store the frequency of every element using an `unordered_map`.

Example:

```text
nums = [2,2,1,1,1,2,2]

2 → 4
1 → 3
```

Return the element whose frequency is greater than `n / 2`.

## Code

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        unordered_map<int, int> mp;

        for(int num : nums) {
            mp[num]++;
        }

        for(auto &pair : mp) {
            if(pair.second > nums.size() / 2) {
                return pair.first;
            }
        }

        return 0;
    }
};
```

## Dry Run

```text
nums = [2,2,1,1,1,2,2]

Frequency Map:

2 → 4
1 → 3

n / 2 = 3

4 > 3

Answer = 2
```

### Complexity

```text
Average Time Complexity : O(n)
Space Complexity        : O(n)
```

---

# 📊 Comparison of All Approaches

| Approach | Time Complexity | Space Complexity | Main Idea |
|---|---:|---:|---|
| Sorting + Middle | `O(n log n)` | Depends on sorting | Majority occupies middle |
| Sorting + Frequency | `O(n log n)` | Depends on sorting | Count adjacent elements |
| Boyer-Moore Voting | `O(n)` | `O(1)` | Cancel different elements |
| HashMap | `O(n)` average | `O(n)` | Store frequencies |

---

# 🏆 Best Approach

The **Boyer-Moore Voting Algorithm** is the best optimized solution here:

```text
Time Complexity  : O(n)
Space Complexity : O(1)
```

It works directly because the problem guarantees that a majority element always exists.

---

# ⚠️ Important Note

If a majority element is **not guaranteed**, the final Boyer-Moore candidate should be verified by counting its frequency.

For this problem, verification is unnecessary.

---

# 🚨 Common Mistakes

## Using `>= n / 2`

The correct condition is:

```text
frequency > ⌊n / 2⌋
```

## Forgetting That Sorting Changes the Array

```cpp
sort(nums.begin(), nums.end());
```

modifies the original array.

## Using Boyer-Moore Without the Majority Guarantee

Without a guaranteed majority element, verify the final candidate.

---

# 💻 All Solutions Together

## Solution 1 — Sorting + Middle Element

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans = nums[nums.size() / 2];

        return ans;
    }
};
```

## Solution 2 — Sorting + Frequency Counting

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        int freq = 1;
        int ans = nums[0];

        for(int i = 1; i < n; i++) {

            if(nums[i] == nums[i - 1]) {
                freq++;
            }
            else {
                freq = 1;
                ans = nums[i];
            }

            if(freq > n / 2) {
                return ans;
            }
        }

        return ans;
    }
};
```

## Solution 3 — Boyer-Moore Voting Algorithm

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        int freq = 0, ans = 0;

        for(int i = 0; i < n; i++) {

            if(freq == 0) {
                ans = nums[i];
            }

            if(nums[i] == ans) {
                freq++;
            }
            else {
                freq--;
            }
        }

        return ans;
    }
};
```

## Solution 4 — HashMap

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        unordered_map<int, int> mp;

        for(int num : nums) {
            mp[num]++;
        }

        for(auto &pair : mp) {
            if(pair.second > nums.size() / 2) {
                return pair.first;
            }
        }

        return 0;
    }
};
```

---

# 🎯 Key Takeaways

- A majority element appears more than `⌊n / 2⌋` times.
- Sorting makes equal elements adjacent.
- After sorting, the majority element must occupy the middle index.
- HashMap stores the frequency of every element.
- Boyer-Moore cancels different elements.
- Boyer-Moore provides the best space complexity: `O(1)`.

---

# 📚 Related DSA Topics

- Arrays
- Sorting
- HashMap
- `unordered_map`
- Frequency Counting
- Boyer-Moore Voting Algorithm
- Searching

---

# ⭐ Quick Revision

```text
Majority Element
        |
        v
Appears more than n / 2 times
        |
        +-----------------------------+
        |             |               |
        v             v               v
      Sorting       HashMap       Boyer-Moore
        |             |               |
    O(n log n)      O(n)            O(n)
    Space varies    O(n)            O(1)
```

## Final Complexity Summary

```text
Sorting + Middle     : O(n log n)
Sorting + Frequency  : O(n log n)
HashMap              : O(n) average, O(n) space
Boyer-Moore Voting   : O(n) time, O(1) space
```
