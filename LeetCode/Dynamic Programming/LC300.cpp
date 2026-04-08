// Leetcode 300. Longest Increasing Subsequence



// Approach 1 - Recursion + Memoization (Top-Down DP)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;

    // dp[i][prev+1] → stores result for index i and previous index
    int dp[2501][2501];

    // 🔹 Recursive function with memoization
    int solve(vector<int>& nums, int i, int prev) {

        // Base case: reached end of array
        if (i == n) return 0;

        // If already computed, return stored value
        if (dp[i][prev + 1] != -1) return dp[i][prev + 1];

        int take = 0;

        // 🔹 Take current element if:
        // 1. prev == -1 (no previous element)
        // 2. nums[i] > nums[prev] (increasing condition)
        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + solve(nums, i + 1, i);
        }

        // 🔹 Skip current element
        int not_take = solve(nums, i + 1, prev);

        // Store result in dp
        return dp[i][prev + 1] = max(take, not_take);
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();

        // Initialize dp with -1
        memset(dp, -1, sizeof(dp));

        // Start recursion from index 0, prev = -1
        return solve(nums, 0, -1);
    }
};

int main() {
    Solution obj;

    // 🔹 Sample Input
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    // 🔹 Function Call
    int result = obj.lengthOfLIS(nums);

    // 🔹 Output
    cout << "Length of LIS: " << result << endl;

    return 0;
}





// Approach 2 - Tabulation (Bottom-Up DP)

#include <bits/stdc++.h>
using namespace std;

    class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            int n = nums.size();

            // 🔹 t[i] = length of LIS ending at index i
            vector<int> t(n, 1);  // each element itself is LIS of length 1

            int LIS = 1; // store overall maximum LIS

            // 🔹 Iterate over each element
            for (int i = 0; i < n; i++) {

                // Check all previous elements
                for (int j = 0; j < i; j++) {

                    // If increasing sequence possible
                    if (nums[i] > nums[j]) {
                        t[i] = max(t[i], t[j] + 1);
                    }
                }

                // Update global LIS after inner loop
                LIS = max(LIS, t[i]);
            }

            return LIS;
        }
    };

int main() {
    Solution obj;

    // 🔹 Sample Input
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    // 🔹 Function Call
    int result = obj.lengthOfLIS(nums);

    // 🔹 Output
    cout << "Length of LIS: " << result << endl;

    return 0;
}