// Leetcode 1911. Maximum Alternating Subsequence Sum


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // DP table: t[i][isEven]
    // i -> current index
    // isEven -> whether current position contributes as + (even index in subsequence)
    long long t[100001][2];

    long long solve(vector<int> &nums, int i, bool isEven) {
        // Base case: reached end of array
        if (i >= nums.size()) return 0;

        // Return already computed result
        if (t[i][isEven] != -1) return t[i][isEven];

        // Option 1: Skip current element
        long long skip = solve(nums, i + 1, isEven);

        // Option 2: Take current element
        long long take;
        if (isEven) {
            // Even position -> add element
            take = nums[i] + solve(nums, i + 1, false);
        } else {
            // Odd position -> subtract element
            take = -nums[i] + solve(nums, i + 1, true);
        }

        // Store and return the best choice
        return t[i][isEven] = max(take, skip);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        // Initialize DP table with -1
        memset(t, -1, sizeof(t));

        // Start from index 0, first element treated as even position
        return solve(nums, 0, true);
    }
};

int main() {
    Solution obj;

    // Sample Input
    vector<int> nums = {4, 2, 5, 3};

    // Expected Output: 7
    // Explanation: Choose subsequence [4, 2, 5]
    // Alternating sum = 4 - 2 + 5 = 7

    long long result = obj.maxAlternatingSum(nums);

    cout << "Maximum Alternating Sum: " << result << endl;

    return 0;
}








// Approach - 2 Bottom-Up DP

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        // dp[i][0] -> next operation is subtraction
        // dp[i][1] -> next operation is addition
        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));

        // Base case:
        // dp[n][0] = dp[n][1] = 0 (already initialized)

        for (int i = n - 1; i >= 0; i--) {
            // Case: next is addition (even index in subsequence)
            long long takeAdd = nums[i] + dp[i + 1][0];
            long long skipAdd = dp[i + 1][1];
            dp[i][1] = max(takeAdd, skipAdd);

            // Case: next is subtraction (odd index)
            long long takeSub = -nums[i] + dp[i + 1][1];
            long long skipSub = dp[i + 1][0];
            dp[i][0] = max(takeSub, skipSub);
        }

        // Start from index 0, first element treated as even (addition)
        return dp[0][1];
    }
};

int main() {
    Solution obj;

    // Sample Input
    vector<int> nums = {4, 2, 5, 3};

    // Expected Output: 7
    // Explanation: 4 - 2 + 5 = 7

    cout << "Maximum Alternating Sum: " << obj.maxAlternatingSum(nums) << endl;

    return 0;
}












// Approach - 3 Space Optimized DP

long long maxAlternatingSum(vector<int>& nums) {
    long long even = 0; // next add
    long long odd = 0;  // next subtract

    for (int i = nums.size() - 1; i >= 0; i--) {
        long long newEven = max(nums[i] + odd, even);
        long long newOdd  = max(-nums[i] + even, odd);

        even = newEven;
        odd = newOdd;
    }

    return even;
}

int main() {
    Solution obj;

    // Sample Input
    vector<int> nums = {4, 2, 5, 3};

    // Expected Output: 7
    // Explanation: 4 - 2 + 5 = 7

    cout << "Maximum Alternating Sum: " << obj.maxAlternatingSum(nums) << endl;

    return 0;
}
