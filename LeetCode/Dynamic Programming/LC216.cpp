// Leetcode 216. Combination Sum III

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> ans; // stores all valid combinations

    // Backtracking function
    void solve(vector<int> &nums, int i, int sum, int k, int n) {

        // If we have selected k numbers
        if(nums.size() == k) {
            // Check if their sum equals target n
            if(sum == n) 
                ans.push_back(nums);
            return;
        }

        // Try numbers from current index to 9
        for(int num = i; num <= 9; num++) {

            // Pruning: stop if sum exceeds target
            if(sum + num > n) break;

            // Choose the current number
            nums.push_back(num);

            // Recurse for next numbers
            solve(nums, num + 1, sum + num, k, n);

            // Backtrack (remove last element)
            nums.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;

        // Start backtracking from number 1
        solve(nums, 1, 0, k, n);

        return ans;
    }
};

int main() {
    Solution obj;

    // Sample input
    int k = 3;  // number of elements
    int n = 7;  // target sum

    // Function call
    vector<vector<int>> result = obj.combinationSum3(k, n);

    // Print all combinations
    cout << "Valid combinations:\n";
    for(auto &vec : result) {
        cout << "[ ";
        for(int x : vec)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}