// Leetcode Problem 7: Reverse Integer


#include <iostream>
#include <climits> // Required for INT_MAX and INT_MIN

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x != 0) {
            int digit = x % 10;
            
            // Overflow check:
            // If ans * 10 will be > INT_MAX or < INT_MIN, return 0
            if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10)) {
                return 0;
            }
            
            ans = (ans * 10) + digit;
            x /= 10;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    int input = 123;
    int result = sol.reverse(input);
    
    cout << "Original: " << input << endl;
    cout << "Reversed: " << result << endl;
    
    // Testing overflow
    int overflowInput = 1534236469;
    cout << "Overflow Case: " << sol.reverse(overflowInput) << " (Returns 0)" << endl;

    return 0;
}