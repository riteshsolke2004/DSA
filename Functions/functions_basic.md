# 📌 Function Declaration vs Definition
# Declaration (tells compiler function exists)
 int add(int, int);

# Definition (actual logic)
int add(int a, int b) {
    return a + b;
}

# 📌 Function Call

When you use the function:

add(10, 20);


Control goes:

main() → function → back to main()

📌 Example 2: No Arguments, No Return Value
#include <iostream>
using namespace std;

void greet() {
    cout << "Welcome to C++ Programming!";
}

int main() {
    greet();
    return 0;
}

📌 Example 3: With Arguments, No Return
#include <iostream>
using namespace std;

void square(int n) {
    cout << "Square = " << n * n;
}

int main() {
    square(5);
    return 0;
}

📌 Example 4: No Arguments, With Return
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

📌 Function with Default Arguments
#include <iostream>
using namespace std;

int multiply(int a, int b = 2) {
    return a * b;
}

int main() {
    cout << multiply(5) << endl;
    cout << multiply(5, 4);
}

📌 Function Overloading

Same function name, different parameters.

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

📌 Call by Value vs Call by Reference
Call by Value
void change(int x) {
    x = 10;
}


Original value does not change.

Call by Reference
void change(int &x) {
    x = 10;
}


Original value does change.

📌 Example (Call by Reference)
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


Output:

50

📌 Advantages of Using Functions

Code reusability

Easy testing

Structured programming

Better readability

Faster debugging

Cleaner logic
