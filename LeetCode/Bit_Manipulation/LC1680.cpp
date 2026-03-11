// Leetcode 1680. Concatenation of Consecutive Binary Numbers





// Approach - 1 : Bit Manipulation

// #include <iostream>
// #include <cmath>
// using namespace std;

// class Solution {
// public:

//     int M = 1e9 + 7;   // modulo

//     int concatenatedBinary(int n) {
//         long long result = 0;

//         // iterate from 1 to n
//         for(int num = 1; num <= n; num++) {

//             // number of bits in num
//             int digits = log2(num) + 1;

//             // shift result and append num
//             result = ((result << digits) % M + num) % M;
//         }

//         return result;
//     }
// };

// int main() {

//     int n;
//     cout << "Enter n: ";
//     cin >> n;

//     Solution obj;
//     int ans = obj.concatenatedBinary(n);

//     cout << "Result = " << ans << endl;

//     return 0;
// }










// Approach - 2 : Bit Manipulation (Optimized)

#include <iostream>
using namespace std;

class Solution {
public:

    int M = 1e9 + 7;   // modulo

    int concatenatedBinary(int n) {
        long long result = 0;
        int digits = 0;

        for(int num = 1; num <= n; num++) {

            // increase digit count when num is power of 2
            if((num & (num - 1)) == 0)
                digits++;

            // shift result and append num
            result = ((result << digits) % M + num) % M;
        }

        return result;
    }
};

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    Solution obj;
    int ans = obj.concatenatedBinary(n);

    cout << "Result = " << ans << endl;

    return 0;
}