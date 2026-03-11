// Leetcode 503: Next Greater Element II



#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> s;

        // Iterating twice to handle circular array property
        for(int i = 2 * n - 1; i >= 0; i--) {
            // Remove elements smaller than current element from stack
            while(!s.empty() && nums[s.top()] <= nums[i % n]) {
                s.pop();
            }
            
            // If stack is not empty, top element is the next greater
            if (i < n) {
                ans[i] = s.empty() ? -1 : nums[s.top()];
            }
            
            s.push(i % n);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case: A circular array
    vector<int> input = {1, 2, 3, 4, 3};
    
    cout << "Input Array: ";
    for(int x : input) cout << x << " ";
    cout << endl;

    vector<int> result = sol.nextGreaterElements(input);

    cout << "Next Greater Elements: ";
    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}