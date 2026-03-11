
// BFS

#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
#include <vector>
#include <string>

using namespace std;

// BFS-based function to detect a cycle in a single connected component
bool isCycle(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &mp) {
    // Map to keep track of the parent of each node to avoid moving back to the immediate parent
    unordered_map<int, int> parent;

    parent[src] = -1; // Source node has no parent
    visited[src] = true;
    queue<int> q;
    q.push(src);

    while(!q.empty()) {
        int fNode = q.front();
        q.pop();

        for(auto neighbour : mp[fNode]) {
            // If the neighbor is already visited and is NOT the parent of the current node, it's a cycle
            if(visited[neighbour] && neighbour != parent[fNode]) {
                return true;
            }
            // If the neighbor is not visited, mark it, set its parent, and push to queue
            else if(!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = fNode;
            }
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>>& edges, int n, int m) {  
    // 1. Create Adjacency List
    // We loop up to 'm' because 'm' represents the number of edges
    unordered_map<int, list<int>> mp;
    for(int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        mp[u].push_back(v);
        mp[v].push_back(u); // Undirected graph means edges go both ways
    }

    // 2. To handle disconnected components (islands in the graph)
    unordered_map<int, bool> visited;
    // The problem states vertices are labeled from 1 to 'N'
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            bool ans = isCycle(i, visited, mp);
            if(ans) return "Yes";
        }
    }

    return "No";
}

int main() {
    // Sample Input: N=3, M=3, Edges=[[1, 2], [2, 3], [1, 3]]
    int n = 3; 
    int m = 3;
    vector<vector<int>> edges = {
        {1, 2},
        {2, 3},
        {1, 3}
    };

    // Should output "Yes" because 1-2-3-1 forms a triangle (cycle)
    cout << "Cycle present: " << cycleDetection(edges, n, m) << endl;

    // Test Case 2: No Cycle
    int n2 = 3;
    int m2 = 2;
    vector<vector<int>> edges2 = {
        {1, 2},
        {2, 3}
    };
    
    // Should output "No"
    cout << "Cycle present: " << cycleDetection(edges2, n2, m2) << endl;

    return 0;
}





















// DFS

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <string>

using namespace std;

// Recursive DFS function to detect cycle
bool isCycle(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &mp, int parent) {
    // 1. Mark the current node as visited
    visited[node] = true;

    // 2. Explore all neighbors of the current node
    for(auto neighbors : mp[node]) {
        // If neighbor is not visited, move deeper into the graph
        if(!visited[neighbors]) {
            bool isCycleDetected = isCycle(neighbors, visited, mp, node);
            if(isCycleDetected) return true;
        }
        // If neighbor is visited AND it is not the parent of the current node, a cycle is found
        else if(neighbors != parent) {
            return true;
        }
    }

    return false;
}

string cycleDetection(vector<vector<int>>& edges, int n, int m) {  
    // 3. Build Adjacency List for an undirected graph
    unordered_map<int, list<int>> mp;
    for(int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        mp[u].push_back(v);
        mp[v].push_back(u); 
    }

    // 4. Track visited nodes across disconnected components
    unordered_map<int, bool> visited;
    for(int i = 1; i <= n; i++) { // Nodes are 1 to N
        if(!visited[i]) {
            // Start DFS from the current unvisited node with parent as -1
            bool ans = isCycle(i, visited, mp, -1);
            if(ans) return "Yes";
        }
    }

    return "No";
}

int main() {
    // SAMPLE INPUT 1: A graph with 3 nodes and 3 edges forming a cycle
    int n = 3;
    int m = 3;
    vector<vector<int>> edges = {
        {1, 2},
        {2, 3},
        {1, 3}
    };

    cout << "Test Case 1 (Cycle): " << cycleDetection(edges, n, m) << endl; // Output: Yes

    // SAMPLE INPUT 2: A graph with 3 nodes and 2 edges (no cycle)
    int n2 = 3;
    int m2 = 2;
    vector<vector<int>> edges2 = {
        {1, 2},
        {2, 3}
    };

    cout << "Test Case 2 (No Cycle): " << cycleDetection(edges2, n2, m2) << endl; // Output: No

    return 0;
}