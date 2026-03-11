// Leetcode 414. Third Maximum Number

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;

        for (int n : nums) {
            if (n == first || n == second || n == third)
                continue;  // skip duplicates

            if (n > first) {
                third = second;
                second = first;
                first = n;
            }
            else if (n > second) {
                third = second;
                second = n;
            }
            else if (n > third) {
                third = n;
            }
        }

        return third == LONG_MIN ? first : third;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    cout << "Third Maximum: " << obj.thirdMax(nums) << endl;

    return 0;
}
