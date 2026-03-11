// Problem: LeetCode 815 - Bus Routes



#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        // 1. Build a Map: Stop ID -> List of Bus Indices
        unordered_map<int, vector<int>> stopToBuses;
        for (int i = 0; i < routes.size(); i++) {
            for (int stop : routes[i]) {
                stopToBuses[stop].push_back(i);
            }
        }

        // 2. BFS Setup
        queue<int> q; 
        vector<bool> visitedBus(routes.size(), false);
        unordered_set<int> visitedStop;

        for (int busIndex : stopToBuses[source]) {
            q.push(busIndex);
            visitedBus[busIndex] = true;
        }

        int busCount = 1;

        // 3. Start BFS
        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                int currentBus = q.front();
                q.pop();

                for (int stop : routes[currentBus]) {
                    if (stop == target) return busCount;

                    if (visitedStop.count(stop)) continue;
                    visitedStop.insert(stop);

                    for (int nextBus : stopToBuses[stop]) {
                        if (!visitedBus[nextBus]) {
                            visitedBus[nextBus] = true;
                            q.push(nextBus);
                        }
                    }
                }
            }
            busCount++;
        }
        return -1;
    }
};

int main() {
    Solution sol;

    // Hardcoded Input Example
    // Route 0: Stops 1, 2, 7
    // Route 1: Stops 3, 6, 7
    vector<vector<int>> routes = {{1, 2, 7}, {3, 6, 7}};
    int source = 1;
    int target = 6;

    int result = sol.numBusesToDestination(routes, source, target);

    // Output result
    cout << "Minimum buses required: " << result << endl;

    return 0;
}