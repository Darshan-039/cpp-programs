// Leetcode 140. Word Break II







// Approach - 1 

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> ans;       // To store all valid full sentences
    unordered_set<string> st; // For O(1) word lookups

    void solve(int i, string &s, string &currSentence) {
        // BASE CASE: If we reached the end of the string, the current path is valid
        if(i == s.length()) {
            ans.push_back(currSentence);
            return;
        }

        // Try every possible "cut" from the current index 'i' to the end of the string
        for(int j = i; j < s.length(); j++) {
            // Extract substring from index 'i' of length (j-i+1)
            string tempWord = s.substr(i, j - i + 1);

            // If this slice is a valid word in our dictionary
            if(st.count(tempWord)) {
                // BACKTRACKING STEP:
                // 1. Save the state before making a change
                string tempSentence = currSentence;

                // 2. Modify: Add a space if it's not the first word, then add the word
                if(!currSentence.empty()) currSentence += " ";
                currSentence += tempWord;

                // 3. Recurse: Move to the next index after this word
                solve(j + 1, s, currSentence);

                // 4. Undo: Restore the old sentence to try the next 'j' (other word lengths)
                currSentence = tempSentence;
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // Clear global/member variables to ensure fresh results for every call
        ans.clear();
        st.clear();
        st.insert(wordDict.begin(), wordDict.end());

        string currSentence = "";
        solve(0, s, currSentence);

        return ans;
    }
};

int main() {
    Solution sol;

    // --- TEST INPUT ---
    string s = "catsanddog";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};

    // Execution
    vector<string> result = sol.wordBreak(s, wordDict);

    // Printing results
    cout << "Possible sentences for '" << s << "':" << endl;
    if(result.empty()) {
        cout << "No valid sentences found." << endl;
    } else {
        for(const string& sentence : result) {
            cout << "-> " << sentence << endl;
        }
    }

    return 0;
}













#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_set<string> st;
    unordered_map<string, vector<string>> mp;

    vector<string> solve(string &s) {
        if(s.empty()) return {""};

        if(mp.count(s)) return mp[s];

        vector<string> result;
        for(int i = 1; i <= s.length(); i++) {
            string currWord = s.substr(0, i);

            if(st.count(currWord)) {
                string remainWord = s.substr(i);
                vector<string> remainResult = solve(remainWord);

                for(string &w: remainResult) {
                    string toAdd = currWord + (w.empty() ? "" : " ") + w;
                    result.push_back(toAdd);
                }
            }
        }

        return mp[s] = result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        st.clear();
        mp.clear(); // Important: Clear memoization for new test cases!
        st.insert(wordDict.begin(), wordDict.end());

        return solve(s);
    }
};

int main() {
    Solution sol;

    // --- TEST CASE 1 ---
    string s1 = "catsanddog";
    vector<string> dict1 = {"cat", "cats", "and", "sand", "dog"};
    
    vector<string> result1 = sol.wordBreak(s1, dict1);

    cout << "Test Case 1 Output:" << endl;
    for (const string& sentence : result1) {
        cout << "\"" << sentence << "\"" << endl;
    }
    
    cout << "---" << endl;

    // --- TEST CASE 2 ---
    string s2 = "pineapplepenapple";
    vector<string> dict2 = {"apple", "pen", "applepen", "pine", "pineapple"};
    
    vector<string> result2 = sol.wordBreak(s2, dict2);

    cout << "Test Case 2 Output:" << endl;
    for (const string& sentence : result2) {
        cout << "\"" << sentence << "\"" << endl;
    }

    return 0;
}