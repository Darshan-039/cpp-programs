// Leetcode 3474. Generate String Based on Conditions



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();

        // This array tells which positions are fixed (cannot be changed later)
        vector<bool> fixed(n + m - 1, false);
       
        // Initialize answer string with 'a'
        string ans(n + m - 1, 'a');

        // Step 1: Handle all 'T' (True) conditions
        // If str1[i] == 'T', then substring starting at i must match str2
        for(int i = 0; i < n; i++) {

            if(str1[i] == 'T') {
                
                for(int k = i, idx = 0; k < i + m; k++, idx++) {

                    // If already different and fixed → impossible
                    if(ans[k] != str2[idx]) {
                        if(fixed[k]) return "";

                        // Otherwise assign required character
                        ans[k] = str2[idx];
                    }

                    // Mark this position as fixed
                    fixed[k] = true;
                }
            }
        }

        // Step 2: Handle all 'F' (False) conditions
        // If str1[i] == 'F', substring starting at i must NOT match str2
        for(int i = 0; i < n; i++) {

            if(str1[i] == 'F') {

                bool match = true;

                // Check if current substring matches str2
                for(int k = i, idx = 0; k < i + m; k++, idx++) {
                    if(ans[k] != str2[idx]) {
                        match = false;
                        break;
                    }
                }

                // If it matches, we must break it
                if(match) {

                    bool changed = false;

                    // Try to change from rightmost position
                    for(int k = i + m - 1; k >= i; k--) {
                        int idx = k - i;

                        // Only change if not fixed
                        if(!fixed[k]) {

                            // Replace with any character different from str2[idx]
                            for(char ch = 'a'; ch <= 'z'; ch++) {
                                if(ch != str2[idx]) {
                                    ans[k] = ch;
                                    changed = true;
                                    break;
                                }
                            }
                        }

                        if(changed) break;
                    }

                    // If no change possible → impossible
                    if(!changed) return "";
                }
            }
        }

        return ans;
    }
};

int main() {
    string str1, str2;

    // Input
    cout << "Enter str1 (T/F string): ";
    cin >> str1;

    cout << "Enter str2 (pattern string): ";
    cin >> str2;

    Solution obj;

    // Function call
    string result = obj.generateString(str1, str2);

    // Output
    if(result == "") {
        cout << "No valid string can be generated" << endl;
    } else {
        cout << "Generated String: " << result << endl;
    }

    return 0;
}