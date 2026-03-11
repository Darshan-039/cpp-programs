// LeetCode Problem 42: Trapping Rain Water



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {

        // Approach - 1: Using extra space for leftMax and rightMax arrays




        // int n = height.size();
        // vector<int> lmax(n,0);
        // vector<int> rmax(n,0);

        // // Creating leftMax arr
        // lmax[0] = height[0];
        // for(int i = 1; i<n; i++) lmax[i] = max(height[i] , lmax[i-1]);

        // // Creating rightMax arr
        // rmax[n-1] = height[n-1];
        // for(int i = n-2; i>=0; i--) rmax[i] = max(height[i] , rmax[i+1]);


        // int ans = 0;
        // for(int i = 0; i<n; i++) ans += min(lmax[i], rmax[i]) - height[i];

        // return ans;






        // Approach - 2: Two-pointer approach (Optimized for space)


        int n = height.size();
        if (n == 0) return 0;

        int ans = 0;
        int lmax = 0, rmax = 0;

        int i = 0, j = n - 1;
        
        // Two-pointer logic:
        // The amount of water is limited by the shorter wall.
        while(i < j) {
            lmax = max(lmax, height[i]);
            rmax = max(rmax, height[j]);

            if(lmax < rmax) {
                // Since lmax < rmax, the water level at 'i' is limited by lmax
                ans += lmax - height[i];
                i++;
            }
            else {
                // Since rmax <= lmax, the water level at 'j' is limited by rmax
                ans += rmax - height[j];
                j--;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard elevation map
    vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Test Case 1: " << sol.trap(height1) << " (Expected: 6)" << endl;

    // Test Case 2: Large pool in the middle
    vector<int> height2 = {4, 2, 0, 3, 2, 5};
    cout << "Test Case 2: " << sol.trap(height2) << " (Expected: 9)" << endl;

    // Test Case 3: Stairs (No water can be trapped)
    vector<int> height3 = {1, 2, 3, 4, 5};
    cout << "Test Case 3: " << sol.trap(height3) << " (Expected: 0)" << endl;

    return 0;
}