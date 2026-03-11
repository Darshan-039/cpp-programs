// Leetcode 50:- Pow(x, n)






// Approach - 1 : Using Recursion

// #include <iostream>
// using namespace std;

// class Solution {
// public:
//     double myPow(double x, long long n) {
//         if (n == 0) return 1;                // Base case

//         if (n < 0) return 1 / myPow(x, -n);  // Handle negative power

//         double half = myPow(x, n / 2);       // Recursion

//         if (n % 2 == 0)
//             return half * half;              // Even exponent
//         else
//             return x * half * half;          // Odd exponent
//     }
// };

// int main() {
//     // ✅ I MADE THE INPUT MYSELF HERE
//     double x = 2.0;
//     long long n = -10;

//     Solution obj;
//     double result = obj.myPow(x, n);

//     cout << "Input: x = " << x << ", n = " << n << endl;
//     cout << "Output: " << result << endl;

//     return 0;
// }
















// Approach - 2 : Using For Loop

#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, long long n) {
        // Base case: x^0 = 1
        if (n == 0) return 1;
        
        // Handle negative power
        if (n < 0) return 1 / myPow(x, -n);

        // Recursive fast exponentiation
        double half = myPow(x, n / 2);

        if (n % 2 == 0) {
            return half * half;           // Even power
        } else {
            return x * half * half;       // Odd power
        }
    }
};

int main() {

    // ✅ I CREATED THE INPUT HERE (you can change it)
    double x = 2.5;
    long long n = 5;

    Solution obj;
    double result = obj.myPow(x, n);

    cout << "Input: x = " << x << ", n = " << n << endl;
    cout << "Output: " << result << endl;

    return 0;
}
