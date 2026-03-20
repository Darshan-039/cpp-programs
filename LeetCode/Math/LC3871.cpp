// Leetcode 3871. Count Commas in Numbers from 1 to n



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        // Start from 1000 (first number having at least 1 comma)
        long long start = 1000;

        // Number of commas in current range
        int commas = 1;

        // Process ranges like:
        // [1000 - 999999] → 1 comma
        // [1,000,000 - 999,999,999] → 2 commas
        // and so on...
        while(start <= n) {

            // End of current range
            long long end = start * 1000 - 1;

            // Clamp range within n
            long long right = min(n, end);

            // Count numbers in this range
            long long count = right - start + 1;

            // Each number contributes 'commas' commas
            ans += count * commas;

            // Move to next range
            start *= 1000;
            commas++;
        }

        return ans;
    }
};

int main() {
    Solution obj;

    // 🔹 Sample Input
    long long n;
    cout << "Enter n: ";
    cin >> n;

    // 🔹 Function call
    long long result = obj.countCommas(n);

    // 🔹 Output
    cout << "Total commas used: " << result << endl;

    return 0;
}