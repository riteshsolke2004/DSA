# 🐄 Aggressive Cows

## Problem Statement

Given an integer array `arr[]` representing the positions of stalls and an integer `k` representing the number of aggressive cows.

Place all `k` cows into the stalls such that the **minimum distance between any two cows is as large as possible**.

All stall positions are distinct.

---

## Example 1

### Input

```text
arr = [1, 2, 4, 8, 9]
k = 3
```

### Output

```text
3
```

### Explanation

One optimal placement is:

```text
Cow 1 → Stall 1
Cow 2 → Stall 4
Cow 3 → Stall 8
```

Distances:

```text
4 - 1 = 3
8 - 4 = 4
```

Minimum distance:

```text
min(3, 4) = 3
```

Therefore:

```text
Answer = 3
```

---

## Example 2

### Input

```text
arr = [10, 1, 2, 7, 5]
k = 3
```

First sort the stalls:

```text
arr = [1, 2, 5, 7, 10]
```

### Output

```text
4
```

One optimal placement is:

```text
Cow 1 → Stall 1
Cow 2 → Stall 5
Cow 3 → Stall 10
```

Distances:

```text
5 - 1  = 4
10 - 5 = 5
```

Minimum distance:

```text
min(4, 5) = 4
```

Therefore:

```text
Answer = 4
```

---

# Approach — Binary Search on Answer

This problem asks us to:

> **Maximize the minimum distance between cows.**

This is a classic **Binary Search on Answer** problem.

Instead of checking every possible arrangement of cows, we binary search over the possible minimum distance.

---

# Step 1 — Sort the Stall Positions

First:

```cpp
sort(arr.begin(), arr.end());
```

For example:

```text
arr = [10, 1, 2, 7, 5]
```

becomes:

```text
arr = [1, 2, 5, 7, 10]
```

Sorting is necessary because we need to calculate distances between stalls in increasing order.

---

# Step 2 — Define the Search Space

The minimum possible distance can start from:

```text
0
```

The maximum possible distance is:

```text
last stall - first stall
```

Therefore:

```cpp
int start = 0;
int end = arr[n - 1] - arr[0];
```

For:

```text
arr = [1, 2, 4, 8, 9]
```

we get:

```text
start = 0

end = 9 - 1
    = 8
```

So our binary-search space is:

```text
[0 ........ 8]
```

> We can also start from `1` when `k >= 2`, because stall positions are distinct.

---

# Step 3 — Check Whether a Distance Is Possible

We use:

```cpp
isvalidAns(arr, k, minDistance)
```

This function answers:

> Can we place at least `k` cows such that every newly placed cow is at least `minDistance` away from the previously placed cow?

We always place the first cow at the first stall:

```cpp
int cow = 1;
int lastindex = 0;
```

Then traverse the remaining stalls.

```cpp
if(arr[i] - arr[lastindex] >= minDistance)
```

If the distance is large enough, place another cow:

```cpp
cow++;
lastindex = i;
```

Once:

```cpp
cow == k
```

we know that the distance is possible.

---

# Why Greedy Placement Works

For a fixed `minDistance`, we place each cow in the **earliest possible stall**.

For example:

```text
arr = [1, 2, 4, 8, 9]
minDistance = 3
```

Place first cow:

```text
1
🐄
```

Check stall `2`:

```text
2 - 1 = 1

1 < 3 ❌
```

Don't place.

Check stall `4`:

```text
4 - 1 = 3

3 >= 3 ✅
```

Place second cow:

```text
1       4
🐄      🐄
```

Check stall `8`:

```text
8 - 4 = 4

4 >= 3 ✅
```

Place third cow:

```text
1       4               8
🐄      🐄              🐄
```

We successfully placed all `3` cows.

Therefore:

```text
minDistance = 3
```

is a valid answer.

---

# Binary Search Logic

Calculate:

```cpp
int mid = start + (end - start) / 2;
```

Here `mid` represents a possible **minimum distance between cows**.

Now there are two cases.

### Case 1 — `mid` is possible

```cpp
if(isvalidAns(arr, k, mid))
```

If we can place all cows with minimum distance `mid`, then:

```text
mid is valid ✅
```

But we want to **maximize** the minimum distance.

So save the answer:

```cpp
ans = mid;
```

and search for a larger distance:

```cpp
start = mid + 1;
```

---

### Case 2 — `mid` is not possible

If we cannot place all cows:

```text
mid is too large ❌
```

So search for a smaller distance:

```cpp
end = mid - 1;
```

---

# C++ Solution

```cpp
class Solution {
public:

    bool isvalidAns(vector<int> &arr, int k, int minDistance) {

        int cow = 1;
        int lastindex = 0;

        for(int i = 1; i < arr.size(); i++) {

            if(arr[i] - arr[lastindex] >= minDistance) {

                cow++;
                lastindex = i;
            }

            if(cow == k) {
                return true;
            }
        }

        return false;
    }


    int aggressiveCows(vector<int> &arr, int k) {

        sort(arr.begin(), arr.end());

        int n = arr.size();

        int start = 0;
        int end = arr[n - 1] - arr[0];

        int ans = -1;

        while(start <= end) {

            int mid = start + (end - start) / 2;

            if(isvalidAns(arr, k, mid)) {

                ans = mid;

                // Try to maximize the minimum distance
                start = mid + 1;
            }
            else {

                // Current distance is too large
                end = mid - 1;
            }
        }

        return ans;
    }
};
```

---

# Dry Run

Consider:

```text
arr = [1, 2, 4, 8, 9]
k = 3
```

The array is already sorted.

Initial values:

```text
start = 0
end   = 9 - 1 = 8
ans   = -1
```

---

### Iteration 1

```text
mid = (0 + 8) / 2
    = 4
```

Check whether cows can be placed with minimum distance `4`.

Placement:

```text
Cow 1 → 1
Cow 2 → 8
```

There is no valid stall for the third cow.

Therefore:

```text
4 → Invalid ❌
```

Move left:

```text
end = 4 - 1
    = 3
```

---

### Iteration 2

```text
start = 0
end   = 3

mid = 1
```

Possible placement:

```text
Cow 1 → 1
Cow 2 → 2
Cow 3 → 4
```

All cows can be placed.

Therefore:

```text
1 → Valid ✅
```

Save:

```text
ans = 1
```

Since we want a larger minimum distance:

```text
start = 2
```

---

### Iteration 3

```text
start = 2
end   = 3

mid = 2
```

Possible placement:

```text
Cow 1 → 1
Cow 2 → 4
Cow 3 → 8
```

Valid.

Therefore:

```text
ans = 2
start = 3
```

---

### Iteration 4

```text
start = 3
end   = 3

mid = 3
```

Possible placement:

```text
Cow 1 → 1
Cow 2 → 4
Cow 3 → 8
```

Distances:

```text
4 - 1 = 3
8 - 4 = 4
```

Valid.

Therefore:

```text
ans = 3
start = 4
```

Now:

```text
start = 4
end   = 3
```

Binary search stops.

Final answer:

```text
3
```

---

# Binary Search Table

| `start` | `end` | `mid` | Valid? | `ans` | Action       |
| ------: | ----: | ----: | :----: | ----: | ------------ |
|       0 |     8 |     4 |    ❌   |    -1 | Search left  |
|       0 |     3 |     1 |    ✅   |     1 | Search right |
|       2 |     3 |     2 |    ✅   |     2 | Search right |
|       3 |     3 |     3 |    ✅   |     3 | Search right |

Final:

```text
Answer = 3
```

---

# Complexity Analysis

Let:

```text
N = number of stalls
D = maximum stall position - minimum stall position
```

Sorting takes:

```text
O(N log N)
```

For every binary-search candidate, the validity function traverses the stalls:

```text
O(N)
```

Binary search over the distance takes:

```text
O(log D)
```

Therefore, total time complexity is:

```text
O(N log N + N log D)
```

### Space Complexity

Ignoring the sorting implementation's internal memory:

```text
O(1)
```

---

# Key Concepts

* Binary Search
* Binary Search on Answer
* Greedy Algorithm
* Sorting
* Maximize the Minimum
* Search Space Optimization

---

# Important Pattern

This problem asks:

> **Maximize the minimum distance**

That is a strong hint for **Binary Search on Answer**.

The pattern is:

```text
Possible minimum distance
          ↓
      Choose mid
          ↓
Can we place k cows with this distance?
        /       \
      YES        NO
       ↓          ↓
Save mid       Too large
       ↓          ↓
Go right       Go left
       ↓
Find maximum valid answer
```

The most important binary-search logic to remember is:

```cpp
if(isvalidAns(arr, k, mid)) {

    ans = mid;

    // Valid, but we want an even larger distance
    start = mid + 1;
}
else {

    // Distance is too large
    end = mid - 1;
}
```

## Connection with Allocate Minimum Pages

Both problems use **Binary Search on Answer**, but their objective is opposite:

```text
Allocate Minimum Pages
→ Minimize the maximum
→ Valid answer → Search LEFT


Aggressive Cows
→ Maximize the minimum
→ Valid answer → Search RIGHT
```

This distinction is one of the most useful patterns to remember for binary-search-on-answer problems.
