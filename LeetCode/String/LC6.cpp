// Leetcode Problem 6: Zigzag Conversion



#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        // If numRows is 1, the zigzag is just the string itself
        if(numRows == 1) return s;

        string ans = "";
        // The distance between the start of one 'V' shape and the next
        int jumps = (numRows - 1) * 2;

        for(int i = 0; i < numRows; i++) {
            for(int j = i; j < s.length(); j += jumps) {
                // Add the character at the current vertical column
                ans += s[j];

                // For middle rows, there is an extra character in the diagonal
                // Formula: current_index + full_jump - (2 * current_row)
                if(i > 0 && i < numRows - 1 && (j + jumps - 2 * i) < s.length()) {
                    ans += s[j + jumps - 2 * i];
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    string s1 = "PAYPALISHIRING";
    int rows1 = 3;
    cout << "Input: " << s1 << ", Rows: " << rows1 << endl;
    cout << "Output: " << sol.convert(s1, rows1) << endl; 
    // Expected: "PAHNAPLSIIGYIR"

    cout << "---------------------------" << endl;

    // Test Case 2
    string s2 = "PAYPALISHIRING";
    int rows2 = 4;
    cout << "Input: " << s2 << ", Rows: " << rows2 << endl;
    cout << "Output: " << sol.convert(s2, rows2) << endl;
    // Expected: "PINALIGYAIHRN"

    return 0;
}