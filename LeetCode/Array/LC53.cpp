// Leetcode Problem 53: Maximum Subarray




#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // Required for INT_MIN

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // If the array is empty, technically there is no sum
        if (nums.empty()) return 0;

        int cSum = 0;
        int maxSum = INT_MIN;

        for(int x : nums) {
            cSum += x;
            
            // Update maxSum first so we can handle arrays 
            // consisting entirely of negative numbers
            maxSum = max(maxSum, cSum);

            // If the current running sum drops below zero, 
            // it's better to restart from the next element
            if(cSum < 0) cSum = 0;
        }

        return maxSum;
    }
};

int main() {
    Solution sol;

    // Sample Input: The max subarray here is [4, -1, 2, 1], which sums to 6.
    vector<int> input = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    int result = sol.maxSubArray(input);

    // Output the result
    cout << "Maximum Subarray Sum: " << result << endl;

    // Another example: All negative numbers
    vector<int> negativeInput = {-5, -1, -8, -2};
    cout << "Maximum Subarray Sum (All Negatives): " << sol.maxSubArray(negativeInput) << endl;

    return 0;
}