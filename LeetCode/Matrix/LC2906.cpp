// Leetcode 2906. Construct Product Matrix



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        const int MOD = 12345;

        // Result matrix
        vector<vector<int>> ans(n, vector<int>(m, 0));

        // Step 1: Flatten 2D grid into 1D array
        vector<int> nums;
        for(auto &row : grid) {
            for(int x : row) {
                nums.push_back(x);
            }
        }

        int size = n * m;

        // Step 2: Create prefix and suffix product arrays
        vector<int> prefix(size, 1);
        vector<int> suffix(size, 1);

        // prefix[i] = product of all elements before index i
        for(int i = 1; i < size; i++) {
            prefix[i] = (1LL * prefix[i-1] * nums[i-1]) % MOD;
        }

        // suffix[i] = product of all elements after index i
        for(int i = size - 2; i >= 0; i--) {
            suffix[i] = (1LL * suffix[i+1] * nums[i+1]) % MOD;
        }

        // Step 3: Fill answer using prefix * suffix
        int idx = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans[i][j] = (1LL * prefix[idx] * suffix[idx]) % MOD;
                idx++;
            }
        }

        return ans;
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
    vector<vector<int>> result = obj.constructProductMatrix(grid);

    cout << "\nResult Matrix:\n";
    for(auto &row : result) {
        for(int x : row) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}