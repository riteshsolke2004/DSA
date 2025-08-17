231. Power of Two

Given an integer n, return true if it is a power of two. Otherwise, return false.
An integer n is a power of two, if there exists an integer x such that n == 2x.

Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1
Example 2:

Input: n = 16
Output: true
Explanation: 24 = 16
Example 3:

Input: n = 3
Output: false


#solution :- 
  class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};



#Dry run for this :- 
🔹 How Execution Works

Let’s test with n = 16.

Step 1: Function Call
Solution obj;
cout << obj.isPowerOfTwo(16);


n = 16 is passed to the function.

Step 2: Condition n > 0

16 > 0 ✅ true, so continue.

If n was negative or zero, it would immediately return false.

Step 3: Bitwise Trick (n & (n - 1))

Compute n - 1 = 15.

Binary representations:

n   = 16 = 10000 (binary)
n-1 = 15 = 01111 (binary)


Now n & (n-1):

10000

& 01111

00000

- Result = `0`.  


#### Step 4: Final Condition
```cpp
return (n > 0 && (n & (n - 1)) == 0);
n > 0 → true

(n & (n-1)) == 0 → true

So the function returns true ✅.
