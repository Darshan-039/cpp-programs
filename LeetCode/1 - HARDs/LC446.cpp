// Leetcode 446: Arithmetic Slices II - Subsequence



#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        int result = 0;
        // Using vector of maps to be standard-compliant
        vector<unordered_map<long, int>> arr(n);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                // Cast to long to handle potential overflow in subtraction
                long diff = (long)nums[i] - nums[j];

                auto it = arr[j].find(diff);
                int count_at_j = (it == arr[j].end()) ? 0 : it->second;

                // result only increases when a sequence hits length 3 or more
                result += count_at_j;

                // Add count_at_j (existing subsequences) + 1 (new pair {nums[j], nums[i]})
                arr[i][diff] += (count_at_j + 1);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Test Case 1: All same elements
    vector<int> nums1 = {7, 7, 7, 7, 7};
    cout << "Test Case 1 {7,7,7,7,7}: " << sol.numberOfArithmeticSlices(nums1) << " (Expected: 16)" << endl;

    // Test Case 2: Standard Arithmetic Progression
    vector<int> nums2 = {2, 4, 6, 8, 10};
    cout << "Test Case 2 {2,4,6,8,10}: " << sol.numberOfArithmeticSlices(nums2) << " (Expected: 7)" << endl;

    // Test Case 3: Mixed elements
    vector<int> nums3 = {1, 1, 2, 5, 7};
    cout << "Test Case 3 {1,1,2,5,7}: " << sol.numberOfArithmeticSlices(nums3) << " (Expected: 0)" << endl;

    return 0;
}