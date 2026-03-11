// Leetcode Problem 40: Combination Sum II



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> result;

    // Fixed the extra comma in the parameter list from your snippet
    void solve(vector<int>& candidates, int target, vector<int> &curr, int idx) {
        if(target < 0) return;

        if(target == 0) {
            result.push_back(curr);
            return;
        }

        for(int i = idx; i < n; i++) {
            // Skip duplicates at the same recursive level
            if(i > idx && candidates[i] == candidates[i-1]) continue;

            // Optional Optimization: If current element is too large, 
            // no need to check the rest since candidates are sorted.
            if(candidates[i] > target) break; 

            curr.push_back(candidates[i]);      // DO
            solve(candidates, target - candidates[i], curr, i + 1); // EXPLORE
            curr.pop_back();                   // UNDO
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        result.clear(); // Clear result for multiple calls
        vector<int> curr;

        sort(candidates.begin(), candidates.end());

        solve(candidates, target, curr, 0);

        return result; 
    }
};

int main() {
    Solution sol;
    
    // Define input here
    vector<int> candidates = {2, 5, 2, 1, 2};
    int target = 5;

    vector<vector<int>> res = sol.combinationSum2(candidates, target);

    // Print the output
    cout << "Combinations for target " << target << ":" << endl;
    cout << "[" << endl;
    for (const auto& vec : res) {
        cout << "  [";
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << (i == vec.size() - 1 ? "" : ", ");
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;

    return 0;
}