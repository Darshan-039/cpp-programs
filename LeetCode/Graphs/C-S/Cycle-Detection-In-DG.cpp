


// DFS


#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

// Added '&' to pass maps by reference, otherwise state is lost in recursion
bool checkCycleDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adj) {
    visited[node] = true;
    dfsVisited[node] = true;

    for(auto neighbour : adj[node]) {
        if(!visited[neighbour]) {
            bool cycleDetected = checkCycleDFS(neighbour, visited, dfsVisited, adj);
            if(cycleDetected) return true;
        }
        else if(dfsVisited[neighbour]) {
            // If the neighbor is already in the current DFS recursion stack, a cycle exists
            return true;
        }
    }

    // Backtracking: remove the node from the current path stack
    dfsVisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
    unordered_map<int, list<int>> adj;
    // Build adjacency list (using edges.size() instead of n to avoid out-of-bounds)
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            bool cycleFound = checkCycleDFS(i, visited, dfsVisited, adj);
            if(cycleFound) return 1;
        }
    }
    return 0;
}

int main() {
    // Input: n = number of nodes, m = number of edges
    int n = 4;
    vector<pair<int, int>> edges = {
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 2} // This creates a cycle: 2 -> 3 -> 4 -> 2
    };

    if(detectCycleInDirectedGraph(n, edges)) {
        cout << "Cycle detected in the graph." << endl;
    } else {
        cout << "No cycle detected in the graph." << endl;
    }

    return 0;
}
















// BFS

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
    // 1. Create Adjacency List
    unordered_map<int, list<int>> adj;
    for(int i = 0; i < edges.size(); i++) {
        // Adjusting for 1-based to 0-based indexing as per your logic
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;
        adj[u].push_back(v);
    }

    // 2. Find all indegrees
    vector<int> indegree(n, 0);
    for(auto i : adj) {
        for(int j : i.second) {
            indegree[j]++;
        }
    }

    // 3. Push nodes with 0 indegree into queue
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) q.push(i);
    }

    // 4. Do BFS
    int cnt = 0;
    while(!q.empty()) {
        int fNode = q.front();
        q.pop();
        cnt++;

        for(auto neighbour : adj[fNode]) {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0) q.push(neighbour);
        }
    }

    // If cnt == n, we visited all nodes (No Cycle). 
    // Otherwise, a cycle exists.
    return (cnt != n); 
}

int main() {
    // --- Test Case 1: Graph with a Cycle ---
    // 1 -> 2, 2 -> 3, 3 -> 1
    int n1 = 3;
    vector<pair<int, int>> edges1 = {{1, 2}, {2, 3}, {3, 1}};
    
    // --- Test Case 2: Graph without a Cycle (DAG) ---
    // 1 -> 2, 2 -> 3
    int n2 = 3;
    vector<pair<int, int>> edges2 = {{1, 2}, {2, 3}};

    cout << "Test Case 1 (Cycle): " << (detectCycleInDirectedGraph(n1, edges1) ? "Cycle Detected" : "No Cycle") << endl;
    cout << "Test Case 2 (No Cycle): " << (detectCycleInDirectedGraph(n2, edges2) ? "Cycle Detected" : "No Cycle") << endl;

    return 0;
}