// Leetcode 209. Minimum Size Subarray Sum


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int i = 0;              // Left pointer of window
        int sum = 0;            // Current window sum
        int ans = INT_MAX;      // Store minimum length

        // Expand window using right pointer j
        for(int j = 0; j < n; j++) {
            sum += nums[j];     // Add current element to window

            // Shrink window while sum >= target
            while(sum >= target) {
                // Update minimum length
                ans = min(ans, j - i + 1);

                // Remove left element and move left pointer
                sum -= nums[i];
                i++;
            }
        }

        // If no valid subarray found, return 0
        return ans == INT_MAX ? 0 : ans;
    }
};

int main() {
    Solution obj;

    // 🔹 Sample Input
    int target = 7;
    vector<int> nums = {2, 3, 1, 2, 4, 3};

    // 🔹 Function Call
    int result = obj.minSubArrayLen(target, nums);

    // 🔹 Output
    cout << "Minimum Subarray Length: " << result << endl;

    return 0;
}