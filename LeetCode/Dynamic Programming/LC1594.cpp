// Leetcode 1594. Maximum Non Negative Product in a Matrix




// Approach - 1 (Top-Down DP with Memoization):

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;
    int MOD = 1e9 + 7;

    typedef long long ll;

    // DP table: stores {maxProduct, minProduct} from (i,j) to end
    vector<vector<pair<ll, ll>>> t;

    // Recursive function to compute max & min product paths
    pair<ll, ll> solve(vector<vector<int>> &grid, int i, int j) {

        // Base case: reached bottom-right cell
        if(i == m-1 && j == n-1) 
            return {grid[i][j], grid[i][j]};

        // If already computed, return memoized value
        if(t[i][j] != make_pair(LLONG_MIN, LLONG_MAX)) 
            return t[i][j];

        ll maxVal = LLONG_MIN;  // max product from this cell
        ll minVal = LLONG_MAX;  // min product from this cell

        // Move Down
        if(i+1 < m) {
            auto [downMax, downMin] = solve(grid, i+1, j);

            // Multiply current value with both max & min
            maxVal = max({maxVal, grid[i][j] * downMax, grid[i][j] * downMin});
            minVal = min({minVal, grid[i][j] * downMax, grid[i][j] * downMin});
        }

        // Move Right
        if(j+1 < n) {
            auto [rightMax, rightMin] = solve(grid, i, j+1);

            maxVal = max({maxVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
            minVal = min({minVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
        }

        // Store result in DP table
        return t[i][j] = {maxVal, minVal};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Initialize DP with extreme values
        t = vector<vector<pair<ll, ll>>>(
            m, vector<pair<ll, ll>>(n, {LLONG_MIN, LLONG_MAX})
        );

        auto [maxProduct, minProduct] = solve(grid, 0, 0);

        // If maximum product is negative → return -1
        if(maxProduct < 0) return -1;

        return maxProduct % MOD;
    }
};

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    // Input grid
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    cout << obj.maxProductPath(grid) << endl;

    return 0;
}







// Approach - 2 (Bottom-Up DP):

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MOD = 1e9 + 7;
    typedef long long ll;

    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // DP table:
        // first  -> maximum product till this cell
        // second -> minimum product till this cell
        vector<vector<pair<ll, ll>>> t(m, vector<pair<ll, ll>>(n));

        // Base case: starting cell
        t[0][0] = {grid[0][0], grid[0][0]};

        // ✅ Fill first row (only left movement possible)
        for(int j = 1; j < n; j++) {
            t[0][j].first = t[0][j-1].first * grid[0][j];
            t[0][j].second = t[0][j-1].second * grid[0][j];
        }

        // ✅ Fill first column (only upward movement possible)
        for(int i = 1; i < m; i++) {
            t[i][0].first = t[i-1][0].first * grid[i][0];
            t[i][0].second = t[i-1][0].second * grid[i][0];
        }

        // ✅ Fill rest of the matrix
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {

                ll upMax = t[i-1][j].first;
                ll upMin = t[i-1][j].second;

                ll leftMax = t[i][j-1].first;
                ll leftMin = t[i][j-1].second;

                // Consider all 4 possibilities because of negative numbers
                t[i][j].first = max({
                    upMax * grid[i][j],
                    upMin * grid[i][j],
                    leftMax * grid[i][j],
                    leftMin * grid[i][j]
                });

                t[i][j].second = min({
                    upMax * grid[i][j],
                    upMin * grid[i][j],
                    leftMax * grid[i][j],
                    leftMin * grid[i][j]
                });
            }
        }

        auto [maxProduct, minProduct] = t[m-1][n-1];

        // If maximum product is negative → no valid answer
        if(maxProduct < 0) return -1;

        return maxProduct % MOD;
    }
};

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    // Input grid values
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    cout << obj.maxProductPath(grid) << endl;

    return 0;
}