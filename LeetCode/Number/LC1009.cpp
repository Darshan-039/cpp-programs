// LeetCode Problem 1009: Complement of Base 10 Integer



#include <iostream>

using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        // Edge case: if n is 0, its binary is "0", so complement is "1"
        if (n == 0) return 1;

        int m = n;
        int mask = 0;

        // Create a mask of 1s (e.g., if n=5 (101), mask becomes 7 (111))
        while(m != 0) {
            mask = (mask << 1) | 1;
            m = m >> 1;
        }

        // ~n flips all bits (including leading 0s in the 32-bit int)
        // & mask keeps only the bits that were part of the original number
        int ans = (~n) & mask;
        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1: n = 5
    // Binary: 101, Complement: 010 (Decimal 2)
    int n1 = 5;
    cout << "Input: " << n1 << " -> Complement: " << sol.bitwiseComplement(n1) << endl;

    // Test Case 2: n = 7
    // Binary: 111, Complement: 000 (Decimal 0)
    int n2 = 7;
    cout << "Input: " << n2 << " -> Complement: " << sol.bitwiseComplement(n2) << endl;

    // Test Case 3: n = 10
    // Binary: 1010, Complement: 0101 (Decimal 5)
    int n3 = 10;
    cout << "Input: " << n3 << " -> Complement: " << sol.bitwiseComplement(n3) << endl;

    return 0;
}