// Leetcode 73. Set Matrix Zeroes



//Approch-1 (Using extra space of m*n)
//T.C : O(m*n*(m+n))
//S.C : O(m*n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> temp = matrix;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    for (int k = 0; k < n; k++) {
                        temp[i][k] = 0;  // zero out the entire row
                    }
                    for (int k = 0; k < m; k++) {
                        temp[k][j] = 0;  // zero out the entire column
                    }
                }
            }
        }

        matrix = temp;
    }
};


//Approch-2 (Using m+n extra space)
//T.C : O(m*n)
//S.C : O(m+n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();        // number of rows
        int n = matrix[0].size();     // number of columns

        vector<bool> row(m, false);
        vector<bool> col(n, false);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    row[i] = true; //mark it for zero
                    col[j] = true; //mark it for zero
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(row[i] || col[j]){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};


//Approach-3 (In place constant space)
//T.C : O(m*n)
//S.C : O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Flags to track if first row or first column should be zero
        bool firstRowZero = false;
        bool firstColZero = false;

        // Step 1: Check if first column contains any zero
        for(int i = 0; i < m; i++) {
            if(matrix[i][0] == 0) 
                firstColZero = true;
        }

        // Step 2: Check if first row contains any zero
        for(int j = 0; j < n; j++) {
            if(matrix[0][j] == 0) 
                firstRowZero = true;
        }

        // Step 3: Use first row and column as markers
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0; // mark row
                    matrix[0][j] = 0; // mark column
                }
            }
        }

        // Step 4: Set elements to zero based on markers
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 5: Update first row if needed
        if(firstRowZero) {
            for(int j = 0; j < n; j++) 
                matrix[0][j] = 0;
        }

        // Step 6: Update first column if needed
        if(firstColZero) {
            for(int i = 0; i < m; i++) 
                matrix[i][0] = 0;
        }
    }
};

int main() {
    int m, n;
    cout << "Enter rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    cout << "Enter matrix elements:\n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    Solution obj;
    obj.setZeroes(matrix);

    cout << "\nMatrix after setting zeroes:\n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}