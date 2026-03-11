// class MyCircularQueue {
//     int *arr;
//     int front, rear, size;

// public:
//     MyCircularQueue(int k) {
//         size = k;
//         arr = new int[size];
//         front = rear = -1;
//     }

//     bool enQueue(int value) {
//         // Queue is full
//         if ((front == 0 && rear == size - 1) ||
//             (rear == (front - 1 + size) % size))
//             return false;

//         // First element
//         if (front == -1) {
//             front = rear = 0;
//         }
//         // Circular move
//         else if (rear == size - 1 && front != 0) {
//             rear = 0;
//         }
//         // Normal move
//         else {
//             rear++;
//         }

//         arr[rear] = value;
//         return true;
//     }

//     bool deQueue() {
//         if (front == -1)
//             return false;

//         // Single element
//         if (front == rear) {
//             front = rear = -1;
//         }
//         // Circular move
//         else if (front == size - 1) {
//             front = 0;
//         }
//         // Normal move
//         else {
//             front++;
//         }
//         return true;
//     }

//     int Front() {
//         if (front == -1)
//             return -1;
//         return arr[front];
//     }

//     int Rear() {
//         if (front == -1)
//             return -1;
//         return arr[rear];
//     }

//     bool isEmpty() {
//         return front == -1;
//     }

//     bool isFull() {
//         return ((front == 0 && rear == size - 1) ||
//                 (rear == (front - 1 + size) % size));
//     }

//     ~MyCircularQueue() {
//         delete[] arr;
//     }
// };

















class MyCircularQueue {
private:
    vector<int> q;
    int front, rear, count, size;

public:
    MyCircularQueue(int k) {
        q.resize(k);
        size = k;
        front = 0;
        rear = -1;
        count = 0;
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % size;
        q[rear] = value;
        count++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % size;
        count--;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return q[front];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return q[rear];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == size;
    }
};