// LeetCode Problem 169: Majority Element


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int maj = 0; // Better than NULL for int types

        for(int x : nums) {
            if(count == 0) {
                count = 1;
                maj = x;
            }
            else if(x == maj) {
                count++;
            }
            else {
                count--;
            }
        }

        return maj;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Majority is 3
    vector<int> nums1 = {3, 2, 3};
    cout << "Input: [3, 2, 3] -> Result: " << sol.majorityElement(nums1) << endl;

    // Test Case 2: Majority is 2
    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    cout << "Input: [2, 2, 1, 1, 1, 2, 2] -> Result: " << sol.majorityElement(nums2) << endl;

    // Test Case 3: Majority is 5
    vector<int> nums3 = {5, 5, 5, 2, 2};
    cout << "Input: [5, 5, 5, 2, 2] -> Result: " << sol.majorityElement(nums3) << endl;

    return 0;
}