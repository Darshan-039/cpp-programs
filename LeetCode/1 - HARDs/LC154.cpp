// Leetcode:- 154. Find Minimum in Rotated Sorted Array II
// {Hard} //

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] < nums[e]) {
                e = mid;    // minimum in left including mid
            }
            else if (nums[mid] > nums[e]) {
                s = mid + 1; // minimum in right
            }
            else {
                // nums[mid] == nums[e] → duplicate, shrink safely
                e--;
            }
        }

        return nums[s];
    }
};

int main() {
    // ⭐ Your own input
    vector<int> nums = {2, 2, 2, 0, 1};

    cout << "Input array: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    Solution obj;
    int ans = obj.findMin(nums);

    cout << "Minimum element = " << ans << endl;

    return 0;
}
