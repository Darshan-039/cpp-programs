// LeetCode 1657. Determine if Two Strings Are Close



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        // If lengths are different → cannot be close
        if(n != m) return false;

        vector<int> freq1(26, 0), freq2(26, 0);

        // Count frequency of each character in both strings
        for(char ch : word1) 
            freq1[ch - 'a']++;

        for(char ch : word2) 
            freq2[ch - 'a']++;

        // Check if both strings use the same set of characters
        // (i.e., if a character exists in one, it must exist in the other)
        for(int i = 0; i < 26; i++) {
            if((freq1[i] == 0 && freq2[i] != 0) || 
               (freq1[i] != 0 && freq2[i] == 0)) {
                return false;
            }
        }

        // Sort frequency arrays to compare distributions
        // This checks if we can transform frequencies via swaps
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        // If both frequency patterns match → strings are close
        return freq1 == freq2;
    }
};

int main() {
    Solution obj;

    // Sample input
    string word1 = "abc";
    string word2 = "bca";

    // Function call
    bool result = obj.closeStrings(word1, word2);

    // Output
    if(result)
        cout << "Strings are CLOSE" << endl;
    else
        cout << "Strings are NOT CLOSE" << endl;

    return 0;
}