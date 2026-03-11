// Leetcode :- 162 Find Peak Element

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s = 0, e = nums.size() - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] < nums[mid + 1]) {
                s = mid + 1;  // Peak is in right half
            } 
            else {
                e = mid;      // Peak is in left half (including mid)
            }
        }
        return s;  // s == e → peak index
    }
};

int main() {
    // ⭐ Your own input
    vector<int> nums = {1, 2, 3, 1};

    Solution obj;
    int peakIndex = obj.findPeakElement(nums);

    cout << "Input: ";
    for (int x : nums) cout << x << " ";
    cout << "\nPeak Index = " << peakIndex;
    cout << "\nPeak Value = " << nums[peakIndex] << endl;

    return 0;
}
