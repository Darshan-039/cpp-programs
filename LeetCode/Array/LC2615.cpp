// Leetcode 2615. Sum of Distances


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;

    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();

        vector<ll> ans(n, 0);

        // Maps to store:
        // indexSum[val]  -> sum of indices where 'val' appeared
        // indexCount[val] -> frequency of 'val'
        unordered_map<int, ll> indexSum;
        unordered_map<int, ll> indexCount;

        // Pass 1: Left to Right
        // Calculate contribution from previous occurrences
        for (int i = 0; i < n; i++) {
            ll sum = indexSum[nums[i]];
            ll freq = indexCount[nums[i]];

            // Contribution = freq * i - sum_of_indices
            ans[i] += freq * i - sum;

            // Update maps
            indexSum[nums[i]] += i;
            indexCount[nums[i]] += 1;
        }

        // Clear maps for second pass
        indexSum.clear();
        indexCount.clear();

        // Pass 2: Right to Left
        // Calculate contribution from future occurrences
        for (int i = n - 1; i >= 0; i--) {
            ll sum = indexSum[nums[i]];
            ll freq = indexCount[nums[i]];

            // Contribution = sum_of_indices - freq * i
            ans[i] += sum - freq * i;

            // Update maps
            indexSum[nums[i]] += i;
            indexCount[nums[i]] += 1;
        }

        return ans;
    }
};


// Main function
int main() {
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    Solution obj;
    vector<long long> result = obj.distance(nums);

    cout << "Distance array:\n";
    for (auto val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}