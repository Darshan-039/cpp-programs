#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

/*
    DFS function to find bridges using Tarjan's Algorithm
*/
void dfs(int node, int parent, int &timer,
         vector<int> &disc,
         vector<int> &low,
         vector<vector<int>> &result,
         unordered_map<int, list<int>> &adj,
         unordered_map<int, bool> &visited) {

    visited[node] = true;

    disc[node] = low[node] = timer++;

    for(auto neighbour : adj[node]) {

        if(neighbour == parent)
            continue;

        if(!visited[neighbour]) {

            dfs(neighbour, node, timer, disc, low, result, adj, visited);

            // While backtracking, update low value of current node
            low[node] = min(low[node], low[neighbour]);

            // Bridge condition
            if(low[neighbour] > disc[node]) {
                result.push_back({node, neighbour});
            }
        }
        else {
            // If neighbour is already visited and is not parent, then it's a back edge
            // Update low value for back edge
            low[node] = min(low[node], disc[neighbour]);
        }
    }
}


vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {

    unordered_map<int, list<int>> adj;

    // Create adjacency list
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int w = edges[i][1];   // renamed to avoid shadowing

        adj[u].push_back(w);
        adj[w].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    unordered_map<int, bool> visited;

    vector<vector<int>> result;

    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            dfs(i, -1, timer, disc, low, result, adj, visited);
        }
    }

    return result;
}


int main() {

    // ===== INPUT IN CODE =====
    int v = 5;   // number of vertices
    int e = 5;   // number of edges

    vector<vector<int>> edges = {
        {0,1},
        {1,2},
        {2,0},
        {1,3},
        {3,4}
    };

    // Find bridges
    vector<vector<int>> bridges = findBridges(edges, v, e);

    // Print bridges
    cout << "Bridges in the graph:\n";
    for(auto &b : bridges) {
        cout << b[0] << " - " << b[1] << endl;
    }

    return 0;
}


















// Approach - 2 (Brute Force - Check connectivity after removing each edge)

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<int> &visited) {
    visited[node] = 1;

    for(int neighbour : adj[node]) {
        if(!visited[neighbour]) {
            dfs(neighbour, adj, visited);
        }
    }
}

// function to check if graph is connected
bool isConnected(int n, vector<vector<int>> &adj) {
    vector<int> visited(n, 0);

    dfs(0, adj, visited);

    for(int i = 0; i < n; i++) {
        if(!visited[i]) return false;
    }
    return true;
}

int main() {

    // ===== INPUT =====
    int n = 5;
    vector<vector<int>> edges = {
        {0,1},
        {1,2},
        {2,0},
        {1,3},
        {3,4}
    };

    // build adjacency list
    vector<vector<int>> adj(n);
    for(auto &e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    cout << "Bridges:\n";

    // check each edge
    for(auto &e : edges) {
        int u = e[0];
        int v = e[1];

        // remove edge u-v
        adj[u].erase(find(adj[u].begin(), adj[u].end(), v));
        adj[v].erase(find(adj[v].begin(), adj[v].end(), u));

        // check connectivity
        if(!isConnected(n, adj)) {
            cout << u << " - " << v << endl;
        }

        // add edge back
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return 0;
}