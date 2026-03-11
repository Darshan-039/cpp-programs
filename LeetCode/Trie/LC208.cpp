// LeetCode 208: Implement Trie (Prefix Tree)




#include <iostream>
#include <vector>
#include <string>

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
    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word) {
        if(word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index]) {
            child = root->children[index];
        }
        else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }
    
    void insert(string word) {
        insertUtil(root, word);
    }



    bool searchUtil(TrieNode* root, string word) {
        if(word.length() == 0) return root->isTerminal;

        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index]) {
            child = root->children[index];
        }
        else return false;

        return searchUtil(child, word.substr(1));
    }
    
    bool search(string word) {
        return searchUtil(root, word);
    }



    bool prefixUtil(TrieNode* root, string word) {
        if(word.length() == 0) return true;

        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index]) {
            child = root->children[index];
        }
        else return false;

        return prefixUtil(child, word.substr(1));
    }
    
    bool startsWith(string prefix) {
        return prefixUtil(root, prefix);
    }
};

int main() {
    Trie* obj = new Trie();

    // 1. Testing Insertion
    cout << "Inserting words: 'apple', 'app', 'coding'..." << endl;
    obj->insert("apple");
    obj->insert("app");
    obj->insert("coding");

    // Enable printing true/false instead of 1/0
    cout << boolalpha;

    // 2. Testing Search
    cout << "\n--- Search Tests ---" << endl;
    cout << "Search 'apple': " << obj->search("apple") << endl;    // Expected: true
    cout << "Search 'app': " << obj->search("app") << endl;        // Expected: true
    cout << "Search 'appl': " << obj->search("appl") << endl;      // Expected: false
    cout << "Search 'coder': " << obj->search("coder") << endl;    // Expected: false

    // 3. Testing StartsWith (Prefix)
    cout << "\n--- Prefix Tests ---" << endl;
    cout << "StartsWith 'app': " << obj->startsWith("app") << endl;   // Expected: true
    cout << "StartsWith 'cod': " << obj->startsWith("cod") << endl;   // Expected: true
    cout << "StartsWith 'xyz': " << obj->startsWith("xyz") << endl;   // Expected: false

    return 0;
}