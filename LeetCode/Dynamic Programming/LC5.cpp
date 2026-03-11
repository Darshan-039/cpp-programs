// Leetcode Problem 5: Longest Palindromic Substring


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int t[1001][1001];

    bool checkPalindrome(string &s, int i, int j) {
        if (i >= j) return true;

        if (t[i][j] != -1) {
            return t[i][j];
        }

        if (s[i] == s[j]) {
            return t[i][j] = checkPalindrome(s, i + 1, j - 1);
        }

        return t[i][j] = false;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        memset(t, -1, sizeof(t));

        int maxLength = 0;
        int sp = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {   // j should start from i
                if (checkPalindrome(s, i, j)) {
                    if (j - i + 1 > maxLength) {
                        maxLength = j - i + 1;
                        sp = i;
                    }
                }
            }
        }

        return s.substr(sp, maxLength);
    }
};

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;   // use getline(cin, s) if spaces are allowed

    Solution obj;
    string ans = obj.longestPalindrome(s);

    cout << "Longest Palindromic Substring: " << ans << endl;

    return 0;
}
