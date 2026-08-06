# 🪟 Sliding Window Maximum

## Problem Statement

You are given an integer array `nums` and an integer `k`.

There is a sliding window of size `k` that moves from the **left side of the array to the right side**, one position at a time.

For every window, find the **maximum element**.

Return an array containing the maximum value from every sliding window.

---

## Example 1

### Input

```text id="4hn0xr"
nums = [1, 3, -1, -3, 5, 3, 6, 7]
k = 3
```

### Output

```text id="i5uqyk"
[3, 3, 5, 5, 6, 7]
```

### Explanation

```text id="m7kydw"
Window                         Maximum
------------------------------------------------
[1, 3, -1] -3  5  3  6  7      → 3

1 [3, -1, -3] 5  3  6  7       → 3

1  3 [-1, -3, 5] 3  6  7       → 5

1  3  -1 [-3, 5, 3] 6  7       → 5

1  3  -1  -3 [5, 3, 6] 7       → 6

1  3  -1  -3  5 [3, 6, 7]      → 7
```

Therefore:

```text id="mugtz5"
Answer = [3, 3, 5, 5, 6, 7]
```

---

## Example 2

### Input

```text id="s8cfxh"
nums = [1]
k = 1
```

### Output

```text id="yix1qs"
[1]
```

---

# Approach 1 — Brute Force

The simplest approach is to generate every window of size `k`.

For every window:

1. Traverse all `k` elements.
2. Find the maximum element.
3. Add the maximum to the answer.

---

## Brute Force C++ Solution

```cpp id="4kj8yn"
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> ans;

        for(int i = 0; i <= n - k; i++) {

            int maxi = INT_MIN;

            for(int j = i; j < i + k; j++) {

                maxi = max(maxi, nums[j]);
            }

            ans.push_back(maxi);
        }

        return ans;
    }
};
```

---

# Brute Force Dry Run

Consider:

```text id="t8mqv8"
nums = [1, 3, -1, -3, 5]
k = 3
```

### Window 1

```text id="0h2d5a"
i = 0

[1, 3, -1]
```

Find maximum:

```text id="96o9kn"
max(1, 3, -1) = 3
```

Answer:

```text id="wt8au8"
ans = [3]
```

---

### Window 2

```text id="squ42b"
i = 1

[3, -1, -3]
```

Maximum:

```text id="63ejdg"
3
```

Answer:

```text id="q5i92c"
ans = [3, 3]
```

---

### Window 3

```text id="gm8bte"
i = 2

[-1, -3, 5]
```

Maximum:

```text id="ol5jsj"
5
```

Answer:

```text id="3k38ea"
ans = [3, 3, 5]
```

---

# Brute Force Complexity

There are approximately:

```text id="1kwhbd"
N - K + 1
```

windows.

For every window, we check `K` elements.

Therefore:

```text id="enprcw"
Time Complexity = O(N × K)
```

Extra space, excluding the output:

```text id="tj3mca"
Space Complexity = O(1)
```

For large inputs, this approach can cause **TLE**.

---

# Approach 2 — Optimal Using Deque

We can optimize the solution using a:

```cpp id="kl3ikd"
deque<int> dq;
```

The deque maintains useful candidates for the maximum element of the current window.

The important point is:

> We store **indices**, not values, inside the deque.

For example:

```text id="53n4ji"
nums = [1, 3, -1]
```

The deque may contain:

```text id="zvn43b"
[1, 2]
```

These are indices.

Their corresponding values are:

```text id="glj8mi"
nums[1] = 3
nums[2] = -1
```

---

# Why Store Indices?

Because we need to know when an element goes **outside the current window**.

Suppose:

```text id="b7y0bn"
index = 4
k = 3
```

Current window contains indices:

```text id="ak31is"
2, 3, 4
```

Any index:

```text id="zzsyq5"
<= index - k
```

is outside the window.

Here:

```text id="cxycl4"
index - k
= 4 - 3
= 1
```

So index `1` must be removed.

This can be checked easily using:

```cpp id="oxn9n3"
if(dq.front() <= index - k) {
    dq.pop_front();
}
```

---

# Monotonic Decreasing Deque

The deque maintains elements in **decreasing order of their values**.

Conceptually:

```text id="ufn3mr"
Front                         Back
 ↓                              ↓

Largest → Smaller → Smaller → Smallest
```

Therefore, the maximum element is always at:

```cpp id="xdnpt4"
dq.front()
```

and its value is:

```cpp id="ak6h69"
nums[dq.front()]
```

---

# Rule 1 — Remove Smaller Elements

Suppose the deque contains:

```text id="4o4s5f"
3, -1, -3
```

and a new element arrives:

```text id="db2yfe"
5
```

Since `5` is greater than:

```text id="b19tf3"
-3
-1
3
```

none of those smaller elements can become the maximum while `5` remains inside the window.

So remove them from the back.

```cpp id="hnkgyy"
while(!dq.empty() && nums[dq.back()] < nums[index]) {
    dq.pop_back();
}
```

Then push the new index:

```cpp id="o8idlt"
dq.push_back(index);
```

---

# Rule 2 — Remove Out-of-Window Elements

When the window moves forward, some old index may leave the window.

Remove it from the front:

```cpp id="8tmqfb"
if(!dq.empty() && dq.front() <= index - k) {
    dq.pop_front();
}
```

---

# Rule 3 — Front Always Contains Maximum

After maintaining the deque:

```cpp id="l16i3p"
nums[dq.front()]
```

is the maximum element of the current window.

So:

```cpp id="vkwujp"
ans.push_back(nums[dq.front()]);
```

---

# Optimal C++ Solution

```cpp id="jmywz9"
class Solution {
public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> dq;
        vector<int> ans;

        // Process first window
        for(int index = 0; index < k; index++) {

            while(!dq.empty() &&
                  nums[dq.back()] < nums[index]) {

                dq.pop_back();
            }

            dq.push_back(index);
        }

        ans.push_back(nums[dq.front()]);


        // Process remaining elements
        for(int index = k; index < nums.size(); index++) {

            // Remove element outside current window
            if(!dq.empty() &&
               dq.front() <= index - k) {

                dq.pop_front();
            }

            // Remove smaller elements
            while(!dq.empty() &&
                  nums[dq.back()] < nums[index]) {

                dq.pop_back();
            }

            // Add current index
            dq.push_back(index);

            // Front contains maximum
            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};
```

---

# Complete Dry Run

Consider:

```text id="z2yp76"
nums = [1, 3, -1, -3, 5, 3, 6, 7]

k = 3
```

Remember:

```text id="8iyxeg"
Deque stores INDICES.
```

---

## Build First Window

### index = 0

Current:

```text id="hjq7kc"
nums[0] = 1
```

Deque is empty.

Push index `0`.

```text id="rfub8f"
dq indices = [0]

dq values = [1]
```

---

### index = 1

Current:

```text id="vrns98"
nums[1] = 3
```

Compare with back:

```text id="8r8vmt"
nums[0] < nums[1]

1 < 3 ✅
```

Remove index `0`.

```text id="v7j9pb"
dq = []
```

Push index `1`.

```text id="a1cr6f"
dq indices = [1]

dq values = [3]
```

---

### index = 2

Current:

```text id="c5ux7u"
nums[2] = -1
```

Compare:

```text id="hv8tlb"
3 < -1 ❌
```

Don't remove `3`.

Push index `2`.

```text id="yfl9r9"
dq indices = [1, 2]

dq values = [3, -1]
```

First window:

```text id="0dz6b2"
[1, 3, -1]
```

Maximum:

```text id="gklh3d"
nums[dq.front()]
= nums[1]
= 3
```

Answer:

```text id="rm8kjr"
ans = [3]
```

---

# index = 3

Current:

```text id="s0ik1g"
nums[3] = -3
```

Current window should be:

```text id="57ymte"
[3, -1, -3]
```

Check outdated index:

```text id="pr2py6"
index - k
= 3 - 3
= 0
```

Deque front:

```text id="4b6nfg"
1
```

Check:

```text id="oqn7b5"
1 <= 0 ❌
```

Nothing removed.

Now compare from back:

```text id="nxrb8n"
-1 < -3 ❌
```

Push `3`.

```text id="x73fv9"
dq indices = [1, 2, 3]

dq values = [3, -1, -3]
```

Maximum:

```text id="tm78zx"
3
```

Answer:

```text id="cbf55w"
[3, 3]
```

---

# index = 4

Current:

```text id="n9yy0w"
nums[4] = 5
```

Window:

```text id="t2qhrx"
[-1, -3, 5]
```

Check outdated:

```text id="t88g71"
index - k
= 4 - 3
= 1
```

Deque front:

```text id="e3qqnm"
1
```

Therefore:

```text id="6s0sf6"
1 <= 1 ✅
```

Remove front.

Deque becomes:

```text id="gvjwr3"
indices = [2,3]

values = [-1,-3]
```

Now remove smaller elements from the back.

Compare:

```text id="5yky6d"
-3 < 5 ✅
```

Pop.

```text id="w8i04j"
dq values = [-1]
```

Again:

```text id="r9mlne"
-1 < 5 ✅
```

Pop.

```text id="nx7gns"
dq = []
```

Push index `4`.

```text id="ahqfh5"
dq indices = [4]

dq values = [5]
```

Maximum:

```text id="q0osgi"
5
```

Answer:

```text id="5ugyxl"
[3, 3, 5]
```

---

# index = 5

Current:

```text id="4osuh4"
nums[5] = 3
```

Window:

```text id="emepk1"
[-3, 5, 3]
```

Check outdated:

```text id="6uhf29"
index-k
= 5-3
= 2
```

Deque front:

```text id="09eim7"
4
```

```text id="5nwuhq"
4 <= 2 ❌
```

Nothing removed.

Compare:

```text id="qowwd7"
5 < 3 ❌
```

Push index `5`.

```text id="dmsf2u"
dq indices = [4,5]

dq values = [5,3]
```

Maximum:

```text id="5mftk6"
5
```

Answer:

```text id="wrr1bz"
[3,3,5,5]
```

---

# index = 6

Current:

```text id="n33udc"
nums[6] = 6
```

Window:

```text id="3k16u8"
[5,3,6]
```

Check outdated:

```text id="ll7k5v"
index-k
= 6-3
= 3
```

Deque front:

```text id="pxczoj"
4
```

Still inside window.

Now remove smaller values:

```text id="57k03s"
3 < 6 → Pop
5 < 6 → Pop
```

Deque becomes empty.

Push `6`.

```text id="vcc4zd"
dq indices = [6]

dq values = [6]
```

Maximum:

```text id="vw5xzs"
6
```

Answer:

```text id="3tj1vs"
[3,3,5,5,6]
```

---

# index = 7

Current:

```text id="6fvh0c"
nums[7] = 7
```

Window:

```text id="78hmjz"
[3,6,7]
```

Check outdated:

```text id="5kx1ye"
index-k
= 7-3
= 4
```

Deque front is `6`, so it is still valid.

Compare:

```text id="vmrq58"
6 < 7
```

Pop `6`.

Push `7`.

```text id="d7x2f3"
dq indices = [7]

dq values = [7]
```

Maximum:

```text id="bz79ak"
7
```

Answer:

```text id="9c6h9a"
[3,3,5,5,6,7]
```

---

# Final Answer

```text id="pbwdla"
[3, 3, 5, 5, 6, 7]
```

---

# Dry Run Summary

| Current Index | Current Value | Deque Values  | Window Maximum |
| ------------: | ------------: | ------------- | -------------: |
|  First window |             — | `[3, -1]`     |            `3` |
|             3 |            -3 | `[3, -1, -3]` |            `3` |
|             4 |             5 | `[5]`         |            `5` |
|             5 |             3 | `[5, 3]`      |            `5` |
|             6 |             6 | `[6]`         |            `6` |
|             7 |             7 | `[7]`         |            `7` |

---

# Why is the Deque Approach O(N)?

Each element is:

```text id="1br68n"
Pushed into deque → At most once
Popped from deque → At most once
```

Therefore, even though there is a `while` loop inside the main loop, the total number of deque operations across the whole algorithm is proportional to `N`.

Hence:

```text id="7kl5ej"
Time Complexity = O(N)
```

The deque can contain at most `K` indices:

```text id="1v1xd3"
Space Complexity = O(K)
```

The output array contains:

```text id="zxnpys"
N - K + 1
```

elements.

---

# Key Concepts

* Sliding Window
* Deque
* Monotonic Decreasing Deque
* Array
* Window Maximum
* Index Tracking

---

# Important Pattern

For **Sliding Window Maximum**, maintain a **monotonically decreasing deque**.

The three rules to remember are:

```text id="3x2vb3"
1. Remove OUT-OF-WINDOW index from FRONT

2. Remove SMALLER elements from BACK

3. Push CURRENT index at BACK

4. nums[dq.front()] = MAXIMUM
```

Core pattern:

```cpp id="sz9zun"
// Remove outdated index
if(!dq.empty() && dq.front() <= index - k) {
    dq.pop_front();
}

// Remove smaller elements
while(!dq.empty() &&
      nums[dq.back()] < nums[index]) {

    dq.pop_back();
}

// Add current index
dq.push_back(index);

// Current window maximum
ans.push_back(nums[dq.front()]);
```

---

# Brute Force vs Optimal

| Approach            |       Time | Extra Space | Technique                    |
| ------------------- | ---------: | ----------: | ---------------------------- |
| Brute Force         | `O(N × K)` |      `O(1)` | Check every window           |
| **Monotonic Deque** | **`O(N)`** |  **`O(K)`** | Maintain maximum efficiently |

For interviews and competitive programming, the **Monotonic Deque `O(N)` solution** is the preferred approach.
