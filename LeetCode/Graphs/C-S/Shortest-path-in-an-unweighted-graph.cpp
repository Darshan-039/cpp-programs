#include <iostream>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <list>
#include <vector>

using namespace std;

vector<int> shortestPath(vector<pair<int,int>> edges, int n, int m, int s, int t) {
    
    // 1. Create Adjacency List
    unordered_map<int, list<int>> adj;
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 2. BFS to find parents
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;

    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while(!q.empty()) {
        int fNode = q.front();
        q.pop();

        for(auto neighbor : adj[fNode]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = fNode;
                q.push(neighbor);
            }
        }
    }

    // 3. Reconstruct path from target to source
    vector<int> ans;
    int currentNode = t;
    
    // Safety check: if target was never visited, path doesn't exist
    if (visited.find(t) == visited.end()) return {};

    ans.push_back(t);
    while(currentNode != s) {
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    // --- INPUT DATA ---
    int n = 8; // Total nodes
    int m = 9; // Total edges
    
    // Defining the edges of the graph
    vector<pair<int, int>> edges = {
        {1, 2}, {1, 3}, {1, 4}, 
        {2, 5}, {5, 8}, {3, 8}, 
        {4, 6}, {6, 7}, {7, 8}
    };

    int startNode = 1;
    int endNode = 8;

    // --- CALLING THE FUNCTION ---
    vector<int> result = shortestPath(edges, n, m, startNode, endNode);

    // --- PRINTING OUTPUT ---
    cout << "The shortest path from " << startNode << " to " << endNode << " is:" << endl;
    
    if(result.empty()) {
        cout << "No path found!" << endl;
    } else {
        for(int i = 0; i < result.size(); i++) {
            cout << result[i] << (i == result.size() - 1 ? "" : " -> ");
        }
        cout << endl;
    }

    return 0;
}