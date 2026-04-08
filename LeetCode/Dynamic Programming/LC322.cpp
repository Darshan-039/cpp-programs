// Leetcode 322. Coin Change




// Approach - 1 Recursive + Memoization

#include <bits/stdc++.h>
using namespace std;

// Recursive function with memoization
int solve(vector<int> &nums, int x, int n, vector<int> &dp) {

    if(x == 0) return 0;
    if(x < 0) return INT_MAX;
    if(dp[x] != -1) return dp[x];

    int minAns = INT_MAX;

    // Try every coin
    for(int i = 0; i < n; i++) {

        // Recursively solve for remaining amount
        int ans = solve(nums, x - nums[i], n, dp);

        // If valid result found, update minimum
        if(ans != INT_MAX) minAns = min(minAns, ans + 1);
    }

    // Store result in DP array
    return dp[x] = minAns;
}


// Function to find minimum number of coins
int minimumElements(vector<int> &nums, int x) {

    int n = nums.size();

    // DP array to store results for amounts 0..x
    vector<int> dp(x + 1, -1);

    int ans = solve(nums, x, n, dp);

    // If not possible to make amount, return -1
    return ans == INT_MAX ? -1 : ans;
}



int main() {

    int n;
    cout << "Enter number of coins: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter coin values:\n";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int x;
    cout << "Enter target amount: ";
    cin >> x;

    int result = minimumElements(nums, x);

    cout << "Minimum coins required: " << result << endl;

    return 0;
}




















// Approach - 2 Iterative + Tabulation
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        // dp[i] = minimum coins required to make amount i
        vector<int> dp(amount + 1, INT_MAX);

        // Base case: 0 amount needs 0 coins
        dp[0] = 0;

        // Calculate for all amounts from 1 to amount
        for(int i = 1; i <= amount; i++) {

            // Try every coin
            for(int j = 0; j < n; j++) {

                // Check if coin can be used
                if(i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {

                    // Update minimum coins needed
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }

        // If still INT_MAX, amount cannot be formed
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};


int main() {

    int n;
    cout << "Enter number of coins: ";
    cin >> n;

    vector<int> coins(n);

    cout << "Enter coin values:\n";
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int amount;
    cout << "Enter target amount: ";
    cin >> amount;

    Solution obj;

    int result = obj.coinChange(coins, amount);

    cout << "Minimum coins required: " << result << endl;

    return 0;
}