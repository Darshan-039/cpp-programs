// Leetcode 3913. Sort Vowels in a String


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:

    // Function to check whether character is vowel
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u';
    }

    string sortVowels(string s) {

        int n = s.length();

        // Store all vowels
        vector<char> vowels;

        // Store frequency of each vowel
        unordered_map<char, int> freq;

        // Store first occurrence index of each vowel
        unordered_map<char, int> firstIdx;

        // Step 1: Collect vowels and their details
        for (int i = 0; i < n; i++) {

            char ch = s[i];

            if (isVowel(ch)) {

                vowels.push_back(ch);

                // Increase frequency
                freq[ch]++;

                // Store first occurrence index
                if (!firstIdx.count(ch)) {
                    firstIdx[ch] = i;
                }
            }
        }

        // Step 2: Sort vowels
        sort(vowels.begin(), vowels.end(),
             [&](char a, char b) {

            // Higher frequency comes first
            if (freq[a] != freq[b]) {
                return freq[a] > freq[b];
            }

            // If frequency same,
            // vowel appearing earlier comes first
            return firstIdx[a] < firstIdx[b];
        });

        // Step 3: Put sorted vowels back into string
        int k = 0;

        for (int i = 0; i < n; i++) {

            if (isVowel(s[i])) {
                s[i] = vowels[k++];
            }
        }

        return s;
    }
};

int main() {

    string s;

    cout << "Enter string: ";
    cin >> s;

    Solution obj;

    string result = obj.sortVowels(s);

    cout << "Result: " << result << endl;

    return 0;
}