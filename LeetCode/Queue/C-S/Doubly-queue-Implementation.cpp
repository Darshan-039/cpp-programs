#include <bits/stdc++.h>
using namespace std;

class Deque
{
    int *arr;
    int qfront;
    int rear;
    int size;

public:
    // Constructor
    Deque(int n)
    {
        size = n;
        arr = new int[size];
        qfront = rear = -1;
    }

    // Insert element at front
    bool pushFront(int x)
    {
        // Deque is full
        if (isFull())
            return false;

        // First element
        if (qfront == -1)
            qfront = rear = 0;

        // Circular case
        else if (qfront == 0)
            qfront = size - 1;

        // Normal case
        else
            qfront--;

        arr[qfront] = x;
        return true;
    }

    // Insert element at rear
    bool pushRear(int x)
    {
        if (isFull())
            return false;

        // First element
        if (rear == -1)
            qfront = rear = 0;

        // Circular case
        else if (rear == size - 1)
            rear = 0;

        // Normal case
        else
            rear++;

        arr[rear] = x;
        return true;
    }

    // Delete from front
    int popFront()
    {
        if (isEmpty())
            return -1;

        int ans = arr[qfront];

        // Only one element
        if (qfront == rear)
            qfront = rear = -1;

        // Circular case
        else if (qfront == size - 1)
            qfront = 0;

        // Normal case
        else
            qfront++;

        return ans;
    }

    // Delete from rear
    int popRear()
    {
        if (isEmpty())
            return -1;

        int ans = arr[rear];

        // Only one element
        if (qfront == rear)
            qfront = rear = -1;

        // Circular case
        else if (rear == 0)
            rear = size - 1;

        // Normal case
        else
            rear--;

        return ans;
    }

    // Return front element
    int getFront()
    {
        if (isEmpty())
            return -1;

        return arr[qfront];
    }

    // Return rear element
    int getRear()
    {
        if (isEmpty())
            return -1;

        return arr[rear];
    }

    // Check if deque is empty
    bool isEmpty()
    {
        return qfront == -1;
    }

    // Check if deque is full
    bool isFull()
    {
        return (rear + 1) % size == qfront;
    }
};

int main()
{
    int n;
    cout << "Enter size of Deque: ";
    cin >> n;

    Deque dq(n);

    int choice, x;

    do
    {
        cout << "\n===== DEQUE MENU =====\n";
        cout << "1. Push Front\n";
        cout << "2. Push Rear\n";
        cout << "3. Pop Front\n";
        cout << "4. Pop Rear\n";
        cout << "5. Get Front\n";
        cout << "6. Get Rear\n";
        cout << "7. Check Empty\n";
        cout << "8. Check Full\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> x;
            if (dq.pushFront(x))
                cout << "Inserted at Front\n";
            else
                cout << "Deque is Full\n";
            break;

        case 2:
            cout << "Enter value: ";
            cin >> x;
            if (dq.pushRear(x))
                cout << "Inserted at Rear\n";
            else
                cout << "Deque is Full\n";
            break;

        case 3:
            x = dq.popFront();
            if (x == -1)
                cout << "Deque is Empty\n";
            else
                cout << "Deleted from Front: " << x << endl;
            break;

        case 4:
            x = dq.popRear();
            if (x == -1)
                cout << "Deque is Empty\n";
            else
                cout << "Deleted from Rear: " << x << endl;
            break;

        case 5:
            x = dq.getFront();
            if (x == -1)
                cout << "Deque is Empty\n";
            else
                cout << "Front Element: " << x << endl;
            break;

        case 6:
            x = dq.getRear();
            if (x == -1)
                cout << "Deque is Empty\n";
            else
                cout << "Rear Element: " << x << endl;
            break;

        case 7:
            if (dq.isEmpty())
                cout << "Deque is Empty\n";
            else
                cout << "Deque is Not Empty\n";
            break;

        case 8:
            if (dq.isFull())
                cout << "Deque is Full\n";
            else
                cout << "Deque is Not Full\n";
            break;

        case 9:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid Choice\n";
        }

    } while (choice != 9);

    return 0;
}