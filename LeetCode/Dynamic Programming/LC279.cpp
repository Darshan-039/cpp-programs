// Leetcode 279. Perfect Squares



#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

class Solution {
public: 
    // Array to store results of subproblems (Memoization table)
    int arr[10001];

    int solve(int n) {
        // Base case: If n is 0, we need 0 squares
        if(n == 0) return 0;

        // If we have already calculated the result for n, return it
        if(arr[n] != -1) return arr[n];

        int minCount = INT_MAX;

        // Try every perfect square i*i that is less than or equal to n
        for(int i = 1; i*i <= n; i++) {
            // Recurse for the remaining value (n - i*i)
            int result = 1 + solve(n - i*i);

            // Keep track of the minimum count found
            minCount = min(minCount, result);
        }

        // Store the result in the memoization table before returning
        return arr[n] = minCount;
    }

    int numSquares(int n) {
        // Initialize the memoization table with -1
        memset(arr, -1, sizeof(arr));
        return solve(n);
    }
};

int main() {
    Solution sol;

    // Sample Input 1: n = 12
    // 12 = 4 + 4 + 4 (3 squares)
    int n1 = 12;
    cout << "Input: " << n1 << " -> Output: " << sol.numSquares(n1) << endl;

    // Sample Input 2: n = 13
    // 13 = 4 + 9 (2 squares)
    int n2 = 13;
    cout << "Input: " << n2 << " -> Output: " << sol.numSquares(n2) << endl;

    return 0;
}