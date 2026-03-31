// Leetcode 3643. Reverse Submatrix



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n = grid.size();
        int m = grid[0].size();

        // Boundary check: if starting point is invalid
        if (x >= n || y >= m) return grid;

        // Boundary check: if submatrix exceeds grid size
        if (x + k - 1 >= n || y + k - 1 >= m) return grid;

        int i = x;              // starting row of submatrix
        int j = x + k - 1;      // ending row of submatrix

        // Reverse rows within the k x k submatrix
        while (i < j) {

            // Swap entire rows (only within submatrix columns)
            for (int z = y; z < y + k; z++) {
                swap(grid[i][z], grid[j][z]);
            }

            i++;
            j--;
        }

        return grid;
    }
};

int main() {
    int n, m;
    cout << "Enter rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    cout << "Enter matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int x, y, k;
    cout << "Enter x, y (start index) and k (size of submatrix): ";
    cin >> x >> y >> k;

    Solution obj;
    vector<vector<int>> result = obj.reverseSubmatrix(grid, x, y, k);

    cout << "Updated Matrix:\n";
    for (auto row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}