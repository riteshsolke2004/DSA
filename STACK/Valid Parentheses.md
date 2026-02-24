Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false


# SOLUTION 
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
