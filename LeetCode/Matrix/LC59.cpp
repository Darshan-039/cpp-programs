// Leetcode 59. Spiral Matrix II



#include <iostream>
#include <vector>
using namespace std;

void spiral(int n) {
    vector<int> ans;
    int arr[3][3];
    
    int row = 3;
    int col = 3;
    int count = 1;
    
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row-1;
    int endingCol = col-1;
    
    while(count <= 9) {
        // Printing Starting Row    
        for(int i = startingCol; count <= 9 && i<=endingCol; i++){
            arr[startingRow][i] = count;
            count++;
        }
        startingRow++;
        
        // Printing Ending Col
        for(int i = startingRow;count <= 9 && i<=endingRow; i++) {
            arr[i][endingCol] = count;
            count++;
        }
        endingCol--;
        
        // Printing Ending Row
        for(int i = endingCol; count <= 9 && i>=startingCol; i--) {
            arr[endingRow][i] = count;
            count++;
        }
        endingRow--;
        
        // Printing Starting Col
        for(int i = endingRow; count <= 9 && i>=startingRow; i--) {
            arr[i][startingCol] = count;
            count++;
        }
        startingCol++;
    }
    
    for(int i = 0; i<3; i++) {
        for(int j = 0; j<3; j++) {
            cout <<arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 3;
    spiral(n);
}