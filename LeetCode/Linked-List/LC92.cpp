// Leetcoed :- 92 Reverse Linked List II


#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;

        // Step 1: move prev to node before `left`
        for (int i = 1; i < left; i++)
            prev = prev->next;

        // Step 2: reverse sublist
        ListNode* curr = prev->next;
        ListNode* then = curr->next;

        for (int i = 0; i < right - left; i++) {
            curr->next = then->next;
            then->next = prev->next;
            prev->next = then;
            then = curr->next;
        }

        return dummy.next;
    }
};

void printList(ListNode* head) {
    while(head) {
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

    cout << "Enter list values: ";
    ListNode* head = NULL;
    ListNode* tail = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (!head) {
            head = new ListNode(x);
            tail = head;
        } else {
            tail->next = new ListNode(x);
            tail = tail->next;
        }
    }

    int left, right;
    cout << "Enter left and right positions: ";
    cin >> left >> right;

    Solution sol;
    ListNode* result = sol.reverseBetween(head, left, right);

    cout << "Reversed list: ";
    printList(result);

    return 0;
}















ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (!head || left == right) return head;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    
    ListNode* before = dummy;
    for (int i = 0; i < left - 1; i++) before = before->next;

    // 'start' is the beginning of the segment to reverse
    ListNode* start = before->next;
    ListNode* curr = start;
    ListNode* prev = nullptr;

    // Reverse exactly (right - left + 1) nodes
    for (int i = 0; i < (right - left + 1); i++) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    // Now 'prev' is the new head of the reversed segment (the old 'end')
    // 'curr' is the node at position 'right + 1' (the 'after' node)

    // Re-connect the pieces
    before->next = prev;  // Connect left part to reversed middle
    start->next = curr;   // Connect reversed middle to right part

    return dummy->next;
}