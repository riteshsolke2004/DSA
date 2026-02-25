## Queue-Operations

## USING ARRAY
```cpp

#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // ENQUEUE
    void enqueue(int x) {
        if (rear == SIZE - 1) {
            cout << "Queue Overflow\n";
            return;
        }

        if (front == -1)
            front = 0;

        arr[++rear] = x;
        cout << x << " inserted\n";
    }

    // DEQUEUE
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow\n";
            return;
        }

        cout << arr[front++] << " removed\n";
    }

    // FRONT ELEMENT
    int getFront() {
        if (front == -1 || front > rear) {
            cout << "Queue Empty\n";
            return -1;
        }
        return arr[front];
    }

    // DISPLAY
    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue Empty\n";
            return;
        }

        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();
    q.display();

    cout << "Front: " << q.getFront();
}

```

## USING LINKED-LIST

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

class Queue {
    Node *front, *rear;

public:
    Queue() {
        front = rear = NULL;
    }

    // ENQUEUE
    void enqueue(int x) {
        Node* temp = new Node(x);

        if (rear == NULL) {
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
        cout << x << " inserted\n";
    }

    // DEQUEUE
    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow\n";
            return;
        }

        Node* temp = front;
        cout << front->data << " removed\n";

        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
    }

    // FRONT ELEMENT
    int getFront() {
        if (front == NULL) {
            cout << "Queue Empty\n";
            return -1;
        }
        return front->data;
    }

    // DISPLAY
    void display() {
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    cout << "Front: " << q.getFront() << endl;

    q.dequeue();
    q.display();
}

```
