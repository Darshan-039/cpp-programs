// 3Sum closest
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int ThreeSum(vector<int> nums, int target) {
    int n = nums.size();
    
    sort(nums.begin(),nums.end());
    int closestSum = nums[0] + nums[1] + nums[2];
    
    for(int i = 0; i<n; i++) {
        int j = i+1;
        int k = n-1;
        while(j<k) {
            int sum = nums[i]+nums[j]+nums[k];
            // Check that new sum is closest or not
            if(abs(target-sum) < abs(target-closestSum)){
                closestSum = sum;
            }
            
            if(sum < target) {
                j++;
            }
            else if(sum > target) {
                k--;
            }
            else {
                return sum; // Perfect Match
            }
        }
    }
    return closestSum;
}

int main() {
   vector<int> nums = {0,0,0};
   int target = 1;
   int res = ThreeSum(nums,target);
   cout << res;
   
}
