// Find First and Last Occ of a number
#include <iostream>
#include <vector>
using namespace std;

int firstOcc(vector<int> nums, int target) {
    int s = 0;
    int e = nums.size() - 1;
    int ans = -1;
    
    while(s<=e) {
        int mid = s + (e - s) / 2;
        if(nums[mid] == target) {
            ans = mid;
            e = mid - 1;
        }
        else if(nums[mid] < target) {
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    return ans;
}

int lastOcc(vector<int> nums, int target) {
    int s = 0;
    int e = nums.size() - 1;
    int ans = -1;
    
    while(s<=e) {
        int mid = s + (e - s) / 2;
        if(nums[mid] == target) {
            ans = mid;
            s = mid + 1;
        }
        else if(nums[mid] < target) {
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    
    vector<int> ans(2,-1);
    ans[0] = firstOcc(nums,target);
    ans[1] = lastOcc(nums,target);
    
    cout << ans[0] << " " << ans[1];
}