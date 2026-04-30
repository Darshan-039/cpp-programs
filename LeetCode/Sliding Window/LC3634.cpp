// Leetcode 3634. Minimum Removals to Make Array Valid


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();

        // Sort the array to apply sliding window
        sort(nums.begin(), nums.end());

        int i = 0;        // left pointer
        int maxLen = 0;   // maximum valid subarray length

        // Expand right pointer
        for (int j = 0; j < n; j++) {

            // Shrink window until condition is satisfied
            // nums[j] <= k * nums[i]
            while (nums[j] > (long long)k * nums[i]) {
                i++;
            }

            // Update maximum valid window length
            maxLen = max(maxLen, j - i + 1);
        }

        // Minimum removals = total - longest valid subarray
        return n - maxLen;
    }
};


// Main function
int main() {
    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << "Enter value of k: ";
    cin >> k;

    Solution obj;
    int result = obj.minRemoval(nums, k);

    cout << "Minimum removals required: " << result << endl;

    return 0;
}