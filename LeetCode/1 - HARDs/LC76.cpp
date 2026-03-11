// Leetcode 76: Minimum Window Substring




#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();

        if (m > n) return "";

        // Using a fixed-size array instead of unordered_map for speed
        // ASCII size 128 covers all English letters and symbols
        int mp[128] = {0};
        for (char ch : t) mp[ch]++;

        int countReq = m;
        int start_i = 0;
        int minWindowSize = INT_MAX;

        int i = 0; // Left pointer
        int j = 0; // Right pointer

        while (j < n) {
            // If the character at s[j] is needed (count > 0)
            if (mp[s[j]] > 0) {
                countReq--;
            }

            // Decrement frequency: positive means we need it, 
            // negative means we have extra of it.
            mp[s[j]]--;

            // When all characters from 't' are found in the window
            while (countReq == 0) {
                int currWindowSize = j - i + 1;

                if (minWindowSize > currWindowSize) {
                    minWindowSize = currWindowSize;
                    start_i = i;
                }

                // Try to shrink from the left
                mp[s[i]]++;

                // If mp[s[i]] > 0, we just removed a character that was 
                // essential to satisfying the string 't'
                if (mp[s[i]] > 0) {
                    countReq++;
                }

                i++;
            }
            j++;
        }

        return minWindowSize == INT_MAX ? "" : s.substr(start_i, minWindowSize);
    }
};

// --- DRIVER CODE TO RUN TEST CASES ---
int main() {
    Solution sol;

    // Test Case 1: Standard case
    string s1 = "ADOBECODEBANC", t1 = "ABC";
    cout << "Test 1: " << sol.minWindow(s1, t1) << " (Expected: BANC)" << endl;

    // Test Case 2: Duplicates in t
    string s2 = "AAABECADEBA", t2 = "AAB";
    cout << "Test 2: " << sol.minWindow(s2, t2) << " (Expected: AAB)" << endl;

    // Test Case 3: No valid window
    string s3 = "a", t3 = "aa";
    cout << "Test 3: \"" << sol.minWindow(s3, t3) << "\" (Expected: \"\")" << endl;

    return 0;
}