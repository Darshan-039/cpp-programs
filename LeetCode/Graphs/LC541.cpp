// Leetcode 541. Number of Provinces



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // DFS function to visit all connected cities
    void DFS(int city, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[city] = true; // mark current city as visited

        // explore all neighboring cities
        for (int i = 0; i < isConnected.size(); i++) {
            // if there is a connection and not visited yet
            if (isConnected[city][i] == 1 && !visited[i]) {
                DFS(i, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        // visited array to track visited cities
        vector<bool> visited(n, false);

        int provinces = 0; // count of connected components

        // traverse all cities
        for (int i = 0; i < n; i++) {
            // if city is not visited, it's a new province
            if (!visited[i]) {
                DFS(i, isConnected, visited);
                provinces++; // increment province count
            }
        }

        return provinces;
    }
};

int main() {
    Solution obj;

    // Example input:
    // 3 cities
    // Adjacency matrix representation
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    // Expected output: 2 provinces
    cout << "Number of Provinces: " << obj.findCircleNum(isConnected) << endl;

    return 0;
}