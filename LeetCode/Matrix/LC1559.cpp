// Leetcode 1559. Detect Cycles in 2D Grid


#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int m, n;

    // 4 possible directions: down, up, left, right
    vector<vector<int>> directions = {
        {1, 0},
        {-1, 0},
        {0, -1},
        {0, 1}
    };

    // BFS function to detect cycle
    bool cycleDetectBFS(int r, int c,
                        vector<vector<char>>& grid,
                        vector<vector<bool>>& visited) {

        // Queue stores:
        // current_row, current_col, previous_row, previous_col
        queue<tuple<int, int, int, int>> q;

        q.push({r, c, -1, -1});
        visited[r][c] = true;

        while (!q.empty()) {

            auto [curr_r, curr_c, prev_r, prev_c] = q.front();
            q.pop();

            // Explore all 4 directions
            for (auto &dir : directions) {

                int new_r = curr_r + dir[0];
                int new_c = curr_c + dir[1];

                // Check boundaries and same character condition
                if (new_r >= 0 && new_r < m &&
                    new_c >= 0 && new_c < n &&
                    grid[new_r][new_c] == grid[curr_r][curr_c]) {

                    // Ignore the parent node
                    if (new_r == prev_r && new_c == prev_c)
                        continue;

                    // If already visited, cycle found
                    if (visited[new_r][new_c])
                        return true;

                    // Mark visited and push into queue
                    visited[new_r][new_c] = true;

                    q.push({new_r, new_c, curr_r, curr_c});
                }
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {

        m = grid.size();
        n = grid[0].size();

        // Visited matrix
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Traverse every cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Start BFS if cell is not visited
                if (!visited[i][j]) {

                    if (cycleDetectBFS(i, j, grid, visited)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

int main() {

    int rows, cols;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<char>> grid(rows, vector<char>(cols));

    cout << "Enter grid characters:\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;

    if (obj.containsCycle(grid)) {
        cout << "Cycle Detected\n";
    } else {
        cout << "No Cycle Found\n";
    }

    return 0;
}