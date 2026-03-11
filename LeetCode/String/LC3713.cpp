// Leetcode 3713. Longest Balanced Substring




// Approach: Brute Force 
// Time Complexity: O(n^3) - We have two nested loops to generate all possible substrings, and an additional loop to check if the substring is balanced.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        if (n == 0) return 0;
        
        int ans = 0;

        for(int i = 0; i < n; i++) {
            vector<int> count(26, 0);

            for(int j = i; j < n; j++) {
                count[s[j] - 'a']++;
                // The frequency of the current character we just added
                int freq = count[s[j] - 'a'];

                bool isBalanced = true;

                // Check if all characters currently in our 'count' vector 
                // have the same frequency as 'freq'
                for(int k : count) {
                    if(k != 0 && k != freq) {
                        isBalanced = false;
                        break;
                    }
                }

                if(isBalanced) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    string input1 = "aaabbbccc";
    cout << "Input: " << input1 << "\nOutput: " << sol.longestBalanced(input1) << endl; 

    // Test Case 2
    string input2 = "abccba";
    cout << "Input: " << input2 << "\nOutput: " << sol.longestBalanced(input2) << endl;

    // Test Case 3
    string input3 = "abcde";
    cout << "Input: " << input3 << "\nOutput: " << sol.longestBalanced(input3) << endl;

    return 0;
}








// Approach - 2 : Optimized Brute Force with Math Trick
// Time Complexity: O(n^2) - We have two nested loops to generate all possible 
//          substrings, but we avoid the innermost loop to check if the substring is 
//          balanced by using a mathematical trick.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            vector<int> count(26, 0);
            int max_freq = 0;
            int distinct_count = 0;

            for(int j = i; j < n; j++) {
                int ch = s[j] - 'a';
                
                // If this is a new character, increment distinct count
                if(count[ch] == 0) {
                    distinct_count++;
                }

                count[ch]++;

                // Track the highest frequency of any character in the current window
                max_freq = max(max_freq, count[ch]);

                int length = j - i + 1;
                
                // Math Trick: If (max_freq * number of distinct chars) == total length,
                // then all present characters MUST have the exact same frequency.
                if(max_freq * distinct_count == length) {
                    ans = max(ans, length);
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Test cases to verify the code
    struct TestCase {
        string input;
        string description;
    };

    vector<TestCase> tests = {
        {"aaabbbccc", "All characters have same frequency (3)"},
        {"abccba", "Symmetric balanced string"},
        {"abcde", "All characters unique (frequency 1)"},
        {"aabbac", "Balanced part is 'aabb' (length 4)"},
        {"azazaz", "Two characters alternating"},
        {"", "Empty string case"}
    };

    cout << "--- LeetCode 3713 Optimized Solution ---" << endl;

    for (const auto& test : tests) {
        int result = sol.longestBalanced(test.input);
        cout << "Input: \"" << test.input << "\"" << endl;
        cout << "Description: " << test.description << endl;
        cout << "Result: " << result << endl;
        cout << "---------------------------------------" << endl;
    }

    return 0;
}