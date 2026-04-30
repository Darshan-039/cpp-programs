// Leetcode 137. Single Number II


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0; // This will accumulate the bits of our final unique number

        // Iterate through all 32 bits of a standard integer
        for(int k = 0; k < 32; k++) {
            
            // Create a mask with a '1' at the k-th position and '0's everywhere else
            // For example, if k=2, temp = 0000...0100 in binary
            int temp = (1 << k); 

            int oneCount = 0; // To count how many numbers have the k-th bit set to 1

            // Check the k-th bit of every number in the array
            for(int num: nums) {
                // If the bitwise AND is non-zero, it means the k-th bit of 'num' is 1
                if(num & temp) {
                    oneCount++;
                }
            }

            // Since all other numbers appear exactly 3 times, their 1s at this bit position 
            // will sum up to a multiple of 3. 
            // If the total count is NOT a multiple of 3, the extra '1' must belong to our single number.
            if(oneCount % 3 != 0) {
                ans |= temp; // Set the k-th bit in our answer to 1 using bitwise OR
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    
    // Hardcoded sample input
    // The number 5 appears exactly once, while 2 and 8 appear three times.
    vector<int> nums = {2, 2, 8, 2, 5, 8, 8};
    
    cout << "Input array: ";
    for(int num : nums) {
        cout << num << " ";
    }
    cout << "\n";
    
    // Call the function and print the result
    int result = solution.singleNumber(nums);
    
    cout << "The single number is: " << result << "\n";
    
    return 0;
}