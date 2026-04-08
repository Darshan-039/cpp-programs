#include <bits/stdc++.h> 
using namespace std;

/*
    Function: calculatePrimsMST
    --------------------------------
    Finds Minimum Spanning Tree using Prim's Algorithm.

    n -> number of nodes
    m -> number of edges
    g -> edge list in form {{u,v}, weight}

    Returns:
    List of edges that belong to MST
*/
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g) {    
    // Adjacency list:
    // adj[u] = { {v, weight}, ... }
    vector<vector<pair<int, int>>> adj(n + 1);

    // Convert edge list → adjacency list
    for(int i = 0; i < m; i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        // Undirected graph
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }


    vector<int> key(n + 1, INT_MAX);
    vector<bool> MST(n + 1, false);
    vector<int> parent(n + 1, -1);

    /*
        Min Heap (priority queue)
        Stores: {edgeWeight, node}
        Smallest weight always comes first
    */
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

    // Start Prim's from node 1
    key[1] = 0;
    pq.push({0, 1});

    // Process nodes until heap becomes empty
    while(!pq.empty()) {

        // Extract node having minimum key value
        int u = pq.top().second;
        pq.pop();

        // Skip if already included in MST
        if (MST[u]) continue;

        // Mark node as included in MST
        MST[u] = true;

        // Traverse all adjacent nodes
        for(auto it : adj[u]) {
            int v = it.first;   // neighbour
            int w = it.second;  // edge weight

            /*
                Update key if:
                1. Node not yet in MST
                2. Found smaller edge weight
            */
            if (!MST[v] && w < key[v]) {
                parent[v] = u;
                key[v] = w;
                pq.push({key[v], v});
            }
        }
    }

    // Store final MST edges
    vector<pair<pair<int, int>, int>> ans;

    for(int i = 1; i <= n; i++) {
        if(parent[i] != -1) {
            ans.push_back({{parent[i], i}, key[i]});
        }
    }

    return ans;
}

int main() {
    int n, m;

    // Input number of nodes and edges
    cout << "Enter number of nodes and edges: ";
    if (!(cin >> n >> m)) return 0;

    vector<pair<pair<int, int>, int>> edges;

    // Input edges
    cout << "Enter edges (u v weight):" << endl;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({{u, v}, w});
    }

    // Call Prim's Algorithm
    vector<pair<pair<int, int>, int>> mst =
        calculatePrimsMST(n, m, edges);

    // Print MST edges
    cout << "\nEdges in the Minimum Spanning Tree:" << endl;

    int totalWeight = 0;
    for(auto &edge : mst) {
        cout << edge.first.first
             << " - "
             << edge.first.second
             << " (Weight: "
             << edge.second << ")"
             << endl;

        totalWeight += edge.second;
    }

    // Print total MST weight
    cout << "Total MST Weight: " << totalWeight << endl;

    return 0;
}