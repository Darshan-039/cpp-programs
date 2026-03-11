// Leetcode 229: Majority Element II


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        // Candidates and their counters
        int count1 = 0;
        int maj1 = 0;
        int count2 = 0;
        int maj2 = 0;

        // Phase 1: Finding candidates
        for(int x : nums) {
            if(x == maj1 && count1 > 0) {
                count1++;
            }
            else if(x == maj2 && count2 > 0) {
                count2++;
            }
            else if(count1 == 0) {
                maj1 = x;
                count1 = 1;
            }
            else if(count2 == 0) {
                maj2 = x;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }

        // Phase 2: Verifying candidates
        vector<int> result;
        int frq1 = 0;
        int frq2 = 0;
        for(int i : nums) {
            if(i == maj1) frq1++;
            else if(i == maj2) frq2++;
        }

        if(frq1 > n / 3) result.push_back(maj1);
        if(frq2 > n / 3) result.push_back(maj2);

        return result;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Both 3 and 2 appear more than n/3 times (8/3 = 2.66)
    vector<int> nums1 = {3, 2, 3, 2, 1, 3, 2, 5};
    vector<int> res1 = sol.majorityElement(nums1);
    
    cout << "Input: [3, 2, 3, 2, 1, 3, 2, 5]" << endl;
    cout << "Output: [";
    for(int i = 0; i < res1.size(); i++) cout << res1[i] << (i == res1.size() - 1 ? "" : ", ");
    cout << "]" << endl << "---" << endl;

    // Test Case 2: Only 1 appears more than n/3 times
    vector<int> nums2 = {1, 1, 1, 3, 3, 2, 2, 2};
    vector<int> res2 = sol.majorityElement(nums2);
    
    cout << "Input: [1, 1, 1, 3, 3, 2, 2, 2]" << endl;
    cout << "Output: [";
    for(int i = 0; i < res2.size(); i++) cout << res2[i] << (i == res2.size() - 1 ? "" : ", ");
    cout << "]" << endl;

    return 0;
}