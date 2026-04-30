// Leetcode 452. Minimum Number of Arrows to Burst Balloons


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();

        // Step 1: Sort balloons based on starting point
        sort(points.begin(), points.end());

        // Store current overlapping interval
        vector<int> prev = points[0];

        // At least one arrow is needed for first balloon
        int count = 1;

        // Step 2: Traverse remaining balloons
        for (int i = 1; i < n; i++) {
            int currStart = points[i][0];
            int currEnd   = points[i][1];

            int prevStart = prev[0];
            int prevEnd   = prev[1];

            // Case 1: No overlap → need new arrow
            if (currStart > prevEnd) {
                count++;
                prev = points[i];
            }
            else {
                // Case 2: Overlap exists
                // Update overlapping range
                prev[0] = max(prevStart, currStart);
                prev[1] = min(prevEnd, currEnd);
            }
        }

        return count;
    }
};

int main() {
    int n;

    // Input number of balloons
    cout << "Enter number of balloons: ";
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));

    // Input balloon intervals
    cout << "Enter balloon intervals (start end):\n";
    for (int i = 0; i < n; i++) {
        cin >> points[i][0] >> points[i][1];
    }

    Solution obj;

    // Output minimum arrows required
    cout << "Minimum arrows required: "
         << obj.findMinArrowShots(points) << endl;

    return 0;
}