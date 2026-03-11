#include <iostream>
#include <vector>
using namespace std;

int main() {

    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(3));

    cout << "Enter edges (u v weight):\n";
    for(int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    const int INF = 1e9;

    // Distance array
    vector<int> dist(V, INF);

    // Source distance = 0
    dist[src] = 0;

    // Step 1: Relax all edges (V-1) times
    for(int i = 1; i <= V - 1; i++) {

        for(int j = 0; j < E; j++) {

            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(dist[u] != INF && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Step 2: Check for negative weight cycle
    bool negativeCycle = false;

    for(int j = 0; j < E; j++) {

        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if(dist[u] != INF && dist[u] + wt < dist[v]) {
            negativeCycle = true;
            break;
        }
    }

    if(negativeCycle) {
        cout << "Graph contains negative weight cycle\n";
    } 
    else {
        cout << "Shortest distances from source:\n";
        for(int i = 0; i < V; i++) {
            cout << "Vertex " << i << " : " << dist[i] << endl;
        }
    }

    return 0;
}