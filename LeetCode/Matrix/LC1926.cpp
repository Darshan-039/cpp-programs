// Leetcode 1926. Nearest Exit from Entrance in Maze



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;

    // Function to check if a cell is valid for traversal
    bool isValid(vector<vector<char>>& maze, int i, int j, vector<vector<bool>> &visited) {
        // Out of bounds OR wall '+' OR already visited
        if(i < 0 || i >= m || j < 0 || j >= n || maze[i][j] == '+' || visited[i][j]) 
            return false;
        return true;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        m = maze.size();
        n = maze[0].size();

        // Visited matrix to avoid revisiting cells
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Queue for BFS (stores {row, col})
        queue<pair<int,int>> q;

        // Start BFS from entrance
        q.push({entrance[0], entrance[1]});
        visited[entrance[0]][entrance[1]] = true;

        int steps = 0; // number of moves taken

        // Direction arrays (Up, Down, Left, Right)
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        // Standard BFS traversal
        while(!q.empty()) {
            int size = q.size();
            steps++; // moving to next level (distance increases)

            while(size--) {
                auto [x, y] = q.front();
                q.pop();

                // Explore all 4 directions
                for(int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    // Skip invalid cells
                    if(!isValid(maze, nx, ny, visited)) continue;

                    // If it's on boundary → it's an exit
                    // (Entrance is not counted because we start from it and check neighbors)
                    if(nx == 0 || nx == m-1 || ny == 0 || ny == n-1)
                        return steps;

                    // Mark visited and push into queue
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        // No exit found
        return -1;
    }
};

int main() {
    Solution obj;

    // Sample Input
    vector<vector<char>> maze = {
        {'+', '+', '.', '+'},
        {'.', '.', '.', '+'},
        {'+', '+', '+', '.'}
    };

    vector<int> entrance = {1, 2}; // row = 1, col = 2

    int result = obj.nearestExit(maze, entrance);

    cout << "Nearest Exit Steps: " << result << endl;

    return 0;
}