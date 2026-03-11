// Leetcode :- 32. Longest Valid Parentheses



#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int open = 0, close = 0, ans = 0;

        // Forward Pass: Left to Right
        for(char ch : s) {
            if(ch == '(') open++;
            else close++;

            if(open == close) {
                ans = max(ans, 2 * close);
            } else if(close > open) {
                open = close = 0;
            }
        }

        open = close = 0;
        // Backward Pass: Right to Left
        // Fixed: i-- instead of i++
        for(int i = n - 1; i >= 0; i--) {
            char ch = s[i];
            if(ch == '(') open++;
            else close++;

            if(open == close) {
                ans = max(ans, 2 * open);
            } 
            // Fixed: If open > close while going backwards, it's invalid
            else if(open > close) {
                open = close = 0;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<string> tests = {"(()", ")()())", "", "()(()((())"};
    
    for(string s : tests) {
        cout << "Input: \"" << s << "\" | Output: " << sol.longestValidParentheses(s) << endl;
    }

    return 0;
}