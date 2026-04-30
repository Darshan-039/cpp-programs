// Leetcode 200. Number of Islands


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int m, n;

    // DFS function to mark all connected land cells
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // Base case: out of bounds or water / already visited
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') {
            return;
        }

        // Mark current land cell as visited
        grid[i][j] = '$';

        // Visit all 4 directions
        dfs(grid, i + 1, j); // down
        dfs(grid, i - 1, j); // up
        dfs(grid, i, j + 1); // right
        dfs(grid, i, j - 1); // left
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int islands = 0;

        // Traverse the entire grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Found unvisited land
                if (grid[i][j] == '1') {
                    dfs(grid, i, j); // mark connected island
                    islands++;
                }
            }
        }

        return islands;
    }
};

int main() {
    int m, n;

    // Input rows and columns
    cout << "Enter number of rows: ";
    cin >> m;

    cout << "Enter number of columns: ";
    cin >> n;

    vector<vector<char>> grid(m, vector<char>(n));

    // Input grid values
    cout << "Enter grid values (0 for water, 1 for land):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;

    // Output number of islands
    cout << "Number of islands: " << obj.numIslands(grid) << endl;

    return 0;
}