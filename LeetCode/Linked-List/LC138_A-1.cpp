// 138. Copy List with Random Pointer

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private: 
    void insertAtTail(Node* &head, Node* &tail, int data) {
        Node* newNode = new Node(data);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        else {
            tail -> next = newNode;
            tail = newNode;
        }
    }

public:
    Node* copyRandomList(Node* head) {
        // Step-1: Create a clone list
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        Node* temp = head;

        while(temp != NULL) {
            insertAtTail(cloneHead,cloneTail,temp -> val);
            temp = temp -> next;
        }

        // Step-2: Create a Map
        unordered_map<Node* , Node*> oldToNewNode;

        Node* originalNode = head;
        Node* cloneNode = cloneHead;

        while(originalNode != NULL) {
            oldToNewNode[originalNode] = cloneNode;
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }

        // Step-3: Seting random pointers
        originalNode = head;
        cloneNode = cloneHead;

        while(originalNode != NULL) {
            cloneNode -> random = oldToNewNode[originalNode -> random];
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }

        return cloneHead;

    }
};