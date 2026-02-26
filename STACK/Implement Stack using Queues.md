## Implement Stack using Queues

Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions 
of a normal stack (push, top, pop, and empty).

## Implement the MyStack class:

- void push(int x) Pushes element x to the top of the stack.
- int pop() Removes the element on the top of the stack and returns it.
- int top() Returns the element on the top of the stack.
- boolean empty() Returns true if the stack is empty, false otherwise.

## Notes:

You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.
 

- Example 1:

- Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
- Output
[null, null, null, 2, 2, false]

- Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False


## LEETCODE SOLUTION 
```cpp

class MyStack {
public:
    queue<int> q;

    MyStack() {}

    void push(int x) {
        q.push(x);

        int n = q.size();
        for (int i = 0; i < n - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int ans = q.front();
        q.pop();
        return ans;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

```

## Basic C++ code 
```cpp
#include <iostream>
#include <queue>
using namespace std;

class myStack {
    queue<int> q;

public:
    void push(int x) {
        q.push(x);

        // rotate previous elements
        int n = q.size();
        for (int i = 0; i < n - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        q.pop();
    }

    int top() {
        if (q.empty()) return -1;
        return q.front();
    }

    bool empty() {
        return q.empty();
    }

    int size() {
        return q.size();
    }
};

int main() {
    myStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl;

    st.pop();

    cout << "Top after pop: " << st.top() << endl;
    cout << "Size: " << st.size() << endl;

    return 0;
}
```
