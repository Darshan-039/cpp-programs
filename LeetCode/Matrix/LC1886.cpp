// Leetcode 1886. Determine Whether Matrix Can Be Obtained By Rotation



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();

        // Check if already equal (0° rotation)
        if (mat == target) return true;

        // Try 3 more rotations (90°, 180°, 270°)
        for (int k = 1; k < 4; k++) {

            // Step 1: Transpose the matrix
            // Convert rows to columns
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    swap(mat[i][j], mat[j][i]);
                }
            }

            // Step 2: Reverse each row
            // This completes 90° clockwise rotation
            for (int i = 0; i < n; i++) {
                reverse(mat[i].begin(), mat[i].end());
            }

            // Check if current rotation matches target
            if (mat == target) return true;
        }

        return false;
    }
};

int main() {
    int n;
    cout << "Enter size of matrix (n x n): ";
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));
    vector<vector<int>> target(n, vector<int>(n));

    cout << "Enter matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    cout << "Enter target matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> target[i][j];
        }
    }

    Solution obj;
    bool result = obj.findRotation(mat, target);

    if (result)
        cout << "Yes, matrix can be rotated to match target.\n";
    else
        cout << "No, matrix cannot be rotated to match target.\n";

    return 0;
}