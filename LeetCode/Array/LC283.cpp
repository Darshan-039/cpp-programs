// Online C++ compiler to run C++ program online
// MoveZeros
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printArray(int arr[],int size) {
   for(int k = 0; k < size; k++) {
        cout << arr[k] << "\t";
    }
}

void sort0(int arr[],int n) {
    int i = 0;
    int pos = 0;
    
    
    while(i<n){
        if(arr[i] != 0) {
            swap(arr[pos++] , arr[i++]);
        }
        else{
            i++;
        }
    }
    
    printArray(arr,6);
}

int main() {
    // deque<int> d;
    int arr[6] = {0,1,0,3,12,0};
    
    sort0(arr,6);
    
    
}