// Leetcode 1877. Minimize Maximum Pair Sum in Array



#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        // Sort the array to use the greedy two-pointer approach
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int i = 0;
        int j = n - 1;

        int ans = INT_MIN;

        // Pair the smallest (i) with the largest (j)
        while(i < j) {
 
            ans = max(ans, nums[i] + nums[j]);
            i++;
            j--;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Sample Input 1
    vector<int> nums1 = {3, 5, 2, 3};
    // Pairs: (2,5), (3,3) -> max sum is 7
    cout << "Input: {3, 5, 2, 3} | Output: " << sol.minPairSum(nums1) << endl;

    // Sample Input 2
    vector<int> nums2 = {3, 5, 4, 2, 4, 6};
    // Pairs: (2,6), (3,5), (4,4) -> max sum is 8
    cout << "Input: {3, 5, 4, 2, 4, 6} | Output: " << sol.minPairSum(nums2) << endl;

    return 0;
}