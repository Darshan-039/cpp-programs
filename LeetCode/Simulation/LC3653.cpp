// Leetcode 3653. XOR After Queries


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Mod value to prevent overflow
    int M = 1e9 + 7;

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        // Process each query
        for(auto &query : queries) {
            int l = query[0];  // starting index
            int r = query[1];  // ending index
            int k = query[2];  // step size
            int v = query[3];  // multiplier

            // Apply operation from l to r with step k
            while(l <= r) {
                nums[l] = (1LL * nums[l] * v) % M; // multiply and take mod
                l += k; // jump by k
            }
        }

        // Compute XOR of final array
        int result = 0;
        for(int &x : nums)
            result ^= x;

        return result;
    }
};

int main() {
    Solution obj;

    // Sample input array
    vector<int> nums = {1, 2, 3, 4, 5};

    // Queries: {l, r, k, v}
    vector<vector<int>> queries = {
        {0, 4, 1, 2}, // multiply all elements by 2
        {1, 3, 2, 3}  // multiply indices 1 and 3 by 3
    };

    // Function call
    int result = obj.xorAfterQueries(nums, queries);

    // Output result
    cout << "Final XOR Result: " << result << endl;

    return 0;
}