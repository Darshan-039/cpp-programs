#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
    // ... (your existing class methods: topologicalSort and shortestPath) ...
public:
    void topologicalSort(int node, stack<int> &s, vector<bool> &visited, unordered_map<int, list<pair<int, int>>> &adj) {
        visited[node] = true;
        for(auto neighbour: adj[node]) {
            if(!visited[neighbour.first]) {
                topologicalSort(neighbour.first, s, visited, adj);
            }
        }
        s.push(node);
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        unordered_map<int, list<pair<int, int>>> adj;
        for(int i = 0; i < E; i++) {   
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adj[u].push_back({v, w});
        }
       
        stack<int> s;
        vector<bool> visited(V, false); 
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                topologicalSort(i, s, visited, adj);
            }
        }
        
        vector<int> dist(V, 1e9);
        dist[0] = 0; 
        
        while(!s.empty()) {
            int top = s.top();
            s.pop();
            
            if(dist[top] == 1e9) continue;
            
            for(auto i: adj[top]) {
                int nextNode = i.first;
                int weight = dist[top] + i.second;
                dist[nextNode] = min(dist[nextNode], weight);
            }
        }
        
        for(int i = 0; i < V; i++) {
            if(dist[i] == 1e9) dist[i] = -1;
        }
        
        return dist;
    }
};

int main() {
    Solution sol;

    // --- SAMPLE INPUT ---
    // Nodes: 6, Edges: 7
    int V = 6;
    int E = 7;
    
    // edges[i] = {u, v, weight}
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 4, 1},
        {1, 2, 3},
        {4, 2, 2},
        {4, 5, 4},
        {2, 3, 6},
        {5, 3, 1}
    };

    // Call the function
    vector<int> result = sol.shortestPath(V, E, edges);

    // Output the distances
    cout << "Shortest distances from node 0:" << endl;
    for (int i = 0; i < V; i++) {
        cout << "To node " << i << " : " << result[i] << endl;
    }

    return 0;
}