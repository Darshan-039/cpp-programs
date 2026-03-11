// Leetcode 64. Minimum Path Sum




// Approach - 1 (Using Recursion - Top Down DP)

// #include <iostream>
// #include <vector>
// #include <climits>
// using namespace std;

// class Solution {
// public:

//     // grid dimensions
//     int n, m;

//     /*
//         Recursive function to find minimum path sum
//         from (i, j) → (n-1, m-1)

//         Allowed moves:
//         → Right
//         → Down
//     */
//     int solve(vector<vector<int>>& grid, int i, int j) {

//         // Base Case:
//         // If we reached destination cell
//         if(i == n-1 && j == m-1)
//             return grid[i][j];

//         // initialize large values
//         int right = INT_MAX;
//         int down  = INT_MAX;

//         // move RIGHT if inside grid
//         if(j + 1 < m)
//             right = grid[i][j] + solve(grid, i, j + 1);

//         // move DOWN if inside grid
//         if(i + 1 < n)
//             down = grid[i][j] + solve(grid, i + 1, j);

//         // choose minimum cost path
//         return min(right, down);
//     }

//     // main function called by user
//     int minPathSum(vector<vector<int>>& grid) {

//         // store grid size
//         n = grid.size();
//         m = grid[0].size();

//         // start from top-left cell
//         return solve(grid, 0, 0);
//     }
// };


// // ---------------- MAIN FUNCTION (INPUT ADDED) ----------------

// int main() {

//     /*
//         Example Grid:

//         1 3 1
//         1 5 1
//         4 2 1

//         Minimum Path:
//         1 → 3 → 1 → 1 → 1

//         Output = 7
//     */

//     vector<vector<int>> grid = {
//         {1,3,1},
//         {1,5,1},
//         {4,2,1}
//     };

//     Solution obj;

//     int result = obj.minPathSum(grid);

//     cout << "Minimum Path Sum = " << result << endl;

//     return 0;
// }














// Approach - 2 (Using Tabulation - Bottom Up DP)

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        /*
            We convert grid itself into DP table.

            grid[i][j] =
            minimum cost to reach cell (i,j)
            from (0,0)
        */

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                // starting cell (no previous path)
                if(i == 0 && j == 0)
                    continue;

                // cost coming from UP
                int up = INT_MAX;
                if(i - 1 >= 0)
                    up = grid[i-1][j];

                // cost coming from LEFT
                int left = INT_MAX;
                if(j - 1 >= 0)
                    left = grid[i][j-1];

                // choose minimum path
                grid[i][j] += min(up, left);
            }
        }

        // answer stored at bottom-right cell
        return grid[n-1][m-1];
    }
};