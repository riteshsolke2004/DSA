```cpp
#include <iostream>
using namespace std ;

class Stack {
    public :
    
    int *arr ;
    int top1 ;
    int top2 ;
    int size ;
    
    Stack(int capacity){
        arr = new int [capacity] ;
        size = capacity ;
        top1 = -1 ;
        top2 = size ;
    }
    
    void push1(int value) {
        
        if(top2 - top1 == 1){
            cout << "Stack is overflow" ;
        }
        else{
            top1++ ;
            arr[top1] = value ;
        }
    }
    
    void pop1(){
        if(top1 == -1){
            cout << "Stack is underflow" ;
        }
        else{
            top1-- ;
        }
    }
    
    void push2(int value){
        if(top2 - top1 == 1){
            cout << "Stack is overflow" ;
        }
        else{
            top2-- ;
            arr[top2] = value ;
        }
    }
    
    void pop2(){
        if(top2 == size){
            cout << "Stack is Empty";
        }
        else{
            top2++ ;
        }
    }
    
    void print(){
        for(int i=0; i<size ; i++){
            cout << arr[i]  << " ";
        }
        cout << endl ;
        cout << "Top 1 :- " << top1 ;
        cout << "Top 2 :- " << top2 ;
    }
};

int main() {
    
    Stack s(10) ;
    s.push1(10) ;
    s.push1(20) ;
    s.push1(30) ;
    s.push1(40) ;
    s.push1(50) ;
    
    s.push2(100) ;
    s.push2(90) ;
    s.push2(80) ;
    s.push2(70) ;
    s.push2(60) ;
    
    s.pop1() ;
    s.pop2() ;
    
    s.print();
}
```
