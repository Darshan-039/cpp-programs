// Leetcode 2181 :- Merge Nodes in Between Zeros

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
    ListNode* mergeNodes(ListNode* head) {
        head = head->next;            // skip first zero
        ListNode* resHead = head;     // final head (first sum node)
        ListNode* curr = head;

        while (head) {
            int sum = 0;

            // accumulate values until hitting zero
            while (head && head->val != 0) {
                sum += head->val;
                head = head->next;
            }

            curr->val = sum;

            // if last zero → stop
            if (!head->next) {
                curr->next = NULL;
                break;
            }

            // move curr forward
            curr->next = head->next;
            curr = curr->next;

            // move head forward
            head = head->next;
        }

        return resHead;
    }
};