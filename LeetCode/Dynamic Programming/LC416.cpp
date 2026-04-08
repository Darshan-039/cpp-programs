// Leetcode 416. Partition Equal Subset Sum


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // DP table: t[i][x] means whether we can form sum 'x' using elements from index i
    int t[201][20001];

    bool solve(vector<int>& nums, int i, int x) {
        // If required sum becomes 0 → subset found
        if(x == 0) return true;

        // If we reach end of array and sum is not 0 → not possible
        if(i >= nums.size()) return false;

        // If already computed, return stored result
        if(t[i][x] != -1) return t[i][x];

        bool take = false;

        // Option 1: Take current element (only if it doesn't exceed sum)
        if(nums[i] <= x)
            take = solve(nums, i + 1, x - nums[i]);

        // Option 2: Skip current element
        bool not_take = solve(nums, i + 1, x);

        // Store and return result
        return t[i][x] = take || not_take;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        // Total sum of array
        int S = accumulate(begin(nums), end(nums), 0);

        // If total sum is odd → cannot divide into equal subsets
        if(S % 2 != 0) return false;

        // Initialize DP table with -1 (unvisited)
        memset(t, -1, sizeof(t));

        // Target sum for each subset
        int x = S / 2;

        // Check if subset with sum x exists
        return solve(nums, 0, x);
    }
};

int main() {
    Solution obj;

    // Sample input
    vector<int> nums = {1, 5, 11, 5};

    // Function call
    bool result = obj.canPartition(nums);

    // Output result
    if(result)
        cout << "Can be partitioned into equal subsets ✅" << endl;
    else
        cout << "Cannot be partitioned ❌" << endl;

    return 0;
}