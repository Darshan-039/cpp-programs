#include <bits/stdc++.h>
using namespace std;

// Your Dijkstra Function
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int, list<pair<int, int>>> adj;
    for(int i = 0; i < edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
    }

    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;

    set<pair<int, int>> s;
    s.insert({0, source});

    while(!s.empty()) {
        auto top = *(s.begin());
        s.erase(s.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        for(auto neighbour : adj[topNode]) {
            // Check for overflow safety before adding
            if(nodeDistance != INT_MAX && nodeDistance + neighbour.second < dist[neighbour.first]) {
                
                auto record = s.find({dist[neighbour.first], neighbour.first});
                if(record != s.end()) {
                    s.erase(record);
                }

                dist[neighbour.first] = nodeDistance + neighbour.second;
                s.insert({dist[neighbour.first], neighbour.first});
            }
        }
    }
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