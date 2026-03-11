#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> mp;

        // Populate map with remainders
        for(int &i: time) {
            i %= 60;
            mp[i]++;
        }

        long long ans = 0;

        // Calculate pairs based on remainder logic
        for(auto& [rem, count] : mp) {
            if(rem == 0 || rem == 30) {
                // Special cases: pairs with themselves
                ans += (long long)count * (count - 1) / 2;
            } 
            else if(rem < 30) {
                // General cases: pair rem with (60 - rem)
                int target = 60 - rem;
                if(mp.find(target) != mp.end()) {
                    ans += (long long)count * mp[target];
                }
            }
        }

        return (int)ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> input1 = {30, 20, 150, 100, 40};
    // Explain: 
    // (20, 40) -> 60
    // (150%60=30, 30) -> 60
    // (100%60=40, 20) -> 60
    cout << "Test 1: " << sol.numPairsDivisibleBy60(input1) << " (Expected: 3)" << endl;

    // Test Case 2
    vector<int> input2 = {60, 60, 60};
    // Explain:
    // (60, 60), (60, 60), (60, 60) -> 3 pairs
    cout << "Test 2: " << sol.numPairsDivisibleBy60(input2) << " (Expected: 3)" << endl;

    return 0;
}