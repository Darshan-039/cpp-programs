// Leetcode 1411. Number of Ways to Paint N × 3 Grid



#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // Define the modulo constant to prevent integer overflow
    int M = 1e9 + 7;
    
    vector<vector<int>> t;

    string states[12] = {"RYG", "RGY", "RYR", "RGR", "YRG", "YGR", "YGY", "YRY", "GRY", "GYR", "GRG", "GYG"};

    int solve(int n, int prev) {
        // Base Case: If no more rows are left to paint, we found 1 valid way.
        if(n == 0) return 1;

        if(t[n][prev] != -1) return t[n][prev];

        int result = 0;
        string last = states[prev];

        // Try all 12 possible patterns for the current row
        for(int curr = 0; curr < 12; curr++) {
            if(curr == prev) continue;

            string currPat = states[curr];
            bool conflict = false;

            // Check for vertical conflicts:
            // No cell can have the same color as the cell directly above it.
            for(int col = 0; col < 3; col++) {
                if(currPat[col] == last[col]) {
                    conflict = true;
                    break;
                }
            }

            // If the pattern is compatible with the row above, recurse for the next row.
            if(!conflict) {
                result = (result + solve(n-1, curr)) % M;
            }
        }

        return t[n][prev] = result;
    }

    int numOfWays(int n) {
        t.resize(n, vector<int>(12, -1));
        int result = 0;

        // Start the process by choosing each of the 12 patterns for the very first row.
        for(int i = 0; i<12; i++) { 
            // After picking the first row (i), we solve for the remaining (n-1) rows.
            result = (result + solve(n-1, i)) % M;
        }

        return result;
    }    
};

int main() {
    Solution sol;
    
    // Example Input: Number of rows in the grid
    int n;
    cout << "Enter the number of rows (n): ";
    if (!(cin >> n)) {
        n = 3; // Default fallback for demonstration
        cout << n << endl;
    }

    int result = sol.numOfWays(n);

    cout << "Total number of ways to paint a " << n << "x3 grid: " << result << endl;

    return 0;
}