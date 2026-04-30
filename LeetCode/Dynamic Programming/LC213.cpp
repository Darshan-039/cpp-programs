// Leetcode 213. House Robber II


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    // Helper function: Solves House Robber I (linear houses)
    // We use this for two cases in circular arrangement
    int solve(vector<int>& nums, int l, int r) {
        
        int prevPrev = 0;   // dp[i-2]
        int prev = 0;       // dp[i-1]
        
        for(int i = l; i <= r; i++) {
            int skip = prev;                   // Don't rob current house
            int take = nums[i] + prevPrev;     // Rob current house
            
            int temp = max(skip, take);        // Best choice
            
            // Shift values for next iteration
            prevPrev = prev;
            prev = temp;
        }
        
        return prev;   // Maximum money we can rob
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // Edge cases
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        
        // Case 1: Take first house → skip last house
        int take_first_house = solve(nums, 0, n-2);
        
        // Case 2: Skip first house → can take last house
        int skip_first_house = solve(nums, 1, n-1);        
        
        // Return maximum of both cases
        return max(take_first_house, skip_first_house);
    }
};

int main() {
    Solution obj;

    // 🔹 Sample Input
    vector<int> nums = {2, 3, 2};

    // 🔹 Function Call
    int result = obj.rob(nums);

    // 🔹 Output
    cout << "Maximum money that can be robbed: " << result << endl;

    return 0;
}