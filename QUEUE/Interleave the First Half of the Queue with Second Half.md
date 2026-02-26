## Interleave the First Half of the Queue with Second Half

Given a queue q[] of even size. Your task is to rearrange the queue by interleaving its first half with the second half.

Interleaving is the process of mixing two sequences by alternating their elements while preserving their relative order.
In other words, Interleaving means place the first element from the first half and then first element from the 2nd half and
again second element from the first half and then second element from the 2nd half and so on....

Examples:

- Input: q[] = [2, 4, 3, 1]
- Output: [2, 3, 4, 1]
- Explanation: We place the first element of the first half 2 and after that place the first element of second half 3 and after that repeat
the same process one more time so the resulting queue will be [2, 3, 4, 1]
- Input: q[] = [3, 5]
- Output: [3, 5]
- Explanation: We place the first element of the first half 3 and first element
of the second half 5 so the resulting queue is [3, 5]


## Solution
```cpp
class Solution {
public:
    void rearrangeQueue(queue<int> &q) {

        queue<int> q1;

        int size = q.size();
        int half = size / 2;

        // move first half into q1
        while (half--) {
            int element = q.front();
            q.pop();
            q1.push(element);
        }

        // interleave back into q
        while (!q1.empty()) {
            int element = q1.front();
            q1.pop();
            q.push(element);

            element = q.front();
            q.pop();
            q.push(element);
        }
    }
};
```
