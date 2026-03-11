// Leetcode 3714. Longest Balanced Substring



#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Helper to find balance between exactly two specific characters
    int helper(string s, char ch1, char ch2) {
        int n = s.length();
        unordered_map<int, int> diffMap;
        diffMap[0] = -1; // Base case for diff 0

        int c1 = 0;
        int c2 = 0;
        int maxL = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] != ch1 && s[i] != ch2) {
                diffMap.clear();
                diffMap[0] = i; // Reset base case to current index
                c1 = 0;
                c2 = 0;
                continue;
            }

            if(s[i] == ch1) c1++;
            else c2++;

            int diff = c1 - c2;
            if(diffMap.count(diff)) {
                maxL = max(maxL, i - diffMap[diff]);
            } else {
                diffMap[diff] = i;
            }
        }
        return maxL;
    }

    int longestBalanced(string s) {
        int n = s.length();
        if (n == 0) return 0;
        int maxL = 0;

        // Case 1: Identical characters (e.g., "aaaa")
        int count = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1]) count++;
            else {
                maxL = max(maxL, count);
                count = 1;
            }
        }
        maxL = max(maxL, count);

        // Case 2: Two-character balance (a==b, a==c, or b==c)
        maxL = max(maxL, helper(s, 'a', 'b'));
        maxL = max(maxL, helper(s, 'a', 'c'));
        maxL = max(maxL, helper(s, 'b', 'c'));

        // Case 3: Three-character balance (a==b==c)
        int countA = 0, countB = 0, countC = 0;
        unordered_map<string, int> diffMap;
        diffMap["0_0"] = -1;

        for(int i = 0; i < n; i++) {
            if(s[i] == 'a') countA++;
            else if(s[i] == 'b') countB++;
            else if(s[i] == 'c') countC++;

            int diffAB = countA - countB;
            int diffAC = countA - countC;
            string key = to_string(diffAB) + "_" + to_string(diffAC);

            if(diffMap.count(key)) {
                maxL = max(maxL, i - diffMap[key]);
            } else {
                diffMap[key] = i;
            }
        }

        return maxL;
    }
};

int main() {
    Solution sol;

    // Define test cases
    vector<string> inputs = {
        "abcabc",    // Case 3: a=2, b=2, c=2 (Length 6)
        "aabb",      // Case 2: a=2, b=2 (Length 4)
        "aaaa",      // Case 1: a=4 (Length 4)
        "abcde",     // Only a, b, c handled in your specific logic
        "aabbccaaa"  // Mixed
    };

    cout << "--- Testing Longest Balanced Substring ---" << endl;
    for (const string& str : inputs) {
        cout << "Input: " << str << " -> Result: " << sol.longestBalanced(str) << endl;
    }

    return 0;
}