// Leetcode 3834. Merge Adjacent Equal Values in an Array



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> result;

        for(int x : nums) {
            long long current = x;

            // While the current value matches the last element in our result,
            // merge them and pop the last element.
            while(!result.empty() && result.back() == current) {
                current += result.back();
                result.pop_back();
            }

            result.push_back(current);
        }

        return result;
    }
};

void printResult(const vector<long long>& res) {
    cout << "[ ";
    for(long long x : res) cout << x << " ";
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Test Case 1: Simple merge
    // [2, 2, 3] -> 2+2=4 -> [4, 3]
    vector<int> nums1 = {2, 2, 3};
    cout << "Test 1: ";
    printResult(sol.mergeAdjacent(nums1));

    // Test Case 2: Cascading merge (The "2048" effect)
    // [1, 1, 2, 4] 
    // 1+1=2 -> 2+2=4 -> 4+4=8 -> [8]
    vector<int> nums2 = {1, 1, 2, 4};
    cout << "Test 2: ";
    printResult(sol.mergeAdjacent(nums2));

    // Test Case 3: Mixed values
    vector<int> nums3 = {3, 3, 6, 12, 5};
    cout << "Test 3: ";
    printResult(sol.mergeAdjacent(nums3)); // Expected: [24, 5]

    return 0;
}