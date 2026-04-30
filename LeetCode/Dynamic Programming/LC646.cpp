// Leetcode 646. Maximum Length of Pair Chain





// Approach - 1 Top-Down DP with Memoization

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // dp[i][prevIndex + 1]
    // i -> current index in pairs
    // prevIndex -> index of last selected pair (-1 means no previous)
    int dp[1001][1001];

    int solve(vector<vector<int>>& pairs, int i, int prevIndex) {
        // Base case: reached end of pairs
        if (i >= pairs.size()) return 0;

        // Return memoized result
        if (dp[i][prevIndex + 1] != -1)
            return dp[i][prevIndex + 1];

        int take = 0;

        // Option 1: Take current pair if valid
        // Condition: current start > previous end
        if (prevIndex == -1 || pairs[i][0] > pairs[prevIndex][1]) {
            take = 1 + solve(pairs, i + 1, i);
        }

        // Option 2: Skip current pair
        int skip = solve(pairs, i + 1, prevIndex);

        // Store and return the maximum
        return dp[i][prevIndex + 1] = max(take, skip);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        // Initialize DP table with -1
        memset(dp, -1, sizeof(dp));

        // Sort pairs based on first element
        sort(pairs.begin(), pairs.end());

        // Start recursion from index 0 with no previous pair
        return solve(pairs, 0, -1);
    }
};

int main() {
    Solution obj;

    // Sample Input
    vector<vector<int>> pairs = {
        {1, 2},
        {2, 3},
        {3, 4}
    };

    // Expected Output: 2
    // Explanation:
    // One possible chain: [1,2] -> [3,4]

    int result = obj.findLongestChain(pairs);

    cout << "Longest Chain Length: " << result << endl;

    return 0;
}








// Approach - 2 Bottom-Up DP

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        // Sort pairs based on first element (default behavior)
        sort(pairs.begin(), pairs.end());

        // t[i] -> longest chain ending at index i
        vector<int> t(n, 1);

        int maxL = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {

                // Check if pair j can come before pair i
                // Condition: end of j < start of i
                if (pairs[j][1] < pairs[i][0]) {
                    t[i] = max(t[i], t[j] + 1);
                }
            }

            // Update overall maximum chain length
            maxL = max(maxL, t[i]);
        }

        return maxL;
    }
};

int main() {
    Solution obj;

    // Sample Input
    vector<vector<int>> pairs = {
        {1, 2},
        {2, 3},
        {3, 4}
    };

    // Expected Output: 2
    // Explanation:
    // One valid chain: [1,2] -> [3,4]

    int result = obj.findLongestChain(pairs);

    cout << "Longest Chain Length: " << result << endl;

    return 0;
}