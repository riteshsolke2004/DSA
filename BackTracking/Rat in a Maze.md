# 🐀 Rat in a Maze

## Problem Statement

Given a binary matrix `maze[][]` of size `n × n` containing `0` and `1`, find all possible paths for a rat to travel from the source cell `(0, 0)` to the destination cell `(n - 1, n - 1)`.

The rat can move in four directions:

```text
U → Up
D → Down
L → Left
R → Right
```

- `1` represents an open cell.
- `0` represents a blocked cell.
- The rat can move only through open cells.
- The same cell cannot be visited more than once in a single path.
- Return all valid paths.
- If no valid path exists, return an empty list.
- Paths must be returned in lexicographically increasing order.

---

# Examples

## Example 1

### Input

```text
maze[][] = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}}
```

### Output

```text
["DDRDRR", "DRDDRR"]
```

### Explanation

There are two valid paths from `(0, 0)` to `(3, 3)`:

<img width="595" height="251" alt="blobid0_1781254127" src="https://github.com/user-attachments/assets/13182111-d13a-47fc-b6c7-1d188a88daba" />


```text
DDRDRR
DRDDRR
```

---

## Example 2

### Input

```text
maze[][] = [[1, 0], [1, 0]]
```

### Output

```text
[]
```

### Explanation

The destination cell `(1, 1)` is blocked, so no valid path exists.

---

# 💡 Approach: Backtracking + DFS

The provided solution uses **Depth First Search (DFS)** with **Backtracking**.

For every current cell, it tries four directions:

```text
D → L → R → U
```

Before moving to a new cell, it checks:

1. The cell is inside the maze.
2. The cell contains `1`.
3. The cell has not already been visited in the current path.

The algorithm follows this pattern:

```text
Choose a cell
      ↓
Mark it visited
      ↓
Explore recursively
      ↓
Unmark it
      ↓
Try another path
```

This is the core idea of backtracking.

---

# 💻 Provided C++ Solution

```cpp
class Solution {
  public:

    bool isSafe(vector<vector<int>>& maze, int newX, int newY,
                int row, int col, vector<vector<bool>>& visited) {

        if (newX >= 0 && newX < row &&
            newY >= 0 && newY < col &&
            maze[newX][newY] == 1 &&
            visited[newX][newY] == false) {

            return true;
        }

        return false;
    }


    void solve(vector<vector<int>>& maze,
               int srcX, int srcY,
               int destX, int destY,
               int row, int col,
               vector<string>& ans,
               string path,
               vector<vector<bool>>& visited) {

        // Destination reached
        if (srcX == destX && srcY == destY) {
            ans.push_back(path);
            return;
        }


        // D → Down
        int newX = srcX + 1;
        int newY = srcY;

        if (isSafe(maze, newX, newY, row, col, visited)) {

            visited[newX][newY] = true;

            solve(maze, newX, newY, destX, destY,
                  row, col, ans, path + 'D', visited);

            visited[newX][newY] = false;
        }


        // L → Left
        newX = srcX;
        newY = srcY - 1;

        if (isSafe(maze, newX, newY, row, col, visited)) {

            visited[newX][newY] = true;

            solve(maze, newX, newY, destX, destY,
                  row, col, ans, path + 'L', visited);

            visited[newX][newY] = false;
        }


        // R → Right
        newX = srcX;
        newY = srcY + 1;

        if (isSafe(maze, newX, newY, row, col, visited)) {

            visited[newX][newY] = true;

            solve(maze, newX, newY, destX, destY,
                  row, col, ans, path + 'R', visited);

            visited[newX][newY] = false;
        }


        // U → Up
        newX = srcX - 1;
        newY = srcY;

        if (isSafe(maze, newX, newY, row, col, visited)) {

            visited[newX][newY] = true;

            solve(maze, newX, newY, destX, destY,
                  row, col, ans, path + 'U', visited);

            visited[newX][newY] = false;
        }
    }


    vector<string> ratInMaze(vector<vector<int>>& maze) {

        int row = maze.size();
        int col = maze[0].size();

        vector<string> ans;

        if (maze[0][0] == 0 || maze[row - 1][col - 1] == 0) {
            return ans;
        }

        vector<vector<bool>> visited(
            row, vector<bool>(col, false)
        );

        visited[0][0] = true;

        solve(maze, 0, 0,
              row - 1, col - 1,
              row, col,
              ans, "", visited);

        return ans;
    }
};
```

---

# 🧠 Code Explanation

## 1. `isSafe()` Function

Before moving to a new cell, the function checks:

```cpp
newX >= 0 && newX < row
```

The row must remain inside the maze.

```cpp
newY >= 0 && newY < col
```

The column must remain inside the maze.

```cpp
maze[newX][newY] == 1
```

The cell must be open.

```cpp
visited[newX][newY] == false
```

The cell must not already be part of the current path.

If all conditions are satisfied:

```cpp
return true;
```

Otherwise:

```cpp
return false;
```

---

## 2. Base Case

```cpp
if (srcX == destX && srcY == destY) {
    ans.push_back(path);
    return;
}
```

When the rat reaches the destination, the current path is valid.

For example:

```text
DDRDRR
```

The path is stored in:

```cpp
ans
```

Then recursion returns to explore other possible paths.

---

## 3. Try Down

```cpp
newX = srcX + 1;
newY = srcY;
```

If the next cell is safe:

```cpp
visited[newX][newY] = true;
```

Mark it as visited.

Then recursively explore:

```cpp
path + 'D'
```

After recursion:

```cpp
visited[newX][newY] = false;
```

This is the backtracking step.

---

## 4. Try Left, Right and Up

The same logic is repeated for:

```text
L → Left
R → Right
U → Up
```

For each direction:

```text
Check Safe
    ↓
Mark Visited
    ↓
Recursive Call
    ↓
Unmark Visited
```

---

# 🔍 Detailed Dry Run

Consider:

```text
maze = {
    {1, 0, 0, 0},
    {1, 1, 0, 1},
    {1, 1, 0, 0},
    {0, 1, 1, 1}
}
```

Start:

```text
(0, 0)
```

First path:

```text
(0,0)
  D
(1,0)
  D
(2,0)
  R
(2,1)
  D
(3,1)
  R
(3,2)
  R
(3,3)
```

Therefore:

```text
DDRDRR
```

is stored.

After backtracking, another valid path is found:

```text
DRDDRR
```

Final answer:

```text
["DDRDRR", "DRDDRR"]
```

---

# 🌳 Recursion Tree Concept

Every recursive call tries four possible directions:

```text
                 Current Cell
                      |
        +-------------+-------------+
        |             |             |
        D             L             R
        |
        ...
                      |
                      U
```

Conceptually:

```text
solve(current cell)
        |
        +---- Down
        |
        +---- Left
        |
        +---- Right
        |
        +---- Up
```

Only safe cells create recursive calls.

---

# 🔄 Algorithm

```text
1. Check whether the source or destination is blocked.

2. If blocked:
       Return an empty list.

3. Create a visited matrix.

4. Mark (0, 0) as visited.

5. Start DFS from (0, 0).

6. For every cell, try:
       D → L → R → U

7. Before moving, check:
       - Inside boundaries
       - Open cell
       - Not visited

8. Mark the next cell as visited.

9. Recursively explore the new cell.

10. Unmark the cell after returning.

11. If the destination is reached:
        Store the path.

12. Return all valid paths.
```

---

# 🔄 Flow Diagram

```text
Start
  |
  v
Check Source and Destination
  |
  +---- Blocked ----> Return []
  |
  v
Mark Source as Visited
  |
  v
Call solve(0, 0)
  |
  v
Reached Destination?
  |
 Yes -----------------> Store Path
  |                         |
 No                        Return
  |
  v
Try D → L → R → U
  |
  v
Is Next Cell Safe?
  |
 No ----> Try Next Direction
  |
 Yes
  |
  v
Mark Visited
  |
  v
Recursive Call
  |
  v
Backtrack
Unmark Cell
```

---

# 🔙 Understanding Backtracking

Backtracking means undoing a choice after exploring it.

In this code:

```cpp
visited[newX][newY] = true;
```

means:

```text
Choose the cell
```

The recursive call:

```cpp
solve(...)
```

means:

```text
Explore the path
```

Finally:

```cpp
visited[newX][newY] = false;
```

means:

```text
Undo the choice
```

This allows the same cell to be used in a different valid path.

---

# ⚠️ Important Edge Cases

## Source is Blocked

```text
maze[0][0] = 0
```

Return:

```text
[]
```

## Destination is Blocked

```text
maze[n - 1][n - 1] = 0
```

Return:

```text
[]
```

The provided code handles both cases:

```cpp
if (maze[0][0] == 0 || maze[row - 1][col - 1] == 0) {
    return ans;
}
```

## No Valid Path

Even when source and destination are open, walls may block all possible paths.

Return:

```text
[]
```

---

# 📌 Lexicographical Order

The required lexicographical order is achieved by exploring:

```text
D → L → R → U
```

Because:

```text
D < L < R < U
```

the DFS generates paths in lexicographically increasing order.

---

# ⚠️ Small Robustness Improvement

The provided code assumes that `maze` is not empty because it uses:

```cpp
maze[0].size()
```

If empty input must also be handled, add:

```cpp
if (maze.empty() || maze[0].empty()) {
    return {};
}
```

The original backtracking approach remains unchanged.

---

# ⏱️ Complexity Analysis

For an `n × n` maze, the algorithm may explore an exponential number of possible paths in the worst case.

```text
Time Complexity: O(4^(n²)) in the worst case
```

The visited matrix and recursion stack require:

```text
Space Complexity: O(n²)
```

excluding the space required to store all valid output paths.

---

# 🎯 Key Concepts

- Backtracking
- Recursion
- Depth First Search
- Matrix Traversal
- Visited Matrix
- Path Finding

---

# 🧠 Interview Notes

### Why use DFS?

DFS explores one complete path before returning and trying another possibility.

### Why use `visited`?

It prevents cycles and ensures that the same cell is not visited twice in one path.

### Why unmark a cell?

A cell used in one path may be needed in another valid path.

```cpp
visited[newX][newY] = false;
```

allows that.

### Why use `path + 'D'`?

It records the movement taken.

Example:

```text
"" + D = "D"
"D" + R = "DR"
"DR" + D = "DRD"
```

---

# ⭐ Quick Revision

```text
Start from (0, 0)

If destination reached:
    Store path

Try:

D → L → R → U

For every direction:

    Check safe

    If safe:
        Mark visited
        Recurse
        Unmark visited

Return all paths
```

---

# 📚 Related DSA Topics

- Backtracking
- Recursion
- DFS
- Graph Traversal
- Matrix Problems
- Path Finding

---

# 🔗 Conclusion

The provided solution uses **DFS with Backtracking** to find every valid path from the source to the destination.

The core pattern is:

```text
Check Safe
    ↓
Mark Visited
    ↓
Recursive Call
    ↓
Unmark Visited
```

By exploring directions in:

```text
D → L → R → U
```

the solution generates all valid paths in lexicographical order.

## Final Complexity

```text
Time Complexity  : Exponential in the worst case
Space Complexity : O(n²), excluding output storage
```

This is a standard and efficient backtracking approach for the **Rat in a Maze** problem.
