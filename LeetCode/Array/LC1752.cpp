// Online C++ compiler to run C++ program online
// Check if Array is Sorted and Rotated
#include <iostream>
#include <vector>
using namespace std;

void printarray(vector<int> arr, int size) {
    for(int i = 0; i<size; i++) {
        cout << arr[i] << "\t";
    }
}

bool isrotate(vector<int>& arr) {
    int svc = arr.size();
    int count=0;
    for(int i = 1; i<svc; i++) {
        if(arr[i-1] > arr[i]) {
            count++;
        }   
    }
    
    if(arr[svc-1] > arr[0]) {
        count++;
    }
    return count<=1;
    
    // printarray(temp,svc);
}

int main() {
  vector<int> vc = {3,4,5,1,5};

   if(isrotate(vc)) cout << "true";
   else cout << "false";
}