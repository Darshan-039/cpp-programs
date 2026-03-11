// Leetcode -23 Merge k Sorted Lists




#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for singly-linked list provided in your snippet
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Your custom comparator
class compare {
public:
    bool operator() (ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public: 
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

        int k = lists.size();
        for(int i = 0; i < k; i++) {
            if(lists[i]) minHeap.push(lists[i]);
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(!minHeap.empty()) {
            ListNode* top = minHeap.top();
            minHeap.pop();

            if(top->next) minHeap.push(top->next);

            if(!head) {
                head = top;
                tail = top;
            }    
            else {
                tail->next = top;
                tail = tail->next;
            }
        }
        
        // Ensure the last node doesn't point to old data
        if(tail) tail->next = NULL; 

        return head;
    }
};

// --- Helper Functions for the Input ---

// Function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    cout << endl;
}

// Function to create a linked list from a vector
ListNode* createList(vector<int> arr) {
    if (arr.empty()) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    // 1. Create Input Data
    // List 1: 1 -> 4 -> 5
    // List 2: 1 -> 3 -> 4
    // List 3: 2 -> 6
    vector<ListNode*> lists;
    lists.push_back(createList({1, 4, 5}));
    lists.push_back(createList({1, 3, 4}));
    lists.push_back(createList({2, 6}));

    // 2. Call the Solution
    Solution sol;
    ListNode* result = sol.mergeKLists(lists);

    // 3. Print result
    cout << "Merged List: " << endl;
    printList(result);

    return 0;
}