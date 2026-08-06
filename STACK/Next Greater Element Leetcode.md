# 📈 Next Greater Element I

## Problem Statement

The **Next Greater Element** of an element `x` in an array is the **first greater element present on the right side of `x`**.

You are given two distinct 0-indexed integer arrays:

```text
nums1
nums2
```

where `nums1` is a subset of `nums2`.

For every element `nums1[i]`:

1. Find `nums1[i]` inside `nums2`.
2. Search on its right side in `nums2`.
3. Find the **first element greater than `nums1[i]`**.
4. If no greater element exists, return `-1` for that element.

Return the resulting array.

---

# Example 1

### Input

```text
nums1 = [4, 1, 2]
nums2 = [1, 3, 4, 2]
```

### Output

```text
[-1, 3, -1]
```

### Explanation

For `4`:

```text
nums2 = [1, 3, 4, 2]
               ↑

Elements on right = [2]

2 < 4

Next Greater = -1
```

For `1`:

```text
nums2 = [1, 3, 4, 2]
         ↑

First greater element on right = 3
```

Therefore:

```text
1 → 3
```

For `2`:

```text
nums2 = [1, 3, 4, 2]
                  ↑
```

There are no elements on the right.

Therefore:

```text
2 → -1
```

Final answer:

```text
[-1, 3, -1]
```

---

# Example 2

### Input

```text
nums1 = [2, 4]
nums2 = [1, 2, 3, 4]
```

### Output

```text
[3, -1]
```

### Explanation

For `2`:

```text
nums2 = [1, 2, 3, 4]
            ↑

First greater element = 3
```

Therefore:

```text
2 → 3
```

For `4`:

```text
nums2 = [1, 2, 3, 4]
                  ↑
```

Nothing exists on the right.

Therefore:

```text
4 → -1
```

Final answer:

```text
[3, -1]
```

---

# Approach 1 — Brute Force

For every element of `nums1`:

1. Find the element inside `nums2`.
2. Start searching from the next position.
3. Find the first element greater than the current element.
4. If found, store it.
5. Otherwise, store `-1`.

---

## Brute Force Solution

```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1,
                                   vector<int>& nums2) {

        vector<int> ans;

        for(int i = 0; i < nums1.size(); i++) {

            int nextGreater = -1;

            for(int j = 0; j < nums2.size(); j++) {

                if(nums1[i] == nums2[j]) {

                    for(int k = j + 1; k < nums2.size(); k++) {

                        if(nums2[k] > nums1[i]) {

                            nextGreater = nums2[k];
                            break;
                        }
                    }

                    break;
                }
            }

            ans.push_back(nextGreater);
        }

        return ans;
    }
};
```

---

# Brute Force Dry Run

Consider:

```text
nums1 = [4, 1, 2]

nums2 = [1, 3, 4, 2]
```

### nums1[0] = 4

Find `4` in `nums2`.

```text
[1, 3, 4, 2]
       ↑
```

Start searching after `4`.

```text
2 > 4 ❌
```

No greater element.

```text
ans = [-1]
```

---

### nums1[1] = 1

Find `1`.

```text
[1, 3, 4, 2]
 ↑
```

Check right side.

First element:

```text
3 > 1 ✅
```

Therefore:

```text
ans = [-1, 3]
```

---

### nums1[2] = 2

Find `2`.

```text
[1, 3, 4, 2]
          ↑
```

Nothing exists on the right.

```text
ans = [-1, 3, -1]
```

---

# Brute Force Complexity

Let:

```text
M = nums1.size()
N = nums2.size()
```

For every element of `nums1`, we may scan `nums2`.

Therefore:

```text
Time Complexity = O(M × N)
```

Extra space excluding output:

```text
Space Complexity = O(1)
```

---

# Approach 2 — Optimal

We can optimize the problem using:

```text
Monotonic Stack + Hash Map
```

Instead of repeatedly searching `nums2`, we calculate the Next Greater Element for **every element of `nums2` only once**.

Then we store:

```text
Element → Next Greater Element
```

inside a hash map.

Finally, for every element in `nums1`, we directly get its answer from the map.

---

# Step 1 — Process nums2

Consider:

```text
nums2 = [1, 3, 4, 2]
```

We want to calculate:

```text
1 → 3
3 → 4
4 → -1
2 → -1
```

We use a **Monotonic Stack** and traverse:

```text
RIGHT → LEFT
```

---

# Step 2 — Monotonic Stack Rules

For every `nums2[i]`:

### Rule 1

Remove all elements from the stack that are smaller than or equal to the current element.

```text
stack.top() <= nums2[i]

→ POP
```

### Rule 2

After popping:

If stack is empty:

```text
NGE = -1
```

Otherwise:

```text
NGE = stack.top()
```

### Rule 3

Store:

```text
nums2[i] → NGE
```

in the hash map.

### Rule 4

Push the current element into the stack.

---

# Optimal Solution

```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1,
                                   vector<int>& nums2) {

        stack<int> st;
        unordered_map<int, int> mp;

        // Find NGE for every element of nums2
        for(int i = nums2.size() - 1; i >= 0; i--) {

            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            if(st.empty()) {
                mp[nums2[i]] = -1;
            }
            else {
                mp[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }


        // Get answers for nums1
        vector<int> ans;

        for(int i = 0; i < nums1.size(); i++) {

            ans.push_back(mp[nums1[i]]);
        }

        return ans;
    }
};
```

---

# Optimal Solution Dry Run

Consider:

```text
nums1 = [4, 1, 2]

nums2 = [1, 3, 4, 2]
```

Initially:

```text
Stack = []

Map = {}
```

We traverse `nums2` from right to left.

---

## i = 3

Current:

```text
nums2[3] = 2
```

Stack:

```text
[]
```

Stack is empty.

Therefore:

```text
2 → -1
```

Map:

```text
{
    2 : -1
}
```

Push `2`.

```text
Stack = [2]
```

---

## i = 2

Current:

```text
nums2[2] = 4
```

Stack:

```text
[2]
```

Check:

```text
2 <= 4 ✅
```

Pop `2`.

Stack becomes empty.

Therefore:

```text
4 → -1
```

Map:

```text
{
    2 : -1,
    4 : -1
}
```

Push `4`.

```text
Stack = [4]
```

---

## i = 1

Current:

```text
nums2[1] = 3
```

Stack:

```text
[4]
```

Check:

```text
4 <= 3 ❌
```

Don't pop.

Stack top is:

```text
4
```

Therefore:

```text
3 → 4
```

Map:

```text
{
    2 : -1,
    4 : -1,
    3 : 4
}
```

Push `3`.

```text
Stack = [4, 3]
```

---

## i = 0

Current:

```text
nums2[0] = 1
```

Stack:

```text
[4, 3]
```

Top:

```text
3
```

Check:

```text
3 <= 1 ❌
```

So:

```text
1 → 3
```

Map:

```text
{
    1 : 3,
    2 : -1,
    3 : 4,
    4 : -1
}
```

Push `1`.

---

# Now Process nums1

We have:

```text
nums1 = [4, 1, 2]
```

Simply use the map.

```text
mp[4] = -1

mp[1] = 3

mp[2] = -1
```

Therefore:

```text
ans = [-1, 3, -1]
```

---

# Complete Dry Run Table

| Current Element | Stack Before | Elements Popped |  NGE |
| --------------: | ------------ | --------------- | ---: |
|             `2` | `[]`         | None            | `-1` |
|             `4` | `[2]`        | `2`             | `-1` |
|             `3` | `[4]`        | None            |  `4` |
|             `1` | `[4,3]`      | None            |  `3` |

NGE Map:

```text
1 → 3
2 → -1
3 → 4
4 → -1
```

For:

```text
nums1 = [4,1,2]
```

we get:

```text
[-1,3,-1]
```

---

# Why Do We Need a Hash Map?

The stack calculates the NGE for elements of:

```text
nums2
```

But the final answer is required only for elements of:

```text
nums1
```

So we store:

```text
value → NGE
```

Example:

```text
1 → 3
3 → 4
4 → -1
2 → -1
```

Then each `nums1` element can directly retrieve its answer.

---

# Complexity Analysis

Let:

```text
M = nums1.size()
N = nums2.size()
```

Processing `nums2`:

```text
O(N)
```

Each element is pushed once and popped at most once.

Processing `nums1`:

```text
O(M)
```

Hash map lookup takes average `O(1)`.

Therefore:

```text
Time Complexity = O(N + M)
```

Space used by stack and hash map:

```text
Space Complexity = O(N)
```

---

# Brute Force vs Optimal

| Approach                       | Time Complexity | Extra Space |
| ------------------------------ | --------------: | ----------: |
| Brute Force                    |      `O(M × N)` |      `O(1)` |
| **Monotonic Stack + Hash Map** |  **`O(N + M)`** |  **`O(N)`** |

---

# Key Concepts

* Arrays
* Stack
* Monotonic Stack
* Hash Map
* Next Greater Element

---

# Pattern to Remember

The easiest way to remember **Next Greater Element I**:

```text
nums2
  ↓
Find NGE using Monotonic Stack
  ↓
Store value → NGE in Hash Map
  ↓
nums1
  ↓
Lookup answers from Hash Map
```

For finding the Next Greater Element:

```text
Traverse RIGHT → LEFT

        ↓

Pop elements <= current

        ↓

Stack Empty?
 /          \
YES          NO
 ↓            ↓
-1        stack.top()

        ↓

Store in Map

        ↓

Push Current
```

---

# Final Complexity

```text
Brute Force:
Time  → O(M × N)
Space → O(1)

Optimal:
Time  → O(N + M)
Space → O(N)
```

The optimal solution uses a **Monotonic Stack to calculate the Next Greater Elements** and a **Hash Map to efficiently answer queries for `nums1`**.
