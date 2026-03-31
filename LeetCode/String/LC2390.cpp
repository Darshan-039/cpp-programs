// Leetcode 2390. Removing Stars From a String



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        int k = -1; // Pointer to track valid characters (acts like a stack top)
        int n = s.length();

        for (int i = 0; i < n; i++) {

            if (s[i] == '*') {
                // If '*' found → remove previous character
                k--;
            } else {
                // Otherwise, keep the character
                // Move pointer forward and place character
                s[++k] = s[i];
            }
        }

        // Return string till valid index (k)
        return s.substr(0, k + 1);
    }
};

int main() {
    string s;

    cout << "Enter string: ";
    cin >> s;

    Solution obj;
    string result = obj.removeStars(s);

    cout << "Result after removing stars: " << result << endl;

    return 0;
}