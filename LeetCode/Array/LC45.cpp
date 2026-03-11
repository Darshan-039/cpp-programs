// Leetcode 45. Jump Game II



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0; // Already at the end

        int jumps = 0;
        int current_end = 0;
        int farthest = 0;

        for (int i = 0; i < n - 1; i++) {
            // Update the farthest point we can reach from index i
            farthest = max(farthest, i + nums[i]);

            // If we have reached the end of the range of our current jump
            if (i == current_end) {
                jumps++;
                current_end = farthest;
                
                // Optimization: If we can already reach the last index, stop
                if (current_end >= n - 1) break;
            }
        }
        return jumps;
    }
};

int main() {
    Solution sol;
    
    // Example Input 1: [2, 3, 1, 1, 4]
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Input: [2, 3, 1, 1, 4] -> Min Jumps: " << sol.jump(nums1) << endl;

    // Example Input 2: [2, 3, 0, 1, 4]
    vector<int> nums2 = {2, 3, 0, 1, 4};
    cout << "Input: [2, 3, 0, 1, 4] -> Min Jumps: " << sol.jump(nums2) << endl;

    return 0;
}