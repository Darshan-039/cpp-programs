// Leetcode 3296. Minimum Number of Seconds to Build a Mountain




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;

    // 🔹 Check if we can build mountain of height >= mountainHeight in 'mid' seconds
    bool check(ll mid, vector<int>& workerTimes, int mountainHeight) {
        ll h = 0; // total height built

        for(int &t : workerTimes) {

            // Formula derived from:
            // t * (k * (k + 1)) / 2 <= mid
            // Solve quadratic → k ≈ sqrt(2*mid/t + 0.25) - 0.5
            ll k = (ll)(sqrt(2.0 * mid / t + 0.25) - 0.5);

            h += k;

            // Early stop if already enough
            if(h >= mountainHeight) return true;
        }

        return h >= mountainHeight;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int maxTime = *max_element(workerTimes.begin(), workerTimes.end());

        // 🔹 Binary search range
        ll l = 1;
        ll r = (ll)maxTime * mountainHeight * (mountainHeight + 1) / 2;

        ll result = 0;

        while(l <= r) {
            ll mid = l + (r - l) / 2;

            if(check(mid, workerTimes, mountainHeight)) {
                result = mid;     // possible answer
                r = mid - 1;      // try smaller time
            } else {
                l = mid + 1;      // need more time
            }
        }

        return result;
    }
};

int main() {
    Solution obj;

    // 🔹 Sample Input
    int mountainHeight = 10;
    vector<int> workerTimes = {1, 2, 3};

    // 🔹 Function call
    long long result = obj.minNumberOfSeconds(mountainHeight, workerTimes);

    // 🔹 Output
    cout << "Minimum seconds required: " << result << endl;

    return 0;
}