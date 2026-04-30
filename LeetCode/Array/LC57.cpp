// Leetcode 57. Insert Interval


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        int i = 0;

        // Step 1: Add all intervals that come BEFORE newInterval
        // (no overlap, completely on left side)
        while (i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }

        // Step 2: Merge all overlapping intervals with newInterval
        int start = newInterval[0];
        int end = newInterval[1];

        // Overlap condition: intervals[i][0] <= end
        while (i < n && intervals[i][0] <= end) {
            // Expand the merged interval
            start = min(start, intervals[i][0]);
            end = max(end, intervals[i][1]);
            i++;
        }

        // Add the merged interval
        ans.push_back({start, end});

        // Step 3: Add remaining intervals (right side, no overlap)
        while (i < n) {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};


int main() {

    Solution obj;

    vector<vector<int>> intervals = {
        {1, 3},
        {6, 9}
    };

    vector<int> newInterval = {2, 5};

    vector<vector<int>> result = obj.insert(intervals, newInterval);

    cout << "Result: ";
    for (auto &interval : result) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }

    return 0;
}