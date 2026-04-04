// Leetcode 399. Evaluate Division



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    // DFS to find path from src → dst and calculate product
    void dfs(unordered_map<string, vector<pair<string, double>>> &adj,
             string src, string dst,
             unordered_set<string>& visited,
             double product, double &ans) {

        // If already visited → avoid cycle
        if(visited.find(src) != visited.end())
            return;
        
        visited.insert(src);

        // If destination reached → store answer
        if(src == dst) {
            ans = product;
            return;
        }
        
        // Traverse neighbors
        for(auto p : adj[src]) {
            
            string v   = p.first;   // neighbor variable
            double val = p.second;  // weight (division value)
            
            // Continue DFS with updated product
            dfs(adj, v, dst, visited, product * val, ans);
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        
        int n = equations.size();
        
        // Adjacency list: variable → {neighbor, weight}
        unordered_map<string, vector<pair<string, double>>> adj;
        
        // Step 1: Build graph
        for(int i = 0; i < n; i++) {
            string u   = equations[i][0];
            string v   = equations[i][1];
            double val = values[i];
            
            adj[u].push_back({v, val});        // u / v = val
            adj[v].push_back({u, 1.0 / val});  // v / u = 1/val
        }
        
        vector<double> result;
        
        // Step 2: Process each query
        for(auto &query : queries) {
            
            string src = query[0];
            string dst = query[1];
            
            double ans     = -1.0; // default if no path
            double product = 1.0;  // initial product
            
            // Only run DFS if src exists in graph
            if(adj.find(src) != adj.end()) {
                unordered_set<string> visited;
                
                dfs(adj, src, dst, visited, product, ans);
            }
            
            result.push_back(ans);
        }
        
        return result;
    }
};

int main() {
    int n;

    // Input number of equations
    cout << "Enter number of equations: ";
    cin >> n;

    vector<vector<string>> equations(n, vector<string>(2));
    vector<double> values(n);

    // Input equations and values
    cout << "Enter equations (format: a b value means a/b = value):" << endl;
    for(int i = 0; i < n; i++) {
        cin >> equations[i][0] >> equations[i][1] >> values[i];
    }

    int q;

    // Input number of queries
    cout << "Enter number of queries: ";
    cin >> q;

    vector<vector<string>> queries(q, vector<string>(2));

    // Input queries
    cout << "Enter queries (format: a b):" << endl;
    for(int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }

    Solution obj;

    // Function call
    vector<double> result = obj.calcEquation(equations, values, queries);

    // Output results
    cout << "Results:" << endl;
    for(double val : result) {
        cout << val << endl;
    }

    return 0;
}