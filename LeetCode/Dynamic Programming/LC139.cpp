// Leetcode 139. Word Break



#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <cstring> // For memset

using namespace std;

class Solution {
public: 
    unordered_set<string> st;
    int n;
    int t[301];

    bool solve(int index, string &s) {
        // Base Case: If we reached the end of the string, we successfully broke it
        if(index >= n) return true;

        // Memoization: Return stored result if already calculated
        if(t[index] != -1) return t[index];

        // Try every possible substring starting from 'index'
        for(int i = 1; index + i <= n; i++) {
            string temp = s.substr(index, i);

            // If the current substring exists in the dictionary AND
            // the rest of the string can be broken, return true
            if(st.find(temp) != st.end() && solve(index + i, s)) {
                return t[index] = true;
            }
        }

        return t[index] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        st.clear();
        memset(t, -1, sizeof(t));

        for(string &word: wordDict) st.insert(word);

        return solve(0, s);
    }
};

int main() {
    Solution sol;

    // Test Case 1
    string s1 = "leetcode";
    vector<string> dict1 = {"leet", "code"};
    cout << boolalpha; // Prints true/false instead of 1/0
    cout << "Test 1: " << sol.wordBreak(s1, dict1) << " (Expected: true)" << endl;

    // Test Case 2
    string s2 = "applepenapple";
    vector<string> dict2 = {"apple", "pen"};
    cout << "Test 2: " << sol.wordBreak(s2, dict2) << " (Expected: true)" << endl;

    // Test Case 3
    string s3 = "catsandog";
    vector<string> dict3 = {"cats", "dog", "sand", "and", "cat"};
    cout << "Test 3: " << sol.wordBreak(s3, dict3) << " (Expected: false)" << endl;

    return 0;
}