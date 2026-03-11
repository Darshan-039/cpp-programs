#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return true;
            }

            // The critical addition for duplicates:
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            }
            // Check if the left side is sorted
            else if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1; 
                } else {
                    left = mid + 1;  
                }
            }
            // Otherwise, the right side must be sorted
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1; 
                } else {
                    right = mid - 1; 
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    int n, target;

    // --- Input Section ---
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements (sorted but rotated, e.g., 2 5 6 0 0 1 2): " << endl;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter target value to search: ";
    cin >> target;

    // --- Logic & Output Section ---
    bool found = sol.search(nums, target);

    if (found) {
        cout << "\nResult: true (Target " << target << " found in the array.)" << endl;
    } else {
        cout << "\nResult: false (Target " << target << " not found.)" << endl;
    }

    return 0;
}