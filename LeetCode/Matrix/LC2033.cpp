// Leetcode 2033. Minimum Operations to Make a Uni-Value Grid


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    int minOperations(vector<vector<int>>& grid, int x) {

        // Store all grid elements in 1D vector
        vector<int> nums;

        for (auto &row : grid) {
            for (int val : row) {
                nums.push_back(val);
            }
        }

        int n = nums.size();

        // Find median using nth_element
        // Median minimizes total operations
        nth_element(nums.begin(),
                    nums.begin() + n / 2,
                    nums.end());

        int target = nums[n / 2];

        int result = 0;

        // Calculate operations needed
        for (int &num : nums) {

            // If remainder differs,
            // conversion is impossible
            if (num % x != target % x) {
                return -1;
            }

            // Count operations
            result += abs(target - num) / x;
        }

        return result;
    }
};

int main() {

    int rows, cols, x;

    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> grid(rows, vector<int>(cols));

    cout << "Enter grid elements:\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    cout << "Enter x: ";
    cin >> x;

    Solution obj;

    int result = obj.minOperations(grid, x);

    cout << "Minimum Operations: " << result << endl;

    return 0;
}