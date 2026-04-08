// Leetcode 152. Maximum Product Subarray


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int prefix = 1;   // Left to right product
        int suffix = 1;   // Right to left product
        int ans = INT_MIN; // Stores maximum product

        for(int i = 0; i < n; i++) {

            // If product becomes 0, reset to 1
            // because multiplying further will always give 0
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;

            // Calculate prefix product (left to right)
            prefix *= nums[i];

            // Calculate suffix product (right to left)
            suffix *= nums[n - i - 1];

            // Take maximum of current prefix, suffix, and answer
            ans = max({ans, prefix, suffix});
        }

        return ans;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    int result = obj.maxProduct(nums);

    cout << "Maximum Product Subarray: " << result << endl;

    return 0;
}