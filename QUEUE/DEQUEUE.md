## DEQUEUE OPERATIONS 

## DEQUEUE USING ARRAY
```cpp
#include <iostream>
using namespace std;

#define SIZE 5

class Deque {
    int arr[SIZE];
    int front, rear;

public:
    Deque() { front = rear = -1; }

    bool isFull() {
        return (front == 0 && rear == SIZE-1) || (front == rear+1);
    }

    bool isEmpty() { return front == -1; }

    void insertFront(int x) {
        if (isFull()) return;

        if (isEmpty()) front = rear = 0;
        else if (front == 0) front = SIZE-1;
        else front--;

        arr[front] = x;
    }

    void insertRear(int x) {
        if (isFull()) return;

        if (isEmpty()) front = rear = 0;
        else if (rear == SIZE-1) rear = 0;
        else rear++;

        arr[rear] = x;
    }

    void deleteFront() {
        if (isEmpty()) return;

        if (front == rear) front = rear = -1;
        else if (front == SIZE-1) front = 0;
        else front++;
    }

    void deleteRear() {
        if (isEmpty()) return;

        if (front == rear) front = rear = -1;
        else if (rear == 0) rear = SIZE-1;
        else rear--;
    }
};
```

## DEQUEUE USING LINKED-LIST
```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *prev, *next;
    Node(int x) { data = x; prev = next = NULL; }
};

class Deque {
    Node *front, *rear;

public:
    Deque() { front = rear = NULL; }

    void insertFront(int x) {
        Node* temp = new Node(x);

        if (!front) front = rear = temp;
        else {
            temp->next = front;
            front->prev = temp;
            front = temp;
        }
    }

    void insertRear(int x) {
        Node* temp = new Node(x);

        if (!rear) front = rear = temp;
        else {
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
        }
    }

    void deleteFront() {
        if (!front) return;

        Node* temp = front;
        front = front->next;

        if (front) front->prev = NULL;
        else rear = NULL;

        delete temp;
    }

    void deleteRear() {
        if (!rear) return;

        Node* temp = rear;
        rear = rear->prev;

        if (rear) rear->next = NULL;
        else front = NULL;

        delete temp;
    }
};

```

## Circular Queue using Array
```cpp
#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = rear = -1;
    }

    bool isFull() {
        return (front == (rear + 1) % SIZE);
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Overflow\n";
            return;
        }

        if (isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % SIZE;

        arr[rear] = x;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Underflow\n";
            return;
        }

        cout << arr[front] << " removed\n";

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }

    void display() {
        if (isEmpty()) return;

        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

```
## Circular Queue using Linked List
```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) { data = x; next = NULL; }
};

class CircularQueue {
    Node *front, *rear;

public:
    CircularQueue() { front = rear = NULL; }

    void enqueue(int x) {
        Node* temp = new Node(x);

        if (!front) {
            front = rear = temp;
            rear->next = front;
            return;
        }

        rear->next = temp;
        rear = temp;
        rear->next = front;
    }

    void dequeue() {
        if (!front) return;

        if (front == rear) {
            delete front;
            front = rear = NULL;
            return;
        }

        Node* temp = front;
        front = front->next;
        rear->next = front;
        delete temp;
    }
};
```
