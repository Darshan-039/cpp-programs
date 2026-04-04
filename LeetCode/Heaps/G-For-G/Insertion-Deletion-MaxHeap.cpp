#include <iostream>
using namespace std;

class heap {
    public:
    int arr[100];
    int size;

    heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while(index > 1) {
            int parent = index / 2;

            if(arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else return;
        }
    }


    void deleteFromHeap() {
        if(size == 0) {
            cout << "Nothing to delete";
            return;
        }

        // Take last element to first
        arr[1] = arr[size];
        size--;

        int i = 1;
        while(i < size) {
            int leftChild = 2 * i;
            int rightChild = 2 * i + 1;

            if(leftChild < size && arr[leftChild] > arr[i]) {
                swap(arr[leftChild], arr[i]);
                i = leftChild;
            }
            else if(rightChild < size && arr[rightChild] > arr[i]) {
                swap(arr[rightChild], arr[i]);
                i = rightChild;
            }
            else return;
        }
    }

    void print() {
        for(int i = 1; i<=size; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    heap h;
    h.insert(10);
    h.insert(5);
    h.insert(6);
    h.insert(3);

    h.deleteFromHeap();
    h.print();

}