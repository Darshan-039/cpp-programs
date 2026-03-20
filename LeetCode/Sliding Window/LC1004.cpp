// Leetcode 1004. Max Consecutive Ones III




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int i = 0;          // left pointer of window
        int zeros = 0;      // count of zeros in current window
        int ans = 0;        // maximum length of valid subarray

        // expand window using right pointer j
        for(int j = 0; j < nums.size(); j++) {

            // if current element is 0, increase zero count
            if(nums[j] == 0)
                zeros++;

            // if zeros exceed k, shrink window from left
            while(zeros > k) {
                if(nums[i] == 0)
                    zeros--;
                i++; // move left pointer
            }

            // update maximum window size
            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    // Sample input
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

    // Function call
    int result = obj.longestOnes(nums, k);

    // Output
    cout << "Longest subarray length with at most " << k 
         << " zero(s): " << result << endl;

    return 0;
}