# 📈 Next Greater Element

## Problem Statement

Given an integer array `arr[]`, find the **Next Greater Element (NGE)** for every element in the array.

The **Next Greater Element** of an element is the **nearest element on its right side that is greater than the current element**.

If there is no greater element on the right, the answer for that element is `-1`.

---

## Example 1

### Input

```text
arr = [1, 3, 2, 4]
```

### Output

```text
[3, 4, 4, -1]
```

### Explanation

```text
1 → 3
3 → 4
2 → 4
4 → -1
```

Therefore:

```text
[3, 4, 4, -1]
```

---

## Example 2

### Input

```text
arr = [6, 8, 0, 1, 3]
```

### Output

```text
[8, -1, 1, 3, -1]
```

### Explanation

```text
6 → 8

8 → -1
No greater element exists on the right.

0 → 1

1 → 3

3 → -1
No greater element exists on the right.
```

---

## Example 3

### Input

```text
arr = [1, 2, 3, 5]
```

### Output

```text
[2, 3, 5, -1]
```

Since the array is sorted in increasing order, the next element is also the next greater element.

---

## Example 4

### Input

```text
arr = [5, 4, 3, 1]
```

### Output

```text
[-1, -1, -1, -1]
```

There is no greater element on the right for any element.

---

# Approach 1 — Brute Force

The simplest approach is to check all elements on the right side of the current element.

For every `arr[i]`:

1. Start checking from `i + 1`.
2. Find the first element greater than `arr[i]`.
3. Store that element as the answer.
4. If no greater element exists, store `-1`.

---

## Brute Force Solution

```cpp
class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {

        int n = arr.size();

        vector<int> ans(n, -1);

        for(int i = 0; i < n; i++) {

            for(int j = i + 1; j < n; j++) {

                if(arr[j] > arr[i]) {

                    ans[i] = arr[j];
                    break;
                }
            }
        }

        return ans;
    }
};
```

---

# Brute Force Complexity

For every element, we may have to check all the elements on its right.

```text
Time Complexity  = O(N²)
Space Complexity = O(N)
```

The `O(N)` space is used for the output array.

---

# Approach 2 — Optimal Monotonic Stack

We can solve the problem efficiently using a **Monotonic Stack**.

Instead of searching the right side repeatedly, we traverse the array:

```text
RIGHT → LEFT
```

and maintain useful elements inside a stack.

---

# Main Idea

For every element `arr[i]`:

### Step 1 — Remove Smaller Elements

Remove elements from the stack that are **smaller than or equal to** the current element.

Conceptually:

```text
while stack is not empty
AND
stack.top() <= arr[i]

        POP
```

Why?

Because those elements cannot be the Next Greater Element of `arr[i]`.

---

### Step 2 — Find Next Greater

After removing smaller elements:

If the stack is empty:

```text
NGE = -1
```

Otherwise:

```text
NGE = stack.top()
```

The top element is the nearest greater element on the right.

---

### Step 3 — Push Current Element

Push:

```text
arr[i]
```

into the stack so that it can potentially become the Next Greater Element for elements on its left.

---

# Optimal C++ Solution

```cpp
class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {

        int n = arr.size();

        stack<int> s;
        vector<int> ans(n);

        for(int i = n - 1; i >= 0; i--) {

            while(!s.empty() && s.top() <= arr[i]) {
                s.pop();
            }

            if(s.empty()) {
                ans[i] = -1;
            }
            else {
                ans[i] = s.top();
            }

            s.push(arr[i]);
        }

        return ans;
    }
};
```

---

# Dry Run

Consider:

```text
arr = [1, 3, 2, 4]
```

We traverse from:

```text
RIGHT → LEFT
```

Initially:

```text
Stack = []
ans   = [_, _, _, _]
```

---

## i = 3

Current:

```text
arr[3] = 4
```

Stack:

```text
[]
```

Stack is empty.

Therefore:

```text
ans[3] = -1
```

Push `4`.

```text
Stack = [4]

ans = [_, _, _, -1]
```

---

## i = 2

Current:

```text
arr[2] = 2
```

Stack:

```text
[4]
```

Compare:

```text
4 <= 2 ❌
```

Don't pop.

The top is greater than `2`.

Therefore:

```text
ans[2] = 4
```

Push `2`.

```text
Stack = [4, 2]
               ↑
              top
```

Answer:

```text
[_, _, 4, -1]
```

---

## i = 1

Current:

```text
arr[1] = 3
```

Stack:

```text
[4, 2]
```

Compare top:

```text
2 <= 3 ✅
```

Pop `2`.

Stack:

```text
[4]
```

Now:

```text
4 <= 3 ❌
```

Stop popping.

The top is `4`.

Therefore:

```text
ans[1] = 4
```

Push `3`.

```text
Stack = [4, 3]
```

Answer:

```text
[_, 4, 4, -1]
```

---

## i = 0

Current:

```text
arr[0] = 1
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
ans[0] = 3
```

Push `1`.

```text
Stack = [4, 3, 1]
```

Final answer:

```text
[3, 4, 4, -1]
```

---

# Dry Run Table

| Index | Current | Stack Before | Popped |  NGE |
| ----: | ------: | ------------ | ------ | ---: |
|     3 |     `4` | `[]`         | None   | `-1` |
|     2 |     `2` | `[4]`        | None   |  `4` |
|     1 |     `3` | `[4,2]`      | `2`    |  `4` |
|     0 |     `1` | `[4,3]`      | None   |  `3` |

Final:

```text
[3, 4, 4, -1]
```

---

# Why Traverse Right to Left?

For every element, we need information about elements on its:

```text
RIGHT SIDE
```

By traversing from right to left, the stack already contains elements that appeared to the right of the current element.

So instead of searching the entire right side repeatedly, we use the stack to efficiently find the nearest useful greater element.

---

# Why Pop Smaller Elements?

Suppose:

```text
Current = 5

Stack top = 3
```

Since:

```text
3 <= 5
```

`3` cannot be the Next Greater Element of `5`.

So we remove it.

If the stack becomes:

```text
[10, 7]
```

then:

```text
7 > 5
```

Therefore:

```text
NGE of 5 = 7
```

---

# Why Use `<=` Instead of `<`?

The question asks for a **strictly greater** element.

Suppose:

```text
Current = 5
Stack top = 5
```

The top is equal, not greater.

Therefore, it must also be removed:

```text
5 <= 5
```

Hence:

```cpp
while(!s.empty() && s.top() <= arr[i])
```

is correct.

---

# Complexity Analysis

Each element is:

```text
Pushed → At most once
Popped → At most once
```

Therefore:

```text
Time Complexity = O(N)
```

The stack can contain at most `N` elements.

```text
Space Complexity = O(N)
```

---

# Brute Force vs Optimal

| Approach            | Time Complexity | Extra Space |
| ------------------- | --------------: | ----------: |
| Brute Force         |         `O(N²)` |      `O(1)` |
| **Monotonic Stack** |      **`O(N)`** |  **`O(N)`** |

---

# Key Concepts

* Stack
* Monotonic Stack
* Next Greater Element
* Arrays
* Right-to-Left Traversal

---

# Pattern to Remember

For **Next Greater Element on the Right**:

```text
1. Traverse RIGHT → LEFT

2. Pop elements <= current

3. Stack empty?
      YES → answer = -1
      NO  → answer = stack.top()

4. Push current element
```

### Shortcut

```text
Next Greater Element
        ↓
Traverse Right → Left
        ↓
Pop Smaller / Equal Elements
        ↓
Stack Top = Answer
        ↓
Push Current
```

This is one of the most important **Monotonic Stack patterns** in DSA.
