// // 566. Reshape the Matrix

// class Solution {
// public:
//     vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
//         int m = mat.size();
//         int n = mat[0].size();

//         if(m*n != r*c) return mat;

//         vector<vector<int>> ans(r,vector<int>(c));
//         int col = 0; int row = 0;

//         // Fill the matrix row by row
//         // c = 4
//         for(int i = 0; i<m; i++) {
//             for(int j = 0; j<n; j++) {
//                 ans[row][col] = mat[i][j];
//                 col++;

//                  // Move to next row if column filled
//                 if (col == c) {
//                     col = 0;
//                     row++;
//                 }
//             }
//         }

//         return ans;
//     }
// };