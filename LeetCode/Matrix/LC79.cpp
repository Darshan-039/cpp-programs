// Leetcode 79. Word Search



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m, k;

    // 🔹 DFS function to search word in grid
    bool solve(vector<vector<char>>& board, int i, int j, string &word, int index, vector<vector<bool>>& visited) {
        
        // ✅ If all characters matched
        if(index == k) return true;

        // ❌ Invalid cases: out of bounds / already visited / mismatch
        if(i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || board[i][j] != word[index]) {
            return false;
        }

        // Mark current cell as visited
        visited[i][j] = true;

        // 🔍 Explore all 4 directions
        bool found = solve(board, i, j+1, word, index+1, visited) ||  // right
                     solve(board, i, j-1, word, index+1, visited) ||  // left
                     solve(board, i+1, j, word, index+1, visited) ||  // down
                     solve(board, i-1, j, word, index+1, visited);    // up

        // 🔁 Backtrack (unmark visited)
        visited[i][j] = false;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        k = word.length();

        // Track visited cells
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Try starting from each cell
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                // Start DFS only if first character matches
                if(board[i][j] == word[0]) {
                    if(solve(board, i, j, word, 0, visited)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};


// 🔥 MAIN FUNCTION (Sample Input)
int main() {
    Solution obj;

    // Example board
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word = "ABCCED";

    bool ans = obj.exist(board, word);

    if(ans) cout << "Word exists in board\n";
    else cout << "Word does NOT exist in board\n";

    return 0;
}