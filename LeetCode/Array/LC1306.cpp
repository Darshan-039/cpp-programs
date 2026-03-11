// Leetcode 1306: Jump Game III



#include <iostream>
#include <vector>

using namespace std;



//Approach - 1: DFS with In-Place Visited Marking
class Solution {
public:
    bool solve(vector<int> &arr, int n, int idx) {
        // Base Case: Out of bounds or already visited (marked by negative value)
        if (idx < 0 || idx >= n || arr[idx] < 0) return false;

        // Found the target!
        if (arr[idx] == 0) return true;

        int step = arr[idx];
        
        // Mark as visited by negating the value
        // Note: We use -1 if the value is somehow already handled, 
        // but here negating works for all arr[i] > 0.
        arr[idx] = -arr[idx];

        // Recurse: Try jumping forward OR jumping backward
        return solve(arr, n, idx + step) || solve(arr, n, idx - step);
    }

    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        return solve(arr, n, start);
    }
};





// Approach - 2
bool canReach(vector<int>& arr, int start) {
    int n = arr.size();
    queue<int> q;
    q.push(start);

    vector<bool> visited(n, false);
    visited[start] = true;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        // Check for goal
        if(arr[curr] == 0) return true;

        // check for forward
        int forward = curr + arr[curr];
        if(forward < n && !visited[forward]) {
            visited[forward] = true;
            q.push(forward);
        }

        // check for backward
        int backward = curr - arr[curr];
        if(backward >= 0 && !visited[backward]) {
            visited[backward] = true;
            q.push(backward);
        }
    }

    return false;
}



int main() {
    Solution sol;

    // Example 1
    // start = 5, can we reach index 3 or 6?
    vector<int> arr1 = {4, 2, 3, 0, 3, 1, 2};
    int start1 = 5;

    cout << "Test Case 1: ";
    if (sol.canReach(arr1, start1)) {
        cout << "Path found to 0!" << endl;
    } else {
        cout << "No path found." << endl;
    }

    // Example 2
    vector<int> arr2 = {3, 0, 2, 1, 2};
    int start2 = 2;

    cout << "Test Case 2: ";
    if (sol.canReach(arr2, start2)) {
        cout << "Path found to 0!" << endl;
    } else {
        cout << "No path found." << endl;
    }

    return 0;
}