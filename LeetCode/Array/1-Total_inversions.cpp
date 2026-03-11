#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> &nums, int s, int e, int mid) {
    vector<int> temp;
    int i = s;
    int j = mid + 1;
    int ans = 0;

    while(i <= mid && j <= e) {
        if(nums[i] < nums[j]) {
            temp.push_back(nums[i]);
            i++;
        }
        else {
            temp.push_back(nums[j]);
            ans += (mid - i + 1);
            j++;
        }
    }

    while(i <= mid) {
        temp.push_back(nums[i]);
        i++;
    }

    while(j <= e) {
        temp.push_back(nums[j]);
        j++;
    }

    for(int i = 0;i<temp.size(); i++) {
        nums[i+s] = temp[i];
    }


    return ans;
}

int mergeSort(vector<int> &nums, int s, int e) {
    if(s >= e) return 0;


    int mid = s + (e-s)/2;

    int lCount = mergeSort(nums, s, mid);
    int Rcount = mergeSort(nums, mid+1, e);
    int total = merge(nums, s, e, mid);

    return lCount + Rcount + total;
}

int main() {
    vector<int> nums = {1,3,5,10,2,6,8,9};
    int n = nums.size();
    int ans = mergeSort(nums, 0, n-1);

    cout << ans << endl;

}