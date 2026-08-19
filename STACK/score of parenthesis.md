# 🔢 856. Score of Parentheses

## Problem Statement

Given a **balanced parentheses string** `s`, return its **score**.

The score of a balanced parentheses string is based on the following rules:

- `"()"` has score `1`.
- `AB` has score `A + B`, where `A` and `B` are balanced parentheses strings.
- `(A)` has score `2 * A`, where `A` is a balanced parentheses string.

### What is Given?

- A balanced parentheses string `s`.

### What Needs to Be Returned?

Return the integer score of the string.

---

# Examples

## Example 1

### Input

```text
s = "()"
```

### Output

```text
1
```

### Explanation

```text
() = 1
```

---

## Example 2

### Input

```text
s = "(())"
```

### Output

```text
2
```

### Explanation

First:

```text
() = 1
```

Then:

```text
(()) = 2 × 1 = 2
```

---

## Example 3

### Input

```text
s = "()()"
```

### Output

```text
2
```

### Explanation

```text
()() = () + ()
      = 1 + 1
      = 2
```

---

# 💡 Approach: Stack

The provided solution uses a **stack** to calculate the score at different nesting levels.

The main idea is:

```text
( → Start a new nesting level
) → Calculate the score of that level
```

Each `(` pushes a new `0` onto the stack.

Each `)` calculates the score of the current level and adds it to the previous level.

---

# 🧠 How the Solution Works

Initially:

```cpp
st.push(0);
```

The initial `0` represents the outermost level.

For every opening parenthesis:

```cpp
if (ch == '(') {
    st.push(0);
}
```

For every closing parenthesis:

```cpp
int inside = st.top();
st.pop();

int score = max(1, 2 * inside);

st.top() += score;
```

This handles all three scoring rules.

---

# 🧩 Understanding `max(1, 2 * inside)`

This line is the key:

```cpp
int score = max(1, 2 * inside);
```

## Case 1: `()`

For an empty pair:

```text
inside = 0
```

Therefore:

```text
max(1, 2 × 0)
= max(1, 0)
= 1
```

So:

```text
() = 1
```

---

## Case 2: `(A)`

If there is a valid balanced string inside:

```text
inside > 0
```

Then:

```text
score = 2 × inside
```

For example:

```text
(())
```

The inner:

```text
() = 1
```

Therefore:

```text
(()) = 2 × 1 = 2
```

---

# 💻 Provided C++ Solution

```cpp
class Solution {
public:
    int scoreOfParentheses(string s) {

        stack<int> st;
        st.push(0);

        for (char ch : s) {

            if (ch == '(') {
                st.push(0);
            }

            else {
                int inside = st.top();
                st.pop();

                int score = max(1, 2 * inside);

                st.top() += score;
            }
        }

        return st.top();
    }
};
```

---

# 🧠 Algorithm

1. Create a stack.
2. Push `0` initially.
3. Traverse every character of `s`.
4. If the character is `(`, push `0`.
5. If the character is `)`:
   - Store the top value in `inside`.
   - Pop the stack.
   - Calculate:
     ```text
     score = max(1, 2 × inside)
     ```
   - Add the score to the previous level.
6. Return the top of the stack.

---

# 🔍 Detailed Dry Run

## Dry Run 1: `s = "()"`

Initial stack:

```text
[0]
```

### Character: `(`

Push `0`.

```text
[0, 0]
```

### Character: `)`

```text
inside = 0
```

Pop:

```text
[0]
```

Calculate:

```text
score = max(1, 2 × 0)
      = 1
```

Add it to the previous level:

```text
[1]
```

Final answer:

```text
1
```

---

# 🔍 Detailed Dry Run: `s = "(())"`

Initial stack:

```text
[0]
```

| Character | Action | Stack |
|---|---|---|
| Start | Push initial `0` | `[0]` |
| `(` | Push `0` | `[0, 0]` |
| `(` | Push `0` | `[0, 0, 0]` |
| `)` | `inside = 0`, score = `1` | `[0, 1]` |
| `)` | `inside = 1`, score = `2` | `[2]` |

Final answer:

```text
2
```

---

# 🔍 Detailed Dry Run: `s = "()()"`

Initial stack:

```text
[0]
```

After the first:

```text
() → 1
```

Stack:

```text
[1]
```

After the second:

```text
() → 1
```

The score is added:

```text
1 + 1 = 2
```

Final stack:

```text
[2]
```

Answer:

```text
2
```

---

# 🔄 How All Rules Are Handled

## Rule 1: `"()" = 1`

```text
inside = 0

score = max(1, 2 × 0)
      = 1
```

---

## Rule 2: `AB = A + B`

The line:

```cpp
st.top() += score;
```

adds completed balanced strings at the same level.

Example:

```text
()()

First ()  = 1
Second () = 1

Total = 2
```

---

## Rule 3: `(A) = 2 × A`

For nested parentheses:

```text
inside > 0
```

Therefore:

```text
score = 2 × inside
```

Example:

```text
(()) = 2 × 1 = 2
```

---

# 🧱 Stack Visualization

For:

```text
(()())
```

The structure is:

```text
(
├── () → 1
└── () → 1
```

The total score inside is:

```text
1 + 1 = 2
```

The outer parentheses double it:

```text
2 × 2 = 4
```

Therefore:

```text
Score = 4
```

---

# 🔄 Approach Flow

```text
Start
  |
  v
Push 0
  |
  v
Traverse string
  |
  +--------------------+
  |                    |
  v                    v
 '('                  ')'
  |                    |
Push 0            Get inside score
  |                    |
  |                 Pop stack
  |                    |
  |        score = max(1, 2 × inside)
  |                    |
  +--------------------+
                       |
                       v
            Add score to previous level
                       |
                       v
                 Continue traversal
                       |
                       v
                  Return st.top()
```

---

# 🌳 Recursion Tree

This solution does not use recursion.

```text
Recursion Tree: Not Applicable
```

The solution uses:

```text
Stack + Iterative Traversal
```

---

# ⏱️ Complexity Analysis

Let:

```text
n = s.length()
```

## Time Complexity

Every character is processed exactly once.

Stack operations such as:

```text
push
pop
top
```

take `O(1)` time.

Therefore:

```text
Time Complexity: O(n)
```

---

## Space Complexity

In the worst case, the stack stores one value for each nesting level.

Therefore:

```text
Space Complexity: O(n)
```

---

# ⚠️ Important Points

## 1. Why Push an Initial `0`?

```cpp
st.push(0);
```

When a complete pair of parentheses is processed, its score needs to be added to the previous level.

The initial `0` acts as the outermost level.

---

## 2. Why Push `0` for Every `(`?

Every opening parenthesis starts a new nested level.

That level initially has no score:

```text
(
↓
0
```

---

## 3. Why Use `max(1, 2 * inside)`?

It handles both:

```text
()  → 1
(A) → 2 × A
```

in one expression.

---

# 🚨 Common Mistakes

## Mistake 1: Forgetting the Initial `0`

Without:

```cpp
st.push(0);
```

there may be no previous stack level to add the final score.

---

## Mistake 2: Using Only `2 * inside`

Incorrect:

```cpp
int score = 2 * inside;
```

For:

```text
()
```

this would give:

```text
0
```

Correct:

```cpp
int score = max(1, 2 * inside);
```

---

## Mistake 3: Forgetting to Add the Score Back

The calculated score must be added to the parent level:

```cpp
st.top() += score;
```

This is also what handles:

```text
AB = A + B
```

---

# 🎯 Key Concepts

- Stack
- Strings
- Balanced Parentheses
- Nested Structures
- Iterative Traversal

---

# 🧠 Interview Notes

### What technique is used?

```text
Stack
```

### Why is a stack useful?

Because parentheses can be nested, and a stack naturally tracks nested levels.

### What does each stack value represent?

The accumulated score at a particular nesting depth.

### How is concatenation handled?

Using:

```cpp
st.top() += score;
```

### What is the time complexity?

```text
O(n)
```

### What is the space complexity?

```text
O(n)
```

---

# ⭐ Quick Revision

```text
Push 0 initially

For every character:

    If '(':
        Push 0

    Else:
        inside = stack.top()
        Pop stack

        score = max(1, 2 × inside)

        Add score to previous level

Return stack.top()
```

---

# 📚 Related DSA Topics

- Stack
- Strings
- Balanced Parentheses
- Nested Structures
- Expression Evaluation

---

# 🔗 Conclusion

The provided solution solves **Score of Parentheses** using a **stack**.

The key logic is:

```text
()  → 1

(A) → 2 × A

AB  → A + B
```

The expression:

```cpp
max(1, 2 * inside)
```

correctly handles both the basic and nested cases.

## Final Complexity

```text
Time Complexity  : O(n)
Space Complexity : O(n)
```

This is a clean, efficient, and beginner-friendly stack-based solution.
