// Leetcode 1545. Find Kth Bit in Nth Binary String



#include <iostream>
using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {

        // Base case
        if(n == 1)
            return '0';

        int length = (1 << n) - 1;        // total length = 2^n - 1
        int mid = (length + 1) / 2;      // middle position

        // Case 1: If k is in left half
        if(k < mid)
            return findKthBit(n - 1, k);

        // Case 2: If k is exactly middle
        else if(k == mid)
            return '1';

        // Case 3: If k is in right half
        else {
            char ch = findKthBit(n - 1, length - k + 1);

            // Invert the bit
            return (ch == '0') ? '1' : '0';
        }
    }
};

int main() {

    int n, k;

    cout << "Enter n and k: ";
    cin >> n >> k;

    Solution obj;
    char result = obj.findKthBit(n, k);

    cout << "Kth bit is: " << result << endl;

    return 0;
}