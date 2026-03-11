// Search in Rotated Sorted Array
#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> nums,int target) {
    int s = 0; 
    int e = nums.size()-1;
    
    while(s<=e) {
        int mid = s + (e-s)/2;
        if(nums[mid] == target) {
            return mid;
        }
        
        // Left vala part sort he
        if(nums[s] <= nums[mid]) {
            // Check if Target is in left part
            if(nums[s] <= target && target <= nums[mid]) {
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }
        // Right vaa part sort he
        else {
            // Target is in right part
            if(nums[mid] <= target && target <= nums[e]) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }
    }
    
    return -1;
}

int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    int ans = search(nums,target);
    cout << ans;
}