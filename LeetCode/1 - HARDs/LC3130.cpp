// Leetcode 3130. Find All Possible Stable Binary Arrays II



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int M = 1e9 + 7;

    int numberOfStableArrays(int zero, int one, int limit) {

        // t[i][j][0] -> number of arrays using i zeros and j ones ending with 0
        // t[i][j][1] -> number of arrays using i zeros and j ones ending with 1
        vector<vector<vector<int>>> t(zero + 1, vector<vector<int>>(one + 1, vector<int>(2, 0)));

        // Base case:
        // If only zeros are used (no ones)
        // Valid only if zeros count <= limit
        for (int i = 0; i <= min(zero, limit); i++) {
            t[i][0][0] = 1;   // array ends with 0
        }

        // Base case:
        // If only ones are used (no zeros)
        // Valid only if ones count <= limit
        for (int j = 0; j <= min(one, limit); j++) {
            t[0][j][1] = 1;   // array ends with 1
        }

        // Fill DP table
        for (int i = 0; i <= zero; i++) {
            for (int j = 0; j <= one; j++) {

                // Skip already initialized base cases
                if (i == 0 || j == 0) continue;

                // Case 1: Current element is 1
                // We append 1 after sequences ending with 0 or 1
                t[i][j][1] = (t[i][j - 1][1] + t[i][j - 1][0]) % M;

                // Remove sequences that exceed the limit of consecutive 1s
                if (j - 1 >= limit) {
                    t[i][j][1] = (t[i][j][1] - t[i][j - 1 - limit][0] + M) % M;
                }

                // Case 2: Current element is 0
                // We append 0 after sequences ending with 0 or 1
                t[i][j][0] = (t[i - 1][j][0] + t[i - 1][j][1]) % M;

                // Remove sequences that exceed the limit of consecutive 0s
                if (i - 1 >= limit) {
                    t[i][j][0] = (t[i][j][0] - t[i - 1 - limit][j][1] + M) % M;
                }
            }
        }

        // Total valid arrays = ending with 0 + ending with 1
        return (t[zero][one][0] + t[zero][one][1]) % M;
    }
};

int main() {

    int zero, one, limit;

    // Take input
    cout << "Enter number of zeros: ";
    cin >> zero;

    cout << "Enter number of ones: ";
    cin >> one;

    cout << "Enter limit: ";
    cin >> limit;

    Solution obj;
    int result = obj.numberOfStableArrays(zero, one, limit);

    cout << "Number of Stable Arrays = " << result << endl;

    return 0;
}