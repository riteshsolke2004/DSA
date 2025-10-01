Insert an Element at the Bottom of a Stack
You are given a stack st of n integers and an element x. You have to insert x at the bottom of the given stack. 

Example 1:

Input:
n = 5
x = 2
st = {4,3,2,1,8}
Output:
{2,4,3,2,1,8}
Explanation:
After insertion of 2, the final stack will be {2,4,3,2,1,8}.
Example 2:

Input:
n = 3
x = 4
st = {5,3,1}
Output:
{4,5,3,1}
Explanation:
After insertion of 4, the final stack will be {4,5,3,1}.
Your Task:

You don't need to read input or print anything. Your task is to complete the function insertAtBottom() which takes a stack st and an integer x as inputs and returns the modified stack after insertion.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)


#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std ;

void insertAtBottom(stack<int> &s , int value){

    if(s.empty()){
        s.push(value) ;
        return ;
    }

    int top = s.top() ;
    s.pop() ;

    insertAtBottom(s,value) ;

    s.push(top) ;
    
}


int main() {
    stack<int> s;

    int value = 101 ;

    s.push(10) ;
    s.push(20);
    s.push(30);

    insertAtBottom(s , value) ;

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop() ;
    }
    cout << endl ;

    return 0 ;

}
