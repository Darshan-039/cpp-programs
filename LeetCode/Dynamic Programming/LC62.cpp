// Leetcode 62. Unique Paths




// Approach - 1 (Recursion + Memoization)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int t[101][101]; // DP array for memoization

    // Recursive function to count paths from (i, j) to (m-1, n-1)
    int solve(int i, int j, int m, int n) {

        // Base case: reached destination
        if(i == m-1 && j == n-1) return 1;

        // Out of bounds → no valid path
        if(i < 0 || i >= m || j < 0 || j >= n) return 0;

        // If already computed, return stored value
        if(t[i][j] != -1) return t[i][j];

        // Move right (j+1)
        int right = solve(i, j+1, m, n);

        // Move down (i+1)
        int down = solve(i+1, j, m, n);

        // Store result in DP table and return
        return t[i][j] = down + right;
    }

    int uniquePaths(int m, int n) {
        // Initialize DP array with -1
        memset(t, -1, sizeof(t));

        // Start from top-left corner (0,0)
        return solve(0, 0, m, n);
    }
};

int main() {
    int m, n;

    // Input grid size
    cout << "Enter number of rows (m): ";
    cin >> m;

    cout << "Enter number of columns (n): ";
    cin >> n;

    Solution obj;

    // Function call
    int result = obj.uniquePaths(m, n);

    // Output result
    cout << "Number of Unique Paths: " << result << endl;

    return 0;
}











// Approach - 2 (Tabulation)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {

        // Step 1: Create DP table initialized with 1
        // First row & first column will always be 1
        vector<vector<int>> t(m+1, vector<int>(n+1, 1));

        // Step 2: Fill the DP table
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {

                // Number of ways = from top + from left
                t[i][j] = t[i-1][j] + t[i][j-1];
            }
        }

        // Step 3: Return bottom-right cell
        return t[m-1][n-1];
    }
};

int main() {
    int m, n;

    // Input grid size
    cout << "Enter number of rows (m): ";
    cin >> m;

    cout << "Enter number of columns (n): ";
    cin >> n;

    Solution obj;

    // Function call
    int result = obj.uniquePaths(m, n);

    // Output result
    cout << "Number of Unique Paths: " << result << endl;

    return 0;
}