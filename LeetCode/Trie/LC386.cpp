// Leetcode 386. Lexicographical Numbers





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Recursive function to generate numbers in lexicographical order
    void solve(int curr, int n, vector<int> &result) {

        // If current number exceeds n, stop recursion
        if(curr > n) 
            return;

        // Add current number to result
        result.push_back(curr);

        // Try appending digits 0 to 9
        for(int append = 0; append <= 9; append++) {

            // Create new number by appending digit
            int newNum = curr * 10 + append;

            // If new number exceeds n, stop further exploration
            if(newNum > n) 
                return;   // Important: because further digits will also be larger

            // Recursive call
            solve(newNum, n, result);
        }
    }

    vector<int> lexicalOrder(int n) {

        vector<int> result;

        // Start from digits 1 to 9
        for(int startNum = 1; startNum <= 9; startNum++) {
            solve(startNum, n, result);
        }

        return result;
    }
};

int main() {

    int n;
    cout << "Enter value of n: ";
    cin >> n;

    Solution obj;
    vector<int> ans = obj.lexicalOrder(n);

    cout << "Lexicographical Order:\n";
    for(int num : ans) {
        cout << num << " ";
    }

    return 0;
}
