// LeetCode 442: Find All Duplicates in an Array



#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {
            // Use the absolute value to find the corresponding index
            int num = abs(nums[i]);
            int idx = num - 1;

            // If the value at idx is already negative, we've seen 'num' before
            if(nums[idx] < 0) {
                ans.push_back(num);
            }
            else {
                // Otherwise, mark it as seen by making it negative
                nums[idx] *= -1;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    cout << "--- LeetCode 442: Find All Duplicates in an Array ---" << endl << endl;

    // Test Case 1
    vector<int> nums1 = {4, 3, 2, 7, 8, 2, 3, 1};
    cout << "Input 1: [4, 3, 2, 7, 8, 2, 3, 1]" << endl;
    vector<int> result1 = sol.findDuplicates(nums1);
    cout << "Duplicates: ";
    for(int x : result1) cout << x << " "; 
    cout << "\n(Expected: 2 3)" << endl << endl;

    // Test Case 2
    vector<int> nums2 = {1, 1, 2};
    cout << "Input 2: [1, 1, 2]" << endl;
    vector<int> result2 = sol.findDuplicates(nums2);
    cout << "Duplicates: ";
    for(int x : result2) cout << x << " ";
    cout << "\n(Expected: 1)" << endl << endl;

    // Test Case 3
    vector<int> nums3 = {1};
    cout << "Input 3: [1]" << endl;
    vector<int> result3 = sol.findDuplicates(nums3);
    cout << "Duplicates: " << (result3.empty() ? "None" : "") << endl;

    return 0;
}