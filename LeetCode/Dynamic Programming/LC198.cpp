// Leetcode 198. House Robber



// Approach - 1
// Recursive Solution with Memoization (Top-Down DP)

// #include <iostream>
// #include <vector>
// #include <algorithm> // For max()
// #include <cstring>   // For memset()

// using namespace std;

// class Solution {
// public:
//     int t[101]; 
//     int n;

//     int solve(vector<int> &nums, int i) {
//         // Base case: If we pass the last house, no more money can be stolen
//         if(i >= n) return 0;

//         // Memoization: Return result if already calculated
//         if(t[i] != -1) return t[i];

//         // Choice 1: Steal from the current house and move to i+2
//         int steal = nums[i] + solve(nums, i+2);
        
//         // Choice 2: Skip the current house and move to i+1
//         int skip = solve(nums, i+1);

//         // Store and return the maximum of the two choices
//         return t[i] = max(steal, skip);
//     }

//     int rob(vector<int>& nums) {
//         n = nums.size();
//         // Initialize the memoization table with -1
//         memset(t, -1, sizeof(t));

//         return solve(nums, 0);
//     }
// };

// int main() {
//     Solution sol;
//     int num_houses;

//     cout << "Enter the number of houses: ";
//     cin >> num_houses;

//     // Safety check for your fixed-size array t[101]
//     if (num_houses > 100) {
//         cout << "Error: This code only supports up to 100 houses." << endl;
//         return 1;
//     }

//     vector<int> houses(num_houses);
//     cout << "Enter the amount of money in each house: " << endl;
//     for (int i = 0; i < num_houses; i++) {
//         cin >> houses[i];
//     }

//     int result = sol.rob(houses);
//     cout << "Maximum money that can be stolen: " << result << endl;

//     return 0;
// }
















// Approach - 2
// Optimal Solution using O(1) space

#include <iostream>
#include <vector>
#include <algorithm> // For max()

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // This approach uses only two variables instead of a full DP array
        int prev2 = 0;         // Represents dp[i-2]
        int prev1 = nums[0];   // Represents dp[i-1]

        for(int i = 1; i < n; i++) {
            // Choice: Skip this house (prev1) OR Rob this house (nums[i] + prev2)
            int current = max(prev1, nums[i] + prev2);

            // Shift variables forward for the next house
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};

int main() {
    Solution sol;
    int n;

    cout << "Enter the number of houses: ";
    if (!(cin >> n) || n < 0) {
        cout << "Please enter a valid non-negative number." << endl;
        return 1;
    }

    if (n == 0) {
        cout << "Maximum money that can be stolen: 0" << endl;
        return 0;
    }

    vector<int> nums(n);
    cout << "Enter the amount of money in each house: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = sol.rob(nums);
    cout << "Maximum money that can be stolen: " << result << endl;

    return 0;
}