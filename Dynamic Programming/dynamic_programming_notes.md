# Dynamic Programming (DP) – Notes

---

# 1. What is Dynamic Programming? 
 
Dynamic Programming (DP) is an optimization technique used to solve problems by breaking them into smaller subproblems and storing their results to avoid repeated calculations.

DP can be applied when a problem has:

* Overlapping Subproblems 
* Optimal Substructure

---

# 2. Overlapping Subproblems

If the same subproblem is solved multiple times, the problem has overlapping subproblems.

### Example: Fibonacci Series

```text
F(n) = F(n-1) + F(n-2)
```

In recursion, values such as `F(2)` are calculated repeatedly, causing extra work.

---

# 3. Optimal Substructure

A problem has optimal substructure if the optimal solution of the main problem can be obtained by combining optimal solutions of smaller subproblems.

### Example

```text
F(n) = F(n-1) + F(n-2)
```

The larger answer is built from smaller optimal answers.

---

# 4. Dynamic Programming Approaches

## A. Top-Down Approach (Memoization)

### Features

* Uses recursion.
* Stores already computed answers.
* Avoids repeated recursive calls.
* Requires extra memory (DP array).

### Process

1. Solve recursively.
2. Store answer in DP array.
3. If answer already exists, return it directly.

```text
Recursion + Memoization = Top-Down DP
```

---

## B. Bottom-Up Approach (Tabulation)

### Features

* Uses loops instead of recursion.
* Builds solution from base cases.
* Generally faster.
* No recursion stack overhead.

### Process

1. Create DP array.
2. Initialize base cases.
3. Fill the array iteratively.
4. Return final answer.

```text
Loop + DP Array = Bottom-Up DP
```

---

# 5. General DP Workflow

```text
Problem
   ↓
Recursion
   ↓
Recursion + Memoization (Top-Down)
   ↓
Bottom-Up (Tabulation)
   ↓
Space Optimization
```

---

# Fibonacci Problem

## Recurrence Relation

```text
fib(n) = fib(n-1) + fib(n-2)
```

---

## Base Cases

```text
fib(0) = 0
fib(1) = 1
```

---

# Recursive Solution

```cpp
int fib(int n) {

    if(n == 0)
        return 0;

    if(n == 1)
        return 1;

    return fib(n-1) + fib(n-2);
}
```

### Drawback

* Time Complexity: **O(2ⁿ)**
* Many repeated calculations occur.

---

# Memoization (Top-Down)

```cpp
int solve(int n, vector<int>& dp) {

    if(n == 0)
        return 0;

    if(n == 1)
        return 1;

    if(dp[n] != -1)
        return dp[n];

    dp[n] = solve(n-1, dp) + solve(n-2, dp);

    return dp[n];
}
```

### Complexity

* Time Complexity: **O(n)**
* Space Complexity: **O(n)**

---

# Tabulation (Bottom-Up)

```cpp
int fib(int n) {

    vector<int> dp(n + 1);

    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++) {

        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}
```

### Complexity

* Time Complexity: **O(n)**
* Space Complexity: **O(n)**

---

# Space Optimization

Since only the previous two values are required:

```cpp
int fib(int n) {

    int prev2 = 0;
    int prev1 = 1;

    for(int i = 2; i <= n; i++) {

        int curr = prev1 + prev2;

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}
```

### Complexity

* Time Complexity: **O(n)**
* Space Complexity: **O(1)**

---

# DP Learning Order

## Step 1

Write the recursive solution.

## Step 2

Apply Memoization (Top-Down).

## Step 3

Convert it into Tabulation (Bottom-Up).

## Step 4

Perform Space Optimization if possible.

---

# Key Points

## ✅ DP works when:

* Overlapping Subproblems exist.
* Optimal Substructure exists.

---

## ✅ DP Types

* 1D DP
* 2D DP
* 3D DP

---

## ✅ Main Techniques

1. Recursion
2. Memoization
3. Tabulation
4. Space Optimization

---

# Summary Flow

```text
Recursion
     ↓
Top-Down DP (Memoization)
     ↓
Bottom-Up DP (Tabulation)
     ↓
Space Optimization
```

---

# Formula to Remember

```text
Dynamic Programming =
Overlapping Subproblems
+
Optimal Substructure
```
