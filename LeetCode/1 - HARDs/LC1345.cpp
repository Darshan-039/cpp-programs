#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) mp[arr[i]].push_back(i);

        queue<int> q;
        q.push(0);
        vector<bool> visited(n, false);
        visited[0] = true;

        int step = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int curr = q.front();
                q.pop();

                if(curr == n - 1) return step;

                // Neighbors: Forward, Backward, and Same Value
                vector<int>& neighbors = mp[arr[curr]];
                neighbors.push_back(curr - 1);
                neighbors.push_back(curr + 1);

                for(int next : neighbors) {
                    if(next >= 0 && next < n && !visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
                // Crucial: clear the list so we don't re-process these same-value jumps
                mp[arr[curr]].clear(); 
            }
            step++;
        }
        return step;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};
    cout << "Minimum Jumps: " << sol.minJumps(arr) << endl; // Output: 3
    return 0;
}