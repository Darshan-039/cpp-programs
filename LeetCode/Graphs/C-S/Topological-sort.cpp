#include <bits/stdc++.h>
using namespace std;

// DFS Helper function
void toposort(int node, vector<bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj) {
    visited[node] = true;

    for(auto neighbour : adj[node]) {
        if(!visited[neighbour]) {
            toposort(neighbour, visited, s, adj);
        }
    }

    // Push to stack only after all neighbors are visited (Post-order)
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    // 1. Create Adjacency List
    unordered_map<int, list<int>> adj;
    for(int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v_node = edges[i][1]; // Renamed from 'v' to avoid conflict with parameter 'v'
        adj[u].push_back(v_node);
    }

    // 2. Initialize visited array
    vector<bool> visited(v, false);
    stack<int> s;

    // 3. Call DFS for all unvisited nodes
    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            toposort(i, visited, s, adj);
        }
    }

    // 4. Pop elements from stack to get topological order
    vector<int> ans;
    while(!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    
    return ans;
}

int main() {
    /* Sample Input 1:
       v = 3, e = 2
       Edges: 0 -> 1, 0 -> 2
    */
    int v = 3;
    int e = 2;
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2}
    };

    cout << "Topological Sort for Sample Input:" << endl;
    vector<int> result = topologicalSort(edges, v, e);

    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    /* Sample Input 2 (Complex DAG):
       v = 4, e = 4
       0 -> 1, 0 -> 3, 1 -> 2, 3 -> 2
    */
    v = 4;
    e = 4;
    edges = {{0, 1}, {0, 3}, {1, 2}, {3, 2}};
    
    cout << "\nTopological Sort for Complex DAG:" << endl;
    result = topologicalSort(edges, v, e);
    for (int node : result) {
        cout << node << " ";
    }
    
    return 0;
}