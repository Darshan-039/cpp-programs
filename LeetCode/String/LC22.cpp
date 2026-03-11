// Leetcode :- 22 Generate Parentheses

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> result;   // Stores all valid combinations

    // Function to check if parentheses string is valid
    bool isvalid(string& str) {
        int count = 0;

        for(char ch : str) {
            if(ch == '(')
                count++;       // Opening bracket increases count
            else {
                count--;       // Closing bracket decreases count
                if(count < 0)  // If more closing before opening -> invalid
                    return false;
            }
        }

        return count == 0;  // Valid only if completely balanced
    }

    // Backtracking function to generate all possible sequences
    void solve(string& curr, int n) {

        // If length becomes 2*n -> full parentheses string formed
        if(curr.length() == 2*n) {

            // If valid parentheses, store it
            if(isvalid(curr)) {
                result.push_back(curr);
            }
            return;
        }

        // Try adding '('
        curr.push_back('(');
        solve(curr, n);
        curr.pop_back();  // backtrack

        // Try adding ')'
        curr.push_back(')');
        solve(curr, n);
        curr.pop_back();  // backtrack
    }

    vector<string> generateParenthesis(int n) {
        string curr = "";
        solve(curr, n);
        return result;
    }
};

// MAIN FUNCTION TO TAKE INPUT AND PRINT RESULT
int main() {
    Solution obj;

    int n;
    cout << "Enter n (number of parentheses pairs): ";
    cin >> n;

    vector<string> ans = obj.generateParenthesis(n);

    cout << "\nGenerated Parentheses:\n";
    for(string s : ans) {
        cout << s << endl;
    }
}
