// Leetcode Problem 50: Pow(x, n)


#include <iostream>
#include <iomanip> // For formatting output

// class Solution {
// public:
//     double myPow(double x, int n) {
//         // Use long long to avoid overflow when n = -2147483648
//         long long N = n;
        
//         if (N < 0) {
//             x = 1 / x;
//             N = -N;
//         }
        
//         double ans = 1.0;
//         while (N > 0) {
//             // If the current bit is 1, multiply the answer by the current x
//             if (N & 1) {
//                 ans *= x;
//             }
//             // Square the base for the next bit position
//             x *= x;
//             // Shift N right to check the next bit
//             N >>= 1;
//         }
//         return ans;
//     }
// };















class Solution {
public:
    double myPow(double x, int n) {
        // Use long long to prevent overflow when negating INT_MIN
        long long N = n;
        
        // Handle negative exponents: x^(-n) = (1/x)^n
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        return fastPow(x, N);
    }

private:
    double fastPow(double x, long long n) {
        // Base case: x^0 = 1
        if (n == 0) return 1.0;
        
        // Recursive step: compute x^(n/2) once
        double half = fastPow(x, n / 2);
        
        // If n is even: result is half * half
        if (n % 2 == 0) {
            return half * half;
        } 
        // If n is odd: result is half * half * x
        else {
            return half * half * x;
        }
    }
};










int main() {
    Solution sol;

    // Test Case 1
    double x1 = 2.0;
    int n1 = 10;
    std::cout << "Input: x = " << x1 << ", n = " << n1 << std::endl;
    std::cout << "Output: " << sol.myPow(x1, n1) << std::endl << std::endl;

    // Test Case 2 (Negative Exponent)
    double x2 = 2.0;
    int n2 = -2;
    std::cout << "Input: x = " << x2 << ", n = " << n2 << std::endl;
    std::cout << "Output: " << sol.myPow(x2, n2) << std::endl << std::endl;

    // Test Case 3 (Base 1.0001)
    double x3 = 1.0001;
    int n3 = 100;
    std::cout << "Input: x = " << x3 << ", n = " << n3 << std::endl;
    std::cout << "Output: " << std::fixed << std::setprecision(5) << sol.myPow(x3, n3) << std::endl;

    return 0;
}