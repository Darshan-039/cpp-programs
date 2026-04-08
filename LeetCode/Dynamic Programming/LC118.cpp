// Leetcode 118. Pascal's Triangle




// Approach 1 : Iterative

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> res; // Final result storing all rows

        // 🔹 Generate each row
        for(int i = 0; i < numRows; i++) {

            vector<int> row(i + 1); // Each row has (i+1) elements

            // 🔹 Fill elements of current row
            for(int j = 0; j <= i; j++) {

                // First and last element are always 1
                if(j == 0 || j == i) {
                    row[j] = 1;
                }
                else {
                    // Sum of two elements from previous row
                    row[j] = res[i-1][j-1] + res[i-1][j];
                }
            }

            // 🔹 Add current row to result
            res.push_back(row);
        }

        return res;
    }
};

int main() {
    int numRows;

    cout << "Enter number of rows: ";
    cin >> numRows;

    Solution obj;
    vector<vector<int>> result = obj.generate(numRows);

    cout << "Pascal's Triangle:\n";
    
    for(auto &row : result) {
        for(int x : row) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}







// Approach 2 : Recursive

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans; // stores all rows of Pascal's Triangle

    // 🔹 Recursive function to build nth row
    vector<int> solve(int n) {

        // Base case: first row
        if(n == 1) {
            ans.push_back({1});
            return {1};
        }

        // Get previous row (n-1)
        vector<int> temp = solve(n - 1);

        // Create current row of size n (initialize with 1s)
        vector<int> result(n, 1);

        // Fill middle elements using previous row
        for(int i = 1; i < n - 1; i++) {
            result[i] = temp[i] + temp[i - 1];
        }

        // Store current row
        ans.push_back(result);

        return result;
    }

    vector<vector<int>> generate(int numRows) {
        ans.clear();          // clear previous results (important!)
        solve(numRows);       // build recursively
        return ans;
    }
};

int main() {
    int numRows;

    cout << "Enter number of rows: ";
    cin >> numRows;

    Solution obj;
    vector<vector<int>> result = obj.generate(numRows);

    cout << "Pascal's Triangle:\n";

    for(auto &row : result) {
        for(int x : row) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}