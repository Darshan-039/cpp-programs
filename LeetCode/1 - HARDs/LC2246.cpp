// Leetcode - 2246: Longest Path With Different Adjacent Characters



class Solution {
public:
    int LongestPathResult = 1; // Global max path found so far

    int solve(int currentNode, vector<vector<int>>& adj, string& s) {
        // top1 and top2 store the lengths of the two longest valid branches 
        // starting from children
        int top1 = 0;
        int top2 = 0;

        for(int child : adj[currentNode]) {
            // Recursive call to get the longest path starting from the child
            int childPathLength = solve(child, adj, s);

            // Condition: The character of the child must be different from the parent
            if(s[currentNode] != s[child]) {
                // Update the two longest valid branches
                if(childPathLength > top1) {
                    top2 = top1;
                    top1 = childPathLength;
                }
                else if(childPathLength > top2) {
                    top2 = childPathLength;
                }
            }
        }

        LongestPathResult = max(LongestPathResult, 1 + top1 + top2);

        // Return the longest single branch to the parent (1 + longest child branch)
        return 1 + top1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);

        // Build Adjacency List (Parent -> child) 
        for(int i = 1; i<n; i++) {
            adj[parent[i]].push_back(i);
        }

        solve(0, adj, s);
        return LongestPathResult;
    }
};