// Leetcode 191: Number of 1 Bits



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;

        // Brian Kernighan’s Algorithm
        // Effectively skips all 0s and only loops for the number of 1s
        while(n > 0) {
            n = n & (n - 1);
            cnt++;
        }

        return cnt;
    }
};

int main() {
    Solution sol;

    // Example Input: 11 (Binary: 00000000000000000000000000001011)
    int input = 11; 
    
    int result = sol.hammingWeight(input);

    cout << "Input: " << input << endl;
    cout << "Number of 1 bits: " << result << endl;

    return 0;
}