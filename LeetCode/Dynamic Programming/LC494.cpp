// Leetcode 494. Target Sum


#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    // DP table:
    // t[i][sum + 10000] stores number of ways
    // i = current index in array
    // sum = current calculated sum
    int t[21][20001];

    // Recursive function to count ways to reach target
    int solve(vector<int>& nums, int target, int i, int sum) {
        // Base case: all numbers processed
        if (i >= nums.size()) {
            return (sum == target) ? 1 : 0;
        }

        // Check if state already computed
        if (t[i][sum + 10000] != -1) {
            return t[i][sum + 10000];
        }

        // Choice 1: Add current number
        int add = solve(nums, target, i + 1, sum + nums[i]);

        // Choice 2: Subtract current number
        int subtract = solve(nums, target, i + 1, sum - nums[i]);

        // Store and return total ways
        return t[i][sum + 10000] = add + subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        // Initialize DP table with -1
        memset(t, -1, sizeof(t));

        // Start recursion from index 0 and sum = 0
        return solve(nums, target, 0, 0);
    }
};

int main() {
    int n, target;

    // Input number of elements
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    // Input array elements
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Input target value
    cout << "Enter target sum: ";
    cin >> target;

    Solution obj;

    // Find and print number of ways
    cout << "Number of ways to reach target: "
         << obj.findTargetSumWays(nums, target) << endl;

    return 0;
}