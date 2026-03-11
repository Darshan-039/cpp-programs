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