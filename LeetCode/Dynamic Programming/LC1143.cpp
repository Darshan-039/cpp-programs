// Leetcode 1143. Longest Common Subsequence




// Approach 1: Recursion + Memoization
// Time Complexity: O(n*m) where n and m are the lengths of the two strings.

// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>
// #include <cstring> // For memset

// using namespace std;

// class Solution {
// public:
//     int n;
//     int m;
//     int t[1001][1001];

//     int solve(string &text1, string &text2, int i, int j) {
//         if(i >= n || j >= m) return 0;

//         if(t[i][j] != -1) return t[i][j];

//         if(text1[i] == text2[j])
//             return t[i][j] = 1 + solve(text1, text2, i+1, j+1);

//         return t[i][j] = max(solve(text1, text2, i, j+1), solve(text1, text2, i+1, j));
//     }

//     int longestCommonSubsequence(string text1, string text2) {
//         n = text1.length();
//         m = text2.length();
//         memset(t, -1, sizeof(t));

//         return solve(text1, text2, 0, 0);
//     }
// };

// int main() {
//     Solution sol;

//     // --- Input Section ---
//     string s1 = "abcde";
//     string s2 = "ace";

//     // Run the solver
//     int result = sol.longestCommonSubsequence(s1, s2);

//     // --- Output Section ---
//     cout << "String 1: " << s1 << endl;
//     cout << "String 2: " << s2 << endl;
//     cout << "Length of Longest Common Subsequence: " << result << endl;

//     return 0;
// }















// Approach - 2 : Tabulation (Bottom-Up DP)


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        // Create a 2D DP table 't' of size (n+1) x (m+1)
        // t[i][j] will store the LCS of text1[0...i-1] and text2[0...j-1]
        vector<vector<int>> t(n + 1, vector<int>(m + 1));

        // Base Case Initialization: 
        // If either string is empty (length 0), the LCS is 0.
        for (int row = 0; row <= n; row++) t[row][0] = 0;
        for (int col = 0; col <= m; col++) t[0][col] = 0;

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                // If characters match, take the diagonal value and add 1
                if (text1[i - 1] == text2[j - 1]) {
                    t[i][j] = 1 + t[i - 1][j - 1];
                } 
                // If they don't match, take the maximum of skipping 
                // one character from either text1 or text2
                else {
                    t[i][j] = max(t[i][j - 1], t[i - 1][j]);
                }
            }
        }

        // The answer is stored in the last cell of the table
        return t[n][m];
    }
};

int main() {
    Solution sol;

    // --- Hardcoded Input ---
    string text1 = "abcde";
    string text2 = "ace";

    // Call the function
    int result = sol.longestCommonSubsequence(text1, text2);

    // --- Output Results ---
    cout << "String 1: " << text1 << endl;
    cout << "String 2: " << text2 << endl;
    cout << "LCS Length: " << result << endl;

    return 0;
}