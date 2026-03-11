// Leetcode:-31 Next Permutation

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        // STEP 1: Find the first index from right where nums[i] < nums[i+1]
        // This is the "gola index" (pivot)
        int gola_index = -1;
        for(int i = n - 1; i > 0; i--) {
            if(nums[i - 1] < nums[i]) {
                gola_index = i - 1;
                break;
            }
        }

        // STEP 2: If gola_index found, find the element just larger than nums[gola_index]
        // starting from right end
        if(gola_index != -1) {
            int swap_index = gola_index;  
            for(int i = n - 1; i > gola_index; i--) {
                if(nums[i] > nums[gola_index]) {
                    swap_index = i;
                    break;
                }
            }
            // Swap the two
            swap(nums[gola_index], nums[swap_index]);
        }

        // STEP 3: Reverse the suffix (everything after gola_index)
        reverse(nums.begin() + gola_index + 1, nums.end());
    }
};

// MAIN FUNCTION TO TAKE INPUT
int main() {
    Solution obj;

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    obj.nextPermutation(nums);

    cout << "Next permutation: ";
    for(int x : nums) cout << x << " ";
    cout << endl;

    return 0;
}
