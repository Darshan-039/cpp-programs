// Leetcode 1536. Minimum Swaps to Arrange a Binary Grid




#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    /*
        Problem:
        We want grid[i][j] such that
        for every row i, there are at least (n-i-1)
        trailing zeros.

        Allowed operation:
        → swap adjacent rows only.
    */

    int minSwaps(vector<vector<int>>& grid) {

        int n = grid.size();

        // endZeros[i] = number of trailing zeros in row i
        vector<int> endZeros(n, 0);

        // Count trailing zeros for every row
        for(int i = 0; i < n; i++) {

            int j = n - 1;
            int count = 0;

            // move from right side and count zeros
            while(j >= 0 && grid[i][j] == 0) {
                j--;
                count++;
            }

            endZeros[i] = count;
        }

        int steps = 0; // total swaps

        // Fix rows one by one
        for(int i = 0; i < n; i++) {

            // required trailing zeros for row i
            int need = n - i - 1;

            // find row below having enough zeros
            int j = i;

            while(j < n && endZeros[j] < need)
                j++;

            // no valid row found → impossible
            if(j == n)
                return -1;

            // number of adjacent swaps needed
            steps += j - i;

            // bring row upward using swaps
            while(j > i) {
                swap(endZeros[j], endZeros[j - 1]);
                j--;
            }
        }

        return steps;
    }
};


// ---------------- MAIN FUNCTION (INPUT ADDED) ----------------

int main() {

    /*
        Example Input:

        grid =
        0 0 1
        1 1 0
        1 0 0

        Expected Output = 3
    */

    vector<vector<int>> grid = {
        {0,0,1},
        {1,1,0},
        {1,0,0}
    };

    Solution obj;

    int ans = obj.minSwaps(grid);

    cout << "Minimum swaps needed: " << ans << endl;

    return 0;
}