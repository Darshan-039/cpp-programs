// Online C++ compiler to run C++ program online
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    // Write C++ code here
    int arr[5] = {4,1,7,3,9};
    int size = 5;
    
    for(int i = 0; i<size; i++) {
        int minIndex = i;
        for(int j = i+1; j<size; j++) {
            if(arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }
    
    for(int x: arr) {
        cout << x << "\t";
    }
    
}