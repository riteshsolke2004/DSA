📘 Introduction to C++
📌 What is C++?

C++ is a powerful, high-performance programming language developed by Bjarne Stroustrup as an extension of the C language.
It supports procedural, object-oriented, and generic programming, which makes it a solid foundation for learning programming seriously.

If programming languages had a backbone, C++ would be it.

🧠 Why Learn C++?

Builds strong logic & problem-solving skills

Teaches memory management (important for real systems)

Used in competitive programming

Core language for:

Operating Systems

Game Development

Embedded Systems

High-performance applications

Learning C++ from scratch = learning programming the classic way.

🛠️ Features of C++

Fast execution 🚀

Object-Oriented Programming (OOP)

Rich Standard Library (STL)

Low-level memory control

Portable & scalable

🧩 Basic Structure of a C++ Program
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, World!";
    return 0;
}

Explanation:

#include <iostream> → Header file for input/output

using namespace std; → Avoids writing std:: again and again

main() → Program execution starts here

cout → Used to print output

return 0; → Successful program termination

📥 Input & Output
Output:
cout << "Welcome to C++";

Input:
int x;
cin >> x;

📦 Variables & Data Types
Common Data Types:
Data Type	Size	Example
int	4 bytes	int a = 10;
float	4 bytes	float b = 5.5;
double	8 bytes	double c = 10.55;
char	1 byte	char ch = 'A';
bool	1 byte	bool isTrue = true;
➗ Operators in C++
Arithmetic Operators

+ - * / %

Relational Operators

== != > < >= <=

Logical Operators

&& || !

🔁 Control Statements
If-Else
if (age >= 18) {
    cout << "Eligible to vote";
} else {
    cout << "Not eligible";
}

Switch Case
switch(day) {
    case 1: cout << "Monday"; break;
    case 2: cout << "Tuesday"; break;
    default: cout << "Invalid day";
}

🔄 Loops
For Loop
for(int i = 1; i <= 5; i++) {
    cout << i << " ";
}

While Loop
int i = 1;
while(i <= 5) {
    cout << i << " ";
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


Functions help in:

Code reusability

Better readability

Modular programming

📚 Arrays
int arr[5] = {1, 2, 3, 4, 5};


Access elements using index:

cout << arr[0];

🔤 Strings
#include <string>

string name = "C++";
cout << name;

🧠 Basic OOP Concepts (Intro)

Class → Blueprint

Object → Instance of class

Encapsulation → Data hiding

Inheritance → Code reuse

Polymorphism → Many forms

Example:

class Student {
public:
    int id;
    string name;
};
