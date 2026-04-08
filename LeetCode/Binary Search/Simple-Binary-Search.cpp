#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s <= e) {
        if(arr[mid] == target) return true;

        if(target > arr[mid]) s = mid + 1;
        else e = mid - 1;

        mid = s + (e-s)/2;
    }

    return false;
}

int main() {
    int arr[6] = {2,4,6,8,10,15};
    int arr2[7] = {2,4,6,8,10,13,20};

    cout << binarySearch(arr, 6, 8) << endl;
    cout << binarySearch(arr2, 7, 10) << endl;
}