// Leetcode 3212. Count Submatrices With Equal Number of X and Y



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;

        // prefix[i][j] stores:
        // {count of 'X', count of 'Y'} from (0,0) to (i,j)
        vector<vector<pair<int, int>>> prefix(
            n, vector<pair<int, int>>(m, {0, 0})
        );

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                pair<int, int> temp;

                // Step 1: Current cell contribution
                if (grid[i][j] == 'X') temp = {1, 0};
                else if (grid[i][j] == 'Y') temp = {0, 1};
                else temp = {0, 0};

                // Step 2: Add top prefix
                if (i > 0) {
                    auto up = prefix[i - 1][j];
                    temp.first += up.first;
                    temp.second += up.second;
                }

                // Step 3: Add left prefix
                if (j > 0) {
                    auto left = prefix[i][j - 1];
                    temp.first += left.first;
                    temp.second += left.second;
                }

                // Step 4: Remove double-counted diagonal
                if (i > 0 && j > 0) {
                    auto diag = prefix[i - 1][j - 1];
                    temp.first -= diag.first;
                    temp.second -= diag.second;
                }

                // Store prefix result
                prefix[i][j] = temp;

                // Step 5: Check condition
                // Equal number of X and Y and at least one X
                if (temp.first == temp.second && temp.first > 0) {
                    count++;
                }
            }
        }

        return count;
    }
};

int main() {
    int n, m;

    cout << "Enter rows and columns: ";
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    cout << "Enter grid (X, Y or .):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    int result = obj.numberOfSubmatrices(grid);

    cout << "Number of valid submatrices: " << result << endl;

    return 0;
}