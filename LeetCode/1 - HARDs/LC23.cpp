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

class compare {
public:
    // 🔹 Custom comparator for min-heap
    // Returns true if 'a' should come AFTER 'b'
    // (i.e., we want smallest value at top → min heap)
    bool operator() (ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public: 
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        // 🔥 Min Heap (Priority Queue)
        // Stores pointers to ListNode
        // Ordered by node->val (smallest on top)
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

        // 🔹 Step 1: Push first node of each list into heap
        int k = lists.size();
        for(int i = 0; i < k; i++) {
            if(lists[i]) {
                minHeap.push(lists[i]);
            }
        }

        // 🔹 Step 2: Create result linked list
        ListNode* head = NULL;  // start of merged list
        ListNode* tail = NULL;  // last node of merged list

        // 🔹 Step 3: Process heap until empty
        while(!minHeap.empty()) {
            
            // Get smallest node
            ListNode* top = minHeap.top();
            minHeap.pop();

            // 🔸 If next node exists, push it into heap
            // This keeps heap updated with next candidates
            if(top->next) {
                minHeap.push(top->next);
            }

            // 🔸 Add current node to result list
            if(!head) {
                // First node case
                head = top;
                tail = top;
            }    
            else {
                // Attach to tail and move tail forward
                tail->next = top;
                tail = tail->next;
            }
        }

        // 🔹 Step 4: Return merged list
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