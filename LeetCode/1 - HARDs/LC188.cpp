// Leetcode 188. Best Time to Buy and Sell Stock IV




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Recursive DP function
    // i → current day
    // transactions → remaining transactions
    // buy → 1 means we can buy, 0 means we need to sell
    int solve(vector<int> &prices, int i, int transactions, bool buy, 
              vector<vector<vector<int>>> &t) {
        
        // Base case: no days left or no transactions left
        if(i >= prices.size() || transactions == 0) return 0;

        // Return already computed result
        if(t[i][transactions][buy] != -1) 
            return t[i][transactions][buy];
        
        // If we can buy
        if(buy) {
            // Option 1: Buy today
            int buy_today = solve(prices, i+1, transactions, false, t) - prices[i];

            // Option 2: Skip today
            int buy_next = solve(prices, i+1, transactions, true, t);

            return t[i][transactions][buy] = max(buy_today, buy_next);
        }
        else {
            // If we must sell

            // Option 1: Sell today
            int sell_today = prices[i] + solve(prices, i+1, transactions-1, true, t);
            
            // Option 2: Skip today
            int sell_next = solve(prices, i+1, transactions, false, t);

            return t[i][transactions][buy] = max(sell_today, sell_next);
        }
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        // 3D DP array: n x (k+1) x 2
        vector<vector<vector<int>>> t(n, vector<vector<int>>(k+1, vector<int>(2, -1)));

        // Start from day 0, k transactions, and we can buy
        return solve(prices, 0, k, true, t);
    }
};

int main() {
    Solution obj;

    // Sample Input
    int k = 2;
    vector<int> prices = {3, 2, 6, 5, 0, 3};

    // Function Call
    int result = obj.maxProfit(k, prices);

    // Output
    cout << "Maximum Profit with " << k << " transactions: " << result << endl;

    return 0;
}