// Rotate list to the right by k places

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step-1: Finds the length of the LL and tail also
        ListNode* tail = head;
        int length = 1;

        while(tail -> next) {
            tail = tail -> next;
            length++;
        }

        // Step-2: Make the list circular 
        tail -> next = head;

        // Step-3: Finds how many time to rotate
        k = k % length;
        int stepsToNewHead = length - k;

        // Step-4: Moves newTail to rotating element
        ListNode* newTail = tail;
        while(stepsToNewHead) {
            newTail = newTail -> next;
            stepsToNewHead--;
        }

        // Step-5: Breaks the LL from newTail Node
        head = newTail -> next;
        newTail -> next = NULL;

        return head;

    }
};