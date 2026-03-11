// Leetcode 134. Gas Station
 
// Description:
// There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].


#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int deficit = 0;
        int balance = 0;
        int start = 0;
        int n = gas.size();
        
        for(int i = 0; i < n; i++) {
            balance += gas[i] - cost[i];
            
            if(balance < 0) {
                deficit += balance;
                start = i + 1;
                balance = 0;
            }
        }
        
        if(deficit + balance >= 0) return start;
        else return -1;
    }
};

int main() {
    Solution sol;

    // Example Input
    // gas:  [1, 2, 3, 4, 5]
    // cost: [3, 4, 5, 1, 2]
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    int result = sol.startStation(gas, cost);

    if (result != -1) {
        cout << "Start at station index: " << result << endl;
    } else {
        cout << "No possible starting station exists." << endl;
    }

    return 0;
}