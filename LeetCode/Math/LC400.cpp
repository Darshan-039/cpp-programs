#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        long long digit = 1;     // number of digits in current group
        long long start = 1;     // starting number of the group
        long long count = 9;     // number of digits in this group
        
        // Step 1: Find the digit group
        while (n > count) {
            n -= count;
            digit++;
            start *= 10;
            count = digit * 9 * start;
        }
        
        // Step 2: Find the actual number where nth digit is located
        long long num = start + (n - 1) / digit;
        
        // Step 3: Extract the digit inside the number
        string s = to_string(num);
        return s[(n - 1) % digit] - '0';
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter n: ";
    cin >> n;
    
    cout << "The " << n << "th digit is: " << sol.findNthDigit(n) << endl;
    
    return 0;
}
