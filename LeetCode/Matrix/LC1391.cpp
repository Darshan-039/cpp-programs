// Leetcode 1391. Check if There is a Valid Path in a Grid


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

    int m, n;

    /*
        Street Types:

        1 -> left, right
        2 -> up, down
        3 -> left, down
        4 -> right, down
        5 -> left, up
        6 -> up, right
    */

    // Mapping each street type to its possible directions
    unordered_map<int, vector<vector<int>>> directions = {

        {1, {{0, -1}, {0, 1}}},     // left, right
        {2, {{-1, 0}, {1, 0}}},    // up, down
        {3, {{0, -1}, {1, 0}}},    // left, down
        {4, {{0, 1}, {1, 0}}},     // right, down
        {5, {{0, -1}, {-1, 0}}},   // left, up
        {6, {{-1, 0}, {0, 1}}}     // up, right
    };

    // DFS function to check valid path
    bool dfs(vector<vector<int>>& grid,
             int i,
             int j,
             vector<vector<bool>>& visited) {

        // Reached destination
        if (i == m - 1 && j == n - 1) {
            return true;
        }

        visited[i][j] = true;

        // Explore all possible directions
        for (auto &dir : directions[grid[i][j]]) {

            int new_i = i + dir[0];
            int new_j = j + dir[1];

            // Boundary check + visited check
            if (new_i < 0 || new_i >= m ||
                new_j < 0 || new_j >= n ||
                visited[new_i][new_j]) {

                continue;
            }

            /*
                IMPORTANT:
                Check whether next cell can connect back
                to current cell
            */

            for (auto &backDir : directions[grid[new_i][new_j]]) {

                if (new_i + backDir[0] == i &&
                    new_j + backDir[1] == j) {

                    // Continue DFS
                    if (dfs(grid, new_i, new_j, visited)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        // Visited matrix
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Start DFS from top-left corner
        return dfs(grid, 0, 0, visited);
    }
};

int main() {

    int rows, cols;

    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> grid(rows, vector<int>(cols));

    cout << "Enter grid values:\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;

    if (obj.hasValidPath(grid)) {
        cout << "Valid Path Exists\n";
    } else {
        cout << "No Valid Path\n";
    }

    return 0;
}