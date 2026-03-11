// Leetcode Problem 4: Median of Two Sorted Arrays





// Approach - 1
// #include <vector>
// #include <algorithm>
// #include <iostream>

// using namespace std;

// class Solution {
// public:
//     int n;
//     int m;

//     double evenSize(vector<int>& nums1, vector<int>& nums2, int idx1, int idx2) {
//         int count = 0;
//         int i = 0, j = 0;
//         double sum = 0; 

//         while (i < n && j < m) {
//             int val;
//             if (nums1[i] < nums2[j]) {
//                 val = nums1[i];
//                 i++;
//             } else {
//                 val = nums2[j];
//                 j++;
//             }

//             if (count == idx1 || count == idx2) {
//                 sum += val;
//             }
//             count++;
            
//             if (count > max(idx1, idx2)) return sum / 2.0;
//         }

//         while (i < n) {
//             if (count == idx1 || count == idx2) sum += nums1[i];
//             i++;
//             count++;
//         }

//         while (j < m) {
//             if (count == idx1 || count == idx2) sum += nums2[j];
//             j++;
//             count++;
//         }

//         return sum / 2.0;
//     }

//     double oddSize(vector<int>& nums1, vector<int>& nums2, int idx) {
//         int count = 0;
//         int i = 0, j = 0;
//         double result = 0;

//         while (i < n && j < m) {
//             int val;
//             if (nums1[i] < nums2[j]) {
//                 val = nums1[i];
//                 i++;
//             } else {
//                 val = nums2[j];
//                 j++;
//             }

//             if (count == idx) return (double)val;
//             count++;
//         }

//         while (i < n) {
//             if (count == idx) return (double)nums1[i];
//             i++;
//             count++;
//         }

//         while (j < m) {
//             if (count == idx) return (double)nums2[j];
//             j++;
//             count++;
//         }

//         return result;
//     }

//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         n = nums1.size();
//         m = nums2.size();
//         int tSize = n + m;

//         if (tSize % 2 == 0) {
//             int idx1 = tSize / 2;
//             int idx2 = (tSize / 2) - 1;
//             return evenSize(nums1, nums2, idx1, idx2);
//         } else {
//             int idx = tSize / 2;
//             return oddSize(nums1, nums2, idx);
//         }
//     }
// };

// int main() {
//     Solution sol;

//     // --- Input for Test Case 1 (Odd Total) ---
//     vector<int> n1 = {1, 3, 8};
//     vector<int> n2 = {7, 9};
//     // Combined sorted: 1, 3, 7, 8, 9 -> Median is 7
//     cout << "Test 1 (Odd): " << sol.findMedianSortedArrays(n1, n2) << endl;

//     // --- Input for Test Case 2 (Even Total) ---
//     vector<int> n3 = {1, 2};
//     vector<int> n4 = {3, 4};
//     // Combined sorted: 1, 2, 3, 4 -> Median is (2+3)/2 = 2.5
//     cout << "Test 2 (Even): " << sol.findMedianSortedArrays(n3, n4) << endl;

//     return 0;
// }








// Approach - 2
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int tSize = n + m;

        int i = 0, j = 0;
        int count = 0;
        
        int current = 0, prev = 0;
        int targetIdx = tSize / 2;

        while(count <= targetIdx) {
            prev = current;

            if(i < n && (j >= m || nums1[i] < nums2[j])) {
                current = nums1[i];
                i++;
            }
            else {
                current = nums2[j];
                j++;
            }
            count++;
        }

        if(tSize % 2 == 0) return (prev + current) / 2.0;        
        else return (double)current;
    }
};

int main() {
    Solution sol;

    // --- Test Case 1: Odd Total Size ---
    vector<int> arr1 = {1, 3};
    vector<int> arr2 = {2};
    cout << "Test 1 - Expected: 2.0, Result: " << sol.findMedianSortedArrays(arr1, arr2) << endl;

    // --- Test Case 2: Even Total Size ---
    vector<int> arr3 = {1, 2};
    vector<int> arr4 = {3, 4};
    cout << "Test 2 - Expected: 2.5, Result: " << sol.findMedianSortedArrays(arr3, arr4) << endl;

    // --- Test Case 3: One Empty Array ---
    vector<int> arr5 = {};
    vector<int> arr6 = {1};
    cout << "Test 3 - Expected: 1.0, Result: " << sol.findMedianSortedArrays(arr5, arr6) << endl;

    return 0;
}