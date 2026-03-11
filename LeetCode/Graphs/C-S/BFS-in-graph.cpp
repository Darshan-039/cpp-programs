#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform BFS starting from vertex 0
vector<int> bfsTraversal(int n, vector<vector<int>> &adj) {
    vector<int> ans;
    // Use a vector for visited status for better performance with fixed 'n'
    vector<bool> visited(n, false);
    queue<int> q;

    // The problem specifically requires starting BFS from vertex 0
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int fNode = q.front();
        q.pop();
        ans.push_back(fNode);

        // Traversal proceeds from left to right as per the input list order
        for (int neighbor : adj[fNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return ans;
}

int main() {
    // Example from Sample Input 1
    // n = 8 (vertices 0 to 7)
    int n = 8;

    // Building the Adjacency List
    // Index i contains the neighbors of vertex i
    vector<vector<int>> adj(n);
    adj[0] = {1, 2, 3}; // Vertex 0 connects to 1, 2, 3
    adj[1] = {4, 7};    // Vertex 1 connects to 4, 7
    adj[2] = {5};       // Vertex 2 connects to 5
    adj[3] = {6};       // Vertex 3 connects to 6
    adj[4] = {};        // Leaf node
    adj[5] = {};        // Leaf node
    adj[6] = {};        // Leaf node
    adj[7] = {};        // Leaf node

    // Execute BFS
    vector<int> result = bfsTraversal(n, adj);

    // Print output: 0 1 2 3 4 7 5 6
    cout << "BFS Traversal starting from vertex 0: " << endl;
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}