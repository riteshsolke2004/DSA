# 📘 Introduction to C++

## 📌 Overview
C++ is a powerful, general-purpose programming language developed by **Bjarne Stroustrup**.  
It is an extension of the C language and supports **procedural**, **object-oriented**, and **generic programming**.
  
C++ is widely used where performance, efficiency, and control over system resources are important.
--- 
 
## 🎯 Why Learn C++?
- Strong foundation for programming concepts
- High performance and fast execution
- Used in system software, games, compilers, and embedded systems
- Helps understand memory management deeply
- Core language for competitive programming

---

## 🛠️ Features of C++
- Object Oriented Programming (OOP)
- Rich Standard Template Library (STL)
- Low-level memory manipulation
- Platform independent
- High speed and efficiency

---
## 🧩 Basic Structure of a C++ Program

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World";
    return 0;
}
```
Explanation:

#include <iostream> → Header file for input/output

using namespace std; → Access standard library

main() → Entry point of program

cout → Output statement

return 0; → Successful execution

📥 Input and Output
Output
cout << "Welcome to C++";

Input
int x;
cin >> x;

📦 Data Types
Data Type	Description
int	Integer values
float	Decimal numbers
double	Large decimal numbers
char	Single character
bool	true / false

Example:
```cpp
int a = 10;
float b = 5.5;
char c = 'A';
```
➗ Operators
Arithmetic Operators

+ - * / %

Relational Operators

== != > < >= <=

Logical Operators

&& || !

🔁 Control Statements
If-Else
if (age >= 18) {
    cout << "Eligible";
} else {
    cout << "Not Eligible";
}

Switch Case
switch(choice) {
    case 1: cout << "Option 1"; break;
    case 2: cout << "Option 2"; break;
    default: cout << "Invalid Option";
}

🔄 Loops
For Loop

```cpp
for(int i = 1; i <= 5; i++) {
    cout << i;
}

While Loop
int i = 1;
while(i <= 5) {
    cout << i;
    i++;
}

Do-While Loop
do {
    cout << i;
    i++;
} while(i <= 5);

🧮 Functions
int add(int a, int b) {
    return a + b;
}
```

Functions help in:

Code reusability

Better structure

Easy debugging

📚 Arrays
```cpp
int arr[5] = {1, 2, 3, 4, 5};
```

Access elements:

cout << arr[0];

🔤 Strings
#include <string>

string name = "C++";
cout << name;

🧠 Introduction to OOP

Class

Object

Encapsulation

Inheritance

Polymorphism

Example:
```cpp

class Student {
public:
    int roll;
    string name;
};
```
