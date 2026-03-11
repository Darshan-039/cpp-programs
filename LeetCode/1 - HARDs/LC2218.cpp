// Leetcode 2218. Maximum Value of K Coins From Piles






// Approach - 1 Recursion + Memoization

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int n;                    // number of piles
    int t[1001][2001];        // DP table: t[i][k] = max value using piles from i with k coins remaining

    int solve(int i, vector<vector<int>> &piles, int k) {

        // If we used all piles
        if(i >= n) 
            return 0;

        // If already computed
        if(t[i][k] != -1) 
            return t[i][k];

        // Option 1: Do not take coins from this pile
        int not_taken = solve(i+1, piles, k);

        int taken = 0;
        int sum = 0;

        // Try taking coins from this pile
        // We can take at most k coins or pile size
        for(int j = 0; j < min((int)piles[i].size(), k); j++) {

            // Add current coin value
            sum += piles[i][j];

            // Recursively solve for remaining piles and coins
            taken = max(taken, sum + solve(i+1, piles, k-(j+1)));
        }

        // Store result in DP table
        return t[i][k] = max(taken, not_taken);
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {

        n = piles.size();

        // Initialize DP table with -1
        memset(t, -1, sizeof(t));

        return solve(0, piles, k);
    }
};


int main() {

    Solution obj;

    // Example Input
    vector<vector<int>> piles = {
        {1,100,3},
        {7,8,9}
    };

    int k = 2;

    cout << "Maximum value of coins = " 
         << obj.maxValueOfCoins(piles, k) << endl;

    return 0;
}













// Approach - 2 Tabulation

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {

        int n = piles.size();

        // DP table
        // t[i][j] = maximum value using first i piles and taking j coins
        vector<vector<int>> t(n+1, vector<int>(k+1, 0));

        // Traverse each pile
        for(int i = 1; i <= n; i++) {

            // Number of coins we want to take
            for(int coins = 0; coins <= k; coins++) {

                int sum = 0;

                // Try taking currCoins from current pile
                for(int currCoins = 0; 
                    currCoins <= min((int)piles[i-1].size(), coins); 
                    currCoins++) {

                    // Add value of coin from current pile
                    if(currCoins > 0)
                        sum += piles[i-1][currCoins-1];

                    // Update DP value
                    t[i][coins] = max(
                        t[i][coins],
                        sum + t[i-1][coins-currCoins]
                    );
                }
            }
        }

        // Maximum value using all piles and k coins
        return t[n][k];
    }
};


int main() {

    int n;
    cout << "Enter number of piles: ";
    cin >> n;

    vector<vector<int>> piles(n);

    for(int i = 0; i < n; i++) {

        int m;
        cout << "Enter number of coins in pile " << i+1 << ": ";
        cin >> m;

        piles[i].resize(m);

        cout << "Enter coin values:\n";
        for(int j = 0; j < m; j++) {
            cin >> piles[i][j];
        }
    }

    int k;
    cout << "Enter total coins to pick (k): ";
    cin >> k;

    Solution obj;

    int result = obj.maxValueOfCoins(piles, k);

    cout << "Maximum value = " << result << endl;

    return 0;
}