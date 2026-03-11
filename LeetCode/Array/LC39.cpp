#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(int index, int target, vector<int>& candidates) {
        // BASE CASE 1: Successfully reached the target
        if(target == 0) {
            ans.push_back(temp);
            return;
        }

        // BASE CASE 2: Sum exceeded target OR ran out of elements
        if(target < 0 || index == candidates.size()) {
            return;
        }

        // --- OPTION 1: INCLUDE candidates[index] ---
        // We add the current element to our path
        temp.push_back(candidates[index]);
        
        // Recursive call: Stay at the SAME index because we can reuse elements
        // We reduce the target by the value we just picked
        solve(index, target - candidates[index], candidates);

        // --- BACKTRACK ---
        // Remove the last element added to explore the "exclude" branch
        temp.pop_back();

        // --- OPTION 2: EXCLUDE candidates[index] ---
        // Skip the current element and move to the next index
        // Target remains the same
        solve(index + 1, target, candidates);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear(); // Clear globally declared ans for multiple calls
        temp.clear();
        solve(0, target, candidates);
        return ans;
    }
};

// Main function to provide input and test the code
int main() {
    Solution sol;

    // Input: Candidates and Target
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    cout << "Target: " << target << "\nCandidates: ";
    for(int c : candidates) cout << c << " ";
    cout << "\n\nResulting Combinations:\n";

    // Call the function
    vector<vector<int>> result = sol.combinationSum(candidates, target);

    // Print the output
    if (result.empty()) {
        cout << "No combinations found." << endl;
    } else {
        for (const auto& combination : result) {
            cout << "[ ";
            for (int num : combination) {
                cout << num << " ";
            }
            cout << "]" << endl;
        }
    }

    return 0;
}