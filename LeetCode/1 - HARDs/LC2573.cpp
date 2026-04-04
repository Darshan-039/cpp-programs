// Leetcode 2573. Find the String with LCP



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();

        // Step 0: Initialize result string with placeholders
        string s(n, '#');

        char ch = 'a'; // start assigning characters from 'a'

        // Step 1: Assign characters based on LCP
        for (int i = 0; i < n; i++) {

            // If current position is not assigned yet
            if (s[i] == '#') {

                // If we exceed 'z', it's not possible
                if (ch > 'z') return "";

                // Assign same character to all positions j where lcp[i][j] > 0
                for (int j = i; j < n; j++) {
                    if (lcp[i][j] > 0) {
                        s[j] = ch;
                    }
                }
                ch++; // move to next character
            }
        }

        // Step 2: Build DP table to compute LCP of generated string
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Fill DP from bottom-right to top-left
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                // If characters match
                if (s[i] == s[j]) {

                    // If at last row/column → only 1 match possible
                    if (i == n - 1 || j == n - 1)
                        dp[i][j] = 1;
                    else
                        // Extend match using next diagonal
                        dp[i][j] = dp[i + 1][j + 1] + 1;
                }
                // else dp[i][j] stays 0
            }
        }

        // Step 3: Validate if constructed string matches given LCP matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] != lcp[i][j]) return ""; // invalid case
            }
        }

        return s; // valid string
    }
};

int main() {
    Solution obj;

    // Example LCP matrix
    vector<vector<int>> lcp = {
        {3, 0, 1},
        {0, 2, 0},
        {1, 0, 1}
    };

    /*
        Expected explanation:
        lcp[i][j] = length of longest common prefix of substring starting at i and j

        One valid output string could be: "aba"
    */

    string result = obj.findTheString(lcp);

    if (result == "")
        cout << "No valid string possible" << endl;
    else
        cout << "Constructed String: " << result << endl;

    return 0;
}