// Leetcode:-121 Best Time to Buy and Sell Stock

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minPrice = prices[0];

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > minPrice) {
                maxProfit = max(maxProfit, prices[i] - minPrice);
            }
            minPrice = min(minPrice, prices[i]);
        }

        return maxProfit;
    }
};

int main() {
    // ⭐ Input inside the code
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << "Prices: ";
    for (int x : prices) cout << x << " ";
    cout << endl;

    Solution obj;
    int result = obj.maxProfit(prices);

    cout << "Maximum Profit = " << result << endl;

    return 0;
}
