// Leetcode 1312. Minimum Insertion Steps to Make a String Palindrome




// Approach 1: Recursion + Memoization (Top-Down DP)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // DP table for memoization
    // t[i][j] stores the minimum insertions needed
    // to make substring s[i..j] a palindrome
    int t[501][501];

    int solve(int i, int j, string &s) {

        // Length of current substring
        int n = j - i + 1;

        // If only one character, it is already a palindrome
        if(n == 1) return 0;

        // If two characters
        if(n == 2) {
            // If both characters same → already palindrome
            if(s[i] == s[j]) return 0;
            // Otherwise insert one character
            else return 1;
        }

        // If already computed, return stored result
        if(t[i][j] != -1) return t[i][j];

        // If first and last characters match
        // move inside the substring
        if(s[i] == s[j]) 
            return t[i][j] = solve(i+1, j-1, s);

        // Case 1: insert character matching s[i]
        int first_last = solve(i+1, j, s);

        // Case 2: insert character matching s[j]
        int last_first = solve(i, j-1, s);

        // Take minimum insertions
        return t[i][j] = min(first_last, last_first) + 1;
    }

    int minInsertions(string s) {

        // Initialize DP table with -1
        memset(t, -1, sizeof(t));

        int n = s.length();

        // Solve for entire string
        return solve(0, n-1, s);
    }
};


int main() {

    string s;

    // Input string
    cin >> s;

    Solution obj;

    // Output minimum insertions required
    cout << obj.minInsertions(s) << endl;

    return 0;
}







// Approach 2: Tabulation (Bottom-Up DP)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int minInsertions(string s) {

        int n = s.length();

        // DP table
        // dp[i][j] = minimum insertions required to make substring s[i..j] a palindrome
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // len = length of substring
        for(int len = 2; len <= n; len++) {

            // i = starting index of substring
            for(int i = 0; i + len - 1 < n; i++) {

                // j = ending index of substring
                int j = i + len - 1;

                // If substring length = 2
                if(len == 2) {
                    if(s[i] == s[j]) 
                        dp[i][j] = 0;   // already palindrome
                    else 
                        dp[i][j] = 1;   // one insertion needed
                }

                // If first and last characters match
                else if(s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1];
                }

                // If characters don't match
                else {
                    int first_last = dp[i+1][j];   // insert near i
                    int last_first = dp[i][j-1];   // insert near j

                    dp[i][j] = min(first_last, last_first) + 1;
                }
            }
        }

        // Result for entire string
        return dp[0][n-1];
    }
};


int main() {

    string s;

    // Take input string
    cin >> s;

    Solution obj;

    // Print minimum insertions needed
    cout << obj.minInsertions(s) << endl;

    return 0;
}