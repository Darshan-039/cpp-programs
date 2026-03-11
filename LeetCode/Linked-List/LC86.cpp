// Leetcode 86 :- Partiton List 

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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;

        ListNode* list1 = new ListNode(-1);  // < x
        ListNode* head1 = list1;

        ListNode* list2 = new ListNode(-1);  // >= x
        ListNode* head2 = list2;

        while (head) {

            if (head -> val < x) {
                list1 -> next = head;
                list1 = list1 -> next;
            } else {
                list2 -> next = head;
                list2 = list2 -> next;
            }
            head = head -> next;

        }

        // IMPORTANT: End the second list
        list2->next = NULL;

        // Connect list1 with list2
        list1->next = head2->next;

        // Return the head of list1
        return head1->next;
    }
};
