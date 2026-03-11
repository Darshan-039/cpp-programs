// Leetcode 41: First Missing Positive


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            // Use 'while' instead of 'if'
            // We keep swapping until the current nums[i] is in the right place,
            // or it is out of range (<= 0 or > n), or it is a duplicate.
            while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Second pass: find the first index where the number isn't correct
        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) return i + 1;
        }

        // If all numbers from 1 to n are present, the answer is n + 1
        return n + 1;
    }
};

int main() {
    Solution sol;

    vector<int> v1 = {1, 2, 0};
    cout << "Input: {1, 2, 0} | Output: " << sol.firstMissingPositive(v1) << " (Expected: 3)" << endl;

    vector<int> v2 = {3, 4, -1, 1};
    cout << "Input: {3, 4, -1, 1} | Output: " << sol.firstMissingPositive(v2) << " (Expected: 2)" << endl;

    vector<int> v3 = {7, 8, 9, 11, 12};
    cout << "Input: {7, 8, 9, 11, 12} | Output: " << sol.firstMissingPositive(v3) << " (Expected: 1)" << endl;

    return 0;
}