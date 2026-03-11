// Leetcode 495 :- Teemo Attacking

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total = 0;
        int n = timeSeries.size();
        
        for(int i = 0; i < n - 1; i++) {
            int diff = timeSeries[i+1] - timeSeries[i];
            total += min(diff, duration);  // Add only non-overlapping part
        }
        
        return total + duration;  // Last attack always adds full duration
    }
};

int main() {
    // ✅ I created the input here
    vector<int> timeSeries = {2, 5, 6, 10};
    int duration = 4;

    Solution s;
    int result = s.findPoisonedDuration(timeSeries, duration);

    cout << "Output = " << result << endl;

    return 0;
}
