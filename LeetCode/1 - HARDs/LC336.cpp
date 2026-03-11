// Leetcode 336. Palindrome Pairs



#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPalindrome(const string &s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        int n = words.size();

        if(n < 2) return result;

        unordered_map<string, int> mp;
        for(int i = 0; i < n; i++) {
            string s = words[i];
            reverse(s.begin(), s.end());
            mp[s] = i;
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= words[i].length(); j++) {
                string str1 = words[i].substr(0, j);
                string str2 = words[i].substr(j);

                // Case 1: If str1 is in map and str2 is a palindrome
                if(mp.count(str1) && isPalindrome(str2) && mp[str1] != i) {
                    result.push_back({i, mp[str1]});
                }

                // Case 2: If str2 is in map and str1 is a palindrome
                if(!str1.empty() && mp.count(str2) && isPalindrome(str1) && mp[str2] != i) {
                    result.push_back({mp[str2], i});
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    
    // Test Input
    vector<string> words = {"abcd", "dcba", "lls", "s", "sssll"};
    
    // Call the function
    vector<vector<int>> result = sol.palindromePairs(words);
    
    // Printing the output
    cout << "Palindrome Pair Indices:" << endl;
    cout << "[";
    for(int i = 0; i < result.size(); i++) {
        cout << "[" << result[i][0] << ", " << result[i][1] << "]";
        if(i != result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}