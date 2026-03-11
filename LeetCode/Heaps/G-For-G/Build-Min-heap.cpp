#include <bits/stdc++.h> 

void heapify(vector<int> &arr, int n, int i) {
    int smallest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if(leftChild < n && arr[leftChild] < arr[smallest]) {
        smallest = leftChild;
    }

    if(rightChild < n && arr[rightChild] < arr[smallest]) {
        smallest = rightChild;
    }

    if(i != smallest) {
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);
    }
}

vector<int> buildMinHeap(vector<int> &arr) {
    int n = arr.size();

    for(int i = n/2-1; i>=0; i--) heapify(arr, n, i);

    return arr;
}
