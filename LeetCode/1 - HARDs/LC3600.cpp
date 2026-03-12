// Leetcode 3600. Count Ways to Build Rooms in an Ant Colony





#include <bits/stdc++.h>
using namespace std;

/*
    DSU (Disjoint Set Union) / Union Find
    Used to efficiently manage connected components in a graph.
*/
class DSU {
public:
    vector<int> parent, rank;

    // Constructor
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);

        // Initially every node is its own parent
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    // Find the ultimate parent of a node (with path compression)
    int findParent(int node) {
        if(parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    // Union two sets
    bool Union(int x, int y) {
        int parent_x = findParent(x);
        int parent_y = findParent(y);

        // Already in same component
        if(parent_x == parent_y)
            return false;

        // Union by rank
        if(rank[parent_x] < rank[parent_y]) {
            parent[parent_x] = parent_y;
        }
        else if(rank[parent_x] > rank[parent_y]) {
            parent[parent_y] = parent_x;
        }
        else {
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }

        return true;
    }
};

class Solution {
public:

    /*
        This function checks if it is possible to make the graph connected
        with stability >= mid using at most k upgrades.
    */
    bool check(int n, vector<vector<int>>& edges, int k, int mid) {

        DSU dsu(n);
        vector<vector<int>> upgradeCandidate;

        for(auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int s = edge[2]; // stability
            int m = edge[3]; // mandatory edge flag

            // If edge is mandatory
            if(m == 1) {

                // Mandatory edge must satisfy stability condition
                if(s < mid)
                    return false;

                dsu.Union(u, v);
            }
            else {

                // Normal edge with enough stability
                if(s >= mid)
                    dsu.Union(u, v);

                // Edge that can become valid after upgrade
                else if(2 * s >= mid)
                    upgradeCandidate.push_back({u, v});
            }
        }

        // Try using upgrade candidates
        for(auto &edge : upgradeCandidate) {

            int u = edge[0];
            int v = edge[1];

            if(dsu.findParent(u) != dsu.findParent(v)) {

                if(k <= 0)
                    return false;

                dsu.Union(u, v);
                k--;
            }
        }

        // Check if graph becomes fully connected
        int root = dsu.findParent(0);

        for(int node = 1; node < n; node++) {
            if(dsu.findParent(node) != root)
                return false;
        }

        return true;
    }

    /*
        Binary search to find maximum stability value
        such that graph remains connected.
    */
    int maxStability(int n, vector<vector<int>>& edges, int k) {

        DSU dsu(n);

        // Check mandatory edges for cycle
        for(auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int s = edge[2];
            int m = edge[3];

            if(m == 1) {

                // If mandatory edges create cycle → impossible
                if(dsu.findParent(u) == dsu.findParent(v))
                    return -1;

                dsu.Union(u, v);
            }
        }

        int result = -1;

        int l = 1;
        int r = 2 * 1e5;

        while(l <= r) {

            int mid = l + (r - l) / 2;

            if(check(n, edges, k, mid)) {
                result = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }

        return result;
    }
};

int main() {

    int n, m, k;

    cout << "Enter number of nodes, edges, upgrades: ";
    cin >> n >> m >> k;

    vector<vector<int>> edges;

    cout << "Enter edges in format: u v stability mandatory(0/1)\n";

    for(int i = 0; i < m; i++) {

        int u, v, s, mandatory;
        cin >> u >> v >> s >> mandatory;

        edges.push_back({u, v, s, mandatory});
    }

    Solution obj;

    int ans = obj.maxStability(n, edges, k);

    cout << "Maximum Stability: " << ans << endl;

    return 0;
}