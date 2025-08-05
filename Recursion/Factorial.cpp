Question :- calculate the factorial using the recursion. 

#include <iostream>
using namespace std ;

int factorial(int n) {
    
    if(n == 0){
        return 1 ;
    }
    int fact = factorial(n-1) ;
    return fact * n ;
}

int main() {
    
    int result = factorial(5) ;
    cout << "fact is :- "<< result ;
    return 0 ;
}
