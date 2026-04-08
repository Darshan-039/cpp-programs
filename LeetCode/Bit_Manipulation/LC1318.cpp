// Leetcode 1318. Minimum Flips to Make a OR b Equal to c


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0; // stores total flips needed

        // Check all 32 bits (for integer)
        for(int i = 0; i < 32; i++) {

            // Extract i-th bit from a, b, and c
            int x = (a >> i) & 1; // bit of a
            int y = (b >> i) & 1; // bit of b
            int z = (c >> i) & 1; // bit of c

            // Case 1: c's bit is 0
            // So (a OR b) must be 0 → both x and y should be 0
            if(z == 0) {
                if(x == 1) count++; // flip a's bit
                if(y == 1) count++; // flip b's bit
            }
            // Case 2: c's bit is 1
            // So at least one of x or y must be 1
            else {
                if(x == 0 && y == 0) 
                    count++; // flip any one bit
            }
        }

        return count;
    }
};

int main() {
    int a, b, c;

    cout << "Enter values of a, b, c: ";
    cin >> a >> b >> c;

    Solution obj;
    int result = obj.minFlips(a, b, c);

    cout << "Minimum flips required: " << result << endl;

    return 0;
}