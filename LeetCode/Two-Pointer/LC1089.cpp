// Leetcode 1089. Duplicate Zeros


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int zeros = 0;

        // Count total number of zeros in array
        for (int x : arr) {
            if (x == 0) zeros++;
        }

        // i → original array pointer
        // j → virtual extended array pointer
        int i = n - 1;
        int j = n + zeros - 1;

        // Traverse from end to avoid overwriting elements
        while (i >= 0) {

            // Copy element if within bounds
            if (j < n) {
                arr[j] = arr[i];
            }

            // If current element is zero, duplicate it
            if (arr[i] == 0) {
                j--;
                if (j < n) {
                    arr[j] = 0;
                }
            }

            // Move both pointers backward
            i--;
            j--;
        }
    }
};


// Main function
int main() {
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    Solution obj;
    obj.duplicateZeros(arr);

    cout << "Array after duplicating zeros:\n";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}