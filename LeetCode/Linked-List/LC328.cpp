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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* l1Head = new ListNode(-1);    
        ListNode* l1Tail = l1Head;

        ListNode* l2Head = new ListNode(-1);    
        ListNode* l2Tail = l2Head;

        ListNode* temp = head;

        int i = 1;
        while(temp) {
            if(i%2 == 1) {
                l1Tail -> next = temp;
                l1Tail = l1Tail -> next;
            }
            else {
                l2Tail -> next = temp;
                l2Tail = l2Tail -> next;
            }

            temp = temp -> next;
            i++;
        }

        l1Tail -> next = l2Head -> next;
        l2Tail -> next = NULL;

        return l1Head -> next;
    }
};