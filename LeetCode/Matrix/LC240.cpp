// Search a 2D Matrix II

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

bool find(vector<vector<int>>& matrix,int target) {
    int row = matrix.size();
    int col = matrix[0].size();
    
    int rowIndex = 0;
    int colIndex = col-1;
    
    while(rowIndex < row && colIndex>=0) {
        int element = matrix[rowIndex][colIndex];
        if(element == target) {
            return 1;
        }
        if(element < target) {
            rowIndex++;
        }
        else {
            colIndex--;
        }
    }
    
    return 0;
    
}

int main() {
    vector<vector<int>> matrix = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24}
    };
    int target = 18;
    
    int res = find(matrix,target);
    // printMatrix(matrix);
    cout << res;
}
