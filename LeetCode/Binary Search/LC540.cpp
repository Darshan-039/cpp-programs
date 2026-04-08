// Leetcode 540. Single Element in a Sorted Array





#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n = nums.size();

        // If array has only one element
        if(n == 1) return nums[0];

        // Check if the first element is unique
        if(nums[0] != nums[1]) return nums[0];

        // Check if the last element is unique
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        int s = 0;          // Start index
        int e = n - 1;      // End index

        while(s <= e) {

            int mid = s + (e - s) / 2;   // Calculate middle index

            // If mid element is different from both neighbours
            // then it is the single non-duplicate element
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
                return nums[mid];

            // If mid index is even
            if(mid % 2 == 0) {

                // Pair is broken on left side
                if(nums[mid] == nums[mid-1])
                    e = mid - 1;

                // Pair is correct → unique element on right
                else
                    s = mid + 1;
            }
            else { // If mid index is odd

                // Pair is correct → move right
                if(nums[mid] == nums[mid-1])
                    s = mid + 1;

                // Pair broken → move left
                else
                    e = mid - 1;
            }
        }

        return -1; // Should not happen in valid input
    }
};

int main() {

    int n;
    cout << "Enter size of sorted array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements (sorted, every element twice except one):\n";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    int result = obj.singleNonDuplicate(nums);

    cout << "Single non-duplicate element is: " << result << endl;

    return 0;
}