# ⌫ 844. Backspace String Compare

## Problem Statement

Given two strings `s` and `t`, return `true` if they are equal after typing both strings into separate empty text editors.

The character:

```text
#
```

represents a **backspace**.

A backspace removes the most recently typed character.

If a backspace is applied when the text editor is already empty, the text remains empty.

### What is Given?

Two strings:

```text
s
t
```

containing lowercase characters and the backspace character `#`.

### What Needs to Be Returned?

Return:

```text
true
```

if both strings become the same after processing all backspaces.

Otherwise, return:

```text
false
```

---

# Examples

## Example 1

### Input

```text
s = "ab#c"
t = "ad#c"
```

### Output

```text
true
```

### Explanation

For `s`:

```text
a → ab → a → ac
```

For `t`:

```text
a → ad → a → ac
```

Both strings become:

```text
"ac"
```

Therefore:

```text
true
```

---

## Example 2

### Input

```text
s = "ab##"
t = "c#d#"
```

### Output

```text
true
```

### Explanation

For `s`:

```text
a → ab → a → ""
```

For `t`:

```text
c → "" → d → ""
```

Both strings become:

```text
""
```

Therefore:

```text
true
```

---

## Example 3

### Input

```text
s = "a#c"
t = "b"
```

### Output

```text
false
```

### Explanation

After processing:

```text
s = "c"
t = "b"
```

Since:

```text
"c" != "b"
```

the answer is:

```text
false
```

---

# 💡 Approach: Using Two Stacks

The provided solution uses two stacks:

```cpp
stack<char> s1;
stack<char> s2;
```

One stack processes string `s`, and the other processes string `t`.

The idea is:

```text
Normal character → Push into stack

'#' → Remove the previous character
```

After processing both strings, compare the contents of both stacks.

If both stacks contain exactly the same characters, return:

```text
true
```

Otherwise:

```text
false
```

---

# 💻 Provided C++ Solution

```cpp
class Solution {
public:
    bool backspaceCompare(string s, string t) {

        stack<char> s1;
        stack<char> s2;

        for (char ch : s) {
            if (ch != '#') {
                s1.push(ch);
            }
            else if (!s1.empty()) {
                s1.pop();
            }
        }

        for (char ch : t) {
            if (ch != '#') {
                s2.push(ch);
            }
            else if (!s2.empty()) {
                s2.pop();
            }
        }

        if (s1.size() != s2.size()) {
            return false;
        }

        while (!s1.empty()) {
            if (s1.top() != s2.top()) {
                return false;
            }

            s1.pop();
            s2.pop();
        }

        return true;
    }
};
```

---

# 🧠 Understanding the Code

## Step 1: Create Two Stacks

```cpp
stack<char> s1;
stack<char> s2;
```

These stacks represent the final text after processing each input string.

---

## Step 2: Process String `s`

```cpp
for (char ch : s)
```

For every character:

### If it is a normal character

```cpp
if (ch != '#') {
    s1.push(ch);
}
```

Push it into the stack.

### If it is `#`

```cpp
else if (!s1.empty()) {
    s1.pop();
}
```

Remove the previously typed character.

If the stack is already empty, nothing happens.

This correctly follows the problem condition.

---

## Step 3: Process String `t`

The exact same logic is used:

```cpp
for (char ch : t) {
    if (ch != '#') {
        s2.push(ch);
    }
    else if (!s2.empty()) {
        s2.pop();
    }
}
```

After this, both stacks represent the final edited strings.

---

## Step 4: Compare Stack Sizes

```cpp
if (s1.size() != s2.size()) {
    return false;
}
```

If the final strings have different lengths, they cannot be equal.

---

## Step 5: Compare Characters

```cpp
while (!s1.empty()) {
    if (s1.top() != s2.top()) {
        return false;
    }

    s1.pop();
    s2.pop();
}
```

Compare the top characters one by one.

If any character differs:

```text
false
```

If all characters match:

```text
true
```

---

# 🔍 Detailed Dry Run

## Dry Run 1

### Input

```text
s = "ab#c"
t = "ad#c"
```

### Processing `s`

| Character | Action | Stack |
|---|---|---|
| `a` | Push | `a` |
| `b` | Push | `a b` |
| `#` | Pop `b` | `a` |
| `c` | Push | `a c` |

Final text:

```text
ac
```

---

### Processing `t`

| Character | Action | Stack |
|---|---|---|
| `a` | Push | `a` |
| `d` | Push | `a d` |
| `#` | Pop `d` | `a` |
| `c` | Push | `a c` |

Final text:

```text
ac
```

Both stacks are equal.

```text
Answer = true
```

---

# 🔍 Dry Run 2

### Input

```text
s = "ab##"
t = "c#d#"
```

### Processing `s`

```text
a  → Push
b  → Push
#  → Remove b
#  → Remove a
```

Final:

```text
""
```

### Processing `t`

```text
c  → Push
#  → Remove c
d  → Push
#  → Remove d
```

Final:

```text
""
```

Both strings are equal.

```text
Answer = true
```

---

# 🔍 Dry Run 3

### Input

```text
s = "a#c"
t = "b"
```

### Processing `s`

```text
a → Push
# → Pop a
c → Push
```

Final:

```text
"c"
```

### Processing `t`

```text
b → Push
```

Final:

```text
"b"
```

Since:

```text
c != b
```

```text
Answer = false
```

---

# 🧱 Stack Visualization

For:

```text
s = "abc##d"
```

The stack operations are:

```text
a     → [a]

b     → [a, b]

c     → [a, b, c]

#     → [a, b]

#     → [a]

d     → [a, d]
```

Final string:

```text
"ad"
```

---

# 🔄 Algorithm

```text
Create two empty stacks

For every character in s:

    If character is not '#':
        Push it into stack s1

    Else if s1 is not empty:
        Pop the top character

For every character in t:

    If character is not '#':
        Push it into stack s2

    Else if s2 is not empty:
        Pop the top character

If stack sizes are different:
    Return false

While the stacks are not empty:

    If top characters are different:
        Return false

    Pop both stacks

Return true
```

---

# 🔄 Approach Flow

```text
Start
  |
  v
Create Two Stacks
  |
  v
Process String s
  |
  v
Process String t
  |
  v
Compare Stack Sizes
  |
  +--------------------+
  |                    |
Different             Same
  |                    |
false                  v
                  Compare Tops
                       |
                +------+------+
                |             |
             Different      Same
                |             |
              false        Pop Both
                              |
                              v
                        More Elements?
                         /          \
                       Yes           No
                        |             |
                        +-----------> true
```

---

# ⚠️ Important Edge Cases

## Edge Case 1: Backspace on Empty Text

```text
s = "#"
```

The text editor is already empty.

After backspace:

```text
""
```

The code handles this safely:

```cpp
else if (!s1.empty()) {
    s1.pop();
}
```

---

## Edge Case 2: Multiple Backspaces

```text
s = "abc###"
```

Processing:

```text
abc → ab → a → ""
```

Final result:

```text
""
```

---

## Edge Case 3: Different Final Lengths

Example:

```text
s = "a"
t = "b#"
```

After processing:

```text
s = "a"
t = ""
```

The stack sizes differ, so:

```cpp
return false;
```

---

# 🌳 Recursion Tree

This solution does not use recursion.

```text
Recursion Tree: Not Applicable
```

The solution uses:

```text
Two Stacks
```

---

# ⏱️ Complexity Analysis

Let:

```text
n = s.length()
m = t.length()
```

## Time Complexity

Each character is processed once.

The final stacks are also compared once.

```text
Time Complexity: O(n + m)
```

---

## Space Complexity

In the worst case, neither string contains backspaces.

Both stacks may store all characters.

```text
Space Complexity: O(n + m)
```

---

# 🎯 Key Concepts

- Stack
- Strings
- Simulation
- Backspace Processing
- LIFO

---

# 🧠 Interview Notes

### Why use a stack?

A backspace always removes the most recently typed character.

This follows the:

```text
LIFO
```

principle:

```text
Last In, First Out
```

### What happens when `#` appears on an empty stack?

Nothing happens.

The text remains empty.

### Why compare stack sizes first?

Strings with different lengths can never be equal.

---

# ⭐ Quick Revision

```text
Normal Character:
    Push

'#':
    If stack is not empty:
        Pop

Process both strings

Different stack sizes:
    false

Compare stack elements:
    Same → true
    Different → false
```

---

# 📚 Related DSA Topics

- Stack
- Strings
- Simulation
- Two Pointers
- String Processing

---

# 🔗 Conclusion

The provided solution simulates two text editors using stacks.

```text
Character → Push

'#' → Remove previous character

Empty editor + '#' → Do nothing
```

After processing both strings, the stacks represent their final states.

If both final states are equal:

```text
true
```

Otherwise:

```text
false
```

## Final Complexity

```text
Time Complexity  : O(n + m)
Space Complexity : O(n + m)
```

This is a clean and beginner-friendly stack-based solution for comparing strings with backspace operations.
