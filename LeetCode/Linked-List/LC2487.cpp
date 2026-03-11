// Remove Nodes from Linked List

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
    ListNode* removeNodes(ListNode* head) {
        // Step 1: Reverse the list
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // prev is now the head of reversed list
        head = prev;

        // Step 2: Remove nodes smaller than max on left
        ListNode* newHead = head;
        curr = head->next;
        int maxVal = head->val;

        while (curr) {
            if (curr->val >= maxVal) {
                maxVal = curr->val;
                head->next = curr;
                head = curr;
            }
            curr = curr->next;
        }

        head->next = NULL; // end the list

        // Step 3: Reverse back to restore original order
        prev = NULL;
        curr = newHead;

        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }
};
