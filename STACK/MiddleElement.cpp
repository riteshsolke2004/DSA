#include <iostream>
#include <stack>
#include <vector>

using namespace std ;

void middleelement(stack <int> &s, int count, int toatalsize){

    if(count == toatalsize/2){
        cout << s.top() ;
        return ;
    }

    int value =  s.top() ;
    s.pop() ;
    count++ ;

    middleelement(s,count,toatalsize);
    s.push(value) ;
}

int main() {

    stack <int> s ;
    s.push(10) ;
    s.push(20);
    s.push(30);
    s.push(40) ;
    s.push(50) ;

    int count = 0 ;
    int totalsize = s.size() ;

     middleelement(s,count,totalsize) ;

    return 0 ;
}
