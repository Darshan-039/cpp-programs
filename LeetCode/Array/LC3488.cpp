// Leetcode 3488. Minimum Distance to the Same Element II


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<int> ans;

        // Map: value -> list of indices where it appears
        unordered_map<int, vector<int>> mp;

        // Step 1: Store indices of each value
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        // Step 2: Process each query
        for (int x : queries) {

            int val = nums[x];        // value at index x
            auto &vec = mp[val];      // all indices where this value appears
            int m = vec.size();

            // If value appears only once → no other same element
            if (m == 1) {
                ans.push_back(-1);
                continue;
            }

            // Find position of index x in vec using binary search
            int pos = lower_bound(vec.begin(), vec.end(), x) - vec.begin();

            // Previous occurrence (circular)
            int prev = (pos == 0) ? vec[m - 1] : vec[pos - 1];

            // Next occurrence (circular)
            int next = (pos == m - 1) ? vec[0] : vec[pos + 1];

            // Distance to previous (circular distance)
            int d1 = min(abs(x - prev), n - abs(x - prev));

            // Distance to next (circular distance)
            int d2 = min(abs(x - next), n - abs(x - next));

            // Take minimum distance
            ans.push_back(min(d1, d2));
        }

        return ans;
    }
};


int main() {

    Solution obj;

    vector<int> nums = {1, 2, 1, 3, 1, 2};
    vector<int> queries = {0, 1, 2, 3};

    vector<int> result = obj.solveQueries(nums, queries);

    cout << "Output: ";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}