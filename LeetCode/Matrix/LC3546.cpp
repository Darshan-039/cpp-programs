// Leetcode 3546. Partition Grid Into Two Equal Sum Subgrids



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Step 1: Calculate total sum of grid
        long long total = 0;
        for(auto &row : grid) {
            for(int x : row) {
                total += x;
            }
        }

        // Step 2: Try vertical cuts (column-wise)
        long long sum = 0;
        for(int col = 0; col < m - 1; col++) {
            
            // Add current column values
            for(int row = 0; row < n; row++) {
                sum += grid[row][col];
            }

            // Check if left part = right part
            if(sum * 2 == total) return true;
        }

        // Step 3: Try horizontal cuts (row-wise)
        sum = 0;
        for(int row = 0; row < n - 1; row++) {
            
            // Add current row values
            for(int col = 0; col < m; col++) {
                sum += grid[row][col];
            }

            // Check if top part = bottom part
            if(sum * 2 == total) return true;
        }

        // No valid partition found
        return false;
    }
};

int main() {
    int n, m;
    cout << "Enter rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    cout << "Enter grid values:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    bool result = obj.canPartitionGrid(grid);

    if(result)
        cout << "\nYes, grid can be partitioned equally.\n";
    else
        cout << "\nNo, grid cannot be partitioned equally.\n";

    return 0;
}