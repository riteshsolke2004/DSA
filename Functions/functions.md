# 📘 Functions in C++ (Complete Guide)
📌 What is a Function in C++?

A function is a block of code that performs a specific task.
Instead of writing the same logic again and again, we put it inside a function and reuse it.

👉 Functions help in:

Code reusability
 
Better readability

Easy debugging 

Proper program structure

Traditional programming always respects this idea — divide the program into small logical parts.

📌 Why Functions Are Important

Avoid repetition of code

Make large programs manageable

Improve clarity and maintenance

Support modular programming

Make teamwork easier

Strong fundamentals start with understanding functions properly.

📌 General Syntax of a Function
return_type function_name(parameters) {
    // function body
    return value;
}

Example:
```cpp
int add(int a, int b) {
    return a + b;
}
```
📌 Parts of a Function

Return Type → Data type of value returned

Function Name → Identifier used to call the function

Parameters → Input values

Function Body → Logic inside { }

Return Statement → Sends result back to caller

📌 Types of Functions in C++
1. Library Functions

Predefined functions provided by C++
Example:

sqrt(), pow(), cout, cin

2. User-Defined Functions

Functions created by the programmer.

📌 Types of User-Defined Functions (Based on Arguments & Return)
| Type | Arguments | Return Value |
| ---- | --------- | ------------ |
| 1    | No        | No           |
| 2    | Yes       | No           |
| 3    | No        | Yes          |
| 4    | Yes       | Yes          |

