// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    int arr[6] = {1,6,5,10,3,8};
    int size = 6;
    
    for(int i = 1; i<size; i++) {
        int temp = arr[i];
        int j = i-1;
        for(; j>=0; j--) {
            if(arr[j] > temp) {
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
    }
    
    for(int x: arr) {
        cout << x << "\t";
    }
}