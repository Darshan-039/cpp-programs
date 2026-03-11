// Leetcode 70: Climbing Stairs


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {

        // Method 2: DP using array
        if (n == 1 || n == 2 || n == 3) {
            return n;
        }

        vector<int> array(n + 1);

        array[0] = 0;
        array[1] = 1;
        array[2] = 2;

        for (int i = 3; i <= n; i++) {
            array[i] = array[i - 1] + array[i - 2];
        }

        return array[n];
    }
};

int main() {
    int n;
    cout << "Enter number of steps: ";
    cin >> n;

    Solution obj;
    int result = obj.climbStairs(n);

    cout << "Number of ways to climb stairs: " << result << endl;

    return 0;
}
