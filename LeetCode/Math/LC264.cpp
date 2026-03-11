// Leetcode 264. Ugly Number II



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        // STEP 1: Initialize a DP array to store found ugly numbers.
        // ans[i] will store the i-th ugly number.
        vector<int> ans(n + 1);
        ans[1] = 1; // The first ugly number is always 1 by definition.

        // STEP 2: Initialize pointers for prime factors 2, 3, and 5.
        // These pointers track which previously found ugly number 
        // should be multiplied by 2, 3, or 5 next.
        int i2 = 1;
        int i3 = 1;
        int i5 = 1;

        // STEP 3: Iterate from the 2nd to the n-th ugly number.
        for(int i = 2; i <= n; i++) {
            // Calculate potential next ugly numbers by multiplying 
            // the pointed-to values by their respective factors.
            int i2UglyNum = ans[i2] * 2;
            int i3UglyNum = ans[i3] * 3;
            int i5UglyNum = ans[i5] * 5;

            // STEP 4: Choose the smallest among the potential candidates.
            // This ensures the ugly numbers are generated in ascending order.
            int minUglyNum = min({i2UglyNum, i3UglyNum, i5UglyNum});

            // Store the next smallest ugly number in the DP array.
            ans[i] = minUglyNum;

            // STEP 5: Increment pointers for the factor(s) that produced the minimum value.
            // We use 'if' instead of 'else if' to skip duplicate values 
            // (e.g., 2*3 = 6 and 3*2 = 6).
            if(i2UglyNum == minUglyNum) i2++;
            if(i3UglyNum == minUglyNum) i3++;
            if(i5UglyNum == minUglyNum) i5++;
        }

        // Return the n-th ugly number calculated.
        return ans[n];
    }
};

int main() {
    Solution sol;
    
    // Test Input: Find the 10th ugly number.
    int n = 10; 
    
    // The sequence is: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12...
    int result = sol.nthUglyNumber(n);
    
    cout << "The " << n << "-th ugly number is: " << result << endl;

    return 0;
}