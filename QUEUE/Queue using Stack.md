## Queue using Stack

Implement a Queue using stacks. You are allowed to use only stack data structures to implement the queue.
The Queue must support the following operations:

- (i) enqueue(x): Insert an element x at the rear of the queue.
- (ii) dequeue(): Remove the element from the front of the queue.
- (iii) front(): Return the front element if the queue is not empty, else return -1.
- (iv) size(): Return the number of elements currently in the queue.

## There will be a sequence of queries queries[][]. The queries are represented in numeric form:

- 1 x : Call enqueue(x)
- 2: Call dequeue()
- 3: Call front()
- 4: Call size()
You just have to implement the functions enqueue, dequeue, front and size. The driver code will handle the input and output.

## Examples:

- Input: q = 7, queries[][] = [[1, 5], [1, 3], [1, 4], [3], [2], [4], [3]]
- Output: [5, 2, 3]
Explanation: Queries on queue are as follows:
enqueue(5): Insert 5 at the rear of the queue.
enqueue(3): Insert 3 at the rear of the queue.
enqueue(4): Insert 4 at the rear of the queue.
front(): Return the front element i.e 5.
dequeue(): Remove the front element 5 from the queue.
size(): Queue now has 2 elements.
front(): Return the front element i.e 3.

- Input: q = 3, queries[][] = [[3], [4], [1, 10]]
- Output: [-1, 0]
Explanation: Queries on queue are as follows:
front(): Queue is empty, return -1.
size(): Queue contains 0 elements return 0.
enqueue(10): Insert 10 at the rear (no output for enqueue).


## SOLUTION 
```cpp

class myQueue {
    stack<int> s1, s2;

public:
    myQueue() {}

    void enqueue(int x) {
        s1.push(x);
    }

    void dequeue() {
        if (s1.empty() && s2.empty()) return;

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }

    int front() {
        if (s1.empty() && s2.empty()) return -1;

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    int size() {
        return s1.size() + s2.size();
    }
};
```
## Full Basic C++ Code 

```cpp
#include <iostream>
#include <stack>
using namespace std;

class myQueue {
    stack<int> s1, s2;

public:
    void enqueue(int x) {
        s1.push(x);
    }

    void dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty\n";
            return;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        s2.pop();
    }

    int front() {
        if (s1.empty() && s2.empty()) return -1;

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    int size() {
        return s1.size() + s2.size();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    myQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front: " << q.front() << endl;

    q.dequeue();

    cout << "Front after dequeue: " << q.front() << endl;
    cout << "Size: " << q.size() << endl;

    return 0;
}

```
