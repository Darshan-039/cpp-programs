// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void printarray(int arr[], int size) {
    for(int i = 0; i<size; i++) {
        cout << arr[i] << "\t";
    }
}

void mergearray(int arr[], int brr[], int m, int n) {
    int last = m+n-1;
    while(m>0 && n>0) {
        if(arr[m-1] < brr[n-1]) {
            arr[last] = brr[n-1];
            n--;
        }
        else{
            arr[last] = arr[m-1];
            m--;
        }
        last-=1;
    }
    
    while(n>0) {
        arr[last] = brr[n-1];
        last--;
        n--;
    }
    
    printarray(arr,6);
}

int main() {
   int arr[6] = {1,2,3,0,0,0};
   int brr[3] = {2,5,6};
   
   mergearray(arr,brr,3,3);
}