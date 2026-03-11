// Leetcode :- 316  Remove Duplicate Letters
// Monotonic Stack + Greedy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {

        vector<int> LastIndex(26);
        vector<bool> taken(26, false);

        int n = s.length();
        string res = "";

        // Store last occurrence index of each character
        for (int i = 0; i < n; i++) {
            LastIndex[s[i] - 'a'] = i;
        }

        // Build result using greedy + stack logic
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            int idx = ch - 'a';

            if (taken[idx]) continue;

            while (!res.empty() &&
                   res.back() > ch &&
                   LastIndex[res.back() - 'a'] > i) {
                taken[res.back() - 'a'] = false;
                res.pop_back();
            }

            res.push_back(ch);
            taken[idx] = true;
        }

        return res;
    }
};

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    Solution obj;
    string result = obj.removeDuplicateLetters(s);

    cout << "Result after removing duplicate letters: " << result << endl;

    return 0;
}
