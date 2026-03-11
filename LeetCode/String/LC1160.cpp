// Leetcode :- 1160  Find Words That Can Be Formed by Characters

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> charCount(26, 0);

        // Count frequency of each character in chars
        for (char c : chars) {
            charCount[c - 'a']++;
        }

        int totalLength = 0;

        // Check each word
        for (string word : words) {
            vector<int> currCount = charCount;
            bool canForm = true;

            for (char c : word) {
                if (currCount[c - 'a'] > 0) {
                    currCount[c - 'a']--;
                } else {
                    canForm = false;
                    break;
                }
            }

            if (canForm) {
                totalLength += word.length();
            }
        }

        return totalLength;
    }
};

int main() {
    int n;
    cout << "Enter number of words: ";
    cin >> n;

    vector<string> words(n);
    cout << "Enter words:\n";
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    string chars;
    cout << "Enter characters string: ";
    cin >> chars;

    Solution obj;
    int result = obj.countCharacters(words, chars);

    cout << "Total length of good words = " << result << endl;

    return 0;
}
