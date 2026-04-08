// BFS in graph

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














// DFS in graph

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm> // Optional: for sorting output

using namespace std;

// Helper function to perform recursive DFS traversal
void DFS(int node, unordered_map<int, list<int>> &mp, unordered_map<int, bool> &visited, vector<int> &temp) {
    // 1. Mark the current node as visited and add it to the current component list
    temp.push_back(node);
    visited[node] = true;

    // 2. Visit all neighbors of the current node that haven't been visited yet
    for(int j : mp[node]) {
        if(!visited[j]) {
            // Recursive call to explore deeper into the graph
            DFS(j, mp, visited, temp);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges) {
    // 3. Prepare the Adjacency List from the input edge list
    unordered_map<int, list<int>> mp;
    for(auto i : edges) {
        int u = i[0];
        int v = i[1];

        // Since it's an undirected graph, add edges for both directions
        mp[u].push_back(v);
        mp[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    // 4. Loop through all vertices (0 to V-1) to handle disconnected components
    for(int i = 0; i < V; i++) {
        // If a node is not visited, it belongs to a new connected component
        if(!visited[i]) {
            vector<int> component;
            // Start DFS from this node to find all nodes in this specific component
            DFS(i, mp, visited, component);
            // Store the completed component in our final answer list
            ans.push_back(component);
        }
    }

    return ans;
}

int main() {
    // Define total vertices (V) and total edges (E)
    int V = 5;
    int E = 4;

    // Define the edges as a vector of vectors
    // This represents a graph with two separate components: {0, 2, 1} and {3, 4}
    vector<vector<int>> edges = {
        {0, 2},
        {2, 1},
        {3, 4}
    };

    // Call the function
    vector<vector<int>> result = depthFirstSearch(V, E, edges);

    // Print the output
    cout << "Connected Components:" << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << "Component " << i + 1 << ": ";
        for (int node : result[i]) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}