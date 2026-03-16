// Leetcode 3835. Count of Subarrays With Cost Less Than or Equal to K



#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        // Deques to store indices for min and max tracking in O(1)
        deque<int> maxi, mini;
        long long ans = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            // Maintain monotonic property for minimums
            while (!mini.empty() && nums[mini.back()] >= nums[right]) mini.pop_back();
            // Maintain monotonic property for maximums
            while (!maxi.empty() && nums[maxi.back()] <= nums[right]) maxi.pop_back();
            
            maxi.push_back(right);
            mini.push_back(right);

            // Shrink window from the left if the condition cost <= k is violated
            while (left <= right) {
                // Formula: (Max - Min) * Length
                long long cost = (long long)(nums[maxi.front()] - nums[mini.front()]) * (right - left + 1);
                if (cost <= k) break;

                left++;
                // Clean up indices that are no longer in the window
                while (!maxi.empty() && maxi.front() < left) maxi.pop_front();
                while (!mini.empty() && mini.front() < left) mini.pop_front();
            }

            // All subarrays ending at 'right' and starting from 'left' to 'right' are valid
            ans += (right - left + 1);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1, 3, 2};
    long long k1 = 2;
    // Valid: [1], [3], [2], [1,3] (3-1)*2=4 > 2 (Invalid), [3,2] (3-2)*2=2 (Valid)
    cout << "Test 1 Result: " << sol.countSubarrays(nums1, k1) << " (Expected: 5)" << endl;

    // Test Case 2: Constant values (Cost always 0)
    vector<int> nums2 = {5, 5, 5, 5};
    long long k2 = 10;
    // All subarrays valid: (4*5)/2 = 10
    cout << "Test 2 Result: " << sol.countSubarrays(nums2, k2) << " (Expected: 10)" << endl;

    // Test Case 3: Wide spread
    vector<int> nums3 = {1, 10, 1};
    long long k3 = 5;
    // Valid: [1], [10], [1]
    cout << "Test 3 Result: " << sol.countSubarrays(nums3, k3) << " (Expected: 3)" << endl;

    return 0;
}