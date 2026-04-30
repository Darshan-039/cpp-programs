// Leetcode 1855. Maximum Distance Between a Pair of Values


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int i = 0;   // Pointer for nums1
        int j = 0;   // Pointer for nums2
        int ans = 0; // Store maximum distance

        // Traverse both arrays
        while(i < n1 && j < n2) {

            // If condition fails, move i forward
            // because nums1[i] must be <= nums2[j]
            if(nums1[i] > nums2[j]) {
                i++;
            }
            else {
                // Valid pair found → update max distance
                ans = max(ans, j - i);

                // Try to expand distance by moving j forward
                j++;
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    // 🔹 Sample Input
    vector<int> nums1 = {55, 30, 5, 4, 2};
    vector<int> nums2 = {100, 20, 10, 10, 5};

    // 🔹 Function Call
    int result = obj.maxDistance(nums1, nums2);

    // 🔹 Output
    cout << "Maximum Distance: " << result << endl;

    return 0;
}