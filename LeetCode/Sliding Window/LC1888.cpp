// Leetcode 1888. Minimum Number of Flips to Make the Binary String Alternating





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(string s) {

        int n = s.length();

        // result will store the minimum flips required
        int result = INT_MAX;

        // flip1 -> flips required to match pattern "010101..."
        // flip2 -> flips required to match pattern "101010..."
        int flip1 = 0;
        int flip2 = 0;

        // Sliding window pointers
        int i = 0;
        int j = 0;

        // We iterate until 2*n to simulate all rotations
        while(j < 2*n) {

            // Expected characters for both alternating patterns
            char expectedCharS1 = (j % 2) ? '1' : '0';
            char expectedCharS2 = (j % 2) ? '0' : '1';

            // Compare with actual character using modulo (rotation simulation)
            if(s[j % n] != expectedCharS1) flip1++;
            if(s[j % n] != expectedCharS2) flip2++;

            // Maintain window size <= n
            if(j - i + 1 > n) {

                // Remove effect of character leaving the window
                expectedCharS1 = (i % 2) ? '1' : '0';
                expectedCharS2 = (i % 2) ? '0' : '1';

                if(s[i % n] != expectedCharS1) flip1--;
                if(s[i % n] != expectedCharS2) flip2--;

                i++;
            }

            // When window size = n, update result
            if(j - i + 1 == n)
                result = min({result, flip1, flip2});

            j++;
        }

        return result;
    }
};

int main() {

    Solution obj;

    string s;

    cout << "Enter binary string: ";
    cin >> s;

    cout << "Minimum flips required: " << obj.minFlips(s) << endl;

    return 0;
}
