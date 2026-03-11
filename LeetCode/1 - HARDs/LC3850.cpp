// Leetcode 3850. Count the Number of Valid Sequences




#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
    int countSequences(vector<int>& nums, long long k) {
        int n = nums.size();

        unordered_map<double, long long> dp;
        dp[1.0] = 1;

        for(int x : nums) {
            unordered_map<double, long long> next_dp;

            for (auto const& [val, count] : dp) {
                // Choice 1: Multiply
                next_dp[val * x] += count;

                // Choice 2: Divide
                next_dp[val / (double)x] += count;

                // Choice 3: Leave unchanged
                next_dp[val] += count;
            }
            dp = next_dp;
        }

        long long totalCount = 0;
        for (auto const& [val, count] : dp) {
            if (abs(val - k) < 1e-9) {
                totalCount += count;
            }
        }

        return totalCount;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    long long k;
    cout << "Enter target value k: ";
    cin >> k;

    Solution obj;
    int result = obj.countSequences(nums, k);

    cout << "Number of valid sequences = " << result << endl;

    return 0;
}