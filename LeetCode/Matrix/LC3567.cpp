// Leetcode 3567. Minimum Absolute Difference in a Matrix




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Result matrix of size (m-k+1) x (n-k+1)
        vector<vector<int>> result(m - k + 1, vector<int>(n - k + 1, 0));
        
        // Traverse all possible k x k submatrices
        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                
                // Set stores elements in sorted order and removes duplicates
                set<int> vals;
                
                // Collect all elements of current k x k submatrix
                for (int r = i; r <= i + k - 1; r++) {
                    for (int c = j; c <= j + k - 1; c++) {
                        vals.insert(grid[r][c]);
                    }
                }
                
                // If only one unique element → min diff = 0 (already default)
                if (vals.size() == 1) {
                    continue;
                }
                
                int minAbsDiff = INT_MAX;
                
                // Compare adjacent elements in sorted set
                auto prev = vals.begin();
                auto curr = next(prev);
                
                while (curr != vals.end()) {
                    // Since set is sorted → difference is positive
                    minAbsDiff = min(minAbsDiff, *curr - *prev);
                    prev = curr;
                    curr++;
                }
                
                // Store result
                result[i][j] = minAbsDiff;
            }
        }
        
        return result;
    }
};

int main() {
    int m, n, k;

    cout << "Enter rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    cout << "Enter grid elements:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cout << "Enter k (submatrix size): ";
    cin >> k;

    Solution obj;
    vector<vector<int>> result = obj.minAbsDiff(grid, k);

    cout << "Result matrix:\n";
    for (auto &row : result) {
        for (auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}