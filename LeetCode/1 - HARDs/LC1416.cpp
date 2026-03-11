// Leetcode 1416. Restore The Array



// Approach - 1 (R + M)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;                          // length of string
    const int MOD = 1e9 + 7;        // modulo value

    // Recursive DP function
    int solve(int i, string &s, int &k, vector<int> &t) {

        // If we reached the end of string,
        // we found one valid way
        if(i == n) return 1;

        // Numbers cannot start with '0'
        if(s[i] == '0') return 0;

        // If already computed, return stored result
        if(t[i] != -1) return t[i];

        long long num = 0;          // to build number digit by digit
        long long ways = 0;         // number of ways from index i

        // Try forming numbers starting from index i
        for(int j = i; j < n; j++) {

            // Build number s[i..j]
            num = (num * 10) + (s[j] - '0');

            // If number exceeds k, stop further expansion
            if(num > k) break;

            // Add number of ways from next position
            ways = (ways + solve(j + 1, s, k, t)) % MOD;
        }

        // Store result in DP table
        return t[i] = ways;
    }

    int numberOfArrays(string s, int k) {

        n = s.length();

        // DP array initialized with -1
        vector<int> t(n, -1);

        // Start recursion from index 0
        return solve(0, s, k, t);
    }
};

int main() {

    string s;
    int k;

    // Input
    cout << "Enter string: ";
    cin >> s;

    cout << "Enter k: ";
    cin >> k;

    Solution obj;

    // Call function
    int result = obj.numberOfArrays(s, k);

    cout << "Number of ways: " << result << endl;

    return 0;
}







// Approach - 2 (T)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArrays(string s, int k) {

        int n = s.length();                 // Length of the string
        const int MOD = 1e9 + 7;            // Mod value for large numbers

        // dp[i] = number of ways to split substring starting from index i
        vector<long long> dp(n + 1, 0);

        // Base case:
        // If we reach the end of string, there is 1 valid way
        dp[n] = 1;

        // Traverse from right → left (Bottom-Up DP)
        for(int i = n - 1; i >= 0; i--) {

            // Numbers cannot start with '0'
            if(s[i] == '0') continue;

            long long num = 0;

            // Try forming numbers starting from index i
            for(int j = i; j < n; j++) {

                // Build number s[i..j]
                num = num * 10 + (s[j] - '0');

                // If number exceeds k, stop further expansion
                if(num > k) break;

                // Add number of ways from the next index
                dp[i] = (dp[i] + dp[j + 1]) % MOD;
            }
        }

        // Final answer: number of ways starting from index 0
        return dp[0];
    }
};

int main() {

    string s;
    int k;

    // Taking input from user
    cout << "Enter numeric string: ";
    cin >> s;

    cout << "Enter value of k: ";
    cin >> k;

    Solution obj;

    // Call function
    int result = obj.numberOfArrays(s, k);

    // Output result
    cout << "Number of possible arrays: " << result << endl;

    return 0;
}