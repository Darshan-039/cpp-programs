#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    void solve(int start, int n, int k, vector<int> &temp) {
        // Base Case: If we have picked k elements, add to answer
        if(temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        // Optimization: If remaining elements aren't enough to reach k, stop
        // if(start > n) return; 

        for(int i = start; i <= n; i++) {
            temp.push_back(i);
            solve(i + 1, n, k, temp); // Recurse for the next element
            temp.pop_back();          // Backtrack
        }
    }

    vector<vector<int>> combine(int n, int k) {
        ans.clear(); // Clear results for fresh run
        vector<int> temp;
        solve(1, n, k, temp);
        return ans;
    }
};

int main() {
    Solution sol;
    int n, k;

    // --- Input Handling ---
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter k: ";
    cin >> k;

    // Process the logic
    vector<vector<int>> result = sol.combine(n, k);

    // --- Output Handling ---
    cout << "\nThe possible combinations are:\n";
    cout << "[ " << endl;
    for (const auto& combination : result) {
        cout << "  [ ";
        for (int i = 0; i < combination.size(); i++) {
            cout << combination[i] << (i == combination.size() - 1 ? "" : ", ");
        }
        cout << " ]" << endl;
    }
    cout << "]" << endl;

    return 0;
}