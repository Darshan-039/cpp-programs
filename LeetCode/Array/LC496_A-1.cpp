// 496. Next Greater Element I

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        for (int x : nums1) {
            int idx = -1;

            for (int i = 0; i < nums2.size(); i++) {
                if (nums2[i] == x) {
                    idx = i;
                    break;
                }
            }

            int nextGreater = -1;

            for (int j = idx + 1; j < nums2.size(); j++) {
                if (nums2[j] > x) {
                    nextGreater = nums2[j];
                    break;
                }
            }

            ans.push_back(nextGreater);
        }

        return ans;
    }
};

int main() {
    // Your own input vectors
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    Solution s;
    vector<int> ans = s.nextGreaterElement(nums1, nums2);

    cout << "Output: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
