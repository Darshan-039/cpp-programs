// Leetcode :- 239. Sliding Window Maximum



#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        int n = nums.size();
        if (n == 0) return ans; // Edge case: empty input

        // 1. Pushing max value idx for first window
        for(int i = 0; i < k; i++) {
            // Maintain decreasing order in deque
            while(!dq.empty() && nums[i] >= nums[dq.back()]) 
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        // Storing ans for the first window
        ans.push_back(nums[dq.front()]);

        // 2. Further windows are accessed
        for(int i = k; i < n; i++) {
            
            // Removal process (front): Remove idx if it's out of window
            if(!dq.empty() && i - dq.front() >= k) {
                dq.pop_front();
            }

            // Removal Process (back): Maintain decreasing order
            while(!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }

            // Adding process
            dq.push_back(i);

            // Storing ans: front of dq is always the maximum for current window
            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // --- INPUT SECTION ---
    // Standard LeetCode example
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    cout << "Input Array: ";
    for(int x : nums) cout << x << " ";
    cout << "\nWindow Size: " << k << endl;

    // --- EXECUTION ---
    vector<int> result = sol.maxSlidingWindow(nums, k);

    // --- OUTPUT SECTION ---
    cout << "Sliding Window Maximums: ";
    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}