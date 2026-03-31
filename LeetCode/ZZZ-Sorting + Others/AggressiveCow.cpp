// Online C++ compiler to run C++ program online
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool ispossible(vector<int> arr,int k,int mid) {
 int cowcount = 1;
 int fpos = arr[0];
 
    for(int i = 0; i<arr.size(); i++) {
        if(arr[i] - fpos >= mid) {
            cowcount++;
            if(cowcount == k) {
                return true;
            }
            fpos = arr[i];
        }
    }
    return false;
}

int main() {
    // Write C++ code here
    vector<int> vc = {1,2,4,8,9};
    int cow = 2;
    
    sort(vc.begin(), vc.end());
    int maxi = -1;
    for(int i = 0; i<vc.size(); i++) {
        maxi = max(maxi, vc[i]);
    }
    int s = 0;
    int e = maxi;
    int ans;
    int mid = s + (e-s)/2;
    
    while(s<=e) {
        if(ispossible(vc,cow,mid)) {
            ans = mid;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    
    cout << ans << endl;
    
}