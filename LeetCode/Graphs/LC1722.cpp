// Leetcode 1722. Minimize Hamming Distance After Swap Operations


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // DSU (Disjoint Set Union) structures
    vector<int> rank;
    vector<int> parent;

    // Find operation with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  // compress path
        return parent[x];
    }

    // Union operation using rank
    void Union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return;

        // Attach smaller rank tree under larger rank tree
        if (rank[rootX] < rank[rootY])
            swap(rootX, rootY);

        parent[rootY] = rootX;

        // If ranks are equal, increase rank
        if (rank[rootX] == rank[rootY])
            rank[rootX]++;
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();

        // Initialize DSU
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        // Perform unions based on allowed swaps
        for (auto &vec : allowedSwaps) {
            Union(vec[0], vec[1]);
        }

        // Map: parent -> frequency map of values in source
        unordered_map<int, unordered_map<int, int>> groupFreq;

        for (int i = 0; i < n; i++) {
            int root = find(i);  // group leader
            groupFreq[root][source[i]]++;
        }

        int hammingDistance = 0;

        // Compare target with available values in same group
        for (int i = 0; i < n; i++) {
            int root = find(i);

            // If value exists in group, use it
            if (groupFreq[root][target[i]] > 0) {
                groupFreq[root][target[i]]--;
            } else {
                // Otherwise, mismatch
                hammingDistance++;
            }
        }

        return hammingDistance;
    }
};


// Main function
int main() {
    int n;
    cout << "Enter size of arrays: ";
    cin >> n;

    vector<int> source(n), target(n);

    cout << "Enter source array: ";
    for (int i = 0; i < n; i++) cin >> source[i];

    cout << "Enter target array: ";
    for (int i = 0; i < n; i++) cin >> target[i];

    int m;
    cout << "Enter number of allowed swaps: ";
    cin >> m;

    vector<vector<int>> allowedSwaps(m, vector<int>(2));

    cout << "Enter allowed swaps (index pairs):\n";
    for (int i = 0; i < m; i++) {
        cin >> allowedSwaps[i][0] >> allowedSwaps[i][1];
    }

    Solution obj;
    int result = obj.minimumHammingDistance(source, target, allowedSwaps);

    cout << "Minimum Hamming Distance: " << result << endl;

    return 0;
}