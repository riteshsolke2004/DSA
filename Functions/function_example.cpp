✅ Example 1: Function with Arguments and Return Value (Most Used)
Program: Add two numbers using function

#include <iostream>
using namespace std;

// Function declaration
int add(int a, int b);

int main() {
    int x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;

    int result = add(x, y);
    cout << "Sum = " << result;

    return 0;
}

// Function definition
int add(int a, int b) {
    return a + b;
}

Output:
Enter two numbers: 5 3
Sum = 8
