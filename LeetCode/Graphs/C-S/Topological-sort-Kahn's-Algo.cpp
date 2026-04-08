#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    // 1. Create Adjacency List
    unordered_map<int, list<int>> adj;
    for(int i = 0; i < e; i++) {
        int u = edges[i][0];
        int neighbor = edges[i][1]; // renamed 'v' to 'neighbor' to avoid confusion with parameter 'v'
        adj[u].push_back(neighbor);
    }

    vector<int> ans;

    // 2. Find all indegrees
    vector<int> indegree(v, 0); // initialize with 0
    for(auto i : adj) {
        for(int j : i.second) {
            indegree[j]++;
        }
    }

    // 3. Push nodes with 0 indegree into queue
    queue<int> q;
    for(int i = 0; i < v; i++) {
        if(indegree[i] == 0) q.push(i);
    }

    // 4. Do BFS
    while(!q.empty()) {
        int fNode = q.front();
        q.pop();
        ans.push_back(fNode);

        for(auto neighbour : adj[fNode]) {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0) q.push(neighbour);
        }
    }
    
    return ans;
}

int main() {
    // --- Input Data ---
    int v = 6; // Number of vertices (0 to 5)
    int e = 6; // Number of edges
    
    // Edges representing a Directed Acyclic Graph (DAG)
    // Example: 5->0, 5->2, 2->3, 3->1, 4->1, 4->0
    vector<vector<int>> edges = {
        {5, 0}, {5, 2}, {2, 3}, {3, 1}, {4, 1}, {4, 0}
    };

    // --- Execution ---
    vector<int> result = topologicalSort(edges, v, e);

    // --- Output ---
    cout << "Topological Sort Order: ";
    for(int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}