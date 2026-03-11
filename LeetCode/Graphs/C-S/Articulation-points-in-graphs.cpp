#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;


void dfs(int node, int parent,
        vector<int> &disc,
        vector<int> &low,
        unordered_map<int, bool> &visited,
        unordered_map<int, list<int>> &adj,
        vector<int> &ap,
        int timer) {


    visited[node] = true;
    disc[node] = low[node] = timer++;

    // count children of DFS tree (important for root case)
    int child = 0;

    for(auto nbr : adj[node]) {

        // ignore edge back to parent
        if(parent == nbr) 
            continue;

        // Case 1: neighbour not visited ? DFS call
        if(!visited[nbr]) {

            dfs(nbr, node, disc, low, visited, adj, ap, timer);

            // update low value after returning from DFS
            low[node] = min(low[node], low[nbr]);

            /*
                Articulation Point condition:

                If neighbour subtree cannot reach an ancestor
                of current node, then removing this node
                disconnects the graph.
            */
            if(low[nbr] >= disc[node] && parent != -1)
                ap[node] = 1;

            child++;
        }
        else {
            /*
                Back edge found:
                update low value using neighbour's discovery time
            */
            low[node] = min(low[node], disc[nbr]);
        }
    }

    /*
        Special case for ROOT node:
        Root is AP if it has more than one child
    */
    if(parent == -1 && child > 1)
        ap[node] = 1;
}

int main() {

    int n = 5;   
    int e = 5;  

    vector<pair<int,int>> edges;
    edges.push_back({0,3});
    edges.push_back({3,4});
    edges.push_back({0,4});
    edges.push_back({0,1});
    edges.push_back({1,2});

    unordered_map<int, list<int>> adj;

    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    int timer = 0;
    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    unordered_map<int, bool> visited;
    vector<int> ap(n, 0);


    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, -1, disc, low, visited, adj, ap, timer);
        }
    }

    // print articulation points
    cout << "Articulation Points: ";
    for(int i = 0; i < n; i++) {
        if(ap[i])
            cout << i << " ";
    }
}