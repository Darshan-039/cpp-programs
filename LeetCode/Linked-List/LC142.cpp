// Title: Linked List Cycle II

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect cycle using Floyd's Algorithm
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {   // Meeting point
                break;
            }
        }

        // If no cycle
        if (fast == NULL || fast->next == NULL) {
            return NULL;
        }

        // Step 2: Move slow to head, keep fast at meeting point
        slow = head;

        // Move both 1 step at a time
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // Both meet at the start of cycle
        return slow;
    }
};
