#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

// Insert at HEAD
void insertAtHead(Node* &head, int d) {
    Node* newNode = new Node(d);
    newNode->next = head;
    head = newNode;
}

// Insert at TAIL
void insertAtTail(Node* &tail, int d) {
    Node* newNode = new Node(d);
    tail->next = newNode;
    tail = newNode;
}

// Insert at ANY POSITION (1-based indexing)
void insertAtPosition(Node* &head, Node* &tail, int position, int d) {

    // Insert at HEAD
    if (position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int count = 1;

    // Move to (position - 1)
    while (count < position - 1 && temp != NULL) {
        temp = temp->next;
        count++;
    }

    // Insert at TAIL if position is last + 1
    if (temp->next == NULL) {
        insertAtTail(tail, d);
        return;
    }

    // Insert in middle
    Node* newNode = new Node(d);
    newNode->next = temp->next;
    temp->next = newNode;
}

// PRINT linked list
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {

    // Initial head & tail
    Node* head = new Node(10);
    Node* tail = head;

    insertAtHead(head, 5);        // 5 → 10
    insertAtTail(tail, 20);       // 5 → 10 → 20
    insertAtPosition(head, tail, 2, 99); // 5 → 99 → 10 → 20
    insertAtPosition(head, tail, 1, 1);  // insert at head
    insertAtPosition(head, tail, 6, 50); // insert at tail

    print(head);

    return 0;
}
