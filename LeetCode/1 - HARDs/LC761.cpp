// Leetcode 761. Special Binary String




#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s.empty()) return "";
        
        vector<string> specials;
        int start = 0;
        int count = 0;

        for (int i = 0; i < s.length(); i++) {
            // Treat '1' as '(' and '0' as ')'
            count += (s[i] == '1') ? 1 : -1;

            if (count == 0) {
                // Strip the outer 1 and 0, recurse on the middle
                string inner = s.substr(start + 1, i - start - 1);
                specials.push_back("1" + makeLargestSpecial(inner) + "0");
                
                start = i + 1; 
            }
        }

        // Sort chunks descending to get the lexicographically largest result
        sort(specials.begin(), specials.end(), greater<string>());

        string result = "";
        for (const string &str : specials) result += str;

        return result;
    }
};

int main() {
    Solution sol;

    // --- TEST CASES ---
    
    // Case 1: Simple nested and adjacent special strings
    string s1 = "11011000";
    // Expected logic:
    // Chunks found: "1100" and "10"
    // After recursion and sorting: "11100100"
    cout << "Input: " << s1 << " -> Output: " << sol.makeLargestSpecial(s1) << endl;

    // Case 2: Already largest
    string s2 = "10";
    cout << "Input: " << s2 << " -> Output: " << sol.makeLargestSpecial(s2) << endl;

    // Case 3: Complex nested structure
    string s3 = "1101001100";
    cout << "Input: " << s3 << " -> Output: " << sol.makeLargestSpecial(s3) << endl;

    return 0;
}