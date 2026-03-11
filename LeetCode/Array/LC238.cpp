// Leetcode 238: Product of Array Except Self



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Initialize result array with 1s
        vector<int> ans(n, 1);
        
        // Step 2: Calculate Prefix Products
        // Each index i will store the product of all elements to its left
        for(int i = 1; i < n; i++) {
            ans[i] = nums[i - 1] * ans[i - 1];
        }

        // Step 3: Calculate Suffix Products on the fly
        // Multiply the existing prefix product with the product of all elements to the right
        int suffix = 1;
        for(int i = n - 2; i >= 0; i--) {
            suffix *= nums[i + 1];
            ans[i] *= suffix;
        }

        return ans;
    }
};

// Function to print the vector for display purposes
void printVector(const vector<int>& v) {
    cout << "[";
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << (i == v.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Test Case 1: Standard positive integers
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> res1 = sol.productExceptSelf(nums1);
    cout << "Input:  [1, 2, 3, 4]" << endl;
    cout << "Output: ";
    printVector(res1); // Expected: [24, 12, 8, 6]
    cout << "---" << endl;

    // Test Case 2: Including zeros and negative numbers
    vector<int> nums2 = {-1, 1, 0, -3, 3};
    vector<int> res2 = sol.productExceptSelf(nums2);
    cout << "Input:  [-1, 1, 0, -3, 3]" << endl;
    cout << "Output: ";
    printVector(res2); // Expected: [0, 0, 9, 0, 0]

    return 0;
}