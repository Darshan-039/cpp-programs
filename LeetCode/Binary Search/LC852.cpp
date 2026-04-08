// Leetcode 852. Peak Index in a Mountain Array




#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int s = 1;                      // Start from 1 because peak cannot be at index 0
        int e = arr.size() - 2;         // End at n-2 because peak cannot be at last index

        while(s <= e) {

            int mid = s + (e - s) / 2;  // Calculate mid index

            // Check if mid is the peak element
            if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1])
                return mid;

            // If we are on the increasing slope
            if(arr[mid] > arr[mid-1])
                s = mid + 1;            // Move right

            // If we are on the decreasing slope
            else
                e = mid - 1;            // Move left
        }

        return -1; // Peak not found (should not happen in valid mountain array)
    }
};

int main() {

    int n;
    cout << "Enter size of mountain array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements of mountain array:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    int peakIndex = obj.peakIndexInMountainArray(arr);

    cout << "Peak index: " << peakIndex << endl;
    cout << "Peak element: " << arr[peakIndex] << endl;

    return 0;
}