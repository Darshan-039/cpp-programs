// Leetcode 3761. Minimum Mirror Pair Distance


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Function to reverse a number
    int getReverse(int n) {
        int rev = 0;

        while(n > 0) {
            int rem = n % 10;      // get last digit
            rev = rev * 10 + rem;  // build reversed number
            n /= 10;               // remove last digit
        }

        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;
        // key = number (or reversed number)
        // value = index where it appeared

        int ans = INT_MAX;

        for(int i = 0; i < n; i++) {

            // If current number already exists in map
            // means we have seen its reverse earlier
            if(mp.count(nums[i])) {
                ans = min(ans, i - mp[nums[i]]);
            }

            // Store reverse of current number with index
            mp[getReverse(nums[i])] = i;
        }

        // If no such pair found → return -1
        return ans == INT_MAX ? -1 : ans;
    }
};

int main() {

    // Example input
    vector<int> nums = {12, 34, 21, 43, 56};

    Solution obj;
    int result = obj.minMirrorPairDistance(nums);

    cout << "Minimum Mirror Pair Distance: " << result << endl;

    return 0;
}