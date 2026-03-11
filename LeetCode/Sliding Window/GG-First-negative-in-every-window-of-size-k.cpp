#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        deque<int> dq; // Stores indices of negative numbers
        int n = arr.size();
        vector<int> ans;
        
        // 1. Process the first window of size k
        for(int i = 0; i < k; i++) {
            if(arr[i] < 0) dq.push_back(i);
        }
        
        // Store answer for the first window
        if(dq.empty()) ans.push_back(0);
        else ans.push_back(arr[dq.front()]);
        
        // 2. Process remaining windows
        for(int i = k; i < n; i++) {
            
            // Removal: Remove index if it's out of the current window range
            if(!dq.empty() && i - dq.front() >= k) {
                dq.pop_front();
            }
            
            // Addition: Add current index if the element is negative
            if(arr[i] < 0) dq.push_back(i);
            
            // Storing answer: Front of deque is the first negative index for this window
            if(dq.empty()) {
                ans.push_back(0);
            } else {
                ans.push_back(arr[dq.front()]);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Example Input
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;
    
    vector<int> result = sol.firstNegInt(arr, k);
    
    // Print Output
    cout << "First negative integer in each window of size " << k << ":" << endl;
    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}