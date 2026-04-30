// Approac - 1 (R + M)

#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000000007


// Space Optimization
long long SpaceOptimization(int n) {

    if(n == 1) return 0;
    if(n == 2) return 1;

    long long prev2 = 0;
    long long prev1 = 1;

    for(int i = 3; i <= n; i++) {

        long long curr =
        ((i - 1) * (prev1 + prev2) % MOD) % MOD;

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

// Tabulation
long long Tabulation(int n) {
    vector<long long int> dp(n+1, 0);
    dp[1] = 0;
    dp[2] = 1; 

    for(int i = 3; i<=n; i++) {
        dp[i] = ( (i-1) * ( (dp[i-1])%MOD + (dp[i-2])%MOD )%MOD )%MOD;
    }


    return dp[n];
}

// Recursive + memoization
long long RM(int n, vector<long long> &dp) {

    // Base cases
    if(n == 1) return 0;   // No derangement possible
    if(n == 2) return 1;   // Only one derangement: swap

    // If already computed, return stored value
    if(dp[n] != -1)
        return dp[n];

    // Derangement formula
    // D(n) = (n-1) * ( D(n-1) + D(n-2) )
    long long ans =
        ((n - 1) % MOD *
        ((RM(n - 1, dp) % MOD +
          RM(n - 2, dp) % MOD) % MOD)) % MOD;

    // Store result in dp array
    return dp[n] = ans;
}






// Function to start memoization
long long countDerangements(int n) {

    // DP array initialized with -1
    vector<long long> dp(n + 1, -1);

    return RM(n, dp);
}

int main() {

    int n;

    cout << "Enter value of n: ";
    cin >> n;

    long long result = countDerangements(n);

    cout << "Number of derangements = " << result << endl;

    return 0;
}