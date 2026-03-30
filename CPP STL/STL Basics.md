# 📘 C++ Standard Template Library (STL) – Complete Guide

The **Standard Template Library (STL)** is a powerful library in C++ that provides **generic classes and functions** to implement common data structures and algorithms efficiently.
      
STL follows the philosophy:   
> *“Don’t reinvent the wheel.”* 
     
It is built on **templates**, making it fast, reusable, and type-safe.
  
---                
  
## 📌 Components of STL

STL is mainly divided into **4 parts**:
1. Containers   
2. Algorithms    
3. Iterators     
4. Functors   
 
---

# 1️⃣ C++ STL Containers

Containers are **data structures** used to store objects in memory.

### 🔹 Types of Containers
- **Sequence Containers**
- **Associative Containers**
- **Unordered Containers**
- **Container Adapters**

---

## 🔸 1. Sequence Containers

Store elements in a **linear order**.

---

### ▶ `vector`
**Definition:**  
Dynamic array that can grow or shrink in size.

**Syntax:**
```cpp
vector<data_type> name;
```
### Example 
```cpp
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3};
    v.push_back(4);

    for(int x : v)
        cout << x << " ";
}
```
▶ list

Definition:
Doubly linked list for fast insertion/deletion.

Syntax:
```cpp
list<data_type> name;
```

Example:
```cpp
#include <list>
#include <iostream>
using namespace std;

int main() {
    list<int> l = {10, 20, 30};
    l.push_front(5);

    for(int x : l)
        cout << x << " ";
}
```
▶ deque

Definition:
Double-ended queue (insert/delete from both ends).

Example:
```cpp
#include <deque>
using namespace std;

int main() {
    deque<int> d;
    d.push_front(1);
    d.push_back(2);
}
```
▶ array

Definition:
Fixed-size array with STL features.

Example:
```cpp
#include <array>
using namespace std;

int main() {
    array<int, 3> arr = {1, 2, 3};
}
```
🔸 2. Associative Containers

Store elements in sorted order using keys.

▶ set

Definition:
Stores unique elements in sorted order.

Example:
```cpp
#include <set>
using namespace std;

int main() {
    set<int> s = {3, 1, 2};
}
```
▶ map

Definition:
Stores key-value pairs in sorted order.

Example:
```cpp
#include <map>
using namespace std;

int main() {
    map<int, string> m;
    m[1] = "One";
}
```

🔸 3. Unordered Containers

Based on hash tables (faster, not sorted).

▶ unordered_set
```cpp
#include <unordered_set>
using namespace std;

unordered_set<int> us = {1, 2, 3};
```
▶ unordered_map

```cpp
#include <unordered_map>
using namespace std;

unordered_map<int, string> um;
um[1] = "Apple";
```
🔸 4. Container Adapters

Built on top of other containers.

▶ stack

LIFO
```cpp
#include <stack>
using namespace std;

stack<int> st;
st.push(10);
```
▶ queue

FIFO
```cpp
#include <queue>
using namespace std;

queue<int> q;
q.push(10);
```
▶ priority_queue

```cpp
#include <queue>
using namespace std;

priority_queue<int> pq;
pq.push(5);
```
2️⃣ STL Algorithms

Algorithms work on ranges of elements.

Header file:
```cpp
#include <algorithm>
```
▶ sort()
```cpp
sort(arr.begin(), arr.end());
  ```
▶ reverse()
```cpp
reverse(v.begin(), v.end());
```
▶ find()
```cpp
auto it = find(v.begin(), v.end(), 10);
```
▶ count()
```cpp
int c = count(v.begin(), v.end(), 5);
```
▶ max_element() / min_element()
```cpp
*max_element(v.begin(), v.end());
```
▶ binary_search()
```cpp
binary_search(v.begin(), v.end(), 10);
```
3️⃣ STL Iterators

Iterators act like pointers used to access container elements.

🔹 Types of Iterators
Iterator Type	Description
Input	Read-only
Output	Write-only
Forward	Read & write (one direction)
Bidirectional	Forward + backward
Random Access	Direct access
▶ Common Functions

```cpp
container.begin()
container.end()
container.rbegin()
container.rend()
```
▶ Example
```cpp
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3};

    for(auto it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
}
```
4️⃣ Functors (Function Objects)

Definition:
A functor is an object that behaves like a function using operator().

▶ Why Functors?

Faster than normal functions

Can store state

Used heavily in STL algorithms

▶ Example
```cpp
#include <iostream>
using namespace std;

class Add {
public:
    int operator()(int a, int b) {
        return a + b;
    }
};

int main() {
    Add obj;
    cout << obj(3, 4);
}
```
▶ Functors with Algorithms
```cpp
sort(v.begin(), v.end(), greater<int>());
```
