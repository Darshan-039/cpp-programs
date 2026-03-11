// Leetcode :- 90  Subsets II
// Backtracking with duplicate handling

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<int>& nums, vector<int>& ans,
               int idx, vector<vector<int>>& AllSubSets) {

        // Base Case
        if (idx == nums.size()) {
            AllSubSets.push_back(ans);
            return;
        }

        // ---------- Include current element ----------
        ans.push_back(nums[idx]);
        solve(nums, ans, idx + 1, AllSubSets);
        ans.pop_back();

        // ---------- Exclude current element and skip duplicates ----------
        idx++;
        while (idx < nums.size() && nums[idx] == nums[idx - 1]) {
            idx++;
        }
        solve(nums, ans, idx, AllSubSets);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> ans;
        vector<vector<int>> AllSubsets;

        solve(nums, ans, 0, AllSubsets);
        return AllSubsets;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements (may contain duplicates): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    vector<vector<int>> result = obj.subsetsWithDup(nums);

    cout << "\nAll unique subsets:\n";
    for (auto& subset : result) {
        cout << "[ ";
        for (int x : subset) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}
