// Leetcode 3833. Count of Dominant Indices



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int cnt = 0;
        long long suffixSum = 0;

        for (int i = n - 1; i >= 0; i--) {
            int elementsToRight = n - 1 - i;

            if (elementsToRight > 0) {
                // Checking if nums[i] is greater than the average of elements to its right
                if (nums[i] > (double)suffixSum / elementsToRight) {
                    cnt++;
                }
            }
            suffixSum += nums[i];
        }

        return cnt;
    }
};

int main() {
    Solution sol;

    // Example Input 1
    vector<int> nums1 = {10, 2, 3, 4, 1};
    cout << "Test Case 1: " << sol.dominantIndices(nums1) << endl; // Expected: 3 
    // (4 > 1, 3 > (4+1)/2, 10 > (2+3+4+1)/4)

    // Example Input 2
    vector<int> nums2 = {1, 5, 2};
    cout << "Test Case 2: " << sol.dominantIndices(nums2) << endl; // Expected: 1 
    // (5 > 2, but 1 is not > (5+2)/2)

    return 0;
}