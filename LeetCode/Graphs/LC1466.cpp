// Leetcode 1466. Reorder Routes to Make All Paths Lead to the City Zero


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int count = 0; // stores number of edges to reverse

    // DFS traversal
    void DFS(int node, int parent, unordered_map<int, vector<pair<int, int>>> &adj) {

        // Traverse all neighbors of current node
        for(auto &nbr : adj[node]) {

            int v = nbr.first;   // neighbor node
            int check = nbr.second; // direction flag

            // Avoid going back to parent
            if(v != parent) {

                // If edge is originally directed away from 0 → needs reversal
                if(check == 1) count++;

                // DFS on neighbor
                DFS(v, node, adj);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {

        // Step 1: Create adjacency list
        // {neighbor, direction}
        // direction = 1 → original edge (u → v)
        // direction = 0 → reverse edge (v → u)
        unordered_map<int, vector<pair<int, int>>> adj;

        for(auto &P : connections) {
            int u = P[0];
            int v = P[1];

            adj[u].push_back({v, 1}); // original direction
            adj[v].push_back({u, 0}); // reverse direction
        }

        // Step 2: DFS from node 0
        DFS(0, -1, adj);

        // Step 3: return number of changes needed
        return count;
    }
};

int main() {
    int n, m;

    // Input number of nodes
    cout << "Enter number of cities (n): ";
    cin >> n;

    // Input number of connections
    cout << "Enter number of connections: ";
    cin >> m;

    vector<vector<int>> connections(m, vector<int>(2));

    // Input edges
    cout << "Enter connections (u v):" << endl;
    for(int i = 0; i < m; i++) {
        cin >> connections[i][0] >> connections[i][1];
    }

    Solution obj;

    // Function call
    int result = obj.minReorder(n, connections);

    // Output result
    cout << "Minimum edges to reorder: " << result << endl;

    return 0;
}