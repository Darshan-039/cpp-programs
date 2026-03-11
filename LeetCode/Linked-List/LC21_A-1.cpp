// Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* head;

        // Ensure list1 starts with the smaller value
        if (list1->val <= list2->val) {
            head = list1;
        } else {
            head = list2;
            list2 = list2->next;
            head->next = list1;
        }

        ListNode* prev = head;
        ListNode* curr = prev->next;

        while (list2 != NULL) {
            if (curr == NULL || list2->val <= curr->val) {
                // Insert list2 node between prev and curr
                ListNode* next2 = list2->next;
                prev->next = list2;
                list2->next = curr;
                list2 = next2;
                prev = prev->next;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};
