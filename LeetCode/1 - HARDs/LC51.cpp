// Leetcode 51: N-Queens Problem







// Approach - 1: Backtracking (Brute Force)


// #include <iostream>
// #include <vector>
// #include <string>

// using namespace std;

// class Solution {
// public:
//     bool isSafe(vector<string> &board, int row, int col, int n) {
//         // Horizontal check (Actually redundant if we place one queen per row)
//         for(int i = 0; i < n; i++) {
//             if(board[row][i] == 'Q') return false;
//         }

//         // Vertical check
//         for(int i = 0; i < n; i++) {
//             if(board[i][col] == 'Q') return false;
//         }

//         // Upper Left Diagonal
//         for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
//             if(board[i][j] == 'Q') return false;
//         }

//         // Upper Right Diagonal
//         for(int i = row, j = col; i >= 0 && j < n; i--, j++) {
//             if(board[i][j] == 'Q') return false;
//         }

//         return true;
//     }

//     void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans) {
//         // Base Case: All queens are placed
//         if(row == n) {
//             ans.push_back(board);
//             return;
//         }

//         for(int j = 0; j < n; j++) {
//             if(isSafe(board, row, j, n)) {
//                 board[row][j] = 'Q';        // Action
//                 nQueens(board, row + 1, n, ans); // Recurse
//                 board[row][j] = '.';        // Backtrack
//             }
//         }
//     }

//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> ans;
//         vector<string> board(n, string(n, '.'));
//         nQueens(board, 0, n, ans);
//         return ans;
//     }
// };

// // Helper to print the board beautifully
// void printBoards(vector<vector<string>>& solutions) {
//     cout << "Total Solutions Found: " << solutions.size() << endl << endl;
//     for (auto& board : solutions) {
//         for (string& row : board) {
//             cout << row << endl;
//         }
//         cout << "----------" << endl;
//     }
// }

// int main() {
//     Solution sol;
    
//     int n = 4; // Standard 4x4 test case
//     cout << "Solving for N = " << n << "..." << endl;
    
//     vector<vector<string>> result = sol.solveNQueens(n);
//     printBoards(result);

//     return 0;
// }
















// Approcah - 2: Backtracking with O(1) checks using Hash Maps

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Using maps to track occupied columns and diagonals
    unordered_map<int, bool> colCheck;
    unordered_map<int, bool> LeftDigCheck;
    unordered_map<int, bool> RightDigCheck;

    void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans) {
        // Base case: All queens are placed successfully
        if(row == n) {
            ans.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++) {
            // Check if placing a Queen at (row, col) is safe using O(1) lookups
            if(!colCheck[col] && !LeftDigCheck[n - 1 + col - row] && !RightDigCheck[row + col]) {
                
                // ACTION: Place Queen and mark maps
                board[row][col] = 'Q';
                colCheck[col] = true;
                LeftDigCheck[n - 1 + col - row] = true;
                RightDigCheck[row + col] = true;

                // RECURSE: Move to the next row
                nQueens(board, row + 1, n, ans);

                // BACKTRACK: Remove Queen and UNMARK maps for other possibilities
                board[row][col] = '.';
                colCheck[col] = false;
                LeftDigCheck[n - 1 + col - row] = false;
                RightDigCheck[row + col] = false;
            }
        }
    }
        
    vector<vector<string>> solveNQueens(int n) {
        // Reset maps in case the function is called multiple times
        colCheck.clear();
        LeftDigCheck.clear();
        RightDigCheck.clear();

        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        nQueens(board, 0, n, ans);
        return ans;
    }
};

// --- Main Function to provide input ---
int main() {
    Solution sol;
    
    // Change this value to test different board sizes (e.g., 4, 8)
    int n = 4; 
    
    vector<vector<string>> result = sol.solveNQueens(n);

    cout << "Total Solutions for N = " << n << ": " << result.size() << endl << endl;

    // Printing the boards
    for (int i = 0; i < result.size(); i++) {
        cout << "Solution " << i + 1 << ":" << endl;
        for (string row : result[i]) {
            cout << row << endl;
        }
        cout << "-----------------" << endl;
    }

    return 0;
}