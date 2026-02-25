## Stack Operations using Linked-List 

```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Stack {
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    // PUSH
    void push(int x) {
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
        cout << x << " pushed\n";
    }

    // POP
    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        cout << top->data << " popped\n";
        top = top->next;
        delete temp;
    }

    // PEEK
    int peek() {
        if (top == NULL) {
            cout << "Stack Empty\n";
            return -1;
        }
        return top->data;
    }

    // DISPLAY
    void display() {
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    st.display();

    cout << "Top element: " << st.peek() << endl;

    st.pop();
    st.display();
}

```
