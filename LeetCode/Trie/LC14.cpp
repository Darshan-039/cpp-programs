// 14. Longest Common Prefix




// Approach - 1 
// Using Trie to find longest common prefix among a list of strings
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for(int i = 0; i < 26; i++) children[i] = NULL;
        childCount = 0;
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie(char ch) {
        root = new TrieNode(ch);
    }

    void insertUtil(TrieNode* curr, string word) {
        if(word.length() == 0) {
            curr->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(curr->children[index]) {
            child = curr->children[index];
        } else {
            child = new TrieNode(word[0]);
            curr->children[index] = child;
            curr->childCount++;
        }

        insertUtil(child, word.substr(1));
    }

    void insert(string word) {
        if(word.length() > 0) insertUtil(root, word);
    }

    void lcp(string str, string &ans) {
        TrieNode* curr = root; // Use a temp pointer to avoid destroying the Trie
        
        for(int i = 0; i < str.length(); i++) {
            char ch = str[i];

            // If a node has exactly one child, it's part of the common prefix
            if(curr->childCount == 1) {
                int index = ch - 'a';
                curr = curr->children[index];
                ans.push_back(ch);
            } 
            else break;

            // If we reach the end of any word, the prefix must stop
            if(curr->isTerminal) break;
        }
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        if(strs.size() == 1) return strs[0];

        Trie *t = new Trie('\0');

        // Insert all strings into trie
        for(string word: strs) {
            if(word == "") return ""; // If any string is empty, LCP is ""
            t->insert(word);
        }

        string first = strs[0];
        string ans = "";
        
        t->lcp(first, ans);

        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<string> input1 = {"flower", "flow", "flight"};
    cout << "Input: {flower, flow, flight}\nLCP: " << sol.longestCommonPrefix(input1) << endl;

    // Test Case 2
    vector<string> input2 = {"dog", "racecar", "car"};
    cout << "\nInput: {dog, racecar, car}\nLCP: " << sol.longestCommonPrefix(input2) << endl;

    return 0;
}















// Approach - 2
// Optimal Approach
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0) return "";
        if (n == 1) return strs[0];

        string temp = strs[0]; 
        int m = temp.length();
        string ans = "";

        for (int i = 0; i < m; i++) {
            char ch = temp[i];
            bool isSame = true; // Assume true, then verify

            for (int j = 1; j < n; j++) {
                // IMPORTANT: Check if index 'i' is within bounds for current string
                // and if the character matches
                if (i >= strs[j].length() || strs[j][i] != ch) {
                    isSame = false;
                    break;
                }
            }

            if (isSame) {
                ans.push_back(ch);
            } else {
                // If we found a mismatch or hit the end of any string, stop
                break;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // --- Test Case 1 ---
    vector<string> input1 = {"flower", "flow", "flight"};
    cout << "Test 1 - Input: {flower, flow, flight}" << endl;
    cout << "Result: \"" << sol.longestCommonPrefix(input1) << "\"" << endl;

    // --- Test Case 2 ---
    vector<string> input2 = {"dog", "racecar", "car"};
    cout << "\nTest 2 - Input: {dog, racecar, car}" << endl;
    cout << "Result: \"" << sol.longestCommonPrefix(input2) << "\"" << endl;

    // --- Test Case 3 ---
    vector<string> input3 = {"apple", "ape", "april"};
    cout << "\nTest 3 - Input: {apple, ape, april}" << endl;
    cout << "Result: \"" << sol.longestCommonPrefix(input3) << "\"" << endl;

    return 0;
}