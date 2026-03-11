// 4 Sum
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> FourSum(vector<int> nums,int target) {
    int n = nums.size();
    vector<vector<int>> ans;
    
    sort(nums.begin(),nums.end());
    
    for(int i = 0; i<n; i++) {
        if(i>0 && nums[i] == nums[i-1]) continue;
        for(int j = i+1; j<n;j++) {
            if(j>i+1 && nums[j] == nums[j-1]) continue;
            int p = j+1;
            int q = n-1;
            
            while(p<q) {
                int sum = nums[i]+nums[j]+nums[p]+nums[q];
                if(sum < target) p++;
                else if(sum > target) q--;
                else {
                    ans.push_back({nums[i],nums[j],nums[p],nums[q]});
                    p++;
                    q--;
                    
                    while(p<q && nums[p] == nums[p-1]) p++;
                }
            }
        }
    }
    return ans;
}

int main() {
   vector<int> nums = {1,0,-1,0,-2,2};
   int target = 0;
   vector<vector<int>> res = FourSum(nums,target);
   
   for(auto x: res) {
       for(int y: x) {
           cout << y << " ";
       }
       cout << endl;
   }
}








