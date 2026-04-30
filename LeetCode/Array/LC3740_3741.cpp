// Leetcode 3740. Minimum Distance Between Identical Elements in an Array



#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

        // Step 1: Store indices of each number
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        // Step 2: Check each number's index list
        for (auto &it : mp) {
            vector<int> &v = it.second;

            // Need at least 3 occurrences to form a triplet
            if (v.size() < 3) continue;

            // Step 3: Check every consecutive triplet
            for (int i = 0; i + 2 < v.size(); i++) {
                // Distance = 2 * (last index - first index)
                int dist = 2 * (v[i + 2] - v[i]);

                // Update minimum answer
                ans = min(ans, dist);
            }
        }

        // If no valid triplet found, return -1
        return (ans == INT_MAX) ? -1 : ans;
    }
};

int main() {
    int n;

    // Input size of array
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    // Input array elements
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    // Find and print minimum distance
    int result = obj.minimumDistance(nums);

    if (result == -1)
        cout << "No valid triplet found." << endl;
    else
        cout << "Minimum distance is: " << result << endl;

    return 0;
}