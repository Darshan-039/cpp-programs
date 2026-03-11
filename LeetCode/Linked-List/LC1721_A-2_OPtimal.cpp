// / Leetcode 1721 :- Swapping Nodes in a Linked List


class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* first = nullptr;

        // Step 1: Move fast to k-th node
        for(int i = 1; i < k; i++) {
            fast = fast->next;
        }

        // This is the k-th node from start
        first = fast;

        // Step 2: Move fast to end, slow will reach k-th from end
        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        // Step 3: slow now points to k-th from end (second node)
        // Swap values
        int temp = first->val;
        first->val = slow->val;
        slow->val = temp;

        return head;
    }
};
