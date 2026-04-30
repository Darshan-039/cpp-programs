// Leetcode 122. Best Time to Buy and Sell Stock II


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // If less than 2 days, no transaction possible
        if(n <= 1) return 0;

        // t[i] = maximum profit we can achieve up to day i
        vector<int> t(n, 0);

        t[0] = 0;

        // For day 1, either do nothing or buy on day 0 and sell on day 1
        t[1] = max(0, prices[1] - prices[0]);

        // Fill DP array
        for(int i = 2; i < n; i++) {

            // Case 1: Do nothing on day i
            t[i] = t[i-1];

            // Case 2: Try selling on day i
            for(int j = 0; j <= i-1; j++) {

                // Profit if we buy on day j and sell on day i
                int today_profit = prices[i] - prices[j];

                // Profit before day j (non-overlapping transactions)
                int prev_profit = (j >= 1) ? t[j-1] : 0;

                // Update maximum profit
                t[i] = max(t[i], today_profit + prev_profit);
            }
        }

        return t[n-1];
    }
};

int main() {
    Solution obj;

    // Sample Input
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};

    // Function Call
    int result = obj.maxProfit(prices);

    // Output
    cout << "Maximum Profit: " << result << endl;

    return 0;
}