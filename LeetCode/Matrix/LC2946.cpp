// Leetcode 3548. Check if Grid Can Be Partitioned



// Approach - 1 (Using Extra Space for Rotated Matrix)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        // Reduce k to avoid extra rotations
        k = k % n;

        // If no rotation needed → always similar
        if(k == 0) return true;

        // Create a new matrix to store rotated result
        vector<vector<int>> rotatMat(m, vector<int>(n));

        // Traverse each cell
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                int toRotate = k;

                // Even rows → shift RIGHT
                // (equivalent to left shift by n-k)
                if(i % 2 == 0) 
                    toRotate = abs(k - n);

                // Place element in rotated position
                rotatMat[i][ (j + toRotate) % n ] = mat[i][j];
            }
        }

        // Compare original matrix with rotated matrix
        return mat == rotatMat;
    }
};


// 🔥 MAIN FUNCTION (Sample Input)
int main() {
    Solution obj;

    // Example matrix
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int k = 1; // number of shifts

    bool ans = obj.areSimilar(mat, k);

    if(ans) cout << "Matrix is similar after shifts\n";
    else cout << "Matrix is NOT similar after shifts\n";

    return 0;
}









// Approach - 2 (Direct Comparison without Extra Space)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        // Reduce k (rotating n times gives same matrix)
        k = k % n;

        // If no effective rotation → always similar
        if(k == 0) return true;

        // Traverse each row
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                int finalIdx;

                // Even row → shift right
                if(i % 2 == 0) 
                    finalIdx = (j + k) % n;

                // Odd row → shift left
                else 
                    finalIdx = (j - k + n) % n;

                // Compare current element with expected position
                if(mat[i][j] != mat[i][finalIdx]) 
                    return false;
            }
        }

        return true;
    }
};


// 🔥 MAIN FUNCTION (Sample Input)
int main() {
    Solution obj;

    // Example matrix
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int k = 1; // number of shifts

    bool ans = obj.areSimilar(mat, k);

    if(ans) cout << "Matrix is similar after shifts\n";
    else cout << "Matrix is NOT similar after shifts\n";

    return 0;
}