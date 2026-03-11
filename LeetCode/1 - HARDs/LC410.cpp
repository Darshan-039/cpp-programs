// Leetcode - 410: Split Array Largest Sum


#include <iostream>
#include <vector>
#include <numeric> // For accumulate
#include <algorithm> // For *max_element

using namespace std;

class Solution {
private:
    bool isPossible(vector<int>& nums, int n, int k, int mid) {
        int tSum = 0;
        int partition = 1;

        for(int i = 0; i < n; i++) {
            if(tSum + nums[i] <= mid) {
                tSum += nums[i];
            } else {
                partition++;
                // If partitions exceed k or a single element is larger than mid
                if(partition > k || nums[i] > mid) return false;
                tSum = nums[i];
            }
        }
        return true;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        // The range for binary search:
        // Start (s) should be the maximum element in the array
        // End (e) should be the sum of all elements
        int maxElement = 0;
        int sum = 0;
        for(int x : nums) {
            sum += x;
            maxElement = max(maxElement, x);
        }

        int s = maxElement; // Efficiency tip: s can start at max(nums)
        int e = sum;
        int ans = sum;

        while(s <= e) {
            int mid = s + (e - s) / 2;

            if(isPossible(nums, n, k, mid)) {
                ans = mid;
                e = mid - 1; // Try to find a smaller "maximum sum"
            } else {
                s = mid + 1; // Need a larger capacity
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {7, 2, 5, 10, 8};
    int k1 = 2;
    // Explanation: Split into [7,2,5] and [10,8]. Max sum is 18.
    cout << "Test Case 1: " << sol.splitArray(nums1, k1) << " (Expected: 18)" << endl;

    // Test Case 2
    vector<int> nums2 = {1, 2, 3, 4, 5};
    int k2 = 2;
    // Explanation: Split into [1,2,3] and [4,5]. Max sum is 9.
    cout << "Test Case 2: " << sol.splitArray(nums2, k2) << " (Expected: 9)" << endl;

    // Test Case 3
    vector<int> nums3 = {1, 4, 4};
    int k3 = 3;
    // Explanation: Split into [1], [4], [4]. Max sum is 4.
    cout << "Test Case 3: " << sol.splitArray(nums3, k3) << " (Expected: 4)" << endl;

    return 0;
}