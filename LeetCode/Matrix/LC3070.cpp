// Leetcode 3070. Count Submatrices With Sum Less Than or Equal to K




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;

        // 🔹 Prefix sum matrix
        // prefix[i][j] = sum of submatrix from (0,0) to (i,j)
        vector<vector<int>> prefix(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                // Start with current cell value
                prefix[i][j] = grid[i][j];

                // Add top part
                if(i > 0) prefix[i][j] += prefix[i-1][j];

                // Add left part
                if(j > 0) prefix[i][j] += prefix[i][j-1];

                // Remove double-counted area
                if(i > 0 && j > 0) 
                    prefix[i][j] -= prefix[i-1][j-1];

                // 🔹 Check if sum of submatrix (0,0) → (i,j) ≤ k
                if(prefix[i][j] <= k) 
                    count++;
            }
        }

        return count;
    }
};

int main() {
    Solution obj;

    // 🔹 Sample Input
    vector<vector<int>> grid = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };

    int k = 4;

    // 🔹 Function call
    int result = obj.countSubmatrices(grid, k);

    // 🔹 Output
    cout << "Count of submatrices with sum <= k: " << result << endl;

    return 0;
}