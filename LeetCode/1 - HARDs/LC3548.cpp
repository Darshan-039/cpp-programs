// Leetcode 3548. Check if Grid Can Be Partitioned



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    typedef long long ll;
    ll total = 0; // stores total sum of grid

    // 🔹 Check if horizontal cut is possible
    bool checkHorCuts(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        unordered_set<ll> st; // store elements seen so far
        ll top = 0; // sum of upper part

        // Try cutting after each row
        for(int i = 0; i <= m-2; i++) {

            // Add current row to "top" part
            for(int j = 0; j < n; j++) {
                st.insert(grid[i][j]);
                top += grid[i][j];
            }

            ll bottom = total - top; // remaining sum
            ll diff = top - bottom;  // difference

            // ✅ Case 1: equal partition
            if(diff == 0) return true;

            // ✅ Case 2: try removing one element to balance
            if(diff == (ll)grid[0][0]) return true;
            if(diff == (ll)grid[0][n-1]) return true;
            if(diff == (ll)grid[i][0]) return true;

            // ✅ Case 3: check if diff exists in seen elements
            if(i > 0 && n > 1 && st.count(diff)) return true;
        }

        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // 🔹 Calculate total sum of grid
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }

        // 🔹 Check horizontal cuts
        if(checkHorCuts(grid)) return true;

        // Reverse rows → simulate cutting from bottom
        reverse(grid.begin(), grid.end());
        if(checkHorCuts(grid)) return true;

        // Restore original grid
        reverse(grid.begin(), grid.end());

        // 🔹 Check vertical cuts using transpose
        vector<vector<int>> transposeGrid(n, vector<int>(m));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) { 
                transposeGrid[j][i] = grid[i][j];
            }
        }

        if(checkHorCuts(transposeGrid)) return true;

        // Reverse transpose → simulate opposite direction
        reverse(transposeGrid.begin(), transposeGrid.end());
        if(checkHorCuts(transposeGrid)) return true;

        return false;
    }
};


// 🔥 MAIN FUNCTION (Sample Input)
int main() {
    Solution obj;

    // Example grid
    vector<vector<int>> grid = {
        {2, 1, 3},
        {1, 2, 1},
        {1, 1, 2}
    };

    // Call function
    bool ans = obj.canPartitionGrid(grid);

    // Output result
    if(ans) cout << "Partition possible\n";
    else cout << "Partition not possible\n";

    return 0;
}