// Leetcode 2130 :- Maximum Twin Sum of a Linked List

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
    int pairSum(ListNode* head) {
        // Step 1: Find middle of list
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* prev = NULL;

        while(slow) {
            ListNode* nextNode = slow -> next;
            slow -> next = prev;
            prev = slow;
            slow = nextNode;
        }

        // Step:3 Now prev points to start of reversed second half
        ListNode* second = prev;
        ListNode* first = head;

        // Step 4: Calculate max twin sum
        int maxSum = 0;
        while(second) {
            maxSum = max(maxSum,first -> val + second -> val);
            first = first -> next;
            second = second -> next;
        }

        return maxSum;
        
    }
};