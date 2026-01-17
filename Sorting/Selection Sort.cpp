#include <iostream>
#include <vector>
using namespace std ;

void selectionSort(int arr[], int n){
    
    for(int i=0; i<n-1; i++){
        int minindex = i;
        
        for(int j= i+1; j<n;j++){
            
            if(arr[j] < arr[minindex]){
                minindex = j ;
            }
        }
        swap(arr[i], arr[minindex] );
    }
}

int main() {
    
    int arr[] = {3,58,5,2,14,1,0} ;
    int n = sizeof(arr)/ sizeof(int);

selectionSort(arr,n) ;
    for(int a: arr){
        cout << a <<"," ;
    }
    
    
    return 0 ;
}
