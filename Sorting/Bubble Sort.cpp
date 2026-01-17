#include <iostream>
#include <vector>
using namespace std ;


void bubblesort(vector<int> &arr){
    int n = arr.size() ;
    
    for(int i=0; i<n-1; i++){
        
        for(int j=0; j<n-i-1; j++){
            
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
    
    
}


int main() {
    
    vector<int> arr = {3,6,5,2,4,1,0} ;
    
    bubblesort(arr) ;
    
    for(int a: arr){
        cout << a <<"," ;
    }
    
    
    return 0 ;
}
