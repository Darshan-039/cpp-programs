// Leetcode 1493. Longest Subarray of 1's After Deleting One Element




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int count = 0;   // number of zeros in current window
        int ans = 0;     // maximum length of valid subarray
        int i = 0;       // left pointer of sliding window

        // iterate with right pointer j
        for(int j = 0; j < n; j++) {

            // if current element is 0, increase zero count
            if(nums[j] == 0) 
                count++;

            // if more than one zero, shrink window from left
            while(count > 1) {
                if(nums[i] == 0) 
                    count--;
                i++; // move left pointer
            }

            // update answer
            // (j - i) because we must delete one element
            ans = max(ans, j - i);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    // Sample input
    vector<int> nums = {1,1,0,1};

    // Function call
    int result = obj.longestSubarray(nums);

    // Output
    cout << "Longest subarray of 1s after deleting one element: " 
         << result << endl;

    return 0;
}