#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int value) {
    if (s.empty()) {
        s.push(value);
        return;
    }

    int top = s.top();
    s.pop();

    insertAtBottom(s, value);

    s.push(top);
}

void reverseAstack(stack<int> &s) {  // Pass by reference
    if (s.empty()) {
        return;
    }

    int value = s.top();
    s.pop();

    reverseAstack(s);

    insertAtBottom(s, value);
}

void printStack(stack<int> s) {  // Pass by value to not disturb original
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << "Before reverse: ";
    printStack(s);

    reverseAstack(s);

    cout << "After reverse: ";
    printStack(s);

    return 0;
}
