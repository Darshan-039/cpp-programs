// Leetcode 1335. Minimum Difficulty of a Job Schedule



#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

class Solution {
public:
    int n;
    int t[301][11];

    int solve(vector<int>& jobDifficulty, int i, int d) {
        if(d == 1) {
            int maxi = jobDifficulty[i];
            for(int k = i; k < n; k++) 
                maxi = max(maxi, jobDifficulty[k]);
            return maxi;
        }

        if(t[i][d] != -1) return t[i][d];

        int maxD = jobDifficulty[i]; 
        int finalResult = INT_MAX; 

        for(int j = i; j <= n - d; j++) {
            maxD = max(maxD, jobDifficulty[j]);
            int result = maxD + solve(jobDifficulty, j + 1, d - 1);
            finalResult = min(finalResult, result);
        }

        return t[i][d] = finalResult;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n = jobDifficulty.size();
        if(d > n) return -1;
        memset(t, -1, sizeof(t));
        return solve(jobDifficulty, 0, d);
    }
};

int main() {
    Solution sol;
    int num_jobs, days;

    cout << "Enter number of jobs: ";
    cin >> num_jobs;
    
    vector<int> jobDifficulty(num_jobs);
    cout << "Enter job difficulties: ";
    for(int i = 0; i < num_jobs; i++) {
        cin >> jobDifficulty[i];
    }

    cout << "Enter number of days: ";
    cin >> days;

    int result = sol.minDifficulty(jobDifficulty, days);
    cout << "Minimum difficulty: " << result << endl;

    return 0;
}