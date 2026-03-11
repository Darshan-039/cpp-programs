// LeetCode 54: Spiral Matrix

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

void PrintSpiral(int arr[][3]) {
    vector<int> ans;
    
    int row = 3;
    int col = 3;
    int count = 0;
    
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row-1;
    int endingCol = col-1;
    
    while(count < 9) {
        // Printing Starting Row    
        for(int i = startingCol; count < 9 && i<=endingCol; i++){
            ans.push_back(arr[startingRow][i]);
            count++;
        }
        startingRow++;
        
        // Printing Ending Col
        for(int i = startingRow;count < 9 && i<=endingRow; i++) {
            ans.push_back(arr[i][endingCol]);
            count++;
        }
        endingCol--;
        
        // Printing Ending Row
        for(int i = endingCol; count < 9 && i>=startingCol; i--) {
            ans.push_back(arr[endingRow][i]);
            count++;
        }
        endingRow--;
        
        // Printing Starting Col
        for(int i = endingRow; count < 9 && i>=startingRow; i--) {
            ans.push_back(arr[i][startingCol]);
            count++;
        }
        startingCol++;
    }
    
    for(int x: ans) {
        cout << x << "\t";
    }
}

int main() {
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    
    PrintSpiral(arr);
}
