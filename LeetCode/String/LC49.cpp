// Leetcode :- 49  Group Anagrams

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        // ---------- Method 1: Sorting (commented) ----------
        /*
        for (auto &s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }
        */

        // ---------- Method 2: Frequency Count (Optimal) ----------
        for (string s : strs) {
            // Count characters
            vector<int> freq(26, 0);
            for (char c : s) {
                freq[c - 'a']++;
            }

            // Create unique key
            string key = "";
            for (int x : freq) {
                key += "#" + to_string(x);
            }

            mp[key].push_back(s);
        }

        // Store result
        vector<vector<string>> ans;
        for (auto &it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> strs(n);
    cout << "Enter strings (lowercase only):\n";
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    Solution obj;
    vector<vector<string>> result = obj.groupAnagrams(strs);

    cout << "\nGrouped Anagrams:\n";
    for (auto &group : result) {
        cout << "[ ";
        for (auto &word : group) {
            cout << word << " ";
        }
        cout << "]\n";
    }

    return 0;
}
