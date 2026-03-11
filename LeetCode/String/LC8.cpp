// Leetcode 8: String to Integer (atoi)



#include <iostream>
#include <string>
#include <climits> // Required for INT_MAX and INT_MIN

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();

        // 1. Skip all leading whitespace characters
        while(i < n && s[i] == ' ') i++;
        if(i == n) return 0;

        // 2. Determine the sign of the number
        bool isNegative = false;
        if(s[i] == '-') {
            isNegative = true;
            i++;
        }
        else if (s[i] == '+') {
            i++;
        }

        int value = 0;
        int maxLimit = INT_MAX / 10;
        int minLimit = INT_MIN / 10;

        // 3. Process each digit
        while(i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            if (!isNegative) {
                // Positive Overflow Check
                if(value > maxLimit || (value == maxLimit && digit > 7)) return INT_MAX;
                value = value * 10 + digit;
            } else {
                // Negative Overflow Check
                if(value < minLimit || (value == minLimit && digit > 8)) return INT_MIN;
                value = value * 10 - digit;
            }
            i++;
        }

        return value;
    }
};

// --- Main Function to provide input ---
int main() {
    Solution sol;

    // Array of test cases
    string testCases[] = {
        "42",                // Simple positive
        "   -42",            // Leading spaces and negative
        "4193 with words",   // Digits followed by words
        "words and 987",     // Words followed by digits (should be 0)
        "-91283472332",      // Negative Overflow
        "2147483648",        // Positive Overflow
        "  +  42",           // Invalid sign/space combo (should be 0)
        "00000-42a123"       // Leading zeros then sign (should be 0)
    };

    cout << "--- LeetCode 8: String to Integer (atoi) ---" << endl << endl;

    for (const string& test : testCases) {
        int result = sol.myAtoi(test);
        cout << "Input:  \"" << test << "\"" << endl;
        cout << "Output: " << result << endl;
        cout << "-----------------------------------" << endl;
    }

    return 0;
}