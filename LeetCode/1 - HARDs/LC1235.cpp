// Leetcode 1235. Maximum Profit in Job Scheduling



#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
    int n;
    int t[50001];

    int getIndex(vector<vector<int>> &array, int s, int target) {
        int result = n; // Changed from n+1 to n to avoid out-of-bounds
        int e = n - 1;

        while(s <= e) {
            int mid = s + (e - s) / 2;
            if(array[mid][0] >= target) {
                result = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return result;
    }

    int solve(vector<vector<int>> &array, int i) {
        if(i >= n) return 0;
        if(t[i] != -1) return t[i];

        // Option 1: Take the current job
        int next = getIndex(array, i + 1, array[i][1]);
        int take = array[i][2] + solve(array, next);

        // Option 2: Skip the current job
        int not_take = solve(array, i + 1);

        return t[i] = max(take, not_take);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        memset(t, -1, sizeof(t));

        vector<vector<int>> array(n, vector<int>(3));
        for(int i = 0; i < n; i++) {
            array[i][0] = startTime[i];
            array[i][1] = endTime[i];
            array[i][2] = profit[i];
        }

        sort(begin(array), end(array));
        return solve(array, 0);
    }
};

int main() {
    Solution sol;
    
    // Input Data
    vector<int> startTime = {1, 2, 3, 3};
    vector<int> endTime   = {3, 4, 5, 6};
    vector<int> profit    = {50, 10, 40, 70};

    int maxProfit = sol.jobScheduling(startTime, endTime, profit);

    cout << "Maximum Profit: " << maxProfit << endl; // Expected: 120 (Job 1 and Job 4)

    return 0;
}