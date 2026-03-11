// Leetcode 1444. Number of Ways of Cutting a Pizza




#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    int m, n;
    
    // apples[i][j] stores the total number of apples in the subgrid 
    // from top-left corner (i, j) to the bottom-right corner (m-1, n-1)
    int apples[55][55];
    
    // DP table for memoization. dp[i][j][k] stores the number of ways to cut 
    // the subgrid starting at (i, j) into k pieces.
    int dp[55][55][15];

    long long MOD = 1e9 + 7;

    int solve(int i, int j, int k) {
        // Base case 1: If the current piece has fewer apples than the pieces we need 
        // to cut, it's impossible to give every piece at least one apple.
        if (apples[i][j] < k) return 0;

        // Base case 2: If we only need 1 piece (no more cuts), check if it has 
        // at least one apple. If yes, it's 1 valid way; otherwise 0.
        if (k == 1) return apples[i][j] >= 1;

        // Return memoized result if we have already computed this state
        if (dp[i][j][k] != -1) return dp[i][j][k];

        int ans = 0;

        // --- Horizontal Cuts ---
        // Try cutting horizontally at every possible row 'h' below the current row 'i'
        for (int h = i + 1; h < m; h++) {
            int lower_slice_apples = apples[h][j]; 
            int upper_slice_apples = apples[i][j] - lower_slice_apples;

            // The upper slice is given away. It must have at least 1 apple.
            // The lower slice is kept for future cuts. It must have enough apples 
            // for the remaining k-1 pieces.
            if (upper_slice_apples >= 1 && lower_slice_apples >= k - 1) {
                ans = (ans % MOD + solve(h, j, k - 1) % MOD) % MOD;
            }
        }

        // --- Vertical Cuts ---
        // Try cutting vertically at every possible column 'v' to the right of 'j'
        for (int v = j + 1; v < n; v++) {
            int right_slice_apples = apples[i][v];
            int left_slice_apples = apples[i][j] - right_slice_apples;

            // The left slice is given away. It must have at least 1 apple.
            // The right slice is kept for future cuts. It must have enough apples 
            // for the remaining k-1 pieces.
            if (left_slice_apples >= 1 && right_slice_apples >= k - 1) {
                ans = (ans % MOD + solve(i, v, k - 1) % MOD) % MOD;
            }
        }

        // Memoize and return the result
        return dp[i][j][k] = ans;
    }

    int ways(vector<string>& pizza, int k) {
        m = pizza.size();
        n = pizza[0].length();

        memset(apples, 0, sizeof(apples));

        // Build the 2D suffix sum array for apples
        // We traverse from the bottom-right of the pizza up to the top-left
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // Apples to the right of the current cell
                apples[i][j] = apples[i][j + 1];

                // Add apples in the current column 'j' from row 'i' down to the bottom
                for (int l = i; l < m; l++) {
                    if (pizza[l][j] == 'A') {
                        apples[i][j] += 1;
                    }
                }
            }
        }

        // Initialize DP table with -1 (uncomputed)
        memset(dp, -1, sizeof(dp));

        // Start the recursive process from the top-left corner (0, 0) needing k pieces
        return solve(0, 0, k);
    }
};

int main() {
    Solution sol;

    // --- Test Case 1 ---
    vector<string> pizza1 = {"A..", "AAA", "..."};
    int k1 = 3;
    cout << "Test Case 1:\n";
    cout << "Expected Output: 3\n";
    cout << "Actual Output: " << sol.ways(pizza1, k1) << "\n\n";

    // --- Test Case 2 ---
    vector<string> pizza2 = {"A..", "AA.", "..."};
    int k2 = 3;
    cout << "Test Case 2:\n";
    cout << "Expected Output: 1\n";
    cout << "Actual Output: " << sol.ways(pizza2, k2) << "\n\n";

    // --- Test Case 3 ---
    vector<string> pizza3 = {"A..", "A..", "..."};
    int k3 = 1;
    cout << "Test Case 3:\n";
    cout << "Expected Output: 1\n";
    cout << "Actual Output: " << sol.ways(pizza3, k3) << "\n";

    return 0;
}