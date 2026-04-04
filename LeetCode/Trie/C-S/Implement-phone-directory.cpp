// Optimal approach 


// Approach - 1 (Using Sorting and Binary Search) - O(N log N + M log N)

// vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr) {
//     sort(contactList.begin(), contactList.end());
//     contactList.erase(unique(contactList.begin(), contactList.end()), contactList.end());


//     int n = contactList.size();
//     vector<vector<string>> ans;

//     int left = 0;
//     int right = n-1;

//     for(int i = 0; i<queryStr.length(); i++) {
//         char ch = queryStr[i];

//         while(left <= right && (contactList[left].length() <= i || contactList[left][i] != ch)) {
//             left++;
//         }

//         while(left <= right && (contactList[right].length() <= i || contactList[right][i] != ch)) {
//             right--;
//         }

//         vector<string> temp;
//         if (left <= right) {
//             // 4. Collect ALL matching strings (Fix: j = left to right)
//             for (int j = left; j <= right; j++) {
//                 temp.push_back(contactList[j]);
//             }
//             ans.push_back(temp);
//         }
//         else break;

//     }

//     return ans;
// }






// Approach - 2 (Using Trie)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for(int i = 0; i < 26; i++) children[i] = NULL;
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode('\0'); }

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
        }
        insertUtil(child, word.substr(1));
    }

    void insert(string word) {
        insertUtil(root, word); 
    }

    void printSuggestions(TrieNode* curr, vector<string> &temp, string prefix) {
        if(curr->isTerminal) temp.push_back(prefix);

        for(int i = 0; i < 26; i++) {
            TrieNode* next = curr->children[i];
            if(next) {
                prefix.push_back('a' + i);
                printSuggestions(next, temp, prefix);
                prefix.pop_back(); // Backtrack
            }
        }
    }

    vector<vector<string>> getSuggestions(string str) {
        TrieNode* prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for(int i = 0; i < str.length(); i++) {
            char lastCh = str[i];
            prefix.push_back(lastCh);

            TrieNode* curr = prev->children[lastCh - 'a'];

            // If prefix not found, the requirement is often to return "0"
            if(!curr) {
                // Fill the remaining characters of queryStr with "0"
                while(i < str.length()) {
                    output.push_back({"0"});
                    i++;
                }
                break;
            }
            
            vector<string> temp;
            printSuggestions(curr, temp, prefix);
            output.push_back(temp);
            prev = curr; 
        }
        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string>& contactList, string &queryStr) {
    Trie *t = new Trie();    
    for(string word : contactList) t->insert(word);
    return t->getSuggestions(queryStr);
}

int main() {
    // --- Sample Input ---
    vector<string> contactList = {"geeikistest", "geeksforgeeks", "geeksfortest"};
    string queryStr = "geeips";

    // --- Execute Function ---
    vector<vector<string>> result = phoneDirectory(contactList, queryStr);

    // --- Print Output ---
    cout << "Suggestions for query '" << queryStr << "':" << endl;
    for(int i = 0; i < result.size(); i++) {
        cout << "Prefix '" << queryStr.substr(0, i+1) << "': ";
        for(string s : result[i]) {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}
