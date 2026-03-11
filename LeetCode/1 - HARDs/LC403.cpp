// Leetcode 403. Frog Jump



#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>

using namespace std;

class Solution {
public:
    int n;
    unordered_map<int, int> mp;
    int t[2001][2001];

    bool solve(vector<int>& stones, int curr_stone_idx, int prevJump) {
        if(curr_stone_idx == n-1) return true;
        if(t[curr_stone_idx][prevJump] != -1) return t[curr_stone_idx][prevJump];

        bool result = false;
        for(int nextJump = prevJump-1; nextJump <= prevJump+1; nextJump++) {
            if(nextJump > 0) {
                int next_stone_val = stones[curr_stone_idx] + nextJump;   
                if(mp.count(next_stone_val)) {
                    result = result || solve(stones, mp[next_stone_val], nextJump);
                }
            }
        }
        return t[curr_stone_idx][prevJump] = result;
    }

    bool canCross(vector<int>& stones) {
        n = stones.size();
        mp.clear();
        for(int i = 0; i < n; i++) mp[stones[i]] = i;
        memset(t, -1, sizeof(t));
        
        // The problem states the first jump MUST be 1 unit from the first stone (at index 0).
        // Since your solve starts with prevJump 0, the first loop will naturally try jump 1.
        return solve(stones, 0, 0);
    }
};

int main() {
    Solution sol;
    vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};
    
    if(sol.canCross(stones)) {
        cout << "The frog can cross the river!" << endl;
    } else {
        cout << "The frog cannot cross." << endl;
    }
    return 0;
}