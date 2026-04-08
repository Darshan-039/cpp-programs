// Leetcode 714. Best Time to Buy and Sell Stock with Transaction Fee


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int trFee;               // transaction fee
    int t[50001][2];         // DP table: t[idx][buy]

    // Recursive function with memoization
    int solve(vector<int> &prices, int idx, bool buy) {

        // Base case: no more days left
        if(idx >= prices.size()) return 0;

        // If already computed, return stored result
        if(t[idx][buy] != -1) return t[idx][buy];

        // If we are allowed to BUY
        if(buy) {
            // Option 1: Buy today → subtract price
            int buy_today = solve(prices, idx + 1, false) - prices[idx];

            // Option 2: Skip buying
            int buy_next = solve(prices, idx + 1, true);

            // Take maximum profit
            return t[idx][buy] = max(buy_today, buy_next);
        }
        else {
            // If we are allowed to SELL

            // Option 1: Sell today → add price and subtract fee
            int sell_today = prices[idx] + solve(prices, idx + 1, true) - trFee;

            // Option 2: Skip selling
            int sell_next = solve(prices, idx + 1, false);

            // Take maximum profit
            return t[idx][buy] = max(sell_today, sell_next);
        }
    }

    int maxProfit(vector<int>& prices, int fee) {
        // Initialize DP table with -1 (uncomputed)
        memset(t, -1, sizeof(t));

        trFee = fee;

        // Start from day 0 with buying allowed
        return solve(prices, 0, true);
    }
};

int main() {
    Solution obj;

    // Sample input
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;

    // Function call
    int result = obj.maxProfit(prices, fee);

    // Output result
    cout << "Maximum Profit: " << result << endl;

    return 0;
}