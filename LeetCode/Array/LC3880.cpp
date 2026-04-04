// Leetcode 3880. Minimum Absolute Difference Between 1s and 2s


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n = nums.size();
        
        int prev = -1;      // stores last seen value (1 or 2)
        int prevIdx = -1;   // stores index of last seen value
        int minDiff = INT_MAX; // stores minimum distance

        for(int i = 0; i < n; i++) {

            // Step 1: Initialize prev if not set yet
            if(prev == -1 && (nums[i] == 1 || nums[i] == 2)) {
                prev = nums[i];
                prevIdx = i;
            }

            // Step 2: Update index if same value repeats
            if(prev == 1 && nums[i] == 1) {
                prevIdx = i;
            }
            else if(prev == 2 && nums[i] == 2) {
                prevIdx = i;
            }

            // Step 3: If we find 1 after 2 OR 2 after 1 → update minDiff
            if(prev == 1 && nums[i] == 2) {
                minDiff = min(minDiff, abs(i - prevIdx));
                prev = 2;
                prevIdx = i;
            }
            else if(prev == 2 && nums[i] == 1) {
                minDiff = min(minDiff, abs(i - prevIdx));
                prev = 1;
                prevIdx = i;
            }
        }

        // Step 4: If no valid pair found
        if(minDiff == INT_MAX) return -1;

        return minDiff;
    }
};

int main() {
    int n;
    
    // Input size
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    // Input elements
    cout << "Enter elements (only 1s and 2s): ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    // Function call
    int result = obj.minAbsoluteDifference(nums);

    // Output result
    if(result == -1) {
        cout << "No valid pair found" << endl;
    } else {
        cout << "Minimum Absolute Difference: " << result << endl;
    }

    return 0;
}