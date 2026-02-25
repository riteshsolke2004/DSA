## Expression contains redundant bracket or not

Given a string of balanced expression s, check if it contains a redundant parenthesis or not. A set of parenthesis are redundant 
if the same sub-expression is surrounded by unnecessary or multiple brackets.
Note: Expression may contain + , - , *, and / operators. Given expression is valid and there are no white spaces present.

Examples:

- Input: s = "((a+b))"
- Output: true
- Explanation: ((a+b)) can reduced to (a+b).

- Input: s = "(a+(b)/c)"
- Output: true
- Explanation: (a+(b)/c) can reduced to (a+b/c) because b is surrounded by () which is redundant.

- Input: s = "(a+b+(c+d))"
- Output: false
- Explanation:(a+b+(c+d)) doesn't have any redundant or multiple brackets.

```cpp

class Solution {
  public:
    bool checkRedundancy(string &s) {
        // code here
        stack<char> st ;
        
        for(int i=0; i< s.length(); i++) {
            
            char ch = s[i] ;
            
            if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
                
                st.push(ch) ;
            }
            
            else if(ch == ')'){
                bool operatorFound = false ;
                
                while(!st.empty() && st.top() != '(' ){
                    
                    char value = st.top() ;
                    if(value == '(' || value == '+' || value == '-' || value == '*' || value == '/'){
                        operatorFound = true ;
                    }
                    st.pop() ;
                }
                
                if(operatorFound == false){
                    return true ;
                }
                else{
                    st.pop() ;
                }
            }
        }
        
        return false ;
        
    }
};
```
