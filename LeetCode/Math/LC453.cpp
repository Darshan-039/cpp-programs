// Leetcode :- 453  Minimum Moves to Equal Array Elements

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long sum = 0;
        int mini = INT_MAX;
        int n = nums.size();

        for (int x : nums) {
            // Sum of all elements
            sum += x;
            // Find minimum element
            if (x < mini) {
                mini = x;
            }
        }

        // Total moves = sum - (minimum × n)
        long long moves = sum - (long long)mini * n;

        // Result fits in 32-bit integer
        return (int)moves;
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
    int result = obj.minMoves(nums);

    cout << "Minimum moves = " << result << endl;

    return 0;
}
