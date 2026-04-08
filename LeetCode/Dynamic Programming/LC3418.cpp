// Leetcode 3418. Maximum Amount of Coins You Can Get



// Approach 1 (R + M)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;

    // 3D DP:
    // t[i][j][neu] = maximum coins from (i,j) with 'neu' neutralizations left
    int t[501][501][3];

    int solve(vector<vector<int>>& coins, int i, int j, int neu) {

        // Base case: reached bottom-right cell
        if(i == m-1 && j == n-1) {

            // If it's negative and we can neutralize → take 0 instead
            if(coins[i][j] < 0 && neu > 0) {
                return 0;
            }

            return coins[i][j];
        }

        // Out of bounds → invalid path
        if(i >= m || j >= n) {
            return INT_MIN;
        }

        // Memoization check
        if(t[i][j][neu] != INT_MIN) {
            return t[i][j][neu];
        }

        // Option 1: Take current cell value
        int down  = solve(coins, i+1, j, neu);
        int right = solve(coins, i, j+1, neu);

        int take = coins[i][j] + max(down, right);

        // Option 2: Skip (neutralize) current cell if it's negative
        int skip = INT_MIN;

        if(coins[i][j] < 0 && neu > 0) {
            int skipDown  = solve(coins, i+1, j, neu-1);
            int skipRight = solve(coins, i, j+1, neu-1);

            skip = max(skipDown, skipRight);
        }

        // Store and return max of both choices
        return t[i][j][neu] = max(take, skip);
    }

    int maximumAmount(vector<vector<int>>& coins) {

        m = coins.size();
        n = coins[0].size();

        // Initialize DP with INT_MIN (means unvisited)
        for(int i = 0; i < 501; i++) {
            for(int j = 0; j < 501; j++) {
                for(int k = 0; k < 3; k++) {
                    t[i][j][k] = INT_MIN;
                }
            }
        }

        // Start from (0,0) with 2 neutralizations
        return solve(coins, 0, 0, 2);
    }
};

int main() {
    Solution obj;

    // Sample Input
    vector<vector<int>> coins = {
        {1, -2, 3},
        {2, -5, 10},
        {4, 2, -1}
    };

    int result = obj.maximumAmount(coins);

    cout << "Maximum Coins: " << result << endl;

    return 0;
}







// Approach 2 - Space Optimized DP (Bottom-Up):
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {

        int m = coins.size();
        int n = coins[0].size();

        // DP table: dp[i][j][k]
        // k = number of neutralizations left (0 to 2)
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));

        // Base case: bottom-right cell
        for(int k = 0; k <= 2; k++) {
            if(coins[m-1][n-1] < 0 && k > 0) {
                dp[m-1][n-1][k] = 0; // neutralize
            } else {
                dp[m-1][n-1][k] = coins[m-1][n-1];
            }
        }

        // Fill DP from bottom-right to top-left
        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {

                // Skip base cell (already filled)
                if(i == m-1 && j == n-1) continue;

                for(int k = 0; k <= 2; k++) {

                    int bestNext = INT_MIN;

                    // Move down
                    if(i+1 < m) bestNext = max(bestNext, dp[i+1][j][k]);

                    // Move right
                    if(j+1 < n) bestNext = max(bestNext, dp[i][j+1][k]);

                    // Option 1: Take current value
                    int take = (bestNext == INT_MIN) ? INT_MIN : coins[i][j] + bestNext;

                    // Option 2: Skip (neutralize)
                    int skip = INT_MIN;
                    if(coins[i][j] < 0 && k > 0) {

                        int nextBest = INT_MIN;

                        if(i+1 < m) nextBest = max(nextBest, dp[i+1][j][k-1]);
                        if(j+1 < n) nextBest = max(nextBest, dp[i][j+1][k-1]);

                        skip = nextBest;
                    }

                    dp[i][j][k] = max(take, skip);
                }
            }
        }

        return dp[0][0][2]; // start with 2 neutralizations
    }
};

int main() {
    Solution obj;

    // Sample Input
    vector<vector<int>> coins = {
        {1, -2, 3},
        {2, -5, 10},
        {4, 2, -1}
    };

    int result = obj.maximumAmount(coins);

    cout << "Maximum Coins: " << result << endl;

    return 0;
}