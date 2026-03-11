// Leetcode 926. Flip String to Monotone Increasing






#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int n;

    // Recursive DP function
    // currentIdx → current position in string
    // prev → previous character chosen (0 or 1)
    // t → memo table
    int solve(string &s, int currentIdx, int prev, vector<vector<int>> &t) {

        // base case: reached end of string
        if (currentIdx >= n)
            return 0;

        // if already computed
        if (t[currentIdx][prev] != -1)
            return t[currentIdx][prev];

        int flip = INT_MAX;     // cost if we flip current char
        int no_flip = INT_MAX;  // cost if we don't flip

        // Case 1: current character is '0'
        if (s[currentIdx] == '0') {

            if (prev == 1) {
                // previous was 1 → we must flip 0 to 1
                flip = 1 + solve(s, currentIdx + 1, 1, t);
            }
            else {
                // previous was 0 → we have two choices
                flip = 1 + solve(s, currentIdx + 1, 1, t);   // flip 0→1
                no_flip = solve(s, currentIdx + 1, 0, t);    // keep 0
            }
        }

        // Case 2: current character is '1'
        else {

            if (prev == 1) {
                // previous was 1 → keep 1
                no_flip = solve(s, currentIdx + 1, 1, t);
            }
            else {
                // previous was 0 → two choices
                flip = 1 + solve(s, currentIdx + 1, 0, t);   // flip 1→0
                no_flip = solve(s, currentIdx + 1, 1, t);    // keep 1
            }
        }

        // store result in DP table
        return t[currentIdx][prev] = min(flip, no_flip);
    }

    int minFlipsMonoIncr(string s) {
        n = s.length();

        // DP table: n x 2
        vector<vector<int>> t(n + 1, vector<int>(2, -1));

        return solve(s, 0, 0, t);
    }
};

int main() {

    // Input string
    string s = "00110";

    Solution obj;

    int result = obj.minFlipsMonoIncr(s);

    cout << "Minimum flips to make string monotone increasing: ";
    cout << result;

    return 0;
}










// Approach - 2 (Iterative DP with space optimization)


#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:

    // Function to calculate minimum flips
    int minFlipsMonoIncr(string s) {

        int count_of_ones = 0;  // counts number of '1's seen so far
        int flips = 0;         // minimum flips needed

        for(char ch : s) {

            if(ch == '1') {
                // If current char is '1'
                // increase count of ones
                count_of_ones++;
            }
            else {
                // If current char is '0'
                // we have two choices:
                // 1. Flip this 0 to 1  → flips + 1
                // 2. Flip all previous 1s to 0 → count_of_ones
                // Take minimum of both
                flips = min(flips + 1, count_of_ones);
            }
        }

        return flips;
    }
};

int main() {

    string s;

    // Taking input from user
    cout << "Enter binary string: ";
    cin >> s;

    Solution obj;

    int result = obj.minFlipsMonoIncr(s);

    cout << "Minimum flips to make string monotone increasing: ";
    cout << result;

    return 0;
}