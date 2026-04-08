// Leetcode 72. Edit Distance



// Approach 1 : Recursion + Memoization

// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int n, m;

//     // DP table for memoization
//     int t[501][501];

//     // Recursive function to compute edit distance
//     int solve(string &s1, string &s2, int i, int j) {
        
//         // If s1 is exhausted, insert remaining characters of s2
//         if(i == n) return m - j;

//         // If s2 is exhausted, delete remaining characters of s1
//         if(j == m) return n - i;

//         // If both strings are exhausted
//         if(i >= n && j >= m) return 0;

//         // If characters match, move both pointers
//         if(s1[i] == s2[j]) 
//             return solve(s1, s2, i+1, j+1);

//         // If already computed, return stored result
//         if(t[i][j] != -1) 
//             return t[i][j];

//         // Case 1: Insert (move j pointer)
//         int insert = solve(s1, s2, i, j+1);

//         // Case 2: Delete (move i pointer)
//         int delet = solve(s1, s2, i+1, j);

//         // Case 3: Replace (move both pointers)
//         int replace = solve(s1, s2, i+1, j+1);

//         // Take minimum of all operations and add 1
//         return t[i][j] = min({insert, delet, replace}) + 1;
//     }

//     int minDistance(string word1, string word2) {
//         // Initialize DP table with -1
//         memset(t, -1, sizeof(t));

//         n = word1.length();
//         m = word2.length();

//         return solve(word1, word2, 0, 0);
//     }
// };

// int main() {
//     Solution obj;

//     // Sample Input
//     string word1 = "horse";
//     string word2 = "ros";

//     // Call function
//     int result = obj.minDistance(word1, word2);

//     // Output result
//     cout << "Edit Distance: " << result << endl;

//     return 0;
// }








// Approach 2 : Tabulation

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        // DP table where t[i][j] = edit distance between
        // first i chars of s1 and first j chars of s2
        vector<vector<int>> t(n+1, vector<int>(m+1, 0));

        // Base case:
        // Convert s1[0...i-1] to empty string -> delete all characters
        for(int i = 0; i <= n; i++) 
            t[i][0] = i;

        // Convert empty string to s2[0...j-1] -> insert all characters
        for(int j = 0; j <= m; j++) 
            t[0][j] = j;

        // Fill DP table
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {

                // If characters match → no operation needed
                if(s1[i-1] == s2[j-1]) {
                    t[i][j] = t[i-1][j-1];
                } 
                else {
                    // 3 operations
                    int insert = t[i][j-1];     // insert
                    int delet  = t[i-1][j];     // delete
                    int replace = t[i-1][j-1];  // replace

                    // Take minimum + 1 operation
                    t[i][j] = 1 + min({insert, delet, replace});
                }
            }
        }

        // Final answer
        return t[n][m];
    }
};

int main() {
    Solution obj;

    // Sample Input
    string s1 = "horse";
    string s2 = "ros";

    int ans = obj.minDistance(s1, s2);

    cout << "Edit Distance: " << ans << endl;

    return 0;
}