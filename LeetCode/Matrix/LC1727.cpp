// Leetcode 1727. Largest Submatrix With Rearrangements





// Approach - 1 (Brute Force) - O(n^3 log n) - TLE

// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int largestSubmatrix(vector<vector<int>>& matrix) {
//         int n = matrix.size();      // number of rows
//         int m = matrix[0].size();   // number of columns

//         int maxArea = 0;

//         // Traverse each row
//         for(int row = 0; row < n; row++) {

//             // Step 1: Build heights (like histogram)
//             for(int col = 0; col < m; col++) {
//                 // If current cell is 1, add height from above row
//                 if(matrix[row][col] == 1 && row > 0) {
//                     matrix[row][col] += matrix[row-1][col];
//                 }
//                 // else it remains 0
//             }

//             // Step 2: Copy current row heights
//             vector<int> heights = matrix[row];

//             // Step 3: Sort heights in descending order
//             // (simulate column rearrangement)
//             sort(heights.begin(), heights.end(), greater<int>());

//             // Step 4: Try all widths and compute area
//             for(int i = 0; i < m; i++) {
//                 int width = i + 1;        // number of columns taken
//                 int height = heights[i];  // minimum height in this width

//                 maxArea = max(maxArea, width * height);
//             }
//         }

//         return maxArea;
//     }
// };

// int main() {
//     // 🔹 Sample 5x5 input
//     vector<vector<int>> matrix = {
//         {0, 1, 1, 0, 1},
//         {1, 1, 1, 1, 0},
//         {1, 1, 1, 0, 1},
//         {1, 1, 0, 1, 1},
//         {0, 1, 1, 1, 1}
//     };

//     Solution obj;
//     int result = obj.largestSubmatrix(matrix);

//     cout << "Maximum Submatrix Area: " << result << endl;

//     return 0;
// }







// APproach - 2 (Optimized) - O(n^2 log n) - Accepted

// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int largestSubmatrix(vector<vector<int>>& matrix) {
//         int n = matrix.size();      // number of rows
//         int m = matrix[0].size();   // number of columns

//         int maxArea = 0;

//         // This will store heights of previous row (histogram idea)
//         vector<int> prevRow(m, 0);

//         // Traverse each row
//         for(int row = 0; row < n; row++) {

//             // Copy current row
//             vector<int> currRow = matrix[row];

//             // Step 1: Build heights
//             // If current cell is 1 → add height from previous row
//             for(int col = 0; col < m; col++) {
//                 if(currRow[col] == 1) {
//                     currRow[col] += prevRow[col];
//                 }
//                 // else remains 0
//             }

//             // Step 2: Copy heights for sorting
//             vector<int> heights = currRow;

//             // Step 3: Sort in descending order
//             // (simulate column rearrangement)
//             sort(heights.begin(), heights.end(), greater<int>());

//             // Step 4: Calculate max area
//             for(int i = 0; i < m; i++) {
//                 int width = i + 1;        // number of columns used
//                 int height = heights[i]; // minimum height in this width

//                 maxArea = max(maxArea, width * height);
//             }

//             // Step 5: Update prevRow for next iteration
//             prevRow = currRow;
//         }

//         return maxArea;
//     }
// };

// int main() {
//     // 🔹 Sample 5x5 input
//     vector<vector<int>> matrix = {
//         {0, 1, 1, 0, 1},
//         {1, 1, 1, 1, 0},
//         {1, 1, 1, 0, 1},
//         {1, 1, 0, 1, 1},
//         {0, 1, 1, 1, 1}
//     };

//     Solution obj;
//     int result = obj.largestSubmatrix(matrix);

//     cout << "Maximum Submatrix Area: " << result << endl;

//     return 0;
// }








// Approach - 3 (Optimized) - O(n^2) - Accepted

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();      // number of rows
        int m = matrix[0].size();   // number of columns

        int maxArea = 0;

        // Stores {height, column_index} from previous row
        vector<pair<int, int>> prevHeights;

        // Traverse each row
        for(int row = 0; row < n; row++) {

            vector<pair<int, int>> currHeights;

            // Track which columns are already updated
            vector<int> visited(m, false);

            // Step 1: Extend previous heights if current cell is 1
            for(auto &[height, col] : prevHeights) {
                if(matrix[row][col] == 1) {
                    currHeights.push_back({height + 1, col});
                    visited[col] = true;   // mark this column as used
                }
            }

            // Step 2: Start new heights for fresh 1s
            for(int col = 0; col < m; col++) {
                if(!visited[col] && matrix[row][col] == 1) {
                    currHeights.push_back({1, col});
                }
            }


            // Step 3: Calculate max area
            for(int i = 0; i < currHeights.size(); i++) {
                int width = i + 1;                 // number of columns used
                int height = currHeights[i].first; // min height in this width

                maxArea = max(maxArea, width * height);
            }

            // Step 4: Update for next row
            prevHeights = currHeights;
        }

        return maxArea;
    }
};

int main() {
    // 🔹 Sample 5x5 input
    vector<vector<int>> matrix = {
        {0, 1, 1, 0, 1},
        {1, 1, 1, 1, 0},
        {1, 1, 1, 0, 1},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 1, 1}
    };

    Solution obj;
    int result = obj.largestSubmatrix(matrix);

    cout << "Maximum Submatrix Area: " << result << endl;

    return 0;
}