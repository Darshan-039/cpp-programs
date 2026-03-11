// Leetcode 88: Merge Sorted Array


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n - 1; // Last index of nums1
        int i = m - 1;     // Last "filled" element in nums1
        int j = n - 1;     // Last element in nums2

        // Compare elements from the back and move the larger one to the end
        while(i >= 0 && j >= 0) {
            if(nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            }
            else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        // Note: We don't need to check (i >= 0) because they are already in nums1.
        // We only need to check if elements remain in nums2.
        while(j >= 0) {
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }
};

int main() {
    Solution sol;

    cout << "--- LeetCode 88: Merge Sorted Array ---" << endl << endl;

    // Test Case: nums1 has extra space (zeros) at the end to hold nums2
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    cout << "Input nums1: [1, 2, 3, 0, 0, 0], m = 3" << endl;
    cout << "Input nums2: [2, 5, 6], n = 3" << endl;

    sol.merge(nums1, m, nums2, n);

    cout << "Merged array: ";
    for(int x : nums1) {
        cout << x << " ";
    }
    cout << "\n(Expected: 1 2 2 3 5 6)" << endl;

    return 0;
}