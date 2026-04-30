// Leetcode 1048. Longest String Chain



// Approach - 1 Top-Down DP with Memoization

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // dp[i][prevIndex + 1]
    // i -> current index in words
    // prevIndex -> index of previously selected word (-1 means no previous word)
    int dp[1001][1001];

    // Check if s1 is a predecessor of s2
    // Condition: s2 should be formed by adding exactly one character to s1
    bool isPredecessor(string &s1, string &s2) {
        int n = s1.length(), m = s2.length();

        // Length condition must satisfy
        if (n + 1 != m) return false;

        int i = 0, j = 0;
        int diff = 0;

        // Two pointer comparison
        while (i < n && j < m) {
            if (s1[i] == s2[j]) {
                i++;
                j++;
            } else {
                diff++;
                if (diff > 1) return false;
                j++; // move only in longer string
            }
        }

        return true;
    }

    int solve(vector<string> &words, int i, int prevIndex) {
        // Base case: reached end of words
        if (i >= words.size()) return 0;

        // Return memoized result
        if (dp[i][prevIndex + 1] != -1)
            return dp[i][prevIndex + 1];

        int take = 0;

        // Option 1: Take current word if valid chain condition holds
        if (prevIndex == -1 || isPredecessor(words[prevIndex], words[i])) {
            take = 1 + solve(words, i + 1, i);
        }

        // Option 2: Skip current word
        int skip = solve(words, i + 1, prevIndex);

        // Store and return maximum
        return dp[i][prevIndex + 1] = max(take, skip);
    }

    int longestStrChain(vector<string>& words) {
        // Initialize DP table
        memset(dp, -1, sizeof(dp));

        // Sort words based on length (important for valid chain formation)
        sort(words.begin(), words.end(), [](string &a, string &b) {
            return a.length() < b.length();
        });

        // Start recursion from index 0 with no previous word
        return solve(words, 0, -1);
    }
};

int main() {
    Solution obj;

    // Sample Input
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};

    // Expected Output: 4
    // Explanation:
    // One longest chain: "a" -> "ba" -> "bda" -> "bdca"

    int result = obj.longestStrChain(words);

    cout << "Longest String Chain Length: " << result << endl;

    return 0;
}








// Approach - 2 Bottom-Up DP

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Custom comparator to sort words by length (ascending)
    static bool cmp(string &a, string &b) {
        return a.length() < b.length();
    }

    // Check if s1 is a predecessor of s2
    // s2 should be formed by adding exactly one character to s1
    bool isPredecessor(string &s1, string &s2) {
        int n = s1.length(), m = s2.length();

        // Length condition must be satisfied
        if (n + 1 != m) return false;

        int i = 0, j = 0;
        int diff = 0;

        // Two pointer comparison
        while (i < n && j < m) {
            if (s1[i] == s2[j]) {
                i++;
                j++;
            } else {
                diff++;
                if (diff > 1) return false;
                j++; // move only in longer string
            }
        }

        return true;
    }

    int longestStrChain(vector<string>& words) {
        // Step 1: Sort words based on length
        sort(words.begin(), words.end(), cmp);

        int n = words.size();

        // dp[i] -> longest chain ending at index i
        vector<int> dp(n, 1);

        int ans = 1;

        // Step 2: Build DP
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {

                // Check if words[j] can be predecessor of words[i]
                if (isPredecessor(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            // Update overall maximum chain length
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    // Sample Input
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};

    // Expected Output: 4
    // Explanation:
    // "a" -> "ba" -> "bda" -> "bdca"

    int result = obj.longestStrChain(words);

    cout << "Longest String Chain Length: " << result << endl;

    return 0;
}