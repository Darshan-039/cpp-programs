// Leetcode 33 :- Search in Rotated Sorted Array





#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int s = 0;                     // Start index
        int e = nums.size() - 1;       // End index

        while(s <= e) {

            int mid = s + (e - s) / 2; // Calculate middle index

            // If target is found
            if(nums[mid] == target)
                return mid;

            // Check if LEFT PART is sorted
            if(nums[s] <= nums[mid]) {

                // Check if target lies inside left sorted part
                if(target >= nums[s] && target <= nums[mid]) {
                    e = mid - 1;      // Search in left half
                }
                else {
                    s = mid + 1;      // Search in right half
                }

            }
            else { // RIGHT PART is sorted

                // Check if target lies inside right sorted part
                if(target >= nums[mid] && target <= nums[e]) {
                    s = mid + 1;      // Search in right half
                }
                else {
                    e = mid - 1;      // Search in left half
                }
            }
        }

        return -1; // Target not found
    }
};

int main() {

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements of rotated sorted array:\n";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter target element: ";
    cin >> target;

    Solution obj;
    int result = obj.search(nums, target);

    if(result != -1)
        cout << "Target found at index: " << result << endl;
    else
        cout << "Target not found" << endl;

    return 0;
}