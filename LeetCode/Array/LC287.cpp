// Leetcode 287. Find the Duplicate Number


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        // Traverse through the array
        for (int i = 0; i < n; i++) {
            // Get the absolute value because elements may already be marked negative
            int idx = abs(nums[i]);

            // If the value at index (idx - 1) is already negative,
            // it means this number has appeared before → duplicate found
            if (nums[idx - 1] < 0)
                return idx;

            // Mark the visited index as negative
            nums[idx - 1] *= -1;
        }

        // If no duplicate found (though problem guarantees one duplicate)
        return -1;
    }
};

int main() {
    int n;

    // Input size of array
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    // Input array elements
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    // Find and print duplicate number
    cout << "Duplicate element is: " << obj.findDuplicate(nums) << endl;

    return 0;
}