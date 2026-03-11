// Online C++ compiler to run C++ program online
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    // Write C++ code here
    int arr[5] = {4,1,7,3,9};
    int size = 5;
    
    for(int i = 1; i<size; i++) {
        bool isswap = false;
        for(int j = 0; j<size-i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                isswap = true;
            }
        }
        if(isswap == false) {
            break;
        }
    }
    
    for(int x: arr) {
        cout << x << "\t";
    }
    
}