// Leetcode 868. Binary Gap




#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * Finds the longest distance between two adjacent 1's in the binary representation of n.
     * T.C: O(1) - Always iterates 32 times (fixed integer width).
     * S.C: O(1) - Uses a constant amount of extra space.
     */
    int binaryGap(int n) {
        int prev = -1;  // Stores index of the last '1' found
        int result = 0; // Stores the maximum distance (gap)

        // Iterate through all 32 bits of the integer
        for (int curr = 0; curr < 32; curr++) {
            // (n >> curr) & 1: Shifts the bit at 'curr' to the 0th position and checks if it is 1
            if (((n >> curr) & 1) > 0) {
                // If this isn't the first '1' we've seen, calculate the gap
                if (prev != -1) {
                    result = max(result, curr - prev);
                }
                // Update the 'prev' pointer to the current index
                prev = curr;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    
    // Test Inputs
    int input1 = 22; // Binary: 10110 -> Gaps: (2-1)=1, (4-2)=2. Max = 2
    int input2 = 8;  // Binary: 1000  -> Only one '1'. Max = 0
    int input3 = 5;  // Binary: 101   -> Gap: (2-0)=2. Max = 2

    cout << "Binary Gap of " << input1 << ": " << sol.binaryGap(input1) << endl;
    cout << "Binary Gap of " << input2 << ": " << sol.binaryGap(input2) << endl;
    cout << "Binary Gap of " << input3 << ": " << sol.binaryGap(input3) << endl;

    return 0;
}