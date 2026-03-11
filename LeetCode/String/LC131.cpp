// Leetcode :- 131 Palindrome Partitioning

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    bool isPalindrome(string s) {
        int i = 0; 
        int n = s.length() - 1;
        while (i < n) {
            if (s[i] != s[n]) return false;
            i++;
            n--;
        }
        return true;
    }

    void getAllParts(string s, vector<string> &partitions, vector<vector<string>> &ans) {
        // Base Case
        if (s.size() == 0) {
            ans.push_back(partitions);
            return;
        }

        for (int i = 0; i < s.size(); i++) {
            string part = s.substr(0, i + 1);

            if (isPalindrome(part)) {
                partitions.push_back(part);
                getAllParts(s.substr(i + 1), partitions, ans);
                partitions.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;
        getAllParts(s, partitions, ans);
        return ans;
    }
};

int main() {
    // ⭐ Your input here
    string s = "aab";

    Solution obj;
    vector<vector<string>> result = obj.partition(s);

    // Print output
    cout << "Input string: " << s << "\n";
    cout << "Palindrome partitions:\n";

    for (auto &vec : result) {
        cout << "[ ";
        for (auto &p : vec) {
            cout << p << " ";
        }
        cout << "]\n";
    }

    return 0;
}
