#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<string, bool> mp;

    bool isConcatenated(string word, unordered_set<string> &st) {
        if(mp.find(word) != mp.end()) return mp[word];

        int n = word.length();
        for(int i = 0; i < n; i++) {
            string prefix = word.substr(0, i + 1);
            string suffix = word.substr(i + 1);

            // Logic: A word is concatenated if:
            // 1. The prefix exists in the set AND the suffix is also a concatenated word
            // 2. OR the prefix exists in the set AND the suffix exists in the set
            if((st.find(prefix) != st.end() && isConcatenated(suffix, st)) || 
               (st.find(prefix) != st.end() && st.find(suffix) != st.end())) {
                return mp[word] = true;
            }
        }

        return mp[word] = false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        mp.clear();
        unordered_set<string> st(words.begin(), words.end());
        vector<string> result;

        for(const string& word : words) {
            if(isConcatenated(word, st)) {
                result.push_back(word);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Sample Input 1
    vector<string> words1 = {
        "cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"
    };
    
    // Sample Input 2
    vector<string> words2 = {"cat", "dog", "catdog"};

    vector<string> result1 = sol.findAllConcatenatedWordsInADict(words1);
    vector<string> result2 = sol.findAllConcatenatedWordsInADict(words2);

    // Outputting Results
    cout << "Test Case 1 Results:" << endl;
    for(const string& w : result1) cout << "[" << w << "] ";
    
    cout << "\n\nTest Case 2 Results:" << endl;
    for(const string& w : result2) cout << "[" << w << "] ";
    cout << endl;

    return 0;
}