// Leetcode 1019:- Next Greater Node In Linked List

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function from your solution
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> arr;

        // Step 1: Convert linked list to array
        while(head) {
            arr.push_back(head -> val);
            head = head -> next;
        }

        int n = arr.size();
        vector<int> ans(n, 0);
        stack<int> st;

        // Step 2: Monotonic Stack
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[i] > arr[st.top()]) {
                ans[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter linked list values: ";
    ListNode* head = NULL;
    ListNode* tail = NULL;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if(!head) {
            head = new ListNode(x);
            tail = head;
        } else {
            tail->next = new ListNode(x);
            tail = tail->next;
        }
    }

    Solution sol;
    vector<int> result = sol.nextLargerNodes(head);

    cout << "Next greater nodes: ";
    for(int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
