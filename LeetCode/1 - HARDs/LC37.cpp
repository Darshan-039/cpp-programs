// Leetcode 37. Sudoku Solver



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char dig) {
        // Horizontal & Vertical check
        for(int i = 0; i < 9; i++) {
            if(board[row][i] == dig) return false;
            if(board[i][col] == dig) return false;
        }

        // 3x3 Grid check
        int sRow = (row / 3) * 3;
        int sCol = (col / 3) * 3;

        for(int i = sRow; i < sRow + 3; i++) {
            for(int j = sCol; j < sCol + 3; j++) {
                if(board[i][j] == dig) return false;
            }
        }
        return true;
    }

    bool helper(vector<vector<char>>& board, int row, int col) {
        if(row == 9) return true;

        int nextRow = row;
        int nextCol = col + 1;
        if(nextCol == 9) {
            nextRow += 1;
            nextCol = 0;
        }

        if(board[row][col] != '.') {
            return helper(board, nextRow, nextCol);   
        }

        for(char dig = '1'; dig <= '9'; dig++) {
            if(isSafe(board, row, col, dig)) {
                board[row][col] = dig;
                if(helper(board, nextRow, nextCol)) return true;
                board[row][col] = '.'; // Backtrack
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
};

// Function to print the board nicely
void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
            if ((j + 1) % 3 == 0 && j < 8) cout << "| ";
        }
        cout << endl;
        if ((i + 1) % 3 == 0 && i < 8) cout << "---------------------" << endl;
    }
}

int main() {
    // Sample Input: Standard Sudoku Puzzle
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    Solution sol;
    cout << "Original Puzzle:" << endl;
    printBoard(board);
    
    sol.solveSudoku(board);

    cout << "\nSolved Sudoku:" << endl;
    printBoard(board);

    return 0;
}