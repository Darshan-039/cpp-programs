#include <bits/stdc++.h>
using namespace std;

// Function to maintain min-heap property
void heapify(vector<int> &arr, int n, int i) {
    int smallest = i;              // Assume current index is smallest
    int leftChild = 2 * i + 1;     // Left child index
    int rightChild = 2 * i + 2;    // Right child index

    // Check if left child exists and is smaller
    if (leftChild < n && arr[leftChild] < arr[smallest]) {
        smallest = leftChild;
    }

    // Check if right child exists and is smaller
    if (rightChild < n && arr[rightChild] < arr[smallest]) {
        smallest = rightChild;
    }

    // If smallest is not the current node, swap and recurse
    if (i != smallest) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

// Function to build min heap
vector<int> buildMinHeap(vector<int> &arr) {
    int n = arr.size();

    // Start from last non-leaf node and heapify
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    return arr;
}

int main() {
    int n;

    // Input size of array
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    // Input elements
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Build Min Heap
    buildMinHeap(arr);

    // Output Min Heap
    cout << "Min Heap array: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}