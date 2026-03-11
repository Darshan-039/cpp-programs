// Leetcode  13: Roman to Integer



#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // Helper function for O(1) character lookup
    int getValue(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }

    int romanToInt(string s) {
        int ans = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            int currentVal = getValue(s[i]);
            
            // Look ahead: if next value is larger, subtract current instead of adding
            if (i + 1 < n && currentVal < getValue(s[i + 1])) {
                ans -= currentVal;
            } else {
                ans += currentVal;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string inputStr;

    cout << "Enter a Roman Numeral (e.g., MCMXCIV): ";
    cin >> inputStr;

    // Optional: Convert input to uppercase if needed
    for (auto &c : inputStr) c = toupper(c);

    int result = sol.romanToInt(inputStr);
    cout << "Integer Value: " << result << endl;

    return 0;
}