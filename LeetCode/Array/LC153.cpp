// // Leetcode 3217:- Find Minimum in Rotated Sorted Array
// Two approachs are given below:
// Approach 1:- Checking if left half is sorted
// Approach 2:- Checking with last element
// Both approaches have time complexity O(log n) and space complexity O(1).



// #include <iostream>
// #include <vector>
// using namespace std;

// int findMin(vector<int>& nums) {
//     int s = 0;
//     int e = nums.size() - 1;

//     while (s < e) {
//         int mid = s + (e - s) / 2;

//         // If left half is sorted
//         if (nums[mid] >= nums[s]) {

//             // If entire array is already sorted
//             if (nums[s] <= nums[e]) {
//                 return nums[s];   // First element is smallest
//             }

//             // Minimum is in right half
//             s = mid + 1;
//         } 
//         else {
//             // Minimum is in left half (including mid)
//             e = mid;
//         }
//     }

//     return nums[s]; // s == e → minimum element
// }

// int main() {

//     // ⭐ Your own input
//     vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

//     cout << "Input array: ";
//     for (int x : nums) cout << x << " ";
//     cout << endl;

//     int minimum = findMin(nums);

//     cout << "Minimum element = " << minimum << endl;

//     return 0;
// }


















#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            // If mid element is greater than last element,
            // then minimum is in the right half
            if (nums[mid] > nums[e]) {
                s = mid + 1;
            } 
            else {
                // Minimum is in left half (including mid)
                e = mid;
            }
        }

        return nums[s]; // s == e → minimum element
    }
};

int main() {
    // ⭐ Your own input here
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    Solution obj;
    int ans = obj.findMin(nums);

    cout << "Input array: ";
    for (int x : nums) cout << x << " ";
    cout << "\nMinimum element = " << ans << endl;

    return 0;
}
