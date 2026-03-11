// Leetcode 518. Coin Change II




#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:

    // DP table
    // t[i][amount] = number of ways to make 'amount'
    // using coins from index i onward
    int t[301][5001];

    int solve(int i, int amount, vector<int>& coins) {

        // Base Case 1:
        // If amount becomes 0 → we found a valid combination
        if(amount == 0)
            return 1;

        // Base Case 2:
        // If we have used all coins but amount is still > 0
        if(i >= coins.size())
            return 0;

        // If result already computed → return memoized value
        if(t[i][amount] != -1)
            return t[i][amount];

        int take = 0;

        // Option 1: Take the current coin
        // We can reuse the same coin because coins are infinite
        if(coins[i] <= amount)
            take = solve(i, amount - coins[i], coins);

        // Option 2: Skip the current coin
        int skip = solve(i + 1, amount, coins);

        // Store result in DP table
        return t[i][amount] = take + skip;
    }

    int change(int amount, vector<int>& coins) {

        // Initialize DP table with -1
        memset(t, -1, sizeof(t));

        // Start recursion from coin index 0
        return solve(0, amount, coins);
    }
};

int main() {

    int amount, n;

    cout << "Enter amount: ";
    cin >> amount;

    cout << "Enter number of coins: ";
    cin >> n;

    vector<int> coins(n);

    cout << "Enter coin values:\n";
    for(int i = 0; i < n; i++)
        cin >> coins[i];

    Solution obj;

    int result = obj.change(amount, coins);

    cout << "Number of combinations = " << result << endl;

    return 0;
}
