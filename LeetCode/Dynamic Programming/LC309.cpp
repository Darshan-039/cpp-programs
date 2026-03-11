// Leetcode 309. Best Time to Buy and Sell Stock with Cooldown



// Approach - 1: Recursion + Memoization

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <cstring>

// using namespace std;

// class Solution {
// public:
//     int n;
//     int t[5001][2]; 

//     int solve(vector<int> &prices, int day, bool buy) {
//         if(day >= n) return 0;
//         if(t[day][buy] != -1) return t[day][buy];

//         int profit = 0;
//         if(buy) {
//             int take = solve(prices, day+1, false) - prices[day];
//             int not_take = solve(prices, day+1, true);
//             profit = max(take, not_take);
//         }
//         else {
//             int take = prices[day] + solve(prices, day+2, true);
//             int not_take = solve(prices, day+1, false);
//             profit = max(take, not_take);
//         }

//         return t[day][buy] = profit;
//     }

//     int maxProfit(vector<int>& prices) {
//         n = prices.size();
//         if (n == 0) return 0;
//         memset(t, -1, sizeof(t));
//         return solve(prices, 0, true);
//     }
// };

// int main() {
//     Solution sol;
    
//     // Example Input: [1, 2, 3, 0, 2]
//     // Day 1: Buy (price 1)
//     // Day 2: Sell (price 2) -> Profit = 1
//     // Day 3: Cooldown
//     // Day 4: Buy (price 0)
//     // Day 5: Sell (price 2) -> Profit = 2
//     // Total Max Profit = 3
//     vector<int> prices = {1, 2, 3, 0, 2};
    
//     cout << "Max Profit: " << sol.maxProfit(prices) << endl;

//     return 0;
// }

















// Approach - 2 : Tabulation (Bottom-Up DP)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // Base Case: Not enough days to complete a buy-sell cycle
        if(n <= 1) return 0;

        // t[i] = maximum profit achievable by the end of day 'i'
        vector<int> t(n, 0);

        // Day 0: Max profit is 0 (can't sell yet)
        t[0] = 0;
        // Day 1: Max profit is either nothing (0) or selling what we bought on Day 0
        t[1] = max(0, prices[1] - prices[0]);

        for(int i = 2; i < n; i++) {
            // OPTION 1: Skip selling today. Carry over yesterday's max profit.
            t[i] = t[i-1];

            // OPTION 2: Sell today at prices[i]. 
            // We check every previous day 'j' to see if buying then was optimal.
            for(int j = 0; j <= i-1; j++) {

                // Current profit if we bought at j and sell at i
                int today_profit = prices[i] - prices[j];

                // COOLDOWN: If we bought at day j, we must have been 
                // on cooldown at day j-1. So the previous profit must 
                // come from day j-2.
                int prev_profit = (j >= 2) ? t[j-2] : 0;

                // Update t[i] with the best possible combination
                t[i] = max(t[i], today_profit + prev_profit);
            }
        }

        return t[n-1];
    }
};

int main() {
    Solution sol;

    // Example Input: [1, 2, 3, 0, 2]
    // Calculation:
    // Day 0 & 1: Buy 1, Sell 2 (Profit 1)
    // Day 2: Cooldown
    // Day 3: Buy 0
    // Day 4: Sell 2 (Profit 2)
    // Total = 3
    vector<int> input_prices = {1, 2, 3, 0, 2};

    int result = sol.maxProfit(input_prices);

    cout << "Prices: ";
    for(int p : input_prices) cout << p << " ";
    cout << "\nMaximum Profit: " << result << endl;

    return 0;
}