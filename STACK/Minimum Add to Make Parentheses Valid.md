# 🧩 921. Minimum Add to Make Parentheses Valid

## Problem Statement

A parentheses string is valid if and only if:

- It is an empty string.
- It can be written as `AB`, where both `A` and `B` are valid parentheses strings.
- It can be written as `(A)`, where `A` is a valid parentheses string.

You are given a parentheses string `s`.

In one move, you can insert either:

```text
(
```

or:

```text
)
```

at any position in the string.

Return the **minimum number of moves** required to make the given parentheses string valid.

### What is Given?

A string `s` containing only:

```text
(
)
```

### What Needs to Be Returned?

Return the minimum number of parentheses that must be inserted to make the string valid.

### Important Condition

You cannot remove or replace any existing parenthesis.

You can only **insert** new parentheses.

---

# Examples

## Example 1

### Input

```text
s = "())"
```

### Output

```text
1
```

### Explanation

The string:

```text
())
```

contains one extra closing parenthesis.

Insert one opening parenthesis:

```text
(())
```

Now the string is valid.

Therefore:

```text
Minimum moves = 1
```

---

## Example 2

### Input

```text
s = "((("
```

### Output

```text
3
```

### Explanation

There are three opening parentheses and no closing parentheses.

We need to insert:

```text
)))
```

So:

```text
(((
+ )))
------
((()))
```

Therefore:

```text
Minimum moves = 3
```

---

# 💡 Approach: Stack

The provided solution uses a **stack** to keep track of unmatched parentheses.

The main idea is simple:

```text
'(' → Push into stack
```

For:

```text
')'
```

there are two possibilities:

1. If an opening parenthesis exists at the top of the stack, match them and pop.
2. Otherwise, the closing parenthesis is unmatched, so push it into the stack.

At the end:

```text
Stack Size = Number of unmatched parentheses
```

Each unmatched parenthesis requires exactly one insertion.

Therefore:

```cpp
return st.size();
```

---

# 💻 Provided C++ Solution

```cpp
class Solution {
public:
    int minAddToMakeValid(string s) {

        stack<int> st ;

        for(char ch : s) {

            if(ch == '('){
                st.push(ch) ;
            }
            else {

                if(!st.empty() && st.top() == '('){
                    st.pop() ;
                }
                else {
                    st.push(ch) ;
                }
            }
        }
        return st.size() ;
    }
};
```

---

# 📝 Small Improvement

The provided code is logically correct.

However, the stack stores parentheses characters, so using:

```cpp
stack<char>
```

is more appropriate than:

```cpp
stack<int>
```

Because C++ can implicitly convert `char` to `int`, the original code still works.

A cleaner version is:

```cpp
class Solution {
public:
    int minAddToMakeValid(string s) {

        stack<char> st;

        for(char ch : s) {

            if(ch == '(') {
                st.push(ch);
            }
            else {

                if(!st.empty() && st.top() == '(') {
                    st.pop();
                }
                else {
                    st.push(ch);
                }
            }
        }

        return st.size();
    }
};
```

The approach remains exactly the same.

---

# 🧠 Understanding the Code

## Step 1: Create a Stack

```cpp
stack<int> st;
```

The stack stores unmatched parentheses.

A cleaner declaration would be:

```cpp
stack<char> st;
```

Initially:

```text
Stack = []
```

---

## Step 2: Traverse Every Character

```cpp
for(char ch : s)
```

We process every parenthesis one by one.

---

## Step 3: Opening Parenthesis

If the current character is:

```text
(
```

we push it into the stack.

```cpp
if(ch == '(') {
    st.push(ch);
}
```

This means we currently have an opening parenthesis waiting to be matched.

---

## Step 4: Closing Parenthesis

When we find:

```text
)
```

we check:

```cpp
if(!st.empty() && st.top() == '(')
```

If an unmatched opening parenthesis exists, they form a valid pair:

```text
()
```

So we remove the opening parenthesis:

```cpp
st.pop();
```

---

## Step 5: Unmatched Closing Parenthesis

If the stack is empty, there is no opening parenthesis available.

Example:

```text
)
```

This closing parenthesis is unmatched.

So we store it:

```cpp
st.push(ch);
```

It will require an opening parenthesis to be inserted later.

---

## Step 6: Return Stack Size

After processing the complete string:

```cpp
return st.size();
```

Every remaining parenthesis is unmatched.

Each unmatched parenthesis needs exactly one insertion.

Therefore:

```text
Minimum Insertions = Number of Unmatched Parentheses
```

---

# 🔍 Detailed Dry Run

## Dry Run 1: `s = "())"`

Initial:

```text
Stack = []
```

### Character 1: `(`

Push:

```text
[
    (
]
```

---

### Character 2: `)`

The top is:

```text
(
```

They match:

```text
()
```

Pop the stack:

```text
[]
```

---

### Character 3: `)`

The stack is empty.

This `)` is unmatched.

Push it:

```text
[
    )
]
```

Final stack size:

```text
1
```

Therefore:

```text
Minimum moves = 1
```

---

# 🔍 Detailed Dry Run: `s = "((("`

Initial:

```text
[]
```

### Character 1: `(`

```text
[(]
```

### Character 2: `(`

```text
[(, (]
```

### Character 3: `(`

```text
[(, (, (]
```

There are no closing parentheses to match them.

Final stack size:

```text
3
```

We need to insert:

```text
)))
```

Therefore:

```text
Minimum moves = 3
```

---

# 🔍 Additional Dry Run: `s = "()))"`

Process:

| Character | Action | Stack |
|---|---|---|
| `(` | Push | `(` |
| `)` | Match and Pop | Empty |
| `)` | Unmatched → Push | `)` |
| `)` | Unmatched → Push | `) )` |

Final stack size:

```text
2
```

So we need:

```text
2 insertions
```

For example:

```text
(())
))
```

Conceptually, insert two opening parentheses to match the extra closing parentheses.

---

# 🧱 Stack Visualization

For:

```text
s = "(()))("
```

The process is:

```text
(     → Push

((    → Push

(()   → Match and Pop

((    → Match and Pop

()    → Unmatched ')' stored

()(   → Push '('
```

The remaining unmatched parentheses represent the number of insertions required.

---

# 🔄 Algorithm

```text
Create an empty stack

For every character ch in s:

    If ch is '(':
        Push it into the stack

    Otherwise:

        If stack is not empty
        and stack.top() is '(':
            Pop the stack

        Otherwise:
            Push ')'

Return the size of the stack
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
Traverse String
  |
  v
Is Character '('?
  /             \
Yes              No
 |                |
Push '('      Is stack top '('?
 |              /         \
 |            Yes          No
 |             |            |
 |           Pop        Push ')'
 |             |            |
 +-------------+------------+
               |
               v
        More Characters?
          /         \
        Yes          No
         |            |
         +------------+
               |
               v
        Return stack.size()
```

---

# 🎯 Why Does `stack.size()` Give the Answer?

At the end, the stack contains only unmatched parentheses.

For every unmatched:

```text
(
```

we need to insert:

```text
)
```

For every unmatched:

```text
)
```

we need to insert:

```text
(
```

Therefore:

```text
Number of insertions = Number of unmatched parentheses
```

So:

```cpp
return st.size();
```

---

# ⚠️ Common Mistakes

## Mistake 1: Only Counting Opening Parentheses

Consider:

```text
)))
```

There are no opening parentheses, but we still need three insertions.

So unmatched closing parentheses must also be counted.

---

## Mistake 2: Popping Without Checking the Stack

Incorrect:

```cpp
st.pop();
```

The stack may be empty.

The correct logic checks:

```cpp
!st.empty() && st.top() == '('
```

before popping.

---

## Mistake 3: Returning the Number of Matched Pairs

The question asks for the minimum number of **insertions**, not the number of valid pairs.

We must count the parentheses left unmatched.

---

# 🌳 Recursion Tree

This solution does not use recursion.

```text
Recursion Tree: Not Applicable
```

The solution uses:

```text
Stack + Greedy Matching
```

---

# ⏱️ Complexity Analysis

Let:

```text
n = s.length()
```

## Time Complexity

We traverse the string exactly once.

Each stack operation:

```text
push
pop
top
```

takes:

```text
O(1)
```

Therefore:

```text
Time Complexity: O(n)
```

---

## Space Complexity

In the worst case, all parentheses may remain unmatched.

Example:

```text
"(((((("
```

or:

```text
"))))))"
```

The stack can contain up to `n` elements.

Therefore:

```text
Space Complexity: O(n)
```

---

# 🧠 Interview Notes

### What data structure is used?

```text
Stack
```

### What does the stack store?

```text
Unmatched parentheses
```

### When do we pop?

When we find:

```text
()
```

A closing parenthesis matches an opening parenthesis at the top of the stack.

### What does the final stack size represent?

```text
The minimum number of insertions required.
```

---

# ⭐ Quick Revision

```text
'(':
    Push

')':
    If top is '(':
        Pop
    Else:
        Push unmatched ')'

Finally:

Answer = stack.size()
```

---

# 📚 Related DSA Topics

- Stack
- Strings
- Parentheses
- Balanced Parentheses
- Greedy Matching

---

# 🔗 Conclusion

The provided solution uses a stack to match valid pairs:

```text
()
```

Every unmatched parenthesis remains in the stack.

Since each unmatched parenthesis needs exactly one matching parenthesis to be inserted:

```text
Minimum Moves = stack.size()
```

## Final Complexity

```text
Time Complexity  : O(n)
Space Complexity : O(n)
```

This is a simple, efficient, and beginner-friendly approach to make a parentheses string valid.
