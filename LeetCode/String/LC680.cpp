#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // Helper function to check if a substring is a pure palindrome
    bool isPalindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                // If mismatch, try skipping either the left OR the right char
                return isPalindrome(s, left + 1, right) || 
                       isPalindrome(s, left, right - 1);
            }
            left++;
            right--;
        }

        return true;
    }
};

int main() {
    Solution sol;

    // Test cases
    vector<string> inputs = {"aba", "abca", "abcde", "teebbbet", "racecar"};

    cout << boolalpha; // Prints "true" or "false" instead of 1 or 0
    cout << "--- Valid Palindrome II Results ---" << endl;

    for (const string& test : inputs) {
        cout << "Input: \"" << test << "\" -> Result: " << sol.validPalindrome(test) << endl;
    }

    return 0;
}