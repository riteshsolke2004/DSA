# 🍌 Koko Eating Bananas

## Problem Statement

Koko loves to eat bananas.

You are given an integer array `piles[]`, where:

```text
piles[i] = number of bananas in the i-th pile
```

You are also given an integer `h`, representing the total number of hours available.

Koko chooses an eating speed of `k` bananas per hour.

In each hour:

* Koko chooses one pile.
* She eats `k` bananas from that pile.
* If the pile contains fewer than `k` bananas, she eats all remaining bananas from that pile.
* Koko cannot start eating from another pile during the same hour.

The task is to find the **minimum eating speed `k`** such that Koko can finish all the bananas within `h` hours.

---

## Example 1

### Input

```text
piles = [3, 6, 7, 11]
h = 8
```

### Output

```text
4
```

### Explanation

If Koko eats at a speed of:

```text
4 bananas/hour
```

then:

```text
Pile 3  → ceil(3 / 4)  = 1 hour
Pile 6  → ceil(6 / 4)  = 2 hours
Pile 7  → ceil(7 / 4)  = 2 hours
Pile 11 → ceil(11 / 4) = 3 hours
```

Total:

```text
1 + 2 + 2 + 3 = 8 hours
```

Since:

```text
8 <= h
```

speed `4` is valid.

Speed `3` would require:

```text
ceil(3/3)  = 1
ceil(6/3)  = 2
ceil(7/3)  = 3
ceil(11/3) = 4

Total = 10 hours
```

So speed `3` is not valid.

Therefore:

```text
Answer = 4
```

---

## Example 2

### Input

```text
piles = [30, 11, 23, 4, 20]
h = 5
```

### Output

```text
30
```

### Explanation

There are:

```text
5 piles
5 hours
```

Each pile requires at least one hour.

Therefore, every pile must be completed in exactly one hour.

The largest pile contains:

```text
30 bananas
```

So Koko must eat at least:

```text
30 bananas/hour
```

Therefore:

```text
Answer = 30
```

---

# Approach — Binary Search on Answer

This problem asks us to find:

> The **minimum eating speed** that allows Koko to finish all bananas within `h` hours.

Instead of checking every possible speed one by one, we apply **Binary Search on Answer**.

---

# Step 1 — Define the Search Space

The minimum possible eating speed is:

```text
1 banana/hour
```

Therefore:

```cpp
start = 1;
```

The maximum useful eating speed is the size of the largest pile:

```cpp
end = max(piles);
```

Why?

Suppose:

```text
piles = [3, 6, 7, 11]
```

The largest pile is:

```text
11
```

If Koko eats:

```text
11 bananas/hour
```

then every pile can be completed in at most one hour.

There is no need to search for speeds greater than the largest pile.

So:

```text
Search Space = [1, max(piles)]
```

---

# Step 2 — Calculate Hours Required

For every possible eating speed, we calculate how many hours Koko needs.

Suppose:

```text
pile = 11
speed = 4
```

Koko eats:

```text
Hour 1 → 4 bananas
Hour 2 → 4 bananas
Hour 3 → 3 bananas
```

Therefore:

```text
11 bananas → 3 hours
```

Mathematically, we need ceiling division:

```text
hours = ceil(pile / speed)
```

Instead of using floating-point calculations, we use:

```cpp
(pile + speed - 1) / speed
```

For example:

```text
pile = 11
speed = 4

(11 + 4 - 1) / 4
= 14 / 4
= 3
```

So the code becomes:

```cpp
hours += ((long long)piles[i] + speed - 1) / speed;
```

---

# Step 3 — Validity Check

We create:

```cpp
isValid(piles, h, speed)
```

This function checks:

> Can Koko finish all bananas within `h` hours at the given `speed`?

We calculate the required hours for every pile.

```cpp
hours += ((long long)piles[i] + speed - 1) / speed;
```

If:

```text
hours > h
```

then Koko cannot finish within the available time.

Therefore:

```cpp
return false;
```

Otherwise:

```cpp
return true;
```

---

# Why Use `long long` for Hours?

The total required hours can become large when there are many piles and the eating speed is small.

Therefore:

```cpp
long long hours = 0;
```

is safer than:

```cpp
int hours = 0;
```

We also cast `piles[i]` to `long long`:

```cpp
((long long)piles[i] + speed - 1)
```

to avoid integer overflow during addition.

---

# Binary Search Logic

For every iteration:

```cpp
int mid = start + (end - start) / 2;
```

Here:

```text
mid = possible eating speed
```

Now check:

```cpp
isValid(piles, h, mid)
```

There are two cases.

---

## Case 1 — Speed is Valid

If:

```cpp
isValid(piles, h, mid) == true
```

Koko can finish within `h` hours.

So:

```cpp
ans = mid;
```

But we want the **minimum possible speed**.

Therefore, search for a smaller valid speed:

```cpp
end = mid - 1;
```

So:

```text
VALID → Save answer → Search LEFT
```

---

## Case 2 — Speed is Invalid

If Koko cannot finish within `h` hours:

```text
hours > h
```

then the current speed is too slow.

Therefore, we need to increase the speed:

```cpp
start = mid + 1;
```

So:

```text
INVALID → Speed too slow → Search RIGHT
```

---

# C++ Solution

```cpp
class Solution {
public:

    bool isValid(vector<int>& piles, int h, int speed) {

        long long hours = 0;

        for(int i = 0; i < piles.size(); i++) {

            hours += ((long long)piles[i] + speed - 1) / speed;

            if(hours > h) {
                return false;
            }
        }

        return true;
    }


    int minEatingSpeed(vector<int>& piles, int h) {

        int start = 1;

        int end = *max_element(piles.begin(), piles.end());

        int ans = end;

        while(start <= end) {

            int mid = start + (end - start) / 2;

            if(isValid(piles, h, mid)) {

                ans = mid;

                // Valid speed, try a smaller speed
                end = mid - 1;
            }
            else {

                // Speed is too slow
                start = mid + 1;
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
piles = [30, 11, 23, 4, 20]
h = 5
```

Initial search space:

```text
start = 1
end   = 30
ans   = 30
```

---

## Iteration 1

```text
start = 1
end   = 30

mid = 15
```

Check speed `15`:

```text
30 → ceil(30/15) = 2
11 → ceil(11/15) = 1
23 → ceil(23/15) = 2
4  → ceil(4/15)  = 1
20 → ceil(20/15) = 2
```

Required hours:

```text
2 + 1 + 2 + 1 + 2 = 8
```

Since:

```text
8 > 5
```

speed `15` is invalid.

Therefore:

```text
start = 16
```

---

## Iteration 2

```text
start = 16
end   = 30

mid = 23
```

Hours:

```text
30 → 2
11 → 1
23 → 1
4  → 1
20 → 1
```

Total:

```text
6 hours
```

Since:

```text
6 > 5
```

speed `23` is invalid.

Move right:

```text
start = 24
```

---

## Iteration 3

```text
start = 24
end   = 30

mid = 27
```

Hours:

```text
30 → 2
11 → 1
23 → 1
4  → 1
20 → 1
```

Total:

```text
6 hours
```

Invalid.

Therefore:

```text
start = 28
```

---

## Iteration 4

```text
start = 28
end   = 30

mid = 29
```

Hours:

```text
30 → 2
11 → 1
23 → 1
4  → 1
20 → 1
```

Total:

```text
6 hours
```

Invalid.

Therefore:

```text
start = 30
```

---

## Iteration 5

```text
start = 30
end   = 30

mid = 30
```

Hours:

```text
30 → 1
11 → 1
23 → 1
4  → 1
20 → 1
```

Total:

```text
5 hours
```

Since:

```text
5 <= 5
```

speed `30` is valid.

Save:

```text
ans = 30
```

Try searching for a smaller answer:

```text
end = 29
```

Now:

```text
start = 30
end   = 29
```

Binary search stops.

Therefore:

```text
Answer = 30
```

---

# Binary Search Table

| Start | End | Speed (`mid`) | Hours Required | Valid? | Action             |
| ----: | --: | ------------: | -------------: | :----: | ------------------ |
|     1 |  30 |            15 |              8 |    ❌   | Search Right       |
|    16 |  30 |            23 |              6 |    ❌   | Search Right       |
|    24 |  30 |            27 |              6 |    ❌   | Search Right       |
|    28 |  30 |            29 |              6 |    ❌   | Search Right       |
|    30 |  30 |            30 |              5 |    ✅   | Save & Search Left |

Final answer:

```text
30
```

---

# Why Binary Search Works

As Koko's eating speed increases, the required hours decrease.

Conceptually:

```text
Speed
  ↓

1   2   3   4   5   6   7   ........ maxPile
❌  ❌  ❌  ❌  ❌  ✅  ✅   ........ ✅
                     ↑
               First valid speed
```

Once a particular speed becomes valid, every larger speed will also be valid.

This gives us a monotonic search space:

```text
INVALID INVALID INVALID | VALID VALID VALID
```

Binary search can efficiently find the **first valid value**.

---

# Complexity Analysis

Let:

```text
N = number of piles
M = maximum number of bananas in a pile
```

The validity function checks every pile:

```text
O(N)
```

Binary search operates over:

```text
[1, M]
```

which takes:

```text
O(log M)
```

Therefore, total time complexity is:

```text
O(N × log M)
```

### Space Complexity

```text
O(1)
```

No additional data structure proportional to the input size is required.

---

# Key Concepts

* Binary Search
* Binary Search on Answer
* Ceiling Division
* Minimize the Answer
* Monotonic Search Space
* Search Space Optimization

---

# Important Formula

To calculate:

```text
ceil(a / b)
```

using integer arithmetic:

```cpp
(a + b - 1) / b
```

For Koko:

```cpp
hours += ((long long)piles[i] + speed - 1) / speed;
```

---

# Important Pattern

Koko Eating Bananas is a:

```text
Minimum Valid Answer
```

problem.

So the binary-search pattern is:

```text
Choose speed = mid
        ↓
Can Koko finish within h hours?
       / \
     YES  NO
      ↓    ↓
Save mid  Speed too slow
      ↓    ↓
Go LEFT  Go RIGHT
      ↓
Find minimum valid speed
```

The core code to remember is:

```cpp
if(isValid(piles, h, mid)) {

    ans = mid;

    // We need minimum valid speed
    end = mid - 1;
}
else {

    // Current speed is too slow
    start = mid + 1;
}
```

---

# Connection With Other Binary Search on Answer Problems

### Allocate Minimum Pages

```text
Goal → Minimize the maximum pages

Valid answer
    ↓
Search LEFT
```

### Koko Eating Bananas

```text
Goal → Minimize the eating speed

Valid answer
    ↓
Search LEFT
```

### Aggressive Cows

```text
Goal → Maximize the minimum distance

Valid answer
    ↓
Search RIGHT
```

A useful rule:

```text
Minimize something
→ Valid → Search LEFT

Maximize something
→ Valid → Search RIGHT
```
