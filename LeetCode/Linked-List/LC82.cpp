// Remove duplicates from sorted list II

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != NULL) {

            bool isDuplicate = false;

            // Move curr forward while duplicates exist
            while (curr->next != NULL && curr->val == curr->next->val) {
                curr = curr->next;
                isDuplicate = true;
            }

            if (isDuplicate) {
                // Skip the entire duplicate group
                curr = curr->next;
                prev->next = curr;
            } else {
                // No duplicates → move prev
                prev = prev->next;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};
