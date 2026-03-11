// Leetcode Problem 1207: Unique Number of Occurrences


#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // Step 1: Map to store the frequency of each number
        unordered_map<int, int> mp;
        for(int i : arr) {
            mp[i]++;
        }

        // Step 2: Set to store seen frequencies and check for duplicates
        unordered_set<int> st;
        for(auto i : mp) {
            // If the frequency (i.second) is already in the set, it's not unique
            if(st.count(i.second)) return false;

            st.insert(i.second);
        }

        return true;
    }
};

int main() {
    Solution sol;

    cout << "--- LeetCode 1207: Unique Number of Occurrences ---" << endl << endl;

    // Test Case 1: Expected output: True
    vector<int> arr1 = {1, 2, 2, 1, 1, 3};
    bool result1 = sol.uniqueOccurrences(arr1);
    cout << "Input 1: [1, 2, 2, 1, 1, 3]" << endl;
    cout << "Result: " << (result1 ? "True" : "False") << " (Correct: 1 appears 3x, 2 appears 2x, 3 appears 1x)" << endl << endl;

    // Test Case 2: Expected output: False
    vector<int> arr2 = {1, 2};
    bool result2 = sol.uniqueOccurrences(arr2);
    cout << "Input 2: [1, 2]" << endl;
    cout << "Result: " << (result2 ? "True" : "False") << " (Correct: Both 1 and 2 appear exactly 1x)" << endl << endl;

    // Test Case 3: Expected output: True
    vector<int> arr3 = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
    bool result3 = sol.uniqueOccurrences(arr3);
    cout << "Input 3: [-3, 0, 1, -3, 1, 1, 1, -3, 10, 0]" << endl;
    cout << "Result: " << (result3 ? "True" : "False") << endl;

    return 0;
}