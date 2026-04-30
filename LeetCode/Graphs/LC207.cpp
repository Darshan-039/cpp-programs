// Leetcode 207. Course Schedule


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Function to check if topological sorting is possible
    // (i.e., no cycle exists in the graph)
    bool topoCheck(unordered_map<int, vector<int>> &adj, int n, vector<int> &indegree) {
        queue<int> q;
        int count = 0; // count of processed nodes

        // Step 1: Push all nodes with indegree 0 into queue
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                count++;
            }
        }

        // Step 2: Process the queue
        while(!q.empty()) {
            int top = q.front();
            q.pop();

            // Traverse all neighbors
            for(auto &nbr : adj[top]) {
                indegree[nbr]--; // remove edge

                // If indegree becomes 0, push to queue
                if(indegree[nbr] == 0) {
                    count++;
                    q.push(nbr);
                }
            }
        }

        // If all nodes are processed → no cycle
        return (count == n);
    }

    // Main function to check if all courses can be finished
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);

        // Build graph
        // b -> a means: to take course 'a', you must complete 'b'
        for(auto &vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        return topoCheck(adj, numCourses, indegree);
    }
};


// -------------------- MAIN FUNCTION --------------------
int main() {
    Solution obj;

    int numCourses = 4;

    // Example input:
    // [a, b] means: to take course a, you must first take course b
    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 1},
        {3, 2}
    };

    if(obj.canFinish(numCourses, prerequisites)) {
        cout << "Yes, you can finish all courses (No Cycle)" << endl;
    } else {
        cout << "No, you cannot finish all courses (Cycle exists)" << endl;
    }

    return 0;
}