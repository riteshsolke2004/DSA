# 🧱 Valid Parentheses

## Problem Statement

Given a string `s` containing only the following characters:

```text
( ) { } [ ]
```

determine whether the input string is **valid**.

An input string is valid if:

1. Open brackets are closed by the **same type** of brackets.
2. Open brackets are closed in the **correct order**.
3. Every closing bracket has a corresponding opening bracket.

### What is Given?

A string `s` containing brackets:

```text
( ) { } [ ]
```

### What Needs to Be Returned?

Return:

```text
true
```

if the string is valid, otherwise return:

```text
false
```

---

# Examples

## Example 1

### Input

```text
s = "()"
```

### Output

```text
true
```

### Explanation

The opening bracket:

```text
(
```

is correctly closed by:

```text
)
```

Therefore, the string is valid.

---

## Example 2

### Input

```text
s = "()[]{}"
```

### Output

```text
true
```

### Explanation

All brackets are correctly matched:

```text
() → Valid
[] → Valid
{} → Valid
```

Therefore:

```text
true
```

---

## Example 3

### Input

```text
s = "(]"
```

### Output

```text
false
```

### Explanation

The opening bracket is:

```text
(
```

but it is closed by:

```text
]
```

The bracket types do not match.

Therefore:

```text
false
```

---

## Example 4

### Input

```text
s = "([])"
```

### Output

```text
true
```

### Explanation

The brackets are nested correctly:

```text
(
    [
    ]
)
```

Therefore, the string is valid.

---

## Example 5

### Input

```text
s = "([)]"
```

### Output

```text
false
```

### Explanation

The brackets are not closed in the correct order.

```text
( [
) ]
```

The `)` tries to close `(`, but `[` is still open.

Therefore:

```text
false
```

---

# 💡 Approach: Stack

The provided solution uses a **stack**.

A stack follows the:

```text
LIFO
```

principle:

```text
Last In, First Out
```

This is perfect for checking brackets because the most recently opened bracket must be closed first.

For example:

```text
([{}])
```

The brackets open in this order:

```text
(
[
{
```

They must close in reverse order:

```text
}
]
)
```

---

# 🧠 Main Idea

## Opening Brackets

Whenever we find:

```text
(
[
{
```

we push it into the stack.

```cpp
st.push(ch);
```

---

## Closing Brackets

Whenever we find:

```text
)
]
}
```

we check:

1. Is the stack empty?
2. Does the top opening bracket match the current closing bracket?

If the stack is empty:

```text
There is no opening bracket to match.
```

So return:

```cpp
false;
```

If the brackets do not match:

```text
( + ] → Invalid
[ + ) → Invalid
{ + ] → Invalid
```

Return:

```cpp
false;
```

If they match:

```text
( + )
[ + ]
{ + }
```

remove the opening bracket from the stack.

```cpp
st.pop();
```

---

# 💻 Provided C++ Solution

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            }

            else {

                if (st.empty()) {
                    return false;
                }

                if (ch == ')' && st.top() != '(') {
                    return false;
                }

                else if (ch == '}' && st.top() != '{') {
                    return false;
                }

                else if (ch == ']' && st.top() != '[') {
                    return false;
                }

                else {
                    st.pop();
                }
            }
        }

        return st.empty();
    }
};
```

---

# 🧩 Understanding the Code

## Step 1: Create a Stack

```cpp
stack<char> st;
```

The stack stores opening brackets.

Example:

```text
s = "(["
```

Stack:

```text
Bottom → ( [
             ↑
            Top
```

The most recently opened bracket is always at the top.

---

## Step 2: Traverse the String

```cpp
for (int i = 0; i < s.length(); i++) {
    char ch = s[i];
}
```

We visit every character one by one.

---

## Step 3: Check for Opening Brackets

```cpp
if (ch == '(' || ch == '[' || ch == '{') {
    st.push(ch);
}
```

Every opening bracket is pushed onto the stack.

For:

```text
([
```

The stack becomes:

```text
( [
```

---

## Step 4: Check if the Stack Is Empty

For a closing bracket:

```cpp
if (st.empty()) {
    return false;
}
```

Example:

```text
s = ")"
```

There is a closing bracket, but no opening bracket exists.

Therefore:

```text
false
```

---

## Step 5: Check for Matching Brackets

For:

```text
)
```

the top of the stack must be:

```text
(
```

The code checks:

```cpp
if (ch == ')' && st.top() != '(') {
    return false;
}
```

Similarly:

```cpp
else if (ch == '}' && st.top() != '{') {
    return false;
}

else if (ch == ']' && st.top() != '[') {
    return false;
}
```

---

## Step 6: Remove a Matching Opening Bracket

If none of the mismatch conditions are true, the brackets match.

So:

```cpp
st.pop();
```

removes the opening bracket.

---

## Step 7: Final Check

After processing the complete string:

```cpp
return st.empty();
```

If the stack is empty:

```text
All opening brackets were correctly matched.
```

Return:

```text
true
```

Otherwise:

```text
Some opening brackets are still left.
```

Return:

```text
false
```

---

# 🔍 Detailed Dry Run

## Dry Run 1: `s = "([])"`

Initial stack:

```text
[]
```

| Character | Action | Stack |
|---|---|---|
| `(` | Push `(` | `(` |
| `[` | Push `[` | `( [` |
| `]` | Matches `[` → Pop | `(` |
| `)` | Matches `(` → Pop | `[]` |

The stack is empty.

Therefore:

```text
true
```

---

# 🔍 Detailed Dry Run: `s = "([)]"`

Initial stack:

```text
[]
```

### Character: `(`

Push:

```text
(
```

### Character: `[` 

Push:

```text
( [
```

### Character: `)`

The current character is:

```text
)
```

The top of the stack is:

```text
[
```

But:

```text
) must match (
```

Since:

```text
[ != (
```

the string is invalid.

Return:

```text
false
```

---

# 🔍 Detailed Dry Run: `s = "()[]{}"`

Initial stack:

```text
[]
```

Process:

```text
( → Push
) → Match and Pop

[ → Push
] → Match and Pop

{ → Push
} → Match and Pop
```

Final stack:

```text
[]
```

Therefore:

```text
true
```

---

# 🧱 Stack Visualization

For:

```text
{[()]}
```

The stack operations are:

```text
{       Push
{ [     Push
{ [ (   Push
{ [     ) matches (
{       ] matches [
empty   } matches {
```

Everything matches correctly.

Therefore:

```text
true
```

---

# 🔄 Algorithm

```text
Create an empty stack

For every character ch in the string:

    If ch is an opening bracket:
        Push it into the stack

    Otherwise:

        If stack is empty:
            Return false

        If ch does not match stack.top():
            Return false

        Pop the matching opening bracket

After processing all characters:

    If stack is empty:
        Return true

    Otherwise:
        Return false
```

---

# 🔄 Approach Flow

```text
Start
  |
  v
Create Empty Stack
  |
  v
Traverse Each Character
  |
  +---------------------------+
  |                           |
  v                           v
Opening Bracket          Closing Bracket
  |                           |
Push into Stack          Is Stack Empty?
  |                           |
  |                     Yes → false
  |                           |
  |                          No
  |                           |
  |                    Check Matching
  |                           |
  |                   No Match → false
  |                           |
  +---------------------------+
                              |
                              v
                         Pop Stack
                              |
                              v
                       Continue Traversal
                              |
                              v
                        Is Stack Empty?
                          /         \
                        Yes          No
                         |            |
                       true         false
```

---

# ⏱️ Complexity Analysis

Let:

```text
n = s.length()
```

## Time Complexity

Every character is processed exactly once.

Stack operations:

```text
push()
pop()
top()
```

take:

```text
O(1)
```

Therefore:

```text
Time Complexity: O(n)
```

---

## Space Complexity

In the worst case, all characters can be opening brackets.

Example:

```text
"((((["
```

The stack may store up to `n` characters.

Therefore:

```text
Space Complexity: O(n)
```

---

# ⚠️ Common Mistakes

## Mistake 1: Not Checking if the Stack Is Empty

Incorrect:

```cpp
if (st.top() == '(')
```

If the stack is empty, accessing:

```cpp
st.top()
```

is invalid.

Correct:

```cpp
if (st.empty()) {
    return false;
}
```

before accessing `st.top()`.

---

## Mistake 2: Checking Only the Number of Brackets

The number of opening and closing brackets alone is not enough.

Example:

```text
([)]
```

The number of brackets is correct, but the order is wrong.

Therefore, we need a stack.

---

## Mistake 3: Forgetting the Final Empty Check

Example:

```text
s = "((("
```

No mismatch occurs while traversing.

However, there are still unmatched opening brackets.

Therefore, we must return:

```cpp
st.empty();
```

---

# 🎯 Key Concepts

- Stack
- Strings
- LIFO
- Bracket Matching
- Nested Structures

---

# 🧠 Interview Notes

### Why is a stack used?

Because brackets must close in the reverse order in which they were opened.

This follows:

```text
LIFO
```

### What happens if a closing bracket appears when the stack is empty?

The string is invalid.

### What happens if the closing bracket does not match the stack top?

The string is invalid.

### Why do we check `st.empty()` at the end?

To ensure that no opening brackets remain unmatched.

---

# ⭐ Quick Revision

```text
Opening Bracket:
    Push

Closing Bracket:
    Stack empty?
        Yes → false

    Matches stack top?
        No → false

    Yes → Pop

After traversal:
    Stack empty → true
    Otherwise → false
```

---

# 📚 Related DSA Topics

- Stack
- Strings
- Parentheses Problems
- Balanced Brackets
- Expression Validation

---

# 🔗 Conclusion

The provided solution solves the **Valid Parentheses** problem using a **stack**.

The logic is simple:

```text
Opening bracket → Push

Closing bracket → Check and Pop

Mismatch → false

Stack empty at the end → true
```

## Final Complexity

```text
Time Complexity  : O(n)
Space Complexity : O(n)
```

This is the standard, efficient, and beginner-friendly approach for validating balanced parentheses and brackets.
