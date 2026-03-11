// Online C++ compiler to run C++ program online
// {Rotate Array}
#include <iostream>
#include <vector>
using namespace std;

void printarray(vector<int> arr, int size) {
    for(int i = 0; i<size; i++) {
        cout << arr[i] << "\t";
    }
}

void mergearray(vector<int>& arr,int m) {
    int svc = arr.size();
    vector<int> temp(svc);
    
    for(int i = 0; i<svc; i++) {
        temp[(i+m)%svc] = arr[i];
    }
    
    
    
    printarray(temp,svc);
}

int main() {
  vector<int> vc = {1,2,3,4,5,6};
   int m = 3;
   
   mergearray(vc,3);
}