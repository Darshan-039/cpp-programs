#include <bits/stdc++.h>
using namespace std;

class Deque {
    int *arr;
    int qfront;
    int rear;
    int size;

public:
    Deque(int n) {
        size = n;
        arr = new int[size];
        qfront = rear = -1;
    }

    bool pushFront(int x) {
        if (isFull()) return false;

        if (qfront == -1) {
            qfront = rear = 0;
        }
        else if (qfront == 0) {
            qfront = size - 1;
        }
        else {
            qfront--;
        }

        arr[qfront] = x;
        return true;
    }

    bool pushRear(int x) {
        if (isFull()) return false;

        if (rear == -1) {
            qfront = rear = 0;
        }
        else if (rear == size - 1) {
            rear = 0;
        }
        else {
            rear++;
        }

        arr[rear] = x;
        return true;
    }

    int popFront() {
        if (isEmpty()) return -1;

        int ans = arr[qfront];

        if (qfront == rear) {
            qfront = rear = -1;
        }
        else if (qfront == size - 1) {
            qfront = 0;
        }
        else {
            qfront++;
        }

        return ans;
    }

    int popRear() {
        if (isEmpty()) return -1;

        int ans = arr[rear];

        if (qfront == rear) {
            qfront = rear = -1;
        }
        else if (rear == 0) {
            rear = size - 1;
        }
        else {
            rear--;
        }

        return ans;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[qfront];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }

    bool isEmpty() {
        return qfront == -1;
    }

    bool isFull() {
        return ( (rear + 1) % size == qfront );
    }
};
