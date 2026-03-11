// Leetcode 242 - Valid Anagram

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        int freq[26] = {0};

        for (char c : s) {
            freq[c - 'a']++;
        }

        for (char c : t) {
            freq[c - 'a']--;
        }

        for (int x : freq) {
            if (x != 0) return false;
        }

        return true;
    }
};

int main() {
    // Make your own inputs here:
    string s = "anagram";
    string t = "nagaram";

    Solution obj;
    bool result = obj.isAnagram(s, t);

    if (result) {
        cout << "Output: true\n";
    } else {
        cout << "Output: false\n";
    }

    return 0;
}
