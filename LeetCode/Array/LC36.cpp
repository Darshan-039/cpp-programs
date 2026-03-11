// Valid sudoku

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<unordered_set<char>> rows(9), cols(9), boxes(9);

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {

                char ch = board[r][c];
                if (ch == '.') continue;

                int boxIndex = (r / 3) * 3 + (c / 3);

                if (rows[r].count(ch) || cols[c].count(ch) || boxes[boxIndex].count(ch))
                    return false;

                rows[r].insert(ch);
                cols[c].insert(ch);
                boxes[boxIndex].insert(ch);
            }
        }

        return true;
    }
};

int main() {

    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution s;
    bool result = s.isValidSudoku(board);

    cout << (result ? "Valid Sudoku" : "Invalid Sudoku") << endl;

    return 0;
}
