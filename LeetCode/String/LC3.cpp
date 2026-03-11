// Leetcode Problem 3: Longest Substring Without Repeating Characters

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_set<char> st;
        int i = 0;
        int j = 0;

        while(j < s.length()) {
            if(st.count(s[j]) == 0) {
                st.insert(s[j]);
                ans = max(ans, j-i+1);
                j++;
            }
            else {
                st.erase(s[i]);
                i++;
            }
        }

        return ans;
    }
};

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;  // reads input without spaces

    Solution obj;
    cout << "Length of Longest Substring Without Repeating Characters: "
         << obj.lengthOfLongestSubstring(s) << endl;

    return 0;
}
