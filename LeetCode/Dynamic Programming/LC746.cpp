// Leetcode 746. Min Cost Climbing Stairs





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // ----------- Approach 1: Recursion + Memoization -----------
    int solve(int i, vector<int>& cost, vector<int>& dp) {
        if(i >= cost.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int oneStep = cost[i] + solve(i+1, cost, dp);
        int twoStep = cost[i] + solve(i+2, cost, dp);

        return dp[i] = min(oneStep, twoStep);
    }

    int memoization(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);

        return min(solve(0, cost, dp), solve(1, cost, dp));
    }


    // ----------- Approach 2: Tabulation -----------
    int tabulation(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+2, 0);

        for(int i = n-1; i >= 0; i--) {
            dp[i] = cost[i] + min(dp[i+1], dp[i+2]);
        }

        return min(dp[0], dp[1]);
    }


    // ----------- Approach 3: Space Optimization -----------
    int spaceOptimized(vector<int>& cost) {

        int next1 = 0;
        int next2 = 0;

        for(int i = cost.size()-1; i >= 0; i--) {

            int curr = cost[i] + min(next1, next2);

            next2 = next1;
            next1 = curr;
        }

        return min(next1, next2);
    }
};



int main() {

    int n;
    cout << "Enter number of stairs: ";
    cin >> n;

    vector<int> cost(n);

    cout << "Enter cost array:\n";
    for(int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    Solution obj;

    cout << "\nMemoization Answer: "
         << obj.memoization(cost) << endl;

    cout << "Tabulation Answer: "
         << obj.tabulation(cost) << endl;

    cout << "Space Optimized Answer: "
         << obj.spaceOptimized(cost) << endl;

    return 0;
}