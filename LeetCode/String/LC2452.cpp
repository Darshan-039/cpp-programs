// Leetcode 2452. Words Within Two Edits of Dictionary


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;

        // Iterate over each query word
        for (string& query : queries) {

            // Compare with each word in dictionary
            for (string& word : dictionary) {
                int diff = 0;

                // Count character differences
                for (int i = 0; i < query.size(); i++) {
                    if (query[i] != word[i]) diff++;

                    // If more than 2 differences, stop early
                    if (diff > 2) break;
                }

                // If differences are <= 2, it's valid
                if (diff <= 2) {
                    result.push_back(query);
                    break;  // no need to check further dictionary words
                }
            }
        }

        return result;
    }
};


// Main function
int main() {
    int n, m;

    cout << "Enter number of queries: ";
    cin >> n;

    vector<string> queries(n);
    cout << "Enter query words: ";
    for (int i = 0; i < n; i++) cin >> queries[i];

    cout << "Enter number of dictionary words: ";
    cin >> m;

    vector<string> dictionary(m);
    cout << "Enter dictionary words: ";
    for (int i = 0; i < m; i++) cin >> dictionary[i];

    Solution obj;
    vector<string> result = obj.twoEditWords(queries, dictionary);

    cout << "Words within two edits:\n";
    for (auto &word : result) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}