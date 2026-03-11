// Leetcode 647. Palindromic Substrings












// Approach - 1: Brute Force (O(n^3))





// #include <iostream>
// #include <string>
// #include <vector>
// #include <cstring> // For memset

// using namespace std;

// class Solution {
// public:
//     // Memoization table: t[i][j] stores if substring s[i...j] is a palindrome
//     int t[2001][2001];

//     bool isPalindrome(string &s, int i, int j) {
//         // Base case: empty string or single character
//         if (i >= j) return true;

//         // Return cached result if available
//         if (t[i][j] != -1) return t[i][j];

//         // If characters match, check the inner substring
//         if (s[i] == s[j]) {
//             return t[i][j] = isPalindrome(s, i + 1, j - 1);
//         }

//         return t[i][j] = false;
//     }

//     int countSubstrings(string s) {
//         int n = s.length();
//         // Initialize memoization table with -1 (meaning "uncalculated")
//         memset(t, -1, sizeof(t));
//         int count = 0;

//         // Check every possible substring (i, j)
//         for (int i = 0; i < n; i++) {
//             for (int j = i; j < n; j++) {
//                 if (isPalindrome(s, i, j)) {
//                     count++;
//                 }
//             }
//         }

//         return count;
//     }
// };

// int main() {
//     Solution sol;

//     // Test Case 1: "abc"
//     // Substrings: "a", "b", "c" -> Result: 3
//     string s1 = "abc";
//     cout << "Input: " << s1 << " | Result: " << sol.countSubstrings(s1) << endl;

//     // Test Case 2: "aaa"
//     // Substrings: "a", "a", "a", "aa", "aa", "aaa" -> Result: 6
//     string s2 = "aaa";
//     cout << "Input: " << s2 << " | Result: " << sol.countSubstrings(s2) << endl;

//     // Test Case 3: "racecar"
//     string s3 = "racecar";
//     cout << "Input: " << s3 << " | Result: " << sol.countSubstrings(s3) << endl;

//     return 0;
// }










// Approach - 2 (Dynamic Programming - Tabulation) - O(n^2)



#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;

        // t[i][j] will be true if substring s[i...j] is a palindrome
        vector<vector<bool>> t(n, vector<bool>(n, false));

        // L is the length of the substring we are checking
        for (int L = 1; L <= n; L++) {
            for (int i = 0; i + L - 1 < n; i++) {
                int j = i + L - 1;

                if (i == j) {
                    // Case 1: Single character (always a palindrome)
                    t[i][j] = true;
                } 
                else if (i + 1 == j) {
                    // Case 2: Two characters (palindrome if they match)
                    t[i][j] = (s[i] == s[j]);
                } 
                else {
                    // Case 3: More than 2 characters
                    // Palindrome if ends match AND the inside part is already a palindrome
                    t[i][j] = (s[i] == s[j] && t[i + 1][j - 1]);
                }

                if (t[i][j]) {
                    count++;
                }
            }
        }

        return count;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    string s1 = "abc";
    cout << "Input: \"" << s1 << "\" | Palindromic Substrings: " << sol.countSubstrings(s1) << endl;
    // Expected: 3 ("a", "b", "c")

    // Test Case 2
    string s2 = "aaa";
    cout << "Input: \"" << s2 << "\" | Palindromic Substrings: " << sol.countSubstrings(s2) << endl;
    // Expected: 6 ("a", "a", "a", "aa", "aa", "aaa")

    // Test Case 3
    string s3 = "fdsklf";
    cout << "Input: \"" << s3 << "\" | Palindromic Substrings: " << sol.countSubstrings(s3) << endl;
    // Expected: 6

    return 0;
}