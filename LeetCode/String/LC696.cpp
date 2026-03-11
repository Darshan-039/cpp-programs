// Leetcode 696. Count Binary Substrings



#include <iostream>
#include <string>
#include <algorithm> // For std::min

using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int count = 0;
        int prevGroup = 0; // Length of the previous block of same characters
        int currGroup = 1; // Length of the current block of same characters

        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                currGroup++;
            } else {
                // When we switch from 0 to 1 (or vice versa), 
                // the number of valid substrings is the minimum of the two group sizes.
                count += min(prevGroup, currGroup);
                prevGroup = currGroup;
                currGroup = 1;
            }
        }
        
        // Add the last transition
        return count + min(prevGroup, currGroup);
    }
};

int main() {
    // 1. Create an instance of the Solution class
    Solution sol;

    // 2. Define test inputs
    string input1 = "00110011";
    string input2 = "10101";

    // 3. Call the function and print the results
    cout << "Input: " << input1 << " | Output: " << sol.countBinarySubstrings(input1) << endl;
    cout << "Input: " << input2 << " | Output: " << sol.countBinarySubstrings(input2) << endl;

    return 0;
}