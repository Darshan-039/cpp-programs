#include <bits/stdc++.h> 
using namespace std;

#define MOD 1000000007

// Function to add two numbers under modulo
int add(int a, int b) {
    return (a%MOD + b%MOD) % MOD;
}

// Function to multiply two numbers under modulo
int mul(int a, int b) {
    return ((a%MOD) * 1LL * (b%MOD)) % MOD;
}

// -------------------- RECURSION + MEMOIZATION --------------------
// Returns number of ways to paint n fences with k colors
int solve(int n, int k, vector<int> &dp) {

    // Base case: 1 fence -> k choices
    if(n == 1) return k;

    // Base case: 2 fences
    // same color (k ways) + different colors (k*(k-1))
    if(n == 2) return add(k, mul(k, k-1));

    // If already calculated, return stored value
    if(dp[n] != -1) return dp[n];

    // Recurrence relation
    // dp[i] = (dp[i-2] * (k-1)) + (dp[i-1] * (k-1))
    dp[n] = add( mul(solve(n-2, k, dp), k-1),
                 mul(solve(n-1, k, dp), k-1) );

    return dp[n];
}

// -------------------- TABULATION (BOTTOM-UP DP) --------------------
int Tabulation(int n, int k) {

    vector<int> dp(n+1, 0);

    // Base cases
    dp[1] = k;
    dp[2] = add(k, mul(k, k-1));

    // Fill DP table
    for(int i = 3; i<=n; i++) {
        dp[i] = add( mul(dp[i-2], k-1),
                     mul(dp[i-1], k-1) );
    }

    return dp[n];
}

// -------------------- SPACE OPTIMIZED DP --------------------
int spaceOptimization(int n, int k) {

    // prev2 = dp[i-2], prev1 = dp[i-1]
    int prev2 = k;
    int prev1 = add(k, mul(k, k-1));

    for(int i = 3; i<=n; i++) {

        int ans = add( mul(prev2, k-1),
                       mul(prev1, k-1) );

        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

// Main function used by the problem
int numberOfWays(int n, int k) {

    // Uncomment to use recursion + memoization
    // vector<int> dp(n+1, -1);
    // return solve(n, k, dp);

    // Uncomment to use tabulation
    // return Tabulation(n, k);

    // Using space optimized DP
    return spaceOptimization(n, k);
}

// -------------------- MAIN FUNCTION --------------------
int main() {

    int T;
    cin >> T;   // Number of test cases

    while(T--) {

        int n, k;
        cin >> n >> k;   // Number of posts and colors

        cout << numberOfWays(n, k) << endl;
    }

    return 0;
}