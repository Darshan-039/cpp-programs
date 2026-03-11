// Two-Approachs
// Approach 1: Using Dummy Node (Better Readability)
// Approach 2: Using Previous Pointer
// Time Complexity: O(N + M) where N is the size of nums and M is the number of nodes in the linked list
// Space Complexity: O(1) (ignoring the space used by the bitset)







// class Solution {
// public:
//     ListNode* modifiedList(vector<int>& nums, ListNode* head) {
//         bitset<100001>ss;
//         for(int i: nums){
//             ss.set(i);
//         }
        
//         ListNode* dummy = new ListNode(-1);
//         dummy -> next = head;
//         head = dummy;

//         while(head -> next) {
//             if(ss.test(head -> next -> val)) {
//                 head -> next = head -> next -> next;
//             }
//             else {
//                 head = head -> next;
//             }
//         }



//         return dummy -> next;
//     }
// };
















// #include <iostream>
// #include <vector>
// #include <bitset>
// using namespace std;

// class Solution {
// public:
//     ListNode* modifiedList(vector<int>& nums, ListNode* head) {
//         bitset<100001> ss;
//         for(int i : nums){
//             ss.set(i);
//         }

//         ListNode* temp = head;
//         ListNode* prev = head;

//         while(temp){
//             if(ss.test(temp->val)){
//                 if(temp == head){
//                     head = temp->next;
//                     prev = head;
//                 } 
//                 else {
//                     prev->next = temp->next;
//                 }
//                 temp = temp->next;
//             } 
//             else {
//                 prev = temp;
//                 temp = temp->next;
//             }
//         }
//         return head;
//     }
// };

// int main() {
//     // ⭐ INPUT INSIDE CODE
//     vector<int> nums = {2, 4, 5};  

//     // Creating linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6
//     ListNode* head = new ListNode(1);
//     head->next = new ListNode(2);
//     head->next->next = new ListNode(3);
//     head->next->next->next = new ListNode(4);
//     head->next->next->next->next = new ListNode(5);
//     head->next->next->next->next->next = new ListNode(6);

//     cout << "Original List: ";
//     ListNode* p = head;
//     while(p){
//         cout << p->val << " ";
//         p = p->next;
//     }
//     cout << endl;

//     Solution obj;
//     head = obj.modifiedList(nums, head);

//     cout << "Modified List: ";
//     p = head;
//     while(p){
//         cout << p->val << " ";
//         p = p->next;
//     }
//     cout << endl;

//     return 0;
// }
