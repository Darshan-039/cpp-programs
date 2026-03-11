#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

// Comparator to sort edges by weight
bool cmp(vector<int> &a, vector<int> &b) {
    return a[2] < b[2];
}

// Find with path compression
int findParent(vector<int> &parent, int node) {
    if(parent[node] == node) return node;
    return parent[node] = findParent(parent, parent[node]);
}

// Union by rank
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findParent(parent, u);
    v = findParent(parent, v);

    if(rank[u] < rank[v]) parent[u] = v;
    else if(rank[v] < rank[u]) parent[v] = u;
    else {
        parent[v] = u;
        rank[u]++;
    }
}

// Kruskal MST
int minimumSpanningTree(vector<vector<int>>& edges, int n) {
    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n);
    vector<int> rank(n, 0);

    for(int i = 0; i < n; i++)
        parent[i] = i;

    int minWeight = 0;

    for(int i = 0; i < edges.size(); i++) {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int w = edges[i][2];

        if(u != v) {
            minWeight += w;
            unionSet(u, v, parent, rank);
        }
    }

    return minWeight;
}

int main() {
    int n, m;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<int>> edges;

    cout << "Enter edges (u v weight):\n";
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int ans = minimumSpanningTree(edges, n);
    cout << "MST Total Weight: " << ans << endl;

    return 0;
}