// Leetcode 2463. Minimum Total Distance Traveled


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    typedef long long ll;

    // DP table:
    // dp[ri][fi] = minimum distance to repair robots from ri onwards
    // using factory positions from fi onwards
    vector<vector<ll>> dp;

    // Recursive DP function
    ll solve(vector<int>& robot, vector<int>& positions, int ri, int fi) {
        // Base case: all robots assigned
        if (ri == robot.size()) {
            return 0;
        }

        // Base case: no factory positions left
        if (fi == positions.size()) {
            return 1e18;
        }

        // Return memoized result
        if (dp[ri][fi] != -1) {
            return dp[ri][fi];
        }

        // Option 1: Skip current factory slot
        ll skip = solve(robot, positions, ri, fi + 1);

        // Option 2: Assign current robot to current factory slot
        ll take = 1e18;
        ll next = solve(robot, positions, ri + 1, fi + 1);

        if (next != 1e18) {
            take = abs((long long)robot[ri] - positions[fi]) + next;
        }

        // Store minimum answer
        return dp[ri][fi] = min(take, skip);
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // Sort robots and factories for optimal assignment
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> positions;

        // Expand factory capacities into individual positions
        for (auto& f : factory) {
            for (int i = 0; i < f[1]; i++) {
                positions.push_back(f[0]);
            }
        }

        int n = robot.size();
        int m = positions.size();

        // Initialize DP table with -1
        dp.assign(n + 1, vector<ll>(m + 1, -1));

        return solve(robot, positions, 0, 0);
    }
};

int main() {
    int n, m;

    // Input number of robots
    cout << "Enter number of robots: ";
    cin >> n;

    vector<int> robot(n);

    // Input robot positions
    cout << "Enter robot positions: ";
    for (int i = 0; i < n; i++) {
        cin >> robot[i];
    }

    // Input number of factories
    cout << "Enter number of factories: ";
    cin >> m;

    vector<vector<int>> factory(m, vector<int>(2));

    // Input factory position and capacity
    cout << "Enter factory position and capacity:\n";
    for (int i = 0; i < m; i++) {
        cin >> factory[i][0] >> factory[i][1];
    }

    Solution obj;

    // Output minimum total distance
    cout << "Minimum total distance: "
         << obj.minimumTotalDistance(robot, factory) << endl;

    return 0;
}