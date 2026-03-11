#include <iostream>
#include <unordered_map>
#include <stack>
#include <list>
#include <vector>
using namespace std;

/*
    Step 3: DFS on Transposed Graph
    This DFS marks all nodes in one SCC.
*/
void DFS(int node, unordered_map<int, bool> &visited,
         unordered_map<int, list<int>> &transpose) {

    visited[node] = true;

    for(auto nbr : transpose[node]) {
        if(!visited[nbr]) {
            DFS(nbr, visited, transpose);
        }
    }
}

/*
    Step 1: Topological Sort using DFS
    Push nodes to stack according to finishing time.
*/
void topoSort(int node,
              unordered_map<int, bool> &visited,
              stack<int> &st,
              unordered_map<int, list<int>> &adj) {

    visited[node] = true;

    for(auto nbr : adj[node]) {
        if(!visited[nbr]) {
            topoSort(nbr, visited, st, adj);
        }
    }

    // Push after visiting all neighbours
    st.push(node);
}

/*
    Kosaraju’s Algorithm:
    1. Topological sort
    2. Reverse edges (Transpose graph)
    3. DFS using stack order
*/
int stronglyConnectedComponents(int vertices,
                                 vector<vector<int>> &edges) {

    // Step 0: Create adjacency list
    unordered_map<int, list<int>> adj;

    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    // Step 1: Topological Sort
    stack<int> st;
    unordered_map<int, bool> visited;

    for(int i = 0; i < vertices; i++) {
        if(!visited[i]) {
            topoSort(i, visited, st, adj);
        }
    }

    // Step 2: Transpose Graph
    unordered_map<int, list<int>> transpose;

    for(int i = 0; i < vertices; i++) {
        visited[i] = false;  // reset visited

        for(auto nbr : adj[i]) {
            transpose[nbr].push_back(i);
        }
    }

    // Step 3: DFS using stack order
    int count = 0;

    while(!st.empty()) {
        int node = st.top();
        st.pop();

        if(!visited[node]) {
            count++;
            DFS(node, visited, transpose);
        }
    }

    return count;
}


/* ================= MAIN FUNCTION ================= */

int main() {

    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(2));

    cout << "Enter edges (u v):\n";
    for(int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    int ans = stronglyConnectedComponents(V, edges);

    cout << "Number of Strongly Connected Components: " << ans << endl;

    return 0;
}