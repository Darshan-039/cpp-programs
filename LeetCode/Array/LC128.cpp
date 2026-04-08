// Leetcode 128. Longest Consecutive Sequence


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // Edge case: empty array
        if(nums.size() == 0) return 0;

        // 🔹 Store all elements in a set for O(1) lookup
        unordered_set<int> st(nums.begin(), nums.end());

        int ans = 0;

        // 🔹 Iterate through unique elements
        for(int x : st) {

            // Only start counting if x is the start of a sequence
            // (i.e., x-1 is NOT present)
            if(st.count(x - 1)) continue;

            int count = 1;
            int curr = x;

            // Expand the sequence forward
            while(st.count(curr + 1)) {
                curr++;
                count++;
            }

            // Update maximum length
            ans = max(ans, count);
        }

        return ans;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    int result = obj.longestConsecutive(nums);

    cout << "Longest consecutive sequence length: " << result << endl;

    return 0;
}