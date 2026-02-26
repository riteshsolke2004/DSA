## Queue Reversal Using a Stack

Approach:

Transfer Queue to Stack: Move all elements from the queue to a stack, which reverses their order due to the Last-In-First-Out (LIFO) nature of stacks.
Transfer Back to Queue: Pop elements from the stack back into the queue, restoring them in reverse order.

## Solution 
```cpp
void reverseQueue(queue<int> &q) {
  stack<int> s;
  while (!q.empty()) {
    int element = q.front();
    q.pop();
    s.push(element);
  }
  while (!s.empty()) {
    int element = s.top();
    s.pop();
    q.push(element);
  }
}
```

## Recursive Queue Reversal
Approach:

Base Case: If the queue is empty, return.
Recursive Reduction: Dequeue the front element and apply the reversal on the rest of the queue recursively.
Reconstruction: Enqueue the dequeued element at the back, during the unwinding phase.

```cpp
void reverseQueueUsingRecursion(queue<int> &q) {
  if (q.empty()) return;
  int element = q.front();
  q.pop();
  reverseQueueUsingRecursion(q);
  q.push(element);
}
```

