// Leetcode 1268: Search Suggestions System



#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        // Step 1: Sort products lexicographically
        sort(products.begin(), products.end());
        
        vector<vector<string>> result;
        int left = 0, right = products.size() - 1;
        
        for (int i = 0; i < searchWord.length(); i++) {
            char c = searchWord[i];
            
            // Step 2: Shrink the window from the left by checking the i-th character
            while (left <= right && (products[left].length() <= i || products[left][i] != c)) {
                left++;
            }
            
            // Step 3: Shrink the window from the right by checking the i-th character
            while (left <= right && (products[right].length() <= i || products[right][i] != c)) {
                right--;
            }
            
            // Step 4: Collect at most 3 suggestions from the current valid range [left, right]
            vector<string> suggestions;
            for (int j = 0; j < 3 && left + j <= right; j++) {
                suggestions.push_back(products[left + j]);
            }
            
            result.push_back(suggestions);
        }
        
        return result;
    }
};

int main() {
    Solution sol;

    // --- Provide Input Here ---
    vector<string> products = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    string searchWord = "mouse";

    // --- Execute the Logic ---
    vector<vector<string>> result = sol.suggestedProducts(products, searchWord);

    // --- Display the Output ---
    cout << "Search Suggestions for: " << searchWord << endl;
    cout << "-----------------------------------" << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << "Typed '" << searchWord.substr(0, i + 1) << "': [";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << (j == result[i].size() - 1 ? "" : ", ");
        }
        cout << "]" << endl;
    }

    return 0;
}