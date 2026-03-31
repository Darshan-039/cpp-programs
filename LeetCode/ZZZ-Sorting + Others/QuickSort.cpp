// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int partition(int *arr, int s,int e) {
    int pivot = arr[s];
    int count = 0;
    
    for(int i = s+1; i<=e; i++) {
        if(arr[i] <= pivot) {
            count++;
        }
    }
    
    // Place pivot at right Index
    int RightIdx = s+count;
    swap(arr[s],arr[RightIdx]);
    
    int i = s;
    int j = e;
    while(i <RightIdx && e > RightIdx) {
        while(arr[i] <= pivot) {
            i++;
        }
        while(arr[j] > pivot) {
            j--;
        }
        if(i <RightIdx && e > RightIdx) {
            swap(arr[i++], arr[j--]);
        }
    }
    
    return RightIdx;
}

void quickSort(int *arr, int s,int e) {
    if(s >= e) {
        return ;
    }
    
    int p = partition(arr,s,e);
    
    // Left vala Part sort kro
    quickSort(arr,s,p-1);
    
    // Right vala part sort kro
    quickSort(arr,p+1,e);
}

int main() {
    int arr[6] = {2,1,5,3,9,8};
    
    quickSort(arr,0,5);
    
    for(int x: arr) {
        cout << x << " ";
    }
}