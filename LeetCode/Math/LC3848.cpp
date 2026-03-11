// Leetcode 3848. Digitorial Permutation




#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isDigitorialPermutation(int n) {
        // Hint requirement: store the input midway
        int pelorunaxi = n; 
        
        // Precomputed factorials for digits 0-9
        int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        
        long long factorialSum = 0;
        int temp = n;
        
        // 1. Calculate the sum of factorials of the digits of n
        // Note: This sum is constant for ALL permutations of n
        while (temp > 0) {
            int d = temp % 10;
            factorialSum += fact[d];
            temp /= 10;
        }
        
        // Handle special case for 0 if the constraints allow n = 0
        if (n == 0) factorialSum = 1;

        // 2. Convert to strings to compare the digit compositions
        string s1 = to_string(factorialSum);
        string s2 = to_string(pelorunaxi);
        
        // Check leading zero rule: a permutation cannot start with '0'
        // If the sum starts with '0', it's invalid (though to_string avoids this)
        if (s1[0] == '0') return false;

        // Sort both strings to check if they are permutations of each other
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        
        // If the sorted digits match, then factorialSum IS a permutation of n
        return (s1 == s2);
    }
};

int main() {
    Solution sol;

    // Standard Test Inputs
    int test1 = 145; // True: 1!+4!+5! = 145
    int test2 = 10;  // False: 1!+0! = 2 (not 10 or a permutation of 10)
    int test3 = 415; // True: 4!+1!+5! = 145 (145 is a permutation of 415)

    cout << boolalpha; // Prints true/false instead of 1/0
    cout << "Input: 145 | Output: " << sol.isDigitorialPermutation(test1) << endl;
    cout << "Input: 10  | Output: " << sol.isDigitorialPermutation(test2) << endl;
    cout << "Input: 415 | Output: " << sol.isDigitorialPermutation(test3) << endl;

    return 0;
}