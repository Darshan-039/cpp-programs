// Leetcode 29. Divide Two Integers



#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Base case: If they are the same, result is 1
        if(dividend == divisor) return 1;
        
        // Determine the sign of the result (true = +, false = -)
        // A simple way is: bool sign = (dividend < 0) == (divisor < 0);
        bool sign = true;
        if(dividend >= 0 && divisor < 0) sign = false;
        else if(dividend < 0 && divisor > 0) sign = false;

        // labs() handles the absolute value of long to avoid INT_MIN overflow
        long n = labs(dividend);
        long d = labs(divisor);
        
        long quotient = 0;

        // Main logic: Subtracting powers of 2 of the divisor
        while(n >= d) {
            int cnt = 0;
            
            // Find the highest power of 2 such that (divisor * 2^(cnt+1)) <= dividend
            while(n >= (d << (cnt + 1))) {
                cnt++;
            }

            // Add 2^cnt to the total quotient
            quotient += (1L << cnt); 
            
            // Remove that chunk from the dividend and repeat
            n -= (d << cnt);
        }

        // --- Overflow Handling for 32-bit Integers ---
        // result > 2147483647
        if(quotient == (1L << 31) && sign) return INT_MAX;

        // result is exactly -2147483648
        if(quotient == (1L << 31) && !sign) return INT_MIN;

        return sign ? (int)quotient : (int)-quotient;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard division
    int a1 = 10, b1 = 3;
    cout << "Input: " << a1 << ", " << b1 << " | Output: " << sol.divide(a1, b1) << endl;

    // Test Case 2: Negative result
    int a2 = 7, b2 = -3;
    cout << "Input: " << a2 << ", " << b2 << " | Output: " << sol.divide(a2, b2) << endl;

    // Test Case 3: Overflow Case (INT_MIN / -1)
    int a3 = INT_MIN, b3 = -1;
    cout << "Input: INT_MIN, -1 | Output: " << sol.divide(a3, b3) << " (Should be INT_MAX)" << endl;

    // Test Case 4: Dividend is smaller than divisor
    int a4 = 1, b4 = 2;
    cout << "Input: " << a4 << ", " << b4 << " | Output: " << sol.divide(a4, b4) << endl;

    return 0;
}