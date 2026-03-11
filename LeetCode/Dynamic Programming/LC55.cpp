// Leetcode :- 55  Jump Game
// Top-Down DP (Recursion + Memoization)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int t[10001];

    bool solve(vector<int>& nums, int n, int idx) {
        if (idx >= n - 1) return true;

        if (t[idx] != -1) return t[idx];

        for (int i = 1; i <= nums[idx]; i++) {
            if (idx + i < n && solve(nums, n, idx + i)) {
                return t[idx] = true;
            }
        }

        return t[idx] = false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, n, 0);
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
    bool result = obj.canJump(nums);

    if (result)
        cout << "Can reach last index (true)" << endl;
    else
        cout << "Cannot reach last index (false)" << endl;

    return 0;
}
