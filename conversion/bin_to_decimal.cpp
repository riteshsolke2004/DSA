#include <iostream>
#include <cmath>
using namespace std ;

int main()
{
    int binary, digit, power = 0, decimal = 0 ;
    
    cout<< "Enter Binary number";
    cin>> binary ;
    
    while(binary > 0){
        
        digit = binary % 10 ;
        decimal += digit * pow(2,power);
        binary /= 10 ;
        power++ ;
    }
    
    cout << "decimal value is :- "<< decimal ;
    
    
    

    return 0;
}
