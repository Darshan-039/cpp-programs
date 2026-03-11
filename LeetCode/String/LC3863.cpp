// Leetcode 3863. Minimum Operations to Sort a String




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s) {

        int n = s.size();

        // Create a sorted version of the string
        string t = s;
        sort(t.begin(), t.end());

        // If already sorted, no operation needed
        if(t == s) return 0;

        // If length = 2 and not sorted, we cannot sort entire string
        if(n == 2) return -1;

        // Find smallest and largest characters in the string
        char mini = *min_element(s.begin(), s.end());
        char maxi = *max_element(s.begin(), s.end());

        // If smallest is already at beginning OR largest already at end
        // we can fix the string in one operation
        if(s[0] == mini || s[n-1] == maxi) return 1;

        bool mnInPrefix = false;
        bool mxInSuffix = false;

        // Check if minimum element exists somewhere in prefix
        for(int i = 0; i < n-1; i++)
            if(s[i] == mini)
                mnInPrefix = true;

        // Check if maximum element exists somewhere in suffix
        for(int i = n-1; i > 0; i--)
            if(s[i] == maxi)
                mxInSuffix = true;

        // If neither condition holds, we need 3 operations
        if(!mnInPrefix && !mxInSuffix) return 3;

        // Otherwise answer is 2
        return 2;
    }
};

int main() {

    Solution obj;

    string s;

    cout << "Enter string: ";
    cin >> s;

    cout << "Minimum operations: " << obj.minOperations(s) << endl;

    return 0;
}