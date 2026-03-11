// Leetcode 392. Is Subsequence


#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;

        int n = s.length();
        int m = t.length();

        while(i < n && j < m) {
            if(s[i] == t[j]) {
                i++;
            }
            j++;
        }

        return i == n;
    }
};

int main() {
    // 1. Create an object of the Solution class
    Solution sol;

    // 2. Declare variables for input
    string s, t;

    // 3. Take input from the user
    cout << "Enter the potential subsequence (s): ";
    cin >> s;
    cout << "Enter the main string (t): ";
    cin >> t;

    // 4. Call the function and store the result
    bool result = sol.isSubsequence(s, t);

    // 5. Output the result
    if (result) {
        cout << "True: '" << s << "' is a subsequence of '" << t << "'" << endl;
    } else {
        cout << "False: '" << s << "' is NOT a subsequence of '" << t << "'" << endl;
    }

    return 0;
}