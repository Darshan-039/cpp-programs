// Leetcode 143:- Reorder List

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    // 1️⃣ Find middle of linked list
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // 2️⃣ Reverse linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    // 3️⃣ Merge two lists alternately
    void mergeLists(ListNode* l1, ListNode* l2) {
        while (l1 && l2) {
            ListNode* next1 = l1->next;
            ListNode* next2 = l2->next;

            l1->next = l2;
            l2->next = next1;

            l1 = next1;
            l2 = next2;
        }
    }

    // 4️⃣ Main function
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* middle = findMiddle(head);
        ListNode* second = reverseList(middle->next);
        middle->next = NULL;

        mergeLists(head, second);
    }
};

// Utility: Print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    // ✅ I MADE THE INPUT HERE
    // Creating linked list: 1 → 2 → 3 → 4 → 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    Solution obj;
    obj.reorderList(head);

    cout << "Reordered List: ";
    printList(head);

    return 0;
}
