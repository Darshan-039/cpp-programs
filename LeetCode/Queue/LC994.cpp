// Leetcode 994. Rotting Oranges


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // 🔹 Queue stores: {{row, col}, time}
        queue<pair<pair<int, int>, int>> q;

        // Track visited cells (already rotten/processed)
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int fresh = 0; // count of fresh oranges

        // 🔹 Step 1: Push all initially rotten oranges into queue
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0}); // rotten orange at time 0
                    visited[i][j] = true;
                }
                else if(grid[i][j] == 1) {
                    fresh++; // count fresh oranges
                }
            }
        }

        int time = 0;

        // Directions: up, right, down, left
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        // 🔹 Step 2: BFS traversal
        while(!q.empty()) {
            auto top = q.front();
            q.pop();

            int x = top.first.first;
            int y = top.first.second;
            int t = top.second;

            // Track maximum time taken
            time = max(time, t);

            // Explore all 4 directions
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                // If inside grid AND fresh orange → rot it
                if(nx >= 0 && ny >= 0 && nx < m && ny < n &&
                   !visited[nx][ny] && grid[nx][ny] == 1) {

                    visited[nx][ny] = true;
                    q.push({{nx, ny}, t + 1}); // next minute
                    fresh--; // one fresh orange became rotten
                }
            }
        }

        // 🔹 Step 3: If any fresh orange left → impossible
        if(fresh > 0) return -1;

        return time;
    }
};

int main() {
    int m, n;
    cout << "Enter rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    cout << "Enter grid (0 = empty, 1 = fresh, 2 = rotten):\n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    int result = obj.orangesRotting(grid);

    cout << "Minimum time to rot all oranges: " << result << endl;

    return 0;
}