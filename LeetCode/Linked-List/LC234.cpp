// Linked List is palindrome or not 

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
    ListNode* reverse(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* next = NULL;

        while (head != NULL) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }

    
    bool isPalindrome(ListNode* head) {
        
        if (head == nullptr || head->next == NULL) {
            return true;
        }

        // Find the middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Rrverse the part after middle
        slow= reverse(slow);
        
        // Campare both parts ?
        ListNode* temp=head;
        while (slow != NULL) {
            if (temp->val != slow->val) {
                return false;
            }
            slow = slow->next;
            temp = temp->next;
        }
        
        return true;
    }
};