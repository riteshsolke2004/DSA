# 🧮 150. Evaluate Reverse Polish Notation

## Problem Statement

You are given an array of strings `tokens` representing an arithmetic expression in **Reverse Polish Notation (RPN)**.

Evaluate the expression and return the final integer value.

### Valid Operators

```text
+
-
*
/
```

### Important Conditions

- Each token can be an integer or an operator.
- Division between two integers truncates toward zero.
- Division by zero will not occur.
- The input is always a valid Reverse Polish Notation expression.
- All intermediate and final results fit within a 32-bit signed integer.

---

# 📚 What is Reverse Polish Notation?

In Reverse Polish Notation, an operator comes **after** its operands.

### Normal Expression

```text
(2 + 1) * 3
```

### Reverse Polish Notation

```text
2 1 + 3 *
```

Evaluation:

```text
2 1 + → 3
3 3 * → 9
```

---

# Examples

## Example 1

### Input

```text
tokens = ["2","1","+","3","*"]
```

### Output

```text
9
```

### Explanation

```text
((2 + 1) * 3) = 9
```

---

## Example 2

### Input

```text
tokens = ["4","13","5","/","+"]
```

### Output

```text
6
```

### Explanation

```text
4 + (13 / 5)
= 4 + 2
= 6
```

---

## Example 3

### Input

```text
tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
```

### Output

```text
22
```

### Explanation

```text
((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= 22
```

---

# 💡 Approach: Stack

The provided solution uses a **stack**.

For every token:

- If it is a number, push it onto the stack.
- If it is an operator, pop the top two operands.
- Perform the operation.
- Push the result back.

After processing all tokens, the top of the stack contains the final answer.

---

# 💻 Provided C++ Solution

```cpp
class Solution {
public:
    int evalRPN(vector<string>& token) {

        stack<int> st;
        int ans = 0;

        for(int i = 0; i < token.size(); i++) {

            if(token[i] == "+" || token[i] == "-" || token[i] == "*" || token[i] == "/") {
                int second = st.top();
                st.pop();

                int first = st.top();
                st.pop();

                if(token[i] == "+") {
                    ans = first + second;
                    st.push(ans);
                }
                else if(token[i] == "-") {
                    ans = first - second;
                    st.push(ans);
                }
                else if(token[i] == "*") {
                    ans = first * second;
                    st.push(ans);
                }
                else {
                    ans = first / second;
                    st.push(ans);
                }
            }
            else {
                st.push(stoi(token[i]));
            }
        }

        return st.top();
    }
};
```

---

# 🧠 Code Explanation

## 1. Stack Creation

```cpp
stack<int> st;
```

The stack stores operands and intermediate results.

For:

```text
["2", "1", "+"]
```

the stack first becomes:

```text
[2, 1]
```

Then `+` combines them into:

```text
[3]
```

---

## 2. Identifying Operators

```cpp
if(token[i] == "+" || token[i] == "-" ||
   token[i] == "*" || token[i] == "/")
```

If the current token is an operator, the solution pops two operands.

---

## 3. Operand Order

```cpp
int second = st.top();
st.pop();

int first = st.top();
st.pop();
```

The order is very important.

The operation must be:

```text
first operator second
```

For example:

```text
10 2 -
```

The stack pops:

```text
second = 2
first = 10
```

Therefore:

```text
10 - 2 = 8
```

The provided code correctly handles this.

---

## 4. Performing Operations

### Addition

```cpp
ans = first + second;
```

### Subtraction

```cpp
ans = first - second;
```

### Multiplication

```cpp
ans = first * second;
```

### Division

```cpp
ans = first / second;
```

The result is pushed back:

```cpp
st.push(ans);
```

---

## 5. Handling Numbers

If a token is not an operator:

```cpp
st.push(stoi(token[i]));
```

`stoi()` converts the string into an integer.

Examples:

```text
"10"  → 10
"-11" → -11
"5"   → 5
```

---

# 🔍 Detailed Dry Run

Consider:

```text
tokens = ["2","1","+","3","*"]
```

Initially:

```text
Stack = []
```

## Step 1

Token:

```text
"2"
```

Push:

```text
Stack = [2]
```

## Step 2

Token:

```text
"1"
```

Push:

```text
Stack = [2, 1]
```

## Step 3

Token:

```text
"+"
```

Pop:

```text
second = 1
first = 2
```

Calculate:

```text
2 + 1 = 3
```

Push result:

```text
Stack = [3]
```

## Step 4

Token:

```text
"3"
```

Push:

```text
Stack = [3, 3]
```

## Step 5

Token:

```text
"*"
```

Pop:

```text
second = 3
first = 3
```

Calculate:

```text
3 * 3 = 9
```

Final stack:

```text
Stack = [9]
```

Return:

```text
9
```

---

# 🌳 Stack Visualization

For:

```text
tokens = ["4","13","5","/","+"]
```

Process numbers:

```text
Top
┌────┐
│  5 │
├────┤
│ 13 │
├────┤
│  4 │
└────┘
```

Process `/`:

```text
13 / 5 = 2
```

Stack:

```text
Top
┌───┐
│ 2 │
├───┤
│ 4 │
└───┘
```

Process `+`:

```text
4 + 2 = 6
```

Final answer:

```text
6
```

---

# 🔄 Algorithm

```text
1. Create an empty stack.

2. Traverse every token.

3. If the token is a number:
       Convert it using stoi().
       Push it onto the stack.

4. If the token is an operator:
       Pop second operand.
       Pop first operand.

       Calculate:
           first + second
           first - second
           first * second
           first / second

       Push the result back.

5. Return the top of the stack.
```

---

# 🔄 Flow Diagram

```text
Start
  |
  v
Create Stack
  |
  v
Read Token
  |
  v
Is it an Operator?
  |
 No -----------------> Convert using stoi()
  |                          |
  |                          v
  |                     Push to Stack
  |
 Yes
  |
  v
Pop Second Operand
  |
  v
Pop First Operand
  |
  v
Perform Operation
  |
  v
Push Result
  |
  v
More Tokens?
  |
 Yes ------> Continue
  |
 No
  |
  v
Return stack.top()
```

---

# ⚠️ Important Concept: Operand Order

For addition and multiplication:

```text
a + b = b + a
a * b = b * a
```

But subtraction and division are order-sensitive.

Correct:

```cpp
first - second
first / second
```

Incorrect:

```cpp
second - first
second / first
```

This is one of the most common mistakes in this problem.

---

# ⚠️ Negative Numbers

A token like:

```text
"-11"
```

is correctly treated as a number.

It does not match:

```text
"-"
```

Therefore, it reaches:

```cpp
stoi(token[i])
```

and becomes:

```text
-11
```

---

# ⏱️ Complexity Analysis

Let `n` be the number of tokens.

## Time Complexity

```text
O(n)
```

Each token is processed once.

## Space Complexity

```text
O(n)
```

In the worst case, the stack stores up to `n` operands.

---

# 🎯 Key Concepts

- Stack
- Expression Evaluation
- Reverse Polish Notation
- String to Integer Conversion
- Operand Order

---

# 🧠 Interview Notes

### Why is a stack used?

An operator in RPN appears after its operands.

The stack stores previous operands until an operator is encountered.

### Why pop `second` first?

For:

```text
10 2 -
```

the correct calculation is:

```text
10 - 2
```

Therefore:

```cpp
second = 2;
first = 10;
```

### Why is the answer at the top?

Every operation replaces two values with one result. After the complete expression is processed, only the final answer remains.

---

# ⭐ Quick Revision

```text
Number?
    ↓
Push

Operator?
    ↓
Pop second
Pop first
    ↓
Calculate first op second
    ↓
Push result

Finally:
    ↓
Return stack.top()
```

---

# 📚 Related DSA Topics

- Stack
- Valid Parentheses
- Expression Evaluation
- Prefix and Postfix Expressions
- Basic Calculator

---

# 🔗 Conclusion

The provided solution uses a **stack-based approach** to evaluate the Reverse Polish Notation expression.

The core idea is:

```text
Operand → Push

Operator → Pop two operands
           ↓
        Calculate
           ↓
        Push result
```

The solution correctly maintains operand order for subtraction and division.

## Final Complexity

```text
Time Complexity  : O(n)
Space Complexity : O(n)
```

This is a clean, optimal, and standard stack-based solution for **Evaluate Reverse Polish Notation**.
