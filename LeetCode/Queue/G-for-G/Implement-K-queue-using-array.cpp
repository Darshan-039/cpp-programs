#include<bits/stdc++.h>
using namespace std;

class kQueues {
    int n, k, freeSpot;
    int *front, *rear, *arr, *next;

public:
    // Constructor to initialize the data structure
    kQueues(int n, int k) {
        this->n = n;
        this->k = k;
        
        // Initializing front and rear for k queues
        front = new int[k];
        rear = new int[k];
        for (int j = 0; j < k; j++) front[j] = rear[j] = -1;

        // Initializing next array to link free spots
        next = new int[n];
        for (int j = 0; j < n - 1; j++) next[j] = j + 1;
        next[n - 1] = -1; // Last element points to -1
        
        // Main array to store values
        arr = new int[n];
        
        // Initializing first free spot
        freeSpot = 0;
    }
    
    // Destructor to free up memory
    ~kQueues() {
        delete[] front;
        delete[] rear;
        delete[] arr;
        delete[] next;
    }

    // Enqueue x into i-th queue (i is 0-indexed)
    void enqueue(int x, int i) {
        // Overflow check
        if (freeSpot == -1) {
            cout << "Queue Overflow" << endl;
            return;
        }

        // Finding first free index
        int index = freeSpot;
        
        // Updating freeSpot to the next available index
        freeSpot = next[index];

        // Check if first element to push in queue i
        if (front[i] == -1) front[i] = index;
        else next[rear[i]] = index;   // Linking new element to previous rear

        // updating next to -1 as it is now the last element
        next[index] = -1;
        
        // forwarding rear to current index
        rear[i] = index;
        
        // pushing element into the main array
        arr[index] = x;
    }

    // Dequeue from i-th queue (i is 0-indexed)
    int dequeue(int i) {
        // Underflow check
        if (front[i] == -1) return -1;

        // Finding index to pop
        int index = front[i];
        
        // Updating front to the next element in queue i
        front[i] = next[index];

        // IMPORTANT: Reset rear if queue becomes empty
        if (front[i] == -1) rear[i] = -1;

        // Updating freeSpot list to include this index
        next[index] = freeSpot;
        freeSpot = index;
        
        // Returning popping element
        return arr[index];
    }
    
    // Check if the i-th queue is empty
    bool isEmpty(int i) { return front[i] == -1; }

    // Check if the entire array is full
    bool isFull() { return freeSpot == -1; }
};

int main() {
    // Input: Creating 3 queues in an array of size 10
    kQueues q(10, 3);

    // Enqueue operations
    q.enqueue(10, 0); // Push 10 into Queue 0
    q.enqueue(15, 0); // Push 15 into Queue 0
    q.enqueue(20, 1); // Push 20 into Queue 1
    q.enqueue(25, 0); // Push 25 into Queue 0

    // Dequeue operations and printing output
    cout << "Popped from Q0: " << q.dequeue(0) << endl; // Should be 10
    cout << "Popped from Q1: " << q.dequeue(1) << endl; // Should be 20
    cout << "Popped from Q0: " << q.dequeue(0) << endl; // Should be 15
    cout << "Popped from Q0: " << q.dequeue(0) << endl; // Should be 25
    
    // Check underflow
    cout << "Popped from Q0: " << q.dequeue(0) << endl; // Should be -1

    return 0;
}