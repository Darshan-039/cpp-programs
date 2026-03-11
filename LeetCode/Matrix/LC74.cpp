// LeetCode 74: Search a 2D Matrix

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
    
    int s = 0;
    int e = row*col-1;
    
    int m = s + (e-s)/2;
    
    while(s<=e) {
        int element = matrix[m/col][m%col];
        if(element == target) {
            return 1;
        }
        if(element < target) {
            s = m + 1;
        }
        else {
            e = m - 1;
        }
        m = s + (e-s)/2;
    }
    
    return 0;
    
}

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 7;
    
    int res = find(matrix,target);
    // printMatrix(matrix);
    cout << res;
}
