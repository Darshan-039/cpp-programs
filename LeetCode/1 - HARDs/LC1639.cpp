// Leetcode 1639. Number of Ways to Form a Target String Given a Dictionary







// Approach - 1 Recursion + Memoization (Top-Down DP)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m;  // Length of target
    int k;  // Length of each word (same for all words)

    const int MOD = 1e9 + 7;

    // DP table
    // t[i][j] = number of ways to form target[i..] using columns j..
    int t[1001][1001];

    int solve(int i, int j, vector<vector<long long>> &freq, string &target) {

        // If entire target is formed
        if(i == m) return 1;

        // If columns finished but target still left
        if(j == k) return 0;

        // If already computed
        if(t[i][j] != -1) return t[i][j];

        // Option 1: skip this column
        int not_taken = solve(i, j+1, freq, target) % MOD;

        // Option 2: use this column
        // Multiply by frequency of target character in this column
        long long taken = (freq[target[i] - 'a'][j] *
                           solve(i+1, j+1, freq, target)) % MOD;

        // Store result
        return t[i][j] = (taken + not_taken) % MOD;
    }

    int numWays(vector<string>& words, string target) {

        m = target.length();
        k = words[0].length();

        memset(t, -1, sizeof(t));

        // freq[char][column]
        // How many words contain char at that column
        vector<vector<long long>> freq(26, vector<long long>(k, 0));

        for(int col = 0; col < k; col++) {
            for(string &word : words) {
                char ch = word[col];
                freq[ch - 'a'][col]++;
            }
        }

        return solve(0, 0, freq, target);
    }
};


int main() {

    int n;
    cout << "Enter number of words: ";
    cin >> n;

    vector<string> words(n);

    cout << "Enter words:\n";
    for(int i = 0; i < n; i++) {
        cin >> words[i];
    }

    string target;
    cout << "Enter target string: ";
    cin >> target;

    Solution obj;

    int result = obj.numWays(words, target);

    cout << "Number of ways to form target: " << result << endl;

    return 0;
}










// Approach - 2 Tabulation (Bottom-Up DP)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    int numWays(vector<string>& words, string target) {

        int m = target.length();        // length of target string
        int k = words[0].length();      // length of each word

        // freq[c][j] = how many words have character c at column j
        vector<vector<long long>> freq(26, vector<long long>(k, 0));

        // Build frequency table
        for(int col = 0; col < k; col++) {
            for(string &word : words) {
                char ch = word[col];
                freq[ch - 'a'][col]++;
            }
        }

        // DP table
        // t[i][j] = number of ways to build first i characters of target
        // using first j columns
        vector<vector<int>> t(m+1, vector<int>(k+1, 0));

        // Base case
        // 1 way to form empty target using 0 columns
        t[0][0] = 1;

        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= k; j++) {

                // Option 1: Skip this column
                if(j < k)
                    t[i][j+1] = (t[i][j+1] + t[i][j]) % MOD;

                // Option 2: Take this column if it matches target
                if(i < m && j < k)
                    t[i+1][j+1] =
                        (t[i+1][j+1] +
                        (long long)t[i][j] * freq[target[i] - 'a'][j]) % MOD;
            }
        }

        // Final answer
        return t[m][k];
    }
};


int main() {

    int n;
    cout << "Enter number of words: ";
    cin >> n;

    vector<string> words(n);

    cout << "Enter words:\n";
    for(int i = 0; i < n; i++) {
        cin >> words[i];
    }

    string target;
    cout << "Enter target string: ";
    cin >> target;

    Solution obj;

    int result = obj.numWays(words, target);

    cout << "Number of ways to form target: " << result << endl;

    return 0;
}