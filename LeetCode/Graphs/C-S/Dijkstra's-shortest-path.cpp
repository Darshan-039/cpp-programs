#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    
    // Step 1: Create adjacency list
    // Format: node -> list of {neighbour, weight}
    unordered_map<int, list<pair<int, int>>> adj;
    for(int i = 0; i < edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        // Since graph is undirected, add both directions
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
    }

    // Step 2: Initialize distance array with infinity (INT_MAX)
    vector<int> dist(vertices, INT_MAX);

    // Distance of source node from itself is 0
    dist[source] = 0;

    // Step 3: Set to store {distance, node}
    // It helps to get the minimum distance node efficiently
    set<pair<int, int>> s;
    s.insert({0, source});

    // Step 4: Dijkstra's algorithm
    while(!s.empty()) {

        // Get node with smallest distance
        auto top = *(s.begin());
        s.erase(s.begin());

        int nodeDistance = top.first; // current shortest distance
        int topNode = top.second;     // current node

        // Traverse all neighbours of current node
        for(auto neighbour : adj[topNode]) {

            int neighbourNode = neighbour.first;
            int weight = neighbour.second;

            // Check if new distance is shorter than existing one
            // Also avoid overflow using nodeDistance != INT_MAX
            if(nodeDistance != INT_MAX && nodeDistance + weight < dist[neighbourNode]) {
                
                // If neighbour already exists in set, remove old record
                auto record = s.find({dist[neighbourNode], neighbourNode});
                if(record != s.end()) s.erase(record);

                // Update distance
                dist[neighbourNode] = nodeDistance + weight;

                // Insert updated distance into set
                s.insert({dist[neighbourNode], neighbourNode});
            }
        }
    }

    // Step 5: Return shortest distances from source to all nodes
    return dist;
}

int main() {
    // --- SAMPLE INPUT ---
    int vertices = 4;
    int edges = 5;
    int source = 0;

    // edge list format: {u, v, weight}
    vector<vector<int>> vec = {
        {0, 1, 5},
        {0, 2, 8},
        {1, 2, 9},
        {1, 3, 2},
        {2, 3, 6}
    };

    // Execute Algorithm
    vector<int> result = dijkstra(vec, vertices, edges, source);

    // --- OUTPUT ---
    cout << "Shortest distances from source node " << source << ":" << endl;
    for(int i = 0; i < vertices; i++) {
        cout << "Node " << i << " : ";
        if(result[i] == INT_MAX) cout << "INF";
        else cout << result[i];
        cout << endl;
    }

    return 0;
}