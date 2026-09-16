# 🍎 904. Fruit Into Baskets

## Problem Statement

You are given an integer array `fruits`, where `fruits[i]` represents the fruit type produced by the `i`th tree.

You have exactly **two baskets**.

- Each basket can hold only one type of fruit.
- Each basket can hold unlimited fruits of its type.
- You may start at any tree.
- After starting, you move only to the right.
- You must pick exactly one fruit from every tree you visit.
- You must stop when the next fruit type cannot fit in either basket.

Return the **maximum number of fruits** you can collect.

### Key Observation

The problem is equivalent to finding the:

> **Longest contiguous subarray containing at most two distinct values.**

---

# Examples

## Example 1

### Input

```text
fruits = [1,2,1]
```

### Output

```text
3
```

### Explanation

All three trees can be collected because there are only two fruit types:

```text
1 and 2
```

---

## Example 2

### Input

```text
fruits = [0,1,2,2]
```

### Output

```text
3
```

### Explanation

Start from index `1`:

```text
[1,2,2]
```

Only two fruit types are used, so we can collect `3` fruits.

---

## Example 3

### Input

```text
fruits = [1,2,3,2,2]
```

### Output

```text
4
```

### Explanation

Start from index `1`:

```text
[2,3,2,2]
```

There are only two fruit types, so the maximum is `4`.

---

# 💡 Approach: Sliding Window + Hash Map

The provided solution uses the **Sliding Window** technique with an `unordered_map`.

The current window is:

```text
[left ... right]
```

The map stores:

```text
fruit type → frequency
```

We expand the window using `right`.

If the window contains more than two distinct fruit types, we shrink it from the left until it becomes valid again.

---

# 💻 Provided C++ Solution

```cpp
class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        unordered_map<int, int> mp;

        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < fruits.size(); right++) {

            mp[fruits[right]]++;

            while (mp.size() > 2) {

                mp[fruits[left]]--;

                if (mp[fruits[left]] == 0) {
                    mp.erase(fruits[left]);
                }

                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
```

---

# 🧠 Code Explanation

## 1. Create the Hash Map

```cpp
unordered_map<int, int> mp;
```

It stores the frequency of every fruit type inside the current window.

Example:

```text
[1,2,2]
```

Map:

```text
1 → 1
2 → 2
```

---

## 2. Initialize Pointers

```cpp
int left = 0;
int maxLen = 0;
```

`left` represents the beginning of the window.

`maxLen` stores the longest valid window found so far.

---

## 3. Expand with `right`

```cpp
for (int right = 0; right < fruits.size(); right++)
```

For every fruit:

```cpp
mp[fruits[right]]++;
```

increase its frequency.

---

## 4. Check the Number of Fruit Types

```cpp
while (mp.size() > 2)
```

If there are more than two distinct fruit types, the current window is invalid.

We must shrink it.

---

## 5. Shrink from the Left

```cpp
mp[fruits[left]]--;
left++;
```

Remove the fruit at the left side of the window.

If its frequency becomes zero:

```cpp
if (mp[fruits[left]] == 0) {
    mp.erase(fruits[left]);
}
```

This is important because `mp.size()` must represent the number of **distinct** fruit types.

---

## 6. Update the Answer

Once the window contains at most two fruit types:

```cpp
maxLen = max(maxLen, right - left + 1);
```

The window length is:

```text
right - left + 1
```

---

# 🔍 Detailed Dry Run

For:

```text
fruits = [1,2,3,2,2]
```

Initially:

```text
left = 0
maxLen = 0
```

| `right` | Fruit | Window | Distinct Types | Action | `maxLen` |
|---:|---:|---|---:|---|---:|
| 0 | 1 | `[1]` | 1 | Valid | 1 |
| 1 | 2 | `[1,2]` | 2 | Valid | 2 |
| 2 | 3 | `[1,2,3]` | 3 | Shrink | 2 |
| 3 | 2 | `[2,3,2]` | 2 | Valid | 3 |
| 4 | 2 | `[2,3,2,2]` | 2 | Valid | 4 |

Final answer:

```text
4
```

Longest valid window:

```text
[2,3,2,2]
```

---

# 🪟 Sliding Window Visualization

For:

```text
[1,2,3,2,2]
```

When `right` reaches `2`:

```text
[1, 2, 3]
 ↑     ↑
left  right
```

There are three types:

```text
1, 2, 3
```

So we shrink:

```text
[1, 2, 3]
    ↑
   left
```

After removing `1`:

```text
[2, 3]
```

Now there are only two types, so the window is valid again.

---

# 🔄 Algorithm

```text
1. Create an unordered_map.

2. Set:
       left = 0
       maxLen = 0

3. Move right from 0 to n - 1.

4. Add fruits[right] to the map.

5. While the map contains more than 2 distinct types:

       Decrease fruits[left] frequency.
       Erase it if its frequency becomes zero.
       Move left forward.

6. Calculate:
       right - left + 1

7. Update maxLen.

8. Return maxLen.
```

---

# 🔄 Flow Diagram

```text
Start
  |
  v
Create Hash Map
  |
  v
left = 0
maxLen = 0
  |
  v
Move right
  |
  v
Add fruits[right]
  |
  v
More than 2 types?
  |
  +---- No ----> Calculate Window Length
  |                       |
 Yes                       v
  |                   Update maxLen
  v                       |
Remove fruits[left]       |
  |                       |
Frequency = 0?            |
  |                       |
 Yes → Erase              |
  |                       |
  v                       |
Move left ----------------+
  |
  v
More elements?
  |
 Yes → Continue
  |
 No
  |
  v
Return maxLen
```

---

# 🔙 Why Sliding Window Works

The requirement is:

```text
At most 2 distinct fruit types
```

When the window is valid, we expand it.

When it becomes invalid, we move `left` forward until it becomes valid again.

The pattern is:

```text
Expand
  ↓
Invalid?
  ↓
Shrink
  ↓
Valid
  ↓
Update Answer
```

Both pointers only move forward.

---

# ⚠️ Common Mistakes

## Mistake 1: Not Erasing Zero Frequencies

After:

```cpp
mp[fruits[left]]--;
```

a frequency may become zero.

We must remove that fruit type:

```cpp
mp.erase(fruits[left]);
```

Otherwise `mp.size()` would be incorrect.

## Mistake 2: Wrong Window Length

Correct:

```cpp
right - left + 1
```

For:

```text
left = 0
right = 0
```

the window contains one element:

```text
0 - 0 + 1 = 1
```

## Mistake 3: Resetting Instead of Shrinking

When three fruit types occur, do not reset the entire window.

Instead:

```text
Move left forward
```

until only two types remain.

---

# ⚠️ Important Edge Cases

## One Fruit Type

```text
[1,1,1,1]
```

Answer:

```text
4
```

## Two Fruit Types

```text
[1,2,1,2,1]
```

Answer:

```text
5
```

## All Different

```text
[1,2,3,4,5]
```

The longest valid window has two elements:

```text
[1,2]
```

Answer:

```text
2
```

---

# ⏱️ Complexity Analysis

Let:

```text
n = fruits.size()
```

## Time Complexity

The `right` pointer moves from left to right once, and `left` also only moves forward.

Therefore:

```text
Time Complexity: O(n)
```

Average-case `unordered_map` operations are `O(1)`.

## Space Complexity

The active window contains at most two distinct fruit types after shrinking.

Therefore:

```text
Space Complexity: O(1)
```

for this problem.

---

# 🎯 Key Concepts

- Sliding Window
- Two Pointers
- Hash Map
- Frequency Counting
- Longest Subarray
- At Most K Distinct Elements

---

# 🧠 Interview Notes

### What is the problem really asking?

Find the longest contiguous subarray containing at most two distinct values.

### What does `mp.size()` represent?

The number of distinct fruit types in the current window.

### When do we shrink the window?

```cpp
while (mp.size() > 2)
```

### How is the window length calculated?

```cpp
right - left + 1
```

### Why is this O(n)?

Both `left` and `right` move only forward.

---

# ⭐ Quick Revision

```text
Use:
    Sliding Window + Hash Map

right:
    Expand window

Map:
    Store frequencies

More than 2 types:
    Shrink from left

Frequency becomes 0:
    Erase type

Valid window:
    maxLen = max(maxLen, right - left + 1)

Return:
    maxLen
```

---

# 📚 Related DSA Topics

- Sliding Window
- Two Pointers
- Hash Map
- Frequency Counting
- Longest Subarray
- Longest Substring with K Distinct Characters

---

# 🔗 Conclusion

The provided solution converts the fruit basket problem into a **Longest Subarray with At Most Two Distinct Values** problem.

The core pattern is:

```text
Expand with right
       ↓
More than 2 types?
       ↓
Shrink with left
       ↓
Valid window
       ↓
Update maximum
```

This makes the solution efficient and avoids checking every possible subarray.

## Final Complexity

```text
Time Complexity  : O(n) average
Space Complexity : O(1)
```

This is a clean, efficient, and interview-friendly **Sliding Window + Hash Map** solution.
