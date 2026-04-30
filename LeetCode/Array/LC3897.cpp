// Leetcode 3897. Maximum Value of Concatenated Binary String


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        const int MOD = 1e9 + 7;
        int n = nums1.size();

        vector<string> temp;

        // Step 1: Create binary strings for each pair
        // nums1[i] times '1' followed by nums0[i] times '0'
        for (int i = 0; i < n; i++) {
            string s = string(nums1[i], '1') + string(nums0[i], '0');
            temp.push_back(s);
        }

        // Step 2: Sort strings to form maximum binary number
        sort(temp.begin(), temp.end(), [](string &a, string &b) {
            return a + b > b + a;
        });

        long long ans = 0;

        // Step 3: Convert concatenated binary string into decimal modulo MOD
        for (string &s : temp) {
            for (char ch : s) {
                ans = (ans * 2 + (ch - '0')) % MOD;
            }
        }

        return ans;
    }
};

int main() {
    int n;

    // Input size of arrays
    cout << "Enter size of arrays: ";
    cin >> n;

    vector<int> nums1(n), nums0(n);

    // Input nums1
    cout << "Enter elements of nums1: ";
    for (int i = 0; i < n; i++) {
        cin >> nums1[i];
    }

    // Input nums0
    cout << "Enter elements of nums0: ";
    for (int i = 0; i < n; i++) {
        cin >> nums0[i];
    }

    Solution obj;

    // Find and print maximum value
    cout << "Maximum value is: " << obj.maxValue(nums1, nums0) << endl;

    return 0;
}