## Reverse first K of a Queue

Given an integer k and a queue of integers, we need to reverse the order of the first k elements of the queue, 
leaving the other elements in the same relative order.

-Only following standard operations are allowed on queue.

- enqueue(x) : Add an item x to rear of queue
- dequeue() : Remove an item from front of queue
- size() : Returns number of elements in queue.
- front() : Finds front item.
- Note: The above operations represent the general processings. In-built functions of the respective languages can be used to solve the problem.

## "If the size of queue is smaller than the given k , then return the original queue."

- Examples:
- Input: q = [1, 2, 3, 4, 5], k = 3
- Output: [3, 2, 1, 4, 5]
- Explanation: After reversing the first 3 elements from the given queue the resultant queue will be 3 2 1 4 5

- Input: q = [4, 3, 2, 1], k = 4
- Output: [1, 2, 3, 4]
- Explanation: After reversing the first 4 elements from the given queue the resultant queue will be 1 2 3 4

  ## SOLUTION
```cpp
  class Solution {
public:
    queue<int> reverseFirstK(queue<int> &q, int k) {

        int n = q.size();

        if (k > n || k <= 0) return q;

        stack<int> s;

        // Step 1: push first k into stack
        for (int i = 0; i < k; i++) {
            int element = q.front();
            q.pop();
            s.push(element);
        }

        // Step 2: push stack back to queue
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }

        // Step 3: rotate remaining n-k elements
        for (int i = 0; i < n - k; i++) {
            int element = q.front();
            q.pop();
            q.push(element);
        }

        return q;
    }
};

```
