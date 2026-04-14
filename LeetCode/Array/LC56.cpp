// Leetcode 56. Merge Intervals


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // Step 1: Get number of intervals
        int n = intervals.size();

        // Step 2: Sort intervals based on starting time
        sort(intervals.begin(), intervals.end());

        // Step 3: Result vector to store merged intervals
        vector<vector<int>> ans;

        int i = 0;

        // Step 4: Traverse all intervals
        while(i < n) {

            // Take current interval start and end
            int x = intervals[i][0];
            int y = intervals[i][1];

            // Step 5: Merge overlapping intervals
            while(i + 1 < n && intervals[i + 1][0] <= y) {
                i++;

                // Update the end to maximum end value
                y = max(y, intervals[i][1]);
            }

            // Step 6: Push merged interval
            ans.push_back({x, y});

            // Move to next interval
            i++;
        }

        // Step 7: Return result
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));

    cout << "Enter intervals (start end):\n";
    for(int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    Solution obj;
    vector<vector<int>> result = obj.merge(intervals);

    cout << "\nMerged Intervals:\n";
    for(auto &it : result) {
        cout << it[0] << " " << it[1] << endl;
    }

    return 0;
}