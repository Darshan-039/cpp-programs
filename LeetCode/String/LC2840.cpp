// LeetCode 2840. Check if Strings Can be Made Equal With Operations II


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.length();

        // Frequency arrays for characters at even and odd indices
        vector<int> evens(26, 0);
        vector<int> odds(26, 0);

        // Traverse both strings
        for(int i = 0; i < n; i++) {

            // If index is even → update even frequency
            if(i % 2 == 0) {
                evens[s1[i] - 'a']++;  // add from s1
                evens[s2[i] - 'a']--;  // subtract from s2
            }
            // If index is odd → update odd frequency
            else {
                odds[s1[i] - 'a']++;   // add from s1
                odds[s2[i] - 'a']--;   // subtract from s2
            }
        }

        // Check if all frequencies match
        for(int i = 0; i < 26; i++) {
            if(evens[i] != 0 || odds[i] != 0)
                return false; // mismatch found
        }

        return true; // strings are equivalent
    }
};

int main() {
    Solution obj;

    // Example inputs
    string s1 = "abcd";
    string s2 = "cdab";

    /*
        Explanation:
        You can swap characters at even indices among themselves
        and odd indices among themselves.

        s1 = "abcd"
        even indices → a, c
        odd indices  → b, d

        s2 = "cdab"
        even indices → c, a
        odd indices  → d, b

        Frequencies match → Output = true
    */

    bool result = obj.checkStrings(s1, s2);

    if(result)
        cout << "Strings are equivalent" << endl;
    else
        cout << "Strings are NOT equivalent" << endl;

    return 0;
}