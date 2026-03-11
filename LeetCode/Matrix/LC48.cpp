// Rotate Image - LeetCode 48

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

void rotate(vector<vector<int>>& matrix) {
    // int row = 3;
    // int col = 3;
    int n = 4;
    
   
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
        
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
    
}

int main() {
    vector<vector<int>> matrix = {
        {5,1,9,11},
        {2,4,8,10},
        {13,3,6,7},
        {15,14,12,16}
    };
    
    rotate(matrix);
    printMatrix(matrix);

}
