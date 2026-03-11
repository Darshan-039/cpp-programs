// Median of two sorted Array
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printArray(vector<int> arr) {
    int size = arr.size();
    for(int k = 0; k < size; k++) {
        cout << arr[k] << "\t";
    }
}

void merge(vector<int> arr, vector<int> brr) {
    int k=0,i=0,j=0;
    int n = arr.size();
    int m = brr.size();
    int s = n+m;
    // vector<int> crr(s);
    int idx1 = (s/2)-1;
    int element1 = -1;
    int idx2 = s/2;
    int element2 = -1;
    
    while(i<n && j<m) {
        if(arr[i] < brr[j]) {
            if(k == idx1) element1 = arr[i];
            if(k == idx2) element2 = arr[i];
            i++;
        }
        else{
            if(k == idx1) element1 = brr[j];
            if(k == idx2) element2 = brr[j];
            j++;
        }
        k++;
    }   
    
    while(i<n) {
        if(k == idx1) element1 = arr[i];
        if(k == idx2) element2 = arr[i];
        // crr[k++] = arr[i++];
        i++;
        k++;
    }
    
    while(j<m) {
        if(k == idx1) element1 = brr[j];
        if(k == idx2) element2 = brr[j];
        // crr[k++] = brr[j++];
        j++;
        k++;
    }
    
    // printArray(crr);
    
    int mid = s/2;
    double median;
    if(s%2 == 0) {
        median = (element1+element2)/2;
    }
    else {
        median = element2;
    }
    
    cout << endl << median << endl;
}

int main() {
    // deque<int> d;
    vector<int> arr = {1,2};
    vector<int> brr = {3,4};
    // int brr[4] = {1,3,4,2};
    
    merge(arr,brr);
    // reverse(brr,4);
    
    
}