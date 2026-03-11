// Two codes are there 


// // Leetcode 560:- Subarray Sum Equals K 

// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {

//         unordered_map<int, int> mp;

//         // Prefix sum = 0 is counted once initially
//         mp[0] = 1;

//         int ans = 0;   // number of subarrays with sum = k
//         int sum = 0;   // running prefix sum

//         for(int x : nums) {

//             sum += x;  // update prefix sum

//             // Check if (sum - k) has appeared before
//             if(mp.count(sum - k)) {
//                 ans += mp[sum - k];
//             }

//             // Increase frequency of current prefix sum
//             mp[sum]++;
//         }

//         return ans;
//     }
// };

// int main() {
//     int n, k;
//     cout << "Enter number of elements: ";
//     cin >> n;

//     vector<int> nums(n);
    
//     cout << "Enter the array elements: ";
//     for(int i = 0; i < n; i++) {
//         cin >> nums[i];
//     }

//     cout << "Enter k: ";
//     cin >> k;

//     Solution obj;
//     int result = obj.subarraySum(nums, k);

//     cout << "Number of subarrays with sum " << k << " = " << result << endl;

//     return 0;
// }






// For better Understanding







#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        // Prefix Sum vector
        vector<int> PS(n);
        unordered_map<int, int> mp;

        if (n == 0) return 0; // Guard for empty input

        PS[0] = nums[0];
        for(int i = 1; i < n; i++) {
            PS[i] = PS[i-1] + nums[i];
        }

        for(int i = 0; i < n; i++) {
            // Case 1: The prefix sum itself equals k
            if(PS[i] == k) count++;

            // Case 2: Check if (PS[i] - k) exists in the map
            int target = PS[i] - k;
            if(mp.find(target) != mp.end()) {
                count += mp[target];
            }
            
            // Add current prefix sum to map
            mp[PS[i]]++;
        }

        return count;
    }
};

int main() {
    Solution sol;

    // --- INPUT SECTION ---
    vector<int> nums = {1, 2, 3, -1, 2}; 
    int k = 3;
    // ---------------------

    int result = sol.subarraySum(nums, k);

    cout << "Total subarrays with sum " << k << " is: " << result << endl;

    return 0;
}