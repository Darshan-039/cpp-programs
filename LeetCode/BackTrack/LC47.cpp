// Leetcode Problem 47: Permutations II




// Approach - 1 Backtracking with Frequency Map
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> ans;

    // Pass mp by reference (&) to avoid expensive copying at every recursion level
    void solve(unordered_map<int, int>& mp, vector<int>& temp) {
        if (temp.size() == n) {
            ans.push_back(temp);
            return;
        }

        for (auto& [num, count] : mp) {
            if (count == 0) continue;

            // Action
            temp.push_back(num);
            mp[num]--;

            // Recurse
            solve(mp, temp);

            // Backtrack
            mp[num]++;
            temp.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        ans.clear();
        unordered_map<int, int> mp;
        for (int num : nums) mp[num]++;

        vector<int> temp;
        solve(mp, temp);

        return ans;
    }
};

int main() {
    Solution sol;
    
    // --- INPUT DATA ---
    vector<int> nums = {1, 1, 2};

    // Function Call
    vector<vector<int>> result = sol.permuteUnique(nums);

    // Printing the output
    cout << "Unique Permutations:" << endl;
    for (const auto& row : result) {
        cout << "[ ";
        for (int x : row) {
            cout << x << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}














// Approach - 2 Backtracking with Swapping
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm> // for swap

using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> ans;

    void solve(vector<int> &nums, int index) {
        if (index == n) {
            ans.push_back(nums);
            return;
        }

        // Set to track elements already used at THIS specific 'index' position
        unordered_set<int> st;

        for (int i = index; i < n; i++) {
            // If we have already placed this number at this index in a 
            // previous branch of this loop, skip it to avoid duplicates.
            if (st.find(nums[i]) != st.end()) continue;

            st.insert(nums[i]);
            
            // Swap to place the chosen element at the current 'index'
            swap(nums[i], nums[index]);
            
            // Move to the next position
            solve(nums, index + 1);
            
            // Backtrack: restore the original order for the next iteration of the loop
            swap(nums[i], nums[index]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        ans.clear(); // Clear previous results if any
        solve(nums, 0);
        return ans;
    }
};

int main() {
    Solution sol;

    // --- INPUT DATA ---
    vector<int> nums = {1, 1, 2};

    // Execute the function
    vector<vector<int>> result = sol.permuteUnique(nums);

    // --- PRINT OUTPUT ---
    cout << "Unique Permutations using Swap Method:" << endl;
    for (const auto& row : result) {
        cout << "[ ";
        for (int x : row) {
            cout << x << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}