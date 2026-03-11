// Leetcode 438. Find All Anagrams in a String


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int windowSize = p.length();

        vector<int> ans;
        if (windowSize > n) return ans;

        vector<int> countP(26, 0), countS(26, 0);

        // frequency of p
        for (char c : p)
            countP[c - 'a']++;

        // first window
        for (int i = 0; i < windowSize; i++)
            countS[s[i] - 'a']++;

        if (countP == countS)
            ans.push_back(0);

        // sliding window
        for (int i = 1; i <= n - windowSize; i++) {
            // remove left char
            countS[s[i - 1] - 'a']--;
            // add right char
            countS[s[i + windowSize - 1] - 'a']++;

            if (countS == countP)
                ans.push_back(i);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    // 🔹 Input written directly in code
    string s = "cbaebabacd";
    string p = "abc";

    vector<int> result = obj.findAnagrams(s, p);

    // Output
    cout << "Anagram starting indices: ";
    for (int idx : result)
        cout << idx << " ";

    return 0;
}
