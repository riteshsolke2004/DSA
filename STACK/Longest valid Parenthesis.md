# 🧱 32. Longest Valid Parentheses

## Problem Statement

Given a string `s` containing only `'('` and `')'`, return the length of the longest valid (well-formed) parentheses substring.

A valid substring must have correctly matched and properly ordered parentheses.

---

# Examples

## Example 1

### Input

```text
s = "(()"
```

### Output

```text
2
```

### Explanation

The longest valid parentheses substring is:

```text
()
```

---

## Example 2

### Input

```text
s = ")()())"
```

### Output

```text
4
```

### Explanation

The longest valid parentheses substring is:

```text
()()
```

Therefore, its length is:

```text
4
```

---

## Example 3

### Input

```text
s = ""
```

### Output

```text
0
```

### Explanation

The string is empty, so no valid substring exists.

---

# 💡 Approach: Stack of Indices

The provided solution uses a **stack of indices**.

Instead of storing parentheses characters, the stack stores indices. This allows us to calculate the length of a valid substring using:

```text
Current Index - Boundary Index
```

The solution starts with:

```cpp
st.push(-1);
```

The `-1` acts as an initial boundary.

---

# 💻 C++ Solution

```cpp
class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int> st;
        st.push(-1);

        int ans = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                st.push(i);
            }
            else {
                st.pop();

                if (st.empty()) {
                    st.push(i);
                }
                else {
                    ans = max(ans, i - st.top());
                }
            }
        }

        return ans;
    }
};
```

---

# 🧠 How the Code Works

## Step 1: Push `-1`

```cpp
st.push(-1);
```

This creates a boundary before the string begins.

For:

```text
()
01
```

after processing index `1`:

```text
Length = 1 - (-1) = 2
```

---

## Step 2: Traverse the String

```cpp
for (int i = 0; i < s.size(); i++)
```

Process every character one by one.

---

## Step 3: Opening Parenthesis

```cpp
if (s[i] == '(') {
    st.push(i);
}
```

Store the index of every unmatched opening parenthesis.

---

## Step 4: Closing Parenthesis

```cpp
st.pop();
```

A closing parenthesis attempts to match the latest unmatched opening parenthesis or boundary.

---

## Step 5: Stack Becomes Empty

```cpp
if (st.empty()) {
    st.push(i);
}
```

If the stack becomes empty, the current `)` is invalid.

Its index becomes a new boundary for future valid substrings.

---

## Step 6: Calculate Valid Length

```cpp
ans = max(ans, i - st.top());
```

If the stack is not empty, then:

```text
st.top()
```

represents the boundary immediately before the current valid substring.

So:

```text
Valid Length = i - st.top()
```

---

# 🔍 Detailed Dry Run

## Input

```text
s = ")()())"
```

Indices:

```text
String: ) ( ) ( ) )
Index : 0 1 2 3 4 5
```

Initial state:

```text
Stack = [-1]
ans = 0
```

| Index | Character | Action | Stack | `ans` |
|---|---|---|---|---|
| 0 | `)` | Pop `-1`, stack empty → push `0` | `[0]` | 0 |
| 1 | `(` | Push `1` | `[0, 1]` | 0 |
| 2 | `)` | Pop, length = `2 - 0 = 2` | `[0]` | 2 |
| 3 | `(` | Push `3` | `[0, 3]` | 2 |
| 4 | `)` | Pop, length = `4 - 0 = 4` | `[0]` | 4 |
| 5 | `)` | Pop, stack empty → push `5` | `[5]` | 4 |

Final answer:

```text
4
```

The longest valid substring is:

```text
()()
```

---

# 🧱 Stack Visualization

For:

```text
s = "()"
```

Initially:

```text
[-1]
```

At index `0`:

```text
(
```

Push `0`:

```text
[-1, 0]
```

At index `1`:

```text
)
```

Pop:

```text
[-1]
```

Calculate:

```text
1 - (-1) = 2
```

Answer:

```text
2
```

---

# 🔄 Algorithm

```text
Create a stack of indices

Push -1 as the initial boundary

Initialize ans = 0

For every index i:

    If s[i] == '(':
        Push i

    Else:
        Pop the stack

        If the stack is empty:
            Push i as a new boundary

        Else:
            ans = max(ans, i - stack.top())

Return ans
```

---

# ⚠️ Important Points

## Why `-1`?

It acts as the starting boundary.

Example:

```text
()
```

The length is:

```text
1 - (-1) = 2
```

---

## Why Push an Invalid `)` Index?

Consider:

```text
)()
012
```

The first `)` is invalid.

Store index `0` as a boundary:

```text
[0]
```

Then the valid substring:

```text
()
```

has length:

```text
2 - 0 = 2
```

---

## Why Store Indices Instead of Characters?

The problem asks for the longest **length**.

Using indices makes this calculation possible:

```cpp
i - st.top()
```

---

# 🚨 Common Mistakes

## Mistake 1: Not Pushing `-1`

Without the initial boundary, valid substrings starting at index `0` are harder to calculate correctly.

---

## Mistake 2: Accessing `st.top()` When Empty

After:

```cpp
st.pop();
```

the stack can become empty.

Always check:

```cpp
if (st.empty())
```

before accessing `st.top()`.

---

## Mistake 3: Forgetting to Push the New Boundary

For an invalid closing parenthesis:

```cpp
if (st.empty()) {
    st.push(i);
}
```

This is necessary for calculating future valid substring lengths correctly.

---

# 🌳 Recursion Tree

This solution does not use recursion.

```text
Recursion Tree: Not Applicable
```

The solution uses:

```text
Stack + Index Tracking
```

---

# ⏱️ Complexity Analysis

Let:

```text
n = s.length()
```

## Time Complexity

Each index is pushed and popped at most once.

```text
Time Complexity: O(n)
```

## Space Complexity

In the worst case, all indices can be stored in the stack.

```text
Space Complexity: O(n)
```

---

# 🎯 Key Concepts

- Stack
- Strings
- Balanced Parentheses
- Index Tracking
- Boundary Technique

---

# 🧠 Interview Notes

### What does the stack store?

```text
Indices of unmatched opening parentheses and boundary positions.
```

### Why push `-1` initially?

It acts as a boundary before the string starts.

### Why push the index of an invalid `)`?

It creates a new boundary for the next possible valid substring.

### What is the key length formula?

```cpp
i - st.top()
```

---

# ⭐ Quick Revision

```text
Stack stores indices

Push -1 initially

For '(':
    Push index

For ')':
    Pop

    If stack is empty:
        Push current index as boundary

    Else:
        ans = max(ans, i - st.top())

Return ans
```

---

# 📚 Related DSA Topics

- Stack
- Strings
- Parentheses
- Balanced Parentheses
- Index Tracking

---

# 🔗 Conclusion

The provided solution solves **Longest Valid Parentheses** using a stack of indices.

```text
-1 → Initial boundary

'(' → Push index

')' → Pop

Stack empty → Push current index as new boundary

Stack not empty → Calculate:

i - st.top()
```

## Final Complexity

```text
Time Complexity  : O(n)
Space Complexity : O(n)
```

This is an efficient and standard stack-based approach for finding the longest valid parentheses substring.
