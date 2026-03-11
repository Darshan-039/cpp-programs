// Leetcode 87. Scramble String 




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Memoization map to store already computed states
    unordered_map<string, bool> mp;

    bool solve(string s1, string s2) {

        // If both strings are equal, they are scramble
        if(s1 == s2) return true;

        // If lengths are different, they can't be scramble
        if(s1.length() != s2.length()) return false;

        // Create unique key for memoization
        string key = s1 + "_" + s2;

        // If already calculated, return stored result
        if(mp.find(key) != mp.end()) return mp[key];

        bool result = false;
        int n = s1.length();

        // Try every possible partition
        for(int i = 1; i < n; i++) {

            // Case 1: Strings are swapped
            // Example: "great" -> "rgeat"
            bool swapped =
                solve(s1.substr(0, i), s2.substr(n - i, i)) &&
                solve(s1.substr(i, n - i), s2.substr(0, n - i));

            if(swapped == true) {
                result = true;
                break;
            }

            // Case 2: Strings are NOT swapped
            bool not_swapped =
                solve(s1.substr(0, i), s2.substr(0, i)) &&
                solve(s1.substr(i, n - i), s2.substr(i, n - i));

            if(not_swapped == true) {
                result = true;
                break;
            }
        }

        // Store result in memo map
        return mp[key] = result;
    }

    bool isScramble(string s1, string s2) {
        mp.clear(); // clear memo before new test
        return solve(s1, s2);
    }
};


int main() {

    Solution obj;

    string s1 = "great";
    string s2 = "rgeat";

    if(obj.isScramble(s1, s2))
        cout << "True (Scramble String)" << endl;
    else
        cout << "False (Not Scramble)" << endl;

    return 0;
}