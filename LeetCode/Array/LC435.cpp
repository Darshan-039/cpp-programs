// Leetcode 435. Non-overlapping Intervals


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // Step 1: Sort intervals based on start time
        sort(intervals.begin(), intervals.end());

        int i = 0;      // Pointer to current interval
        int j = 1;      // Pointer to next interval
        int count = 0;  // Count of intervals to remove

        // Step 2: Traverse all intervals
        while (j < n) {
            int currentStart = intervals[i][0];
            int currentEnd   = intervals[i][1];

            int nextStart = intervals[j][0];
            int nextEnd   = intervals[j][1];

            // Case 1: No overlap
            if (currentEnd <= nextStart) {
                i = j; // move to next interval
                j++;
            }

            // Case 2: Overlap, keep current interval (smaller end)
            else if (currentEnd <= nextEnd) {
                count++; // remove next interval
                j++;
            }

            // Case 3: Overlap, next interval ends earlier
            else {
                count++; // remove current interval
                i = j;   // keep next interval
                j++;
            }
        }

        return count;
    }
};

int main() {
    int n;

    // Input number of intervals
    cout << "Enter number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));

    // Input intervals
    cout << "Enter intervals (start end):\n";
    for (int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    Solution obj;

    // Output result
    cout << "Minimum intervals to remove: "
         << obj.eraseOverlapIntervals(intervals) << endl;

    return 0;
}