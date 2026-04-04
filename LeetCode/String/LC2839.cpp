// Leetcode 2839. Check if Strings Can be Made Equal With Operations II



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        // Step 1: Take characters at even indices (0, 2)
        vector<char> even1 = {s1[0], s1[2]};
        vector<char> even2 = {s2[0], s2[2]};
        
        // Step 2: Take characters at odd indices (1, 3)
        vector<char> odd1 = {s1[1], s1[3]};
        vector<char> odd2 = {s2[1], s2[3]};
        
        // Step 3: Sort both even and odd index characters
        sort(even1.begin(), even1.end());
        sort(even2.begin(), even2.end());
        sort(odd1.begin(), odd1.end());
        sort(odd2.begin(), odd2.end());
        
        // Step 4: Compare sorted groups
        // If both even and odd groups match, return true
        return (even1 == even2) && (odd1 == odd2);
    }
};

int main() {
    string s1, s2;
    
    // Taking input from user
    cout << "Enter string s1 (length 4): ";
    cin >> s1;
    
    cout << "Enter string s2 (length 4): ";
    cin >> s2;
    
    Solution obj;
    
    // Calling function
    bool result = obj.canBeEqual(s1, s2);
    
    // Output result
    if(result) {
        cout << "True (Strings can be made equal)" << endl;
    } else {
        cout << "False (Strings cannot be made equal)" << endl;
    }
    
    return 0;
}