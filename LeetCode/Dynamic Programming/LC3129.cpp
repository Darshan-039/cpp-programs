// Leetcode 3129. Find All Possible Stable Binary Arrays I





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    const int M = 1e9 + 7;

    // DP table
    // t[z][o][last]
    // z = zeros remaining
    // o = ones remaining
    // last = last placed block type (1 = last was one, 0 = last was zero)
    long long t[201][201][2];

    // Recursive function with memoization
    long long solve(int zeroLeft, int oneLeft, bool lastWasOne, int limit) {

        // Base case: if no zeros and ones left → valid array formed
        if(zeroLeft == 0 && oneLeft == 0) 
            return 1;

        // If state already computed, return memoized result
        if(t[zeroLeft][oneLeft][lastWasOne] != -1)
            return t[zeroLeft][oneLeft][lastWasOne];

        long long result = 0;

        if(lastWasOne) {
            // Last block was 1 → now we must place a block of 0s

            // Try placing 1..limit zeros
            for(int length = 1; length <= min(zeroLeft, limit); length++) {

                // After placing zeros, last becomes zero
                result = (result + solve(zeroLeft - length, oneLeft, false, limit)) % M;
            }
        }
        else {
            // Last block was 0 → now we must place a block of 1s

            // Try placing 1..limit ones
            for(int length = 1; length <= min(oneLeft, limit); length++) {

                // After placing ones, last becomes one
                result = (result + solve(zeroLeft, oneLeft - length, true, limit)) % M;
            }
        }

        // Store result in DP table
        return t[zeroLeft][oneLeft][lastWasOne] = result;
    }

    int numberOfStableArrays(int zero, int one, int limit) {

        // Initialize DP table with -1
        memset(t, -1, sizeof(t));

        // Case 1: first block is zeros
        long long startWithZero = solve(zero, one, true, limit);

        // Case 2: first block is ones
        long long startWithOne  = solve(zero, one, false, limit);

        return (startWithZero + startWithOne) % M;
    }
};


int main() {

    int zero, one, limit;

    // Input
    cout << "Enter number of zeros: ";
    cin >> zero;

    cout << "Enter number of ones: ";
    cin >> one;

    cout << "Enter limit: ";
    cin >> limit;

    Solution obj;

    int ans = obj.numberOfStableArrays(zero, one, limit);

    cout << "Number of stable arrays = " << ans << endl;

    return 0;
}










// Approach - 2 Tabulation

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    const int M = 1e9 + 7;

    // DP table
    // t[z][o][0] → number of arrays with z zeros and o ones ending with 0
    // t[z][o][1] → number of arrays with z zeros and o ones ending with 1
    long long t[201][201][2];

    int numberOfStableArrays(int zero, int one, int limit) {

        // Initialize DP table
        memset(t, 0, sizeof(t));

        // Base case: empty array
        t[0][0][0] = 1;
        t[0][0][1] = 1;

        // Build DP table
        for(int zeroLeft = 0; zeroLeft <= zero; zeroLeft++) {
            for(int onesLeft = 0; onesLeft <= one; onesLeft++) {

                // Skip base case
                if(zeroLeft == 0 && onesLeft == 0) continue;

                int result = 0;

                // Case 1: Array ends with 1
                // So previously we placed zeros
                for(int len = 1; len <= min(limit, zeroLeft); len++) {

                    // Take previous states ending with 0
                    result = (result + t[zeroLeft - len][onesLeft][0]) % M;
                }

                t[zeroLeft][onesLeft][1] = result;


                // Case 2: Array ends with 0
                // So previously we placed ones
                result = 0;

                for(int len = 1; len <= min(limit, onesLeft); len++) {

                    // Take previous states ending with 1
                    result = (result + t[zeroLeft][onesLeft - len][1]) % M;
                }

                t[zeroLeft][onesLeft][0] = result;
            }
        }

        // Final answer = arrays ending with 0 + arrays ending with 1
        return (t[zero][one][0] + t[zero][one][1]) % M;
    }
};

int main() {

    int zero, one, limit;

    // Input from user
    cout << "Enter number of zeros: ";
    cin >> zero;

    cout << "Enter number of ones: ";
    cin >> one;

    cout << "Enter limit: ";
    cin >> limit;

    Solution obj;

    int ans = obj.numberOfStableArrays(zero, one, limit);

    cout << "Number of Stable Arrays = " << ans << endl;

    return 0;
}