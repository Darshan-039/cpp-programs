// Leetcode 516. Longest Palindromic Subsequence







// Approach 1: Recursive with Memoization (Top-Down DP)

// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:

//     // Recursive function with memoization
//     // Returns LPS length from index i to j
//     int solve(int i, int j, string &s, vector<vector<int>> &dp) {

//         // Base Case 1:
//         // If indices cross, no valid substring
//         if(i > j) 
//             return 0;

//         // Base Case 2:
//         // Single character is always palindrome of length 1
//         if(i == j) 
//             return 1;

//         // If already computed, return stored value
//         if(dp[i][j] != -1) 
//             return dp[i][j];

//         // If characters match
//         if(s[i] == s[j]) {
//             // Include both characters
//             dp[i][j] = 2 + solve(i+1, j-1, s, dp);
//         }
//         else {
//             // If characters don't match,
//             // take maximum by excluding one character
//             dp[i][j] = max(
//                 solve(i+1, j, s, dp),   // Exclude left character
//                 solve(i, j-1, s, dp)    // Exclude right character
//             );
//         }

//         return dp[i][j];
//     }

//     int longestPalindromeSubseq(string s) {

//         int n = s.length();

//         // DP table initialized with -1
//         vector<vector<int>> dp(n, vector<int>(n, -1));

//         return solve(0, n-1, s, dp);
//     }
// };

// int main() {

//     string s;

//     cout << "Enter string: ";
//     cin >> s;

//     Solution obj;
//     int result = obj.longestPalindromeSubseq(s);

//     cout << "Length of Longest Palindromic Subsequence: " << result << endl;

//     return 0;
// }













// Approach - 2 : Tabulation (Bottom-Up DP)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {

        int n = s.length();

        // dp[i][j] = longest palindromic subsequence from i to j
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Every single character is palindrome of length 1
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        // length of substring
        for(int len = 2; len <= n; len++) {

            for(int i = 0; i <= n - len; i++) {

                int j = i + len - 1;

                if(s[i] == s[j]) {

                    if(len == 2)
                        dp[i][j] = 2;
                    else
                        dp[i][j] = 2 + dp[i+1][j-1];

                } else {

                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);

                }
            }
        }

        return dp[0][n-1];
    }
};

int main() {

    string s;
    cout << "Enter string: ";
    cin >> s;

    Solution obj;
    cout << "Longest Palindromic Subsequence length: "
         << obj.longestPalindromeSubseq(s);

    return 0;
}