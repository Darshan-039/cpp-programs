// Sorting using merrge sort algorithm

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
private:
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (left != NULL && right != NULL) {
            if (left->val < right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }

        if (left) tail->next = left;
        else tail->next = right;

        return dummy->next;
    }

public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        // Step 1: Find middle
        ListNode* mid = getMid(head);

        // Step 2: Split list
        ListNode* right = mid->next;
        mid->next = NULL;
        ListNode* left = head;

        // Step 3: Sort each half
        left = sortList(left);
        right = sortList(right);

        // Step 4: Merge sorted halves
        return merge(left, right);
    }
};
