// Leetcode 123. Best Time to Buy and Sell Stock III


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // DP table:
    // t[i][transactions][buy]
    // i → current day
    // transactions → remaining transactions (max 2)
    // buy → 1 means we can buy, 0 means we must sell
    int t[100001][3][2];

    int solve(vector<int> &prices, int i, int transactions, bool buy) {
        
        //  Base cases
        if(i >= prices.size()) return 0;      // No days left
        if(transactions == 0) return 0;       // No transactions left

        //  Memoization check
        if(t[i][transactions][buy] != -1) 
            return t[i][transactions][buy];
        
        //  If we can BUY
        if(buy) {
            // Option 1: Buy today
            int buy_today = solve(prices, i+1, transactions, false) - prices[i];

            // Option 2: Skip today
            int buy_next = solve(prices, i+1, transactions, true);

            return t[i][transactions][buy] = max(buy_today, buy_next);
        }
        else {
            //  If we must SELL

            // Option 1: Sell today
            int sell_today = prices[i] + solve(prices, i+1, transactions-1, true);
            
            // Option 2: Skip today
            int sell_next = solve(prices, i+1, transactions, false);

            return t[i][transactions][buy] = max(sell_today, sell_next);
        }
    }

    int maxProfit(vector<int>& prices) {
        // Initialize DP table with -1
        memset(t, -1, sizeof(t));

        // Start from day 0, 2 transactions allowed, and we can buy
        return solve(prices, 0, 2, true);
    }
};

int main() {
    Solution obj;

    // Sample Input
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};

    //  Function Call
    int result = obj.maxProfit(prices);

    //  Output
    cout << "Maximum Profit (at most 2 transactions): " << result << endl;

    return 0;
}