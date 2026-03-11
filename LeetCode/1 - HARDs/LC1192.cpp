// Leetcode 1192. Critical Connections in a Network




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int node, int parent, int &timer,
             vector<int>& disc,
             vector<int>& low,
             vector<vector<int>>& result,
             vector<vector<int>>& adj,
             vector<int>& visited) {

        visited[node] = 1;
        disc[node] = low[node] = timer++;

        for(int neighbour : adj[node]) {

            if(neighbour == parent) continue;

            if(!visited[neighbour]) {
                dfs(neighbour, node, timer, disc, low, result, adj, visited);

                low[node] = min(low[node], low[neighbour]);

                if(low[neighbour] > disc[node]) {
                    result.push_back({node, neighbour});
                }
            }
            else {
                low[node] = min(low[node], disc[neighbour]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        vector<vector<int>> adj(n);
        for(int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> disc(n, -1);
        vector<int> low(n, -1);
        vector<int> visited(n, 0);
        vector<vector<int>> result;
        int timer = 0;

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(i, -1, timer, disc, low, result, adj, visited);
            }
        }

        return result;
    }
};


int main() {

    Solution obj;

    // ===== INPUT IN CODE =====
    int n = 5;

    vector<vector<int>> connections = {
        {0,1},
        {1,2},
        {2,0},
        {1,3},
        {3,4}
    };

    vector<vector<int>> ans = obj.criticalConnections(n, connections);

    cout << "Critical Connections (Bridges):\n";
    for(auto &edge : ans) {
        cout << edge[0] << " - " << edge[1] << endl;
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