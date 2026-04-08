// Leetcode 2075. Decode the Slanted Ciphertext


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.length();

        // Number of columns in matrix
        int columns = n / rows;

        string ans;

        // 🔹 Traverse diagonals starting from each column of first row
        for(int col = 0; col < columns; col++) {

            // Move diagonally: index increases by (columns + 1)
            for(int j = col; j < n; j += (columns + 1)) {
                ans += encodedText[j];
            }
        }

        // 🔹 Remove trailing spaces from result
        while(!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }

        return ans;
    }
};

int main() {
    string encodedText;
    int rows;

    cout << "Enter encoded text: ";
    getline(cin, encodedText);

    cout << "Enter number of rows: ";
    cin >> rows;

    Solution obj;
    string result = obj.decodeCiphertext(encodedText, rows);

    cout << "Decoded text: " << result << endl;

    return 0;
}