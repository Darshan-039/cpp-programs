// Leetcode 2352. Equal Row and Column Pairs




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();

        // Map to store frequency of each row
        map<vector<int>, int> mp;

        // Store each row in map
        for (auto& row : grid) {
            mp[row]++;
        }

        int count = 0;

        // Traverse each column
        for (int col = 0; col < n; col++) {

            vector<int> temp; // To store current column

            // Build column as a vector
            for (int row = 0; row < n; row++) {
                temp.push_back(grid[row][col]);
            }

            // If this column matches any row, add its frequency
            count += mp[temp];
        }

        return count;
    }
};

int main() {
    int n;
    cout << "Enter size of matrix (n x n): ";
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    int result = obj.equalPairs(grid);

    cout << "Number of equal row-column pairs: " << result << endl;

    return 0;
}