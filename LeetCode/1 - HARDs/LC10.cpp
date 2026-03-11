// Leetcode Problem 10: Regular Expression Matching



#include <iostream>
#include <string>
#include <vector>
#include <cstring> // For memset

using namespace std;

class Solution {
public:
    // Using 21x21 based on typical LC constraints (s.length, p.length <= 20)
    int t[21][21];
    
    bool solve(int i, int j, string s, string p) {
        if(j == p.length()) {
            return i == s.length();
        }

        if(t[i][j] != -1) {
            return t[i][j];
        }

        bool first_ch_mathced = false;
        if(i < s.length() && (s[i] == p[j] || p[j] == '.')) {
            first_ch_mathced = true;
        }

        if(j+1 < p.length() && p[j+1] == '*') {
            // Choice 1: Don't take the character (skip the x*)
            bool not_take = solve(i, j+2, s, p);
            // Choice 2: Take the character (only if it matches)
            bool take = first_ch_mathced && solve(i+1, j, s, p);

            return t[i][j] = (not_take || take);
        }

        return t[i][j] = (first_ch_mathced && solve(i+1, j+1, s, p));
    }

    bool isMatch(string s, string p) {
        memset(t, -1, sizeof(t));
        return solve(0, 0, s, p);
    }
};

int main() {
    Solution sol;

    // Test Case Structure: {string s, string pattern p}
    struct TestCase {
        string s;
        string p;
    };

    vector<TestCase> tests = {
        {"aa", "a"},          // Expected: false
        {"aa", "a*"},         // Expected: true
        {"ab", ".*"},         // Expected: true
        {"aab", "c*a*b"},     // Expected: true (c* is skipped)
        {"mississippi", "mis*is*p*."} // Expected: false
    };

    for (const auto& test : tests) {
        bool result = sol.isMatch(test.s, test.p);
        cout << "String: \"" << test.s << "\" | Pattern: \"" << test.p << "\"" << endl;
        cout << "Result: " << (result ? "true" : "false") << endl;
        cout << "------------------------------------" << endl;
    }

    return 0;
}