class CircularQueue
{
private:
    int* arr;
    int front;
    int rear;
    int size;

public:
    // Initialize your data structure
    CircularQueue(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Enqueue an element into the circular queue
    bool enqueue(int value)
    {
        // Check if queue is full
        if ((front == 0 && rear == size - 1) ||
            (rear == (front - 1) % (size - 1)))
            return false;

        // First element insertion
        if (front == -1) front = rear = 0;

        // Maintain circular nature
        else if (rear == size - 1 && front != 0) rear = 0;

        // Normal insertion
        else rear++;

        arr[rear] = value;

        return true;
    }

    // Dequeue an element from the circular queue
    int dequeue()
    {
        // Queue is empty
        if (front == -1) return -1;

        int ans = arr[front];
        arr[front] = -1;

        // Single element present
        if (front == rear) front = rear = -1;

        // Maintain circular nature
        else if (front == size - 1) front = 0;

        // Normal deletion
        else front++;

        return ans;
    }
};