// Leetcode 160. Intersection of Two Linked Lists


#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        // Two pointers starting from both heads
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        // Traverse both lists
        while(true) {

            // If both pointers meet → intersection found
            if(temp1 == temp2) return temp1;

            // Move to next node
            temp1 = temp1->next;
            temp2 = temp2->next;

            // If both reach NULL → no intersection
            if(!temp1 && !temp2) return NULL;

            // If one pointer reaches end, redirect it to other list
            if(!temp1) temp1 = headB;
            if(!temp2) temp2 = headA;
        }

        return NULL;
    }
};

int main() {
    Solution obj;

    // Creating common intersection part: 8 -> 10
    ListNode* common = new ListNode(8);
    common->next = new ListNode(10);

    // List A: 3 -> 7 -> 8 -> 10
    ListNode* headA = new ListNode(3);
    headA->next = new ListNode(7);
    headA->next->next = common;

    // List B: 99 -> 1 -> 8 -> 10
    ListNode* headB = new ListNode(99);
    headB->next = new ListNode(1);
    headB->next->next = common;

    // Function call
    ListNode* result = obj.getIntersectionNode(headA, headB);

    // Output result
    if(result)
        cout << "Intersection at node with value: " << result->val << endl;
    else
        cout << "No intersection found" << endl;

    return 0;
}