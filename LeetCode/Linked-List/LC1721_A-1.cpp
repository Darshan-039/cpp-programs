// Leetcode 1721 :- Swapping Nodes in a Linked List

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
    ListNode* swapNodes(ListNode* head, int k) {
        if (!head || !head->next) return head;

        // Step 1: Find length
        int length = 0;
        ListNode* temp = head;
        while (temp) {
            temp = temp->next;
            length++;
        }

        // Step 2: Find k-th from start
        ListNode* ele1 = head;
        for (int i = 1; i < k; i++) {
            ele1 = ele1->next;
        }

        // Step 3: Find k-th from end = (length - k + 1)-th from start
        int posFromHead = length - k + 1;

        ListNode* ele2 = head;
        for (int i = 1; i < posFromHead; i++) {
            ele2 = ele2->next;
        }

        // Step 4: Swap values
        int tempVal = ele1->val;
        ele1->val = ele2->val;
        ele2->val = tempVal;

        return head;
    }
};
