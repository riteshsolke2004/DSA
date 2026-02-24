```cpp
#include <iostream>
#include <stack>
#include <vector>
using namespace std ;

void sortedinsert(stack<int>& s , int value){

    if(s.empty()){
        s.push(value) ;
        return ;
    }

    if(value >= s.top()){
        s.push(value) ;
        return ;
    }
    else{
        int topvalue = s.top() ;
        s.pop() ;

        sortedinsert(s,value) ;
        s.push(topvalue) ;
    }    

}

int main(){

    stack<int> s ;

    s.push(10) ;
    s.push(20) ;
    s.push(30) ;
    s.push(40) ;
    s.push(50) ; 

    sortedinsert(s,25) ;
    cout << "Printing the Stack" << endl ;
    while(!s.empty()){
        cout << s.top() << " " ;
        s.pop() ;
    }
    cout << endl ;


    return 0;

}
```
