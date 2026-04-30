// Leetcode 63. Unique Paths II



// Approach 1 (Recursion + Memoization):

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int m, n;
    int t[101][101]; // DP array for memoization

    // Recursive function to count unique paths
    int solve(vector<vector<int>>& grid, int i, int j) {

        // If reached destination → valid path found
        if(i == m-1 && j == n-1) return 1;

        // Out of bounds OR obstacle → no path
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 1) return 0;

        // If already computed → return stored result
        if(t[i][j] != -1) return t[i][j];

        // Move down
        int down = solve(grid, i+1, j);

        // Move right
        int right = solve(grid, i, j+1);

        // Store result in DP table and return
        return t[i][j] = down + right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {

        m = grid.size();        // number of rows
        n = grid[0].size();     // number of columns

        memset(t, -1, sizeof(t)); // initialize DP with -1

        // If destination itself is blocked → no paths
        if(grid[m-1][n-1] == 1) return 0;

        // Start recursion from (0,0)
        return solve(grid, 0, 0);
    }
};

int main() {

    // Example input:
    // 0 → free cell
    // 1 → obstacle
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    Solution obj;

    int result = obj.uniquePathsWithObstacles(grid);

    cout << "Unique Paths: " << result << endl;

    return 0;
}








// Approach 2 (Tabulation):

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int m = grid.size();        // number of rows
        int n = grid[0].size();     // number of columns

        // If start or end is blocked → no path possible
        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) return 0;

        // DP table where t[i][j] = number of ways to reach (i,j)
        vector<vector<int>> t(m, vector<int>(n, 0));

        // Starting point
        t[0][0] = 1;

        // Fill first row
        for (int j = 1; j < n; j++) {
            // If current cell is not blocked → inherit from left
            if (grid[0][j] == 0)
                t[0][j] = t[0][j - 1];
        }

        // Fill first column
        for (int i = 1; i < m; i++) {
            // If current cell is not blocked → inherit from top
            if (grid[i][0] == 0)
                t[i][0] = t[i - 1][0];
        }

        // Fill remaining DP table
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {

                // If cell is not obstacle
                if(grid[i][j] == 0) {
                    // Ways = from top + from left
                    t[i][j] = t[i-1][j] + t[i][j-1];
                }
                // If obstacle → remain 0
            }
        }
        
        // Final answer = ways to reach bottom-right
        return t[m-1][n-1];
    }
};

int main() {

    // Example input:
    // 0 → free cell
    // 1 → obstacle
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    Solution obj;
    int result = obj.uniquePathsWithObstacles(grid);

    cout << "Unique Paths: " << result << endl;

    return 0;
}