// Leetcode 436. Find Right Interval




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // Store {start, index} in set (sorted automatically by start)
        set<pair<int,int>> st;
        for(int i = 0; i < n; i++) {
            st.insert({intervals[i][0], i});
        }

        vector<int> ans;

        for(int i = 0; i < n; i++) {

            int end = intervals[i][1];

            // Find the smallest start >= end
            auto it = st.lower_bound({end, -1});

            if(it != st.end()) {
                // Found valid interval → push its index
                ans.push_back(it->second);
            } else {
                // No such interval exists
                ans.push_back(-1);
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    // 🔹 Sample Input
    vector<vector<int>> intervals = {
        {1, 2},
        {2, 3},
        {3, 4}
    };

    // Call function
    vector<int> result = obj.findRightInterval(intervals);

    // 🔹 Output result
    cout << "Output: ";
    for(int x : result) {
        cout << x << " ";
    }

    return 0;
}