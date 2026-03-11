#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * Finds the maximum possible XOR result by rearranging the bits of string 't'.
     * The strategy is greedy: prioritize placing a '1' at the most significant positions.
     */
    string maximumXor(string s, string t) {
        int n = s.length();

        // 1. Count the available 0s and 1s in string 't'
        vector<int> count(2, 0);
        for(char ch : t) count[ch - '0']++;

        string result = "";

        // 2. Iterate through 's' and try to pick the bit from 't' that results in '1'
        for(int i = 0; i < n; i++) {
            int ch = s[i] - '0';

            // To get a '1' after XOR, we need the opposite bit
            int reqCh = (ch == 0) ? 1 : 0;

            if(count[reqCh] > 0) {
                // If the bit we need is available, use it to get a '1'
                count[reqCh]--;
                result += "1";
            }
            else {
                // Otherwise, we are forced to use the same bit, resulting in '0'
                count[ch]--;
                result += "0";
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    // s = "101", t = "011"
    // To maximize XOR: 
    // Position 0 (s=1): Need 0. Available in t? Yes. (Result: 1)
    // Position 1 (s=0): Need 1. Available in t? Yes. (Result: 1)
    // Position 2 (s=1): Need 0. Available in t? No (only 1 left). (Result: 0)
    string s1 = "101", t1 = "011";
    cout << "Input: s=\"" << s1 << "\", t=\"" << t1 << "\"" << endl;
    cout << "Maximum XOR: " << sol.maximumXor(s1, t1) << endl; // Output: 110

    // Test Case 2
    string s2 = "111", t2 = "000";
    cout << "\nInput: s=\"" << s2 << "\", t=\"" << t2 << "\"" << endl;
    cout << "Maximum XOR: " << sol.maximumXor(s2, t2) << endl; // Output: 111

    return 0;
}