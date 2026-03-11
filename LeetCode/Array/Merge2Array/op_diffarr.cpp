// Online C++ compiler to run C++ program online
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printArray(int arr[],int size) {
   for(int k = 0; k < size; k++) {
        cout << arr[k] << "\t";
    }
}

void merge(int arr[], int brr[],int n,int m) {
    int crr[9];
    int k=0,i=0,j=0;
    
    while(i<n && j<m) {
        if(arr[i] < brr[j]) {
            crr[k++] = arr[i++];
        }
        else{
            crr[k++] = brr[j++];
        }
    }   
    
    while(i<n) {
        crr[k++] = arr[i++];
    }
    
    while(j<m) {
        brr[k++] = brr[j++];
    }
    
    printArray(crr,9);
}

int main() {
    // deque<int> d;
    int arr[5] = {1,3,6,8,10};
    int brr[4] = {2,4,5,7};
    // int brr[4] = {1,3,4,2};
    
    merge(arr,brr,5,4);
    // reverse(brr,4);
    
    
}