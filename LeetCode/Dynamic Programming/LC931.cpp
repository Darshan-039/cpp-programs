// Leetcode 931. Minimum Falling Path Sum


// Approach - 1: Recursion + Memoization (Top-Down DP)

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <climits>
// #include <cstring>

// using namespace std;

// class Solution {
// public:
//     int n;
//     int t[101][101];

//     int solve(vector<vector<int>> &matrix, int row, int col) {
//         // Base Case
//         if(row == n-1) return matrix[row][col];

//         if(t[row][col] != -1) return t[row][col];

//         int sum = matrix[row][col];
//         int minAns = INT_MAX;
        
//         for(int Shift = -1; Shift <= 1; Shift++) {
//             int nextCol = col + Shift;
//             if(row+1 < n && nextCol < n && nextCol >= 0) 
//                 minAns = min(minAns, sum + solve(matrix, row+1, nextCol));
//         } 

//         return t[row][col] = minAns;
//     }

//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         n = matrix.size();
//         if(n == 0) return 0;

//         int minAns = INT_MAX;
//         memset(t, -1, sizeof(t));

//         for(int col = 0; col < n; col++) {
//             minAns = min(minAns, solve(matrix, 0, col));
//         }

//         return minAns;
//     }
// };

// int main() {
//     Solution sol;

//     // Example Input: 3x3 Matrix
//     // Path: 1 -> 4 -> 7 (Sum: 12) or 1 -> 5 -> 7 (Sum: 13) etc.
//     // The minimum path here is 1 -> 4 -> 7 or 1 -> 5 -> 7... 
//     // Wait, let's look at the standard LeetCode example:
//     // [[2,1,3],[6,5,4],[7,8,9]] -> Min path is 1 -> 5 -> 7 = 13
//     vector<vector<int>> matrix = {
//         {2, 1, 3},
//         {6, 5, 4},
//         {7, 8, 9}
//     };

//     int result = sol.minFallingPathSum(matrix);

//     cout << "Minimum Falling Path Sum: " << result << endl;

//     return 0;
// }









// Approach - 2 Iterative (Bottom-Up DP)

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        
        // DP table initialized with size n x n
        vector<vector<int>> t(n, vector<int>(n));

        // Initialize first row: the cost to start at any cell in row 0
        for(int col = 0; col < n; col++) 
            t[0][col] = matrix[0][col];

        // Fill the DP table row by row
        for(int row = 1; row < n; row++) {
            for(int col = 0; col < n; col++) {

                int a = INT_MAX; // Upper-left diagonal
                int b = INT_MAX; // Upper-right diagonal

                if(col - 1 >= 0) a = t[row-1][col-1];
                if(col + 1 < n)  b = t[row-1][col+1];

                // Current cell cost + min of the three possible previous cells
                t[row][col] = matrix[row][col] + min({t[row-1][col], a, b});
            }
        }

        // The answer is the minimum value in the last row
        int result = INT_MAX;
        for(int col = 0; col < n; col++) {
            result = min(result, t[n-1][col]);
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Example Input Matrix
    // 2  1  3
    // 6  5  4
    // 7  8  9
    vector<vector<int>> matrix = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };

    int result = sol.minFallingPathSum(matrix);

    cout << "Minimum Falling Path Sum (Iterative): " << result << endl;

    return 0;
}