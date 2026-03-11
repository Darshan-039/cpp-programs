#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int slow = 2;

        for (int fast = 2; fast < n; fast++) {
            if (nums[fast] != nums[slow - 2]) {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter sorted array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    int newLength = obj.removeDuplicates(nums);

    cout << "New length: " << newLength << endl;
    cout << "Array after removing extra duplicates:\n";

    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}
