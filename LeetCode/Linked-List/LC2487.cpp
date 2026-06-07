// Leetcode 2487. Remove Nodes From Linked List







// Approach - 1 (Using Stack)

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        ListNode* temp = head;

        // Push all nodes into stack
        while (temp) {
            st.push(temp);
            temp = temp->next;
        }

        // Last node is always included
        ListNode* curr = st.top();
        st.pop();

        int maxVal = curr->val;

        // Create answer list with last node
        ListNode* ansHead = new ListNode(curr->val);

        // Process nodes from right to left
        while (!st.empty()) {
            curr = st.top();
            st.pop();

            // Skip node if a greater value exists on its right
            if (curr->val < maxVal)
                continue;

            // Add node to answer list
            ListNode* newNode = new ListNode(curr->val);
            newNode->next = ansHead;
            ansHead = newNode;

            maxVal = curr->val;
        }

        return ansHead;
    }
};

// Function to create linked list from input
ListNode* createList(int n) {
    if (n == 0) return nullptr;

    int x;
    cin >> x;

    ListNode* head = new ListNode(x);
    ListNode* tail = head;

    for (int i = 1; i < n; i++) {
        cin >> x;
        tail->next = new ListNode(x);
        tail = tail->next;
    }

    return head;
}

// Function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values: ";
    ListNode* head = createList(n);

    Solution obj;
    ListNode* result = obj.removeNodes(head);

    cout << "Result: ";
    printList(result);

    return 0;
}









// Approach - 2 (Using Recursion)

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {

        // Base case:
        if (!head || !head->next)
            return head;

        // Recursively process the remaining list.
        ListNode* nextNode = removeNodes(head->next);

        // If the current node's value is smaller than the first node
        // of the processed right side, then a greater value exists
        // somewhere to its right, so remove the current node.
        if (head->val < nextNode->val) return nextNode;

        // Otherwise, keep the current node and connect it
        // to the processed remainder of the list.
        head->next = nextNode;

        return head;
    }
};







// Approach - 3 (Using Recursion and Reversing the List)

class Solution {
private:
    // Recursively reverse the linked list
    ListNode* reverseList(ListNode* head) {

        // Base case: empty list or single node
        if (head == NULL || head->next == NULL) return head;

        // Reverse the remaining list
        ListNode* last = reverseList(head->next);

        // Reverse the current link
        head->next->next = head;
        head->next = NULL;

        return last;
    }

public:
    ListNode* removeNodes(ListNode* head) {

        // Reverse the list so we can process nodes
        // from right to left in the original list
        head = reverseList(head);

        int maximum = 0;

        ListNode* prev = NULL;
        ListNode* current = head;

        while (current != NULL) {

            // Update the maximum value seen so far
            maximum = max(maximum, current->val);

            // If current value is smaller than the maximum,
            // a greater value existed on its right in the
            // original list, so remove this node
            if (current->val < maximum) {

                if (prev == NULL) {
                    // Removing the head node
                    head = current->next;
                    current = head;
                }
                else {
                    // Skip the current node
                    prev->next = current->next;
                    current = current->next;
                }
            }
            else {
                // Keep the current node
                prev = current;
                current = current->next;
            }
        }

        // Reverse again to restore original order
        return reverseList(head);
    }
};