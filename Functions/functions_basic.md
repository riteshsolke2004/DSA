# 📘 Functions in C++ — Complete Guide

## 📌 What is a Function?

A **function** in C++ is a block of code that performs a specific task.  
Instead of writing the same logic again and again, we write it once inside a function and reuse it.
 
Functions help in:
- Code reusability  
- Better program structure  
- Easy debugging  
- Clean and readable code  

Old-school rule that still matters:
> Break large programs into small logical functions.

---

## 📌 Function Declaration vs Function Definition

### ✅ Function Declaration  
Tells the compiler that a function exists.

```cpp
int add(int, int);
```

- Also called function prototype
- Written before main()
- Does not contain logic

# ✅ Function Definition

Contains the actual implementation (logic).

```cpp
int add(int a, int b) {
    return a + b;
}
```

#📌 Function Call

When a function is used inside main():

```cpp
add(10, 20);
```

# Flow of execution:
```css
main() → function → back to main()
```

# 📌 Types of Functions (Based on Arguments & Return Value)

| Type | Arguments | Return Value |
| ---- | --------- | ------------ |
| 1    | No        | No           |
| 2    | Yes       | No           |
| 3    | No        | Yes          |
| 4    | Yes       | Yes          |


# 📌 Example 1: No Arguments, No Return Value
```cpp
#include <iostream>
using namespace std;

void greet() {
    cout << "Welcome to C++ Programming!";
}

int main() {
    greet();
    return 0;
}

```
Explanation:
- Function takes no input
- Does not return anything
- Used only for displaying output.


# 📌 Example 2: with Arguments, No Return Value
```cpp
#include <iostream>
using namespace std;

void square(int n) {
    cout << "Square = " << n * n;
}

int main() {
    square(5);
    return 0;
}
```

Explanation:
- Value is passed as argument
- Function processes it
- No value is returned

# 📌 Example 3: No Arguments, With Return Value
```cpp
#include <iostream>
using namespace std;

int getNumber() {
    return 10;
}

int main() {
    int x = getNumber();
    cout << x;
    return 0;
}
```

Explanation:
- Function returns a value
- No parameters required
- Returned value stored in a variable

# 📌 Function with Default Arguments

Default arguments are used when values are not passed during function call.
```cpp
#include <iostream>
using namespace std;

int multiply(int a, int b = 2) {
    return a * b;
}

int main() {
    cout << multiply(5) << endl;
    cout << multiply(5, 4);
}

```

# output
```
10
20
```

# 📌 Function Overloading

Function overloading means same function name but different parameters.
```cpp
#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

int main() {
    cout << add(2, 3) << endl;
    cout << add(2.5, 3.5);
}
```

Key Points:
- Function name is same
- Parameter list must be different
- Improves readability
- Supports compile-time polymorphism


# 📌 Call by Value vs Call by Reference
✅ Call by Value
```cpp
void change(int x) {
    x = 10;
}
```

- Copy of variable is passed
- Original value does not change

# ✅ Call by Reference
```cpp
void change(int &x) {
    x = 10;
}
```
- Reference (address) is passed
- Original value does change

# 📌 Example: Call by Reference
```cpp
#include <iostream>
using namespace std;

void update(int &x) {
    x = 50;
}

int main() {
    int a = 10;
    update(a);
    cout << a;
    return 0;
}
```
# output 
50

