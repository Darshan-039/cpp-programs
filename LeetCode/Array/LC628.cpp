// Leetcode :- 628  Maximum Product of Three Numbers

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        long max1 = LONG_MIN, max2 = LONG_MIN, max3 = LONG_MIN;
        long min1 = LONG_MAX, min2 = LONG_MAX;

        for (int x : nums) {
            // Track three largest numbers
            if (x > max1) {
                max3 = max2;
                max2 = max1;
                max1 = x;
            }
            else if (x > max2) {
                max3 = max2;
                max2 = x;
            }
            else if (x > max3) {
                max3 = x;
            }

            // Track two smallest numbers
            if (x < min1) {
                min2 = min1;
                min1 = x;
            }
            else if (x < min2) {
                min2 = x;
            }
        }

        long prod1 = max1 * max2 * max3;
        long prod2 = max1 * min1 * min2;

        return max(prod1, prod2);
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    cout << "Maximum Product = " << obj.maximumProduct(nums);

    return 0;
}
